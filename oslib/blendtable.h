#ifndef blendtable_H
#define blendtable_H

/* C header file for BlendTable
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:47:41 2012
 * Tom Hughes, tom@compton.nu, 20 Nov 2002
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
#undef  BlendTable_GenerateTable
#define BlendTable_GenerateTable                0x56280
#undef  XBlendTable_GenerateTable
#define XBlendTable_GenerateTable               0x76280
#undef  BlendTable_GenerateTableModeToMode
#define BlendTable_GenerateTableModeToMode      0x56280
#undef  XBlendTable_GenerateTableModeToMode
#define XBlendTable_GenerateTableModeToMode     0x76280
#undef  BlendTable_GenerateTableModeToSprite
#define BlendTable_GenerateTableModeToSprite    0x56280
#undef  XBlendTable_GenerateTableModeToSprite
#define XBlendTable_GenerateTableModeToSprite   0x76280
#undef  BlendTable_GenerateTableSpriteToMode
#define BlendTable_GenerateTableSpriteToMode    0x56280
#undef  XBlendTable_GenerateTableSpriteToMode
#define XBlendTable_GenerateTableSpriteToMode   0x76280
#undef  BlendTable_GenerateTableSpriteToSprite
#define BlendTable_GenerateTableSpriteToSprite  0x56280
#undef  XBlendTable_GenerateTableSpriteToSprite
#define XBlendTable_GenerateTableSpriteToSprite 0x76280
#undef  BlendTable_UnlockTable
#define BlendTable_UnlockTable                  0x56281
#undef  XBlendTable_UnlockTable
#define XBlendTable_UnlockTable                 0x76281

/********************
 * Type definitions *
 ********************/
typedef bits blendtable_generate_flags;

/************************
 * Constant definitions *
 ************************/
#define blendtable_SOURCE_IS_POINTER            ((blendtable_generate_flags) 0x1u)
#define blendtable_DESTINAION_IS_POINTER        ((blendtable_generate_flags) 0x2u)
#define blendtable_LOCK_TABLE                   ((blendtable_generate_flags) 0x4u)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      blendtable_generate_table_mode_to_mode()
 *
 * Description:   Generate a table of blended palette entries for blending
 *                between two modes - RISC OS 4.31+
 *
 * Input:         flags - value of R0 on entry
 *                source_mode - value of R1 on entry
 *                destination_mode - value of R3 on entry
 *                translucency - value of R5 on entry
 *                buffer_in - value of R6 on entry
 *
 * Output:        source_colours - value of R0 on exit
 *                destination_colours - value of R1 on exit
 *                size - value of R2 on exit
 *                buffer_out - value of R6 on exit
 *
 * Other notes:   Calls SWI 0x56280 with R2 = 0x0, R4 = 0x0.
 */

extern os_error *xblendtable_generate_table_mode_to_mode (blendtable_generate_flags flags,
      os_mode source_mode,
      os_mode destination_mode,
      int translucency,
      byte *buffer_in,
      int *source_colours,
      int *destination_colours,
      int *size,
      byte **buffer_out);
extern void blendtable_generate_table_mode_to_mode (blendtable_generate_flags flags,
      os_mode source_mode,
      os_mode destination_mode,
      int translucency,
      byte *buffer_in,
      int *source_colours,
      int *destination_colours,
      int *size,
      byte **buffer_out);

/* ------------------------------------------------------------------------
 * Function:      blendtable_generate_table_mode_to_sprite()
 *
 * Description:   Generate a table of blended palette entries for blending
 *                from a mode to a sprite - RISC OS 4.31+
 *
 * Input:         flags - value of R0 on entry
 *                source_mode - value of R1 on entry
 *                destination_area - value of R3 on entry
 *                destination_id - value of R4 on entry
 *                translucency - value of R5 on entry
 *                buffer_in - value of R6 on entry
 *
 * Output:        source_colours - value of R0 on exit
 *                destination_colours - value of R1 on exit
 *                size - value of R2 on exit
 *                buffer_out - value of R6 on exit
 *
 * Other notes:   Calls SWI 0x56280 with R2 = 0x0.
 */

extern os_error *xblendtable_generate_table_mode_to_sprite (blendtable_generate_flags flags,
      os_mode source_mode,
      osspriteop_area const *destination_area,
      osspriteop_id destination_id,
      int translucency,
      byte *buffer_in,
      int *source_colours,
      int *destination_colours,
      int *size,
      byte **buffer_out);
extern void blendtable_generate_table_mode_to_sprite (blendtable_generate_flags flags,
      os_mode source_mode,
      osspriteop_area const *destination_area,
      osspriteop_id destination_id,
      int translucency,
      byte *buffer_in,
      int *source_colours,
      int *destination_colours,
      int *size,
      byte **buffer_out);

/* ------------------------------------------------------------------------
 * Function:      blendtable_generate_table_sprite_to_mode()
 *
 * Description:   Generate a table of blended palette entries for blending
 *                from a sprite to a mode - RISC OS 4.31+
 *
 * Input:         flags - value of R0 on entry
 *                source_area - value of R1 on entry
 *                source_id - value of R2 on entry
 *                destination_mode - value of R3 on entry
 *                translucency - value of R5 on entry
 *                buffer_in - value of R6 on entry
 *
 * Output:        source_colours - value of R0 on exit
 *                destination_colours - value of R1 on exit
 *                size - value of R2 on exit
 *                buffer_out - value of R6 on exit
 *
 * Other notes:   Calls SWI 0x56280 with R4 = 0x0.
 */

extern os_error *xblendtable_generate_table_sprite_to_mode (blendtable_generate_flags flags,
      osspriteop_area const *source_area,
      osspriteop_id source_id,
      os_mode destination_mode,
      int translucency,
      byte *buffer_in,
      int *source_colours,
      int *destination_colours,
      int *size,
      byte **buffer_out);
extern void blendtable_generate_table_sprite_to_mode (blendtable_generate_flags flags,
      osspriteop_area const *source_area,
      osspriteop_id source_id,
      os_mode destination_mode,
      int translucency,
      byte *buffer_in,
      int *source_colours,
      int *destination_colours,
      int *size,
      byte **buffer_out);

/* ------------------------------------------------------------------------
 * Function:      blendtable_generate_table_sprite_to_sprite()
 *
 * Description:   Generate a table of blended palette entries for blending
 *                between two sprites - RISC OS 4.31+
 *
 * Input:         flags - value of R0 on entry
 *                source_area - value of R1 on entry
 *                source_id - value of R2 on entry
 *                destination_area - value of R3 on entry
 *                destination_id - value of R4 on entry
 *                translucency - value of R5 on entry
 *                buffer_in - value of R6 on entry
 *
 * Output:        source_colours - value of R0 on exit
 *                destination_colours - value of R1 on exit
 *                size - value of R2 on exit
 *                buffer_out - value of R6 on exit
 *
 * Other notes:   Calls SWI 0x56280.
 */

extern os_error *xblendtable_generate_table_sprite_to_sprite (blendtable_generate_flags flags,
      osspriteop_area const *source_area,
      osspriteop_id source_id,
      osspriteop_area const *destination_area,
      osspriteop_id destination_id,
      int translucency,
      byte *buffer_in,
      int *source_colours,
      int *destination_colours,
      int *size,
      byte **buffer_out);
extern void blendtable_generate_table_sprite_to_sprite (blendtable_generate_flags flags,
      osspriteop_area const *source_area,
      osspriteop_id source_id,
      osspriteop_area const *destination_area,
      osspriteop_id destination_id,
      int translucency,
      byte *buffer_in,
      int *source_colours,
      int *destination_colours,
      int *size,
      byte **buffer_out);

/* ------------------------------------------------------------------------
 * Function:      blendtable_unlock_table()
 *
 * Description:   Unlock a blend table - RISC OS 4.31+
 *
 * Input:         buffer - value of R0 on entry
 *
 * Other notes:   Calls SWI 0x56281.
 */

extern os_error *xblendtable_unlock_table (byte *buffer);
__swi (0x56281) void blendtable_unlock_table (byte *buffer);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
