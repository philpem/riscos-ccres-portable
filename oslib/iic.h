#ifndef iic_H
#define iic_H

/* C header file for IIC
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:47:41 2012
 * Jonathan Coxhead, jonathan@doves.demon.co.uk, 12 May 1995
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
#undef  IIC_Control
#define IIC_Control                             0x240
#undef  XIIC_Control
#define XIIC_Control                            0x20240
#undef  IICControl_Read
#define IICControl_Read                         0x1
#undef  IICControl_Write
#define IICControl_Write                        0x0

/************************
 * Constant definitions *
 ************************/
#define error_IIC_NO_ACKNOWLEDGE                0x20300u

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      iiccontrol_read()
 *
 * Description:   Reads from an IIC device
 *
 * Input:         device - value of R0 on entry
 *                buffer - value of R1 on entry
 *                size - value of R2 on entry
 *
 * Other notes:   Calls SWI 0x240 with R0 |= 0x1.
 */

extern os_error *xiiccontrol_read (int *device,
      byte *buffer,
      int size);
extern void iiccontrol_read (int *device,
      byte *buffer,
      int size);

/* ------------------------------------------------------------------------
 * Function:      iiccontrol_write()
 *
 * Description:   Writes to an IIC device
 *
 * Input:         device - value of R0 on entry
 *                data - value of R1 on entry
 *                size - value of R2 on entry
 *
 * Other notes:   Calls SWI 0x240 with R0 |= 0x0.
 */

extern os_error *xiiccontrol_write (int *device,
      byte const *data,
      int size);
extern void iiccontrol_write (int *device,
      byte const *data,
      int size);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
