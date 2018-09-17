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

#include "ExternInterfaceViewFcns.hpp"

bool is_debug(){
#ifdef _DEBUG_BIP
  return true;
#endif
  return false;
}

// Variable containing the configuration parameters for watchdog (e.g., thresholds)
unordered_map<string, double> fdirDict;

void fdir_init_config(){
	//cout<<"Reading file";
  ifstream fin("../config.cfg");
  for (string line ; getline(fin, line); ) {
    istringstream ssin(line);
    string name, sep;
    double val;
    ssin >> name >> sep >> val;

    if (name != "" && name[0] != '#') 
      fdirDict[name] = val;
  }
}

const double get_init_time(){
  return fdirDict["max_init_time"];
}

const double get_wdog_timeout(){
  return fdirDict["wdog_timeout"];
}

const double get_wdog_eps(){
	return fdirDict["wdog_eps"];
}


void write(const bool i){
  cout<<i;
}

void writeln(const bool i){
  cout<<i<<endl;
}

void write(const int i){
  cout<<i;
}

void writeln(const int i){
  cout<<i<<endl;
}

void write(const double i){
  cout<<i;
}

void writeln(const double i){
  cout<<i<<endl;
}


void write(const string i){
  cout<<i;
}

void writeln(const string i){
  cout<<i<<endl;
}

void write(const char* s){
  cout<<s;
}

void writeln(const char* s){
  cout<<s<<endl;
}

void writelog(const string purpose, const string component, const string message,const string value){
  cout<<"["<<purpose<<"] [BIP::"<<component<<"] - "<<message<<" "<<value<<endl;
}

mutex mtx;
queueOuts qo;
queueStatusOuts qso;


void wrap_mot_cmd(const asn1SccBase_commands_Motion2D &val){
	mtx.lock();
	qo.push("watchdog_RI_mot_cmd");
	qso.push(val);
	mtx.unlock();
}

const double get_rad(const asn1SccBase_Angle &v){
  return v.rad;
}

void set_rad(asn1SccBase_Angle &v, const double val){
  v.rad = val;
}

void writeln(const asn1SccBase_Angle &v){
  cout<<get_rad(v)<<endl;
}

const double get_translation(const asn1SccBase_commands_Motion2D &v){
  return v.translation;
}

void set_translation (asn1SccBase_commands_Motion2D &v, const double val){
  v.translation = val;
}

const double get_rotation(const asn1SccBase_commands_Motion2D &v){
  return v.rotation;
}

void set_rotation(asn1SccBase_commands_Motion2D &v, const double val){
  v.rotation = val;
}

const double get_heading(const asn1SccBase_commands_Motion2D &v){
  return get_rad(v.heading);
}

void set_heading(asn1SccBase_commands_Motion2D &v, const double val){
  set_rad(v.heading,val);
}

ostream &operator<<(ostream &os, const asn1SccBase_commands_Motion2D &v){
  os<<v.translation<<" "<<v.rotation<<" "<<get_rad(v.heading);
  return os;
}

void writeln(const asn1SccBase_commands_Motion2D &v){
  cout<<v<<endl;
}



