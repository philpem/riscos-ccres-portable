#ifndef redrawmanager_H
#define redrawmanager_H

/* C header file for RedrawManager
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:48:23 2012
 * John Tytgat, John.Tytgat@aaug.net, 11 Aug 2009
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

#ifndef wimp_H
#include "oslib/wimp.h"
#endif

#if defined NAMESPACE_OSLIB
  namespace OSLib {
#endif

/**********************************
 * SWI names and SWI reason codes *
 **********************************/
#undef  Redraw_AddCallBack
#define Redraw_AddCallBack                      0x82C80
#undef  XRedraw_AddCallBack
#define XRedraw_AddCallBack                     0xA2C80
#undef  RedrawAddCallBack_SWI
#define RedrawAddCallBack_SWI                   0x0
#undef  RedrawAddCallBack_Address
#define RedrawAddCallBack_Address               0x10
#undef  Redraw_RemoveCallBack
#define Redraw_RemoveCallBack                   0x82C81
#undef  XRedraw_RemoveCallBack
#define XRedraw_RemoveCallBack                  0xA2C81
#undef  RedrawRemoveCallBack_SWI
#define RedrawRemoveCallBack_SWI                0x0
#undef  RedrawRemoveCallBack_Address
#define RedrawRemoveCallBack_Address            0x10
#undef  Service_RedrawManagerInstalled
#define Service_RedrawManagerInstalled          0xA5
#undef  Service_RedrawManagerDying
#define Service_RedrawManagerDying              0xA6

/********************
 * Type definitions *
 ********************/
typedef bits redrawaddremovecallback_flags;

/************************
 * Constant definitions *
 ************************/
#define redrawaddremovecallbackflags_SETUP_GRAPH_RECT ((redrawaddremovecallback_flags) 0x2u)
#define redrawaddremovecallbackflags_SCREEN_COORDS ((redrawaddremovecallback_flags) 0x4u)
#define redrawaddremovecallbackflags_AFTER_ICON_PLOT ((redrawaddremovecallback_flags) 0x8u)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      redrawaddcallback_swi()
 *
 * Description:   Add SWI based callback to the RedrawManager
 *
 * Input:         flags - value of R0 on entry
 *                window_handle - value of R1 on entry
 *                swi - value of R2 on entry
 *                region - value of R3 on entry
 *                region_data - value of R4 on entry
 *
 * Other notes:   Calls SWI 0x82C80 with R0 |= 0x0.
 */

extern os_error *xredrawaddcallback_swi (redrawaddremovecallback_flags flags,
      wimp_w window_handle,
      int swi,
      os_box const *region,
      int region_data);
extern void redrawaddcallback_swi (redrawaddremovecallback_flags flags,
      wimp_w window_handle,
      int swi,
      os_box const *region,
      int region_data);

/* ------------------------------------------------------------------------
 * Function:      redrawaddcallback_address()
 *
 * Description:   Add address based callback to the RedrawManager
 *
 * Input:         flags - value of R0 on entry
 *                window_handle - value of R1 on entry
 *                callback - value of R2 on entry
 *                region - value of R3 on entry
 *                region_data - value of R4 on entry
 *                private_word - value of R5 on entry
 *
 * Other notes:   Calls SWI 0x82C80 with R0 |= 0x10.
 */

extern os_error *xredrawaddcallback_address (redrawaddremovecallback_flags flags,
      wimp_w window_handle,
      asm_routine callback,
      os_box const *region,
      int region_data,
      int private_word);
extern void redrawaddcallback_address (redrawaddremovecallback_flags flags,
      wimp_w window_handle,
      asm_routine callback,
      os_box const *region,
      int region_data,
      int private_word);

/* ------------------------------------------------------------------------
 * Function:      redrawremovecallback_swi()
 *
 * Description:   Remove SWI based callback to the RedrawManager
 *
 * Input:         flags - value of R0 on entry
 *                window_handle - value of R1 on entry
 *                swi - value of R2 on entry
 *                region - value of R3 on entry
 *                region_data - value of R4 on entry
 *
 * Other notes:   Calls SWI 0x82C81 with R0 |= 0x0.
 */

extern os_error *xredrawremovecallback_swi (redrawaddremovecallback_flags flags,
      wimp_w window_handle,
      int swi,
      os_box const *region,
      int region_data);
extern void redrawremovecallback_swi (redrawaddremovecallback_flags flags,
      wimp_w window_handle,
      int swi,
      os_box const *region,
      int region_data);

/* ------------------------------------------------------------------------
 * Function:      redrawremovecallback_address()
 *
 * Description:   Remove address based callback to the RedrawManager
 *
 * Input:         flags - value of R0 on entry
 *                window_handle - value of R1 on entry
 *                callback - value of R2 on entry
 *                region - value of R3 on entry
 *                region_data - value of R4 on entry
 *                private_word - value of R5 on entry
 *
 * Other notes:   Calls SWI 0x82C81 with R0 |= 0x10.
 */

extern os_error *xredrawremovecallback_address (redrawaddremovecallback_flags flags,
      wimp_w window_handle,
      asm_routine callback,
      os_box const *region,
      int region_data,
      int private_word);
extern void redrawremovecallback_address (redrawaddremovecallback_flags flags,
      wimp_w window_handle,
      asm_routine callback,
      os_box const *region,
      int region_data,
      int private_word);

/* ------------------------------------------------------------------------
 * Function:      service_redraw_manager_installed()
 *
 * Description:   Redraw Manager starts up
 *
 * Input:         version - value of R0 on entry
 *
 * Other notes:   Calls SWI 0x30 with R1 = 0xA5.
 */

extern os_error *xservice_redraw_manager_installed (int version);
extern void service_redraw_manager_installed (int version);

/* ------------------------------------------------------------------------
 * Function:      service_redraw_manager_dying()
 *
 * Description:   Redraw Manager is about to die
 *
 * Other notes:   Calls SWI 0x30 with R1 = 0xA6.
 */

extern os_error *xservice_redraw_manager_dying (void);
extern void service_redraw_manager_dying (void);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
