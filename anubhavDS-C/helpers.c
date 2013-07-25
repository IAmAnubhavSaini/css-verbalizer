/* July, 2013 - onwards
 * Anubhav Saini
 * github.com/iamanubhavsaini/anubhavDS-C
 * 
 * Purpose
 * ==================================================
 * Contains helpers that are frequently used.
 *
 */

#ifndef ADS_HELPERS
#define ADS_HELPERS

#ifdef LOWER(c) 
#undef LOWER(c)
#endif
#ifdef UPPER(c)
#undef UPPER(c)
#endif
#ifdef ISALPHA(c)
#undef ISALPHA(c)
#endif
#ifdef ISNUM(c)
#undef ISNUM(c)
#endif
#ifdef ISALPHANUM(c)
#undef ISALPHANUM(c)
#endif

#define LOWER(c) 				(unsigned char)(c | 0x20)
#define UPPER(c) 				(unsigned char)((int)LOWER(c) - 0x20)
#define ISAPLHA(c) 				(LOWER(c) >= 'a' && LOWER(c) <= 'z' )
#define ISNUM(c)				(c >= '0' && c <= '9')
#define ISALPHANUM(c)			(ISALPHA(c) || ISNUM(c))

#endif