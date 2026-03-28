#ifndef clipboardholder_H
#define clipboardholder_H

/* C header file for ClipboardHolder
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
#undef  ClipboardHolder_Copy
#define ClipboardHolder_Copy                    0x54040
#undef  XClipboardHolder_Copy
#define XClipboardHolder_Copy                   0x74040
#undef  ClipboardHolderCopy_FromMemory
#define ClipboardHolderCopy_FromMemory          0x0
#undef  ClipboardHolderCopy_FromFile
#define ClipboardHolderCopy_FromFile            0x1
#undef  ClipboardHolder_Paste
#define ClipboardHolder_Paste                   0x54041
#undef  XClipboardHolder_Paste
#define XClipboardHolder_Paste                  0x74041
#undef  ClipboardHolderPaste_GetState
#define ClipboardHolderPaste_GetState           0x8
#undef  ClipboardHolderPaste_ToMemory
#define ClipboardHolderPaste_ToMemory           0x0
#undef  ClipboardHolderPaste_ToFile
#define ClipboardHolderPaste_ToFile             0x1

/********************
 * Type definitions *
 ********************/
typedef bits clipboardholderpaste_status_flags;

/************************
 * Constant definitions *
 ************************/
#define clipboardholderpastestatus_DELIVERABLE_TO_MEMORY ((clipboardholderpaste_status_flags) 0x1u)
#define clipboardholderpastestatus_DELIVERABLE_TO_FILE ((clipboardholderpaste_status_flags) 0x2u)
#define clipboardholderpastestatus_NEEDS_PROTOCOL ((clipboardholderpaste_status_flags) 0x4u)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      clipboardholdercopy_from_memory()
 *
 * Description:   Copies data from memory to the clipboard - RISC OS 6
 *
 * Input:         filetype - value of R1 on entry
 *                src - value of R2 on entry
 *                length - value of R3 on entry
 *
 * Other notes:   Calls SWI 0x54040 with R0 = 0x0.
 */

extern os_error *xclipboardholdercopy_from_memory (int filetype,
      byte const *src,
      int length);
extern void clipboardholdercopy_from_memory (int filetype,
      byte const *src,
      int length);

/* ------------------------------------------------------------------------
 * Function:      clipboardholdercopy_from_file()
 *
 * Description:   Copies data from file to the clipboard - RISC OS 6
 *
 * Input:         filetype - value of R1 on entry
 *                filename - value of R2 on entry
 *
 * Other notes:   Calls SWI 0x54040 with R0 = 0x1.
 */

extern os_error *xclipboardholdercopy_from_file (int filetype,
      char const *filename);
extern void clipboardholdercopy_from_file (int filetype,
      char const *filename);

/* ------------------------------------------------------------------------
 * Function:      clipboardholderpaste_get_state()
 *
 * Description:   Get status and filetype - RISC OS 6
 *
 * Input:         pref_filetype - value of R1 on entry
 *
 * Output:        status - value of R0 on exit (X version only)
 *                filetype - value of R1 on exit
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x54041 with R0 = 0x8.
 */

extern os_error *xclipboardholderpaste_get_state (int pref_filetype,
      clipboardholderpaste_status_flags *status,
      int *filetype);
extern clipboardholderpaste_status_flags clipboardholderpaste_get_state (int pref_filetype,
      int *filetype);

/* ------------------------------------------------------------------------
 * Function:      clipboardholderpaste_to_memory()
 *
 * Description:   Request data to 'paste' from the clipboard to memory -
 *                RISC OS 6
 *
 * Input:         pref_filetype - value of R1 on entry
 *                window_handle - value of R2 on entry
 *                handle - value of R3 on entry
 *
 * Output:        status - value of R0 on exit (X version only)
 *                filetype - value of R1 on exit
 *                src - value of R2 on exit
 *                length - value of R3 on exit
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x54041 with R0 = 0x0.
 */

extern os_error *xclipboardholderpaste_to_memory (int pref_filetype,
      wimp_w window_handle,
      int handle,
      clipboardholderpaste_status_flags *status,
      int *filetype,
      byte **src,
      int *length);
extern clipboardholderpaste_status_flags clipboardholderpaste_to_memory (int pref_filetype,
      wimp_w window_handle,
      int handle,
      int *filetype,
      byte **src,
      int *length);

/* ------------------------------------------------------------------------
 * Function:      clipboardholderpaste_to_file()
 *
 * Description:   Request data to 'paste' from the clipboard to file - RISC
 *                OS 6
 *
 * Input:         pref_filetype - value of R1 on entry
 *                window_handle - value of R2 on entry
 *                handle - value of R3 on entry
 *
 * Output:        status - value of R0 on exit (X version only)
 *                filetype - value of R1 on exit
 *                filename - value of R2 on exit
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x54041 with R0 = 0x1.
 */

extern os_error *xclipboardholderpaste_to_file (int pref_filetype,
      wimp_w window_handle,
      int handle,
      clipboardholderpaste_status_flags *status,
      int *filetype,
      char **filename);
extern clipboardholderpaste_status_flags clipboardholderpaste_to_file (int pref_filetype,
      wimp_w window_handle,
      int handle,
      int *filetype,
      char **filename);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
