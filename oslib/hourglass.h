#ifndef hourglass_H
#define hourglass_H

/* C header file for Hourglass
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:48:23 2012
 * Jonathan Coxhead, jonathan@doves.demon.co.uk, 29 Aug 1995
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
#undef  Hourglass_On
#define Hourglass_On                            0x406C0
#undef  XHourglass_On
#define XHourglass_On                           0x606C0
#undef  Hourglass_Off
#define Hourglass_Off                           0x406C1
#undef  XHourglass_Off
#define XHourglass_Off                          0x606C1
#undef  Hourglass_Smash
#define Hourglass_Smash                         0x406C2
#undef  XHourglass_Smash
#define XHourglass_Smash                        0x606C2
#undef  Hourglass_Start
#define Hourglass_Start                         0x406C3
#undef  XHourglass_Start
#define XHourglass_Start                        0x606C3
#undef  Hourglass_Percentage
#define Hourglass_Percentage                    0x406C4
#undef  XHourglass_Percentage
#define XHourglass_Percentage                   0x606C4
#undef  Hourglass_LEDs
#define Hourglass_LEDs                          0x406C5
#undef  XHourglass_LEDs
#define XHourglass_LEDs                         0x606C5
#undef  Hourglass_Colours
#define Hourglass_Colours                       0x406C6
#undef  XHourglass_Colours
#define XHourglass_Colours                      0x606C6

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      hourglass_on()
 *
 * Description:   Turns on the hourglass
 *
 * Other notes:   Calls SWI 0x406C0.
 */

extern os_error *xhourglass_on (void);
__swi (0x406C0) void hourglass_on (void);

/* ------------------------------------------------------------------------
 * Function:      hourglass_off()
 *
 * Description:   Turns off the hourglass
 *
 * Other notes:   Calls SWI 0x406C1.
 */

extern os_error *xhourglass_off (void);
__swi (0x406C1) void hourglass_off (void);

/* ------------------------------------------------------------------------
 * Function:      hourglass_smash()
 *
 * Description:   Turns off the hourglass immediately
 *
 * Other notes:   Calls SWI 0x406C2.
 */

extern os_error *xhourglass_smash (void);
__swi (0x406C2) void hourglass_smash (void);

/* ------------------------------------------------------------------------
 * Function:      hourglass_start()
 *
 * Description:   Turns on the hourglass after a given delay
 *
 * Input:         delay - value of R0 on entry
 *
 * Other notes:   Calls SWI 0x406C3.
 */

extern os_error *xhourglass_start (int delay);
__swi (0x406C3) void hourglass_start (int delay);

/* ------------------------------------------------------------------------
 * Function:      hourglass_percentage()
 *
 * Description:   Displays a percentage below the hourglass
 *
 * Input:         percent - value of R0 on entry
 *
 * Other notes:   Calls SWI 0x406C4.
 */

extern os_error *xhourglass_percentage (int percent);
__swi (0x406C4) void hourglass_percentage (int percent);

/* ------------------------------------------------------------------------
 * Function:      hourglass_leds()
 *
 * Description:   Controls the display indicators above and below the
 *                hourglass
 *
 * Input:         eor_mask - value of R0 on entry
 *                and_mask - value of R1 on entry
 *
 * Output:        old_leds - value of R0 on exit (X version only)
 *
 * Returns:       R0 (non-X version only)
 *
 * Other notes:   Calls SWI 0x406C5.
 */

extern os_error *xhourglass_leds (bits eor_mask,
      bits and_mask,
      bits *old_leds);
__swi (0x406C5) bits hourglass_leds (bits eor_mask,
      bits and_mask);

/* ------------------------------------------------------------------------
 * Function:      hourglass_colours()
 *
 * Description:   Sets the colours used to display the hourglass
 *
 * Input:         sand - value of R0 on entry
 *                glass - value of R1 on entry
 *
 * Output:        old_sand - value of R0 on exit
 *                old_glass - value of R1 on exit
 *
 * Other notes:   Calls SWI 0x406C6.
 */

extern os_error *xhourglass_colours (os_colour sand,
      os_colour glass,
      os_colour *old_sand,
      os_colour *old_glass);
extern void hourglass_colours (os_colour sand,
      os_colour glass,
      os_colour *old_sand,
      os_colour *old_glass);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
