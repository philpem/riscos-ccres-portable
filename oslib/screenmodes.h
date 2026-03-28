#ifndef screenmodes_H
#define screenmodes_H

/* C header file for ScreenModes
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:47:41 2012
 * Jonathan Coxhead, jonathan@doves.demon.co.uk, 29 Jun 1995
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
#undef  ScreenModes_ReadInfo
#define ScreenModes_ReadInfo                    0x487C0
#undef  XScreenModes_ReadInfo
#define XScreenModes_ReadInfo                   0x687C0
#undef  ScreenModesReadInfo_MonitorTitle
#define ScreenModesReadInfo_MonitorTitle        0x0
#undef  ScreenModesReadInfo_DPMSState
#define ScreenModesReadInfo_DPMSState           0x1

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      screenmodesreadinfo_monitor_title()
 *
 * Description:   Reads the current monitor title - RISC OS 3.5+
 *
 * Output:        title - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x487C0 with R0 = 0x0.
 */

extern os_error *xscreenmodesreadinfo_monitor_title (char **title);
extern char *screenmodesreadinfo_monitor_title (void);

/* ------------------------------------------------------------------------
 * Function:      screenmodesreadinfo_dpms_state()
 *
 * Description:   Read the DPMS state as configured by the currently
 *                selected MDF - RISC OS 6
 *
 * Output:        dpms_state - value of R0 on exit
 *
 * Other notes:   Calls SWI 0x487C0 with R0 = 0x1.
 */

extern os_error *xscreenmodesreadinfo_dpms_state (int *dpms_state);
extern void screenmodesreadinfo_dpms_state (int *dpms_state);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
