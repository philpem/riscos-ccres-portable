#ifndef routerdiscovery_H
#define routerdiscovery_H

/* C header file for RouterDiscovery
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:47:15 2012
 * John Tytgat, John.Tytgat@aaug.net, 28 Aug 2009
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
#undef  RouterDiscovery_Control
#define RouterDiscovery_Control                 0x57D80
#undef  XRouterDiscovery_Control
#define XRouterDiscovery_Control                0x77D80
#undef  RouterDiscoveryControl_ActivateHostMode
#define RouterDiscoveryControl_ActivateHostMode 0x57D80
#undef  XRouterDiscoveryControl_ActivateHostMode
#define XRouterDiscoveryControl_ActivateHostMode 0x77D80
#undef  RouterDiscoveryControl_ActivateRouterMode
#define RouterDiscoveryControl_ActivateRouterMode 0x57D80
#undef  XRouterDiscoveryControl_ActivateRouterMode
#define XRouterDiscoveryControl_ActivateRouterMode 0x77D80
#undef  RouterDiscoveryControl_Deactivate
#define RouterDiscoveryControl_Deactivate       0x57D80
#undef  XRouterDiscoveryControl_Deactivate
#define XRouterDiscoveryControl_Deactivate      0x77D80
#undef  RouterDiscovery_Status
#define RouterDiscovery_Status                  0x57D81
#undef  XRouterDiscovery_Status
#define XRouterDiscovery_Status                 0x77D81
#undef  Service_InternetService40
#define Service_InternetService40               0x40
#undef  Service_InternetService41
#define Service_InternetService41               0x41
#undef  Service_InternetService42
#define Service_InternetService42               0x42

/************************************
 * Structure and union declarations *
 ************************************/
typedef struct routerdiscovery_router_preference routerdiscovery_router_preference;

/********************
 * Type definitions *
 ********************/
typedef int routerdiscoverycontrol_operation;

struct routerdiscovery_router_preference
   {  int router_address;
      int preference;
   };

typedef int serviceinternetservice40_state;

typedef int serviceinternetservice41_state;

/************************
 * Constant definitions *
 ************************/
#define routerdiscoverycontroloperation_ACTIVATE_HOST_MODE ((routerdiscoverycontrol_operation) 0x0u)
#define routerdiscoverycontroloperation_ACTIVATE_ROUTER_MODE ((routerdiscoverycontrol_operation) 0x1u)
#define routerdiscoverycontroloperation_DEACTIVATE ((routerdiscoverycontrol_operation) 0x2u)
#define serviceinternetservice40state_END_MONITORING ((serviceinternetservice40_state) 0x0u)
#define serviceinternetservice40state_START_SOLICITING ((serviceinternetservice40_state) 0x1u)
#define serviceinternetservice40state_START_MONITORING ((serviceinternetservice40_state) 0x2u)
#define serviceinternetservice41state_END_ADVERTISEMENTS ((serviceinternetservice41_state) 0x0u)
#define serviceinternetservice41state_START_ADVERTISEMENTS ((serviceinternetservice41_state) 0x1u)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      routerdiscoverycontrol_activate_host_mode()
 *
 * Description:   Calls SWI 0x57D80
 *
 * Input:         interface - value of R1 on entry
 *                solicitations_address - value of R2 on entry
 *
 * Other notes:   Before entry, R0 = 0x0.
 */

extern os_error *xrouterdiscoverycontrol_activate_host_mode (char const *interface,
      int solicitations_address);
extern void routerdiscoverycontrol_activate_host_mode (char const *interface,
      int solicitations_address);

/* ------------------------------------------------------------------------
 * Function:      routerdiscoverycontrol_activate_router_mode()
 *
 * Description:   Calls SWI 0x57D80
 *
 * Input:         interface - value of R1 on entry
 *                advertisements_address - value of R2 on entry
 *                min_adv_interval - value of R3 on entry
 *                max_adv_interval - value of R4 on entry
 *                preference - value of R5 on entry
 *
 * Other notes:   Before entry, R0 = 0x1.
 */

extern os_error *xrouterdiscoverycontrol_activate_router_mode (char const *interface,
      int advertisements_address,
      int min_adv_interval,
      int max_adv_interval,
      routerdiscovery_router_preference const *preference);
extern void routerdiscoverycontrol_activate_router_mode (char const *interface,
      int advertisements_address,
      int min_adv_interval,
      int max_adv_interval,
      routerdiscovery_router_preference const *preference);

/* ------------------------------------------------------------------------
 * Function:      routerdiscoverycontrol_deactivate()
 *
 * Description:   Calls SWI 0x57D80
 *
 * Input:         interface - value of R1 on entry
 *
 * Other notes:   Before entry, R0 = 0x2.
 */

extern os_error *xrouterdiscoverycontrol_deactivate (char const *interface);
extern void routerdiscoverycontrol_deactivate (char const *interface);

/* ------------------------------------------------------------------------
 * Function:      service_internet_service40()
 *
 * Description:   RouterDiscovery module starts monitoring an interface for
 *                router advertisement packets
 *
 * Input:         state - value of R2 on entry
 *                interface - value of R3 on entry
 *
 * Other notes:   Calls SWI 0x30 with R0 = 0x40, R1 = 0xB0.
 */

extern os_error *xservice_internet_service40 (serviceinternetservice40_state state,
      char const *interface);
extern void service_internet_service40 (serviceinternetservice40_state state,
      char const *interface);

/* ------------------------------------------------------------------------
 * Function:      service_internet_service41()
 *
 * Description:   RouterDiscovery module starts issuing advertisements on
 *                an interface
 *
 * Input:         state - value of R2 on entry
 *                interface - value of R3 on entry
 *                num_routers - value of R4 on entry
 *                preference - value of R5 on entry
 *
 * Other notes:   Calls SWI 0x30 with R0 = 0x41, R1 = 0xB0.
 */

extern os_error *xservice_internet_service41 (serviceinternetservice41_state state,
      char const *interface,
      int num_routers,
      routerdiscovery_router_preference const *preference);
extern void service_internet_service41 (serviceinternetservice41_state state,
      char const *interface,
      int num_routers,
      routerdiscovery_router_preference const *preference);

/* ------------------------------------------------------------------------
 * Function:      service_internet_service42()
 *
 * Description:   RouterDiscovery module changes the default route
 *
 * Input:         interface - value of R2 on entry
 *                gateway - value of R3 on entry
 *
 * Other notes:   Calls SWI 0x30 with R0 = 0x42, R1 = 0xB0.
 */

extern os_error *xservice_internet_service42 (char const *interface,
      int gateway);
extern void service_internet_service42 (char const *interface,
      int gateway);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
