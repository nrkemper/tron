#include "tstdlib.h"
#define NULL	0
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
	char tmpch1, tmpch2;

	while (*str1 && *str2)
	{
		tmpch1 = *str1;
		tmpch2 = *str2;
		if ((tmpch1 >= 'a' && tmpch1 <= 'z') || (tmpch1 >= 'A' && tmpch1 <= 'Z'))
		{
			if ((tmpch2 >= 'a' && tmpch2 <= 'z') || (tmpch2 >= 'A' && tmpch2 <= 'Z'))
			{
				if (tmpch1 >= 'a' && tmpch1 <='z')
					tmpch1 = tmpch1 - 'a' + 'A';

				if (tmpch2 >= 'a' && tmpch2 <= 'z')
					tmpch2 = tmpch2 - 'a' + 'A';
			}
		}

		if (tmpch1 < tmpch2)
			return -1;

		if (tmpch1 > tmpch2)
			return 1;

		str1++;
		str2++;
	}
	return 0;
}

int T_strncasecmp (const char* str1, const char* str2, int num)
{
	char tmpch1, tmpch2;

	while (*str1 && *str2 && num--)
	{
		tmpch1 = *str1;
		tmpch2 = *str2;
		if ((tmpch1 >= 'a' && tmpch1 <= 'z') || (tmpch1 >= 'A' && tmpch1 <= 'Z'))
		{
			if ((tmpch2 >= 'a' && tmpch2 <= 'z') || (tmpch2 >= 'A' && tmpch2 <= 'Z'))
			{
				if (tmpch1 >= 'a' && tmpch1 <='z')
					tmpch1 = tmpch1 - 'a' + 'A';

				if (tmpch2 >= 'a' && tmpch2 <= 'z')
					tmpch2 = tmpch2 - 'a' + 'A';
			}
		}

		if (tmpch1 < tmpch2)
			return -1;

		if (tmpch1 > tmpch2)
			return 1;

		str1++;
		str2++;
	}
	return 0;
}

void* T_memset (void* ptr, int value, unsigned int num)
{
	if (ptr != NULL)
	{
		unsigned char* tmpp = ptr;
		while (num--)
		{
			*tmpp++ = value;
		}
	}
	return ptr;
}
