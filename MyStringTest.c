#include "MyStringTest.h"
#include "MyString.h"

#include <assert.h>
#include <string.h>
#include <stdio.h>

//==============================================================================
// memcpy()
//==============================================================================

void
MyStringTest_memcpy_ascend (void)
{
}

void
MyStringTest_memcpy_descend (void)
{
}

//==============================================================================
// memmove()
//==============================================================================

void
MyStringTest_memmove (void)
{

}

//==============================================================================
// memchr()
//==============================================================================

void
MyStringTest_memchr (void)
{
}

//==============================================================================
// strpbrk()
//==============================================================================

void
MyStringTest_strpbrk (void)
{
  char text[]= "mic mac\n";
  char accept[]= " \n";
  char * occ1= MyString_strpbrk (text  , accept); assert (occ1 == text+3);
  char * occ2= MyString_strpbrk (occ1+1, accept); assert (occ2 == text+7);
  char * occ3= MyString_strpbrk (occ2+1, accept); assert (occ3 == NULL);
  
}

//==============================================================================
// memcmp()
//==============================================================================

void
MyStringTest_memcmp (void)
{
  unsigned char bytes1[]= { 0xDE, 0xAD, 0xBE, 0xEF };
  unsigned char bytes2[]= { 0xDE, 0xAD, 0xF0, 0x0D };

  assert (MyString_memcmp (bytes1, bytes2, 4) <  0);
  assert (MyString_memcmp (bytes2, bytes1, 4) >  0);

  assert (MyString_memcmp (bytes1, bytes2, 2) == 0);
  assert (MyString_memcmp (bytes2, bytes1, 2) == 0);

  assert (MyString_memcmp (bytes1, bytes1, 4) == 0);
  assert (MyString_memcmp (bytes2, bytes2, 4) == 0);
}

//==============================================================================
// memset()
//==============================================================================

void
MyStringTest_memset (void)
{
}

//==============================================================================
// strlen()
//==============================================================================

void
MyStringTest_strlen (void)
{
  assert (MyString_strlen ("banana") == 6);
  assert (MyString_strlen ("x") == 1);
  assert (MyString_strlen ("") == 0);
  assert (MyString_strlen ("eddy") == 4);
}

//==============================================================================
// strchr()
//==============================================================================

void
MyStringTest_strchr (void)
{
  char text[]= "banana";
  assert (MyString_strchr (text, '\0') == text+6);
  assert (MyString_strchr (text, 'n')  == text+2);  
  assert (MyString_strchr (text, 'x')  == NULL);
}

//==============================================================================
// strrchr()
//==============================================================================

void
MyStringTest_strrchr (void)
{
  char text[]= "banana";
  assert (MyString_strrchr (text, '\0') == text+6);
  assert (MyString_strrchr (text, 'n' ) == text+4);  
  assert (MyString_strrchr (text, 'x' ) == NULL);
}

//==============================================================================
// strcmp()
//==============================================================================

void
MyStringTest_compareChar (void)
{
  assert (MyString_compareChar ('a', 'z') <  0);
  assert (MyString_compareChar ('a', 'a') == 0);
  assert (MyString_compareChar ('z', 'a') >  0);
  
  assert (MyString_compareChar ('z', '\xe9') < 0);
}

void
MyStringTest_commonPrefixLength (void)
{
  assert (MyString_commonPrefixLength ("banana", "banker")     == 3);
  assert (MyString_commonPrefixLength ("banana", "ban")     == 3);

  assert (MyString_commonPrefixLength ("banana", "bananarama") == 6);
  assert (MyString_commonPrefixLength ("bananarama", "banana") == 6);
  assert (MyString_commonPrefixLength ("banana", "banana")     == 6);

  assert (MyString_commonPrefixLength ("apple", "banana") == 0);
  assert (MyString_commonPrefixLength ("apple", "")       == 0);
  assert (MyString_commonPrefixLength ("", "apple")       == 0);
  assert (MyString_commonPrefixLength ("", "")            == 0);
}

void
MyStringTest_strcmp (void)
{
  assert (MyString_strcmp ("banana", "banker") <  0);
  assert (MyString_strcmp ("banana", "banana") == 0);
  assert (MyString_strcmp ("banker", "banana") >  0);

  assert (MyString_strcmp ("banana", "bananarama") < 0);
  assert (MyString_strcmp ("bananarama", "banana") > 0);

  assert (MyString_strcmp ("", "apple") <  0);
  assert (MyString_strcmp ("", ""     ) == 0);
  assert (MyString_strcmp ("apple", "") >  0);
}

//==============================================================================
// strncmp()
//==============================================================================

void
MyStringTest_commonPrefixLengthUpTo (void)
{
  assert (MyString_commonPrefixLengthUpTo ("banana", "banana",  4)  == 4);
  assert (MyString_commonPrefixLengthUpTo ("banana", "banker",  4)  == 3);
  assert (MyString_commonPrefixLengthUpTo ("banana", "ban",    10)  == 3);
  assert (MyString_commonPrefixLengthUpTo ("ban", "banana",    10)  == 3);
}

void
MyStringTest_strncmp (void) {
  assert (MyString_strncmp ("banana", "banker", 3) ==  0);
  assert (MyString_strncmp ("banana", "banker", 4) < 0);
  assert (MyString_strncmp ("banker", "banana", 4) >  0);

  assert (MyString_strncmp ("ban", "banana", 10) <  0);
  assert (MyString_strncmp ("banana", "ban",  3) == 0);
  assert (MyString_strncmp ("ban", "banana",  3) == 0);
  assert (MyString_strncmp ("banana", "ban", 10) >  0);
  assert (strcmp("Regis Barbanchon", "Regis Barbanchon") == 0);
}

//==============================================================================
// strstr()
//==============================================================================

void
MyStringTest_strstr (void)
{ 
  char text[]= "banana";
  assert (MyString_strstr (text, "banana") == text+0);
  assert (MyString_strstr (text, "ban")    == text+0);
  assert (MyString_strstr (text, "")       == text+0);
  assert (MyString_strstr (text, "nana")   == text+2);
  assert (MyString_strstr (text, "anan")   == text+1);
  
  assert (MyString_strstr (text, "bananarama") == NULL);
  assert (MyString_strstr (text, "bank")       == NULL); 
}

//==============================================================================
// strcpy()
//==============================================================================

void
MyStringTest_strcpy (void) {
  char source[]= "banana";
  size_t length= strlen (source);
  char target[length+1];
  char * result= MyString_strcpy (target, source);
  assert (result == target && strcmp (source, target) == 0);
}

//==============================================================================
// strncpy()
//==============================================================================

void
MyStringTest_strncpy (void)
{
  char text1[]= "xxxxxxxxxx";
  char * result1= MyString_strncpy (text1, "Regis", 3);
  assert (result1 == text1 && memcmp(text1, "Regxxxxxxx", 10) == 0);
  char text2[]= "xxxxxxxxxx";
  char * result2= MyString_strncpy (text2, "Regis", 8);
  assert (result2 == text2 && memcmp(text2, "Regis\0\0\0xx", 10) == 0);
}

//==============================================================================
// strcat()
//==============================================================================

void
MyStringTest_strcat (void)
{ 
  char text[100]= "Regis";
  char * result= MyString_strcat (text, " Barbanchon");
  assert (result == text &&  strcmp(text, "Regis Barbanchon") == 0);
}

//==============================================================================
//  strncat()
//==============================================================================

void
MyStringTest_strncat (void)
{
  char text1[100]= "Regis";
  char * result1= MyString_strncat (text1, " Barbanchon", 100);
  assert (result1 == text1 && strcmp (text1, "Regis Barbanchon") == 0);
  char text2[100]= "Regis";
  char * result2= MyString_strncat (text2, " Barbanchon", 4);
  assert (result2 == text2 && strcmp (text2, "Regis Bar") == 0);
}

//==============================================================================
// strspn()
//==============================================================================

void
MyStringTest_strspn (void)
{
  assert (MyString_strspn ("745.99", "0123456789") == 3);
  assert (MyString_strspn ("745"   , "0123456789") == 3);
  assert (MyString_strspn ("+45.99", "0123456789") == 0);
}

//==============================================================================
// strcspn()
//==============================================================================

void
MyStringTest_strcspn (void)
{
  assert (MyString_strcspn ("799.50", ".,") == 3);
  assert (MyString_strcspn ("799,50", ".,") == 3);
  assert (MyString_strcspn ("799"   , ".,") == 3);
  assert (MyString_strcspn (".99"   , ".,") == 0);
}

//==============================================================================
//  strdup()
//==============================================================================

void
MyStringTest_strdup (void)
{
  char text[]= "totolitoto";
  char * copy= MyString_strdup (text);
  assert (strcmp (copy, text) == 0);
  free (copy);
}

//==============================================================================
// strndup()
//=============================================================================

void
MyStringTest_strndup (void)
{
  char text[]= "totolitoto";
  char * copy4= MyString_strndup (text, 4);
  assert (copy4 != NULL && strcmp (copy4, "toto") == 0);
  free (copy4);
  char * copy100= MyString_strndup (text, 100);
  assert (copy100 != NULL && strcmp (copy100, text) == 0);
  free (copy100);
}

//==============================================================================
// strndup()
//=============================================================================

void
MyStringTest_trim (void)
{
    char blanks[]= " \n\t"; 
  {
    char * trimmed= MyString_trim ("Regis Barbanchon", blanks);
    assert (strcmp (trimmed, "Regis Barbanchon") == 0);
    free (trimmed);
  } {
    char * trimmed= MyString_trim ("  \n \t  Regis Barbanchon", blanks);
    assert (strcmp (trimmed, "Regis Barbanchon") == 0);
    free (trimmed);
  } {
    char * trimmed= MyString_trim ("Regis Barbanchon \n  \t  ", blanks);
     assert (strcmp (trimmed, "Regis Barbanchon") == 0);
     free (trimmed);
  } {
    char * trimmed= MyString_trim ("\n \t Regis Barbanchon \n \t ", blanks);
    assert (strcmp (trimmed, "Regis Barbanchon") == 0);
    free (trimmed);
  }
}

//==============================================================================
// MyStringTest
//==============================================================================

void
MyStringTest_runAll (void)
{
  fprintf (stderr, "MyStringTest_runAll(): "); fflush (stderr);

  MyStringTest_memchr();
  MyStringTest_memset();
  MyStringTest_memcmp();

  MyStringTest_memcpy_ascend();
  MyStringTest_memcpy_descend();
  MyStringTest_memmove();

  MyStringTest_strlen();
  MyStringTest_strchr(); 
  MyStringTest_strrchr();
  MyStringTest_strpbrk();

  MyStringTest_compareChar ();
  MyStringTest_commonPrefixLength();
  MyStringTest_strcmp();

  MyStringTest_commonPrefixLengthUpTo();
  MyStringTest_strncmp();

  MyStringTest_strstr();
  MyStringTest_strspn(); 
  MyStringTest_strcspn();

  MyStringTest_strcpy(); 
  MyStringTest_strncpy();
  MyStringTest_strcat(); 
  MyStringTest_strncat();

  MyStringTest_strdup(); 
  MyStringTest_strndup();

  MyStringTest_trim();
  fprintf(stderr, "all tests passed.\n");
}
