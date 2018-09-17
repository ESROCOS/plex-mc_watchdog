/**
 * Copyright Verimag laboratory.
 * 
 * contributors:
 *  Jacques Combaz (jacques.combaz@univ-grenoble-alpes.fr)
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

#include "DeployTypes.hpp"

#include <Launcher.hpp>

namespace staticallocated{

    // data param for Comp__ROOT./
    

    AtomIPort__InterfaceView__Port iport__ROOT__Watchdog__Watchdog_xtest_xcmd_xreturn("Watchdog_test_cmd_return", false, true);

    AtomIPort__InterfaceView__portBase_xcommands_xMotion2D iport__ROOT__Watchdog__Watchdog_xmot_xcmd_xout("Watchdog_mot_cmd_out", false, true);

    AtomIPort__InterfaceView__Port iport__ROOT__Watchdog__wdog_xtimeout("wdog_timeout", false, true);

    ExternalPortCmdWdog eport__ROOT__Watchdog__Watchdog_xtest_xcmd_xin("Watchdog_test_cmd_in", ERROR); // ExternalPortCmdWdog

    AtomEPort__InterfaceView__Port port__ROOT__Watchdog__Watchdog_xtest_xcmd_xreturn("Watchdog_test_cmd_return", false, true);

    AtomEPort__InterfaceView__portBase_xcommands_xMotion2D port__ROOT__Watchdog__Watchdog_xmot_xcmd_xout("Watchdog_mot_cmd_out", false, true);

    // static init for Atom: Comp__ROOT__Watchdog
    

    AT__InterfaceView__Watchdog Comp__ROOT__Watchdog(
     "Watchdog"
     , iport__ROOT__Watchdog__Watchdog_xtest_xcmd_xreturn, iport__ROOT__Watchdog__Watchdog_xmot_xcmd_xout, iport__ROOT__Watchdog__wdog_xtimeout
     , eport__ROOT__Watchdog__Watchdog_xtest_xcmd_xin
     , port__ROOT__Watchdog__Watchdog_xtest_xcmd_xreturn, port__ROOT__Watchdog__Watchdog_xmot_xcmd_xout
     
     
    );


    // static init for Compound: Comp__ROOT

    CT__InterfaceView__Syst Comp__ROOT(
      "ROOT"
     , Comp__ROOT__Watchdog
     
     
     
     
     
     
    );


// End of namespace.
};

/*
 * The "static" includes (the one we use inconditionnaly)
 */


Component* deploy(int argc __attribute__((unused)), char **argv __attribute__((unused))){
    // Top is Comp__ROOT




    staticallocated::eport__ROOT__Watchdog__Watchdog_xtest_xcmd_xin.setHasEarlyUpdate(false);
    staticallocated::eport__ROOT__Watchdog__Watchdog_xtest_xcmd_xin.setHasUrgency(true);

    staticallocated::port__ROOT__Watchdog__Watchdog_xtest_xcmd_xreturn.addInternalPort(staticallocated::iport__ROOT__Watchdog__Watchdog_xtest_xcmd_xreturn);

    staticallocated::port__ROOT__Watchdog__Watchdog_xmot_xcmd_xout.addInternalPort(staticallocated::iport__ROOT__Watchdog__Watchdog_xmot_xcmd_xout);

    // Runtime init for Atom: Comp__ROOT__Watchdog
    // staticallocated::Comp__ROOT__Watchdog


    // Runtime init for Compound: Comp__ROOT
    // staticallocated::Comp__ROOT

    // Finished: Comp__ROOT
    return &(staticallocated::Comp__ROOT);
}

bool isSerializeEnabled() {
    return false;
}

void serialize(char **cbuf __attribute__((unused)), size_t *clen __attribute__((unused))){
    assert(false);
}

void deserialize(const char *buf __attribute__((unused)), size_t len __attribute__((unused)), const TimeValue &time){
    assert(false);
}
