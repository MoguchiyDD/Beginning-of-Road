/*
Developer && Owner: МогучийДД (MoguchiyDD)
LICENSE: MIT License which is located in the text file LICENSE

Goal: Write your own ERRORS for The Program
Result: Complete your own ERRORS for The Program

Past Modification: Adding COPYRIGHT
Last Modification: Adding The BLOCKS ERRORS FUNCTIONS
Modification Date: 2024.04.05, 10:47 PM

Create Date: 2024.04.05, 07:50 PM
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "errors.h"
#include "../arguments/arguments.h"


/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception NumArgsError | 1
 * @brief Error Message about NUMBER OF ARGUMENTS
 * @param argc Number of Arguments from The «main.c» File
 */
void num_args_error(int argc) {
  if ((argc < ARGUMENTS) || (argc > ARGUMENTS)) {
    if (argc == 1) {
      printf("%s: found %d argument, but needed %d arguments.\n", S_COUNT_ARGUMENTS, argc, ARGUMENTS);
    } else {
      printf("%s: found %d arguments, but needed %d arguments.\n", S_COUNT_ARGUMENTS, argc, ARGUMENTS);
    }
    exit(D_COUNT_ARGUMENTS);
  }
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception CmdMissError | 2
 * @brief Error Message about COMMAND IS MISSING
 */
void command_is_missing() {
  printf("%s: command is missing.\n", S_COMMAND_IS_MISSING);
  exit(D_COMMAND_IS_MISSING);
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError | 3
 * @brief Error Message about MEMORY FULL
 */
void memory_full_error() {
  printf("%s: While calculating a binary number, a memory overflow occurred. No further action is possible.\n", S_MEMORY_FULL);
  exit(D_MEMORY_FULL);
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MaxIntError | 4
 * @brief Error Message about MAXIMUM INTEGER
 */
void maximum_integer_error() {
  printf("%s: I don't Work After The %dth\n", S_MAXIMUM_INTEGER, INT_LEAST32_MAX);
  exit(D_MAXIMUM_INTEGER);
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception BinarySearchError | 5
 * @brief Error Message about BINARY SEARCH
 */
void binary_search_error() {
  printf("%s: Returns -1 from a Hard-Coded Pattern when Searching for 1 Number\n", S_BINARY_SEARCH);
  exit(D_BINARY_SEARCH);
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception BinaryError, OctalError, DecimalError, HexdecimalError | 6, 7, 8, 9
 * @brief Error Message about BINARY, OCTAL, DECIMAL and HEXDECIMAL
 * @param integer_error «D_BINARY (6)», «D_OCTAL (7)», «D_DECIMAL (8)» or «D_HEXDECIMAL (9)»
 * @param *string_error «S_BINARY (6)», «S_OCTAL (7)», «S_DECIMAL (8)» or «S_HEXDECIMAL (9)»
 * @param *from «binary», «octal», «decimal» or «hexdecimal» (FROM)
 * @param *to «binary», «octal», «decimal» or «hexdecimal» (TO)
 * @param max_bodh «MAX_BINARY», «MAX_DECIMAL», «MAX_OCTAL» or «MAX_HEXDECIMAL»
 * @param *copy String with KEYS from «doh *copy_bin» Pointer
 */
void bodh(uint_least8_t integer_error, char *string_error, char *from, char *to, uint_least8_t max_bodh, char *copy) {
  uint_least8_t c = 0;  // for «copy»

  printf("%s: Conversion from %s to %s is needed ", string_error, from, to);
  for (c; c < max_bodh; c++) {
    if (c == (max_bodh - 1)) {
      printf("%c.\n", copy[c]);
    } else {
      printf("%c, ", copy[c]);
    }
  }
  exit(integer_error);
}
