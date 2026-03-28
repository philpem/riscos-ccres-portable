#ifndef sharedclibrary_H
#define sharedclibrary_H

/* C header file for SharedCLibrary
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:47:41 2012
 * Jonathan Coxhead, jonathan@doves.demon.co.uk, 18 May 1995
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
#undef  SharedCLibrary_LibInitAPCS_A
#define SharedCLibrary_LibInitAPCS_A            0x80680
#undef  XSharedCLibrary_LibInitAPCS_A
#define XSharedCLibrary_LibInitAPCS_A           0xA0680
#undef  SharedCLibrary_LibInitAPCS_R
#define SharedCLibrary_LibInitAPCS_R            0x80681
#undef  XSharedCLibrary_LibInitAPCS_R
#define XSharedCLibrary_LibInitAPCS_R           0xA0681
#undef  SharedCLibrary_LibInitModule
#define SharedCLibrary_LibInitModule            0x80682
#undef  XSharedCLibrary_LibInitModule
#define XSharedCLibrary_LibInitModule           0xA0682
#undef  SharedCLibrary_LibInitAPCS_32
#define SharedCLibrary_LibInitAPCS_32           0x80683
#undef  XSharedCLibrary_LibInitAPCS_32
#define XSharedCLibrary_LibInitAPCS_32          0xA0683
#undef  SharedCLibrary_LibInitModuleAPCS_32
#define SharedCLibrary_LibInitModuleAPCS_32     0x80684
#undef  XSharedCLibrary_LibInitModuleAPCS_32
#define XSharedCLibrary_LibInitModuleAPCS_32    0xA0684
#undef  Service_APCSBacktrace
#define Service_APCSBacktrace                   0xDC
#undef  Service_APCSBacktraceBacktraceRequest
#define Service_APCSBacktraceBacktraceRequest   0x0
#undef  Service_APCSBacktraceRegisterDump
#define Service_APCSBacktraceRegisterDump       0x1
#undef  Service_APCSBacktraceBacktraceDump
#define Service_APCSBacktraceBacktraceDump      0x2
#undef  Service_APCSBacktraceDecodeName
#define Service_APCSBacktraceDecodeName         0x10
#undef  Service_APCSBacktraceMiniDumpCreated
#define Service_APCSBacktraceMiniDumpCreated    0x20

/************************************
 * Structure and union declarations *
 ************************************/
typedef struct sharedclibrary_stub              sharedclibrary_stub;
typedef struct sharedclibrary_stub_list         sharedclibrary_stub_list;
typedef struct sharedclibrary_stub_list_base    sharedclibrary_stub_list_base;
typedef struct kernel_unwind_block              kernel_unwind_block;

/********************
 * Type definitions *
 ********************/
struct sharedclibrary_stub
   {  int chunk_id;
      byte **entry_vector;
      byte **entry_vector_limit;
      byte *static_data;
      byte *static_data_limit;
   };

struct sharedclibrary_stub_list
   {  sharedclibrary_stub stub [UNKNOWN];
   };

#define sharedclibrary_STUB_LIST(N) \
   struct \
      {  sharedclibrary_stub stub [N]; \
      }

#define sharedclibrary_SIZEOF_STUB_LIST(N) \
   ((N)*sizeof ((sharedclibrary_stub_list *) NULL)->stub)

struct kernel_unwind_block
   {  int r4;
      int r5;
      int r6;
      int r7;
      int r8;
      int r9;
      int fp;
      int sp;
      int pc;
      int sl;
      int f4 [3];
      int f5 [3];
      int f6 [3];
      int f7 [3];
   };

/************************
 * Constant definitions *
 ************************/
#define sharedclibrary_ROOT_STACK_SIZE_SHIFT    (16)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      sharedclibrary_lib_init_apcs_r()
 *
 * Description:   Interfaces an application using APCS-R with the Shared C
 *                Library
 *
 * Input:         stub_list - value of R0 on entry
 *                workspace - value of R1 on entry
 *                workspace_limit - value of R2 on entry
 *                shifted_root_stack_size - value of R6 on entry
 *
 * Output:        stack - value of R1 on exit
 *                stack_limit - value of R2 on exit
 *                version - value of R6 on exit
 *
 * Other notes:   Calls SWI 0x80681 with R3 = 0xFFFFFFFF, R4 = 0x0, R5 = 0xFFFFFFFF.
 */

extern os_error *xsharedclibrary_lib_init_apcs_r (sharedclibrary_stub_list const *stub_list,
      void *workspace,
      void *workspace_limit,
      int shifted_root_stack_size,
      byte **stack,
      byte **stack_limit,
      int *version);
extern void sharedclibrary_lib_init_apcs_r (sharedclibrary_stub_list const *stub_list,
      void *workspace,
      void *workspace_limit,
      int shifted_root_stack_size,
      byte **stack,
      byte **stack_limit,
      int *version);

/* ------------------------------------------------------------------------
 * Function:      sharedclibrary_lib_init_module()
 *
 * Description:   Interfaces a module using APCS-R with the Shared C
 *                Library
 *
 * Input:         stub_list - value of R0 on entry
 *                workspace - value of R1 on entry
 *                workspace_limit - value of R2 on entry
 *                clear - value of R3 on entry
 *                static_data - value of R4 on entry
 *                static_data_limit - value of R5 on entry
 *                shifted_root_stack_size - value of R6 on entry
 *
 * Output:        stack - value of R1 on exit
 *                stack_limit - value of R2 on exit
 *                version - value of R6 on exit
 *
 * Other notes:   Calls SWI 0x80682.
 */

extern os_error *xsharedclibrary_lib_init_module (sharedclibrary_stub_list const *stub_list,
      void *workspace,
      void *workspace_limit,
      byte *clear,
      byte const *static_data,
      byte *static_data_limit,
      int shifted_root_stack_size,
      byte **stack,
      byte **stack_limit,
      int *version);
extern void sharedclibrary_lib_init_module (sharedclibrary_stub_list const *stub_list,
      void *workspace,
      void *workspace_limit,
      byte *clear,
      byte const *static_data,
      byte *static_data_limit,
      int shifted_root_stack_size,
      byte **stack,
      byte **stack_limit,
      int *version);

/* ------------------------------------------------------------------------
 * Function:      sharedclibrary_lib_init_apcs_32()
 *
 * Description:   Interfaces an application using APCS-32 with the Shared C
 *                Library
 *
 * Input:         stub_list - value of R0 on entry
 *                workspace - value of R1 on entry
 *                workspace_limit - value of R2 on entry
 *                shifted_root_stack_size - value of R6 on entry
 *
 * Output:        stack - value of R1 on exit
 *                stack_limit - value of R2 on exit
 *                version - value of R6 on exit
 *
 * Other notes:   Calls SWI 0x80683 with R3 = 0xFFFFFFFF, R4 = 0x0, R5 = 0xFFFFFFFF.
 */

extern os_error *xsharedclibrary_lib_init_apcs_32 (sharedclibrary_stub_list const *stub_list,
      void *workspace,
      void *workspace_limit,
      int shifted_root_stack_size,
      byte **stack,
      byte **stack_limit,
      int *version);
extern void sharedclibrary_lib_init_apcs_32 (sharedclibrary_stub_list const *stub_list,
      void *workspace,
      void *workspace_limit,
      int shifted_root_stack_size,
      byte **stack,
      byte **stack_limit,
      int *version);

/* ------------------------------------------------------------------------
 * Function:      sharedclibrary_lib_init_module_apcs_32()
 *
 * Description:   Interfaces a module using APCS-32 with the Shared C
 *                Library
 *
 * Input:         stub_list - value of R0 on entry
 *                workspace - value of R1 on entry
 *                workspace_limit - value of R2 on entry
 *                clear - value of R3 on entry
 *                static_data - value of R4 on entry
 *                static_data_limit - value of R5 on entry
 *                shifted_root_stack_size - value of R6 on entry
 *
 * Output:        stack - value of R1 on exit
 *                stack_limit - value of R2 on exit
 *                version - value of R6 on exit
 *
 * Other notes:   Calls SWI 0x80684.
 */

extern os_error *xsharedclibrary_lib_init_module_apcs_32 (sharedclibrary_stub_list const *stub_list,
      void *workspace,
      void *workspace_limit,
      byte *clear,
      byte const *static_data,
      byte *static_data_limit,
      int shifted_root_stack_size,
      byte **stack,
      byte **stack_limit,
      int *version);
extern void sharedclibrary_lib_init_module_apcs_32 (sharedclibrary_stub_list const *stub_list,
      void *workspace,
      void *workspace_limit,
      byte *clear,
      byte const *static_data,
      byte *static_data_limit,
      int shifted_root_stack_size,
      byte **stack,
      byte **stack_limit,
      int *version);

/* ------------------------------------------------------------------------
 * Function:      service_apcs_backtrace_backtrace_request()
 *
 * Description:   An APCS Backtrace has been requested - RISC OS 6
 *
 * Input:         output - value of R2 on entry
 *                initial_register_set - value of R3 on entry
 *                unwind - value of R4 on entry
 *                language - value of R5 on entry
 *                error_number - value of R6 on entry
 *                fault_address - value of R7 on entry
 *                app_def - value of R8 on entry
 *
 * Output:        unclaimed - value of R1 on exit (X version only)
 *
 * Returns:       R1 (non-X version only)
 *
 * Other notes:   Calls SWI 0x30 with R0 = 0x0, R1 = 0xDC.
 */

extern os_error *xservice_apcs_backtrace_backtrace_request (os_f output,
      os_register_block const *initial_register_set,
      kernel_unwind_block const *unwind,
      char const *language,
      int error_number,
      byte const *fault_address,
      byte const *app_def,
      osbool *unclaimed);
extern osbool service_apcs_backtrace_backtrace_request (os_f output,
      os_register_block const *initial_register_set,
      kernel_unwind_block const *unwind,
      char const *language,
      int error_number,
      byte const *fault_address,
      byte const *app_def);

/* ------------------------------------------------------------------------
 * Function:      service_apcs_backtrace_register_dump()
 *
 * Description:   An APCS Backtrace is in progress and a register dump
 *                needs to be written - RISC OS 6
 *
 * Input:         output - value of R2 on entry
 *                initial_register_set - value of R3 on entry
 *                app_def - value of R8 on entry
 *
 * Output:        unclaimed - value of R1 on exit (X version only)
 *
 * Returns:       R1 (non-X version only)
 *
 * Other notes:   Calls SWI 0x30 with R0 = 0x1, R1 = 0xDC.
 */

extern os_error *xservice_apcs_backtrace_register_dump (os_f output,
      os_register_block const *initial_register_set,
      byte const *app_def,
      osbool *unclaimed);
extern osbool service_apcs_backtrace_register_dump (os_f output,
      os_register_block const *initial_register_set,
      byte const *app_def);

/* ------------------------------------------------------------------------
 * Function:      service_apcs_backtrace_backtrace_dump()
 *
 * Description:   An APCS Backtrace is in progress and the backtrace needs
 *                to be written - RISC OS 6
 *
 * Input:         output - value of R2 on entry
 *                initial_register_set - value of R3 on entry
 *                unwind - value of R4 on entry
 *                language - value of R5 on entry
 *                app_def - value of R8 on entry
 *
 * Output:        unclaimed - value of R1 on exit (X version only)
 *
 * Returns:       R1 (non-X version only)
 *
 * Other notes:   Calls SWI 0x30 with R0 = 0x2, R1 = 0xDC.
 */

extern os_error *xservice_apcs_backtrace_backtrace_dump (os_f output,
      os_register_block const *initial_register_set,
      kernel_unwind_block const *unwind,
      char const *language,
      byte const *app_def,
      osbool *unclaimed);
extern osbool service_apcs_backtrace_backtrace_dump (os_f output,
      os_register_block const *initial_register_set,
      kernel_unwind_block const *unwind,
      char const *language,
      byte const *app_def);

/* ------------------------------------------------------------------------
 * Function:      service_apcs_backtrace_decode_name()
 *
 * Description:   Request to decode a function name into a displayable
 *                format - RISC OS 6
 *
 * Input:         encoded_name - value of R2 on entry
 *                language - value of R3 on entry
 *
 * Output:        unclaimed - value of R1 on exit (X version only)
 *                decoded_name - value of R2 on exit
 *
 * Returns:       R1 (non-X version only)
 *
 * Other notes:   Calls SWI 0x30 with R0 = 0x10, R1 = 0xDC.
 */

extern os_error *xservice_apcs_backtrace_decode_name (char const *encoded_name,
      char const *language,
      osbool *unclaimed,
      char **decoded_name);
extern osbool service_apcs_backtrace_decode_name (char const *encoded_name,
      char const *language,
      char **decoded_name);

/* ------------------------------------------------------------------------
 * Function:      service_apcs_backtrace_mini_dump_created()
 *
 * Description:   Notification to clients that a MiniDump has been created
 *                - RISC OS 6
 *
 * Input:         minidump_filename - value of R2 on entry
 *                executable_name - value of R3 on entry
 *
 * Output:        unclaimed - value of R1 on exit (X version only)
 *
 * Returns:       R1 (non-X version only)
 *
 * Other notes:   Calls SWI 0x30 with R0 = 0x20, R1 = 0xDC.
 */

extern os_error *xservice_apcs_backtrace_mini_dump_created (char const *minidump_filename,
      char const *executable_name,
      osbool *unclaimed);
extern osbool service_apcs_backtrace_mini_dump_created (char const *minidump_filename,
      char const *executable_name);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
