/**********************************************************************

EEStore.cpp
COPYRIGHT (c) 2013-2016 Gregg E. Berman

Part of DCC++ BASE STATION for the Arduino

**********************************************************************/

#include "DCCpp_Uno.h"

#if HANDLE_EESTORE

#include "EEStore.h"
#include "Accessories.h"
#include "Sensor.h"
#include "Outputs.h"
#include <EEPROM.h>

///////////////////////////////////////////////////////////////////////////////

void EEStore::init(){

  
  eeStore=(EEStore *)calloc(1,sizeof(EEStore));

  EEPROM.get(0,eeStore->data);                                       // get eeStore data 
  
  if(strncmp(eeStore->data.id,EESTORE_ID,sizeof(EESTORE_ID))!=0){    // check to see that eeStore contains valid DCC++ ID
      EEStore::clear();
  }
  
  reset();            // set memory pointer to first free EEPROM space
#if HANDLE_TURNOUTS
  Turnout::load();    // load turnout definitions
#endif
#if HANDLE_SENSORS
  Sensor::load();     // load sensor definitions
#endif
#if HANDLE_OUTPUTS
  Output::load();     // load output definitions
#endif

}

///////////////////////////////////////////////////////////////////////////////

void EEStore::clear(){
    
  sprintf(eeStore->data.id,EESTORE_ID);                           // create blank eeStore structure (no turnouts, no sensors) and save it back to EEPROM
#if HANDLE_TURNOUTS
  eeStore->data.nTurnouts=0;
#endif
#if HANDLE_SENSORS
  eeStore->data.nSensors=0;
#endif
#if HANDLE_OUTPUTS
  eeStore->data.nOutputs=0;
#endif
  EEPROM.put(0,eeStore->data);    
  
}

///////////////////////////////////////////////////////////////////////////////

void EEStore::store(){
  reset();
#if HANDLE_TURNOUTS
  Turnout::store();
#endif
#if HANDLE_SENSORS
  Sensor::store();
#endif
#if HANDLE_OUTPUTS  
  Output::store();
#endif  
  EEPROM.put(0,eeStore->data);    
}

///////////////////////////////////////////////////////////////////////////////

void EEStore::advance(int n){
  eeAddress+=n;
}

///////////////////////////////////////////////////////////////////////////////

void EEStore::reset(){
  eeAddress=sizeof(EEStore);
}
///////////////////////////////////////////////////////////////////////////////

int EEStore::pointer(){
  return(eeAddress);
}
///////////////////////////////////////////////////////////////////////////////

EEStore *EEStore::eeStore=NULL;
int EEStore::eeAddress=0;


#endif // HANDLE_EESTORE
