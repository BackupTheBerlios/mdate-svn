/* lang.hh: Copyright (C) 2003-2004 Sean Dwyer <ewe2@users.sourceforge.net>
 * under GPL
 */
#ifndef _lang_hh
#define _lang_hh

/* $Id: lang.hh 17 2004-06-14 14:19:59Z ewe2 $ */
 
extern const char* helptext;

extern const char* MSG_CERR;
extern const char* MSG_DERR;
extern const char* MSG_JERR;
extern const char* MSG_LERR;
extern const char* MSG_OPTERR;
extern const char* MSG_NONOPTERR;
extern const char* MSG_LONGERR;
extern const char* MSG_GENERR;
extern const char* MSG_ILC;
extern const char* MSG_IGD;
extern const char* MSG_IJDN;
extern const char* MSG_FORMATERR;

extern const char* pretty_format;
extern const char* default_format;

extern const char** short_days;
extern const char** days;

int set_lang(const char *lang);

#endif
