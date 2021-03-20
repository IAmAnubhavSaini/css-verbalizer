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

#define LOWER(c)                (unsigned char)(c | 0x20)
#define UPPER(c)                (unsigned char)((int)LOWER(c) - 0x20)
#define ISAPLHA(c)              (LOWER(c) >= 'a' && LOWER(c) <= 'z' )
#define ISNUM(c)                (c >= '0' && c <= '9')
#define ISALPHANUM(c)           (ISALPHA(c) || ISNUM(c))

#endif
