/*
  ==============================================================================

    YarpInterface.h
    Created: 16 Jul 2014 1:44:43pm
    Author:  johnt_000

  ==============================================================================
*/

#ifndef YARPINTERFACE_H_INCLUDED
#define YARPINTERFACE_H_INCLUDED

#include <yarp/os/all.h>
#include <yarp/os/impl/NameConfig.h>
#include "../JuceLibraryCode/JuceHeader.h"

class YarpInterface : public Thread, public ChangeBroadcaster {

public:
	YarpInterface();
	~YarpInterface();
	bool setPortName(yarp::os::ConstString name);
	bool setNSAddress(yarp::os::ConstString addr);
	void run();

	String getOutputText() {return textOutput;}

	SpinLock lock;

private:
	String textOutput;
	yarp::os::ConstString portName;
	yarp::os::ConstString nsIPAddr;
	ScopedPointer<yarp::os::Network> yarp;
	ScopedPointer<yarp::os::impl::NameConfig> nameConfig;
	ScopedPointer <yarp::os::BufferedPort<yarp::os::Bottle>> yarpPort;
};





#endif  // YARPINTERFACE_H_INCLUDED
