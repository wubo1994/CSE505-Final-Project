#include "api.h"
#include </usr/local/Cellar/swi-prolog/8.0.3_1/libexec/lib/swipl/include/SWI-Prolog.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char **argv)
{
	if(argc != 3) {
		printf("Please pass in correct arguments.\n");
		return 0;
	}
	char *rstring;
	char *plav[3];
	int num = atoi(argv[2]);
	int rval;
	term_t a0;
	static predicate_t p;
	plav[0] = argv[0];
	plav[1] = (char*)"-x";
	plav[2] = (char*)"dialog";
	printf("Before initialize.\n");
	if(!PL_initialise(3, plav)) {
		printf("Initialize prolog failed.\n");
		a0 = PL_new_term_refs(2);
		return 0;
	}
	printf("Initialize prolog succeeded.\n");
	if(!strcmp(argv[1], "rand"))
		p = PL_predicate("show_rand", 2, NULL);
	else if(!strcmp(argv[1], "nat"))
		p = PL_predicate("show_nat", 2, NULL);
	else if(!strcmp(argv[1], "pos"))
		p = PL_predicate("show_pos", 2, NULL);
	else if(!strcmp(argv[1], "neg"))
		p = PL_predicate("show_neg", 2, NULL);
	PL_put_integer(a0, num);
  	//PL_open_query(NULL, PL_Q_NORMAL, p, a0);
	PL_call_predicate(NULL, PL_Q_NORMAL, p, a0);
	rval = PL_get_chars(a0+1, &rstring, CVT_WRITE);
	printf("The result: %s.\n", rstring);
	return 1;
}
