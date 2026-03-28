#ifndef debugger_H
#define debugger_H

/* C header file for Debugger
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:47:41 2012
 * Jonathan Coxhead, jonathan@doves.demon.co.uk, 29 June 1995
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
#undef  Debugger_Disassemble
#define Debugger_Disassemble                    0x40380
#undef  XDebugger_Disassemble
#define XDebugger_Disassemble                   0x60380
#undef  Debugger_DisassembleThumb
#define Debugger_DisassembleThumb               0x40381
#undef  XDebugger_DisassembleThumb
#define XDebugger_DisassembleThumb              0x60381

/************************
 * Constant definitions *
 ************************/
#define error_DEBUG_BREAK_NOT_FOUND             0x800u
      /*Breakpoint not found*/
#define error_DEBUG_INVALID_VALUE               0x801u
      /*Invalid value*/
#define error_DEBUG_RESETTING                   0x802u
      /*Resetting breakpoint*/
#define error_DEBUG_NO_ROOM                     0x803u
      /*No room in breakpoint table*/
#define error_DEBUG_NO_BREAKPOINTS              0x804u
      /*No breakpoints set*/
#define error_DEBUG_BAD_BREAKPOINT              0x805u
      /*Bad breakpoint*/
#define error_DEBUG_UNDEFINED                   0x806u
      /*Undefined breakpoint*/
#define error_DEBUG_NON_ALIGNED                 0x807u
      /*Unaligned address*/
#define error_DEBUG_NO_WORKSPACE                0x808u
      /*No room for debug module workspace*/

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      debugger_disassemble()
 *
 * Description:   Disassembles an instruction
 *
 * Input:         instruction - value of R0 on entry
 *                address - value of R1 on entry
 *
 * Output:        disassembly - value of R1 on exit
 *                used - value of R2 on exit
 *
 * Other notes:   Calls SWI 0x40380.
 */

extern os_error *xdebugger_disassemble (int instruction,
      int *address,
      char **disassembly,
      int *used);
extern void debugger_disassemble (int instruction,
      int *address,
      char **disassembly,
      int *used);

/* ------------------------------------------------------------------------
 * Function:      debugger_disassemble_thumb()
 *
 * Description:   Disassembles a thumb instruction - RISC OS 4+
 *
 * Input:         instruction - value of R0 on entry
 *                address - value of R1 on entry
 *
 * Output:        disassembly - value of R1 on exit
 *                used - value of R2 on exit
 *
 * Other notes:   Calls SWI 0x40381.
 */

extern os_error *xdebugger_disassemble_thumb (int instruction,
      int *address,
      char **disassembly,
      int *used);
extern void debugger_disassemble_thumb (int instruction,
      int *address,
      char **disassembly,
      int *used);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
