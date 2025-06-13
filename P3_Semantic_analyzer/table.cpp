#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "proj2.h"
#include "y.tab.h"

extern "C" int yyleng;

#define STRTBL_LEN 3001      /* String table length */
#define STR_SPRTR  0         /* String seperator in string table */

static std::unordered_map<std::string, int> hashTable;  /* Hash table mapping strings to indices in the string table */
static char stringTable[STRTBL_LEN] = {STR_SPRTR};      /* String table of length STRTBL_LEN */
static int stringTableEndIndex = 0;                    /* End of the string table */
using namespace std;
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

/** If text is found in string table, assign the index of the string to the lexeme (yylval).
 *  
 * If text is not found in string table, add text to end of string table.
 * Also, add the STR_SPRTR character to separate the string from the next string.
 * Lastly, assign the index where text was added to the lexeme (yylval).
 *
 * @param text - String to add to string table.
 * @param tokenType - The type of token (either SCONSTnum or IDnum).
 */

extern "C" void addStringTable(char *text, int tokenType)
{
  string sText;
  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] != '\'') {
      sText += text[i];
    }
  }
  
  if (hashTable.find(sText) != hashTable.end()) 
  {
    //if find, just assign lexeme to yylval.intg 
      yylval.intg = hashTable[sText];
  } 
  else 
  {
    int needed_space = strlen(sText.c_str()) + 1; // fisrt check how many space we need, which is the lengh of the text + 1 for the seperate char
    if (stringTableEndIndex + needed_space >= STRTBL_LEN) 
    {
      fprintf(stderr, "Error: String table overflow.\n");
      return;
    }

    yylval.intg = stringTableEndIndex; // Assign the index to the lexeme
    hashTable[sText] = stringTableEndIndex; // Assign new index
    strcpy(&stringTable[stringTableEndIndex], sText.c_str()); // Add the text into the string table
    stringTableEndIndex += needed_space; // Move the end index by the length of the new text + separator
    stringTable[stringTableEndIndex] = STR_SPRTR; // Add the separator
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

const char* getString(int index)
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

/** Returns the index in the string table where the given text is.
 *  
 * If the text is not found in the string table, returns -1.
 *
 * @param text - The string to search for in the string table.
 * 
 * @return Index into the string table where the string was found.  -1 if not found.
 */

int getIndex(const char* text)
{
   /* TODO: Implement function as described in above comment. */
  string sText(text);
  if(hashTable.find(sText) != hashTable.end())
  {
    return hashTable[sText];
  }
  return -1;
}