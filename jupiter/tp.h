/*********************************************************************

tp.h: header file for the text preprocessor.

Copyright (C) Karl Dahlke, 2011.
This software may be freely distributed under the GPL, general public license,
as articulated by the Free Software Foundation.

*********************************************************************/

#ifndef TP_H
#define TP_H 1

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "../bridge/acsbridge.h"

/* WORDLEN comes from acsbridge.h */
#define NEWWORDLEN 200 /* size of word or number after expansion */

struct textbuf {
	unsigned int *buf;
	acs_ofs_type *offset;
	unsigned short room;
	unsigned short len;
};

extern struct textbuf *tp_in, *tp_out;

extern char tp_acronUpper; /* acronym letters in upper case? */
extern char tp_acronDelim;
extern char tp_oneSymbol; /* read one symbol - not a sentence */
extern char tp_readLiteral; // read each punctuation mark
/* a convenient place to put little phrases to speak */
extern char shortPhrase[NEWWORDLEN];

/* prototypes */

/* sourcefile=tpxlate.c */
int setupTTS(void) ;
void textBufSwitch(void) ;
void textbufClose(const unsigned int *s, int overflow) ;
void speakChar(unsigned int c, int sayit, int bellsound, int asword) ;
void prepTTS(void) ;
unsigned int *prepTTSmsg(const char *msg) ;

#endif
