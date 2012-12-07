static const char *RcsId = "$Id:  $";
//+=============================================================================
//
// file :         Pco.cpp
//
// description :  C++ source for the Pco and its commands. 
//                The class is derived from Device. It represents the
//                CORBA servant object which will be accessed from the
//                network. All commands which can be executed on the
//                Pco are implemented in this file.
//
// project :      TANGO Device Server
//
// $Author:  $
//
// $Revision:  $
//
// $Revision:  $
// $Date:  $
//
// SVN only:
// $HeadURL: $
//
// CVS only:
// $Source:  $
// $Log:  $
//
// copyleft :    Synchrotron SOLEIL 
//               L'Orme des merisiers - Saint Aubin
//               BP48 - 91192 Gif sur Yvette
//               FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================



//===================================================================
//
//	The following table gives the correspondence
//	between commands and method name.
//
//  Command name|  Method name
//	----------------------------------------
//  State   |  dev_state()
//  Status  |  dev_status()
//  Talk    |  talk()
//
//===================================================================

#ifdef WIN32
#include <tango.h>
#include <PogoHelper.h>
#endif
#include <Pco.h>
#include <PcoClass.h>

#ifndef WIN32
#include <tango.h>
#include <PogoHelper.h>
#endif

namespace Pco_ns
{

//+----------------------------------------------------------------------------
//
// method : 		Pco::Pco(string &s)
// 
// description : 	constructor for simulated Pco
//
// in : - cl : Pointer to the DeviceClass object
//      - s : Device name 
//
//-----------------------------------------------------------------------------
Pco::Pco(Tango::DeviceClass *cl,string &s)
:Tango::Device_4Impl(cl,s.c_str())
{
	init_device();
}

Pco::Pco(Tango::DeviceClass *cl,const char *s)
:Tango::Device_4Impl(cl,s)
{
	init_device();
}

Pco::Pco(Tango::DeviceClass *cl,const char *s,const char *d)
:Tango::Device_4Impl(cl,s,d)
{
	init_device();
}
//+----------------------------------------------------------------------------
//
// method : 		Pco::delete_device()
// 
// description : 	will be called at device destruction or at init command.
//
//-----------------------------------------------------------------------------
void Pco::delete_device()
{
	//	Delete device allocated objects
    DELETE_DEVSTRING_ATTRIBUTE(attr_shutterMode_read);	
    DELETE_DEVSTRING_ATTRIBUTE(attr_pixelScanRate_read);	

    //!!!! ONLY LimaDetector device can do this !!!!
    //if(m_ct!=0)
    //{
    //    ControlFactory::instance().reset("PrincetonCCD");
    //    m_ct = 0;
    //}
}

//+----------------------------------------------------------------------------
//
// method : 		Pco::init_device()
// 
// description : 	will be called at device initialization.
//
//-----------------------------------------------------------------------------
void Pco::init_device()
{
	INFO_STREAM << "Pco::Pco() create device " << device_name << endl;

	// Initialise variables to default values
	//--------------------------------------------

    CREATE_DEVSTRING_ATTRIBUTE(attr_shutterMode_read,MAX_ATTRIBUTE_STRING_LENGTH);	
    CREATE_DEVSTRING_ATTRIBUTE(attr_pixelScanRate_read,MAX_ATTRIBUTE_STRING_LENGTH);

    m_is_device_initialized = false;
    set_state(Tango::INIT);
    m_status_message.str("");

    try
    {
        //- get the main object used to pilot the lima framework
        //in fact LimaDetector is create the singleton control objet
        //so this call, will only return existing object, no need to give it the ip !!
        m_ct = ControlFactory::instance().get_control("Pco");

        //- get interface to specific camera
		m_hw = dynamic_cast<lima::Pco::Interface*>(m_ct->hwInterface());
        if(m_hw==0)
        {
            INFO_STREAM<<"Initialization Failed : Unable to get the interface of camera plugin "<<"("<<"Pco"<<") !"<< endl;
            m_status_message <<"Initialization Failed : Unable to get the interface of camera plugin "<<"("<<"Pco"<<") !"<< endl;
            m_is_device_initialized = false;
            set_state(Tango::FAULT);
            return;
        }
		
		//- get camera to specific detector
		m_camera = (m_hw->getCamera());
		if(m_camera == 0)
		{
			INFO_STREAM<<"Initialization Failed : Unable to get the camera of plugin !"<<endl;
			m_status_message <<"Initialization Failed : Unable to get the camera object !"<< endl;
			m_is_device_initialized = false;
			set_state(Tango::FAULT);
			return;			
		}		
	
    }
    catch(Exception& e)
    {
        INFO_STREAM<<"Initialization Failed : "<<e.getErrMsg()<<endl;
        m_status_message <<"Initialization Failed : "<<e.getErrMsg( )<< endl;
        m_is_device_initialized = false;
        set_state(Tango::FAULT);
        return;
    }
    catch(...)
    {
        INFO_STREAM<<"Initialization Failed : UNKNOWN"<<endl;
        m_status_message <<"Initialization Failed : UNKNOWN"<< endl;
        set_state(Tango::FAULT);
        m_is_device_initialized = false;
        return;
    }
		
	m_is_device_initialized = true;		
    set_state(Tango::STANDBY);
    this->dev_state();

}

//+----------------------------------------------------------------------------
//
// method : 		Pco::always_executed_hook()
// 
// description : 	method always executed before any command is executed
//
//-----------------------------------------------------------------------------
void Pco::always_executed_hook()
{
    try
	{
	    m_status_message.str("");
		//- get the singleton control objet used to pilot the lima framework
		m_ct = ControlFactory::instance().get_control("Pco");

		//- get interface to specific detector
		if(m_ct!=0)
			m_hw = dynamic_cast<lima::Pco::Interface*>(m_ct->hwInterface());
		//- get camera to specific detector
		m_camera = (m_hw->getCamera());
		this->dev_state();

	}
	catch(Exception& e)
	{
		ERROR_STREAM << e.getErrMsg() << endl;
		m_status_message <<"Initialization Failed : "<<e.getErrMsg( )<< endl;
		//- throw exception
		set_state(Tango::FAULT);
		m_is_device_initialized = false;
		return;
	}
	catch(...)
	{
		ERROR_STREAM<<"Initialization Failed : UNKNOWN"<<endl;
		m_status_message <<"Initialization Failed : UNKNOWN"<< endl;
		//- throw exception
		set_state(Tango::FAULT);
		m_is_device_initialized = false;
		return;
	}
	
}
//+----------------------------------------------------------------------------
//
// method : 		Pco::read_attr_hardware
// 
// description : 	Hardware acquisition for attributes.
//
//-----------------------------------------------------------------------------
void Pco::read_attr_hardware(vector<long> &attr_list)
{
	DEBUG_STREAM << "Pco::read_attr_hardware(vector<long> &attr_list) entering... "<< endl;
	//	Add your own code here
}

//+----------------------------------------------------------------------------
//
// method : 		Pco::read_shutterMode
// 
// description : 	Extract real attribute values for shutterMode acquisition result.
//
//-----------------------------------------------------------------------------
void Pco::read_shutterMode(Tango::Attribute &attr)
{
	DEBUG_STREAM << "Pco::read_shutterMode(Tango::Attribute &attr) entering... "<< endl;

    try
    {
        *attr_shutterMode_read = m_camera->talk("rollingShutter");
        attr.set_value(attr_shutterMode_read);
    }
    catch(Tango::DevFailed& df)
    {
        ERROR_STREAM << df << endl;
        //- rethrow exception
        Tango::Except::re_throw_exception(df,
                    static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                    static_cast<const char*> (string(df.errors[0].desc).c_str()),
                    static_cast<const char*> ("Pco::read_shutterMode"));
    }			
}

//+----------------------------------------------------------------------------
//
// method : 		Pco::write_shutterMode
// 
// description : 	Write shutterMode attribute values to hardware.
//
//-----------------------------------------------------------------------------
void Pco::write_shutterMode(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "Pco::write_shutterMode(Tango::WAttribute &attr) entering... "<< endl;

    try
    {
        attr.get_write_value(attr_shutterMode_write);
		string cmd = "rollingShutter " + string(attr_shutterMode_write);
        
        m_camera->talk((char*)cmd.c_str());
    }
    catch(Tango::DevFailed& df)
    {
        ERROR_STREAM << df << endl;
        //- rethrow exception
        Tango::Except::re_throw_exception(df,
                    static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                    static_cast<const char*> (string(df.errors[0].desc).c_str()),
                    static_cast<const char*> ("Pco::write_shutterMode"));
    }			
}

//+----------------------------------------------------------------------------
//
// method : 		Pco::read_pixelScanRate
// 
// description : 	Extract real attribute values for pixelScanRate acquisition result.
//
//-----------------------------------------------------------------------------
void Pco::read_pixelScanRate(Tango::Attribute &attr)
{
	DEBUG_STREAM << "Pco::read_pixelScanRate(Tango::Attribute &attr) entering... "<< endl;

	try
    {
        *attr_pixelScanRate_read = m_camera->talk("pixelRate");
        attr.set_value(attr_pixelScanRate_read);
    }
    catch(Tango::DevFailed& df)
    {
        ERROR_STREAM << df << endl;
        //- rethrow exception
        Tango::Except::re_throw_exception(df,
                    static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                    static_cast<const char*> (string(df.errors[0].desc).c_str()),
                    static_cast<const char*> ("Pco::read_pixelScanRate"));
    }			
}

//+----------------------------------------------------------------------------
//
// method : 		Pco::write_pixelScanRate
// 
// description : 	Write pixelScanRate attribute values to hardware.
//
//-----------------------------------------------------------------------------
void Pco::write_pixelScanRate(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "Pco::write_pixelScanRate(Tango::WAttribute &attr) entering... "<< endl;

	try
    {
        attr.get_write_value(attr_pixelScanRate_write);
		string cmd = "pixelRate " + string(attr_pixelScanRate_write);
        
        m_camera->talk((char*)cmd.c_str());
    }
    catch(Tango::DevFailed& df)
    {
        ERROR_STREAM << df << endl;
        //- rethrow exception
        Tango::Except::re_throw_exception(df,
                    static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                    static_cast<const char*> (string(df.errors[0].desc).c_str()),
                    static_cast<const char*> ("Pco::write_shutterMode"));
    }			
}



//+------------------------------------------------------------------
/**
 *	method:	Pco::talk
 *
 *	description:	method to execute "Talk"
 *	A direct command to talk to de camera
 *
 * @param	argin	str argin
 * @return	str argout
 *
 */
//+------------------------------------------------------------------
Tango::DevString Pco::talk(Tango::DevString argin)
{
	//	POGO has generated a method core with argout allocation.
	//	If you would like to use a static reference without copying,
	//	See "TANGO Device Server Programmer's Manual"
	//		(chapter : Writing a TANGO DS / Exchanging data)
	//------------------------------------------------------------
	Tango::DevString	argout  = new char[MAX_ATTRIBUTE_STRING_LENGTH];
	strcpy(argout, "dummy");
	DEBUG_STREAM << "Pco::talk(): entering... !" << endl;

	//	Add your own code to control device here
        
	argout = m_camera->talk(argin);

	return argout;
}

}	//	namespace
