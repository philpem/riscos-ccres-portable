#ifndef displayfield_H
#define displayfield_H

/* C header file for DisplayField
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:48:09 2012
 * Jonathan Coxhead, jonathan@doves.demon.co.uk, 5 Sept 1995
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

#ifndef toolbox_H
#include "oslib/toolbox.h"
#endif

#ifndef gadget_H
#include "oslib/gadget.h"
#endif

#ifndef font_H
#include "oslib/font.h"
#endif

#if defined NAMESPACE_OSLIB
  namespace OSLib {
#endif

/**********************************
 * SWI names and SWI reason codes *
 **********************************/
#undef  DisplayField_SetValue
#define DisplayField_SetValue                   0x1C0
#undef  DisplayField_GetValue
#define DisplayField_GetValue                   0x1C1
#undef  DisplayField_SetFont
#define DisplayField_SetFont                    0x1C2

/************************************
 * Structure and union declarations *
 ************************************/
typedef struct displayfield_gadget              displayfield_gadget;
typedef struct displayfield_object              displayfield_object;

/********************
 * Type definitions *
 ********************/
struct displayfield_gadget
   {  toolbox_msg_reference text;
      int text_limit;
   };

struct displayfield_object
   {  gadget_OBJECT_MEMBERS
      toolbox_msg_reference text;
      int text_limit;
   };

/************************
 * Constant definitions *
 ************************/
#define class_DISPLAY_FIELD                     ((toolbox_class) 0x1C0u)
#define displayfield_RJUSTIFIED                 ((gadget_flags) 0x2u)
#define displayfield_HCENTRED                   ((gadget_flags) 0x4u)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      displayfield_set_value()
 *
 * Description:   Calls reason code 448 of SWI 0x44EC6
 *
 * Input:         flags - value of R0 on entry
 *                window - value of R1 on entry
 *                display_field - value of R3 on entry
 *                text - value of R4 on entry
 *
 * Other notes:   Before entry, R2 = 0x1C0.
 */

extern os_error *xdisplayfield_set_value (bits flags,
      toolbox_o window,
      toolbox_c display_field,
      char const *text);
extern void displayfield_set_value (bits flags,
      toolbox_o window,
      toolbox_c display_field,
      char const *text);

/* ------------------------------------------------------------------------
 * Function:      displayfield_get_value()
 *
 * Description:   Calls reason code 449 of SWI 0x44EC6
 *
 * Input:         flags - value of R0 on entry
 *                window - value of R1 on entry
 *                display_field - value of R3 on entry
 *                buffer - value of R4 on entry
 *                size - value of R5 on entry
 *
 * Output:        used - value of R5 on exit (X version only)
 *
 * Returns:       R5 (non-X version only)
 *
 * Other notes:   Before entry, R2 = 0x1C1.
 */

extern os_error *xdisplayfield_get_value (bits flags,
      toolbox_o window,
      toolbox_c display_field,
      char *buffer,
      int size,
      int *used);
extern int displayfield_get_value (bits flags,
      toolbox_o window,
      toolbox_c display_field,
      char *buffer,
      int size);

/* ------------------------------------------------------------------------
 * Function:      displayfield_set_font()
 *
 * Description:   Calls reason code 450 of SWI 0x44EC6
 *
 * Input:         flags - value of R0 on entry
 *                window - value of R1 on entry
 *                display_field - value of R3 on entry
 *                font - value of R4 on entry
 *                width - value of R5 on entry
 *                height - value of R6 on entry
 *
 * Other notes:   Before entry, R2 = 0x1C2.
 */

extern os_error *xdisplayfield_set_font (bits flags,
      toolbox_o window,
      toolbox_c display_field,
      char const *font,
      int width,
      int height);
extern void displayfield_set_font (bits flags,
      toolbox_o window,
      toolbox_c display_field,
      char const *font,
      int width,
      int height);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
