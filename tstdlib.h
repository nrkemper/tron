#ifndef __TSTDLIB_H__
#define __TSTDLIB_H__
#pragma once

/*
 *
 *
 *    Standard library functions
 *
 *
 */
#define tboolean	unsigned char

int T_strlen (const char* str);
void T_strcpy (char* des, const char* src);
void T_strncpy (char* des, const char* src, int num);
char* T_strcat (char* des, const char* src);
char* T_strncat (char* des, const char* src, int num);
int T_strcmp (const char* str1, const char* str2);
int T_strncmp (const char* str1, const char* str2, int num);
int T_strcasecmp (const char* str1, const char* str2);
int T_strncasecmp (const char* str1, const char* str2, int num);
void* T_memset (void* ptr, int value, unsigned int num);
#endif
