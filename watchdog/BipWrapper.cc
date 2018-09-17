/**
 * Copyright Verimag laboratory.
 *
 * contributors:
 *  Iulia Dragomir (iulia.dragomir@univ-grenoble-alpes.fr)
 *
 * This software is a computer program whose purpose is to generate
 * executable code from BIP models.
 *
 * This software is governed by the CeCILL-B license under French law and
 * abiding by the rules of distribution of free software.  You can  use,
 * modify and/ or redistribute the software under the terms of the CeCILL-B
 * license as circulated by CEA, CNRS and INRIA at the following URL
 * "http://www.cecill.info".
 *
 * As a counterpart to the access to the source code and  rights to copy,
 * modify and redistribute granted by the license, users are provided only
 * with a limited warranty  and the software's author,  the holder of the
 * economic rights,  and the successive licensors  have only  limited
 * liability.
 *
 * In this respect, the user's attention is drawn to the risks associated
 * with loading,  using,  modifying and/or developing or reproducing the
 * software by the user in light of its specific status of free software,
 * that may mean  that it is complicated to manipulate,  and  that  also
 * therefore means  that it is reserved for developers  and  experienced
 * professionals having in-depth computer knowledge. Users are therefore
 * encouraged to load and test the software's suitability as regards their
 * requirements in conditions enabling the security of their systems and/or
 * data to be ensured and,  more generally, to use and operate it in the
 * same conditions as regards security.
 *
 * The fact that you are presently reading this means that you have had
 * knowledge of the CeCILL-B license and that you accept its terms.
 */

#include "BipWrapper.h"
#include "watchdog.h"

Atom *fdir;
map<string, AtomExternalPort *> portsFdir;
AtomScheduler *scheduler;

void initialize_model(){
	Component *root = deploy(0,NULL);
#ifdef _DEBUG_BIP
  writelog("INFO","Watchdog","System instantiated","");
#endif

	const CT__InterfaceView__Syst syst =  *(dynamic_cast<CT__InterfaceView__Syst*>(root));

	map<string, Component *> comps = syst.components();

	auto search = comps.find("Watchdog");
	if (search != comps.end())
		fdir = dynamic_cast<Atom *>(search->second);
	else
    writelog("ERROR","Watchdog","Component not found","");

	const Atom *aux = fdir;
	portsFdir = aux->externalPorts();

	scheduler = new AtomScheduler(*fdir, false);
	scheduler->initialize();
#ifdef _DEBUG_BIP
  writelog("INFO","Watchdog","Engine instantiated","");
#endif
}

void start_engine(){
	BipError &error = scheduler->run();
}

void execute_purge(){
	mtx.lock();
	while(qo.size() > 0){
		string sig = qo.front();
		qo.pop();
    const asn1SccBase_commands_Motion2D v = qso.front();
		qso.pop();
#ifdef _DEBUG_BIP
    writelog("INFO","Watchdog","Send command","");
#endif
    watchdog_RI_mot_cmd(&v);
	}
	mtx.unlock();
}


void execute_port_test_cmd(const asn1SccBase_commands_Motion2D *IN_cmd_val){

#ifdef _DEBUG_BIP
  stringstream ss;
  ss<<*IN_cmd_val;
  writelog("INFO","Watchdog","Received test_cmd",ss.str());
#endif

	//Get corresponding Bip input port
	ExternalPortCmdWdog *testCmdPortIn = dynamic_cast<ExternalPortCmdWdog*>(portsFdir["Watchdog_test_cmd_in"]);
	testCmdPortIn->push(*IN_cmd_val);
}

