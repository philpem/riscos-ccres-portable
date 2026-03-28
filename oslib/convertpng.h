#ifndef convertpng_H
#define convertpng_H

/* C header file for ConvertPNG
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:48:23 2012
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

#if defined NAMESPACE_OSLIB
  namespace OSLib {
#endif

/**********************************
 * SWI names and SWI reason codes *
 **********************************/
#undef  ConvertPNG_Info
#define ConvertPNG_Info                         0x564C0
#undef  XConvertPNG_Info
#define XConvertPNG_Info                        0x764C0
#undef  ConvertPNG_CreateSprite
#define ConvertPNG_CreateSprite                 0x564C1
#undef  XConvertPNG_CreateSprite
#define XConvertPNG_CreateSprite                0x764C1

/********************
 * Type definitions *
 ********************/
typedef bits convertpng_info_flags;

typedef bits convertpng_create_sprite_flags;

typedef bits convertpng_colour_type;

typedef bits convertpng_interlace_type;

/************************
 * Constant definitions *
 ************************/
#define convertpng_CREATE_SPRITE_AREA           ((convertpng_create_sprite_flags) 0x1u)
#define convertpng_USE_BACKGROUND               ((convertpng_create_sprite_flags) 0x2u)
#define convertpng_HAS_PALETTE                  ((convertpng_colour_type) 0x1u)
#define convertpng_IS_COLOUR                    ((convertpng_colour_type) 0x2u)
#define convertpng_HAS_ALPHA_CHANNEL            ((convertpng_colour_type) 0x4u)
#define convertpng_NO_INTERLACING               ((convertpng_interlace_type) 0x1u)
#define convertpng_ADAM7_INTERLACING            ((convertpng_interlace_type) 0x2u)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      convertpng_info()
 *
 * Description:   Read information about a PNG image - RISC OS 4.32+
 *
 * Input:         flags - value of R0 on entry
 *                buffer - value of R1 on entry
 *                size - value of R2 on entry
 *
 * Output:        width - value of R0 on exit
 *                height - value of R1 on exit
 *                bpp - value of R2 on exit
 *                colour_type - value of R3 on exit
 *                interlace_type - value of R4 on exit
 *
 * Other notes:   Calls SWI 0x564C0.
 */

extern os_error *xconvertpng_info (convertpng_info_flags flags,
      byte const *buffer,
      int size,
      int *width,
      int *height,
      int *bpp,
      convertpng_colour_type *colour_type,
      convertpng_interlace_type *interlace_type);
extern void convertpng_info (convertpng_info_flags flags,
      byte const *buffer,
      int size,
      int *width,
      int *height,
      int *bpp,
      convertpng_colour_type *colour_type,
      convertpng_interlace_type *interlace_type);

/* ------------------------------------------------------------------------
 * Function:      convertpng_create_sprite()
 *
 * Description:   Create a sprite from a PNG image - RISC OS 4.32+
 *
 * Input:         flags - value of R0 on entry
 *                input_buffer - value of R1 on entry
 *                input_size - value of R2 on entry
 *                output_buffer - value of R3 on entry
 *                output_size - value of R4 on entry
 *                background - value of R5 on entry
 *
 * Output:        size - value of R4 on exit (X version only)
 *
 * Returns:       R4 (non-X version only)
 *
 * Other notes:   Calls SWI 0x564C1.
 */

extern os_error *xconvertpng_create_sprite (convertpng_create_sprite_flags flags,
      byte const *input_buffer,
      int input_size,
      byte *output_buffer,
      int output_size,
      os_colour background,
      int *size);
extern int convertpng_create_sprite (convertpng_create_sprite_flags flags,
      byte const *input_buffer,
      int input_size,
      byte *output_buffer,
      int output_size,
      os_colour background);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
