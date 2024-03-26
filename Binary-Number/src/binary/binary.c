/*
Developer && Owner: МогучийДД (MoguchiyDD)
LICENSE: MIT License which is located in the text file LICENSE

Goal: Write your own BINARY NUMBER for The Program
Result: Complete your own BINARY NUMBER for The Program

Past Modification: Adding The «REVERSE» and «10->2» BLOCKS
Last Modification: Adding a VALIDATION for Numbers
Modification Date: 2024.03.26, 05:48 PM

Create Date: 2024.03.24, 01:56 PM
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary.h"
#include "../errors.h"

#ifndef BINARY_FILE_C
  #define BINARY_FILE_C

  #define MAX_DECIMAL 10
  #define MAX_OCTAL 8
  #define MAX_HEXDECIMAL 16

  typedef struct for_doh {
    const char key[2];
    const int value;
  } doh;
#endif


// ----------- GENERAL ------------

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError
 * @brief Error Message about MEMORY FULL
 */
static void memory_full_error() {
  printf("%s: While calculating a binary number, a memory overflow occurred. No further action is possible.\n", S_MEMORY_FULL);
  exit(D_MEMORY_FULL);
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError
 * @brief Memory Expansion
 * @param *memory Reference to Memory
 * @param size Memory SIZE
 */
static int memory_realloc(char *memory, int size) {
  size += sizeof(int);

  char *new_memory = realloc(memory, size);
  if (new_memory == NULL) {
    free(memory);
    memory_full_error();
  }

  memory = new_memory;
  return size;
}

// --------------------------------


// ----------- STATICS ------------

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @brief When Converting 1 NUMBER to 1 CHARACTER, it is Stored in Previously Allocated Memory
 * @param index Index for «string[]»
 * @param number Number for «string[]»
 * @param string[] String for New Numbers
 */
static void itoa(int index, int number, char string[]) {
  do {
    string[index++] = (number % 10) + '0';
  } while((number /= 10) > 0);
  string[index++] = '\0';
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @brief Reverse String | (Example, INPUT: 0101; OUTPUT: 1010)
 * @param string[] String (Line, Word)
 */
static void reverse_string(char string[]) {
  int left = 0, right = strlen(string) - 1;
  char mid;

  for (left, right; left < right; left++, right--) {
    mid = string[left];
    string[left] = string[right];
    string[right] = mid;
  };
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @brief Checks 1 Number and Writes it to MEMORY for Further Conversion to BINARY (Example, "9A" -> "910") | `Used for The «string_to_integer» Function`
 * @param *type For ERROR MESSAGE «decimal», «octal» or «hexdecimal»
 * @param *number Number to be Checked for Suitability for Conversion to BINARY
 * @param *new_number MEMORY where The Converted Number is Written After VERIFICATION
 * @param *bin STRUCTURE with Pre-Recorded DATA about «decimal», «octal» or «hexdecimal»
 * @param max_bin For ERROR MESSAGE «MAX_DECIMAL», «MAX_OCTAL» or «MAX_HEXDECIMAL» (#define)
 * @param d_bin For ERROR MESSAGE «D_DECIMAL», «D_OCTAL» or «D_HEXDECIMAL» (#define from «errors.h»)
 * @param s_bin For ERROR MESSAGE «S_DECIMAL», «S_OCTAL» or «S_HEXDECIMAL» (#define from «errors.h»)
 */
static void inside_func_str_to_int(char *type, char *number, char *new_number, doh *bin, int max_bin, int d_bin, char *s_bin) {
  int len_number = strlen(number),  // Length «number»
      index_new_number = 0,  // Index for New Number
      size = len_number,  // for MEMORY
      size_minus_1 = len_number - 1,  // for MEMORY EXPANSION
      is_error = 0,  // Does The INPUT CHARACTER Exist in The STRUCT (0 | No Errors, 1 | Have Errors)
      n = 0,  // for LOOP #1 (Number)
      cur = 0;  // for LOOP #2 (Decumal, Octal || Hexdecimal) and LOOP #3 (for PRINT ERROR)

  doh *copy_bin = bin;
  for (n; n < len_number; n++) {
    bin = copy_bin;  // Clean
    cur = 0;

    // Find Number from Decimal
    for (; bin->key != NULL && ((bin->key[0] == number[n]) == 0); ++bin, cur++) {
      if (cur == MAX_DECIMAL) {
        is_error += 1;
        break;
      }
    }

    if (is_error == 0) {  // No Errors
      if (n == size_minus_1) {  // Memory Expansion
        size = memory_realloc(new_number, size);
        size_minus_1 = size - 1;
      }
      itoa(index_new_number, bin->value, new_number);  // Filling Memory with Data
      index_new_number++;
    } else {  // Have Errors
      printf("%s: Conversion from %s to binary is needed ", s_bin, type);

      // Filling for 1 ERROR MESSAGE
      for (cur = 0; cur < max_bin; cur++, ++copy_bin) {
        if (cur == (max_bin - 1)) {
          printf("%s.\n", copy_bin->key);
        } else {
          printf("%s, ", copy_bin->key);
        }
      }
      exit(d_bin);
    }
  }
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError
 * @brief String to Integer | (Example, INPUT: "9A"; OUTPUT: 910)
 * @param cmd Command is «d» (decimal), «o» (octal) or «h» (hexdecimal)
 * @param *number Number to be Checked for Suitability for Conversion to BINARY
 * @returns Integer
 */
static int string_to_integer(char cmd, char *number) {
  char *new_number = calloc(strlen(number), sizeof(char));
  if (new_number == NULL) {
    memory_full_error();
  }

  if (cmd == 'd') {  // Decimal
    doh decimal[MAX_DECIMAL] = {
      {"0\0", 0}, {"1\0", 1}, {"2\0", 2}, {"3\0", 3}, {"4\0", 4},
      {"5\0", 5}, {"6\0", 6}, {"7\0", 7}, {"8\0", 8}, {"9\0", 9}
    };
    inside_func_str_to_int(
      "decimal", number, new_number,
      decimal, MAX_DECIMAL, D_DECIMAL, S_DECIMAL
    );
  } else if (cmd == 'o') {  // Octal
    doh octal[MAX_OCTAL] = {
      {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3},
      {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}
    };
    inside_func_str_to_int(
      "octal", number, new_number,
      octal, MAX_OCTAL, D_OCTAL, S_OCTAL
    );
  } else if (cmd == 'h') {  // Hexdecimal
    doh hexdecimal[MAX_HEXDECIMAL] = {
      {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3},
      {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
      {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11},
      {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}
    };
    inside_func_str_to_int(
      "hexdecimal", number, new_number,
      hexdecimal, MAX_HEXDECIMAL, D_HEXDECIMAL, S_HEXDECIMAL
    );
  }

  new_number[strlen(new_number)] = '\0';
  int result = atoi(new_number);
  free(new_number);

  return result;
}

// --------------------------------


// ------------ DECIMAL -----------

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError | DecimalError
 * @brief Decimal to Binary | (Example, INPUT: 10; OUTPUT: 1010)
 * @param *number Decimal Number
 * @returns Binary Number
 */
char* db(char *number) {
  int decimal = string_to_integer('d', number),  // Number
      size = 4,  // 1 byte (000 - 111) + '\0'
      size_minus_1 = 3,  // for MEMORY EXPANSION
      div = 1,  // Division without Remainder
      mod = -1,  // Remainder of Division
      s = 0;  // for LOOP

  char *d = calloc(size, sizeof(char)), *result;
  if (d == NULL) {
    memory_full_error();
  }

  for (s; div >= 1; ++s) {
    if (s == size_minus_1) {  // Memory Expansion
      size = memory_realloc(d, size);
      size_minus_1 = size - 1;
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
  reverse_string(d);
  result = d;
  // free(d);

  return result;
}

// --------------------------------
