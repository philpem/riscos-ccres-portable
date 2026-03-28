#ifndef diagnosticdump_H
#define diagnosticdump_H

/* C header file for DiagnosticDump
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:47:41 2012
 * John Tytgat, John.Tytgat@aaug.net, 12 Aug 2009
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
#undef  DiagnosticDump_Write
#define DiagnosticDump_Write                    0x58B00
#undef  XDiagnosticDump_Write
#define XDiagnosticDump_Write                   0x78B00

/********************
 * Type definitions *
 ********************/
typedef bits diagnosticdumpwrite_flags;

/************************
 * Constant definitions *
 ************************/
#define diagnosticdumpwriteflags_APP_ACC_NONE   ((diagnosticdumpwrite_flags) 0x0u)
#define diagnosticdumpwriteflags_APP_ACC_READ   ((diagnosticdumpwrite_flags) 0x1u)
#define diagnosticdumpwriteflags_APP_ACC_READ_TRACE ((diagnosticdumpwrite_flags) 0x2u)
#define diagnosticdumpwriteflags_APP_ACC_READ_TRACE_RECORD ((diagnosticdumpwrite_flags) 0x3u)
#define diagnosticdumpwriteflags_FULL_FILENAME  ((diagnosticdumpwrite_flags) 0x4u)
#define diagnosticdumpwriteflags_OPEN_DUMP_DIR  ((diagnosticdumpwrite_flags) 0x8u)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      diagnosticdump_write()
 *
 * Description:   Write, or buffer for later writing, a diagnostic dump for
 *                the current system state - RISC OS 6
 *
 * Input:         flags - value of R0 on entry
 *                filename - value of R1 on entry
 *                regs - value of R2 on entry
 *
 * Other notes:   Calls SWI 0x58B00.
 */

extern os_error *xdiagnosticdump_write (diagnosticdumpwrite_flags flags,
      char const *filename,
      os_register_block const *regs);
__swi (0x58B00) void diagnosticdump_write (diagnosticdumpwrite_flags flags,
      char const *filename,
      os_register_block const *regs);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
