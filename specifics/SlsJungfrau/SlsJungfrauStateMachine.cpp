/*----- PROTECTED REGION ID(SlsJungfrauStateMachine.cpp) ENABLED START -----*/
static const char *RcsId = "$Id:  $";
//=============================================================================
//
// file :        SlsJungfrauStateMachine.cpp
//
// description : State machine file for the SlsJungfrau class
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

#include <SlsJungfrau.h>

/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::SlsJungfrauStateMachine.cpp

//================================================================
//  States   |  Description
//================================================================
//  INIT     |  
//  STANDBY  |  
//  FAULT    |  
//  RUNNING  |  


namespace SlsJungfrau_ns
{
//=================================================
//		Attributes Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_tresholdEnergy_allowed()
 *	Description : Execution allowed for tresholdEnergy attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_tresholdEnergy_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Check access type.
	if ( type!=Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for WRITE 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT ||
			get_state()==Tango::RUNNING)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::tresholdEnergyStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::tresholdEnergyStateAllowed_WRITE
			return false;
		}
		return true;
	}
	else

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::tresholdEnergyStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::tresholdEnergyStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_clockDivider_allowed()
 *	Description : Execution allowed for clockDivider attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_clockDivider_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Check access type.
	if ( type!=Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for WRITE 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT ||
			get_state()==Tango::RUNNING)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::clockDividerStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::clockDividerStateAllowed_WRITE
			return false;
		}
		return true;
	}
	else

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::clockDividerStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::clockDividerStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_configFileName_allowed()
 *	Description : Execution allowed for configFileName attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_configFileName_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::configFileNameStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::configFileNameStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_delayAfterTrigger_allowed()
 *	Description : Execution allowed for delayAfterTrigger attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_delayAfterTrigger_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for delayAfterTrigger attribute in Write access.
	/*----- PROTECTED REGION ID(SlsJungfrau::delayAfterTriggerStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::delayAfterTriggerStateAllowed_WRITE

	//	Not any excluded states for delayAfterTrigger attribute in read access.
	/*----- PROTECTED REGION ID(SlsJungfrau::delayAfterTriggerStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::delayAfterTriggerStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_detectorFirmwareVersion_allowed()
 *	Description : Execution allowed for detectorFirmwareVersion attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_detectorFirmwareVersion_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::detectorFirmwareVersionStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::detectorFirmwareVersionStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_detectorSoftwareVersion_allowed()
 *	Description : Execution allowed for detectorSoftwareVersion attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_detectorSoftwareVersion_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT)
		{
		/*----- PROTECTED REGION ID(SlsJungfrau::detectorSoftwareVersionStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::detectorSoftwareVersionStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//=================================================
//		Commands Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_SetCmd_allowed()
 *	Description : Execution allowed for SetCmd attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_SetCmd_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::INIT ||
		get_state()==Tango::RUNNING)
	{
	/*----- PROTECTED REGION ID(SlsJungfrau::SetCmdStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::SetCmdStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsJungfrau::is_GetCmd_allowed()
 *	Description : Execution allowed for GetCmd attribute
 */
//--------------------------------------------------------
bool SlsJungfrau::is_GetCmd_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::INIT ||
		get_state()==Tango::RUNNING)
	{
	/*----- PROTECTED REGION ID(SlsJungfrau::GetCmdStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsJungfrau::GetCmdStateAllowed
		return false;
	}
	return true;
}

}	//	End of namespace
