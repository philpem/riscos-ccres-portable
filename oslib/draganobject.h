#ifndef draganobject_H
#define draganobject_H

/* C header file for DragAnObject
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:48:09 2012
 * Jonathan Coxhead, jonathan@doves.demon.co.uk, 18 Jan 1995
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
#undef  DragAnObject_Start
#define DragAnObject_Start                      0x49C40
#undef  XDragAnObject_Start
#define XDragAnObject_Start                     0x69C40
#undef  DragAnObject_Stop
#define DragAnObject_Stop                       0x49C41
#undef  XDragAnObject_Stop
#define XDragAnObject_Stop                      0x69C41

/********************
 * Type definitions *
 ********************/
typedef bits draganobject_flags;
      /*Flags word for DragAnObject_Start*/

/************************
 * Constant definitions *
 ************************/
#define draganobject_HPOS_LEFT                  ((draganobject_flags) 0x0u)
#define draganobject_HPOS_CENTRE                ((draganobject_flags) 0x1u)
#define draganobject_HPOS_RIGHT                 ((draganobject_flags) 0x2u)
#define draganobject_VPOS_BOTTOM                ((draganobject_flags) 0x0u)
#define draganobject_VPOS_CENTRE                ((draganobject_flags) 0x4u)
#define draganobject_VPOS_TOP                   ((draganobject_flags) 0x8u)
#define draganobject_NO_BOUND                   ((draganobject_flags) 0x0u)
#define draganobject_BOUND_TO_WINDOW            ((draganobject_flags) 0x10u)
#define draganobject_GIVEN_BBOX                 ((draganobject_flags) 0x20u)
#define draganobject_BOUND_OBJECT               ((draganobject_flags) 0x0u)
#define draganobject_BOUND_POINTER              ((draganobject_flags) 0x40u)
#define draganobject_DROP_SHADOW                ((draganobject_flags) 0x80u)
#define draganobject_NO_DITHER                  ((draganobject_flags) 0x100u)
#define draganobject_CENTER_ON_PTR_POS          ((draganobject_flags) 0x200u)
      /*Object is centred on pointer position - RISC OS 4*/
#define draganobject_SWI_FUNCTION               ((draganobject_flags) 0x0u)
#define draganobject_CALL_FUNCTION              ((draganobject_flags) 0x10000u)
#define draganobject_FUNCTION_USER              ((draganobject_flags) 0x0u)
#define draganobject_FUNCTION_SVC               ((draganobject_flags) 0x20000u)
#define draganobject_FUNCTION_USE_USER          ((draganobject_flags) 0x40000u)
      /*Really use user mode - RISC OS 5*/

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      draganobject_start()
 *
 * Description:   Takes a copy of an object and starts a Wimp drag
 *
 * Input:         flags - value of R0 on entry
 *                function - value of R1 on entry
 *                register_block - value of R2 on entry
 *                box - value of R3 on entry
 *                bbox - value of R4 on entry
 *
 * Other notes:   Calls SWI 0x49C40.
 */

extern os_error *xdraganobject_start (draganobject_flags flags,
      asm_routine function,
      os_register_block const *register_block,
      os_box const *box,
      os_box const *bbox);
extern void draganobject_start (draganobject_flags flags,
      asm_routine function,
      os_register_block const *register_block,
      os_box const *box,
      os_box const *bbox);

/* ------------------------------------------------------------------------
 * Function:      draganobject_stop()
 *
 * Description:   Terminates any current drag operation, and releases
 *                workspace
 *
 * Other notes:   Calls SWI 0x49C41.
 */

extern os_error *xdraganobject_stop (void);
__swi (0x49C41) void draganobject_stop (void);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
