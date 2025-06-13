#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include "proj2.h"
#include "y.tab.h"

extern "C" int yyleng;

#define STRTBL_LEN 3001      /* String table length */
#define STR_SPRTR  0         /* String seperator in string table */

static std::unordered_map<std::string, int> hashTable;  /* Hash table mapping strings to indices in the string table */
static char stringTable[STRTBL_LEN] = {STR_SPRTR};      /* String table of length STRTBL_LEN */
static int stringTableEndIndex = 0;                    /* End of the string table */

/* TODO: Add additional variable definitions as needed. */

extern "C" void printStringTable()
{
  int i;
  for (i = 0; i < stringTableEndIndex; i++)
  {
    if (stringTable[i] == STR_SPRTR)
      printf(" ");
    else
      printf("%c", stringTable[i]);
  }
  printf("\n");
}

/** If text is found in string table, assign the index of the string to the lexeme (yylval.intg).
 *  
 * If text is not found in string table, add text to end of string table.
 * Also, add the STR_SPRTR character to separate the string from the next string.
 * Lastly, assign the index where text was added to the lexeme (yylval.intg).
 *
 * @param text - String to add to string table.
 * @param tokenType - The type of token (either SCONSTnum or IDnum).
 */

extern "C" void addStringTable(char *text, int tokenType)
{
  std::string sText(text); //change the text to string since the hashtable is string,int
  
  if (hashTable.find(sText) != hashTable.end()) 
  {
    //if find, just assign lexeme to yylval.intg 
      yylval.intg = hashTable[sText];
  } 
  else 
  {
    int needed_space = strlen(text) + 1; // fisrt check how many space we need, which is the lengh of the text + 1 for the seperate char
    if (stringTableEndIndex + needed_space >= STRTBL_LEN) 
    {
      fprintf(stderr, "Error: String table overflow.\n");
      return;
    }

    yylval.intg = stringTableEndIndex;//assign the index to the lexeme
    hashTable[sText] = stringTableEndIndex;//assign new index
    strcpy(&stringTable[stringTableEndIndex], text);//if we have enough sapce, just add the text into the string table
    stringTableEndIndex += needed_space; // move the end index by te length of the new text + seperator
    stringTable[stringTableEndIndex] = STR_SPRTR;// add the seperator
  }
}

/** Returns a pointer to the string that is at the given index of the string table.
 *  
 * If index is out of bounds of the string table, returns null.
 *
 * @param index - Index of string in the string table.
 * 
 * @return Pointer to the string in the index.
 */

extern "C" char* getString(int index)
{
   /* TODO: Implement function as described in above comment. */
   if(index >= STRTBL_LEN || index < 0)
   {
    return NULL;
   }
   else
   {
    char* key = &stringTable[index];
    return key;
   }
}