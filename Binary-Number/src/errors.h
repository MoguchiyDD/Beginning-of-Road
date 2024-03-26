/*
Developer && Owner: МогучийДД (MoguchiyDD)
LICENSE: MIT License which is located in the text file LICENSE

Goal: Write your own ERRORS for The Program
Result: Complete your own ERRORS for The Program

Past Modification: Adding The «MEMORY_FULL» BLOCK ERRORS
Last Modification: Adding The «DECIMAL», «OCTAL» and «HEXDECIMAL» BLOCK ERRORS
Modification Date: 2024.03.26, 05:41 PM

Create Date: 2024.03.23, 10:52 PM
*/


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

  // Decimal
  #define D_DECIMAL 4
  #define S_DECIMAL "DecimalError"

  // Octal
  #define D_OCTAL 5
  #define S_OCTAL "OctalError"

  // Hexdecimal
  #define D_HEXDECIMAL 6
  #define S_HEXDECIMAL "HexdecimalError"
#endif
