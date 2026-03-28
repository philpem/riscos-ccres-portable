#ifndef wimpreadsysinfo_H
#define wimpreadsysinfo_H

/* C header file for WimpReadSysInfo
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:48:24 2012
 * Jonathan Coxhead, jonathan@doves.demon.co.uk, 23 May 1995
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

#ifndef font_H
#include "oslib/font.h"
#endif

#ifndef osspriteop_H
#include "oslib/osspriteop.h"
#endif

#if defined NAMESPACE_OSLIB
  namespace OSLib {
#endif

/**********************************
 * SWI names and SWI reason codes *
 **********************************/
#undef  Wimp_ReadSysInfo
#define Wimp_ReadSysInfo                        0x400F2
#undef  XWimp_ReadSysInfo
#define XWimp_ReadSysInfo                       0x600F2
#undef  WimpReadSysInfo_TaskCount
#define WimpReadSysInfo_TaskCount               0x0
#undef  WimpReadSysInfo_WimpMode
#define WimpReadSysInfo_WimpMode                0x1
#undef  WimpReadSysInfo_SpriteSuffix
#define WimpReadSysInfo_SpriteSuffix            0x2
#undef  WimpReadSysInfo_DesktopState
#define WimpReadSysInfo_DesktopState            0x3
#undef  WimpReadSysInfo_WriteDir
#define WimpReadSysInfo_WriteDir                0x4
#undef  WimpReadSysInfo_Task
#define WimpReadSysInfo_Task                    0x5
#undef  WimpReadSysInfo_Version
#define WimpReadSysInfo_Version                 0x7
#undef  WimpReadSysInfo_Font
#define WimpReadSysInfo_Font                    0x8
#undef  WimpReadSysInfo_ToolSprites
#define WimpReadSysInfo_ToolSprites             0x9
#undef  WimpReadSysInfo_ApplicationLimit
#define WimpReadSysInfo_ApplicationLimit        0xB
#undef  WimpReadSysInfo_SpritePools
#define WimpReadSysInfo_SpritePools             0x10
#undef  WimpReadSysInfo_AutoScrollPauseDelay
#define WimpReadSysInfo_AutoScrollPauseDelay    0x11
#undef  WimpReadSysInfo_SpritePoolsExtended
#define WimpReadSysInfo_SpritePoolsExtended     0x13
#undef  WimpReadSysInfo_SpecialHighlightingColours
#define WimpReadSysInfo_SpecialHighlightingColours 0x14
#undef  WimpReadSysInfo_TextSelection
#define WimpReadSysInfo_TextSelection           0x15
#undef  WimpReadSysInfo_CaretColour
#define WimpReadSysInfo_CaretColour             0x16
#undef  WimpReadSysInfo_DragSettings
#define WimpReadSysInfo_DragSettings            0x17
#undef  WimpReadSysInfo_DblClickSettings
#define WimpReadSysInfo_DblClickSettings        0x18
#undef  WimpReadSysInfo_SubMenuOpenSettings
#define WimpReadSysInfo_SubMenuOpenSettings     0x19
#undef  WimpReadSysInfo_IconBarScrollSettings
#define WimpReadSysInfo_IconBarScrollSettings   0x1A
#undef  WimpReadSysInfo_EdgeSettings
#define WimpReadSysInfo_EdgeSettings            0x1B

/********************
 * Type definitions *
 ********************/
typedef int wimpreadsysinfo_state;

typedef int wimpreadsysinfo_direction;

typedef bits wimpreadsysinfotextselection_flags;

/************************
 * Constant definitions *
 ************************/
#define wimpreadsysinfo_STATE_COMMANDS          ((wimpreadsysinfo_state) 0x0u)
#define wimpreadsysinfo_STATE_DESKTOP           ((wimpreadsysinfo_state) 0x1u)
#define wimpreadsysinfo_DIR_LEFT_TO_RIGHT       ((wimpreadsysinfo_direction) 0x0u)
#define wimpreadsysinfo_DIR_RIGHT_TO_LEFT       ((wimpreadsysinfo_direction) 0x1u)
#define wimpreadsysinfotextselectionflags_ENABLED ((wimpreadsysinfotextselection_flags) 0x1u)
#define wimpreadsysinfotextselectionflags_INSERT_OP_MASK ((wimpreadsysinfotextselection_flags) 0x6u)
#define wimpreadsysinfotextselectionflags_INSERT_OP_NOP ((wimpreadsysinfotextselection_flags) 0x0u)
#define wimpreadsysinfotextselectionflags_INSERT_OP_DEL ((wimpreadsysinfotextselection_flags) 0x2u)
#define wimpreadsysinfotextselectionflags_INSERT_OP_CLEAR ((wimpreadsysinfotextselection_flags) 0x4u)
#define wimpreadsysinfotextselectionflags_INSERT_OP_CUT ((wimpreadsysinfotextselection_flags) 0x6u)
#define wimpreadsysinfotextselectionflags_DEL_OP_MASK ((wimpreadsysinfotextselection_flags) 0x18u)
#define wimpreadsysinfotextselectionflags_DEL_OP_NOP ((wimpreadsysinfotextselection_flags) 0x0u)
#define wimpreadsysinfotextselectionflags_DEL_OP_DEL ((wimpreadsysinfotextselection_flags) 0x8u)
#define wimpreadsysinfotextselectionflags_DEL_OP_CLEAR ((wimpreadsysinfotextselection_flags) 0x10u)
#define wimpreadsysinfotextselectionflags_DEL_OP_CUT ((wimpreadsysinfotextselection_flags) 0x18u)
#define wimpreadsysinfotextselectionflags_MOVE_OP_MASK ((wimpreadsysinfotextselection_flags) 0x60u)
#define wimpreadsysinfotextselectionflags_MOVE_OP_NOP ((wimpreadsysinfotextselection_flags) 0x0u)
#define wimpreadsysinfotextselectionflags_MOVE_OP_DEL ((wimpreadsysinfotextselection_flags) 0x20u)
#define wimpreadsysinfotextselectionflags_MOVE_OP_CLEAR ((wimpreadsysinfotextselection_flags) 0x40u)
#define wimpreadsysinfotextselectionflags_MOVE_OP_CUT ((wimpreadsysinfotextselection_flags) 0x60u)
#define wimpreadsysinfotextselectionflags_AUTO_SELECT ((wimpreadsysinfotextselection_flags) 0x80u)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      wimpreadsysinfo_task_count()
 *
 * Description:   Reads the number of active tasks
 *
 * Output:        task_count - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x400F2 with R0 = 0x0.
 */

extern os_error *xwimpreadsysinfo_task_count (int *task_count);
extern int wimpreadsysinfo_task_count (void);

/* ------------------------------------------------------------------------
 * Function:      wimpreadsysinfo_wimp_mode()
 *
 * Description:   Reads the current Wimp mode
 *
 * Output:        mode - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x400F2 with R0 = 0x1.
 */

extern os_error *xwimpreadsysinfo_wimp_mode (os_mode *mode);
extern os_mode wimpreadsysinfo_wimp_mode (void);

/* ------------------------------------------------------------------------
 * Function:      wimpreadsysinfo_sprite_suffix()
 *
 * Description:   Reads the *IconSprites file name suffix for the
 *                configured mode
 *
 * Output:        suffix - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x400F2 with R0 = 0x2.
 */

extern os_error *xwimpreadsysinfo_sprite_suffix (char **suffix);
extern char *wimpreadsysinfo_sprite_suffix (void);

/* ------------------------------------------------------------------------
 * Function:      wimpreadsysinfo_desktop_state()
 *
 * Description:   Reads the Wimp state
 *
 * Output:        state - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x400F2 with R0 = 0x3.
 */

extern os_error *xwimpreadsysinfo_desktop_state (wimpreadsysinfo_state *state);
extern wimpreadsysinfo_state wimpreadsysinfo_desktop_state (void);

/* ------------------------------------------------------------------------
 * Function:      wimpreadsysinfo_write_dir()
 *
 * Description:   Reads the current writing direction
 *
 * Output:        write_dir - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x400F2 with R0 = 0x4.
 */

extern os_error *xwimpreadsysinfo_write_dir (wimpreadsysinfo_direction *write_dir);
extern wimpreadsysinfo_direction wimpreadsysinfo_write_dir (void);

/* ------------------------------------------------------------------------
 * Function:      wimpreadsysinfo_task()
 *
 * Description:   Reads the current task handle
 *
 * Output:        task - value of R0 on exit (X version only)
 *                version - value of R1 on exit
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x400F2 with R0 = 0x5.
 */

extern os_error *xwimpreadsysinfo_task (wimp_t *task,
      wimp_version_no *version);
extern wimp_t wimpreadsysinfo_task (wimp_version_no *version);

/* ------------------------------------------------------------------------
 * Function:      wimpreadsysinfo_version()
 *
 * Description:   Reads the Wimp version
 *
 * Output:        version - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x400F2 with R0 = 0x7.
 */

extern os_error *xwimpreadsysinfo_version (wimp_version_no *version);
extern wimp_version_no wimpreadsysinfo_version (void);

/* ------------------------------------------------------------------------
 * Function:      wimpreadsysinfo_font()
 *
 * Description:   Reads the desktop and symbol font handles
 *
 * Output:        font - value of R0 on exit (X version only)
 *                symbol_font - value of R1 on exit
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x400F2 with R0 = 0x8.
 */

extern os_error *xwimpreadsysinfo_font (font_f *font,
      font_f *symbol_font);
extern font_f wimpreadsysinfo_font (font_f *symbol_font);

/* ------------------------------------------------------------------------
 * Function:      wimpreadsysinfo_tool_sprites()
 *
 * Description:   Reads the toolsprite control block pointer
 *
 * Output:        toolsprites - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x400F2 with R0 = 0x9.
 */

extern os_error *xwimpreadsysinfo_tool_sprites (osspriteop_area **toolsprites);
extern osspriteop_area *wimpreadsysinfo_tool_sprites (void);

/* ------------------------------------------------------------------------
 * Function:      wimpreadsysinfo_application_limit()
 *
 * Description:   Reads the maximum size of application space
 *
 * Output:        size_limit - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x400F2 with R0 = 0xB.
 */

extern os_error *xwimpreadsysinfo_application_limit (int *size_limit);
extern int wimpreadsysinfo_application_limit (void);

/* ------------------------------------------------------------------------
 * Function:      wimpreadsysinfo_sprite_pools()
 *
 * Description:   Reads both the WIMP sprite pools' control block pointers,
 *                see WimpReadSysInfo_SpritePoolsExtended as well - RISC OS
 *                4+
 *
 * Output:        low_priority - value of R0 on exit
 *                high_priority - value of R1 on exit
 *
 * Other notes:   Calls SWI 0x400F2 with R0 = 0x10.
 */

extern os_error *xwimpreadsysinfo_sprite_pools (osspriteop_area **low_priority,
      osspriteop_area **high_priority);
extern void wimpreadsysinfo_sprite_pools (osspriteop_area **low_priority,
      osspriteop_area **high_priority);

/* ------------------------------------------------------------------------
 * Function:      wimpreadsysinfo_auto_scroll_pause_delay()
 *
 * Description:   Reads the configured auto-scroll pause delay, measured in
 *                centiseconds - RISC OS 4+
 *
 * Output:        delay - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x400F2 with R0 = 0x11.
 */

extern os_error *xwimpreadsysinfo_auto_scroll_pause_delay (int *delay);
extern int wimpreadsysinfo_auto_scroll_pause_delay (void);

/* ------------------------------------------------------------------------
 * Function:      wimpreadsysinfo_sprite_pools_extended()
 *
 * Description:   Reads the WIMP sprite pools' control block pointers -
 *                RISC OS Select
 *
 * Output:        priority - value of R0 on exit
 *                high_priority - value of R1 on exit
 *                low_priority - value of R2 on exit
 *
 * Other notes:   Calls SWI 0x400F2 with R0 = 0x13.
 */

extern os_error *xwimpreadsysinfo_sprite_pools_extended (osspriteop_area **priority,
      osspriteop_area **high_priority,
      osspriteop_area **low_priority);
extern void wimpreadsysinfo_sprite_pools_extended (osspriteop_area **priority,
      osspriteop_area **high_priority,
      osspriteop_area **low_priority);

/* ------------------------------------------------------------------------
 * Function:      wimpreadsysinfo_special_highlighting_colours()
 *
 * Description:   Reads the 'special' highlighting colours defined with
 *                *WimpVisualFlags - RISC OS Select
 *
 * Output:        bg - value of R0 on exit
 *                fg - value of R1 on exit
 *
 * Other notes:   Calls SWI 0x400F2 with R0 = 0x14.
 */

extern os_error *xwimpreadsysinfo_special_highlighting_colours (wimp_colour *bg,
      wimp_colour *fg);
extern void wimpreadsysinfo_special_highlighting_colours (wimp_colour *bg,
      wimp_colour *fg);

/* ------------------------------------------------------------------------
 * Function:      wimpreadsysinfo_text_selection()
 *
 * Description:   Reads the text selection colours and flags - RISC OS
 *                4.36+
 *
 * Output:        bg - value of R0 on exit
 *                fg - value of R1 on exit
 *                flags - value of R2 on exit
 *
 * Other notes:   Calls SWI 0x400F2 with R0 = 0x15, R2 = 0x1.
 */

extern os_error *xwimpreadsysinfo_text_selection (wimp_colour *bg,
      wimp_colour *fg,
      wimpreadsysinfotextselection_flags *flags);
extern void wimpreadsysinfo_text_selection (wimp_colour *bg,
      wimp_colour *fg,
      wimpreadsysinfotextselection_flags *flags);

/* ------------------------------------------------------------------------
 * Function:      wimpreadsysinfo_caret_colour()
 *
 * Description:   Read the default caret colour - RISC OS 6
 *
 * Output:        def - value of R0 on exit
 *                actual - value of R1 on exit
 *
 * Other notes:   Calls SWI 0x400F2 with R0 = 0x16.
 */

extern os_error *xwimpreadsysinfo_caret_colour (wimp_colour *def,
      wimp_colour *actual);
extern void wimpreadsysinfo_caret_colour (wimp_colour *def,
      wimp_colour *actual);

/* ------------------------------------------------------------------------
 * Function:      wimpreadsysinfo_drag_settings()
 *
 * Description:   Read the settings used to detect a drag - RISC OS 6
 *
 * Output:        os_units_move - value of R0 on exit
 *                delay - value of R1 on exit
 *
 * Other notes:   Calls SWI 0x400F2 with R0 = 0x17.
 */

extern os_error *xwimpreadsysinfo_drag_settings (int *os_units_move,
      int *delay);
extern void wimpreadsysinfo_drag_settings (int *os_units_move,
      int *delay);

/* ------------------------------------------------------------------------
 * Function:      wimpreadsysinfo_dbl_click_settings()
 *
 * Description:   Read the settings used to detect a double click - RISC OS
 *                6
 *
 * Output:        os_units_move - value of R0 on exit
 *                delay - value of R1 on exit
 *
 * Other notes:   Calls SWI 0x400F2 with R0 = 0x18.
 */

extern os_error *xwimpreadsysinfo_dbl_click_settings (int *os_units_move,
      int *delay);
extern void wimpreadsysinfo_dbl_click_settings (int *os_units_move,
      int *delay);

/* ------------------------------------------------------------------------
 * Function:      wimpreadsysinfo_sub_menu_open_settings()
 *
 * Description:   Read the settings used to detect whether a submenu entry
 *                should be opened automatically - RISC OS 6
 *
 * Output:        delay_for_open - value of R0 on exit
 *                delay_mouse_ignore - value of R1 on exit
 *
 * Other notes:   Calls SWI 0x400F2 with R0 = 0x19.
 */

extern os_error *xwimpreadsysinfo_sub_menu_open_settings (int *delay_for_open,
      int *delay_mouse_ignore);
extern void wimpreadsysinfo_sub_menu_open_settings (int *delay_for_open,
      int *delay_mouse_ignore);

/* ------------------------------------------------------------------------
 * Function:      wimpreadsysinfo_icon_bar_scroll_settings()
 *
 * Description:   Read the settings used to scroll the iconbar when the
 *                mouse is at its edge - RISC OS 6
 *
 * Output:        speed - value of R0 on exit
 *                acceleration - value of R1 on exit
 *
 * Other notes:   Calls SWI 0x400F2 with R0 = 0x1A.
 */

extern os_error *xwimpreadsysinfo_icon_bar_scroll_settings (int *speed,
      int *acceleration);
extern void wimpreadsysinfo_icon_bar_scroll_settings (int *speed,
      int *acceleration);

/* ------------------------------------------------------------------------
 * Function:      wimpreadsysinfo_edge_settings()
 *
 * Description:   Read the settings used to notify applications that the
 *                mouse has idled at the edge of the screen - RISC OS 6
 *
 * Output:        delay - value of R0 on exit
 *
 * Other notes:   Calls SWI 0x400F2 with R0 = 0x1B.
 */

extern os_error *xwimpreadsysinfo_edge_settings (int *delay);
extern void wimpreadsysinfo_edge_settings (int *delay);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
