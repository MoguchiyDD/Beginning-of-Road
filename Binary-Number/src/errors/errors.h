/*
Developer && Owner: МогучийДД (MoguchiyDD)
LICENSE: MIT License which is located in the text file LICENSE

Goal: Write your own ERRORS for The Program
Result: Complete your own ERRORS for The Program

Past Modification: Adding The «MAXIMUM_INTEGER» BLOCK ERRORS
Last Modification: Adding The BLOCKS ERRORS FUNCTIONS
Modification Date: 2024.04.05, 10:11 PM

Create Date: 2024.03.23, 10:52 PM
*/


#include <stdint.h>

#ifndef ERRORS
  #define ERRORS

  // Number of Arguments from Terminal
  #define D_COUNT_ARGUMENTS 1
  #define S_COUNT_ARGUMENTS "NumArgsError"

  // Command is Missing
  #define D_COMMAND_IS_MISSING 2
  #define S_COMMAND_IS_MISSING "CmdMissError"

  // Memory Full
  #define D_MEMORY_FULL 3
  #define S_MEMORY_FULL "MemoryFullError"

  // Maximum Integer
  #define D_MAXIMUM_INTEGER 4
  #define S_MAXIMUM_INTEGER "MaxIntError"

  // Binary Search
  #define D_BINARY_SEARCH 5
  #define S_BINARY_SEARCH "BinarySearchError"

  // Binary
  #define D_BINARY 6
  #define S_BINARY "BinaryError"

  // Decimal
  #define D_DECIMAL 7
  #define S_DECIMAL "DecimalError"

  // Octal
  #define D_OCTAL 8
  #define S_OCTAL "OctalError"

  // Hexdecimal
  #define D_HEXDECIMAL 9
  #define S_HEXDECIMAL "HexdecimalError"

  void num_args_error(int argc);  // 1
  void command_is_missing();  // 2
  void memory_full_error();  // 3
  void maximum_integer_error();  // 4
  void binary_search_error();  // 5
  void bodh(uint_least8_t integer_error, char *string_error, char *from, char *to, uint_least8_t max_bodh, char *copy);  // 6, 7, 8, 9
#endif
