#ifndef resourcefs_H
#define resourcefs_H

/* C header file for ResourceFS
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:47:15 2012
 * Jonathan Coxhead, jonathan@doves.demon.co.uk, 30 May 1995
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

#ifndef fileswitch_H
#include "oslib/fileswitch.h"
#endif

#if defined NAMESPACE_OSLIB
  namespace OSLib {
#endif

/**********************************
 * SWI names and SWI reason codes *
 **********************************/
#undef  ResourceFS_RegisterFiles
#define ResourceFS_RegisterFiles                0x41B40
#undef  XResourceFS_RegisterFiles
#define XResourceFS_RegisterFiles               0x61B40
#undef  ResourceFS_DeregisterFiles
#define ResourceFS_DeregisterFiles              0x41B41
#undef  XResourceFS_DeregisterFiles
#define XResourceFS_DeregisterFiles             0x61B41
#undef  Service_ResourceFSStarted
#define Service_ResourceFSStarted               0x59
#undef  Service_ResourceFSDying
#define Service_ResourceFSDying                 0x5A
#undef  Service_ResourceFSStarting
#define Service_ResourceFSStarting              0x60

/************************************
 * Structure and union declarations *
 ************************************/
typedef struct resourcefs_file_header           resourcefs_file_header;
typedef struct resourcefs_file_header_base      resourcefs_file_header_base;
typedef struct resourcefs_file_data             resourcefs_file_data;
typedef struct resourcefs_file_data_base        resourcefs_file_data_base;
typedef struct resourcefs_file                  resourcefs_file;
typedef struct resourcefs_file_list             resourcefs_file_list;
typedef struct resourcefs_file_list_base        resourcefs_file_list_base;

/********************
 * Type definitions *
 ********************/
#define resourcefs_FILE_HEADER_MEMBERS \
   int data_size; \
   bits load_addr; \
   bits exec_addr; \
   int size; \
   fileswitch_attr attr;

/* Base resourcefs_file_header structure without variable part */
struct resourcefs_file_header_base
   {  resourcefs_FILE_HEADER_MEMBERS
   };

/* legacy structure */
struct resourcefs_file_header
   {  resourcefs_FILE_HEADER_MEMBERS
      char name [UNKNOWN];
   };

#define resourcefs_FILE_HEADER(N) \
   struct \
      {  resourcefs_FILE_HEADER_MEMBERS \
         char name [N]; \
      }

#define resourcefs_SIZEOF_FILE_HEADER(N) \
   (offsetof (resourcefs_file_header, name) + \
         (N)*sizeof ((resourcefs_file_header *) NULL)->name)

#define resourcefs_FILE_DATA_MEMBERS \
   int size;

/* Base resourcefs_file_data structure without variable part */
struct resourcefs_file_data_base
   {  resourcefs_FILE_DATA_MEMBERS
   };

/* legacy structure */
struct resourcefs_file_data
   {  resourcefs_FILE_DATA_MEMBERS
      byte data [UNKNOWN];
   };

#define resourcefs_FILE_DATA(N) \
   struct \
      {  resourcefs_FILE_DATA_MEMBERS \
         byte data [N]; \
      }

#define resourcefs_SIZEOF_FILE_DATA(N) \
   (offsetof (resourcefs_file_data, data) + \
         (N)*sizeof ((resourcefs_file_data *) NULL)->data)

struct resourcefs_file
   {  resourcefs_file_header header;
      resourcefs_file_data data;
   };

struct resourcefs_file_list
   {  resourcefs_file file [UNKNOWN];
   };

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      resourcefs_register_files()
 *
 * Description:   Add file(s) to the ResourceFS structure
 *
 * Input:         file_list - value of R0 on entry
 *
 * Other notes:   Calls SWI 0x41B40.
 */

extern os_error *xresourcefs_register_files (resourcefs_file_list const *file_list);
__swi (0x41B40) void resourcefs_register_files (resourcefs_file_list const *file_list);

/* ------------------------------------------------------------------------
 * Function:      resourcefs_deregister_files()
 *
 * Description:   Remove file(s) from the ResourceFS structure
 *
 * Input:         file_list - value of R0 on entry
 *
 * Other notes:   Calls SWI 0x41B41.
 */

extern os_error *xresourcefs_deregister_files (resourcefs_file_list const *file_list);
__swi (0x41B41) void resourcefs_deregister_files (resourcefs_file_list const *file_list);

/* ------------------------------------------------------------------------
 * Function:      service_resource_fs_started()
 *
 * Description:   The file structure inside ResourceFS has changed
 *
 * Other notes:   Calls SWI 0x30 with R1 = 0x59.
 */

extern os_error *xservice_resource_fs_started (void);
extern void service_resource_fs_started (void);

/* ------------------------------------------------------------------------
 * Function:      service_resource_fs_dying()
 *
 * Description:   ResourceFS is killed
 *
 * Other notes:   Calls SWI 0x30 with R1 = 0x5A.
 */

extern os_error *xservice_resource_fs_dying (void);
extern void service_resource_fs_dying (void);

/* ------------------------------------------------------------------------
 * Function:      service_resource_fs_starting()
 *
 * Description:   ResourceFS module is reloaded or reinitialised
 *
 * Input:         register_files - value of R2 on entry
 *                workspace - value of R3 on entry
 *
 * Other notes:   Calls SWI 0x30 with R1 = 0x60.
 */

extern os_error *xservice_resource_fs_starting (asm_routine register_files,
      void *workspace);
extern void service_resource_fs_starting (asm_routine register_files,
      void *workspace);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
