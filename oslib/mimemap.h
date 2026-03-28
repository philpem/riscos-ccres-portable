#ifndef mimemap_H
#define mimemap_H

/* C header file for MimeMap
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:48:23 2012
 * Tom Hughes, tom@compton.nu, 15 Feb 2000
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
#undef  MimeMap_Translate
#define MimeMap_Translate                       0x50B00
#undef  XMimeMap_Translate
#define XMimeMap_Translate                      0x70B00
#undef  MimeMapTranslate_FileTypeToAnything
#define MimeMapTranslate_FileTypeToAnything     0x0
#undef  MimeMapTranslate_AnythingToFileType
#define MimeMapTranslate_AnythingToFileType     0x0
#undef  MimeMapTranslate_FiletypeToFiletypeName
#define MimeMapTranslate_FiletypeToFiletypeName 0x0
#undef  MimeMapTranslate_FiletypeToMIMEType
#define MimeMapTranslate_FiletypeToMIMEType     0x0
#undef  MimeMapTranslate_FiletypeToExtension
#define MimeMapTranslate_FiletypeToExtension    0x0
#undef  MimeMapTranslate_FiletypeNameToFiletype
#define MimeMapTranslate_FiletypeNameToFiletype 0x1
#undef  MimeMapTranslate_FiletypeNameToMIMEType
#define MimeMapTranslate_FiletypeNameToMIMEType 0x1
#undef  MimeMapTranslate_FiletypeNameToExtension
#define MimeMapTranslate_FiletypeNameToExtension 0x1
#undef  MimeMapTranslate_MIMETypeToFiletype
#define MimeMapTranslate_MIMETypeToFiletype     0x2
#undef  MimeMapTranslate_MIMETypeToFiletypeName
#define MimeMapTranslate_MIMETypeToFiletypeName 0x2
#undef  MimeMapTranslate_MIMETypeToExtension
#define MimeMapTranslate_MIMETypeToExtension    0x2
#undef  MimeMapTranslate_ExtensionToFiletype
#define MimeMapTranslate_ExtensionToFiletype    0x3
#undef  MimeMapTranslate_ExtensionToFiletypeName
#define MimeMapTranslate_ExtensionToFiletypeName 0x3
#undef  MimeMapTranslate_ExtensionToMIMEType
#define MimeMapTranslate_ExtensionToMIMEType    0x3

/********************
 * Type definitions *
 ********************/
typedef int mimemap_format;

/************************
 * Constant definitions *
 ************************/
#define mimemap_FORMAT_FILETYPE                 ((mimemap_format) 0x0u)
#define mimemap_FORMAT_FILETYPE_NAME            ((mimemap_format) 0x1u)
#define mimemap_FORMAT_MIME_TYPE                ((mimemap_format) 0x2u)
#define mimemap_FORMAT_EXTENSION                ((mimemap_format) 0x3u)
#define mimemap_FORMAT_MAC                      ((mimemap_format) 0x4u)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      mimemaptranslate_file_type_to_anything()
 *
 * Description:   Translate a numeric file type to any other type
 *
 * Input:         file_type - value of R1 on entry
 *                output_format - value of R2 on entry
 *                output - value of R3 on entry
 *
 * Other notes:   Calls SWI 0x50B00 with R0 = 0x0.
 */

extern os_error *xmimemaptranslate_file_type_to_anything (bits file_type,
      mimemap_format output_format,
      char *output);
extern void mimemaptranslate_file_type_to_anything (bits file_type,
      mimemap_format output_format,
      char *output);

/* ------------------------------------------------------------------------
 * Function:      mimemaptranslate_anything_to_file_type()
 *
 * Description:   Translate any type to a numeric file type
 *
 * Input:         input_format - value of R0 on entry
 *                input - value of R1 on entry
 *
 * Output:        file_type - value of R3 on exit (X version only)
 *
 * Returns:       R3 (non-X version only)
 *
 * Other notes:   Calls SWI 0x50B00 with R2 = 0x0.
 */

extern os_error *xmimemaptranslate_anything_to_file_type (mimemap_format input_format,
      char const *input,
      bits *file_type);
extern bits mimemaptranslate_anything_to_file_type (mimemap_format input_format,
      char const *input);

/* ------------------------------------------------------------------------
 * Function:      mimemaptranslate_filetype_to_filetype_name()
 *
 * Description:   Translate a numeric file type to a textual file type name
 *
 * Input:         file_type - value of R1 on entry
 *                file_type_name - value of R3 on entry
 *
 * Other notes:   Calls SWI 0x50B00 with R0 = 0x0, R2 = 0x1.
 */

extern os_error *xmimemaptranslate_filetype_to_filetype_name (bits file_type,
      char *file_type_name);
extern void mimemaptranslate_filetype_to_filetype_name (bits file_type,
      char *file_type_name);

/* ------------------------------------------------------------------------
 * Function:      mimemaptranslate_filetype_to_mime_type()
 *
 * Description:   Translate a numeric file type to a MIME type
 *
 * Input:         file_type - value of R1 on entry
 *                mime_type - value of R3 on entry
 *
 * Other notes:   Calls SWI 0x50B00 with R0 = 0x0, R2 = 0x2.
 */

extern os_error *xmimemaptranslate_filetype_to_mime_type (bits file_type,
      char *mime_type);
extern void mimemaptranslate_filetype_to_mime_type (bits file_type,
      char *mime_type);

/* ------------------------------------------------------------------------
 * Function:      mimemaptranslate_filetype_to_extension()
 *
 * Description:   Translate a numeric file type to a file extension
 *
 * Input:         file_type - value of R1 on entry
 *                extension - value of R3 on entry
 *
 * Other notes:   Calls SWI 0x50B00 with R0 = 0x0, R2 = 0x3.
 */

extern os_error *xmimemaptranslate_filetype_to_extension (bits file_type,
      char *extension);
extern void mimemaptranslate_filetype_to_extension (bits file_type,
      char *extension);

/* ------------------------------------------------------------------------
 * Function:      mimemaptranslate_filetype_name_to_filetype()
 *
 * Description:   Translate a textual file type name to a numeric file type
 *
 * Input:         file_type_name - value of R1 on entry
 *
 * Output:        file_type - value of R3 on exit (X version only)
 *
 * Returns:       R3 (non-X version only)
 *
 * Other notes:   Calls SWI 0x50B00 with R0 = 0x1, R2 = 0x0.
 */

extern os_error *xmimemaptranslate_filetype_name_to_filetype (char const *file_type_name,
      bits *file_type);
extern bits mimemaptranslate_filetype_name_to_filetype (char const *file_type_name);

/* ------------------------------------------------------------------------
 * Function:      mimemaptranslate_filetype_name_to_mime_type()
 *
 * Description:   Translate a textual file type name to a MIME type
 *
 * Input:         file_type_name - value of R1 on entry
 *                mime_type - value of R3 on entry
 *
 * Other notes:   Calls SWI 0x50B00 with R0 = 0x1, R2 = 0x2.
 */

extern os_error *xmimemaptranslate_filetype_name_to_mime_type (char const *file_type_name,
      char *mime_type);
extern void mimemaptranslate_filetype_name_to_mime_type (char const *file_type_name,
      char *mime_type);

/* ------------------------------------------------------------------------
 * Function:      mimemaptranslate_filetype_name_to_extension()
 *
 * Description:   Translate a textual file type name to a file extension
 *
 * Input:         file_type_name - value of R1 on entry
 *                extension - value of R3 on entry
 *
 * Other notes:   Calls SWI 0x50B00 with R0 = 0x1, R2 = 0x3.
 */

extern os_error *xmimemaptranslate_filetype_name_to_extension (char const *file_type_name,
      char *extension);
extern void mimemaptranslate_filetype_name_to_extension (char const *file_type_name,
      char *extension);

/* ------------------------------------------------------------------------
 * Function:      mimemaptranslate_mime_type_to_filetype()
 *
 * Description:   Translate a MIME type to a numeric file type
 *
 * Input:         mime_type - value of R1 on entry
 *
 * Output:        file_type - value of R3 on exit (X version only)
 *
 * Returns:       R3 (non-X version only)
 *
 * Other notes:   Calls SWI 0x50B00 with R0 = 0x2, R2 = 0x0.
 */

extern os_error *xmimemaptranslate_mime_type_to_filetype (char const *mime_type,
      bits *file_type);
extern bits mimemaptranslate_mime_type_to_filetype (char const *mime_type);

/* ------------------------------------------------------------------------
 * Function:      mimemaptranslate_mime_type_to_filetype_name()
 *
 * Description:   Translate a MIME type to a textual file type name
 *
 * Input:         mime_type - value of R1 on entry
 *                file_type_name - value of R3 on entry
 *
 * Other notes:   Calls SWI 0x50B00 with R0 = 0x2, R2 = 0x1.
 */

extern os_error *xmimemaptranslate_mime_type_to_filetype_name (char const *mime_type,
      char *file_type_name);
extern void mimemaptranslate_mime_type_to_filetype_name (char const *mime_type,
      char *file_type_name);

/* ------------------------------------------------------------------------
 * Function:      mimemaptranslate_mime_type_to_extension()
 *
 * Description:   Translate a MIME type to a file extension
 *
 * Input:         mime_type - value of R1 on entry
 *                extension - value of R3 on entry
 *
 * Other notes:   Calls SWI 0x50B00 with R0 = 0x2, R2 = 0x3.
 */

extern os_error *xmimemaptranslate_mime_type_to_extension (char const *mime_type,
      char *extension);
extern void mimemaptranslate_mime_type_to_extension (char const *mime_type,
      char *extension);

/* ------------------------------------------------------------------------
 * Function:      mimemaptranslate_extension_to_filetype()
 *
 * Description:   Translate a file extension to a numeric file type
 *
 * Input:         extension - value of R1 on entry
 *
 * Output:        file_type - value of R3 on exit (X version only)
 *
 * Returns:       R3 (non-X version only)
 *
 * Other notes:   Calls SWI 0x50B00 with R0 = 0x3, R2 = 0x0.
 */

extern os_error *xmimemaptranslate_extension_to_filetype (char const *extension,
      bits *file_type);
extern bits mimemaptranslate_extension_to_filetype (char const *extension);

/* ------------------------------------------------------------------------
 * Function:      mimemaptranslate_extension_to_filetype_name()
 *
 * Description:   Translate a file extension to a textual file type name
 *
 * Input:         extension - value of R1 on entry
 *                file_type_name - value of R3 on entry
 *
 * Other notes:   Calls SWI 0x50B00 with R0 = 0x3, R2 = 0x1.
 */

extern os_error *xmimemaptranslate_extension_to_filetype_name (char const *extension,
      char *file_type_name);
extern void mimemaptranslate_extension_to_filetype_name (char const *extension,
      char *file_type_name);

/* ------------------------------------------------------------------------
 * Function:      mimemaptranslate_extension_to_mime_type()
 *
 * Description:   Translate a file extension to a MIME type
 *
 * Input:         extension - value of R1 on entry
 *                mime_type - value of R3 on entry
 *
 * Other notes:   Calls SWI 0x50B00 with R0 = 0x3, R2 = 0x2.
 */

extern os_error *xmimemaptranslate_extension_to_mime_type (char const *extension,
      char *mime_type);
extern void mimemaptranslate_extension_to_mime_type (char const *extension,
      char *mime_type);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
