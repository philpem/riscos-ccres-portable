#ifndef joystick_H
#define joystick_H

/* C header file for Joystick
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:47:15 2012
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
#undef  Joystick_Read
#define Joystick_Read                           0x43F40
#undef  XJoystick_Read
#define XJoystick_Read                          0x63F40
#undef  Joystick_ReadHalfWord
#define Joystick_ReadHalfWord                   0x43F40
#undef  XJoystick_ReadHalfWord
#define XJoystick_ReadHalfWord                  0x63F40
#undef  Joystick_CalibrateTopRight
#define Joystick_CalibrateTopRight              0x43F41
#undef  XJoystick_CalibrateTopRight
#define XJoystick_CalibrateTopRight             0x63F41
#undef  Joystick_CalibrateBottomLeft
#define Joystick_CalibrateBottomLeft            0x43F42
#undef  XJoystick_CalibrateBottomLeft
#define XJoystick_CalibrateBottomLeft           0x63F42

/********************
 * Type definitions *
 ********************/
typedef bits joystick_state;

typedef bits joystick_half_word_state;

/************************
 * Constant definitions *
 ************************/
#define joystick_X                              ((joystick_state) 0xFFu)
#define joystick_Y                              ((joystick_state) 0xFF00u)
#define joystick_SWITCHES                       ((joystick_state) 0xFF0000u)
#define joystick_XSHIFT                         (0)
#define joystick_YSHIFT                         (8)
#define joystick_SWITCHES_SHIFT                 (16)
#define joystick_HALF_WORDX                     ((joystick_state) 0xFFFFu)
#define joystick_HALF_WORDY                     ((joystick_state) 0xFFFF0000u)
#define joystick_HALF_WORD_XSHIFT               (0)
#define joystick_HALF_WORD_YSHIFT               (16)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      joystick_read()
 *
 * Description:   Returns the state of a joystick
 *
 * Input:         joystick_no - value of R0 on entry
 *
 * Output:        state - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x43F40.
 */

extern os_error *xjoystick_read (int joystick_no,
      joystick_state *state);
__swi (0x43F40) joystick_state joystick_read (int joystick_no);

/* ------------------------------------------------------------------------
 * Function:      joystick_read_half_word()
 *
 * Description:   Returns the state of a joystick
 *
 * Input:         joystick_no - value of R0 on entry
 *
 * Output:        state - value of R0 on exit (X version only)
 *                switches - value of R1 on exit
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x43F40 with R0 |= 0x100.
 */

extern os_error *xjoystick_read_half_word (int joystick_no,
      joystick_half_word_state *state,
      bits *switches);
extern joystick_half_word_state joystick_read_half_word (int joystick_no,
      bits *switches);

/* ------------------------------------------------------------------------
 * Function:      joystick_calibrate_top_right()
 *
 * Description:   One of the pair of SWI's to calibrate an analogue
 *                joystick
 *
 * Other notes:   Calls SWI 0x43F41.
 */

extern os_error *xjoystick_calibrate_top_right (void);
__swi (0x43F41) void joystick_calibrate_top_right (void);

/* ------------------------------------------------------------------------
 * Function:      joystick_calibrate_bottom_left()
 *
 * Description:   One of the pair of SWI's to calibrate an analogue
 *                joystick
 *
 * Other notes:   Calls SWI 0x43F42.
 */

extern os_error *xjoystick_calibrate_bottom_left (void);
__swi (0x43F42) void joystick_calibrate_bottom_left (void);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
