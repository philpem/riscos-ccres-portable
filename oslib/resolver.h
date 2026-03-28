#ifndef resolver_H
#define resolver_H

/* C header file for Resolver
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:47:15 2012
 * Tom Hughes, tom@compton.nu, 21 Sep 2002
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

#ifndef socket_H
#include "oslib/socket.h"
#endif

#if defined NAMESPACE_OSLIB
  namespace OSLib {
#endif

/**********************************
 * SWI names and SWI reason codes *
 **********************************/
#undef  Resolver_GetHostByName
#define Resolver_GetHostByName                  0x46000
#undef  XResolver_GetHostByName
#define XResolver_GetHostByName                 0x66000
#undef  Resolver_GetHost
#define Resolver_GetHost                        0x46001
#undef  XResolver_GetHost
#define XResolver_GetHost                       0x66001
#undef  Resolver_GetCache
#define Resolver_GetCache                       0x46002
#undef  XResolver_GetCache
#define XResolver_GetCache                      0x66002
#undef  Resolver_CacheControl
#define Resolver_CacheControl                   0x46003
#undef  XResolver_CacheControl
#define XResolver_CacheControl                  0x66003
#undef  EventInternet_DNSResolveComplete
#define EventInternet_DNSResolveComplete        0x102

/************************************
 * Structure and union declarations *
 ************************************/
typedef struct resolver_host_details            resolver_host_details;

/********************
 * Type definitions *
 ********************/
struct resolver_host_details
   {  char *name;
      char **aliases;
      socket_af address_type;
      int address_size;
      byte **addresses;
   };

typedef int resolvercachecontrol_reason;

/************************
 * Constant definitions *
 ************************/
#define resolvercachecontrolreason_FLUSH_FAILED ((resolvercachecontrol_reason) 0x0u)
#define resolvercachecontrolreason_FLUSH_ALL    ((resolvercachecontrol_reason) 0x1u)
#define resolvercachecontrolreason_FLUSH_HOST   ((resolvercachecontrol_reason) 0x2u)
#define resolvercachecontrolreason_REREAD_CONFIG ((resolvercachecontrol_reason) 0x3u)
#define resolvercachecontrolreason_NO_CACHE_FAILED ((resolvercachecontrol_reason) 0x8u)
#define resolvercachecontrolreason_DO_CACHE_FAILED ((resolvercachecontrol_reason) 0x9u)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      resolver_get_host_by_name()
 *
 * Description:   Lookup a hostname string (single-tasking)
 *
 * Input:         host_name - value of R1 on entry
 *
 * Output:        errno - value of R0 on exit
 *                host_details - value of R1 on exit (X version only)
 *
 * Returns:       R1 (non-X version only)
 *
 * Other notes:   Calls SWI 0x46000.
 */

extern os_error *xresolver_get_host_by_name (char const *host_name,
      int *errno,
      resolver_host_details **host_details);
extern resolver_host_details *resolver_get_host_by_name (char const *host_name,
      int *errno);

/* ------------------------------------------------------------------------
 * Function:      resolver_get_host()
 *
 * Description:   Lookup a hostname string (multi-tasking)
 *
 * Input:         host_name - value of R1 on entry
 *
 * Output:        errno - value of R0 on exit
 *                host_details - value of R1 on exit (X version only)
 *
 * Returns:       R1 (non-X version only)
 *
 * Other notes:   Calls SWI 0x46001.
 */

extern os_error *xresolver_get_host (char const *host_name,
      int *errno,
      resolver_host_details **host_details);
extern resolver_host_details *resolver_get_host (char const *host_name,
      int *errno);

/* ------------------------------------------------------------------------
 * Function:      resolver_cache_control()
 *
 * Description:   Allow a calling application to control the Resolver cache
 *                in a limited way
 *
 * Input:         reason - value of R0 on entry
 *
 * Other notes:   Calls SWI 0x46003.
 */

extern os_error *xresolver_cache_control (resolvercachecontrol_reason reason);
__swi (0x46003) void resolver_cache_control (resolvercachecontrol_reason reason);

/* ------------------------------------------------------------------------
 * Function:      eventinternet_dns_resolve_complete()
 *
 * Description:   A Resolver resolution request completes, either
 *                successfully or by timing out
 *
 * Input:         host_name - value of R2 on entry
 *                ip_address - value of R3 on entry
 *                errno - value of R4 on entry
 *                host_details - value of R5 on entry
 *
 * Other notes:   Calls SWI 0x22 with R0 = 0x13, R1 = 0x102.
 */

extern os_error *xeventinternet_dns_resolve_complete (char const *host_name,
      int ip_address,
      int errno,
      resolver_host_details const *host_details);
extern void eventinternet_dns_resolve_complete (char const *host_name,
      int ip_address,
      int errno,
      resolver_host_details const *host_details);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
