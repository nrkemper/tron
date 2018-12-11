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

	
	char colon[2] = ":";
	char star[2] = "*";
	char a[2] = "a";
	char K[2] = "K";
	char backslash[2] = "\\";

	if (T_strcasecmp (colon, star) == 1)
		printf ("Correct! The colon has a greater value than the star.\n");
	else
		printf ("Ugh oh! The colon is supposed to have a greater value than the star.\n");
	
	
	if (T_strcasecmp (star, colon) == -1)
		printf ("Correct! The star has a lesser value than the colon.\n");
	else
		printf ("Ugh oh! The star is supposed to have a lesser value than the colon.\n");
	
	if (T_strcasecmp (a, K) == -1)
		printf ("Correct! 'a' has a lesser value than 'K'\n");
	else
		printf ("Ugh oh! 'a' is supposed to have a lesser value than 'K'\n");

	if (T_strcasecmp (K, a) == 1)
		printf ("Correct! 'K' has a greater value than 'a'\n");
	else
		printf ("Ugh oh! 'K' is supposed to have a greater value than 'a'\n");

	if (T_strcasecmp (a, colon) == 1)
		printf ("Correct! 'a' has a greater value than the colon\n");
	else
		printf ("Ugh oh! 'a' is supposed to have a greater value than the colon\n");

	if (T_strcasecmp (colon, a) == -1)
		printf ("Correct! The colon has a lesser value than 'a'\n");
	else
		printf ("Ugh oh! The colon is supposed to have a lesser value than 'a'\n");

	if (T_strcasecmp (backslash, K) == 1)
		printf ("Correct! The backslash is supposed to have a greater value than 'K'\n");
	else 
		printf ("Ugh oh! The backslash is supposed to have a greater value than 'K'\n");
	
	if (T_strcasecmp (K, backslash) == -1)
		printf ("Correct! The backslash is supposed to have a greater value than 'K'\n");
	else 
		printf ("Ugh oh! The backslash is supposed to have a greater value than 'K'\n");
	
	if (T_strcasecmp (backslash, a) == -1)
		printf ("Correct! 'a' is supposed to have a greater value than the backslash\n");
	else 
		printf ("Ugh oh! 'a' is supposed to have a greater value than the backslash\n");
	
	if (T_strcasecmp (a, backslash) == 1)
		printf ("Correct! 'a' is supposed to have a greater value than the backslash\n");
	else 
		printf ("Ugh oh! 'a' is supposed to have a greater value than the backslash\n");
	
	if (T_strcasecmp (K, backslash) == -1)
		printf ("Correct! 'K' is supposed to have a lesser value than the backslash.\n");
	else
		printf ("Ugh oh! 'K' is supposed to have a lesser value than the backslash.\n");

	if (T_strcasecmp (backslash, K) == 1)
		printf ("Correct! The backslash is supposed to have a greater value than 'K'.\n");
	else
		printf ("Ugh oh! The backslash is supposed to have a greater value than 'K'.\n");

	T_memset (string, 0, T_strlen(string));

	printf ("String: '%s'\n", string);
	return 0;
}
