static const char *ClassId    = "$Id:  $";
static const char *TagName    = "$Name:  $";
static const char *CvsPath    = "$Source:  $";
static const char *SvnPath    = "$HeadURL: $";
static const char *HttpServer = "http://www.esrf.fr/computing/cs/tango/tango_doc/ds_doc/";
//+=============================================================================
//
// file :        XpadPixelDetectorClass.cpp
//
// description : C++ source for the XpadPixelDetectorClass. A singleton
//               class derived from DeviceClass. It implements the
//               command list and all properties and methods required
//               by the XpadPixelDetector once per process.
//
// project :     TANGO Device Server
//
// $Author:  $
//
// $Revision:  $
//
// $Log:  $
//
// copyleft :   European Synchrotron Radiation Facility
//              BP 220, Grenoble 38043
//              FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================


#ifdef WIN32
#include "tango.h"
#endif

#include <XpadPixelDetector.h>
#include <XpadPixelDetectorClass.h>

#ifndef WIN32
#include "tango.h"
#endif

//+----------------------------------------------------------------------------
/**
 *	Create XpadPixelDetectorClass singleton and return it in a C function for Python usage
 */
//+----------------------------------------------------------------------------
extern "C" {
#ifdef WIN32

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_XpadPixelDetector_class(const char *name) {
		return XpadPixelDetector_ns::XpadPixelDetectorClass::init(name);
	}
}


namespace XpadPixelDetector_ns
{
//+----------------------------------------------------------------------------
//
// method : 		GetIthlCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *GetIthlCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "GetIthlCmd::execute(): arrived" << endl;

	return insert((static_cast<XpadPixelDetector *>(device))->get_ithl());
}

//+----------------------------------------------------------------------------
//
// method : 		GetDaclCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *GetDaclCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "GetDaclCmd::execute(): arrived" << endl;

	return insert((static_cast<XpadPixelDetector *>(device))->get_dacl());
}

//+----------------------------------------------------------------------------
//
// method : 		DecrementITHLClass::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *DecrementITHLClass::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "DecrementITHLClass::execute(): arrived" << endl;

	((static_cast<XpadPixelDetector *>(device))->decrement_ithl());
	return new CORBA::Any();
}

//+----------------------------------------------------------------------------
//
// method : 		IncrementITHLClass::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *IncrementITHLClass::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "IncrementITHLClass::execute(): arrived" << endl;

	((static_cast<XpadPixelDetector *>(device))->increment_ithl());
	return new CORBA::Any();
}

//+----------------------------------------------------------------------------
//
// method : 		UploadWaitTimesClass::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *UploadWaitTimesClass::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "UploadWaitTimesClass::execute(): arrived" << endl;

	const Tango::DevVarULongArray	*argin;
	extract(in_any, argin);

	((static_cast<XpadPixelDetector *>(device))->upload_wait_times(argin));
	return new CORBA::Any();
}

//+----------------------------------------------------------------------------
//
// method : 		UploadCalibrationCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *UploadCalibrationCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "UploadCalibrationCmd::execute(): arrived" << endl;

	((static_cast<XpadPixelDetector *>(device))->upload_calibration());
	return new CORBA::Any();
}

//+----------------------------------------------------------------------------
//
// method : 		CalibrateOTNSlowCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *CalibrateOTNSlowCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "CalibrateOTNSlowCmd::execute(): arrived" << endl;

	((static_cast<XpadPixelDetector *>(device))->calibrate_otnslow());
	return new CORBA::Any();
}



//+----------------------------------------------------------------------------
//
// method : 		ResetClass::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *ResetClass::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "ResetClass::execute(): arrived" << endl;

	((static_cast<XpadPixelDetector *>(device))->reset());
	return new CORBA::Any();
}

//+----------------------------------------------------------------------------
//
// method : 		LoadConfigCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *LoadConfigCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "LoadConfigCmd::execute(): arrived" << endl;

	const Tango::DevVarULongArray	*argin;
	extract(in_any, argin);

	((static_cast<XpadPixelDetector *>(device))->load_config(argin));
	return new CORBA::Any();
}


//+----------------------------------------------------------------------------
//
// method : 		SaveConfigGCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *SaveConfigGCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "SaveConfigGCmd::execute(): arrived" << endl;

	const Tango::DevVarULongArray	*argin;
	extract(in_any, argin);

	((static_cast<XpadPixelDetector *>(device))->save_config_g(argin));
	return new CORBA::Any();
}

//+----------------------------------------------------------------------------
//
// method : 		SaveConfigLCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *SaveConfigLCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "SaveConfigLCmd::execute(): arrived" << endl;

	const Tango::DevVarULongArray	*argin;
	extract(in_any, argin);

	((static_cast<XpadPixelDetector *>(device))->save_config_l(argin));
	return new CORBA::Any();
}

//+----------------------------------------------------------------------------
//
// method : 		LoadAllConfigGCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *LoadAllConfigGCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "LoadAllConfigGCmd::execute(): arrived" << endl;

	const Tango::DevVarULongArray	*argin;
	extract(in_any, argin);

	((static_cast<XpadPixelDetector *>(device))->load_all_config_g(argin));
	return new CORBA::Any();
}

//+----------------------------------------------------------------------------
//
// method : 		LoadFlatConfigCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be executed
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *LoadFlatConfigCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "LoadFlatConfigCmd::execute(): arrived" << endl;

	Tango::DevULong	argin;
	extract(in_any, argin);

	((static_cast<XpadPixelDetector *>(device))->load_flat_config(argin));
	return new CORBA::Any();
}




//
//----------------------------------------------------------------
//	Initialize pointer for singleton pattern
//----------------------------------------------------------------
//
XpadPixelDetectorClass *XpadPixelDetectorClass::_instance = NULL;

//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetectorClass::XpadPixelDetectorClass(string &s)
// 
// description : 	constructor for the XpadPixelDetectorClass
//
// in : - s : The class name
//
//-----------------------------------------------------------------------------
XpadPixelDetectorClass::XpadPixelDetectorClass(string &s):DeviceClass(s)
{

	cout2 << "Entering XpadPixelDetectorClass constructor" << endl;
	set_default_property();
	get_class_property();
	write_class_property();
	
	cout2 << "Leaving XpadPixelDetectorClass constructor" << endl;

}
//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetectorClass::~XpadPixelDetectorClass()
// 
// description : 	destructor for the XpadPixelDetectorClass
//
//-----------------------------------------------------------------------------
XpadPixelDetectorClass::~XpadPixelDetectorClass()
{
	_instance = NULL;
}

//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetectorClass::instance
// 
// description : 	Create the object if not already done. Otherwise, just
//			return a pointer to the object
//
// in : - name : The class name
//
//-----------------------------------------------------------------------------
XpadPixelDetectorClass *XpadPixelDetectorClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new XpadPixelDetectorClass(s);
		}
		catch (bad_alloc)
		{
			throw;
		}		
	}		
	return _instance;
}

XpadPixelDetectorClass *XpadPixelDetectorClass::instance()
{
	if (_instance == NULL)
	{
		cerr << "Class is not initialised !!" << endl;
		exit(-1);
	}
	return _instance;
}

//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetectorClass::command_factory
// 
// description : 	Create the command object(s) and store them in the 
//			command list
//
//-----------------------------------------------------------------------------
void XpadPixelDetectorClass::command_factory()
{
	command_list.push_back(new LoadFlatConfigCmd("LoadFlatConfig",
		Tango::DEV_ULONG, Tango::DEV_VOID,
		"Flat value to be loaded",
		"",
		Tango::OPERATOR));
	command_list.push_back(new LoadAllConfigGCmd("LoadAllConfigG",
		Tango::DEVVAR_ULONGARRAY, Tango::DEV_VOID,
		"modNum(1..8), chipId(0..6), config_values (11 values)",
		"",
		Tango::OPERATOR));
	command_list.push_back(new SaveConfigLCmd("SaveConfigL",
		Tango::DEVVAR_ULONGARRAY, Tango::DEV_VOID,
		"modNum(1..8), calibId(0..6), chipId(0..7), curRow (0..119), values (80 values)",
		"",
		Tango::OPERATOR));
	command_list.push_back(new SaveConfigGCmd("SaveConfigG",
		Tango::DEVVAR_ULONGARRAY, Tango::DEV_VOID,
		"modNum(1..8), calibId(0..6), reg, values (7 values)",
		"",
		Tango::OPERATOR));
	command_list.push_back(new LoadConfigCmd("LoadConfig",
		Tango::DEVVAR_ULONGARRAY, Tango::DEV_VOID,
		"modNum(1..8), calibId(0..6)",
		"",
		Tango::OPERATOR));
	command_list.push_back(new ResetClass("Reset",
		Tango::DEV_VOID, Tango::DEV_VOID,
		"",
		"",
		Tango::OPERATOR));
	command_list.push_back(new GetDaclCmd("GetDacl",
		Tango::DEV_VOID, Tango::DEVVAR_USHORTARRAY,
		"",
		"array of DACL data",
		Tango::OPERATOR));
	command_list.push_back(new GetIthlCmd("GetIthl",
		Tango::DEV_VOID, Tango::DEVVAR_USHORTARRAY,
		"",
		"array of ITHL data",
		Tango::OPERATOR));
	command_list.push_back(new CalibrateOTNSlowCmd("CalibrateOTNSlow",
		Tango::DEV_VOID, Tango::DEV_VOID,
		"",
		"",
		Tango::OPERATOR));
	command_list.push_back(new UploadCalibrationCmd("UploadCalibration",
		Tango::DEV_VOID, Tango::DEV_VOID,
		"",
		"",
		Tango::OPERATOR));
	command_list.push_back(new UploadWaitTimesClass("UploadWaitTimes",
		Tango::DEVVAR_ULONGARRAY, Tango::DEV_VOID,
		"the wait times",
		"",
		Tango::OPERATOR));
	command_list.push_back(new IncrementITHLClass("IncrementITHL",
		Tango::DEV_VOID, Tango::DEV_VOID,
		"",
		"",
		Tango::OPERATOR));
	command_list.push_back(new DecrementITHLClass("DecrementITHL",
		Tango::DEV_VOID, Tango::DEV_VOID,
		"",
		"",
		Tango::OPERATOR));

	//	add polling if any
	for (unsigned int i=0 ; i<command_list.size(); i++)
	{
	}
}

//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetectorClass::get_class_property
// 
// description : 	Get the class property for specified name.
//
// in :		string	name : The property name
//
//+----------------------------------------------------------------------------
Tango::DbDatum XpadPixelDetectorClass::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}
//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetectorClass::get_default_device_property()
// 
// description : 	Return the default value for device property.
//
//-----------------------------------------------------------------------------
Tango::DbDatum XpadPixelDetectorClass::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetectorClass::get_default_class_property()
// 
// description : 	Return the default value for class property.
//
//-----------------------------------------------------------------------------
Tango::DbDatum XpadPixelDetectorClass::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}
//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetectorClass::device_factory
// 
// description : 	Create the device object(s) and store them in the 
//			device list
//
// in :		Tango::DevVarStringArray *devlist_ptr : The device name list
//
//-----------------------------------------------------------------------------
void XpadPixelDetectorClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{

	//	Create all devices.(Automatic code generation)
	//-------------------------------------------------------------
	for (unsigned long i=0 ; i < devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
						
		// Create devices and add it into the device list
		//----------------------------------------------------
		device_list.push_back(new XpadPixelDetector(this, (*devlist_ptr)[i]));							 

		// Export device to the outside world
		// Check before if database used.
		//---------------------------------------------
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(device_list.back());
		else
			export_device(device_list.back(), (*devlist_ptr)[i]);
	}
	//	End of Automatic code generation
	//-------------------------------------------------------------

}
//+----------------------------------------------------------------------------
//	Method: XpadPixelDetectorClass::attribute_factory(vector<Tango::Attr *> &att_list)
//-----------------------------------------------------------------------------
void XpadPixelDetectorClass::attribute_factory(vector<Tango::Attr *> &att_list)
{
	//	Attribute : deadTime
	deadTimeAttrib	*dead_time = new deadTimeAttrib();
	Tango::UserDefaultAttrProp	dead_time_prop;
	dead_time_prop.set_unit(" ");
	dead_time->set_default_properties(dead_time_prop);
	dead_time->set_disp_level(Tango::EXPERT);
	att_list.push_back(dead_time);

	//	Attribute : init
	initAttrib	*init = new initAttrib();
	Tango::UserDefaultAttrProp	init_prop;
	init_prop.set_unit(" ");
	init->set_default_properties(init_prop);
	init->set_disp_level(Tango::EXPERT);
	att_list.push_back(init);

	//	Attribute : shutter
	shutterAttrib	*shutter = new shutterAttrib();
	Tango::UserDefaultAttrProp	shutter_prop;
	shutter_prop.set_unit(" ");
	shutter->set_default_properties(shutter_prop);
	shutter->set_disp_level(Tango::EXPERT);
	att_list.push_back(shutter);

	//	Attribute : ovf
	ovfAttrib	*ovf = new ovfAttrib();
	Tango::UserDefaultAttrProp	ovf_prop;
	ovf_prop.set_unit(" ");
	ovf->set_default_properties(ovf_prop);
	ovf->set_disp_level(Tango::EXPERT);
	att_list.push_back(ovf);

	//	Attribute : n
	nAttrib	*n = new nAttrib();
	Tango::UserDefaultAttrProp	n_prop;
	n_prop.set_unit(" ");
	n->set_default_properties(n_prop);
	n->set_disp_level(Tango::EXPERT);
	att_list.push_back(n);

	//	Attribute : p
	pAttrib	*p = new pAttrib();
	Tango::UserDefaultAttrProp	p_prop;
	p_prop.set_unit(" ");
	p->set_default_properties(p_prop);
	p->set_disp_level(Tango::EXPERT);
	att_list.push_back(p);

	//	Attribute : gp1
	gp1Attrib	*gp1 = new gp1Attrib();
	Tango::UserDefaultAttrProp	gp1_prop;
	gp1_prop.set_unit(" ");
	gp1->set_default_properties(gp1_prop);
	gp1->set_disp_level(Tango::EXPERT);
	att_list.push_back(gp1);

	//	Attribute : gp2
	gp2Attrib	*gp2 = new gp2Attrib();
	Tango::UserDefaultAttrProp	gp2_prop;
	gp2_prop.set_unit(" ");
	gp2->set_default_properties(gp2_prop);
	gp2->set_disp_level(Tango::EXPERT);
	att_list.push_back(gp2);

	//	Attribute : gp3
	gp3Attrib	*gp3 = new gp3Attrib();
	Tango::UserDefaultAttrProp	gp3_prop;
	gp3_prop.set_unit(" ");
	gp3->set_default_properties(gp3_prop);
	gp3->set_disp_level(Tango::EXPERT);
	att_list.push_back(gp3);

	//	Attribute : gp4
	gp4Attrib	*gp4 = new gp4Attrib();
	Tango::UserDefaultAttrProp	gp4_prop;
	gp4_prop.set_unit(" ");
	gp4->set_default_properties(gp4_prop);
	gp4->set_disp_level(Tango::EXPERT);
	att_list.push_back(gp4);

	//	Attribute : dacl
	daclAttrib	*dacl = new daclAttrib();
	Tango::UserDefaultAttrProp	dacl_prop;
	dacl_prop.set_label("Dacl matrix");
	dacl_prop.set_description("Calibrated Dacl Matrix");
	dacl->set_default_properties(dacl_prop);
	att_list.push_back(dacl);

	//	Attribute : ithl
	ithlAttrib	*ithl = new ithlAttrib();
	Tango::UserDefaultAttrProp	ithl_prop;
	ithl_prop.set_label("Ithl matrix");
	ithl_prop.set_description("Calibrated Ithl matrix");
	ithl->set_default_properties(ithl_prop);
	att_list.push_back(ithl);

	//	End of Automatic code generation
	//-------------------------------------------------------------
}

//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetectorClass::get_class_property()
// 
// description : 	Read the class properties from database.
//
//-----------------------------------------------------------------------------
void XpadPixelDetectorClass::get_class_property()
{
	//	Initialize your default values here (if not done with  POGO).
	//------------------------------------------------------------------

	//	Read class properties from database.(Automatic code generation)
	//------------------------------------------------------------------

	//	Call database and extract values
	//--------------------------------------------
	if (Tango::Util::instance()->_UseDb==true)
		get_db_class()->get_property(cl_prop);
	Tango::DbDatum	def_prop;
	int	i = -1;


	//	End of Automatic code generation
	//------------------------------------------------------------------

}

//+----------------------------------------------------------------------------
//
// method : 	XpadPixelDetectorClass::set_default_property
// 
// description: Set default property (class and device) for wizard.
//              For each property, add to wizard property name and description
//              If default value has been set, add it to wizard property and
//              store it in a DbDatum.
//
//-----------------------------------------------------------------------------
void XpadPixelDetectorClass::set_default_property()
{
	string	prop_name;
	string	prop_desc;
	string	prop_def;

	vector<string>	vect_data;
	//	Set Default Class Properties
	//	Set Default Device Properties
	prop_name = "AcquisitionType";
	prop_desc = "Type of Acquisition:<BR>\n0->SYNC<BR>\n1->ASYNC (not supported yet)";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "AllConfigG";
	prop_desc = "list of the all config G, that will be used by the command LoadAllConfigG:<BR>\nCMOS_DSBL<BR>\nAMP_TP<BR>\nITHH<BR>\nVADJ<BR>\nVREF<BR>\nIMFP<BR>\nIOTA<BR>\nIPRE<BR>\nITHL<BR>\nITUNE<BR>\nIBUFFER<BR>";
	prop_def  = "0\n0\n0\n0\n0\n0\n0\n0\n0\n0";
	vect_data.clear();
	vect_data.push_back("0");
	vect_data.push_back("0");
	vect_data.push_back("0");
	vect_data.push_back("0");
	vect_data.push_back("0");
	vect_data.push_back("0");
	vect_data.push_back("0");
	vect_data.push_back("0");
	vect_data.push_back("0");
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "XpadModel";
	prop_desc = "Define the model of the XPAD (architecture)<BR>\nAvailables models :<BR>\n- BACKPLANE<BR>\n- IMXPAD_S70<BR>\n- IMXPAD_S140<BR>\n- IMXPAD_S340<BR>\n- IMXPAD_S540<BR>";
	prop_def  = "UNKNOWN";
	vect_data.clear();
	vect_data.push_back("UNKNOWN");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "CalibrationPath";
	prop_desc = "Path where the calibration files will be save, and from where the calibrations will be uploaded via an UploadCalibration command";
	prop_def  = "/no/path/defined";
	vect_data.clear();
	vect_data.push_back("/no/path/defined");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

}
//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetectorClass::write_class_property
// 
// description : 	Set class description as property in database
//
//-----------------------------------------------------------------------------
void XpadPixelDetectorClass::write_class_property()
{
	//	First time, check if database used
	//--------------------------------------------
	if (Tango::Util::_UseDb == false)
		return;

	Tango::DbData	data;
	string	classname = get_name();
	string	header;
	string::size_type	start, end;

	//	Put title
	Tango::DbDatum	title("ProjectTitle");
	string	str_title("XPAD Pixel Detector from Lima");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("This is the Xpad 3.2 (PCIe) Pixel Detector device, which uses Lima");
	description << str_desc;
	data.push_back(description);
		
	//	put cvs or svn location
	string	filename(classname);
	filename += "Class.cpp";
	
	// Create a string with the class ID to
	// get the string into the binary
	string	class_id(ClassId);
	
	// check for cvs information
	string	src_path(CvsPath);
	start = src_path.find("/");
	if (start!=string::npos)
	{
		end   = src_path.find(filename);
		if (end>start)
		{
			string	strloc = src_path.substr(start, end-start);
			//	Check if specific repository
			start = strloc.find("/cvsroot/");
			if (start!=string::npos && start>0)
			{
				string	repository = strloc.substr(0, start);
				if (repository.find("/segfs/")!=string::npos)
					strloc = "ESRF:" + strloc.substr(start, strloc.length()-start);
			}
			Tango::DbDatum	cvs_loc("cvs_location");
			cvs_loc << strloc;
			data.push_back(cvs_loc);
		}
	}
	// check for svn information
	else
	{
		string	src_path(SvnPath);
		start = src_path.find("://");
		if (start!=string::npos)
		{
			end = src_path.find(filename);
			if (end>start)
			{
				header = "$HeadURL: ";
				start = header.length();
				string	strloc = src_path.substr(start, (end-start));
				
				Tango::DbDatum	svn_loc("svn_location");
				svn_loc << strloc;
				data.push_back(svn_loc);
			}
		}
	}

	//	Get CVS or SVN revision tag
	
	// CVS tag
	string	tagname(TagName);
	header = "$Name: ";
	start = header.length();
	string	endstr(" $");
	
	end   = tagname.find(endstr);
	if (end!=string::npos && end>start)
	{
		string	strtag = tagname.substr(start, end-start);
		Tango::DbDatum	cvs_tag("cvs_tag");
		cvs_tag << strtag;
		data.push_back(cvs_tag);
	}
	
	// SVN tag
	string	svnpath(SvnPath);
	header = "$HeadURL: ";
	start = header.length();
	
	end   = svnpath.find(endstr);
	if (end!=string::npos && end>start)
	{
		string	strloc = svnpath.substr(start, end-start);
		
		string tagstr ("/tags/");
		start = strloc.find(tagstr);
		if ( start!=string::npos )
		{
			start = start + tagstr.length();
			end   = strloc.find(filename);
			string	strtag = strloc.substr(start, end-start-1);
			
			Tango::DbDatum	svn_tag("svn_tag");
			svn_tag << strtag;
			data.push_back(svn_tag);
		}
	}

	//	Get URL location
	string	httpServ(HttpServer);
	if (httpServ.length()>0)
	{
		Tango::DbDatum	db_doc_url("doc_url");
		db_doc_url << httpServ;
		data.push_back(db_doc_url);
	}

	//  Put inheritance
	Tango::DbDatum	inher_datum("InheritedFrom");
	vector<string> inheritance;
	inheritance.push_back("Device_4Impl");
	inher_datum << inheritance;
	data.push_back(inher_datum);

	//	Call database and and values
	//--------------------------------------------
	get_db_class()->put_property(data);
}

}	// namespace
