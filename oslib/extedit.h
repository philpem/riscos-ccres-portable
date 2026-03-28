#ifndef extedit_H
#define extedit_H

/* C header file for ExtEdit
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:48:24 2012
 * Tom Hughes, tom@compton.nu, 28 Oct 2001
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

#if defined NAMESPACE_OSLIB
  namespace OSLib {
#endif

/************************************
 * Structure and union declarations *
 ************************************/
typedef struct extedit_message_rq               extedit_message_rq;
typedef struct extedit_message_ack              extedit_message_ack;
typedef struct extedit_message_return           extedit_message_return;
typedef struct extedit_message_abort            extedit_message_abort;
typedef struct extedit_message_data_save        extedit_message_data_save;
typedef struct extedit_message_cursor           extedit_message_cursor;

/********************
 * Type definitions *
 ********************/
typedef bits extedit_data_type;

typedef bits extedit_job_handle;

typedef bits extedit_flags;

struct extedit_message_rq
   {  extedit_data_type data_type;
      extedit_job_handle job_handle;
      extedit_flags flags;
      char parent_name [20];
      char leaf_name [204];
   };

struct extedit_message_ack
   {  extedit_data_type data_type;
      extedit_job_handle job_handle;
      extedit_flags flags;
   };

struct extedit_message_return
   {  extedit_data_type data_type;
      extedit_job_handle job_handle;
      extedit_flags flags;
   };

struct extedit_message_abort
   {  byte reserved [4];
      extedit_job_handle job_handle;
   };

struct extedit_message_data_save
   {  extedit_job_handle job_handle;
      byte reserved [12];
      int est_size;
      bits file_type;
      char file_name [212];
   };

struct extedit_message_cursor
   {  byte reserved [4];
      extedit_job_handle job_handle;
      extedit_flags flags;
      int new_cursor_pos;
      int new_sos_pos;
      int new_eos_pos;
      int old_cursor_pos;
      int old_sos_pos;
      int old_eos_pos;
   };

/************************
 * Constant definitions *
 ************************/
#define message_EXT_EDIT_RQ                     0x45D80u
#define message_EXT_EDIT_ACK                    0x45D81u
#define message_EXT_EDIT_RETURN                 0x45D82u
#define message_EXT_EDIT_ABORT                  0x45D83u
#define message_EXT_EDIT_DATA_SAVE              0x45D84u
#define message_EXT_EDIT_CURSOR                 0x45D85u
#define extedit_FILE_TYPE                       ((extedit_data_type) 0xFFFFu)
#define extedit_SUB_TYPE                        ((extedit_data_type) 0xFFFF0000u)
#define extedit_SUB_TYPE_SHIFT                  (16)
#define extedit_CLIENT_HANDLE                   ((extedit_job_handle) 0xFFFFu)
#define extedit_EDITOR_HANDLE                   ((extedit_job_handle) 0xFFFF0000u)
#define extedit_EDITOR_HANDLE_SHIFT             (16)
#define extedit_CONTINUE_EDITING                ((extedit_flags) 0x1u)
#define extedit_SELECTION_ONLY                  ((extedit_flags) 0x2u)
#define extedit_READ_ONLY                       ((extedit_flags) 0x4u)
#define extedit_IMMEDIATE_EXECUTION             ((extedit_flags) 0x8u)
#define extedit_ADJUST_SELECTION                ((extedit_flags) 0x10u)
#define extedit_BEFORE_START                    (0)
#define extedit_AFTER_END                       (-2)
#define extedit_NO_CHANGE                       (-1)

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
