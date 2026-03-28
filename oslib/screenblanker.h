#ifndef screenblanker_H
#define screenblanker_H

/* C header file for ScreenBlanker
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:47:41 2012
 * Jonathan Coxhead, jonathan@doves.demon.co.uk, 12 May 1995
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
#undef  ScreenBlanker_Control
#define ScreenBlanker_Control                   0x43100
#undef  XScreenBlanker_Control
#define XScreenBlanker_Control                  0x63100
#undef  Service_ScreenBlanked
#define Service_ScreenBlanked                   0x7A
#undef  Service_ScreenRestored
#define Service_ScreenRestored                  0x7B

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      service_screen_blanked()
 *
 * Description:   Screen blanked by screen blanker
 *
 * Other notes:   Calls SWI 0x30 with R1 = 0x7A.
 */

extern os_error *xservice_screen_blanked (void);
extern void service_screen_blanked (void);

/* ------------------------------------------------------------------------
 * Function:      service_screen_restored()
 *
 * Description:   Screen restored by screen blanker
 *
 * Input:         x - value of R0 on entry
 *
 * Other notes:   Calls SWI 0x30 with R1 = 0x7B.
 */

extern os_error *xservice_screen_restored (int x);
extern void service_screen_restored (int x);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
