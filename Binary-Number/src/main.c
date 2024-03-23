/*
Developer && Owner: МогучийДД (MoguchiyDD)
LICENSE: MIT License which is located in the text file LICENSE

Goal: Write The BINARY NUMBER from 0
Result: Complete The BINARY NUMBER from 0

Past Modification: Adding The «ERRORS» BLOCK
Last Modification: Adding The «COMMANDS» BLOCK
Modification Date: 2024.03.24, 12:28 AM

Create Date: 2024.03.23, 09:26 PM
*/


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"

#ifndef MAIN
  #define MAIN
  #define ARGUMENTS 2
  #define COMMANDS 3

  // for STRING SWITCH
  enum cmd_args{DB, OB, XB};
  int int_cmd_args(char *cmd) {
    int cur = 0;
    static struct dict {
      const char key[COMMANDS];
      enum cmd_args cmd;
    } cmds[COMMANDS] = {
      {"-db", DB},
      {"-ob", OB},
      {"-xb", XB}
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
  if (argc < ARGUMENTS) {  // CHECK: Number of Arguments
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
      printf("DB\n");
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
