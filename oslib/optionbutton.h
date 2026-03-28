#ifndef optionbutton_H
#define optionbutton_H

/* C header file for OptionButton
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
#undef  OptionButton_SetLabel
#define OptionButton_SetLabel                   0xC0
#undef  OptionButton_GetLabel
#define OptionButton_GetLabel                   0xC1
#undef  OptionButton_SetAction
#define OptionButton_SetAction                  0xC2
#undef  OptionButton_GetAction
#define OptionButton_GetAction                  0xC3
#undef  OptionButton_SetState
#define OptionButton_SetState                   0xC4
#undef  OptionButton_GetState
#define OptionButton_GetState                   0xC5

/************************************
 * Structure and union declarations *
 ************************************/
typedef struct optionbutton_gadget              optionbutton_gadget;
typedef struct optionbutton_object              optionbutton_object;
typedef struct optionbutton_action_state_changed optionbutton_action_state_changed;
typedef struct optionbutton_action_state_changed_block optionbutton_action_state_changed_block;

/********************
 * Type definitions *
 ********************/
struct optionbutton_gadget
   {  toolbox_msg_reference label;
      int label_limit;
      bits action;
   };

struct optionbutton_object
   {  gadget_OBJECT_MEMBERS
      toolbox_msg_reference label;
      int label_limit;
      bits action;
   };

/* ------------------------------------------------------------------------
 * Type:          optionbutton_action_state_changed
 *
 * Description:   Prefer OptionButton_ActionStateChangedBlock
 */

struct optionbutton_action_state_changed
   {  osbool on;
   };

struct optionbutton_action_state_changed_block
   {  toolbox_ACTION_HEADER_MEMBERS
      osbool on;
   };

/************************
 * Constant definitions *
 ************************/
#define class_OPTION_BUTTON                     ((toolbox_class) 0xC0u)
#define optionbutton_GENERATE_STATE_CHANGED     ((gadget_flags) 0x1u)
#define optionbutton_ON                         ((gadget_flags) 0x4u)
#define action_OPTION_BUTTON_STATE_CHANGED      0x82882u
#define optionbutton_STATE_CHANGED_ADJUST       0x1u
#define optionbutton_STATE_CHANGED_SELECT       0x4u

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      optionbutton_set_label()
 *
 * Description:   Sets the label of the specified option button
 *
 * Input:         flags - value of R0 on entry
 *                window - value of R1 on entry
 *                option_button - value of R3 on entry
 *                label - value of R4 on entry
 *
 * Other notes:   Calls SWI 0x44EC6 with R2 = 0xC0.
 */

extern os_error *xoptionbutton_set_label (bits flags,
      toolbox_o window,
      toolbox_c option_button,
      char const *label);
extern void optionbutton_set_label (bits flags,
      toolbox_o window,
      toolbox_c option_button,
      char const *label);

/* ------------------------------------------------------------------------
 * Function:      optionbutton_get_label()
 *
 * Description:   Gets the label of the specified option button
 *
 * Input:         flags - value of R0 on entry
 *                window - value of R1 on entry
 *                option_button - value of R3 on entry
 *                buffer - value of R4 on entry
 *                size - value of R5 on entry
 *
 * Output:        used - value of R5 on exit (X version only)
 *
 * Returns:       R5 (non-X version only)
 *
 * Other notes:   Calls SWI 0x44EC6 with R2 = 0xC1.
 */

extern os_error *xoptionbutton_get_label (bits flags,
      toolbox_o window,
      toolbox_c option_button,
      char *buffer,
      int size,
      int *used);
extern int optionbutton_get_label (bits flags,
      toolbox_o window,
      toolbox_c option_button,
      char *buffer,
      int size);

/* ------------------------------------------------------------------------
 * Function:      optionbutton_set_action()
 *
 * Description:   Calls reason code 194 of SWI 0x44EC6
 *
 * Input:         flags - value of R0 on entry
 *                window - value of R1 on entry
 *                option_button - value of R3 on entry
 *                action - value of R4 on entry
 *
 * Other notes:   Before entry, R2 = 0xC2.
 */

extern os_error *xoptionbutton_set_action (bits flags,
      toolbox_o window,
      toolbox_c option_button,
      bits action);
extern void optionbutton_set_action (bits flags,
      toolbox_o window,
      toolbox_c option_button,
      bits action);

/* ------------------------------------------------------------------------
 * Function:      optionbutton_get_action()
 *
 * Description:   Calls reason code 195 of SWI 0x44EC6
 *
 * Input:         flags - value of R0 on entry
 *                window - value of R1 on entry
 *                option_button - value of R3 on entry
 *
 * Output:        action - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Before entry, R2 = 0xC3.
 */

extern os_error *xoptionbutton_get_action (bits flags,
      toolbox_o window,
      toolbox_c option_button,
      bits *action);
extern bits optionbutton_get_action (bits flags,
      toolbox_o window,
      toolbox_c option_button);

/* ------------------------------------------------------------------------
 * Function:      optionbutton_set_state()
 *
 * Description:   Calls reason code 196 of SWI 0x44EC6
 *
 * Input:         flags - value of R0 on entry
 *                window - value of R1 on entry
 *                option_button - value of R3 on entry
 *                on - value of R4 on entry
 *
 * Other notes:   Before entry, R2 = 0xC4.
 */

extern os_error *xoptionbutton_set_state (bits flags,
      toolbox_o window,
      toolbox_c option_button,
      osbool on);
extern void optionbutton_set_state (bits flags,
      toolbox_o window,
      toolbox_c option_button,
      osbool on);

/* ------------------------------------------------------------------------
 * Function:      optionbutton_get_state()
 *
 * Description:   Calls reason code 197 of SWI 0x44EC6
 *
 * Input:         flags - value of R0 on entry
 *                window - value of R1 on entry
 *                option_button - value of R3 on entry
 *
 * Output:        on - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Before entry, R2 = 0xC5.
 */

extern os_error *xoptionbutton_get_state (bits flags,
      toolbox_o window,
      toolbox_c option_button,
      osbool *on);
extern osbool optionbutton_get_state (bits flags,
      toolbox_o window,
      toolbox_c option_button);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
