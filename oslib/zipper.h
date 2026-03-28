#ifndef zipper_H
#define zipper_H

/* C header file for Zipper
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:48:24 2012
 * Tom Hughes, tom@compton.nu, 22 Sep 2002
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

#ifndef fileswitch_H
#include "oslib/fileswitch.h"
#endif

#if defined NAMESPACE_OSLIB
  namespace OSLib {
#endif

/**********************************
 * SWI names and SWI reason codes *
 **********************************/
#undef  Zipper_UnZipOpen
#define Zipper_UnZipOpen                        0x559C0
#undef  XZipper_UnZipOpen
#define XZipper_UnZipOpen                       0x759C0
#undef  Zipper_UnZipClose
#define Zipper_UnZipClose                       0x559C1
#undef  XZipper_UnZipClose
#define XZipper_UnZipClose                      0x759C1
#undef  Zipper_UnZipInfo
#define Zipper_UnZipInfo                        0x559C2
#undef  XZipper_UnZipInfo
#define XZipper_UnZipInfo                       0x759C2
#undef  Zipper_UnZipInfoObjectCount
#define Zipper_UnZipInfoObjectCount             0x0
#undef  Zipper_UnZipInfoArchiveComment
#define Zipper_UnZipInfoArchiveComment          0x1
#undef  Zipper_UnZipEnumerate
#define Zipper_UnZipEnumerate                   0x559C3
#undef  XZipper_UnZipEnumerate
#define XZipper_UnZipEnumerate                  0x759C3
#undef  Zipper_UnZipFileInfoToBuffer
#define Zipper_UnZipFileInfoToBuffer            0x559C4
#undef  XZipper_UnZipFileInfoToBuffer
#define XZipper_UnZipFileInfoToBuffer           0x759C4
#undef  Zipper_UnZipFileInfoToRegisters
#define Zipper_UnZipFileInfoToRegisters         0x0
#undef  Zipper_UnZipFileOpen
#define Zipper_UnZipFileOpen                    0x559C5
#undef  XZipper_UnZipFileOpen
#define XZipper_UnZipFileOpen                   0x759C5
#undef  Zipper_UnZipFileClose
#define Zipper_UnZipFileClose                   0x559C6
#undef  XZipper_UnZipFileClose
#define XZipper_UnZipFileClose                  0x759C6
#undef  Zipper_UnZipFileRead
#define Zipper_UnZipFileRead                    0x559C7
#undef  XZipper_UnZipFileRead
#define XZipper_UnZipFileRead                   0x759C7
#undef  Zipper_UnZipFileEOF
#define Zipper_UnZipFileEOF                     0x559C8
#undef  XZipper_UnZipFileEOF
#define XZipper_UnZipFileEOF                    0x759C8
#undef  Zipper_ZipOpen
#define Zipper_ZipOpen                          0x559D0
#undef  XZipper_ZipOpen
#define XZipper_ZipOpen                         0x759D0
#undef  Zipper_ZipClose
#define Zipper_ZipClose                         0x559D1
#undef  XZipper_ZipClose
#define XZipper_ZipClose                        0x759D1
#undef  Zipper_ZipFileOpen
#define Zipper_ZipFileOpen                      0x559D2
#undef  XZipper_ZipFileOpen
#define XZipper_ZipFileOpen                     0x759D2
#undef  Zipper_ZipFileClose
#define Zipper_ZipFileClose                     0x559D3
#undef  XZipper_ZipFileClose
#define XZipper_ZipFileClose                    0x759D3
#undef  Zipper_ZipFileWrite
#define Zipper_ZipFileWrite                     0x559D4
#undef  XZipper_ZipFileWrite
#define XZipper_ZipFileWrite                    0x759D4

/************************************
 * Structure and union declarations *
 ************************************/
typedef struct zipper_un_zip_handle_            *zipper_un_zip_handle;
typedef struct zipper_zip_handle_               *zipper_zip_handle;
typedef union  zipper_time_specifier            zipper_time_specifier;
typedef struct zipper_file_attributes           zipper_file_attributes;

/********************
 * Type definitions *
 ********************/
typedef bits zipper_open_flags;
      /*Used in Zipper_UnZipOpen and Zipper_ZipOpen*/

typedef bits zipper_close_flags;
      /*Used in Zipper_UnZipClose and Zipper_ZipClose*/

typedef bits zipper_info_flags;

typedef bits zipper_enumerate_flags;

typedef bits zipper_un_zip_file_open_flags;

typedef bits zipper_un_zip_file_close_flags;

typedef bits zipper_un_zip_file_read_flags;

typedef bits zipper_un_zip_file_eof_flags;

typedef bits zipper_zip_file_open_flags;

typedef bits zipper_zip_file_close_flags;

typedef bits zipper_zip_file_write_flags;

typedef bits zipper_compression_details;

union zipper_time_specifier
   {  struct
      {  bits load_addr;
         bits exec_addr;
         fileswitch_attr attr;
      }
      riscos_style;
      struct
      {  int centiseconds;
         int seconds;
         int minutes;
         int hours;
         int date;
         int month;
         int year;
      }
      zip_style;
   };

struct zipper_file_attributes
   {  bits internal;
      bits external;
   };

/************************
 * Constant definitions *
 ************************/
#define zipperopenflags_APPEND                  ((zipper_open_flags) 0x1u)
      /*Only for Zipper_ZipOpen*/
#define zipperopenflags_NO_DISCARD              ((zipper_open_flags) 0x80000000u)
#define zipperenumerateflags_CREATOR_VERSION_NUMBER ((zipper_enumerate_flags) 0x1u)
#define zipperenumerateflags_GENERAL_PURPOSE_FLAGS ((zipper_enumerate_flags) 0x2u)
#define zipperenumerateflags_COMPRESSION_METHOD ((zipper_enumerate_flags) 0x4u)
#define zipperenumerateflags_COMPRESSED_SIZE    ((zipper_enumerate_flags) 0x8u)
#define zipperenumerateflags_EXPANDED_SIZE      ((zipper_enumerate_flags) 0x10u)
#define zipperenumerateflags_INTERNAL_ATTRIBUTES ((zipper_enumerate_flags) 0x20u)
#define zipperenumerateflags_EXTERNAL_ATTRIBUTES ((zipper_enumerate_flags) 0x40u)
#define zipperenumerateflags_TIMESTAMP          ((zipper_enumerate_flags) 0x80u)
#define zipperenumerateflags_LOAD_AND_EXEC_ADDRESS ((zipper_enumerate_flags) 0x100u)
#define zipperenumerateflags_RO_EXPANDED_SIZE   ((zipper_enumerate_flags) 0x200u)
#define zipperenumerateflags_RO_ATTRIBUTES      ((zipper_enumerate_flags) 0x400u)
#define zipperenumerateflags_RO_OBJECT_TYPE     ((zipper_enumerate_flags) 0x800u)
#define zipperenumerateflags_RO_FILE_TYPE       ((zipper_enumerate_flags) 0x1000u)
#define zipperenumerateflags_GBPB_FILENAME_LEN  ((zipper_enumerate_flags) 0x2000u)
#define zipperenumerateflags_FILENAME_LEN       ((zipper_enumerate_flags) 0x4000u)
#define zipperenumerateflags_EXTRA_INFO_LEN     ((zipper_enumerate_flags) 0x8000u)
#define zipperenumerateflags_FILE_COMMENT_LEN   ((zipper_enumerate_flags) 0x10000u)
#define zipperfileopenflags_RO_STYLE_TIME_SPECIFIER ((zipper_zip_file_open_flags) 0x1u)
#define zipperfileopenflags_OBJ_IS_DIR          ((zipper_zip_file_open_flags) 0x2u)
#define zipperfileopenflags_OBJ_IS_TEXT         ((zipper_zip_file_open_flags) 0x4u)
#define zipperfileopenflags_EXTRA_FIELD         ((zipper_zip_file_open_flags) 0x8u)
#define zipperfileopenflags_COMMENT_FIELD       ((zipper_zip_file_open_flags) 0x10u)
#define zipperfileopenflags_FILE_ATTRIBUTES     ((zipper_zip_file_open_flags) 0x20u)
#define zipper_COMPRESSION_METHOD               ((zipper_compression_details) 0xFFu)
#define zipper_COMPRESSION_METHOD_SHIFT         (0)
#define zipper_COMPRESSION_LEVEL                ((zipper_compression_details) 0xF00u)
#define zipper_COMPRESSION_LEVEL_SHIFT          (8)
#define zipper_COMPRESSION_METHOD_STORE         ((zipper_compression_details) 0x0u)
#define zipper_COMPRESSION_METHOD_DEFLATE       ((zipper_compression_details) 0x8u)
#define zipper_COMPRESSION_LEVEL_MINIMUM        ((zipper_compression_details) 0x1u)
#define zipper_COMPRESSION_LEVEL_MAXIMUM        ((zipper_compression_details) 0x9u)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      zipper_un_zip_open()
 *
 * Description:   Open an archive for extraction
 *
 * Input:         flags - value of R0 on entry
 *                filename - value of R1 on entry
 *
 * Output:        handle - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x559C0.
 */

extern os_error *xzipper_un_zip_open (zipper_open_flags flags,
      char const *filename,
      zipper_un_zip_handle *handle);
__swi (0x559C0) zipper_un_zip_handle zipper_un_zip_open (zipper_open_flags flags,
      char const *filename);

/* ------------------------------------------------------------------------
 * Function:      zipper_un_zip_close()
 *
 * Description:   Close a file previously opened for extraction
 *
 * Input:         flags - value of R0 on entry
 *                handle - value of R1 on entry
 *
 * Other notes:   Calls SWI 0x559C1.
 */

extern os_error *xzipper_un_zip_close (zipper_close_flags flags,
      zipper_un_zip_handle handle);
__swi (0x559C1) void zipper_un_zip_close (zipper_close_flags flags,
      zipper_un_zip_handle handle);

/* ------------------------------------------------------------------------
 * Function:      zipper_un_zip_info_object_count()
 *
 * Description:   Read number of objects in the archive
 *
 * Input:         flags - value of R0 on entry
 *                handle - value of R1 on entry
 *
 * Output:        objects - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x559C2 with R0 |= 0x0.
 */

extern os_error *xzipper_un_zip_info_object_count (zipper_info_flags flags,
      zipper_un_zip_handle handle,
      int *objects);
extern int zipper_un_zip_info_object_count (zipper_info_flags flags,
      zipper_un_zip_handle handle);

/* ------------------------------------------------------------------------
 * Function:      zipper_un_zip_info_archive_comment()
 *
 * Description:   Read archive comment
 *
 * Input:         flags - value of R0 on entry
 *                handle - value of R1 on entry
 *                buffer - value of R2 on entry
 *                buffer_size - value of R3 on entry
 *
 * Output:        read - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x559C2 with R0 |= 0x1.
 */

extern os_error *xzipper_un_zip_info_archive_comment (zipper_info_flags flags,
      zipper_un_zip_handle handle,
      byte *buffer,
      int buffer_size,
      int *read);
extern int zipper_un_zip_info_archive_comment (zipper_info_flags flags,
      zipper_un_zip_handle handle,
      byte *buffer,
      int buffer_size);

/* ------------------------------------------------------------------------
 * Function:      zipper_un_zip_enumerate()
 *
 * Description:   Enumerate the objects in an archive
 *
 * Input:         flags - value of R0 on entry
 *                handle - value of R1 on entry
 *                buffer - value of R2 on entry
 *                objects - value of R3 on entry
 *                offset - value of R4 on entry
 *                buffer_size - value of R5 on entry
 *
 * Output:        objects_read - value of R3 on exit (X version only)
 *                next_offset - value of R4 on exit
 *                buffer_unused - value of R5 on exit
 *
 * Returns:       R3 (non-X version only)
 *
 * Other notes:   Calls SWI 0x559C3.
 */

extern os_error *xzipper_un_zip_enumerate (zipper_enumerate_flags flags,
      zipper_un_zip_handle handle,
      byte *buffer,
      int objects,
      int offset,
      int buffer_size,
      int *objects_read,
      int *next_offset,
      int *buffer_unused);
extern int zipper_un_zip_enumerate (zipper_enumerate_flags flags,
      zipper_un_zip_handle handle,
      byte *buffer,
      int objects,
      int offset,
      int buffer_size,
      int *next_offset,
      int *buffer_unused);

/* ------------------------------------------------------------------------
 * Function:      zipper_un_zip_file_info_to_buffer()
 *
 * Description:   Read information on a file to a buffer, like
 *                Zipper_UnZipEnumerate
 *
 * Input:         flags - value of R0 on entry
 *                handle - value of R1 on entry
 *                filename - value of R2 on entry
 *                data - value of R3 on entry
 *                data_size - value of R4 on entry
 *
 * Output:        data_end - value of R3 on exit
 *                data_unused - value of R4 on exit
 *
 * Other notes:   Calls SWI 0x559C4.
 */

extern os_error *xzipper_un_zip_file_info_to_buffer (zipper_enumerate_flags flags,
      zipper_un_zip_handle handle,
      char const *filename,
      byte *data,
      int data_size,
      byte **data_end,
      int *data_unused);
extern void zipper_un_zip_file_info_to_buffer (zipper_enumerate_flags flags,
      zipper_un_zip_handle handle,
      char const *filename,
      byte *data,
      int data_size,
      byte **data_end,
      int *data_unused);

/* ------------------------------------------------------------------------
 * Function:      zipper_un_zip_file_info_to_registers()
 *
 * Description:   Read information on a file to registers, like OS_File 5
 *
 * Input:         handle - value of R1 on entry
 *                filename - value of R2 on entry
 *
 * Output:        obj_type - value of R0 on exit
 *                load_address - value of R2 on exit
 *                exec_address - value of R3 on exit
 *                size - value of R4 on exit
 *                attr - value of R5 on exit
 *
 * Other notes:   Calls SWI 0x559C4 with R0 = 0x0.
 */

extern os_error *xzipper_un_zip_file_info_to_registers (zipper_un_zip_handle handle,
      char const *filename,
      fileswitch_object_type *obj_type,
      bits *load_address,
      bits *exec_address,
      int *size,
      fileswitch_attr *attr);
extern void zipper_un_zip_file_info_to_registers (zipper_un_zip_handle handle,
      char const *filename,
      fileswitch_object_type *obj_type,
      bits *load_address,
      bits *exec_address,
      int *size,
      fileswitch_attr *attr);

/* ------------------------------------------------------------------------
 * Function:      zipper_un_zip_file_open()
 *
 * Description:   Open a file in an archive for input
 *
 * Input:         flags - value of R0 on entry
 *                handle - value of R1 on entry
 *                filename - value of R2 on entry
 *
 * Other notes:   Calls SWI 0x559C5.
 */

extern os_error *xzipper_un_zip_file_open (zipper_un_zip_file_open_flags flags,
      zipper_un_zip_handle handle,
      char const *filename);
__swi (0x559C5) void zipper_un_zip_file_open (zipper_un_zip_file_open_flags flags,
      zipper_un_zip_handle handle,
      char const *filename);

/* ------------------------------------------------------------------------
 * Function:      zipper_un_zip_file_close()
 *
 * Description:   Close the currently opened archive file
 *
 * Input:         flags - value of R0 on entry
 *                handle - value of R1 on entry
 *
 * Other notes:   Calls SWI 0x559C6.
 */

extern os_error *xzipper_un_zip_file_close (zipper_un_zip_file_close_flags flags,
      zipper_un_zip_handle handle);
__swi (0x559C6) void zipper_un_zip_file_close (zipper_un_zip_file_close_flags flags,
      zipper_un_zip_handle handle);

/* ------------------------------------------------------------------------
 * Function:      zipper_un_zip_file_read()
 *
 * Description:   Read data from the currently opened archive file
 *
 * Input:         flags - value of R0 on entry
 *                handle - value of R1 on entry
 *                data - value of R2 on entry
 *                size - value of R3 on entry
 *
 * Output:        read - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x559C7.
 */

extern os_error *xzipper_un_zip_file_read (zipper_un_zip_file_read_flags flags,
      zipper_un_zip_handle handle,
      byte *data,
      int size,
      int *read);
__swi (0x559C7) int zipper_un_zip_file_read (zipper_un_zip_file_read_flags flags,
      zipper_un_zip_handle handle,
      byte *data,
      int size);

/* ------------------------------------------------------------------------
 * Function:      zipper_un_zip_file_eof()
 *
 * Description:   Check whether EOF has been reached for the currently
 *                opened archive file
 *
 * Input:         flags - value of R0 on entry
 *                handle - value of R1 on entry
 *
 * Output:        eof - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x559C8.
 */

extern os_error *xzipper_un_zip_file_eof (zipper_un_zip_file_eof_flags flags,
      zipper_un_zip_handle handle,
      osbool *eof);
__swi (0x559C8) osbool zipper_un_zip_file_eof (zipper_un_zip_file_eof_flags flags,
      zipper_un_zip_handle handle);

/* ------------------------------------------------------------------------
 * Function:      zipper_zip_open()
 *
 * Description:   Create an archive
 *
 * Input:         flags - value of R0 on entry
 *                filename - value of R1 on entry
 *
 * Output:        handle - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x559D0.
 */

extern os_error *xzipper_zip_open (zipper_open_flags flags,
      char const *filename,
      zipper_zip_handle *handle);
__swi (0x559D0) zipper_zip_handle zipper_zip_open (zipper_open_flags flags,
      char const *filename);

/* ------------------------------------------------------------------------
 * Function:      zipper_zip_close()
 *
 * Description:   Close a file previously opened for writing
 *
 * Input:         flags - value of R0 on entry
 *                handle - value of R1 on entry
 *
 * Other notes:   Calls SWI 0x559D1.
 */

extern os_error *xzipper_zip_close (zipper_close_flags flags,
      zipper_zip_handle handle);
__swi (0x559D1) void zipper_zip_close (zipper_close_flags flags,
      zipper_zip_handle handle);

/* ------------------------------------------------------------------------
 * Function:      zipper_zip_file_open()
 *
 * Description:   Open a file in an archive for input
 *
 * Input:         flags - value of R0 on entry
 *                handle - value of R1 on entry
 *                filename - value of R2 on entry
 *                compression_details - value of R3 on entry
 *                time_specifier - value of R4 on entry
 *                extra - value of R5 on entry
 *                extra_size - value of R6 on entry
 *                comment - value of R7 on entry
 *                attr - value of R8 on entry
 *
 * Other notes:   Calls SWI 0x559D2.
 */

extern os_error *xzipper_zip_file_open (zipper_zip_file_open_flags flags,
      zipper_zip_handle handle,
      char const *filename,
      zipper_compression_details compression_details,
      zipper_time_specifier const *time_specifier,
      byte const *extra,
      int extra_size,
      char const *comment,
      zipper_file_attributes const *attr);
extern void zipper_zip_file_open (zipper_zip_file_open_flags flags,
      zipper_zip_handle handle,
      char const *filename,
      zipper_compression_details compression_details,
      zipper_time_specifier const *time_specifier,
      byte const *extra,
      int extra_size,
      char const *comment,
      zipper_file_attributes const *attr);

/* ------------------------------------------------------------------------
 * Function:      zipper_zip_file_close()
 *
 * Description:   Close the currently opened archive file
 *
 * Input:         flags - value of R0 on entry
 *                handle - value of R1 on entry
 *
 * Output:        uncompressed_size - value of R0 on exit
 *                compressed_size - value of R1 on exit
 *
 * Other notes:   Calls SWI 0x559D3.
 */

extern os_error *xzipper_zip_file_close (zipper_zip_file_close_flags flags,
      zipper_zip_handle handle,
      int *uncompressed_size,
      int *compressed_size);
extern void zipper_zip_file_close (zipper_zip_file_close_flags flags,
      zipper_zip_handle handle,
      int *uncompressed_size,
      int *compressed_size);

/* ------------------------------------------------------------------------
 * Function:      zipper_zip_file_write()
 *
 * Description:   Write data to the currently opened archive file
 *
 * Input:         flags - value of R0 on entry
 *                handle - value of R1 on entry
 *                data - value of R2 on entry
 *                size - value of R3 on entry
 *
 * Other notes:   Calls SWI 0x559D4.
 */

extern os_error *xzipper_zip_file_write (zipper_zip_file_write_flags flags,
      zipper_zip_handle handle,
      byte *data,
      int size);
__swi (0x559D4) void zipper_zip_file_write (zipper_zip_file_write_flags flags,
      zipper_zip_handle handle,
      byte *data,
      int size);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
