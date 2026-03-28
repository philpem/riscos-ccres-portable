#ifndef inversetable_H
#define inversetable_H

/* C header file for InverseTable
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:47:41 2012
 * Tom Hughes, tom@compton.nu, 21 Nov 2002
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

#if defined NAMESPACE_OSLIB
  namespace OSLib {
#endif

/**********************************
 * SWI names and SWI reason codes *
 **********************************/
#undef  InverseTable_Calculate
#define InverseTable_Calculate                  0x4BF40
#undef  XInverseTable_Calculate
#define XInverseTable_Calculate                 0x6BF40
#undef  InverseTable_SpriteTableForSprite
#define InverseTable_SpriteTableForSprite       0x4BF41
#undef  XInverseTable_SpriteTableForSprite
#define XInverseTable_SpriteTableForSprite      0x6BF41
#undef  InverseTable_SpriteTableForMode
#define InverseTable_SpriteTableForMode         0x4BF41
#undef  XInverseTable_SpriteTableForMode
#define XInverseTable_SpriteTableForMode        0x6BF41

/********************
 * Type definitions *
 ********************/
typedef bits inversetable_colour;

/************************
 * Constant definitions *
 ************************/
#define inversetable_RSHIFT                     (0)
#define inversetable_GSHIFT                     (5)
#define inversetable_BSHIFT                     (10)
#define inversetable_R                          ((inversetable_colour) 0x1Fu)
#define inversetable_G                          ((inversetable_colour) 0x3E0u)
#define inversetable_B                          ((inversetable_colour) 0x7C00u)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      inversetable_calculate()
 *
 * Description:   Calculates inverse tables for the current destination -
 *                RISC OS 4.32+
 *
 * Output:        gcol_to_colour - value of R0 on exit
 *                colour_to_gcol - value of R1 on exit
 *
 * Other notes:   Calls SWI 0x4BF40.
 */

extern os_error *xinversetable_calculate (inversetable_colour **gcol_to_colour,
      os_gcol **colour_to_gcol);
extern void inversetable_calculate (inversetable_colour **gcol_to_colour,
      os_gcol **colour_to_gcol);

/* ------------------------------------------------------------------------
 * Function:      inversetable_sprite_table_for_sprite()
 *
 * Description:   Calculates inverse tables for the given sprite - RISC OS
 *                4.32+
 *
 * Input:         gcol_to_colour_in - value of R0 on entry
 *                colour_to_gcol_in - value of R1 on entry
 *                area - value of R2 on entry
 *                id - value of R3 on entry
 *
 * Output:        gcol_to_colour_out - value of R0 on exit
 *                colour_to_gcol_out - value of R1 on exit
 *
 * Other notes:   Calls SWI 0x4BF41.
 */

extern os_error *xinversetable_sprite_table_for_sprite (inversetable_colour *gcol_to_colour_in,
      os_gcol *colour_to_gcol_in,
      osspriteop_area area,
      osspriteop_id id,
      inversetable_colour **gcol_to_colour_out,
      os_gcol **colour_to_gcol_out);
extern void inversetable_sprite_table_for_sprite (inversetable_colour *gcol_to_colour_in,
      os_gcol *colour_to_gcol_in,
      osspriteop_area area,
      osspriteop_id id,
      inversetable_colour **gcol_to_colour_out,
      os_gcol **colour_to_gcol_out);

/* ------------------------------------------------------------------------
 * Function:      inversetable_sprite_table_for_mode()
 *
 * Description:   Calculates inverse tables for the given mode - RISC OS
 *                4.32+
 *
 * Input:         gcol_to_colour_in - value of R0 on entry
 *                colour_to_gcol_in - value of R1 on entry
 *                mode - value of R2 on entry
 *
 * Output:        gcol_to_colour_out - value of R0 on exit
 *                colour_to_gcol_out - value of R1 on exit
 *
 * Other notes:   Calls SWI 0x4BF41 with R3 = 0x0.
 */

extern os_error *xinversetable_sprite_table_for_mode (inversetable_colour *gcol_to_colour_in,
      os_gcol *colour_to_gcol_in,
      os_mode mode,
      inversetable_colour **gcol_to_colour_out,
      os_gcol **colour_to_gcol_out);
extern void inversetable_sprite_table_for_mode (inversetable_colour *gcol_to_colour_in,
      os_gcol *colour_to_gcol_in,
      os_mode mode,
      inversetable_colour **gcol_to_colour_out,
      os_gcol **colour_to_gcol_out);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
