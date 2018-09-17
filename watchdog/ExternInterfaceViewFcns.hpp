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

#ifndef _BIP_Model_ExternInterfaceViewFcns_HPP_
#define _BIP_Model_ExternInterfaceViewFcns_HPP_

#include <iostream>
#include <queue>
#include <chrono>
#include <math.h>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <mutex>
#include "C_ASN1_Types.h"

//#define _DEBUG_BIP

bool is_debug();

using namespace std;

// Standard functions

void write(const bool i);
void writeln(const bool i);
void write(const int i);
void writeln(const int i);
void write(const double i);
void writeln(const double i);
void write(const string i);
void writeln(const string i);
void write(const char* s);
void writeln(const char* s);

void writelog(const string purpose, const string component, const string message, const string value);

// FDIR configuration functions

void fdir_init_config();
const double get_init_time();
const double get_wdog_timeout();
const double get_wdog_eps();

// BIP-FDIR wrappers for halt actions 
void wrap_mot_cmd(const asn1SccBase_commands_Motion2D &val);

// Queue for executing out messages

typedef queue<string> queueOuts;
typedef queue<asn1SccBase_commands_Motion2D> queueStatusOuts;

extern mutex mtx;
extern queueOuts qo;
extern queueStatusOuts qso;

// Type for interface test_cmd

const double get_rad(const asn1SccBase_Angle &v);
void set_rad(asn1SccBase_Angle &v, const double val);
void writeln(const asn1SccBase_Angle &v);

const double get_translation(const asn1SccBase_commands_Motion2D &v);
void set_translation (asn1SccBase_commands_Motion2D &v, const double val);
const double get_rotation(const asn1SccBase_commands_Motion2D &v);
void set_rotation(asn1SccBase_commands_Motion2D &v, const double val);
const double get_heading(const asn1SccBase_commands_Motion2D &v);
void set_heading(asn1SccBase_commands_Motion2D &v, const double val);
void writeln(const asn1SccBase_commands_Motion2D &v);
ostream &operator<<(ostream &os, const asn1SccBase_commands_Motion2D &v);

#endif
