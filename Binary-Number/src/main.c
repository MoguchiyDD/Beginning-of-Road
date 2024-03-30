/*
Developer && Owner: МогучийДД (MoguchiyDD)
LICENSE: MIT License which is located in the text file LICENSE

Goal: Write The BINARY NUMBER from 0
Result: Complete The BINARY NUMBER from 0

Past Modification: Editing The «2->8», «2->10» and «2->16» BLOCKS
Last Modification: Moving The «int_cmd_args» to «commands» FOLDER
Modification Date: 2024.03.29, 06:17 PM

Create Date: 2024.03.23, 09:26 PM
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "commands/commands.h"
#include "binary/binary.h"
#include "errors.h"

#ifndef MAIN
  #define MAIN
  #define ARGUMENTS 3
#endif

int main(int argc, char *argv[]) {
  if ((argc < ARGUMENTS) || (argc > ARGUMENTS)) {  // CHECK: Number of Arguments
    if (argc == 1) {
      printf("%s: found %d argument, but needed %d arguments.\n", S_COUNT_ARGUMENTS, argc, ARGUMENTS);
    } else {
      printf("%s: found %d arguments, but needed %d arguments.\n", S_COUNT_ARGUMENTS, argc, ARGUMENTS);
    }
    exit(D_COUNT_ARGUMENTS);
  }

  printf("Binary Number\n—————————————\n");  // Greetings

  // COMMANDS
  char *cmd = malloc(strlen(argv[1] + 1));
  strcpy(cmd, argv[1]);

  // NUMBER
  int a2 = 0, n = 0;
  char number[strlen(argv[2])];
  while (argv[2][a2]) {
    if (isalpha(argv[2][a2]) != 0) {
      number[n++] = toupper(argv[2][a2]);
    } else {
      number[n++] = argv[2][a2];
    }
    a2++;
  }
  number[strlen(argv[2])] = '\0';

  switch(int_cmd_args(cmd)) {
    case BO:  // 2->8
      char *binary_octal = bo(cmd, number);
      printf("Input : %s\nOutput: %s\n", number, binary_octal);
      free(binary_octal);
      break;
    case OB:  // 8->2
      char *octal_binary = ob(cmd, number);
      printf("Input : %s\nOutput: %s\n", number, octal_binary);
      free(octal_binary);
      break;
    case BD:  // 2->10
      char *binary_decimal = bd(cmd, number);
      printf("Input : %s\nOutput: %s\n", number, binary_decimal);
      free(binary_decimal);
      break;
    case DB:  // 10->2
      char *decimal_binary = db(cmd, number);
      printf("Input : %s\nOutput: %s\n", number, decimal_binary);
      free(decimal_binary);
      break;
    case BH:  // 2->16
      char *binary_hexdecimal = bh(cmd, number);
      printf("Input : %s\nOutput: %s\n", number, binary_hexdecimal);
      free(binary_hexdecimal);
      break;
    case HB:  // 16->2
      char *hexdecimal_binary = hb(cmd, number);
      printf("Input : %s\nOutput: %s\n", number, hexdecimal_binary);
      free(hexdecimal_binary);
      break;
    default:
      printf("%s: command is missing.\n", S_COMMAND_IS_MISSING);
      exit(D_COMMAND_IS_MISSING);
  }

  free(cmd);
  return 0;
}
