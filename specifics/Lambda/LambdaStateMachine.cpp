/*----- PROTECTED REGION ID(LambdaStateMachine.cpp) ENABLED START -----*/
//=============================================================================
//
// file :        LambdaStateMachine.cpp
//
// description : State machine file for the Lambda class
//
// project :     XSpectrum Lambda detector TANGO specific device.
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
//
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================

#include <Lambda.h>

/*----- PROTECTED REGION END -----*/	//	Lambda::LambdaStateMachine.cpp

//================================================================
//  States   |  Description
//================================================================
//  STANDBY  |  
//  FAULT    |  
//  RUNNING  |  


namespace Lambda_ns
{
//=================================================
//		Attributes Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : Lambda::is_configFile_allowed()
 *	Description : Execution allowed for configFile attribute
 */
//--------------------------------------------------------
bool Lambda::is_configFile_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::FAULT)
		{
		/*----- PROTECTED REGION ID(Lambda::configFileStateAllowed_READ) ENABLED START -----*/
		
		/*----- PROTECTED REGION END -----*/	//	Lambda::configFileStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Lambda::is_distortionCorrection_allowed()
 *	Description : Execution allowed for distortionCorrection attribute
 */
//--------------------------------------------------------
bool Lambda::is_distortionCorrection_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::FAULT ||
			get_state()==Tango::RUNNING)
		{
		/*----- PROTECTED REGION ID(Lambda::distortionCorrectionStateAllowed_READ) ENABLED START -----*/
		
		/*----- PROTECTED REGION END -----*/	//	Lambda::distortionCorrectionStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Lambda::is_energyThreshold_allowed()
 *	Description : Execution allowed for energyThreshold attribute
 */
//--------------------------------------------------------
bool Lambda::is_energyThreshold_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Check access type.
	if ( type!=Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for WRITE 
		if (get_state()==Tango::FAULT ||
			get_state()==Tango::RUNNING)
		{
		/*----- PROTECTED REGION ID(Lambda::energyThresholdStateAllowed_WRITE) ENABLED START -----*/
		
		/*----- PROTECTED REGION END -----*/	//	Lambda::energyThresholdStateAllowed_WRITE
			return false;
		}
		return true;
	}
	else

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::FAULT ||
			get_state()==Tango::RUNNING)
		{
		/*----- PROTECTED REGION ID(Lambda::energyThresholdStateAllowed_READ) ENABLED START -----*/
		
		/*----- PROTECTED REGION END -----*/	//	Lambda::energyThresholdStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Lambda::is_libraryVersion_allowed()
 *	Description : Execution allowed for libraryVersion attribute
 */
//--------------------------------------------------------
bool Lambda::is_libraryVersion_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::FAULT ||
			get_state()==Tango::RUNNING)
		{
		/*----- PROTECTED REGION ID(Lambda::libraryVersionStateAllowed_READ) ENABLED START -----*/
		
		/*----- PROTECTED REGION END -----*/	//	Lambda::libraryVersionStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Lambda::is_highVoltage_allowed()
 *	Description : Execution allowed for highVoltage attribute
 */
//--------------------------------------------------------
bool Lambda::is_highVoltage_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::FAULT ||
			get_state()==Tango::RUNNING)
		{
		/*----- PROTECTED REGION ID(Lambda::highVoltageStateAllowed_READ) ENABLED START -----*/
		
		/*----- PROTECTED REGION END -----*/	//	Lambda::highVoltageStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Lambda::is_humidity_allowed()
 *	Description : Execution allowed for humidity attribute
 */
//--------------------------------------------------------
bool Lambda::is_humidity_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::FAULT ||
			get_state()==Tango::RUNNING)
		{
		/*----- PROTECTED REGION ID(Lambda::humidityStateAllowed_READ) ENABLED START -----*/
		
		/*----- PROTECTED REGION END -----*/	//	Lambda::humidityStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Lambda::is_temperature_allowed()
 *	Description : Execution allowed for temperature attribute
 */
//--------------------------------------------------------
bool Lambda::is_temperature_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::FAULT ||
			get_state()==Tango::RUNNING)
		{
		/*----- PROTECTED REGION ID(Lambda::temperatureStateAllowed_READ) ENABLED START -----*/
		
		/*----- PROTECTED REGION END -----*/	//	Lambda::temperatureStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}


//=================================================
//		Commands Allowed Methods
//=================================================


/*----- PROTECTED REGION ID(Lambda::LambdaStateAllowed.AdditionalMethods) ENABLED START -----*/

//	Additional Methods

/*----- PROTECTED REGION END -----*/	//	Lambda::LambdaStateAllowed.AdditionalMethods

}	//	End of namespace
