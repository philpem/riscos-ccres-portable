#ifndef timermanager_H
#define timermanager_H

/* C header file for TimerManager
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:47:41 2012
 * John Tytgat, John.Tytgat@aaug.net, 24 Aug 2009
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
#undef  TimerManager_ReturnNumber
#define TimerManager_ReturnNumber               0x58B80
#undef  XTimerManager_ReturnNumber
#define XTimerManager_ReturnNumber              0x78B80
#undef  TimerManager_Claim
#define TimerManager_Claim                      0x58B81
#undef  XTimerManager_Claim
#define XTimerManager_Claim                     0x78B81
#undef  TimerManager_Release
#define TimerManager_Release                    0x58B82
#undef  XTimerManager_Release
#define XTimerManager_Release                   0x78B82
#undef  TimerManager_SetRate
#define TimerManager_SetRate                    0x58B83
#undef  XTimerManager_SetRate
#define XTimerManager_SetRate                   0x78B83
#undef  TimerManager_Convert
#define TimerManager_Convert                    0x58B84
#undef  XTimerManager_Convert
#define XTimerManager_Convert                   0x78B84

/********************
 * Type definitions *
 ********************/
typedef bits timermanagerreturnnumber_flags;

typedef bits timermanager_measurement_format;

typedef bits timermanagerrelease_flags;

/************************
 * Constant definitions *
 ************************/
#define timermanagermeasurementformat_IN_UNIT_SCALER_SHIFT (0)
#define timermanagermeasurementformat_IN_UNIT_SCALER_MASK (7)
#define timermanagermeasurementformat_IN_TYPE_SHIFT (4)
#define timermanagermeasurementformat_IN_TYPE_MASK (3)
#define timermanagermeasurementformat_OUT_UNIT_SCALER_SHIFT (0)
#define timermanagermeasurementformat_OUT_UNIT_SCALER_MASK (7)
#define timermanagermeasurementformat_OUT_TYPE_SHIFT (4)
#define timermanagermeasurementformat_OUT_TYPE_MASK (3)
#define timermanagermeasurementformat_SCALE_EMIN9 ((timermanager_measurement_format) 0x0u)
      /*scaled by 1/1000000000*/
#define timermanagermeasurementformat_SCALE_EMIN6 ((timermanager_measurement_format) 0x1u)
      /*scaled by 1/1000000*/
#define timermanagermeasurementformat_SCALE_EMIN3 ((timermanager_measurement_format) 0x3u)
      /*scaled by 1/1000*/
#define timermanagermeasurementformat_SCALE_E0  ((timermanager_measurement_format) 0x4u)
      /*scaled by 1*/
#define timermanagermeasurementformat_SCALE_EPOS3 ((timermanager_measurement_format) 0x5u)
      /*scaled by 1000*/
#define timermanagermeasurementformat_SCALE_EPOS6 ((timermanager_measurement_format) 0x6u)
      /*scaled by 1000000*/
#define timermanagermeasurementformat_SCALE_EPOS9 ((timermanager_measurement_format) 0x7u)
      /*scaled by 1000000000*/
#define timermanagermeasurementformat_TYPE_NATIVE_TICKS ((timermanager_measurement_format) 0x0u)
#define timermanagermeasurementformat_TYPE_FREQUENCY ((timermanager_measurement_format) 0x1u)
#define timermanagermeasurementformat_TYPE_PERIOD ((timermanager_measurement_format) 0x2u)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      timermanager_return_number()
 *
 * Description:   Find the number of timers available to the operating
 *                system
 *
 * Input:         flags - value of R0 on entry
 *
 * Output:        num_timers - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x58B80.
 */

extern os_error *xtimermanager_return_number (timermanagerreturnnumber_flags flags,
      int *num_timers);
__swi (0x58B80) int timermanager_return_number (timermanagerreturnnumber_flags flags);

/* ------------------------------------------------------------------------
 * Function:      timermanager_claim()
 *
 * Description:   Claim a timer for dedicated use by a client
 *
 * Input:         flags - value of R0 on entry
 *                timer_number - value of R1 on entry
 *                timer_value - value of R2 on entry
 *                interrupt_call - value of R3 on entry
 *                ws_ptr - value of R4 on entry
 *
 * Output:        timer_rate - value of R2 on exit (X version only)
 *
 * Returns:       R2 (non-X version only)
 *
 * Other notes:   Calls SWI 0x58B81.
 */

extern os_error *xtimermanager_claim (timermanager_measurement_format flags,
      int timer_number,
      int timer_value,
      asm_routine interrupt_call,
      int ws_ptr,
      timermanager_measurement_format *timer_rate);
extern timermanager_measurement_format timermanager_claim (timermanager_measurement_format flags,
      int timer_number,
      int timer_value,
      asm_routine interrupt_call,
      int ws_ptr);

/* ------------------------------------------------------------------------
 * Function:      timermanager_release()
 *
 * Description:   Release a previously claimed timer
 *
 * Input:         flags - value of R0 on entry
 *                timer_number - value of R1 on entry
 *
 * Other notes:   Calls SWI 0x58B82.
 */

extern os_error *xtimermanager_release (timermanagerrelease_flags flags,
      int timer_number);
__swi (0x58B82) void timermanager_release (timermanagerrelease_flags flags,
      int timer_number);

/* ------------------------------------------------------------------------
 * Function:      timermanager_set_rate()
 *
 * Description:   Change the rate used by a timer
 *
 * Input:         flags - value of R0 on entry
 *                timer_number - value of R1 on entry
 *                timer_value - value of R2 on entry
 *
 * Output:        timer_rate - value of R2 on exit (X version only)
 *
 * Returns:       R2 (non-X version only)
 *
 * Other notes:   Calls SWI 0x58B83.
 */

extern os_error *xtimermanager_set_rate (timermanager_measurement_format flags,
      int timer_number,
      int timer_value,
      timermanager_measurement_format *timer_rate);
extern timermanager_measurement_format timermanager_set_rate (timermanager_measurement_format flags,
      int timer_number,
      int timer_value);

/* ------------------------------------------------------------------------
 * Function:      timermanager_convert()
 *
 * Description:   Convert between timer rate formats
 *
 * Input:         flags - value of R0 on entry
 *                timer_number - value of R1 on entry
 *                timer_value - value of R2 on entry
 *
 * Output:        timer_rate - value of R2 on exit (X version only)
 *
 * Returns:       R2 (non-X version only)
 *
 * Other notes:   Calls SWI 0x58B84.
 */

extern os_error *xtimermanager_convert (timermanager_measurement_format flags,
      int timer_number,
      int timer_value,
      timermanager_measurement_format *timer_rate);
extern timermanager_measurement_format timermanager_convert (timermanager_measurement_format flags,
      int timer_number,
      int timer_value);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
