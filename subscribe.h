/*$Id$*/
#ifndef SUBSCRIBE_H
#define SUBSCRIBE_H

#include "stralloc.h"

/* these are the subroutines used for interfacing with the subscriber and  */
/* moderator address databases. For the put/to address output routines     */
/* the 'username' if defined is omitted from the output. flagadd = 1 adds  */
/* a subscriber, flagadd = 0 removes the address. To use e.g. a SQL data-  */
/* base for addresses, just replace these routines and rebuild ezmlm.      */

extern int subscribe(char *dir,char *username,int flagadd,char *from,
	char *event, int flagmysql, int forcehash,
	char *table_override, char *FATAL);

extern const char *issub(char *dir,char *username, char *table_override, char *FATAL);

extern unsigned long putsubs(char *dir,
	unsigned long hash_lo, unsigned long hash_hi,
	int subwrite(), int flagsql, char *fatal);

/*		int subwrite(char *string, unsigned int length); */

extern void tagmsg(char *dir, unsigned long msgnum,
	char *seed, char *action, char *hashout,
	unsigned long bodysize, unsigned long chunk, char *fatal);

extern const char *logmsg(char *dir, unsigned long msgnum, unsigned long,
	unsigned long subs, int done);

extern const char *checktag(char *dir, unsigned long msgnum, unsigned long listno,
	char *action, char *seed, char *hash);

extern void searchlog(char *dir, char *search, int subwrite(), char *fatal);

extern const char *opensql(char *dir, char **table);

extern void closesql();

extern void *psql;		/* contains SQL handle */
#endif
