

#define	FALSE	0
#define TRUE	1
#define	LINE_LEN	512
#define MAX_ARGS	64
#define MAX_ARG_LEN	16
#define	MAX_PATHS	64
#define MAX_PATH_LEN	512
#define WHITESPACE	" .,\t"

#ifndef NULL
#define	NULL	0
#endif


char username1[]="shell1";
char password1[]="123";

char username2[]="shell2";
char password2[]="123";

char username3[]="shell3";
char password3[]="123";

struct command_t 
{
  char *name;			// --> onoma entolhs
  int argc;				// --> Arithmos parametrwn
  char *argv[MAX_ARGS];	// --> Parametroi
};

