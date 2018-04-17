/*----- PROTECTED REGION ID(SlsJungfrau.h) ENABLED START -----*/
//=============================================================================
//
// file :        SlsJungfrau.h
//
// description : Include file for the SlsJungfrau class
//
// project :     Sls dectector TANGO specific device.
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// $HeadURL:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef SlsJungfrau_H
#define SlsJungfrau_H

#include <tango.h>

//- YAT/YAT4TANGO
#include <yat4tango/PropertyHelper.h>
#include <yat4tango/DynamicInterfaceManager.h>

#include "Factory.h"

#include "lima/HwInterface.h"
#include "lima/CtControl.h"
#include "lima/CtAcquisition.h"
#include "lima/CtImage.h"

#include "SlsJungfrauInterface.h"
#include "SlsJungfrauCamera.h"


using namespace yat4tango;

/*----- PROTECTED REGION END -----*/	//	SlsJungfrau.h

/**
 *  SlsJungfrau class description:
 *    Device for sls detectors from PSI. 
 */

namespace SlsJungfrau_ns
{
/*----- PROTECTED REGION ID(SlsJungfrau::Additional Class Declarations) ENABLED START -----*/

//	Additional Class Declarations

/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::Additional Class Declarations

class SlsJungfrau : public TANGO_BASE_CLASS
{

/*----- PROTECTED REGION ID(SlsJungfrau::Data Members) ENABLED START -----*/

//	Add your own data members

/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::Data Members

//	Device property data members
public:
	//	ConfigFileName:	Configuration files used during the camera instanciation.
	string	configFileName;

//	Attribute data members
public:
	Tango::DevLong	*attr_tresholdEnergy_read;
	Tango::DevString	*attr_clockDivider_read;
	Tango::DevString	*attr_configFileName_read;
	Tango::DevDouble	*attr_delayAfterTrigger_read;
	Tango::DevString	*attr_detectorFirmwareVersion_read;
	Tango::DevString	*attr_detectorSoftwareVersion_read;

//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	SlsJungfrau(Tango::DeviceClass *cl,string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	SlsJungfrau(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	SlsJungfrau(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */	
	~SlsJungfrau() {delete_device();};


//	Miscellaneous methods
public:
	/*
	 *	will be called at device destruction or at init command.
	 */
	void delete_device();
	/*
	 *	Initialize the device
	 */
	virtual void init_device();
	/*
	 *	Read the device properties from database
	 */
	void get_device_property();
	/*
	 *	Always executed method before execution command method.
	 */
	virtual void always_executed_hook();


//	Attribute methods
public:
	//--------------------------------------------------------
	/*
	 *	Method      : SlsJungfrau::read_attr_hardware()
	 *	Description : Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(vector<long> &attr_list);
	//--------------------------------------------------------
	/*
	 *	Method      : SlsJungfrau::write_attr_hardware()
	 *	Description : Hardware writing for attributes.
	 */
	//--------------------------------------------------------
	virtual void write_attr_hardware(vector<long> &attr_list);

/**
 *	Attribute tresholdEnergy related methods
 *	Description: set/get Threshold energy.
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_tresholdEnergy(Tango::Attribute &attr);
	virtual void write_tresholdEnergy(Tango::WAttribute &attr);
	virtual bool is_tresholdEnergy_allowed(Tango::AttReqType type);
/**
 *	Attribute clockDivider related methods
 *	Description: Changes the readout clock.<br>
 *               Available clock Divider :<br>
 *               FULL_SPEED<br>
 *               HALF_SPEED<br>
 *               QUARTER_SPEED<br>
 *               SUPER_SLOW_SPEED<br>
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar
 */
	virtual void read_clockDivider(Tango::Attribute &attr);
	virtual void write_clockDivider(Tango::WAttribute &attr);
	virtual bool is_clockDivider_allowed(Tango::AttReqType type);
/**
 *	Attribute configFileName related methods
 *	Description: 
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar
 */
	virtual void read_configFileName(Tango::Attribute &attr);
	virtual bool is_configFileName_allowed(Tango::AttReqType type);
/**
 *	Attribute delayAfterTrigger related methods
 *	Description: set/get delay after trigger.
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_delayAfterTrigger(Tango::Attribute &attr);
	virtual void write_delayAfterTrigger(Tango::WAttribute &attr);
	virtual bool is_delayAfterTrigger_allowed(Tango::AttReqType type);
/**
 *	Attribute detectorFirmwareVersion related methods
 *	Description: Get detector firmware version.
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar
 */
	virtual void read_detectorFirmwareVersion(Tango::Attribute &attr);
	virtual bool is_detectorFirmwareVersion_allowed(Tango::AttReqType type);
/**
 *	Attribute detectorSoftwareVersion related methods
 *	Description: Get detector software version.
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar
 */
	virtual void read_detectorSoftwareVersion(Tango::Attribute &attr);
	virtual bool is_detectorSoftwareVersion_allowed(Tango::AttReqType type);


	//--------------------------------------------------------
	/**
	 *	Method      : SlsJungfrau::add_dynamic_attributes()
	 *	Description : Add dynamic attributes if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_attributes();



//	Command related methods
public:
	/**
	 *	Command SetCmd related method
	 *	Description: Allows to execute a line command (set type)
	 *
	 *	@param argin SlsDetector command
	 *	@returns SlsDetector response
	 */
	virtual Tango::DevString set_cmd(Tango::DevString argin);
	virtual bool is_SetCmd_allowed(const CORBA::Any &any);
	/**
	 *	Command GetCmd related method
	 *	Description: Allows to execute a line command (get type)
	 *
	 *	@param argin SlsDetector command
	 *	@returns SlsDetector response
	 */
	virtual Tango::DevString get_cmd(Tango::DevString argin);
	virtual bool is_GetCmd_allowed(const CORBA::Any &any);


/*----- PROTECTED REGION ID(SlsJungfrau::Additional Method prototypes) ENABLED START -----*/

//	Additional Method prototypes
private:
/**
 * This command gets the device state (stored in its <i>device_state</i> data member) and returns it to the caller.
 *	@return	State Code
 *	@exception DevFailed
 */
	Tango::DevState	dev_state();

/**
 *	method:	SlsJungfrau::manage_devfailed_exception
 *
 *	description: method which manages DevFailed exceptions
 */
    void manage_devfailed_exception(Tango::DevFailed & in_exception, const std::string & in_caller_method_name);

/**
 *	method:	SlsJungfrau::manage_lima_exception
 *
 *	description: method which manages lima exceptions
 */
    void manage_lima_exception(lima::Exception & in_exception, const std::string & in_caller_method_name);

protected :	
    //lima OBJECTS
    lima::SlsJungfrau::Interface * m_hw    ;
    lima::CtControl              * m_ct    ;
    lima::SlsJungfrau::Camera    * m_camera;
	bool                           m_is_device_initialized;
    stringstream                   m_status_message        ;

	yat4tango::DynamicInterfaceManager m_dim;

/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::Additional Method prototypes
};

/*----- PROTECTED REGION ID(SlsJungfrau::Additional Classes Definitions) ENABLED START -----*/

//	Additional Classes Definitions

/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::Additional Classes Definitions

}	//	End of namespace

#endif   //	SlsJungfrau_H
