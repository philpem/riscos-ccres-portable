#ifndef sharefs_H
#define sharefs_H

/* C header file for ShareFS
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:47:16 2012
 * Jonathan Coxhead, jonathan@doves.demon.co.uk, 22 Aug 1995
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

#ifndef freeway_H
#include "oslib/freeway.h"
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
#undef  ShareFS_CreateShare
#define ShareFS_CreateShare                     0x47AC0
#undef  XShareFS_CreateShare
#define XShareFS_CreateShare                    0x67AC0
#undef  ShareFS_StopShare
#define ShareFS_StopShare                       0x47AC1
#undef  XShareFS_StopShare
#define XShareFS_StopShare                      0x67AC1
#undef  ShareFS_EnumerateShares
#define ShareFS_EnumerateShares                 0x47AC2
#undef  XShareFS_EnumerateShares
#define XShareFS_EnumerateShares                0x67AC2
#undef  ShareFS_IdentifyShare
#define ShareFS_IdentifyShare                   0x47AC3
#undef  XShareFS_IdentifyShare
#define XShareFS_IdentifyShare                  0x67AC3
#undef  Service_ShareFSStarting
#define Service_ShareFSStarting                 0x97
#undef  Service_ShareFSTerminating
#define Service_ShareFSTerminating              0x98
#undef  Service_Sharing
#define Service_Sharing                         0x801C8

/************************************
 * Structure and union declarations *
 ************************************/
typedef struct sharefs_message_file_share_dir   sharefs_message_file_share_dir;

/********************
 * Type definitions *
 ********************/
typedef bits sharefs_attr;

typedef bits sharefs_share_flags;

typedef bits sharefs_stop_flags;

typedef bits sharefs_enumerate_flags;

typedef bits sharefs_identify_share_flags;

typedef bits sharefsmessagefilesharedir_flags;

struct sharefs_message_file_share_dir
   {  sharefsmessagefilesharedir_flags flags;
      int xpos;
      int ypos;
      char dir_name [224];
   };

typedef bits sharefs_starting_flags;

typedef bits sharefs_terminating_flags;

/************************
 * Constant definitions *
 ************************/
#define sharefs_ATTR_DISC                       ((sharefs_attr) 0x1u)
#define sharefs_ATTR_DISCP                      ((sharefs_attr) 0x2u)
#define sharefs_ATTR_DISC_RO                    ((sharefs_attr) 0x4u)
#define sharefs_ATTR_HIDDEN                     ((sharefs_attr) 0x8u)
#define sharefs_ATTR_SUBDIR_AUTH                ((sharefs_attr) 0x10u)
#define sharefs_ATTR_CDROM                      ((sharefs_attr) 0x20u)
#define sharefs_ATTR_CDROM_AUTH                 ((sharefs_attr) 0x40u)
#define sharefs_FILE_TYPE_DISCP                 0xBD9u
#define sharefs_FILE_TYPE_DISC                  0xBDAu
#define sharefs_FILE_TYPE_SUBDIR                0xFAFu
#define sharefs_FILE_TYPE_CDROM                 0xFADu
#define sharefs_FILE_TYPE_DISCR                 0xFB4u
#define sharefs_FILE_TYPE_NO_DISC               0xFB5u
#define sharefs_SHARE_DISC                      ((sharefs_share_flags) 0x0u)
#define sharefs_SHARE_DISCP                     ((sharefs_share_flags) 0x1u)
      /*protected */
#define sharefs_SHARE_DISC_RO                   ((sharefs_share_flags) 0x2u)
      /*read-only */
#define sharefs_SHARE_HIDDEN                    ((sharefs_share_flags) 0x4u)
      /*hidden */
#define sharefs_SHARE_SUBDIR_AUTH               ((sharefs_share_flags) 0x8u)
      /*sub directory*/
#define sharefs_SHARE_CDROM                     ((sharefs_share_flags) 0x10u)
      /*CDROM */
#define sharefs_SHARE_CDROM_AUTH                ((sharefs_share_flags) 0x20u)
      /*authentication */
#define sharefs_NO_MORE                         (-1)
#define sharefs_ENUMERATE_PROTECTED             ((sharefs_enumerate_flags) 0x1u)
#define sharefs_ENUMERATE_READ_ONLY             ((sharefs_enumerate_flags) 0x2u)
#define sharefs_ENUMERATE_HIDDEN                ((sharefs_enumerate_flags) 0x4u)
#define sharefs_ENUMERATE_SUBDIR                ((sharefs_enumerate_flags) 0x8u)
#define sharefs_ENUMERATE_CDROM                 ((sharefs_enumerate_flags) 0x10u)
#define sharefs_ENUMERATE_AUTHENTICATED         ((sharefs_enumerate_flags) 0x80000000u)
#define sharefs_IDENTIFY_SHARE_SHARE_NAME       ((sharefs_identify_share_flags) 0x1u)
#define message_FILE_SHARE_DIR                  0x408u
#define sharefsmessagefilesharedirflags_PROTECTED ((sharefsmessagefilesharedir_flags) 0x1u)
#define sharefsmessagefilesharedirflags_READ_ONLY ((sharefsmessagefilesharedir_flags) 0x2u)
#define sharefsmessagefilesharedirflags_HIDDEN  ((sharefsmessagefilesharedir_flags) 0x4u)
#define sharefsmessagefilesharedirflags_AUTHENTICATED ((sharefsmessagefilesharedir_flags) 0x8u)
#define sharefsmessagefilesharedirflags_CDROM   ((sharefsmessagefilesharedir_flags) 0x10u)
#define sharefsmessagefilesharedirflags_WINDOW_POS_GIVEN ((sharefsmessagefilesharedir_flags) 0x40000000u)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      sharefs_create_share()
 *
 * Description:   Start sharing a local disc or subdirectory, or change the
 *                mode of an existing share
 *
 * Input:         flags - value of R0 on entry
 *                obj_name - value of R1 on entry
 *                dir_path - value of R2 on entry
 *                authentication - value of R3 on entry
 *
 * Other notes:   Calls SWI 0x47AC0.
 */

extern os_error *xsharefs_create_share (sharefs_share_flags flags,
      char const *obj_name,
      char const *dir_path,
      int authentication);
__swi (0x47AC0) void sharefs_create_share (sharefs_share_flags flags,
      char const *obj_name,
      char const *dir_path,
      int authentication);

/* ------------------------------------------------------------------------
 * Function:      sharefs_stop_share()
 *
 * Description:   Stop sharing a local directory
 *
 * Input:         flags - value of R0 on entry
 *                obj_name - value of R1 on entry
 *
 * Other notes:   Calls SWI 0x47AC1.
 */

extern os_error *xsharefs_stop_share (sharefs_stop_flags flags,
      char const *obj_name);
__swi (0x47AC1) void sharefs_stop_share (sharefs_stop_flags flags,
      char const *obj_name);

/* ------------------------------------------------------------------------
 * Function:      sharefs_enumerate_shares()
 *
 * Description:   Enumerates authenticated or unauthenticated shares
 *                currently active on this machine
 *
 * Input:         flags - value of R0 on entry
 *                context - start with 0
 *                authentication - value of R5 on entry
 *
 * Output:        obj_name - value of R1 on exit
 *                dir_path - value of R2 on exit
 *                attr - value of R3 on exit
 *                context_out - value of R4 on exit (X version only)
 *
 * Returns:       R4 (non-X version only)
 *
 * Other notes:   Calls SWI 0x47AC2.
 */

extern os_error *xsharefs_enumerate_shares (sharefs_enumerate_flags flags,
      int context,
      int authentication,
      char **obj_name,
      char **dir_path,
      sharefs_attr *attr,
      int *context_out);
extern int sharefs_enumerate_shares (sharefs_enumerate_flags flags,
      int context,
      int authentication,
      char **obj_name,
      char **dir_path,
      sharefs_attr *attr);

/* ------------------------------------------------------------------------
 * Function:      sharefs_identify_share()
 *
 * Description:   To identify a share given its name or directory name -
 *                RISC OS 6
 *
 * Input:         flags - value of R0 on entry
 *                obj_name_or_dir_path - value of R1 on entry
 *                buf - value of R2 on entry
 *                buf_size - value of R3 on entry
 *
 * Output:        attr - value of R0 on exit (X version only)
 *                buf_size_out - value of R3 on exit
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x47AC3.
 */

extern os_error *xsharefs_identify_share (sharefs_identify_share_flags flags,
      char const *obj_name_or_dir_path,
      byte *buf,
      int buf_size,
      sharefs_attr *attr,
      int *buf_size_out);
extern sharefs_attr sharefs_identify_share (sharefs_identify_share_flags flags,
      char const *obj_name_or_dir_path,
      byte *buf,
      int buf_size,
      int *buf_size_out);

/* ------------------------------------------------------------------------
 * Function:      service_share_fs_starting()
 *
 * Description:   ShareFS has started up
 *
 * Input:         flags - value of R2 on entry
 *
 * Other notes:   Calls SWI 0x30 with R1 = 0x97.
 */

extern os_error *xservice_share_fs_starting (sharefs_starting_flags flags);
extern void service_share_fs_starting (sharefs_starting_flags flags);

/* ------------------------------------------------------------------------
 * Function:      service_share_fs_terminating()
 *
 * Description:   ShareFS is terminating
 *
 * Input:         flags - value of R2 on entry
 *
 * Other notes:   Calls SWI 0x30 with R1 = 0x98.
 */

extern os_error *xservice_share_fs_terminating (sharefs_terminating_flags flags);
extern void service_share_fs_terminating (sharefs_terminating_flags flags);

/* ------------------------------------------------------------------------
 * Function:      service_sharing()
 *
 * Description:   Share changed
 *
 * Input:         fsname - value of R0 on entry
 *                state - 0 object unshared, 1 object shared
 *                dir_name - value of R3 on entry
 *                obj_name - value of R4 on entry
 *                priv_data - value of R5 on entry
 *
 * Other notes:   Calls SWI 0x30 with R1 = 0x801C8.
 */

extern os_error *xservice_sharing (char const *fsname,
      int state,
      char const *dir_name,
      char const *obj_name,
      int priv_data);
extern void service_sharing (char const *fsname,
      int state,
      char const *dir_name,
      char const *obj_name,
      int priv_data);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
