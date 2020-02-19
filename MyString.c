#include "MyString.h"
#include <stdio.h>

size_t MyString_strlen (char const string[]) {
    size_t length = 0;
    while (string[length] != '\0') length++;
    return length;
}

char * MyString_strchr(char const string[], int character) {
  if (character == '\0') {
    return (char *) string + MyString_strlen(string);
  }
  for (size_t index = 0; string[index] != '\0'; index++) {
    if (string[index] == character) {
      return (char *) string + index;
    } 
  }
  return NULL;
}

char * MyString_strrchr(char const string[], int character) {
  if (character == '\0') {
    return (char *) string + MyString_strlen(string);
  }
  char const * last_found = NULL;
  for (size_t index = 0; string[index] != '\0'; index++) {
    if (string[index] == character) {
      last_found = (char *) string + index; //&string[index]
    } 
  }
  return (char *) last_found;
}

char * MyString_strpbrk ( char const string [] , char const accept []) {
    if (accept[0] == '\0') {
    return (char *) string + MyString_strlen(string);
  }
  for (size_t index = 0; string[index] != '\0'; index++) {
    for (size_t index_accept = 0; accept[index_accept] != '\0'; index_accept++) {
      if (string[index] == accept[index_accept]) {
        return (char *) string + index; 
      } 
    }
  }
  return NULL;
}

int MyString_compareChar ( char char1 , char char2 ) {
  unsigned char uchar1 = char1;
  unsigned char uchar2 = char2;
  return uchar1 - uchar2;
}

size_t MyString_commonPrefixLength ( char const s1 [] , char const s2 []) {
  size_t index;
  for(index = 0; s1[index] != '\0' && s2[index] != '\0'; index++) {
    if(MyString_compareChar(s1[index], s2[index]) != 0) break;
  }
  return index;
}

size_t MyString_commonPrefixLengthUpTo ( char const s1 [] , char const s2 [] , size_t n ) {
  size_t index;
  for(index = 0; s1[index] != '\0' && s2[index] != '\0' && index<n; index++) {
    if(MyString_compareChar(s1[index], s2[index]) != 0) break;
  }
  return index;
}

int MyString_strcmp (char const string1 [] , char const string2 []) {
  size_t prefixLength = MyString_commonPrefixLength(string1, string2);
  return MyString_compareChar(string1[prefixLength], string2[prefixLength]);
}

int MyString_strncmp ( char const string1 [] , char const string2 [] , size_t n ) {
  size_t prefixLength = MyString_commonPrefixLengthUpTo(string1, string2, n);
  if(prefixLength == n) return 0;
  return MyString_compareChar(string1[prefixLength], string2[prefixLength]);
}

//todo
char * MyString_strstr ( char const string [] , char const substring []) {
  size_t lengthStr = MyString_strlen(string);
  size_t lengthSub = MyString_strlen(substring);
  if(lengthStr < lengthSub) return NULL;
  for (size_t index = 0; index < lengthStr; index++) {
    if (MyString_commonPrefixLength(substring, string+index) == lengthSub) return (char *) string + index;
  }
  return NULL;
}

char * MyString_strcpy ( char target [] , char const source []) {
  for (size_t i = 0; i<MyString_strlen(source); i++) {
    target[i] = source[i];
  }
  return (char *) target;
}

char * MyString_strncpy ( char target [] , char const source [] , size_t n ) {
  size_t length = MyString_strlen(source);
  for (size_t i = 0; i<n; i++) {
    if(i<length) { target[i] = source[i]; }
    else { target[i] = '\0'; }
  }
  return (char *) target;
}

char * MyString_strcat ( char target [] , char const source []) {
  size_t length = MyString_strlen(target);
  MyString_strcpy(target+length, source);
  return target;
}

char * MyString_strncat ( char target [] , char const source [], size_t n) {
  size_t length = MyString_strlen(target);
  size_t index;
  for (index = 0;  source[index] != '\0' && index < n; index++) {
    target[length+index] = source[index];
  }
  target[length + index] = '\0';
  return target;
}

size_t MyString_strspn ( char const string [] , char const accept []) {
  size_t index;
  for (index = 0; string[index] != '\0'; index++) {
    if (MyString_strchr(accept, string[index]) == NULL) break;
  }
  return index;
}

size_t MyString_strcspn ( char const string [] , char const reject []) {
  size_t index;
  for (index = 0; string[index] != '\0'; index++) {
    if (MyString_strchr(reject, string[index]) != NULL) break;
  }
  return index;
}

char * MyString_strdup ( char const string []) {
  char * output = (char *) malloc((MyString_strlen(string)+1)*sizeof *output);
  if (output == NULL) return NULL;
  MyString_strcpy(output, string);
  return output;
}

char * MyString_strndup ( char const string [], size_t max_length) {
  size_t index = 0;
  for (index= 0; index < max_length; index++) {
    if (string[index] == '\0') break;
  } size_t length = index;
  char * output = (char *) malloc((MyString_strlen(string)+1)*sizeof *output);
  if (output == NULL) return NULL;
  MyString_strncpy(output, string, length);
  output[index] = '\0';
  return output;
}

char * MyString_trim ( char const string [] , char const blanks []) {
  size_t left = MyString_strspn(string, blanks);
  char const * start = string + left;
  size_t length = MyString_strlen(start);
  if (length == 0) return MyString_strdup("");
  while (length > 0 && MyString_strchr(blanks, start[length-1]) != NULL) {
    length--;
  }
  return MyString_strndup(start, length);
}

int MyString_memcmp ( const void * memory1 , const void * memory2 , size_t n ) {
  if (memory1 == memory2) return 0;
  unsigned char const *bytes1 = memory1;
  unsigned char const *bytes2 = memory2;
  for(size_t index = 0; index <n; index++) {
    if (bytes1[index] != bytes2[index]) return bytes1[index] - bytes2[index];
  }
  return 0;
}