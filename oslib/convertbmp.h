#ifndef convertbmp_H
#define convertbmp_H

/* C header file for ConvertBMP
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:48:23 2012
 * John Tytgat, John.Tytgat@aaug.net, 13 Dec 2010
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
#undef  ConvertBMP_CreateSpriteFromDIB
#define ConvertBMP_CreateSpriteFromDIB          0x58940
#undef  XConvertBMP_CreateSpriteFromDIB
#define XConvertBMP_CreateSpriteFromDIB         0x78940

/************************************
 * Structure and union declarations *
 ************************************/
typedef struct dibheader                        dibheader;

/********************
 * Type definitions *
 ********************/
typedef bits convertbmpcreatespritefromdib_flags;

struct dibheader
   {  int sizeHeader;
      int width;
      int height;
      int planes_bps;
      int compression;
      int sizeImage;
      int x_pixels_per_meter;
      int y_pixels_per_meter;
      int num_colormap_entries;
      int num_important_colours;
   };

/************************
 * Constant definitions *
 ************************/
#define convertbmpcreatespritefromdibflags_CREATE_SPRITE ((convertbmpcreatespritefromdib_flags) 0x1u)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      convertbmp_create_sprite_from_dib()
 *
 * Description:   Convert from a Windows 'Device Independent Bitmap' (DIB)
 *                to a sprite (or sprite area)
 *
 * Input:         flags - value of R0 on entry
 *                header - value of R1 on entry
 *                header_length - value of R2 on entry
 *                bitmap - value of R3 on entry
 *                bitmap_length - value of R4 on entry
 *                buf_out - value of R5 on entry
 *                buf_out_len - value of R6 on entry
 *
 * Output:        buf_out_used - value of R6 on exit (X version only)
 *
 * Returns:       R6 (non-X version only)
 *
 * Other notes:   Calls SWI 0x58940.
 */

extern os_error *xconvertbmp_create_sprite_from_dib (convertbmpcreatespritefromdib_flags flags,
      dibheader const *header,
      int header_length,
      byte const *bitmap,
      int bitmap_length,
      byte *buf_out,
      int buf_out_len,
      int *buf_out_used);
extern int convertbmp_create_sprite_from_dib (convertbmpcreatespritefromdib_flags flags,
      dibheader const *header,
      int header_length,
      byte const *bitmap,
      int bitmap_length,
      byte *buf_out,
      int buf_out_len);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
