/*
Developer && Owner: МогучийДД (MoguchiyDD)
LICENSE: MIT License which is located in the text file LICENSE

Goal: Declare STRING COMMANDS in NUMERIC Form
Result: STRING COMMANDS to NUMERIC COMMANDS

Past Modification: Adding The «int_cmd_args» FUNCTION
Last Modification: Adding COMMENTS
Modification Date: 2024.03.29, 12:42 PM

Create Date: 2024.03.28, 09:50 PM
*/


#ifndef MAIN_COMMANDS_H
  #define MAIN_COMMANDS_H
  #define COMMANDS 6

  enum cmd_args{
    BO, OB,  // BO — 2->8; OB — 8->2
    BD, DB,  // BD — 2->10; DB — 10->2
    BH, HB  // BH — 2->16; HB — 16->2
  };
  int int_cmd_args(char *cmd);
#endif
