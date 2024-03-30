/*
Developer && Owner: МогучийДД (MoguchiyDD)
LICENSE: MIT License which is located in the text file LICENSE

Goal: Declare STRING COMMANDS in NUMERIC Form
Result: STRING COMMANDS to NUMERIC COMMANDS

Past Modification: Adding COPYRIGHT
Last Modification: Adding The «int_cmd_args» FUNCTION
Modification Date: 2024.03.28, 10:27 PM

Create Date: 2024.03.28, 09:50 PM
*/


#include <stdio.h>
#include <string.h>
#include "commands.h"

#ifndef MAIN_COMMANDS_C
  #define MAIN_COMMANDS_C

  static struct dict_cmds {
    const char key[4];
    enum cmd_args cmd;
  } cmds[COMMANDS] = {
    {"-bd\0", BD}, {"-db\0", DB},
    {"-bo\0", BO}, {"-ob\0", OB},
    {"-bh\0", BH}, {"-hb\0", HB}
  };
#endif


/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @brief for STRING SWITCH | (Example, INPUT: ob; OUTPUT: 3)
 * @param *cmd Command from Terminal
 * @returns Number Command
 */
int int_cmd_args(char *cmd) {
  struct dict_cmds *c = cmds;

  int cur = 0, result = 0;
  for(; c->key != NULL && strcmp(c->key, cmd) != 0; ++c, ++cur) {
    if (cur == COMMANDS) {
      return -1;
    }
  };

  result = c->cmd;
  c -= cur;

  return result;
}
