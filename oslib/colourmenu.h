#ifndef colourmenu_H
#define colourmenu_H

/* C header file for ColourMenu
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

#ifndef os_H
#include "oslib/os.h"
#endif

#ifndef toolbox_H
#include "oslib/toolbox.h"
#endif

#ifndef menu_H
#include "oslib/menu.h"
#endif

#if defined NAMESPACE_OSLIB
  namespace OSLib {
#endif

/**********************************
 * SWI names and SWI reason codes *
 **********************************/
#undef  ColourMenu_ClassSWI
#define ColourMenu_ClassSWI                     0x82980
#undef  XColourMenu_ClassSWI
#define XColourMenu_ClassSWI                    0xA2980
#undef  ColourMenu_PostFilter
#define ColourMenu_PostFilter                   0x82981
#undef  XColourMenu_PostFilter
#define XColourMenu_PostFilter                  0xA2981
#undef  ColourMenu_PreFilter
#define ColourMenu_PreFilter                    0x82982
#undef  XColourMenu_PreFilter
#define XColourMenu_PreFilter                   0xA2982
#undef  ColourMenu_SetColour
#define ColourMenu_SetColour                    0x0
#undef  ColourMenu_GetColour
#define ColourMenu_GetColour                    0x1
#undef  ColourMenu_SetNoneAvailable
#define ColourMenu_SetNoneAvailable             0x2
#undef  ColourMenu_GetNoneAvailable
#define ColourMenu_GetNoneAvailable             0x3
#undef  ColourMenu_SetTitle
#define ColourMenu_SetTitle                     0x4
#undef  ColourMenu_GetTitle
#define ColourMenu_GetTitle                     0x5

/************************************
 * Structure and union declarations *
 ************************************/
typedef struct colourmenu_object                colourmenu_object;
typedef struct colourmenu_object_template       colourmenu_object_template;
typedef struct colourmenu_action_about_to_be_shown colourmenu_action_about_to_be_shown;
typedef struct colourmenu_action_about_to_be_shown_block colourmenu_action_about_to_be_shown_block;
typedef struct colourmenu_action_selection      colourmenu_action_selection;
typedef struct colourmenu_action_selection_block colourmenu_action_selection_block;

/********************
 * Type definitions *
 ********************/
typedef bits colourmenu_flags;

typedef int colourmenu_colour;
      /*A Wimp colour number, or a special value*/

/* ------------------------------------------------------------------------
 * Type:          colourmenu_object
 *
 * Description:   Structure to describe Object for in-memory construction - to be referenced from Toolbox_Template
 */

struct colourmenu_object
   {  colourmenu_flags flags;
      toolbox_msg_reference title;
      int title_limit;
      colourmenu_colour colour;
   };

struct colourmenu_object_template
   {  toolbox_RESOURCE_FILE_OBJECT_MEMBERS
      colourmenu_flags objectflags;
      toolbox_msg_reference title;
      int title_limit;
      colourmenu_colour colour;
   };

typedef os_coord colourmenu_full;

/* ------------------------------------------------------------------------
 * Type:          colourmenu_action_about_to_be_shown
 *
 * Description:   Prefer ColourMenu_ActionAboutToBeShownBlock
 */

struct colourmenu_action_about_to_be_shown
   {  toolbox_position_tag tag;
      union
      {  os_coord top_left;
         colourmenu_full full;
      }
      position;
   };

struct colourmenu_action_about_to_be_shown_block
   {  toolbox_ACTION_HEADER_MEMBERS
      toolbox_position_tag tag;
      union
      {  os_coord top_left;
         colourmenu_full full;
      }
      position;
   };

typedef toolbox_action_header_base colourmenu_action_has_been_hidden_block;
      /*Prefer ColourMenu_ActionDialogueCompletedBlock*/

typedef toolbox_action_header_base colourmenu_action_dialogue_completed_block;

struct colourmenu_action_selection
   {  colourmenu_colour colour;
   };

struct colourmenu_action_selection_block
   {  toolbox_ACTION_HEADER_MEMBERS
      colourmenu_colour colour;
   };

/************************
 * Constant definitions *
 ************************/
#define class_COLOUR_MENU                       ((toolbox_class) 0x82980u)
#define colourmenu_GENERATE_ABOUT_TO_BE_SHOWN   ((colourmenu_flags) 0x1u)
#define colourmenu_GENERATE_DIALOGUE_COMPLETED  ((colourmenu_flags) 0x2u)
#define colourmenu_GENERATE_HAS_BEEN_HIDDEN     ((colourmenu_flags) 0x2u)
#define colourmenu_NONE_ENTRY                   ((colourmenu_flags) 0x4u)
#define colourmenu_TRANSPARENT                  ((colourmenu_colour) 0x10u)
#define colourmenu_NONE                         ((colourmenu_colour) 0xFFFFFFFFu)
#define action_COLOUR_MENU_ABOUT_TO_BE_SHOWN    0x82980u
#define action_COLOUR_MENU_DIALOGUE_COMPLETED   0x82981u
#define action_COLOUR_MENU_HAS_BEEN_HIDDEN      0x82981u
#define action_COLOUR_MENU_SELECTION            0x82982u
#define error_COLOUR_MENU_TASKS_ACTIVE          0x80B000u
#define error_COLOUR_MENU_ALLOC_FAILED          0x80B001u
#define error_COLOUR_MENU_SHORT_BUFFER          0x80B002u
#define error_COLOUR_MENU_NO_SUCH_TASK          0x80B011u
#define error_COLOUR_MENU_NO_SUCH_METHOD        0x80B012u
#define error_COLOUR_MENU_NO_SUCH_MISC_OP_METHOD 0x80B013u

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      colourmenu_set_colour()
 *
 * Description:   Calls reason code 0 of SWI 0x44EC6
 *
 * Input:         flags - value of R0 on entry
 *                colour_menu - value of R1 on entry
 *                colour - value of R3 on entry
 *
 * Other notes:   Before entry, R2 = 0x0.
 */

extern os_error *xcolourmenu_set_colour (bits flags,
      toolbox_o colour_menu,
      colourmenu_colour colour);
extern void colourmenu_set_colour (bits flags,
      toolbox_o colour_menu,
      colourmenu_colour colour);

/* ------------------------------------------------------------------------
 * Function:      colourmenu_get_colour()
 *
 * Description:   Calls reason code 1 of SWI 0x44EC6
 *
 * Input:         flags - value of R0 on entry
 *                colour_menu - value of R1 on entry
 *
 * Output:        colour - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Before entry, R2 = 0x1.
 */

extern os_error *xcolourmenu_get_colour (bits flags,
      toolbox_o colour_menu,
      colourmenu_colour *colour);
extern colourmenu_colour colourmenu_get_colour (bits flags,
      toolbox_o colour_menu);

/* ------------------------------------------------------------------------
 * Function:      colourmenu_set_none_available()
 *
 * Description:   Calls reason code 2 of SWI 0x44EC6
 *
 * Input:         flags - value of R0 on entry
 *                colour_menu - value of R1 on entry
 *                none_available - value of R3 on entry
 *
 * Other notes:   Before entry, R2 = 0x2.
 */

extern os_error *xcolourmenu_set_none_available (bits flags,
      toolbox_o colour_menu,
      osbool none_available);
extern void colourmenu_set_none_available (bits flags,
      toolbox_o colour_menu,
      osbool none_available);

/* ------------------------------------------------------------------------
 * Function:      colourmenu_get_none_available()
 *
 * Description:   Calls reason code 3 of SWI 0x44EC6
 *
 * Input:         flags - value of R0 on entry
 *                colour_menu - value of R1 on entry
 *
 * Output:        none_available - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Before entry, R2 = 0x3.
 */

extern os_error *xcolourmenu_get_none_available (bits flags,
      toolbox_o colour_menu,
      osbool *none_available);
extern osbool colourmenu_get_none_available (bits flags,
      toolbox_o colour_menu);

/* ------------------------------------------------------------------------
 * Function:      colourmenu_set_title()
 *
 * Description:   Calls reason code 4 of SWI 0x44EC6
 *
 * Input:         flags - value of R0 on entry
 *                colour_menu - value of R1 on entry
 *                title - value of R3 on entry
 *
 * Other notes:   Before entry, R2 = 0x4.
 */

extern os_error *xcolourmenu_set_title (bits flags,
      toolbox_o colour_menu,
      char const *title);
extern void colourmenu_set_title (bits flags,
      toolbox_o colour_menu,
      char const *title);

/* ------------------------------------------------------------------------
 * Function:      colourmenu_get_title()
 *
 * Description:   Calls reason code 5 of SWI 0x44EC6
 *
 * Input:         flags - value of R0 on entry
 *                colour_menu - value of R1 on entry
 *                buffer - value of R3 on entry
 *                size - value of R4 on entry
 *
 * Output:        used - value of R4 on exit (X version only)
 *
 * Returns:       R4 (non-X version only)
 *
 * Other notes:   Before entry, R2 = 0x5.
 */

extern os_error *xcolourmenu_get_title (bits flags,
      toolbox_o colour_menu,
      char *buffer,
      int size,
      int *used);
extern int colourmenu_get_title (bits flags,
      toolbox_o colour_menu,
      char *buffer,
      int size);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
