#ifndef dosfs_H
#define dosfs_H

/* C header file for DOSFS
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:47:15 2012
 * Jonathan Coxhead, jonathan@doves.demon.co.uk, 24 May 1995
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

#ifndef filecore_H
#include "oslib/filecore.h"
#endif

#if defined NAMESPACE_OSLIB
  namespace OSLib {
#endif

/**********************************
 * SWI names and SWI reason codes *
 **********************************/
#undef  DOSFS_DiscFormat
#define DOSFS_DiscFormat                        0x44B00
#undef  XDOSFS_DiscFormat
#define XDOSFS_DiscFormat                       0x64B00
#undef  DOSFS_LayoutStructure
#define DOSFS_LayoutStructure                   0x44B01
#undef  XDOSFS_LayoutStructure
#define XDOSFS_LayoutStructure                  0x64B01
#undef  DOSFS_LayoutStructureW
#define DOSFS_LayoutStructureW                  0x44B01
#undef  XDOSFS_LayoutStructureW
#define XDOSFS_LayoutStructureW                 0x64B01
#undef  DOSFS_LayoutStructureGivenSize
#define DOSFS_LayoutStructureGivenSize          0x44B01
#undef  XDOSFS_LayoutStructureGivenSize
#define XDOSFS_LayoutStructureGivenSize         0x64B01
#undef  DOSFS_LayoutStructureGivenSizeW
#define DOSFS_LayoutStructureGivenSizeW         0x44B01
#undef  XDOSFS_LayoutStructureGivenSizeW
#define XDOSFS_LayoutStructureGivenSizeW        0x64B01

/********************
 * Type definitions *
 ********************/
typedef int dosfs_format_specifier;

/************************
 * Constant definitions *
 ************************/
#define dosfs_FORMAT_DOSQ                       ((dosfs_format_specifier) 0x0u)
#define dosfs_FORMAT_DOSM                       ((dosfs_format_specifier) 0x1u)
#define dosfs_FORMAT_DOSH                       ((dosfs_format_specifier) 0x2u)
#define dosfs_FORMAT_DOSN                       ((dosfs_format_specifier) 0x3u)
#define dosfs_FORMAT_DOSP                       ((dosfs_format_specifier) 0x4u)
#define dosfs_FORMAT_DOST                       ((dosfs_format_specifier) 0x5u)
#define dosfs_FORMAT_DOSU                       ((dosfs_format_specifier) 0x6u)
#define dosfs_FORMAT_ATARIM                     ((dosfs_format_specifier) 0x7u)
#define dosfs_FORMAT_ATARIN                     ((dosfs_format_specifier) 0x8u)
#define dosfs_FORMAT_PCMCIA                     ((dosfs_format_specifier) 0x9u)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      dosfs_disc_format()
 *
 * Description:   Fills in a disc format structure with parameters for the
 *                specified format
 *
 * Input:         buffer - value of R0 on entry
 *                vet_format_swi - value of R1 on entry
 *                vet_format_handle - value of R2 on entry
 *                format - value of R3 on entry
 *
 * Other notes:   Calls SWI 0x44B00.
 */

extern os_error *xdosfs_disc_format (filecore_format *buffer,
      int vet_format_swi,
      int vet_format_handle,
      dosfs_format_specifier format);
__swi (0x44B00) void dosfs_disc_format (filecore_format *buffer,
      int vet_format_swi,
      int vet_format_handle,
      dosfs_format_specifier format);

/* ------------------------------------------------------------------------
 * Function:      dosfs_layout_structure()
 *
 * Description:   Lays out into the specified image a set of structures for
 *                its format. Prefer DOSFS_LayoutStructureW
 *
 * Input:         format - value of R0 on entry
 *                defect_list - value of R1 on entry
 *                disc_name - value of R2 on entry
 *                image_file - value of R3 on entry
 *
 * Other notes:   Calls SWI 0x44B01.
 */

extern os_error *xdosfs_layout_structure (dosfs_format_specifier format,
      filecore_defect_list const *defect_list,
      char const *disc_name,
      os_f image_file);
__swi (0x44B01) void dosfs_layout_structure (dosfs_format_specifier format,
      filecore_defect_list const *defect_list,
      char const *disc_name,
      os_f image_file);

/* ------------------------------------------------------------------------
 * Function:      dosfs_layout_structurew()
 *
 * Description:   Lays out into the specified image a set of structures for
 *                its format. Uses 32-bit file handle
 *
 * Input:         format - value of R0 on entry
 *                defect_list - value of R1 on entry
 *                disc_name - value of R2 on entry
 *                image_file - value of R3 on entry
 *
 * Other notes:   Calls SWI 0x44B01.
 */

extern os_error *xdosfs_layout_structurew (dosfs_format_specifier format,
      filecore_defect_list const *defect_list,
      char const *disc_name,
      os_fw image_file);
__swi (0x44B01) void dosfs_layout_structurew (dosfs_format_specifier format,
      filecore_defect_list const *defect_list,
      char const *disc_name,
      os_fw image_file);

/* ------------------------------------------------------------------------
 * Function:      dosfs_layout_structure_given_size()
 *
 * Description:   Lays out into the specified image a set of structures for
 *                its format. Prefer DOSFS_LayoutStructureGivenSizeW
 *
 * Input:         format - value of R0 on entry
 *                defect_list - value of R1 on entry
 *                disc_name - value of R2 on entry
 *                image_file - value of R3 on entry
 *                size - value of R4 on entry
 *
 * Other notes:   Calls SWI 0x44B01.
 */

extern os_error *xdosfs_layout_structure_given_size (dosfs_format_specifier format,
      filecore_defect_list const *defect_list,
      char const *disc_name,
      os_f image_file,
      int size);
extern void dosfs_layout_structure_given_size (dosfs_format_specifier format,
      filecore_defect_list const *defect_list,
      char const *disc_name,
      os_f image_file,
      int size);

/* ------------------------------------------------------------------------
 * Function:      dosfs_layout_structure_given_sizew()
 *
 * Description:   Lays out into the specified image a set of structures for
 *                its format
 *
 * Input:         format - value of R0 on entry
 *                defect_list - value of R1 on entry
 *                disc_name - value of R2 on entry
 *                image_file - value of R3 on entry
 *                size - value of R4 on entry
 *
 * Other notes:   Calls SWI 0x44B01.
 */

extern os_error *xdosfs_layout_structure_given_sizew (dosfs_format_specifier format,
      filecore_defect_list const *defect_list,
      char const *disc_name,
      os_fw image_file,
      int size);
extern void dosfs_layout_structure_given_sizew (dosfs_format_specifier format,
      filecore_defect_list const *defect_list,
      char const *disc_name,
      os_fw image_file,
      int size);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#ifndef dosfs32_H
#include "oslib/dosfs32.h"
#endif

#endif
