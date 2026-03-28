#ifndef cdfsfiler_H
#define cdfsfiler_H

/* C header file for CDFSFiler
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:47:16 2012
 * Tom Hughes, tom@compton.nu, 29 June 2003
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

#ifndef wimp_H
#include "oslib/wimp.h"
#endif

#if defined NAMESPACE_OSLIB
  namespace OSLib {
#endif

/************************************
 * Structure and union declarations *
 ************************************/
typedef struct cdfsfiler_message_open_player    cdfsfiler_message_open_player;
typedef struct cdfsfiler_full_message_open_player cdfsfiler_full_message_open_player;

/********************
 * Type definitions *
 ********************/
struct cdfsfiler_message_open_player
   {  int drive_number;
      bits flags;
   };

struct cdfsfiler_full_message_open_player
   {  wimp_MESSAGE_HEADER_MEMBERS
      int drive_number;
      bits flags;
   };

/************************
 * Constant definitions *
 ************************/
#define message_CDFS_FILER_OPEN_PLAYER          0x4BE00u

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
