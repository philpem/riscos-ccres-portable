#ifndef dhcpclient_H
#define dhcpclient_H

/* C header file for DHCPClient
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:47:15 2012
 * John Tytgat, John.Tytgat@aaug.net, 27 Aug 2009
 */

/* OSLib---efficient, type-safe, transparent, extensible,
 * register-safe API coverage of RISC OS
 * 
 * Copyright (c) 1994-2012 Jonathan Coxhead and OSLib maintainers
 * 
 * Licence:
 * 
 *    OSLib is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 1, or (at your option)
 * any later version - and this with the following clarification and
 * special exception:
 * 
 *    Linking this library statically or dynamically with other modules
 * is making a combined work based on this library. Thus, the terms
 * and conditions of the GNU General Public License cover the whole
 * combination.
 * 
 *    As a special exception, the copyright holders of this library
 * give you permission to link this library with independent modules
 * to produce an executable, regardless of the license terms of these
 * independent modules, and to copy and distribute the resulting
 * executable under terms of your choice, provided that you also meet,
 * for each linked independent module, the terms and conditions of the
 * license of that module. An independent module is a module which is
 * not derived from or based on this library. If you modify this
 * library, you may extend this exception to your version of the library,
 * but you are not obliged to do so. If you do not wish to do so, delete
 * this exception statement from your version.
 * 
 *    OSLib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 *    You should have received a copy of the GNU General Public License
 * along with this programme; if not, write to the Free Software
 * Foundation, Inc, 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef types_H
#include "oslib/types.h"
#endif

#ifndef os_H
#include "oslib/os.h"
#endif

#if defined NAMESPACE_OSLIB
  namespace OSLib {
#endif

/**********************************
 * SWI names and SWI reason codes *
 **********************************/
#undef  DHCPClient_Control
#define DHCPClient_Control                      0x55E00
#undef  XDHCPClient_Control
#define XDHCPClient_Control                     0x75E00
#undef  DHCPClient_State
#define DHCPClient_State                        0x55E01
#undef  XDHCPClient_State
#define XDHCPClient_State                       0x75E01
#undef  DHCPClient_Enumerate
#define DHCPClient_Enumerate                    0x55E02
#undef  XDHCPClient_Enumerate
#define XDHCPClient_Enumerate                   0x75E02
#undef  Service_InternetStatus4
#define Service_InternetStatus4                 0x4
#undef  Service_InternetStatus5
#define Service_InternetStatus5                 0x5
#undef  Service_InternetStatus30
#define Service_InternetStatus30                0x30
#undef  Service_InternetService31
#define Service_InternetService31               0x31

/********************
 * Type definitions *
 ********************/
typedef int dhcpclientcontrol_reason;

typedef int dhcpclientstate_types;

typedef int dhcpclientstate_state;

/************************
 * Constant definitions *
 ************************/
#define dhcpclientcontrolreason_ADD             ((dhcpclientcontrol_reason) 0x0u)
#define dhcpclientcontrolreason_REMOVE          ((dhcpclientcontrol_reason) 0x1u)
#define dhcpclientcontrolreason_RENEW           ((dhcpclientcontrol_reason) 0x2u)
#define dhcpclientstatetype_END_OF_LIST         ((dhcpclientstate_types) 0xFFFFFFFFu)
#define dhcpclientstatetype_STATE               ((dhcpclientstate_types) 0x0u)
#define dhcpclientstatetype_BOUND_ADDRESS       ((dhcpclientstate_types) 0x1u)
#define dhcpclientstatetype_SERVER_ADDRESS      ((dhcpclientstate_types) 0x2u)
#define dhcpclientstatetype_GATEWAY_ADDRESS     ((dhcpclientstate_types) 0x3u)
#define dhcpclientstatetype_LEASE_PERIOD        ((dhcpclientstate_types) 0x4u)
#define dhcpclientstatetype_T1_PERIOD           ((dhcpclientstate_types) 0x5u)
#define dhcpclientstatetype_T2_PERIOD           ((dhcpclientstate_types) 0x6u)
#define dhcpclientstatetype_DHCP_START          ((dhcpclientstate_types) 0x7u)
#define dhcpclientstatetype_LEASE_START         ((dhcpclientstate_types) 0x8u)
#define dhcpclientstatetype_LEASE_END           ((dhcpclientstate_types) 0x9u)
#define dhcpclientstatetype_T1_END              ((dhcpclientstate_types) 0xAu)
#define dhcpclientstatetype_T2_END              ((dhcpclientstate_types) 0xBu)
#define dhcpclientstatestate_SLEEPING           ((dhcpclientstate_state) 0x0u)
#define dhcpclientstatestate_INIT_REBOOT        ((dhcpclientstate_state) 0x0u)
#define dhcpclientstatestate_INIT               ((dhcpclientstate_state) 0x0u)
#define dhcpclientstatestate_REBOOTING          ((dhcpclientstate_state) 0x0u)
#define dhcpclientstatestate_SELECTING          ((dhcpclientstate_state) 0x0u)
#define dhcpclientstatestate_REQUESTING         ((dhcpclientstate_state) 0x0u)
#define dhcpclientstatestate_BOUND              ((dhcpclientstate_state) 0x0u)
#define dhcpclientstatestate_RENEWING           ((dhcpclientstate_state) 0x0u)
#define dhcpclientstatestate_REBINDING          ((dhcpclientstate_state) 0x8u)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      dhcpclient_control()
 *
 * Description:   Add or remove an interface from the DHCPClient's control
 *
 * Input:         reason - value of R0 on entry
 *                interface_name - value of R1 on entry
 *
 * Other notes:   Calls SWI 0x55E00.
 */

extern os_error *xdhcpclient_control (dhcpclientcontrol_reason reason,
      char const *interface_name);
__swi (0x55E00) void dhcpclient_control (dhcpclientcontrol_reason reason,
      char const *interface_name);

/* ------------------------------------------------------------------------
 * Function:      dhcpclient_state()
 *
 * Description:   Read the current DHCP client state for an interface
 *
 * Input:         interface_name - value of R0 on entry
 *                type_list - value of R1 on entry
 *                buf - value of R2 on entry
 *                buf_size - value of R3 on entry
 *
 * Output:        last_type - value of R1 on exit
 *                buf_end - value of R2 on exit
 *                space_left - value of R3 on exit
 *
 * Other notes:   Calls SWI 0x55E01.
 */

extern os_error *xdhcpclient_state (char const *interface_name,
      dhcpclientstate_types const *type_list,
      byte const *buf,
      int buf_size,
      dhcpclientstate_types **last_type,
      byte **buf_end,
      int *space_left);
extern void dhcpclient_state (char const *interface_name,
      dhcpclientstate_types const *type_list,
      byte const *buf,
      int buf_size,
      dhcpclientstate_types **last_type,
      byte **buf_end,
      int *space_left);

/* ------------------------------------------------------------------------
 * Function:      dhcpclient_enumerate()
 *
 * Description:   Enumerates the interfaces under DHCPClient control
 *
 * Input:         interface_name - value of R0 on entry
 *                buf - value of R1 on entry
 *                buf_size - value of R2 on entry
 *
 * Output:        num_state_transitions - value of R0 on exit
 *                buf_end - value of R1 on exit
 *                space_left - value of R2 on exit
 *
 * Other notes:   Calls SWI 0x55E02.
 */

extern os_error *xdhcpclient_enumerate (char const *interface_name,
      char *buf,
      int buf_size,
      int *num_state_transitions,
      char **buf_end,
      int *space_left);
extern void dhcpclient_enumerate (char const *interface_name,
      char *buf,
      int buf_size,
      int *num_state_transitions,
      char **buf_end,
      int *space_left);

/* ------------------------------------------------------------------------
 * Function:      service_internet_status4()
 *
 * Description:   BOOTP/DHCP reply is received
 *
 * Input:         interface_name - value of R2 on entry
 *                dib - value of R3 on entry
 *                dhcp_reply - value of R4 on entry
 *                dhcp_reply_size - value of R5 on entry
 *
 * Output:        unclaimed - value of R1 on exit (X version only)
 *
 * Returns:       R1 (non-X version only)
 *
 * Other notes:   Calls SWI 0x30 with R0 = 0x4, R1 = 0xB0.
 */

extern os_error *xservice_internet_status4 (char const *interface_name,
      byte const *dib,
      byte const *dhcp_reply,
      int dhcp_reply_size,
      osbool *unclaimed);
extern osbool service_internet_status4 (char const *interface_name,
      byte const *dib,
      byte const *dhcp_reply,
      int dhcp_reply_size);

/* ------------------------------------------------------------------------
 * Function:      service_internet_status5()
 *
 * Description:   DHCPClient module receives an offer of an IP address
 *                lease which is better than its current best choice (or if
 *                it is the first acceptable offer)
 *
 * Input:         interface_name - value of R2 on entry
 *                dib - value of R3 on entry
 *                dhcpoffer_buf - value of R4 on entry
 *                dhcpoffer_buf_size - value of R5 on entry
 *
 * Output:        unclaimed - value of R1 on exit (X version only)
 *
 * Returns:       R1 (non-X version only)
 *
 * Other notes:   Calls SWI 0x30 with R0 = 0x5, R1 = 0xB0.
 */

extern os_error *xservice_internet_status5 (char const *interface_name,
      byte const *dib,
      byte const *dhcpoffer_buf,
      int dhcpoffer_buf_size,
      osbool *unclaimed);
extern osbool service_internet_status5 (char const *interface_name,
      byte const *dib,
      byte const *dhcpoffer_buf,
      int dhcpoffer_buf_size);

/* ------------------------------------------------------------------------
 * Function:      service_internet_status30()
 *
 * Description:   DHCPClient module has successfully configured an
 *                interface with an address leased from a DHCP server
 *
 * Input:         interface_name - value of R2 on entry
 *                ip_address - value of R3 on entry
 *
 * Other notes:   Calls SWI 0x30 with R0 = 0x30, R1 = 0xB0.
 */

extern os_error *xservice_internet_status30 (char const *interface_name,
      int ip_address);
extern void service_internet_status30 (char const *interface_name,
      int ip_address);

/* ------------------------------------------------------------------------
 * Function:      service_internet_service31()
 *
 * Description:   DHCPClient module has lost the DHCP server leased address
 *                allocated to an interface
 *
 * Input:         interface_name - value of R2 on entry
 *                ip_address - value of R3 on entry
 *
 * Other notes:   Calls SWI 0x30 with R0 = 0x31, R1 = 0xB0.
 */

extern os_error *xservice_internet_service31 (char const *interface_name,
      int ip_address);
extern void service_internet_service31 (char const *interface_name,
      int ip_address);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
