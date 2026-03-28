#ifndef alarm_H
#define alarm_H

/* C header file for Alarm
 * Written by DefMod (Dec  9 2012) on Sun Dec  9 15:48:24 2012
 * Jonathan Coxhead, jonathan@doves.demon.co.uk, 29 June 1995
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

#ifndef wimp_H
#include "oslib/wimp.h"
#endif

#if defined NAMESPACE_OSLIB
  namespace OSLib {
#endif

/************************************
 * Structure and union declarations *
 ************************************/
typedef struct alarm_date_and_time              alarm_date_and_time;
typedef struct alarm_message_set                alarm_message_set;
typedef struct alarm_message_cancel             alarm_message_cancel;
typedef struct alarm_message_gone_off           alarm_message_gone_off;
typedef struct alarm_full_message_set           alarm_full_message_set;
typedef struct alarm_full_message_cancel        alarm_full_message_cancel;
typedef struct alarm_full_message_gone_off      alarm_full_message_gone_off;

/********************
 * Type definitions *
 ********************/
typedef int alarm_reason;

struct alarm_date_and_time
   {  short year;
      byte month;
      byte date;
      byte hour;
      byte minute;
   };

struct alarm_message_set
   {  alarm_reason set_reason;
      union
      {  os_date_and_time utc;
         alarm_date_and_time local;
      }
      time;
      char sender [40];
      char alarm_name [40];
   };

struct alarm_message_cancel
   {  alarm_reason cancel;
      char sender [40];
      char alarm_name [40];
   };

struct alarm_message_gone_off
   {  char sender [40];
      char alarm_name [40];
   };

struct alarm_full_message_set
   {  wimp_MESSAGE_HEADER_MEMBERS
      alarm_reason set_reason;
      union
      {  os_date_and_time utc;
         alarm_date_and_time local;
      }
      time;
      char sender_name [40];
      char alarm_name [40];
   };

struct alarm_full_message_cancel
   {  wimp_MESSAGE_HEADER_MEMBERS
      alarm_reason cancel;
      char sender_name [40];
      char alarm_name [40];
   };

struct alarm_full_message_gone_off
   {  wimp_MESSAGE_HEADER_MEMBERS
      char sender_name [40];
      char alarm_name [40];
   };

/************************
 * Constant definitions *
 ************************/
#define alarm_NAME_LIMIT                        (40)
#define message_ALARM_SET                       0x500u
#define message_ALARM_GONE_OFF                  0x501u
#define alarm_REASON_SET_LOCAL                  ((alarm_reason) 0x0u)
#define alarm_REASON_SET_UTC                    ((alarm_reason) 0x1u)
#define alarm_REASON_CANCEL                     ((alarm_reason) 0x2u)

#if defined NAMESPACE_OSLIB
  } 
#endif

#endif
