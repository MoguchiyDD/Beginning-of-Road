/*
Developer && Owner: МогучийДД (MoguchiyDD)
LICENSE: MIT License which is located in the text file LICENSE

Goal: Write The BINARY NUMBER from 0
Result: Complete The BINARY NUMBER from 0

Past Modification: Adding The «stdint.h» LIBRARY
Last Modification: Editing The ARGUMENTS and ERRORS
Modification Date: 2024.04.05, 10:43 PM

Create Date: 2024.03.23, 09:26 PM
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors/errors.h"
#include "commands/commands.h"
#include "arguments/arguments.h"
#include "binary/binary.h"

uint_least8_t main(int argc, char *argv[]) {
  num_args_error(argc);  // CHECK: Number of Arguments
  printf("Binary Number\n—————————————\n");  // Greetings

  // COMMANDS
  char *cmd = malloc(strlen(argv[1] + 1));
  strcpy(cmd, argv[1]);

  // NUMBER
  char *number = calloc(strlen(argv[2]), sizeof(char));
  if (number == NULL) {
    printf("%s: While calculating a binary number, a memory overflow occurred. No further action is possible.\n", S_MEMORY_FULL);
    exit(D_MEMORY_FULL);
  }
  primary_validity_arg(argv[2], number);

  switch(int_cmd_args(cmd)) {
    case BO:  // 2->8
      char *binary_octal = _bo(cmd, number);
      printf("Input : %s\nOutput: %s\n", number, binary_octal);
      free(binary_octal);
      break;
    case OB:  // 8->2
      char *octal_binary = _ob(cmd, number);
      printf("Input : %s\nOutput: %s\n", number, octal_binary);
      free(octal_binary);
      break;
    case BD:  // 2->10
      char *binary_decimal = _bd(cmd, number);
      printf("Input : %s\nOutput: %s\n", number, binary_decimal);
      free(binary_decimal);
      break;
    case DB:  // 10->2
      char *decimal_binary = _db(cmd, number);
      printf("Input : %s\nOutput: %s\n", number, decimal_binary);
      free(decimal_binary);
      break;
    case BH:  // 2->16
      char *binary_hexdecimal = _bh(cmd, number);
      printf("Input : %s\nOutput: %s\n", number, binary_hexdecimal);
      free(binary_hexdecimal);
      break;
    case HB:  // 16->2
      char *hexdecimal_binary = _hb(cmd, number);
      printf("Input : %s\nOutput: %s\n", number, hexdecimal_binary);
      free(hexdecimal_binary);
      break;
    case OD:  // 8->10
      char *octal_decimal = _od(cmd, number);
      printf("Input : %s\nOutput: %s\n", number, octal_decimal);
      free(octal_decimal);
      break;
    case DO:  // 10->8
      char *decimal_octal = _do(cmd, number);
      printf("Input : %s\nOutput: %s\n", number, decimal_octal);
      free(decimal_octal);
      break;
    case HD:  // 16->10
      char *hexdecimal_decimal = _hd(cmd, number);
      printf("Input : %s\nOutput: %s\n", number, hexdecimal_decimal);
      free(hexdecimal_decimal);
      break;
    case DH:  // 10->16
      char *decimal_hexdecimal = _dh(cmd, number);
      printf("Input : %s\nOutput: %s\n", number, decimal_hexdecimal);
      free(decimal_hexdecimal);
      break;
    case OH:  // 8->16
      char *octal_hexdecimal = _oh(cmd, number);
      printf("Input : %s\nOutput: %s\n", number, octal_hexdecimal);
      free(octal_hexdecimal);
      break;
    case HO:  // 16->8
      char *hexdecimal_octal = _ho(cmd, number);
      printf("Input : %s\nOutput: %s\n", number, hexdecimal_octal);
      free(hexdecimal_octal);
      break;
    default:
      command_is_missing();
  }

  free(cmd);
  free(number);

  return 0;
}
