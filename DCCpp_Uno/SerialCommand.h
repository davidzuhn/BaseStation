/**********************************************************************

SerialCommand.h
COPYRIGHT (c) 2013-2016 Gregg E. Berman

Part of DCC++ BASE STATION for the Arduino

**********************************************************************/

#ifndef SerialCommand_h
#define SerialCommand_h

#include "DCCpp_Uno.h"

#include "PacketRegister.h"
#include "CurrentMonitor.h"

#define  MAX_COMMAND_LENGTH         30

struct SerialCommand{
  static char commandString[MAX_COMMAND_LENGTH+1];
#if HANDLE_MAIN_TRACK
  static CurrentMonitor *mMonitor;
  static volatile RegisterList *mRegs;
#endif
#if HANDLE_PROG_TRACK
  static volatile RegisterList *pRegs;
#endif

  static void init(
#if HANDLE_MAIN_TRACK
				  volatile RegisterList *_mRegs, 
				  CurrentMonitor *_mMonitor
#endif
#if HANDLE_MAIN_TRACK && HANDLE_PROG_TRACK
				  ,
#endif
#if HANDLE_PROG_TRACK
                                  volatile RegisterList *_pRegs
#endif
				  );
  static void parse(char *);
  static void process();
}; // SerialCommand
  
#endif




