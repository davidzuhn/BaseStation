/**********************************************************************

EEStore.h
COPYRIGHT (c) 2013-2016 Gregg E. Berman

Part of DCC++ BASE STATION for the Arduino

**********************************************************************/

#ifndef EEStore_h
#define EEStore_h

#include "DCCpp_Uno.h"

#define  EESTORE_ID "DCC++"

struct EEStoreData{
  char id[sizeof(EESTORE_ID)];
#if HANDLE_TURNOUTS
  int nTurnouts;
#endif
#if HANDLE_SENSORS
  int nSensors;
#endif
#if HANDLE_OUTPUTS
    int nOutputs;
#endif
};

struct EEStore{
  static EEStore *eeStore;
  EEStoreData data;
  static int eeAddress;
  static void init();
  static void reset();
  static int pointer();
  static void advance(int);
  static void store();
  static void clear();
};
  
#endif

