#ifndef dragasprite_H
#define dragasprite_H

/* C header file for DragASprite
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:48:23 2012
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

#ifndef osspriteop_H
#include "oslib/osspriteop.h"
#endif

#if defined NAMESPACE_OSLIB
  namespace OSLib {
#endif

/**********************************
 * SWI names and SWI reason codes *
 **********************************/
#undef  DragASprite_Start
#define DragASprite_Start                       0x42400
#undef  XDragASprite_Start
#define XDragASprite_Start                      0x62400
#undef  DragASprite_Stop
#define DragASprite_Stop                        0x42401
#undef  XDragASprite_Stop
#define XDragASprite_Stop                       0x62401

/********************
 * Type definitions *
 ********************/
typedef bits dragasprite_flags;
      /*Flags word for DragASprite_Start*/

/************************
 * Constant definitions *
 ************************/
#define dragasprite_HPOS_LEFT                   ((dragasprite_flags) 0x0u)
      /*Sprite at left of box*/
#define dragasprite_HPOS_CENTRE                 ((dragasprite_flags) 0x1u)
      /*Sprite horizontally centred in box*/
#define dragasprite_HPOS_RIGHT                  ((dragasprite_flags) 0x2u)
      /*Sprite at right of box*/
#define dragasprite_VPOS_BOTTOM                 ((dragasprite_flags) 0x0u)
      /*Sprite at bottom of box*/
#define dragasprite_VPOS_CENTRE                 ((dragasprite_flags) 0x4u)
      /*Sprite vertically centred in box*/
#define dragasprite_VPOS_TOP                    ((dragasprite_flags) 0x8u)
      /*Sprite at top of box*/
#define dragasprite_NO_BOUND                    ((dragasprite_flags) 0x0u)
      /*Drag not bounded*/
#define dragasprite_BOUND_TO_WINDOW             ((dragasprite_flags) 0x10u)
      /*Drag bounded to window containing pointer*/
#define dragasprite_GIVEN_BBOX                  ((dragasprite_flags) 0x20u)
      /*Drag bounded to given OS_Box*/
#define dragasprite_BOUND_SPRITE                ((dragasprite_flags) 0x0u)
      /*Box is bounded*/
#define dragasprite_BOUND_POINTER               ((dragasprite_flags) 0x40u)
      /*Pointer is bounded*/
#define dragasprite_DROP_SHADOW                 ((dragasprite_flags) 0x80u)
      /*Make a sprite with a drop-shadow*/
#define dragasprite_NO_DITHER                   ((dragasprite_flags) 0x100u)
      /*Do not make a semi-transparent sprite*/
#define dragasprite_CENTER_ON_PTR_POS           ((dragasprite_flags) 0x200u)
      /*Sprite is centred on pointer position - RISC OS 4*/
#define dragasprite_SYSTEM_SPRITE_AREA          ((osspriteop_area *) 0x0u)
#define dragasprite_WIMP_SPRITE_AREA            ((osspriteop_area *) 0x1u)

/*************************
 * Function declarations *
 *************************/

#ifdef __cplusplus
   extern "C" {
#endif

/* ------------------------------------------------------------------------
 * Function:      dragasprite_start()
 *
 * Description:   Takes a copy of a sprite and starts a Wimp drag
 *
 * Input:         flags - flags 
 *                area - sprite area holding sprite
 *                sprite_name - pointer to sprite name
 *                box - pointer to box
 *                bbox - pointer to optional bounding box
 *
 * Other notes:   Calls SWI 0x42400.
 */

extern os_error *xdragasprite_start (dragasprite_flags flags,
      osspriteop_area const *area,
      char const *sprite_name,
      os_box const *box,
      os_box const *bbox);
extern void dragasprite_start (dragasprite_flags flags,
      osspriteop_area const *area,
      char const *sprite_name,
      os_box const *box,
      os_box const *bbox);

/* ------------------------------------------------------------------------
 * Function:      dragasprite_stop()
 *
 * Description:   Terminates any current drag operation, and releases
 *                workspace
 *
 * Other notes:   Calls SWI 0x42401.
 */

extern os_error *xdragasprite_stop (void);
__swi (0x42401) void dragasprite_stop (void);

#ifdef __cplusplus
   }
#endif

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
