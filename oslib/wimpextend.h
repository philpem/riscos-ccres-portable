#ifndef wimpextend_H
#define wimpextend_H

/* C header file for WimpExtend
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:48:24 2012
 * Richard Sargeant, sargeant@arcade.demon.co.uk, 04-Mar-1999
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

#ifndef osspriteop_H
#include "oslib/osspriteop.h"
#endif

#ifndef wimp_H
#include "oslib/wimp.h"
#endif

#if defined NAMESPACE_OSLIB
  namespace OSLib {
#endif

/**********************************
 * SWI names and SWI reason codes *
 **********************************/
#undef  Wimp_Extend
#define Wimp_Extend                             0x400FB
#undef  XWimp_Extend
#define XWimp_Extend                            0x600FB
#undef  WimpExtend_GetParent
#define WimpExtend_GetParent                    0x6
#undef  WimpExtend_GetFrontChild
#define WimpExtend_GetFrontChild                0x7
#undef  WimpExtend_GetBackChild
#define WimpExtend_GetBackChild                 0x8
#undef  WimpExtend_GetSiblingUnder
#define WimpExtend_GetSiblingUnder              0x9
#undef  WimpExtend_GetSiblingOver
#define WimpExtend_GetSiblingOver               0xA
#undef  WimpExtend_GetFurnitureSizes
#define WimpExtend_GetFurnitureSizes            0xB
#undef  WimpExtend_GetSpriteAddress
#define WimpExtend_GetSpriteAddress             0x100
#undef  WimpExtend_GetModeSuffix
#define WimpExtend_GetModeSuffix                0x101
#undef  WimpExtend_GetSpriteColourMap
#define WimpExtend_GetSpriteColourMap           0x102

/************************************
 * Structure and union declarations *
 ************************************/
typedef struct wimpextend_furniture_sizes       wimpextend_furniture_sizes;

/********************
 * Type definitions *
 ********************/
struct wimpextend_furniture_sizes
   {  wimp_w w;
      os_box border_widths;
      int back_width;
      int close_width;
      int reserved1;
      int title_width;
      int reserved2;
      int iconise_width;
      int toggle_size_width;
      int toggle_size_height;
      int vertical_scroll_upper_gap;
      int up_arrow_height;
      int vertical_scroll_well_height;
      int down_arrow_height;
      int vertical_scroll_lower_gap;
      int adjust_size_height;
      int adjust_size_width;
      int horizontal_scroll_right_gap;
      int right_arrow_width;
      int horizontal_scroll_well_width;
      int left_arrow_width;
      int horizontal_scroll_left_gap;
   };

typedef bits wimpextendgetspritecolourmap_flags;

/************************
 * Constant definitions *
 ************************/
#define wimpextendgetspritecolourmapflags_SELECTED_ITEM ((wimpextendgetspritecolourmap_flags) 0x200000u)
#define wimpextendgetspritecolourmapflags_FADED_ITEM ((wimpextendgetspritecolourmap_flags) 0x400000u)
#define wimpextendgetspritecolourmapflags_PTR_OVER ((wimpextendgetspritecolourmap_flags) 0x800000u)
#define wimpextendgetspritecolourmapflags_FG_COLOUR_SHIFT (24)
#define wimpextendgetspritecolourmapflags_BG_COLOUR_SHIFT (28)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      wimpextend_get_parent()
 *
 * Description:   Finds the window's parent - nested Wimp / RISC OS 3.8+
 *
 * Input:         w - value of R1 on entry
 *
 * Output:        parent - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x400FB with R0 = 0x6.
 */

extern os_error *xwimpextend_get_parent (wimp_w w,
      wimp_w *parent);
extern wimp_w wimpextend_get_parent (wimp_w w);

/* ------------------------------------------------------------------------
 * Function:      wimpextend_get_front_child()
 *
 * Description:   Finds the window's frontmost child; this call may also be
 *                used to enquire about the top-level stack - nested Wimp /
 *                RISC OS 3.8+
 *
 * Input:         w - value of R1 on entry
 *
 * Output:        child - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x400FB with R0 = 0x7.
 */

extern os_error *xwimpextend_get_front_child (wimp_w w,
      wimp_w *child);
extern wimp_w wimpextend_get_front_child (wimp_w w);

/* ------------------------------------------------------------------------
 * Function:      wimpextend_get_back_child()
 *
 * Description:   Finds the window's backmost child; this call may also be
 *                used to enquire about the top-level stack - nested Wimp /
 *                RISC OS 3.8+
 *
 * Input:         w - value of R1 on entry
 *
 * Output:        child - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x400FB with R0 = 0x8.
 */

extern os_error *xwimpextend_get_back_child (wimp_w w,
      wimp_w *child);
extern wimp_w wimpextend_get_back_child (wimp_w w);

/* ------------------------------------------------------------------------
 * Function:      wimpextend_get_sibling_under()
 *
 * Description:   Finds the window's sibling that's immediately behind -
 *                nested Wimp / RISC OS 3.8+
 *
 * Input:         w - value of R1 on entry
 *
 * Output:        sibling - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x400FB with R0 = 0x9.
 */

extern os_error *xwimpextend_get_sibling_under (wimp_w w,
      wimp_w *sibling);
extern wimp_w wimpextend_get_sibling_under (wimp_w w);

/* ------------------------------------------------------------------------
 * Function:      wimpextend_get_sibling_over()
 *
 * Description:   Finds the window's sibling that's immediately in front -
 *                nested Wimp / RISC OS 3.8+
 *
 * Input:         w - value of R1 on entry
 *
 * Output:        sibling - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x400FB with R0 = 0xA.
 */

extern os_error *xwimpextend_get_sibling_over (wimp_w w,
      wimp_w *sibling);
extern wimp_w wimpextend_get_sibling_over (wimp_w w);

/* ------------------------------------------------------------------------
 * Function:      wimpextend_get_furniture_sizes()
 *
 * Description:   Finds the sizes of the window's various items of
 *                furniture - RISC OS 4+
 *
 * Input:         sizes - value of R1 on entry
 *
 * Other notes:   Calls SWI 0x400FB with R0 = 0xB.
 */

extern os_error *xwimpextend_get_furniture_sizes (wimpextend_furniture_sizes *sizes);
extern void wimpextend_get_furniture_sizes (wimpextend_furniture_sizes *sizes);

/* ------------------------------------------------------------------------
 * Function:      wimpextend_get_sprite_address()
 *
 * Description:   Lookup a sprite using the same algorithm as the Window
 *                Manager - RISC OS Select
 *
 * Input:         sprite_area - value of R1 on entry
 *                sprite_name - value of R2 on entry
 *
 * Output:        area - value of R1 on exit
 *                sprite - value of R2 on exit
 *
 * Other notes:   Calls SWI 0x400FB with R0 = 0x100.
 */

extern os_error *xwimpextend_get_sprite_address (osspriteop_area const *sprite_area,
      char const *sprite_name,
      osspriteop_area **area,
      osspriteop_header **sprite);
extern void wimpextend_get_sprite_address (osspriteop_area const *sprite_area,
      char const *sprite_name,
      osspriteop_area **area,
      osspriteop_header **sprite);

/* ------------------------------------------------------------------------
 * Function:      wimpextend_get_mode_suffix()
 *
 * Description:   Append filename with mode suffix - RISC OS Select
 *
 * Input:         filename - value of R1 on entry
 *
 * Output:        buffer1 - value of R0 on exit
 *                buffer2 - value of R1 on exit
 *
 * Other notes:   Calls SWI 0x400FB with R0 = 0x101.
 */

extern os_error *xwimpextend_get_mode_suffix (char *filename,
      char **buffer1,
      char **buffer2);
extern void wimpextend_get_mode_suffix (char *filename,
      char **buffer1,
      char **buffer2);

/* ------------------------------------------------------------------------
 * Function:      wimpextend_get_sprite_colour_map()
 *
 * Description:   Read colourmap translation for rendering sprite - RISC OS
 *                Select
 *
 * Input:         flags - value of R1 on entry
 *                w - value of R2 on entry
 *                validation - value of R3 on entry
 *                background - value of R4 on entry
 *
 * Output:        colourmap - value of R0 on exit
 *
 * Other notes:   Calls SWI 0x400FB with R0 = 0x102.
 */

extern os_error *xwimpextend_get_sprite_colour_map (wimpextendgetspritecolourmap_flags flags,
      wimp_w w,
      char const *validation,
      os_colour background,
      osspriteop_colour_mapping **colourmap);
extern void wimpextend_get_sprite_colour_map (wimpextendgetspritecolourmap_flags flags,
      wimp_w w,
      char const *validation,
      os_colour background,
      osspriteop_colour_mapping **colourmap);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
