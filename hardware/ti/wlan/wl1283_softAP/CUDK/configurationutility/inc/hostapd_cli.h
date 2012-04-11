/*
 * hostapd_cli.h
 *
 * Copyright 2001-2010 Texas Instruments, Inc. - http://www.ti.com/
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and  
 * limitations under the License.
 */
/*
 * hostapd / Hostapd daemon command line interface definition
 * Copyright (c) 2010, Texas Instruments, Inc. - http://www.ti.com/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Alternatively, this software may be distributed under the terms of BSD
 * license below:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *  notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name(s) of the above-listed copyright holder(s) nor the
 *  names of its contributors may be used to endorse or promote products
 *  derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef HOSTAPD_CLI_H
#define HOSTAPD_CLI_H


#define MAX_ADDRESS_SIZE    20
#define MAX_UUID_SIZE       56
#define MAX_PIN_SIZE        56
#define MAX_CMD_NAME_SIZE   20
#define MAX_CMD_DESCRIPTION_SIZE 150
#define MAX_FILENAME_SIZE	80
#define MAX_SSID_LEN        (32)
#define MAX_SSID_TYPE_LEN	(1)
#define MAX_SUPPORTED_SSIDS (32)
#define SSID_TYPE_DELIMITER_LEN (2)
#define MAX_CHANNEL_LEN (3)
#define NUM_OF_G_CHANNELS (14)
#define MAX_SSID_LIST_SIZE  ((MAX_SSID_LEN+MAX_SSID_TYPE_LEN+SSID_TYPE_DELIMITER_LEN) * MAX_SUPPORTED_SSIDS)
#define MAX_CHANNEL_LIST_SIZE (NUM_OF_G_CHANNELS*MAX_CHANNEL_LEN )
#define MAX_PARAMS_IN_CMD   10


typedef struct
{
    char cmdName[MAX_CMD_NAME_SIZE];
    char cmdDescription[MAX_CMD_DESCRIPTION_SIZE];
} TCmdInfo;


typedef enum
{
    HOSTAPD_CLI_CMD_PING = 0,
    HOSTAPD_CLI_CMD_MIB,
    HOSTAPD_CLI_CMD_STA,
    HOSTAPD_CLI_CMD_ALL_STA,
    HOSTAPD_CLI_CMD_NEW_STA,
    HOSTAPD_CLI_CMD_SA_QUERY,
    HOSTAPD_CLI_CMD_WPS_PIN,
    HOSTAPD_CLI_CMD_WPS_PBC,
	HOSTAPD_CLI_CMD_RESET,
	HOSTAPD_CLI_CMD_STOP,
	HOSTAPD_CLI_CMD_START,
	HOSTAPD_CLI_CMD_SET_SSID_LIST,
	HOSTAPD_CLI_CMD_SET_CHANNEL_LIST,
	HOSTAPD_CLI_CMD_COMMIT_CONFIGURATION,
	HOSTAPD_CLI_CMD_START_SCAN,
	HOSTAPD_CLI_CMD_STOP_SCAN,
	HOSTAPD_CLI_CMD_SET_SCAN_INTERVAL,
	HOSTAPD_CLI_CMD_DISABLE_SCAN,
	HOSTAPD_CLI_CMD_ENABLE_SCAN,
	HOSTAPD_CLI_CMD_GET_AP_RESULTS,
	HOSTAPD_CLI_CMD_SET_DWELL_TIME,
#ifndef CONFIG_NO_TI          
	HOSTAPD_CLI_CMD_RELOAD_ACL,
#endif
    HOSTAPD_CLI_CMD_LAST
} EHostapdCLICmds;


static TCmdInfo tCmdsNames[HOSTAPD_CLI_CMD_LAST] =
{
    {"ping",    "Get MIB variables (dot1x, dot11, radius)\n"},              /* HOSTAPD_CLI_CMD_PING */
    {"mib",     "Get MIB variables for one station\n"},                     /* HOSTAPD_CLI_CMD_MIB */
    {"sta",     "Get MIB variables for one station (Param: <addr>)\n"},     /* HOSTAPD_CLI_CMD_STA */
    {"all_sta", "Get MIB variables for all stations\n"},                    /* HOSTAPD_CLI_CMD_ALL_STA */
    {"new_sta", "Add a new station (Param0: <addr>)\n"},                    /* HOSTAPD_CLI_CMD_NEW_STA */
    {"sa_query","Send SA Query to a station (Param: <addr>)\n"},            /* HOSTAPD_CLI_CMD_SA_QUERY */
    {"wps_pin", "Add WPS Enrollee PIN (Param: <pin> <uuid>)\n"},            /* HOSTAPD_CLI_CMD_WPS_PIN */
    {"wps_pbc", "indicate button pushed to initiate PBC \n"},               /* HOSTAPD_CLI_CMD_WPS_PBC */
    {"reset",   "Reload config file and reset the AP\n"},	                /* HOSTAPD_CLI_CMD_RESET */
    {"stop",    "Stop the AP\n"},							                /* HOSTAPD_CLI_CMD_STOP */
    {"start",   "Start the AP <config filename>\n"},		                /* HOSTAPD_CLI_CMD_START */
	{"SET_SSIDS",   		"Set ssid list <ssid list: ap1 p ap2 h>\n"},		    	/* HOSTAPD_CLI_CMD_SET_SSID_LIST */
	{"SET_CHANNELS",   		"Set channel list <channel list: c1 c2>\n"},		   		/* HOSTAPD_CLI_CMD_SET_CHANNEL_LIST */
	{"COMMIT_CONFIG",		"Commit the discovery params configuration\n"},	    		/* HOSTAPD_CLI_CMD_COMMIT_CONFIGURATION */
	{"START_SCAN",    		"Start enterprise discovery\n"},	    					/* HOSTAPD_CLI_CMD_START_SCAN */
	{"STOP_SCAN",     		"Stop enterprise discovery\n"},	    						/* HOSTAPD_CLI_CMD_STOP_SCAN */
	{"SET_INTERVAL",  		"Set interval value between cycles in mSec\n"},				/* HOSTAPD_CLI_CMD_SET_INTERVAL_SCAN      */
	{"DISABLE_DISCOVERY",   "Disable enterprise discovery\n"},	    					/* HOSTAPD_CLI_CMD_DISABLE_SCAN */
	{"ENABLE_DISCOVERY",   	"Enable enterprise discovery\n"},	    					/* HOSTAPD_CLI_CMD_ENABLE_SCAN       */
	{"GET_AP_TABLE",   	  	"Get enterprise discovery ap results\n"},	    			/* HOSTAPD_CLI_CMD_ENABLE_SCAN       */
	{"SET_DWELL_TIME",   	"Set dwell time <0...1000\n"},	    						/* HOSTAPD_CLI_CMD_SET_DWELL_TIME       */
#ifndef CONFIG_NO_TI
	{"reload_acl", "reload acl configuration \n"}                           /* HOSTAPD_CLI_CMD_RELOAD_ACL */
#endif
};

typedef struct
{
    char config_fname[MAX_FILENAME_SIZE];
}TCmdStart;

typedef struct
{
	unsigned int interval;
}TCmdSetInterval;

typedef struct
{
	unsigned int dwell_time;
}TCmdSetDwellTime;

typedef struct
{
    char channel_list[MAX_CHANNEL_LIST_SIZE];
}TCmdSetChannels;

typedef struct
{
    char ssid_list[MAX_SSID_LIST_SIZE];
}TCmdSetSsid;

typedef struct
{
    char address[MAX_ADDRESS_SIZE];
}TCmdSta;


typedef struct
{
  char uuid[MAX_UUID_SIZE];
  unsigned short uuidLen;
  char pin[MAX_PIN_SIZE];
  unsigned short pinLen;

}TCmdWPSPin;

typedef struct
{
    EHostapdCLICmds eCmdType;

    union
    {
		TCmdStart   tCmdStart;
        TCmdSta     tCmdSta;
        TCmdWPSPin  tCmdWPSPin;
		TCmdSetSsid 	tCmdSetSsid;
		TCmdSetChannels tCmdSetChannels;
		TCmdSetInterval tCmdSetInterval;
		TCmdSetDwellTime	tCmdSetDwellTime; 
    } u;
} THostapdCLICmd;


void HostapdCLI_PrintCommands();
int HostapdCLI_RunCommand(const char *ctrl_interface, THostapdCLICmd *pCmd);

#endif /* HOSTAPD_CLI_H */
