/*
Developer && Owner: МогучийДД (MoguchiyDD)
LICENSE: MIT License which is located in the text file LICENSE

Goal: Write your own BINARY NUMBER for The Program
Result: Complete your own BINARY NUMBER for The Program

Past Modification: Adding DOCUMENTATION
Last Modification: Adding The «REVERSE» and «10->2» BLOCKS
Modification Date: 2024.03.24, 02:05 PM

Create Date: 2024.03.24, 01:56 PM
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary.h"
#include "../errors.h"

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError
 * @brief Reverse String | (Example, INPUT: 0101; OUTPUT: 1010)
 * @param *string String (Line, Word)
 * @returns Reverse String (Line, Word)
 */
static char* reverse_string(char *string) {
  int s = strlen(string),  // for ORIGINAL STRING
      cur = 0;  // for REVERSE STRING
  char *str = calloc(s + 1, sizeof(char));
  if (str == NULL) {
    printf("%s: While calculating a binary number, a memory overflow occurred. No further action is possible.\n", S_MEMORY_FULL);
    exit(D_MEMORY_FULL);
  }

  for (s; s >= 0; --s) {
    if (string[s] != '\0') {
      str[cur] = string[s];
      ++cur;
    }
  };
  str[cur] = '\0';
  return str;
}

// 
/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError
 * @brief Decimal to Binary | (Example, INPUT: 10; OUTPUT: 1010)
 * @param *number Number
 * @returns Binary Number
 */
char* db(char *number) {
  int decimal = atoi(number),  // Number
      size = 4,  // 1 byte (000 - 111) + '\0'
      mSize = 3,  // for MEMORY EXPANSION
      div = 1,  // Division without Remainder
      mod = -1,  // Remainder of Division
      s = 0;  // for LOOP

  char *d = calloc(size, sizeof(char)), *result;
  if (d == NULL) {
    printf("%s: While calculating a binary number, a memory overflow occurred. No further action is possible.\n", S_MEMORY_FULL);
    exit(D_MEMORY_FULL);
  }

  for (s; div >= 1; ++s) {
    if (s == mSize) {  // Memory Expansion
      size += sizeof(int);
      mSize = size - 1;
      d = realloc(d, size);
      if (d == NULL) {
        free(d);
        printf("%s: While calculating a binary number, a memory overflow occurred. No further action is possible.\n", S_MEMORY_FULL);
        exit(D_MEMORY_FULL);
      }
    }

    div = decimal / 2;
    mod = decimal % 2;
    decimal = div;

    if (mod != 0) {
      d[s] = '1';
    } else {
      d[s] = '0';
    }
  }

  d[s] = '\0';
  result = reverse_string(d);
  free(d);

  return result;
}
