#ifndef help_H
#define help_H

/* C header file for Help
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:48:24 2012
 * Jonathan Coxhead, jonathan@doves.demon.co.uk, 12 June 1995
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
typedef struct help_message_request             help_message_request;
typedef struct help_message_reply               help_message_reply;
typedef struct help_message_enable              help_message_enable;
typedef struct help_full_message_request        help_full_message_request;
typedef struct help_full_message_reply          help_full_message_reply;
typedef struct help_full_message_enable         help_full_message_enable;

/********************
 * Type definitions *
 ********************/
typedef bits help_flags;

/* ------------------------------------------------------------------------
 * Type:          help_message_request
 *
 * Description:   message type to request help from an application
 *
 * Fields:        pos - mouse coordinates
 *                buttons - mouse button state
 *                w - window handle
 *                i - icon handle
 */

struct help_message_request
   {  os_coord pos;
      wimp_mouse_state buttons;
      wimp_w w;
      wimp_i i;
   };

/* ------------------------------------------------------------------------
 * Type:          help_message_reply
 *
 * Description:   message type to reply with help text
 *
 * Fields:        reply - help message, 0-terminated
 */

struct help_message_reply
   {  char reply [236];
   };

/* ------------------------------------------------------------------------
 * Type:          help_message_enable
 *
 * Description:   message type to switch help on and off - RISC OS 4+
 */

struct help_message_enable
   {  help_flags flags;
   };

/* ------------------------------------------------------------------------
 * Type:          help_full_message_request
 *
 * Description:   message type to request help from an application
 *
 * Fields:        pos - mouse coordinates
 *                buttons - mouse button state
 *                w - window handle
 *                i - icon handle
 */

struct help_full_message_request
   {  wimp_MESSAGE_HEADER_MEMBERS
      os_coord pos;
      wimp_mouse_state buttons;
      wimp_w w;
      wimp_i i;
   };

/* ------------------------------------------------------------------------
 * Type:          help_full_message_reply
 *
 * Description:   message type to reply with help text
 *
 * Fields:        reply - help message, 0-terminated
 */

struct help_full_message_reply
   {  wimp_MESSAGE_HEADER_MEMBERS
      char reply [236];
   };

/* ------------------------------------------------------------------------
 * Type:          help_full_message_enable
 *
 * Description:   message type to switch help on and off - RISC OS 4+
 */

struct help_full_message_enable
   {  wimp_MESSAGE_HEADER_MEMBERS
      help_flags flags;
   };

/************************
 * Constant definitions *
 ************************/
#define message_HELP_REQUEST                    0x502u
#define message_HELP_REPLY                      0x503u
#define message_HELP_ENABLE                     0x504u
      /*RISC OS 4+*/
#define help_DISABLE                            ((help_flags) 0x1u)
#define help_READ_CONFIGURATION                 ((help_flags) 0x2u)

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
