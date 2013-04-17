static const char *RcsId = "$Id:  $";
//+=============================================================================
//
// file :         BaslerCCD.cpp
//
// description :  C++ source for the BaslerCCD and its commands.
//                The class is derived from Device. It represents the
//                CORBA servant object which will be accessed from the
//                network. All commands which can be executed on the
//                BaslerCCD are implemented in this file.
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
//          This file is generated by POGO
//    (Program Obviously used to Generate tango Object)
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
//
//===================================================================
#ifdef WIN32
#include "tango.h"
#include <PogoHelper.h>
#endif

#include <BaslerCCD.h>
#include <BaslerCCDClass.h>

#ifndef WIN32
#include "tango.h"
#include <PogoHelper.h>
#endif

namespace BaslerCCD_ns
{

//+----------------------------------------------------------------------------
//
// method :         BaslerCCD::BaslerCCD(string &s)
//
// description :     constructor for simulated BaslerCCD
//
// in : - cl : Pointer to the DeviceClass object
//      - s : Device name
//
//-----------------------------------------------------------------------------

BaslerCCD::BaslerCCD(Tango::DeviceClass *cl, string &s)
: Tango::Device_4Impl(cl, s.c_str())
{
    init_device();
}

BaslerCCD::BaslerCCD(Tango::DeviceClass *cl, const char *s)
: Tango::Device_4Impl(cl, s)
{
    init_device();
}

BaslerCCD::BaslerCCD(Tango::DeviceClass *cl, const char *s, const char *d)
: Tango::Device_4Impl(cl, s, d)
{
    init_device();
}
//+----------------------------------------------------------------------------
//
// method :         BaslerCCD::delete_device()
//
// description :     will be called at device destruction or at init command.
//
//-----------------------------------------------------------------------------

void BaslerCCD::delete_device()
{
    INFO_STREAM << "BaslerCCD::BaslerCCD() delete device " << device_name << endl;
    //    Delete device allocated objects
    DELETE_SCALAR_ATTRIBUTE(attr_frameRate_read);
    DELETE_SCALAR_ATTRIBUTE(attr_temperature_read);
    DELETE_SCALAR_ATTRIBUTE(attr_gain_read);
    DELETE_SCALAR_ATTRIBUTE(attr_autoGain_read);    

    //!!!! ONLY LimaDetector device can do this !!!!
    //if(m_ct!=0)
    //{
    //    ControlFactory::instance().reset("BaslerCCD");
    //    m_ct = 0;
    //}
}

//+----------------------------------------------------------------------------
//
// method :         BaslerCCD::init_device()
//
// description :     will be called at device initialization.
//
//-----------------------------------------------------------------------------

void BaslerCCD::init_device()
{
    INFO_STREAM << "BaslerCCD::BaslerCCD() create device " << device_name << endl;

    // Initialise variables to default values
    //--------------------------------------------
    get_device_property();
    CREATE_SCALAR_ATTRIBUTE(attr_frameRate_read, 0.0);
    CREATE_SCALAR_ATTRIBUTE(attr_temperature_read, 0.0);
    CREATE_SCALAR_ATTRIBUTE(attr_gain_read, 0.0);
    CREATE_SCALAR_ATTRIBUTE(attr_autoGain_read);    
    m_is_device_initialized = false;
    set_state(Tango::INIT);
    m_status_message.str("");

    try
    {
        //- get the singleton control objet used to pilot the lima framework
        m_ct = ControlFactory::instance().get_control("BaslerCCD");

        //- get interface to specific camera
        m_hw = dynamic_cast<Basler::Interface*> (m_ct->hwInterface());
        if (m_hw == 0)
        {
            ERROR_STREAM << "Initialization Failed : Unable to get the interface of camera plugin " << "(" << "BaslerCCD" << ") !" << endl;
            m_status_message << "Initialization Failed : Unable to get the interface of camera plugin " << "(" << "BaslerCCD" << ") !" << endl;
            m_is_device_initialized = false;
            set_state(Tango::FAULT);
            return;
        }

        //- get camera to specific detector
        m_camera = &(m_hw->getCamera());
        if (m_camera == 0)
        {
            INFO_STREAM << "Initialization Failed : Unable to get the camera of plugin !" << endl;
            m_status_message << "Initialization Failed : Unable to get the camera object !" << endl;
            m_is_device_initialized = false;
            set_state(Tango::FAULT);
            return;
        }
    }
    catch (Exception& e)
    {
        ERROR_STREAM << "Initialization Failed : " << e.getErrMsg() << endl;
        m_status_message << "Initialization Failed : " << e.getErrMsg() << endl;
        m_is_device_initialized = false;
        set_state(Tango::FAULT);
        return;
    }
    catch (...)
    {
        ERROR_STREAM << "Initialization Failed : UNKNOWN" << endl;
        m_status_message << "Initialization Failed : UNKNOWN" << endl;
        set_state(Tango::FAULT);
        m_is_device_initialized = false;
        return;
    }
    m_is_device_initialized = true;

    //write at init, only if device is correctly initialized
    if (m_is_device_initialized)
    {
        INFO_STREAM << "Write tango hardware at Init - autoGain." << endl;
        Tango::WAttribute &autoGain = dev_attr->get_w_attr_by_name("autoGain");
        *attr_autoGain_read = memorizedAutoGain;
        autoGain.set_write_value(*attr_autoGain_read);
        write_autoGain(autoGain);
        
        if(!memorizedAutoGain)
        {
            INFO_STREAM << "Write tango hardware at Init - gain." << endl;
            Tango::WAttribute &gain = dev_attr->get_w_attr_by_name("gain");
            *attr_gain_read = memorizedGain;
            gain.set_write_value(*attr_gain_read);
            write_gain(gain);
        }
    }

    set_state(Tango::STANDBY);
    this->dev_state();
}


//+----------------------------------------------------------------------------
//
// method :         BaslerCCD::get_device_property()
//
// description :     Read the device properties from database.
//
//-----------------------------------------------------------------------------

void BaslerCCD::get_device_property()
{
    //    Initialize your default values here (if not done with  POGO).
    //------------------------------------------------------------------

    //    Read device properties from database.(Automatic code generation)
    //------------------------------------------------------------------
	Tango::DbData	dev_prop;
	dev_prop.push_back(Tango::DbDatum("DetectorIP"));
	dev_prop.push_back(Tango::DbDatum("DetectorTimeout"));
	dev_prop.push_back(Tango::DbDatum("DetectorPacketSize"));
	dev_prop.push_back(Tango::DbDatum("MemorizedGain"));
	dev_prop.push_back(Tango::DbDatum("MemorizedAutoGain"));

	//	Call database and extract values
	//--------------------------------------------
	if (Tango::Util::instance()->_UseDb==true)
		get_db_device()->get_property(dev_prop);
	Tango::DbDatum	def_prop, cl_prop;
	BaslerCCDClass	*ds_class =
		(static_cast<BaslerCCDClass *>(get_device_class()));
	int	i = -1;

	//	Try to initialize DetectorIP from class property
	cl_prop = ds_class->get_class_property(dev_prop[++i].name);
	if (cl_prop.is_empty()==false)	cl_prop  >>  detectorIP;
	else {
		//	Try to initialize DetectorIP from default device value
		def_prop = ds_class->get_default_device_property(dev_prop[i].name);
		if (def_prop.is_empty()==false)	def_prop  >>  detectorIP;
	}
	//	And try to extract DetectorIP value from database
	if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  detectorIP;

	//	Try to initialize DetectorTimeout from class property
	cl_prop = ds_class->get_class_property(dev_prop[++i].name);
	if (cl_prop.is_empty()==false)	cl_prop  >>  detectorTimeout;
	else {
		//	Try to initialize DetectorTimeout from default device value
		def_prop = ds_class->get_default_device_property(dev_prop[i].name);
		if (def_prop.is_empty()==false)	def_prop  >>  detectorTimeout;
	}
	//	And try to extract DetectorTimeout value from database
	if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  detectorTimeout;

	//	Try to initialize DetectorPacketSize from class property
	cl_prop = ds_class->get_class_property(dev_prop[++i].name);
	if (cl_prop.is_empty()==false)	cl_prop  >>  detectorPacketSize;
	else {
		//	Try to initialize DetectorPacketSize from default device value
		def_prop = ds_class->get_default_device_property(dev_prop[i].name);
		if (def_prop.is_empty()==false)	def_prop  >>  detectorPacketSize;
	}
	//	And try to extract DetectorPacketSize value from database
	if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  detectorPacketSize;

	//	Try to initialize MemorizedGain from class property
	cl_prop = ds_class->get_class_property(dev_prop[++i].name);
	if (cl_prop.is_empty()==false)	cl_prop  >>  memorizedGain;
	else {
		//	Try to initialize MemorizedGain from default device value
		def_prop = ds_class->get_default_device_property(dev_prop[i].name);
		if (def_prop.is_empty()==false)	def_prop  >>  memorizedGain;
	}
	//	And try to extract MemorizedGain value from database
	if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  memorizedGain;

	//	Try to initialize MemorizedAutoGain from class property
	cl_prop = ds_class->get_class_property(dev_prop[++i].name);
	if (cl_prop.is_empty()==false)	cl_prop  >>  memorizedAutoGain;
	else {
		//	Try to initialize MemorizedAutoGain from default device value
		def_prop = ds_class->get_default_device_property(dev_prop[i].name);
		if (def_prop.is_empty()==false)	def_prop  >>  memorizedAutoGain;
	}
	//	And try to extract MemorizedAutoGain value from database
	if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  memorizedAutoGain;



    //    End of Automatic code generation
    //------------------------------------------------------------------
    create_property_if_empty(dev_prop, "127.0.0.1", "DetectorIP");
    create_property_if_empty(dev_prop, "11000", "DetectorTimeout");
    create_property_if_empty(dev_prop, "1500", "DetectorPacketSize");
    create_property_if_empty(dev_prop, "0", "MemorizedGain");
    create_property_if_empty(dev_prop, "False", "MemorizedAutoGain");    

}
//+----------------------------------------------------------------------------
//
// method :         BaslerCCD::always_executed_hook()
//
// description :     method always executed before any command is executed
//
//-----------------------------------------------------------------------------

void BaslerCCD::always_executed_hook()
{
    DEBUG_STREAM << "BaslerCCD::always_executed_hook() entering... " << endl;
    try
    {
        m_status_message.str("");
        //- get the singleton control objet used to pilot the lima framework
        m_ct = ControlFactory::instance().get_control("BaslerCCD");

        //- get interface to specific detector
        if (m_ct != 0)
            m_hw = dynamic_cast<Basler::Interface*> (m_ct->hwInterface());

        //- get camera to specific detector
        m_camera = &(m_hw->getCamera());

    }
    catch (Exception& e)
    {
        ERROR_STREAM << e.getErrMsg() << endl;
        m_status_message << "Initialization Failed : " << e.getErrMsg() << endl;
        //- throw exception
        set_state(Tango::FAULT);
        m_is_device_initialized = false;
        return;
    }
    catch (...)
    {
        ERROR_STREAM << "Initialization Failed : UNKNOWN" << endl;
        m_status_message << "Initialization Failed : UNKNOWN" << endl;
        //- throw exception
        set_state(Tango::FAULT);
        m_is_device_initialized = false;
        return;
    }
}
//+----------------------------------------------------------------------------
//
// method :         BaslerCCD::read_attr_hardware
//
// description :     Hardware acquisition for attributes.
//
//-----------------------------------------------------------------------------

void BaslerCCD::read_attr_hardware(vector<long> &attr_list)
{
    DEBUG_STREAM << "BaslerCCD::read_attr_hardware(vector<long> &attr_list) entering... " << endl;
    //    Add your own code here
}

//+----------------------------------------------------------------------------
//
// method :         BaslerCCD::read_frameRate
//
// description :     Extract real attribute values for frameRate acquisition result.
//
//-----------------------------------------------------------------------------

void BaslerCCD::read_frameRate(Tango::Attribute &attr)
{
    DEBUG_STREAM << "BaslerCCD::read_frameRate(Tango::Attribute &attr) entering... " << endl;
    if (m_ct != 0)
    {
        try
        {
            if (m_hw != 0)
            {
                (m_hw->getCamera()).getFrameRate((double&) *attr_frameRate_read);
                attr.set_value(attr_frameRate_read);
            }
        }
        catch (Tango::DevFailed& df)
        {
            ERROR_STREAM << df << endl;
            //- rethrow exception
            Tango::Except::re_throw_exception(df,
                                              static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                                              static_cast<const char*> (string(df.errors[0].desc).c_str()),
                                              static_cast<const char*> ("BaslerCCD::read_frameRate"));
        }
        catch (Exception& e)
        {
            ERROR_STREAM << e.getErrMsg() << endl;
            //- throw exception
            Tango::Except::throw_exception(
                                           static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                                           static_cast<const char*> (e.getErrMsg().c_str()),
                                           static_cast<const char*> ("BaslerCCD::read_frameRate"));
        }
    }
}

//+----------------------------------------------------------------------------
//
// method : 		BaslerCCD::read_temperature
// 
// description : 	Extract real attribute values for temperature acquisition result.
//
//-----------------------------------------------------------------------------

void BaslerCCD::read_temperature(Tango::Attribute &attr)
{
    DEBUG_STREAM << "BaslerCCD::read_temperature(Tango::Attribute &attr) entering... " << endl;
    if (m_ct != 0)
    {
        try
        {
            if (m_hw != 0)
            {
                (m_hw->getCamera()).getTemperature((double&) *attr_temperature_read);
                attr.set_value(attr_temperature_read);
            }
        }
        catch (Tango::DevFailed& df)
        {
            ERROR_STREAM << df << endl;
            //- rethrow exception
            Tango::Except::re_throw_exception(df,
                                              static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                                              static_cast<const char*> (string(df.errors[0].desc).c_str()),
                                              static_cast<const char*> ("BaslerCCD::read_temperature"));
        }
        catch (Exception& e)
        {
            ERROR_STREAM << e.getErrMsg() << endl;
            //- throw exception
            Tango::Except::throw_exception(
                                           static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                                           static_cast<const char*> (e.getErrMsg().c_str()),
                                           static_cast<const char*> ("BaslerCCD::read_temperature"));
        }
    }
}

//+----------------------------------------------------------------------------
//
// method : 		BaslerCCD::read_gain
// 
// description : 	Extract real attribute values for gain acquisition result.
//
//-----------------------------------------------------------------------------

void BaslerCCD::read_gain(Tango::Attribute &attr)
{
    DEBUG_STREAM << "BaslerCCD::read_gain(Tango::Attribute &attr) entering... " << endl;
    if (m_ct != 0)
    {
        try
        {
            double gain;
            if (m_hw != 0)
            {
                (m_hw->getCamera()).getGain(gain);
                *attr_gain_read = (Tango::DevDouble)(gain);
                attr.set_value(attr_gain_read);
            }
        }
        catch (Tango::DevFailed& df)
        {
            ERROR_STREAM << df << endl;
            //- rethrow exception
            Tango::Except::re_throw_exception(df,
                                              static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                                              static_cast<const char*> (string(df.errors[0].desc).c_str()),
                                              static_cast<const char*> ("LimaDetector::read_gain"));
        }
        catch (Exception& e)
        {
            ERROR_STREAM << e.getErrMsg() << endl;
            //- throw exception
            Tango::Except::throw_exception(
                                           static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                                           static_cast<const char*> (e.getErrMsg().c_str()),
                                           static_cast<const char*> ("LimaDetector::read_gain"));
        }
    }
}

//+----------------------------------------------------------------------------
//
// method : 		BaslerCCD::write_gain
// 
// description : 	Write gain attribute values to hardware.
//
//-----------------------------------------------------------------------------

void BaslerCCD::write_gain(Tango::WAttribute &attr)
{
    DEBUG_STREAM << "BaslerCCD::write_gain(Tango::WAttribute &attr) entering... " << endl;
    if (m_ct != 0)
    {
        try
        {
            if (m_hw != 0)
            {
                attr.get_write_value(attr_gain_write);
                (m_hw->getCamera()).setGain(attr_gain_write);
                set_property("MemorizedGain", attr_gain_write);
            }
        }
        catch (Tango::DevFailed& df)
        {
            ERROR_STREAM << df << endl;
            //- rethrow exception
            Tango::Except::re_throw_exception(df,
                                              static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                                              static_cast<const char*> (string(df.errors[0].desc).c_str()),
                                              static_cast<const char*> ("LimaDetector::write_gain"));
        }
        catch (Exception& e)
        {
            ERROR_STREAM << e.getErrMsg() << endl;
            //- throw exception
            Tango::Except::throw_exception(
                                           static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                                           static_cast<const char*> (e.getErrMsg().c_str()),
                                           static_cast<const char*> ("LimaDetector::write_gain"));
        }
    }
}

//+----------------------------------------------------------------------------
//
// method : 		BaslerCCD::read_autoGain
// 
// description : 	Extract real attribute values for autoGain acquisition result.
//
//-----------------------------------------------------------------------------
void BaslerCCD::read_autoGain(Tango::Attribute &attr)
{
	DEBUG_STREAM << "BaslerCCD::read_autoGain(Tango::Attribute &attr) entering... "<< endl;
    if (m_ct != 0)
    {
        try
        {
            bool bAutoGain;
            if (m_hw != 0)
            {
                (m_hw->getCamera()).getAutoGain(bAutoGain);
                *attr_autoGain_read = (Tango::DevBoolean)(bAutoGain);
                attr.set_value(attr_autoGain_read);
            }
        }
        catch (Tango::DevFailed& df)
        {
            ERROR_STREAM << df << endl;
            //- rethrow exception
            Tango::Except::re_throw_exception(df,
                                              static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                                              static_cast<const char*> (string(df.errors[0].desc).c_str()),
                                              static_cast<const char*> ("LimaDetector::read_autoGain"));
        }
        catch (Exception& e)
        {
            ERROR_STREAM << e.getErrMsg() << endl;
            //- throw exception
            Tango::Except::throw_exception(
                                           static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                                           static_cast<const char*> (e.getErrMsg().c_str()),
                                           static_cast<const char*> ("LimaDetector::read_autoGain"));
        }
    }    
}

//+----------------------------------------------------------------------------
//
// method : 		BaslerCCD::write_autoGain
// 
// description : 	Write autoGain attribute values to hardware.
//
//-----------------------------------------------------------------------------
void BaslerCCD::write_autoGain(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "BaslerCCD::write_autoGain(Tango::WAttribute &attr) entering... "<< endl;
    if (m_ct != 0)
    {
        try
        {
            if (m_hw != 0)
            {
                attr.get_write_value(attr_autoGain_write);
                (m_hw->getCamera()).setAutoGain(attr_autoGain_write);
                set_property("MemorizedAutoGain", attr_autoGain_write);
            }
        }
        catch (Tango::DevFailed& df)
        {
            ERROR_STREAM << df << endl;
            //- rethrow exception
            Tango::Except::re_throw_exception(df,
                                              static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                                              static_cast<const char*> (string(df.errors[0].desc).c_str()),
                                              static_cast<const char*> ("LimaDetector::write_autoGain"));
        }
        catch (Exception& e)
        {
            ERROR_STREAM << e.getErrMsg() << endl;
            //- throw exception
            Tango::Except::throw_exception(
                                           static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                                           static_cast<const char*> (e.getErrMsg().c_str()),
                                           static_cast<const char*> ("LimaDetector::write_autoGain"));
        }
    }    
}

//+------------------------------------------------------------------
/**
 *    method:    BaslerCCD::dev_state
 *
 *    description:    method to execute "State"
 *    This command gets the device state (stored in its <i>device_state</i> data member) and returns it to the caller.
 *
 * @return    State Code
 *
 */
//+------------------------------------------------------------------

Tango::DevState BaslerCCD::dev_state()
{
    Tango::DevState argout = DeviceImpl::dev_state();
    DEBUG_STREAM << "BaslerCCD::dev_state(): entering... !" << endl;
    //    Add your own code to control device here

    stringstream DeviceStatus;
    DeviceStatus << "";
    Tango::DevState DeviceState = Tango::STANDBY;
    if (!m_is_device_initialized)
    {
        DeviceState = Tango::FAULT;
        DeviceStatus << m_status_message.str();
    }
    else
    {
        //state&status are retrieved from specific device
        DeviceState = ControlFactory::instance().get_state();
        DeviceStatus << ControlFactory::instance().get_status();
    }

    set_state(DeviceState);
    set_status(DeviceStatus.str());

    argout = DeviceState;
    return argout;
}

/*-------------------------------------------------------------------------
//       BaslerCCD::set_property
/-------------------------------------------------------------------------*/
template <class T>
void BaslerCCD::set_property(string property_name, T value)
{
    if (!Tango::Util::instance()->_UseDb)
    {
        //- rethrow exception
        Tango::Except::throw_exception(static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                                       static_cast<const char*> ("NO DB"),
                                       static_cast<const char*> ("BaslerCCD::set_property"));
    }

    Tango::DbDatum current_value(property_name);
    current_value << value;
    Tango::DbData db_data;
    db_data.push_back(current_value);
    try
    {
        get_db_device()->put_property(db_data);
    }
    catch (Tango::DevFailed &df)
    {
        string message = "Error in storing " + property_name + " in Configuration DataBase ";
        LOG_ERROR((message));
        ERROR_STREAM << df << endl;
        //- rethrow exception
        Tango::Except::re_throw_exception(df,
                                          static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                                          static_cast<const char*> (string(df.errors[0].desc).c_str()),
                                          static_cast<const char*> ("BaslerCCD::set_property"));
    }
}

/*-------------------------------------------------------------------------
//       BaslerCCD::get_property
/-------------------------------------------------------------------------*/
template <class T>
T BaslerCCD::get_property(string property_name)
{
    if (!Tango::Util::instance()->_UseDb)
    {
        //- rethrow exception
        Tango::Except::throw_exception(static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                                       static_cast<const char*> ("NO DB"),
                                       static_cast<const char*> ("BaslerCCD::get_property"));
    }

    T value;
    Tango::DbDatum current_value(property_name);
    Tango::DbData db_data;
    db_data.push_back(current_value);
    try
    {
        get_db_device()->get_property(db_data);
    }
    catch (Tango::DevFailed &df)
    {
        string message = "Error in reading " + property_name + " in Configuration DataBase ";
        LOG_ERROR((message));
        ERROR_STREAM << df << endl;
        //- rethrow exception
        Tango::Except::re_throw_exception(df,
                                          static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                                          static_cast<const char*> (string(df.errors[0].desc).c_str()),
                                          static_cast<const char*> ("BaslerCCD::get_property"));
    }
    db_data[0] >> value;
    return (value);
}

/*-------------------------------------------------------------------------
//       BaslerCCD::create_property_if_empty
/-------------------------------------------------------------------------*/
template <class T>
void BaslerCCD::create_property_if_empty(Tango::DbData& dev_prop, T value, string property_name)
{
    int iPropertyIndex = find_index_from_property_name(dev_prop, property_name);
    if (iPropertyIndex == -1) return;
    if (dev_prop[iPropertyIndex].is_empty())
    {
        Tango::DbDatum current_value(dev_prop[iPropertyIndex].name);
        current_value << value;
        Tango::DbData db_data;
        db_data.push_back(current_value);

        try
        {
            get_db_device()->put_property(db_data);
        }
        catch (Tango::DevFailed &df)
        {
            string message = "Error in storing " + property_name + " in Configuration DataBase ";
            LOG_ERROR((message));
            ERROR_STREAM << df << endl;
            //- rethrow exception
            Tango::Except::re_throw_exception(df,
                                              static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                                              static_cast<const char*> (string(df.errors[0].desc).c_str()),
                                              static_cast<const char*> ("BaslerCCD::create_property_if_empty"));
        }
    }
}

/*-------------------------------------------------------------------------
//       BaslerCCD::find_index_from_property_name
/-------------------------------------------------------------------------*/
int BaslerCCD::find_index_from_property_name(Tango::DbData& dev_prop, string property_name)
{
    size_t iNbProperties = dev_prop.size();
    unsigned int i;
    for (i = 0; i < iNbProperties; i++)
    {
        string sPropertyName(dev_prop[i].name);
        if (sPropertyName == property_name) return i;
    }
    if (i == iNbProperties) return -1;
    return i;
}














}	//	namespace
