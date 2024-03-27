/*
Developer && Owner: МогучийДД (MoguchiyDD)
LICENSE: MIT License which is located in the text file LICENSE

Goal: Write The BINARY NUMBER from 0
Result: Complete The BINARY NUMBER from 0

Past Modification: Editing The «ENUM» BLOCK
Last Modification: Editing The «OCTAL» and «HEXDECIMAL» BLOCKS
Modification Date: 2024.03.27, 02:59 PM

Create Date: 2024.03.23, 09:26 PM
*/


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "binary/binary.h"
#include "errors.h"

#ifndef MAIN
  #define MAIN
  #define ARGUMENTS 3
  #define COMMANDS 3

  enum cmd_args{DB, OB, HB};

  /**
   * @copyright Copyright (c) 2024 MoguchiyDD
   * @brief for STRING SWITCH | (Example, INPUT: ob; OUTPUT: 1)
   * @param *cmd Command from Terminal
   * @returns Number Command
   */
  int int_cmd_args(char *cmd) {
    int cur = 0;
    static struct dict {
      const char key[4];
      enum cmd_args cmd;
    } cmds[COMMANDS] = {
      {"-db\0", DB},
      {"-ob\0", OB},
      {"-hb\0", HB}
    };

    struct dict *d = cmds;
    for(; d->key != NULL && strcmp(d->key, cmd) != 0; ++d) {
      cur++;
      if (cur == COMMANDS) {
        return -1;
      }
    };

    return d->cmd;
  }

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
    case DB:  // 10->2
      char *decimal = db(number);
      printf("Input : %s\nOutput: %s\n", number, decimal);
      free(decimal);
      break;
    case OB:  // 8->2
      char *octal = ob(number);
      printf("Input : %s\nOutput: %s\n", number, octal);
      free(octal);
      break;
    case HB:  // 16->2
      char *hexdecimal = hb(number);
      printf("Input : %s\nOutput: %s\n", number, hexdecimal);
      free(hexdecimal);
      break;
    default:
      printf("%s: command is missing.\n", S_COMMAND_IS_MISSING);
      exit(D_COMMAND_IS_MISSING);
  }

  free(cmd);
  return 0;
}
