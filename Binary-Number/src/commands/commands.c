/*
Developer && Owner: МогучийДД (MoguchiyDD)
LICENSE: MIT License which is located in the text file LICENSE

Goal: Declare STRING COMMANDS in NUMERIC Form
Result: STRING COMMANDS to NUMERIC COMMANDS

Past Modification: Adding The «OD», «DO», «HD», «DH», «OH» and «HO» COMMANDS
Last Modification: Adding The «stdint.h» LIBRARY
Modification Date: 2024.04.03, 08:41 PM

Create Date: 2024.03.28, 09:50 PM
*/


#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "commands.h"

#ifndef MAIN_COMMANDS_C
  #define MAIN_COMMANDS_C

  static struct dict_cmds {
    const char key[4];
    enum cmd_args cmd;
  } cmds[COMMANDS] = {
    {"-bd\0", BD}, {"-db\0", DB},  // 2->10  ; 10->2 
    {"-bo\0", BO}, {"-ob\0", OB},  // 2->8   ; 8->2
    {"-bh\0", BH}, {"-hb\0", HB},  // 2->16  ; 16->2
    {"-od\0", OD}, {"-do\0", DO},  // 8->10  ; 10->8 
    {"-hd\0", HD}, {"-dh\0", DH},  // 16->10 ; 10->16
    {"-oh\0", OH}, {"-ho\0", HO}   // 8->16  ; 16->8
  };
#endif


/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @brief for STRING SWITCH | (Example, INPUT: "-db"; OUTPUT: 1)
 * @param *cmd Command from Terminal
 * @returns Number Command
 */
int_least8_t int_cmd_args(char *cmd) {
  struct dict_cmds *c = cmds;

  uint_least8_t cur = 0, result = 0;
  for(; c->key != NULL && strcmp(c->key, cmd) != 0; ++c, ++cur) {
    if (cur == COMMANDS) {
      return -1;
    }
  };

  result = c->cmd;
  c -= cur;

  return result;
}
