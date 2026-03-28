#ifndef remoteprintersupport_H
#define remoteprintersupport_H

/* C header file for RemotePrinterSupport
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:48:24 2012
 * Richard Sargeant, sargeant@arcade.demon.co.uk, 26-Apr-1999
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

#if defined NAMESPACE_OSLIB
  namespace OSLib {
#endif

/**********************************
 * SWI names and SWI reason codes *
 **********************************/
#undef  RemotePrinterSupport_RemotePrinterSupport
#define RemotePrinterSupport_RemotePrinterSupport 0x47980
#undef  XRemotePrinterSupport_RemotePrinterSupport
#define XRemotePrinterSupport_RemotePrinterSupport 0x67980
#undef  RemotePrinterSupport_ReadPollwordLocation
#define RemotePrinterSupport_ReadPollwordLocation 0x47981
#undef  XRemotePrinterSupport_ReadPollwordLocation
#define XRemotePrinterSupport_ReadPollwordLocation 0x67981
#undef  RemotePrinterSupport_GetNextEvent
#define RemotePrinterSupport_GetNextEvent       0x47982
#undef  XRemotePrinterSupport_GetNextEvent
#define XRemotePrinterSupport_GetNextEvent      0x67982
#undef  RemotePrinterSupport_ReadUniqueAddress
#define RemotePrinterSupport_ReadUniqueAddress  0x47983
#undef  XRemotePrinterSupport_ReadUniqueAddress
#define XRemotePrinterSupport_ReadUniqueAddress 0x67983
#undef  RemotePrinterSupport_Enable
#define RemotePrinterSupport_Enable             0x47984
#undef  XRemotePrinterSupport_Enable
#define XRemotePrinterSupport_Enable            0x67984
#undef  RemotePrinterSupport_Disable
#define RemotePrinterSupport_Disable            0x47985
#undef  XRemotePrinterSupport_Disable
#define XRemotePrinterSupport_Disable           0x67985
#undef  RemotePrinterSupport_EnableUpcalls
#define RemotePrinterSupport_EnableUpcalls      0x47986
#undef  XRemotePrinterSupport_EnableUpcalls
#define XRemotePrinterSupport_EnableUpcalls     0x67986
#undef  RemotePrinterSupport_DisableUpcalls
#define RemotePrinterSupport_DisableUpcalls     0x47987
#undef  XRemotePrinterSupport_DisableUpcalls
#define XRemotePrinterSupport_DisableUpcalls    0x67987

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
