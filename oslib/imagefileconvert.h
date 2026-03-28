#ifndef imagefileconvert_H
#define imagefileconvert_H

/* C header file for ImageFileConvert
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
#undef  ImageFileConvert_Convert
#define ImageFileConvert_Convert                0x56840
#undef  XImageFileConvert_Convert
#define XImageFileConvert_Convert               0x76840
#undef  ImageFileConvert_MiscOp
#define ImageFileConvert_MiscOp                 0x56841
#undef  XImageFileConvert_MiscOp
#define XImageFileConvert_MiscOp                0x76841
#undef  ImageFileConvert_ReadInfo
#define ImageFileConvert_ReadInfo               0x56841
#undef  XImageFileConvert_ReadInfo
#define XImageFileConvert_ReadInfo              0x76841
#undef  ImageFileConvert_Register
#define ImageFileConvert_Register               0x56843
#undef  XImageFileConvert_Register
#define XImageFileConvert_Register              0x76843
#undef  ImageFileConvert_Deregister
#define ImageFileConvert_Deregister             0x56844
#undef  XImageFileConvert_Deregister
#define XImageFileConvert_Deregister            0x76844
#undef  ImageFileConvert_EnumerateConverters
#define ImageFileConvert_EnumerateConverters    0x56845
#undef  XImageFileConvert_EnumerateConverters
#define XImageFileConvert_EnumerateConverters   0x76845
#undef  ImageFileConvert_ConverterInfo
#define ImageFileConvert_ConverterInfo          0x56846
#undef  XImageFileConvert_ConverterInfo
#define XImageFileConvert_ConverterInfo         0x76846

/************************************
 * Structure and union declarations *
 ************************************/
typedef struct imagefileconvert_definition      imagefileconvert_definition;

/********************
 * Type definitions *
 ********************/
typedef bits imagefileconvertconvert_flags;

typedef bits imagefileconvertconvert_type;

typedef bits imagefileconvert_op_type;

typedef bits imagefileconvertreadinfo_flags;

typedef bits imagefileconvertregister_flags;

struct imagefileconvert_definition
   {  int api_version;
      int flags;
      imagefileconvertconvert_type type;
      char *name;
      int ws_value;
      asm_routine do_convert;
      asm_routine do_miscop;
   };

typedef bits imagefileconvertderegister_flags;

typedef bits imagefileconvertenumerateconverters_flags;

typedef bits imagefileconvertconverterinfo_flags;

/************************
 * Constant definitions *
 ************************/
#define imagefileconvertconvertflags_OUT_OPTION_SHIFT (0)
#define imagefileconvertconvertflags_IN_OPTION_SHIFT (8)
#define imagefileconvertconvertflags_IN_OUT_OPTION_SHIFT (16)
#define imagefileconvertconvertflagsoutsprite_SPRITE ((imagefileconvert_flags) 0x1u)
#define imagefileconvertconvertflagsoutjpeg_MONOCHROME ((imagefileconvert_flags) 0x1u)
#define imagefileconvertconvertflagsoutjpeg_QUALITY_SHIFT (1)
#define imagefileconvertconverttype_DEST_FILE_TYPE_SHIFT (0)
#define imagefileconvertconverttype_SRC_FILE_TYPE_SHIFT (16)
#define imagefileconvertconverttype_START_ENUMERATION ((imagefileconvertconvert_type) 0xFFFFFFFFu)
      /*can be used in ImageFileConvert_EnumerateConverters*/
#define imagefileconvertreadinfoflags_PALETTE   ((imagefileconvertreadinfo_flags) 0x1u)
#define imagefileconvertreadinfoflags_COLOUR    ((imagefileconvertreadinfo_flags) 0x2u)
#define imagefileconvertreadinfoflags_ALPHA_OR_MASK ((imagefileconvertreadinfo_flags) 0x4u)
#define imagefileconvertreadinfoflags_INTERLACE_SHIFT (3)
#define imagefileconvertreadinfoflags_INTERLACE_MASK (7)
#define imagefileconvertreadinfoflagsinterlace_NO ((imagefileconvertreadinfo_flags) 0x0u)
#define imagefileconvertreadinfoflagsinterlace_ADAM7 ((imagefileconvertreadinfo_flags) 0x1u)
#define imagefileconvertreadinfoflagsinterlace_VERTICAL ((imagefileconvertreadinfo_flags) 0x2u)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      imagefileconvert_convert()
 *
 * Description:   To convert an image from one format to another
 *
 * Input:         flags - value of R0 on entry
 *                conversion_type - value of R1 on entry
 *                img_in - value of R2 on entry
 *                img_in_size - value of R3 on entry
 *                img_out - value of R4 on entry
 *                img_out_size_in - value of R5 on entry
 *                background - value of R6 on entry
 *                param0 - value of R7 on entry
 *                param1 - value of R8 on entry
 *                param2 - value of R9 on entry
 *
 * Output:        img_out_size_out - value of R5 on exit
 *
 * Other notes:   Calls SWI 0x56840.
 */

extern os_error *ximagefileconvert_convert (imagefileconvertconvert_flags flags,
      imagefileconvertconvert_type conversion_type,
      void const *img_in,
      int img_in_size,
      void *img_out,
      int img_out_size_in,
      os_colour background,
      int param0,
      int param1,
      int param2,
      int *img_out_size_out);
extern void imagefileconvert_convert (imagefileconvertconvert_flags flags,
      imagefileconvertconvert_type conversion_type,
      void const *img_in,
      int img_in_size,
      void *img_out,
      int img_out_size_in,
      os_colour background,
      int param0,
      int param1,
      int param2,
      int *img_out_size_out);

/* ------------------------------------------------------------------------
 * Function:      imagefileconvert_misc_op()
 *
 * Description:   Provide miscellaneous operations to obtain information
 *                about the conversion process
 *
 * Input:         flags - value of R0 on entry
 *                conversion_type - value of R1 on entry
 *                img_in - value of R2 on entry
 *                img_in_size - value of R3 on entry
 *                operation - value of R4 on entry
 *                param0_in - value of R5 on entry
 *                param1_in - value of R6 on entry
 *                param2_in - value of R7 on entry
 *                param3_in - value of R8 on entry
 *                param4_in - value of R9 on entry
 *
 * Output:        param0_out - value of R0 on exit
 *                param1_out - value of R1 on exit
 *                param2_out - value of R2 on exit
 *                param3_out - value of R3 on exit
 *                param4_out - value of R4 on exit
 *                param5_out - value of R5 on exit
 *                param6_out - value of R6 on exit
 *                param7_out - value of R7 on exit
 *                param8_out - value of R8 on exit
 *                param9_out - value of R9 on exit
 *
 * Other notes:   Calls SWI 0x56841.
 */

extern os_error *ximagefileconvert_misc_op (imagefileconvertconvert_flags flags,
      imagefileconvertconvert_type conversion_type,
      void const *img_in,
      int img_in_size,
      imagefileconvert_op_type operation,
      int param0_in,
      int param1_in,
      int param2_in,
      int param3_in,
      int param4_in,
      int *param0_out,
      int *param1_out,
      int *param2_out,
      int *param3_out,
      int *param4_out,
      int *param5_out,
      int *param6_out,
      int *param7_out,
      int *param8_out,
      int *param9_out);
extern void imagefileconvert_misc_op (imagefileconvertconvert_flags flags,
      imagefileconvertconvert_type conversion_type,
      void const *img_in,
      int img_in_size,
      imagefileconvert_op_type operation,
      int param0_in,
      int param1_in,
      int param2_in,
      int param3_in,
      int param4_in,
      int *param0_out,
      int *param1_out,
      int *param2_out,
      int *param3_out,
      int *param4_out,
      int *param5_out,
      int *param6_out,
      int *param7_out,
      int *param8_out,
      int *param9_out);

/* ------------------------------------------------------------------------
 * Function:      imagefileconvert_read_info()
 *
 * Description:   Reads information about the image which is common to most
 *                bitmap-type operations.
 *
 * Input:         flags_in - value of R0 on entry
 *                conversion_type - value of R1 on entry
 *                img_in - value of R2 on entry
 *                img_in_size - value of R3 on entry
 *
 * Output:        width - in pixels
 *                height - in pixels
 *                bps - value of R2 on exit
 *                flags_out - value of R3 on exit
 *                xdpi - value of R4 on exit
 *                ydpi - value of R5 on exit
 *
 * Other notes:   Calls SWI 0x56841 with R4 = 0x190.
 */

extern os_error *ximagefileconvert_read_info (imagefileconvertconvert_flags flags_in,
      imagefileconvertconvert_type conversion_type,
      void const *img_in,
      int img_in_size,
      int *width,
      int *height,
      int *bps,
      imagefileconvertreadinfo_flags *flags_out,
      int *xdpi,
      int *ydpi);
extern void imagefileconvert_read_info (imagefileconvertconvert_flags flags_in,
      imagefileconvertconvert_type conversion_type,
      void const *img_in,
      int img_in_size,
      int *width,
      int *height,
      int *bps,
      imagefileconvertreadinfo_flags *flags_out,
      int *xdpi,
      int *ydpi);

/* ------------------------------------------------------------------------
 * Function:      imagefileconvert_register()
 *
 * Description:   Register a new converter
 *
 * Input:         flags - value of R0 on entry
 *                def - value of R1 on entry
 *
 * Output:        api_version - value of R1 on exit
 *
 * Other notes:   Calls SWI 0x56843.
 */

extern os_error *ximagefileconvert_register (imagefileconvertregister_flags flags,
      imagefileconvert_definition const *def,
      int *api_version);
extern void imagefileconvert_register (imagefileconvertregister_flags flags,
      imagefileconvert_definition const *def,
      int *api_version);

/* ------------------------------------------------------------------------
 * Function:      imagefileconvert_deregister()
 *
 * Description:   Deregister a converter
 *
 * Input:         flags - value of R0 on entry
 *                type - value of R1 on entry
 *                name - value of R2 on entry
 *
 * Other notes:   Calls SWI 0x56844.
 */

extern os_error *ximagefileconvert_deregister (imagefileconvertderegister_flags flags,
      imagefileconvertconvert_type type,
      char const *name);
__swi (0x56844) void imagefileconvert_deregister (imagefileconvertderegister_flags flags,
      imagefileconvertconvert_type type,
      char const *name);

/* ------------------------------------------------------------------------
 * Function:      imagefileconvert_enumerate_converters()
 *
 * Description:   Enumerate the currently registered converters
 *
 * Input:         flags - value of R0 on entry
 *                pair_in - value of R1 on entry
 *
 * Output:        def - value of R0 on exit
 *                pair_out - value of R1 on exit
 *
 * Other notes:   Calls SWI 0x56845.
 */

extern os_error *ximagefileconvert_enumerate_converters (imagefileconvertenumerateconverters_flags flags,
      imagefileconvertconvert_type pair_in,
      imagefileconvert_definition **def,
      imagefileconvertconvert_type *pair_out);
extern void imagefileconvert_enumerate_converters (imagefileconvertenumerateconverters_flags flags,
      imagefileconvertconvert_type pair_in,
      imagefileconvert_definition **def,
      imagefileconvertconvert_type *pair_out);

/* ------------------------------------------------------------------------
 * Function:      imagefileconvert_converter_info()
 *
 * Description:   Read information on a conversion
 *
 * Input:         flags - value of R0 on entry
 *                pair - value of R1 on entry
 *
 * Output:        def - value of R0 on exit
 *                name - value of R1 on exit
 *
 * Other notes:   Calls SWI 0x56846.
 */

extern os_error *ximagefileconvert_converter_info (imagefileconvertconverterinfo_flags flags,
      imagefileconvertconvert_type pair,
      imagefileconvert_definition **def,
      char **name);
extern void imagefileconvert_converter_info (imagefileconvertconverterinfo_flags flags,
      imagefileconvertconvert_type pair,
      imagefileconvert_definition **def,
      char **name);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
