#ifndef keyinput_H
#define keyinput_H

/* C header file for KeyInput
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:47:41 2012
 * John Tytgat, John.Tytgat@aaug.net, 23 Aug 2009
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
#undef  KeyInput_Check
#define KeyInput_Check                          0x58540
#undef  XKeyInput_Check
#define XKeyInput_Check                         0x78540
#undef  KeyInput_CheckMultiple
#define KeyInput_CheckMultiple                  0x58541
#undef  XKeyInput_CheckMultiple
#define XKeyInput_CheckMultiple                 0x78541
#undef  KeyInput_Scan
#define KeyInput_Scan                           0x58542
#undef  XKeyInput_Scan
#define XKeyInput_Scan                          0x78542
#undef  KeyInput_ScanMultiple
#define KeyInput_ScanMultiple                   0x58543
#undef  XKeyInput_ScanMultiple
#define XKeyInput_ScanMultiple                  0x78543

/********************
 * Type definitions *
 ********************/
typedef bits keyinputcheck_flags;

typedef bits keyinputcheckmultiple_flags;

typedef bits keyinputscan_flags;

typedef bits keyinputscanmultiple_flags;

/************************
 * Constant definitions *
 ************************/
#define keyinputcheckmultipleflags_RETURN_TIME  ((keyinputcheckmultiple_flags) 0x1u)
#define keyinputscanmultipleflags_RETURN_TIME   ((keyinputscanmultiple_flags) 0x1u)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      keyinput_check()
 *
 * Description:   Read the state of a particular key
 *
 * Input:         flags - value of R0 on entry
 *                usage - value of R1 on entry
 *
 * Output:        state - value of R2 on exit
 *                time - value of R3 on exit
 *
 * Other notes:   Calls SWI 0x58540.
 */

extern os_error *xkeyinput_check (keyinputcheck_flags flags,
      int usage,
      int *state,
      int *time);
extern void keyinput_check (keyinputcheck_flags flags,
      int usage,
      int *state,
      int *time);

/* ------------------------------------------------------------------------
 * Function:      keyinput_check_multiple()
 *
 * Description:   Read the state of a number of defined keys
 *
 * Input:         flags - value of R0 on entry
 *                buf - value of R1 on entry
 *                num_entries_to_fill - value of R2 on entry
 *
 * Output:        num_entries_filled - value of R2 on exit
 *
 * Other notes:   Calls SWI 0x58541.
 */

extern os_error *xkeyinput_check_multiple (keyinputcheckmultiple_flags flags,
      int *buf,
      int num_entries_to_fill,
      int *num_entries_filled);
extern void keyinput_check_multiple (keyinputcheckmultiple_flags flags,
      int *buf,
      int num_entries_to_fill,
      int *num_entries_filled);

/* ------------------------------------------------------------------------
 * Function:      keyinput_scan()
 *
 * Description:   Read the currently pressed key information
 *
 * Input:         flags - value of R0 on entry
 *                initial_code - value of R1 on entry
 *
 * Output:        next_code - value of R1 on exit
 *                state - value of R2 on exit
 *                time - value of R3 on exit
 *
 * Other notes:   Calls SWI 0x58542.
 */

extern os_error *xkeyinput_scan (keyinputscan_flags flags,
      int initial_code,
      int *next_code,
      int *state,
      int *time);
extern void keyinput_scan (keyinputscan_flags flags,
      int initial_code,
      int *next_code,
      int *state,
      int *time);

/* ------------------------------------------------------------------------
 * Function:      keyinput_scan_multiple()
 *
 * Description:   Read the state of keys to a buffer
 *
 * Input:         flags - value of R0 on entry
 *                initial_code - value of R1 on entry
 *                buf - value of R2 on entry
 *                num_entries_to_fill - value of R3 on entry
 *
 * Output:        next_code - value of R1 on exit
 *                num_entries_filled - value of R3 on exit
 *
 * Other notes:   Calls SWI 0x58543.
 */

extern os_error *xkeyinput_scan_multiple (keyinputscanmultiple_flags flags,
      int initial_code,
      int *buf,
      int num_entries_to_fill,
      int *next_code,
      int *num_entries_filled);
extern void keyinput_scan_multiple (keyinputscanmultiple_flags flags,
      int initial_code,
      int *buf,
      int num_entries_to_fill,
      int *next_code,
      int *num_entries_filled);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
