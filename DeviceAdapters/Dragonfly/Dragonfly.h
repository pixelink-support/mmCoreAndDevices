///////////////////////////////////////////////////////////////////////////////
// FILE:          Dragonfly.h
// PROJECT:       Micro-Manager
// SUBSYSTEM:     DeviceAdapters
//-----------------------------------------------------------------------------
#ifndef _DRAGONFLY_H_
#define _DRAGONFLY_H_

#include "../../MMDevice/DeviceBase.h"
//#include "../../MMDevice/DeviceThreads.h"


//////////////////////////////////////////////////////////////////////////////
// Dragonfly class
//////////////////////////////////////////////////////////////////////////////

class CASDWrapper;
class IASDLoader;

#define ERR_LIBRARY_LOAD 101
#define ERR_LIBRARY_INIT 102

class CDragonfly : public CGenericBase<CDragonfly>
{
public:
  CDragonfly();
  ~CDragonfly();

  int Initialize();
  int Shutdown();

  void GetName( char * Name ) const;
  bool Busy();

  int Connect( const std::string& Port );
  int Disconnect();
  int InitializeComponents();

  int OnPort( MM::PropertyBase* Prop, MM::ActionType Act );

private:
  bool ASDLibraryConnected_;
  bool Initialized_;
  std::string Port_;
  CASDWrapper* ASDWrapper_;
  IASDLoader* ASDLoader_;
};

#endif
