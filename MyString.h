
#ifndef  MY_STRING_H
#define MY_STRING_H

#include <stdlib.h> // we use size_t

void * MyString_memcpy_ascend (void * target, void const * source, size_t n);
void * MyString_memcpy (void * target, void const * source, size_t n);
void * MyString_memcpy_descend (void * target, void const * source, size_t n);
void * MyString_memmove (void * target, void const * source, size_t n);
void * MyString_memchr (void const * block, int value, size_t n);
char * MyString_strpbrk (char const string[], char const accept[]);
int    MyString_memcmp (void const * block1, void const * block2, size_t n);
void * MyString_memset (void * block, int value, size_t n);
size_t MyString_strlen (char const string[]);
char * MyString_strchr (char const string[], int character);
char * MyString_strrchr (char const string[], int character);

int    MyString_compareChar (char char1, char char2); 
size_t MyString_commonPrefixLength (char const string1[],
                                    char const string2[]);
size_t MyString_commonPrefixLengthUpTo (char const string1[], 
                                        char const string2[], 
                                        size_t max_length); 

int    MyString_strcmp (char const string1[], char const string2[]);
int    MyString_strncmp (char const string1[], char const string2[], size_t n);
char * MyString_strstr (char const string[], char const substring[]);
char * MyString_strcpy (char target[], char const source[]);
char * MyString_strncpy (char target[], char const source[], size_t n);
char * MyString_strcat (char target[], char const source[]);
char * MyString_strncat (char target[], char const source[], size_t n);
size_t MyString_strspn (char const string[], char const accept[]);
size_t MyString_strcspn (char const string[], char const reject[]);
char * MyString_strdup (char const string []);
char * MyString_strndup (char const string [], size_t n);

char * MyString_trim (char const string[], char const blanks[]);

#endif

