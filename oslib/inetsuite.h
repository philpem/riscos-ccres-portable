#ifndef inetsuite_H
#define inetsuite_H

/* C header file for InetSuite
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:48:24 2012
 * Tom Hughes, tom@compton.nu, 13 Mar 1999
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

/************************************
 * Structure and union declarations *
 ************************************/
typedef union  inetsuite_message_open_url       inetsuite_message_open_url;
typedef struct inetsuite_full_message_open_url_direct inetsuite_full_message_open_url_direct;
typedef struct inetsuite_full_message_open_url_indirect inetsuite_full_message_open_url_indirect;
typedef union  inetsuite_full_message_open_url  inetsuite_full_message_open_url;

/********************
 * Type definitions *
 ********************/
typedef bits inetsuite_open_url_flags;

union inetsuite_message_open_url
   {  char url [236];
      struct
      {  int tag;
         os_string_value url;
         inetsuite_open_url_flags flags;
         os_string_value body_file;
         os_string_value target;
         os_string_value body_mimetype;
      }
      indirect;
   };

struct inetsuite_full_message_open_url_direct
   {  wimp_MESSAGE_HEADER_MEMBERS
      char url [236];
   };

struct inetsuite_full_message_open_url_indirect
   {  wimp_MESSAGE_HEADER_MEMBERS
      int tag;
      os_string_value url;
      inetsuite_open_url_flags flags;
      os_string_value body_file;
      os_string_value target;
      os_string_value body_mimetype;
   };

union inetsuite_full_message_open_url
   {  inetsuite_full_message_open_url_direct direct;
      inetsuite_full_message_open_url_indirect indirect;
   };

/************************
 * Constant definitions *
 ************************/
#define message_INET_SUITE_OPEN_URL             0x4AF80u
#define inetsuite_USE_MIME_TYPE                 ((inetsuite_open_url_flags) 0x1u)

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
