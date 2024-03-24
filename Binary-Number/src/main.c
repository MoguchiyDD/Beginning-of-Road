/*
Developer && Owner: МогучийДД (MoguchiyDD)
LICENSE: MIT License which is located in the text file LICENSE

Goal: Write The BINARY NUMBER from 0
Result: Complete The BINARY NUMBER from 0

Past Modification: Adding The «COMMANDS» BLOCK
Last Modification: Editing The «COMMANDS» and «DB» BLOCK
Modification Date: 2024.03.24, 02:05 PM

Create Date: 2024.03.23, 09:26 PM
*/


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary/binary.h"
#include "errors.h"

#ifndef MAIN
  #define MAIN
  #define ARGUMENTS 3
  #define COMMANDS 3

  enum cmd_args{DB, OB, XB};

  /**
   * @copyright Copyright (c) 2024 MoguchiyDD
   * @brief for STRING SWITCH | (Example, INPUT: ob; OUTPUT: 1)
   * @param *cmd Command from Terminal
   * @returns Number Command
   */
  int int_cmd_args(char *cmd) {
    int cur = 0;
    static struct dict {
      const char key[COMMANDS];
      enum cmd_args cmd;
    } cmds[COMMANDS] = {
      {"db", DB},
      {"ob", OB},
      {"xb", XB}
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
  switch(int_cmd_args(cmd)) {
    case DB:  // 10->2
      char *decimal = db(argv[2]);
      printf("Input : %s\nOutput: %s\n", argv[2], decimal);
      free(decimal);
      break;
    case OB:  // 8->2
      printf("OB\n");
      break;
    case XB:  // 16->2
      printf("XB\n");
      break;
    default:
      printf("%s: command is missing.\n", S_COMMAND_IS_MISSING);
      exit(D_COMMAND_IS_MISSING);
  }

  free(cmd);
  return 0;
}
