/*
Developer && Owner: МогучийДД (MoguchiyDD)
LICENSE: MIT License which is located in the text file LICENSE

Goal: Declare STRING COMMANDS in NUMERIC Form
Result: STRING COMMANDS to NUMERIC COMMANDS

Past Modification: Adding The «OD», «DO», «HD», «DH», «OH» and «HO» COMMANDS
Last Modification: Adding The «stdint.h» LIBRARY
Modification Date: 2024.04.05, 10:10 PM

Create Date: 2024.03.28, 09:50 PM
*/


#include <stdint.h>

#ifndef MAIN_COMMANDS_H
  #define MAIN_COMMANDS_H
  #define COMMANDS 12

  enum cmd_args{
    BO, OB,  // BO — 2->8   ; OB — 8->2
    BD, DB,  // BD — 2->10  ; DB — 10->2
    BH, HB,  // BH — 2->16  ; HB — 16->2
    OD, DO,  // OD — 8->10  ; DO — 10->8
    HD, DH,  // HD — 16->10 ; DH — 10->16
    OH, HO   // OH — 8->16  ; HO — 16->8
  };
  int_least8_t int_cmd_args(char *cmd);
#endif
