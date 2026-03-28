#ifndef actionbutton_H
#define actionbutton_H

/* C header file for ActionButton
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

#if defined NAMESPACE_OSLIB
  namespace OSLib {
#endif

/**********************************
 * SWI names and SWI reason codes *
 **********************************/
#undef  ActionButton_SetText
#define ActionButton_SetText                    0x80
#undef  ActionButton_GetText
#define ActionButton_GetText                    0x81
#undef  ActionButton_SetAction
#define ActionButton_SetAction                  0x82
#undef  ActionButton_GetAction
#define ActionButton_GetAction                  0x83
#undef  ActionButton_SetClickShow
#define ActionButton_SetClickShow               0x84
#undef  ActionButton_GetClickShow
#define ActionButton_GetClickShow               0x85

/************************************
 * Structure and union declarations *
 ************************************/
typedef struct actionbutton_gadget              actionbutton_gadget;
typedef struct actionbutton_object              actionbutton_object;

/********************
 * Type definitions *
 ********************/
struct actionbutton_gadget
   {  toolbox_msg_reference text;
      int text_limit;
      toolbox_string_reference click_show;
      bits action;
   };

struct actionbutton_object
   {  gadget_OBJECT_MEMBERS
      toolbox_msg_reference text;
      int text_limit;
      toolbox_string_reference click_show;
      bits action;
   };

typedef toolbox_action_header_base actionbutton_action_selected_block;

/************************
 * Constant definitions *
 ************************/
#define class_ACTION_BUTTON                     ((toolbox_class) 0x80u)
#define actionbutton_IS_DEFAULT                 ((gadget_flags) 0x1u)
#define actionbutton_IS_CANCEL                  ((gadget_flags) 0x2u)
#define actionbutton_IS_LOCAL                   ((gadget_flags) 0x4u)
#define actionbutton_IS_MENU                    ((gadget_flags) 0x8u)
#define actionbutton_SHOW_AS_MENU               ((gadget_flags) 0x8u)
#define actionbutton_SHOW_AT_CENTRE             ((gadget_flags) 0x10u)
#define actionbutton_SHOW_AT_POINTER            ((gadget_flags) 0x20u)
#define action_ACTION_BUTTON_SELECTED           0x82881u
#define actionbutton_SELECTED_ADJUST            0x1u
#define actionbutton_SELECTED_SELECT            0x4u
#define actionbutton_SELECTED_DEFAULT           0x8u
#define actionbutton_SELECTED_CANCEL            0x10u
#define actionbutton_SELECTED_LOCAL             0x20u

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      actionbutton_set_text()
 *
 * Description:   Sets the text that will be displayed in the specified
 *                action button
 *
 * Input:         flags - value of R0 on entry
 *                window - value of R1 on entry
 *                action_button - value of R3 on entry
 *                text - value of R4 on entry
 *
 * Other notes:   Calls SWI 0x44EC6 with R2 = 0x80.
 */

extern os_error *xactionbutton_set_text (bits flags,
      toolbox_o window,
      toolbox_c action_button,
      char const *text);
extern void actionbutton_set_text (bits flags,
      toolbox_o window,
      toolbox_c action_button,
      char const *text);

/* ------------------------------------------------------------------------
 * Function:      actionbutton_get_text()
 *
 * Description:   Calls reason code 129 of SWI 0x44EC6
 *
 * Input:         flags - value of R0 on entry
 *                window - value of R1 on entry
 *                action_button - value of R3 on entry
 *                text - value of R4 on entry
 *                size - value of R5 on entry
 *
 * Output:        used - value of R5 on exit (X version only)
 *
 * Returns:       R5 (non-X version only)
 *
 * Other notes:   Before entry, R2 = 0x81.
 */

extern os_error *xactionbutton_get_text (bits flags,
      toolbox_o window,
      toolbox_c action_button,
      char *text,
      int size,
      int *used);
extern int actionbutton_get_text (bits flags,
      toolbox_o window,
      toolbox_c action_button,
      char *text,
      int size);

/* ------------------------------------------------------------------------
 * Function:      actionbutton_set_action()
 *
 * Description:   Sets the action that is raised when the button is clicked
 *
 * Input:         flags - value of R0 on entry
 *                window - value of R1 on entry
 *                action_button - value of R3 on entry
 *                action - value of R4 on entry
 *
 * Other notes:   Calls SWI 0x44EC6 with R2 = 0x82.
 */

extern os_error *xactionbutton_set_action (bits flags,
      toolbox_o window,
      toolbox_c action_button,
      bits action);
extern void actionbutton_set_action (bits flags,
      toolbox_o window,
      toolbox_c action_button,
      bits action);

/* ------------------------------------------------------------------------
 * Function:      actionbutton_get_action()
 *
 * Description:   Gets the action that is raised when the button is clicked
 *
 * Input:         flags - value of R0 on entry
 *                window - value of R1 on entry
 *                action_button - value of R3 on entry
 *
 * Output:        action - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x44EC6 with R2 = 0x83.
 */

extern os_error *xactionbutton_get_action (bits flags,
      toolbox_o window,
      toolbox_c action_button,
      bits *action);
extern bits actionbutton_get_action (bits flags,
      toolbox_o window,
      toolbox_c action_button);

/* ------------------------------------------------------------------------
 * Function:      actionbutton_set_click_show()
 *
 * Description:   Calls reason code 132 of SWI 0x44EC6
 *
 * Input:         flags - value of R0 on entry
 *                window - value of R1 on entry
 *                action_button - value of R3 on entry
 *                obj - value of R4 on entry
 *                show_flags - value of R5 on entry
 *
 * Other notes:   Before entry, R2 = 0x84.
 */

extern os_error *xactionbutton_set_click_show (bits flags,
      toolbox_o window,
      toolbox_c action_button,
      toolbox_o obj,
      bits show_flags);
extern void actionbutton_set_click_show (bits flags,
      toolbox_o window,
      toolbox_c action_button,
      toolbox_o obj,
      bits show_flags);

/* ------------------------------------------------------------------------
 * Function:      actionbutton_get_click_show()
 *
 * Description:   Calls reason code 133 of SWI 0x44EC6
 *
 * Input:         flags - value of R0 on entry
 *                window - value of R1 on entry
 *                action_button - value of R3 on entry
 *
 * Output:        obj - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Before entry, R2 = 0x85.
 */

extern os_error *xactionbutton_get_click_show (bits flags,
      toolbox_o window,
      toolbox_c action_button,
      toolbox_o *obj);
extern toolbox_o actionbutton_get_click_show (bits flags,
      toolbox_o window,
      toolbox_c action_button);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
