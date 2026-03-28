#ifndef pathutils_H
#define pathutils_H

/* C header file for PathUtils
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:47:15 2012
 * John Tytgat, John.Tytgat@aaug.net, 10 Aug 2009
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
#undef  PathUtils_EnumeratePath
#define PathUtils_EnumeratePath                 0x56B80
#undef  XPathUtils_EnumeratePath
#define XPathUtils_EnumeratePath                0x76B80
#undef  PathUtils_JoinPath
#define PathUtils_JoinPath                      0x56B81
#undef  XPathUtils_JoinPath
#define XPathUtils_JoinPath                     0x76B81
#undef  PathUtils_RemovePath
#define PathUtils_RemovePath                    0x56B82
#undef  XPathUtils_RemovePath
#define XPathUtils_RemovePath                   0x76B82

/********************
 * Type definitions *
 ********************/
typedef bits pathutilsenumeratepath_flags;

typedef bits pathutilsjoinpath_flags;

typedef bits pathutilsremovepath_flags;

/************************
 * Constant definitions *
 ************************/
#define pathutilsenumeratepathflags_ALL_PATH_COMPONENTS ((pathutils_enumerate_path_flags) 0x1u)
#define pathutilsjoinpathflags_APPEND           ((pathutils_join_path_flags) 0x1u)
      /*Set for appending, clear for prepending*/

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      pathutils_enumerate_path()
 *
 * Description:   Enumerate the components of a path variables - RISC OS 6
 *
 * Input:         flags - value of R0 on entry
 *                path - value of R1 on entry
 *                output_buf - value of R2 on entry
 *                output_buf_size - value of R3 on entry
 *                context - value of R4 on entry
 *
 * Output:        spare_bytes - value of R3 on exit
 *                new_context - value of R4 on exit
 *                var_type - value of R5 on exit
 *                depth - value of R6 on exit
 *
 * Other notes:   Calls SWI 0x56B80.
 */

extern os_error *xpathutils_enumerate_path (pathutilsenumeratepath_flags flags,
      char const *path,
      char *output_buf,
      int output_buf_size,
      int context,
      int *spare_bytes,
      int *new_context,
      os_var_type *var_type,
      int *depth);
extern void pathutils_enumerate_path (pathutilsenumeratepath_flags flags,
      char const *path,
      char *output_buf,
      int output_buf_size,
      int context,
      int *spare_bytes,
      int *new_context,
      os_var_type *var_type,
      int *depth);

/* ------------------------------------------------------------------------
 * Function:      pathutils_join_path()
 *
 * Description:   Add a component to a path variable - RISC OS 6
 *
 * Input:         flags - value of R0 on entry
 *                path_var_name - value of R1 on entry
 *                value_to_join - value of R2 on entry
 *
 * Other notes:   Calls SWI 0x56B81.
 */

extern os_error *xpathutils_join_path (pathutilsjoinpath_flags flags,
      char const *path_var_name,
      char const *value_to_join);
__swi (0x56B81) void pathutils_join_path (pathutilsjoinpath_flags flags,
      char const *path_var_name,
      char const *value_to_join);

/* ------------------------------------------------------------------------
 * Function:      pathutils_remove_path()
 *
 * Description:   Remove a component from a path variable - RISC OS 6
 *
 * Input:         flags - value of R0 on entry
 *                path_var_name - value of R1 on entry
 *                value_to_remove - value of R2 on entry
 *
 * Other notes:   Calls SWI 0x56B82.
 */

extern os_error *xpathutils_remove_path (pathutilsremovepath_flags flags,
      char const *path_var_name,
      char const *value_to_remove);
__swi (0x56B82) void pathutils_remove_path (pathutilsremovepath_flags flags,
      char const *path_var_name,
      char const *value_to_remove);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
