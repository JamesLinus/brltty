/*
 * BRLTTY - Access software for Unix for a blind person
 *          using a soft Braille terminal
 *
 * Copyright (C) 1995-2000 by The BRLTTY Team, All rights reserved.
 *
 * Nicolas Pitre <nico@cam.org>
 * St�phane Doyon <s.doyon@videotron.ca>
 * Nikhil Nair <nn201@cus.cam.ac.uk>
 *
 * BRLTTY comes with ABSOLUTELY NO WARRANTY.
 *
 * This is free software, placed under the terms of the
 * GNU General Public License, as published by the Free Software
 * Foundation.  Please see the file COPYING for details.
 */

/* This Driver was written as a project in the
 *   HTL W1, Abteilung Elektrotechnik, Wien - �sterreich
 *   (Technical High School, Department for electrical engineering,
 *     Vienna, Austria)
 *  by
 *   Tibor Becker
 *   Michael Burger
 *   Herbert Gruber
 *   Heimo Sch�n
 * Teacher:
 *   August H�randl <hoerandl@elina.htlw1.ac.at>
 *
 * papenmeier/brlconf.h - Braille display library for Papenmeier Screen 2D
 *
 * Edit as necessary for your system.
 */

/* So far, there is only support for serial communications, and
 * only the builtin table is used for character translation
 */

#define BRLNAME	"Papenmeier"

#define BRLCOLS	80
#define BRLROWS	1

#define BAUDRATE B19200

/* codes used in protocoll */
#define cSTX 02
#define cETX 03
#define cIdSend 'S'
#define cIdReceive 'K'
#define PRESSED 1

/* number of status cells */
#define PMSC 22

/* offset within data structure */
#define offsetHorizontal 22
#define offsetVertical   0
/* additional offset - use internal table */
#define offsetTable      512

/* debug output to /tmp/brltty.log */
#undef WR_DEBUG
#undef RD_DEBUG
/*
  #define WR_DEBUG
  #define RD_DEBUG
*/

/* Define the preferred/default status cells mode. */
#define PREFSTYLE ST_Papenmeier