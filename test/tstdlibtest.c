#include "../tstdlib.h"
#include <stdio.h>

int main (void)
{
	char string[100] = "This is a ";
	char string2[100] = "very very long string";
	char name[100] = "Nick Kemp";	
	char buffer[100];
	
	T_strcat (string, string2);
	T_strcpy (buffer, string);

	if (T_strcasecmp (string, buffer) == 0)
		printf ("The two strings are the same!\n");
	else
		printf ("Ugh oh! There's an error in my program.\n");


	printf ("string: '%s'\n", string);
	printf ("buffer: '%s'\n", buffer);
	printf ("string length: %d\n", T_strlen (string));
	printf ("string length: %d\n", T_strlen (name));
	
	
	char newstr1[100] = "ThIs iS A New StrIng\n";
	char newstr2[100] = "tHIs Is A nEw sTRInG\n";

	if (T_strcasecmp (newstr1, newstr2) == 0)
		printf ("The two NEW strings are the same!\n");
	else
		printf ("Ugh oh. There's an error in my code. The strings aren't the same :(\n");
	
	char newnewstr1[100] = "ThESe ArE COmPleteLy dIFfeRenT StRings\n";
	char newnewstr2[100] = "CoMPleteLy DiffereNt StRinGs TheSe ArE\n";

	if (T_strcasecmp (newnewstr1, newnewstr2) == 0)
		printf ("Ugh oh. There's an error in my code. The two NEW NEW strings aren't supposed to be the same :(\n");
	else
		printf ("The two NEW NEW strings are completely different!\n");

	return 0;
}
