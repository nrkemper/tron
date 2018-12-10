#include "tstdlib.h"

/*
 *
 *
 *    Standard library functions
 *
 *
 */

int T_strlen (const char* str)
{
	int cnt=0;

	while (*str++) cnt++;
	
	return cnt;
}

void T_strcpy (char* des, const char* src)
{
	while ((*des++ = *src++));
}

void T_strncpy (char* des, const char* src, int num)
{
	while ((*des++ = *src++) && num--);
}

char* T_strcat (char* des, const char* src)
{
	des += T_strlen(des);
	T_strcpy(des, src);

	return des;
}

char* T_strncat (char* des, const char* src, int num)
{
	des += T_strlen(des);
	T_strncpy (des, src, num);

	return des;
}

int T_strcmp (const char* str1, const char* str2)
{
	while (*str1 && *str2)
	{
		if (*str1 < *str2)
			return -1;
		
		if (*str1 > *str2)
			return 1;
		str1++;
		str2++;
	}

	return 0;
}

int T_strncmp (const char* str1, const char* str2, int num)
{
	while (*str1 && *str2 && num--)
	{
		if (*str1 < *str2)
			return -1;

		if (*str1 > *str2)
			return 1;

		str1++;
		str2++;
	}
	
	return 0;
}

int T_strcasecmp (const char* str1, const char* str2)
{
	while (*str1 && *str2)
	{
		if (*str1 < *str2)
		{
			if (*str2 >= 'a' && *str2 <= 'z')
			{
				if (*str1 < *str2 - 'a' + 'A')
					return -1;
			
				if (*str1 > *str2 - 'a' + 'A')
					return 1;
			}
			else
				return -1;

		}

		if (*str1 > *str2)
		{
			if (*str1 >= 'a' && *str1 <= 'z')
			{
				if (*str1 - 'a' + 'A' < *str2)
					return -1;

				if (*str1 - 'a' + 'A' > *str2)
					return 1;
			}
			else
				return 1;
		}
		str1++;
		str2++;
	}
	return 0;
}

int T_strncasecmp (const char* str1, const char* str2, int num);
