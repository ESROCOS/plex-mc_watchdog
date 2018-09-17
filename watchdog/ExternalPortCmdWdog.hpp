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

#ifndef _EXTERNAL_PORT_CMD_WATCHDOG_
#define _EXTERNAL_PORT_CMD_WATCHDOG_

#include <AtomExternalPort.hpp>
#include <TimeValue.hpp>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include <signal.h>
#include <mutex>

#include "C_ASN1_Types.h"

using namespace std;

class ExternalPortCmdWdog : public AtomExternalPort {
 public:
  ExternalPortCmdWdog(const string &name, const EventConsumptionPolicy &policy) :
    AtomExternalPort(name, policy),
    isEvent(false) {
  }

  virtual ~ExternalPortCmdWdog() {
  }

  virtual void initialize() { 
	}

  virtual bool hasEvent() const {
    mtx.lock();

    bool r = isEvent;

    mtx.unlock();

    return r;
  }

  virtual void popEvent() { 
    mtx.lock();

    assert(isEvent);

    isEvent = false;

    mtx.unlock();
	}

  virtual void purgeEvents() { 
    mtx.lock();

    assert(isEvent);

    isEvent = false;

    mtx.unlock();
	}

  virtual TimeValue eventTime() const {
    mtx.lock();

    assert(isEvent);

    TimeValue r = t;

    mtx.unlock();

    return r;
  }

  virtual asn1SccBase_commands_Motion2D& event_get_v() {
    mtx.lock();

    assert(isEvent);

    asn1SccBase_commands_Motion2D &r = val;

    mtx.unlock();

    return r;
  }

  void push(const asn1SccBase_commands_Motion2D &v) {
    mtx.lock();

    assert(!isEvent);

    isEvent = true;
    val = v;
    t = time();

    notify();

    mtx.unlock();
  }

	protected:
		asn1SccBase_commands_Motion2D val;
		TimeValue t;
		bool isEvent;

		mutable mutex mtx;

};

#endif


