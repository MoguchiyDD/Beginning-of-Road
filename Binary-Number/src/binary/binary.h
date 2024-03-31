/*
Developer && Owner: МогучийДД (MoguchiyDD)
LICENSE: MIT License which is located in the text file LICENSE

Goal: Write your own BINARY NUMBER for The Program
Result: Complete your own BINARY NUMBER for The Program

Past Modification: Adding The «8->2», «10->2» and «16->2» FUNCTIONS
Last Modification: Adding The «8->10», «10->8», «16->10», «10->16», «8->16» and «16->8» BLOCKS
Modification Date: 2024.03.31, 11:22 PM

Create Date: 2024.03.24, 01:56 PM
*/


#ifndef BINARY_FILE_H
  #define BINARY_FILE_H

  // BO — 2->8; OB — 8->2
  char* _bo(char *cmd, char *number);
  char* _ob(char *cmd, char *number);

  // BD — 2->10; DB — 10->2
  char* _bd(char *cmd, char *number);
  char* _db(char *cmd, char *number);

  // BH — 2->16; HB — 16->2
  char* _bh(char *cmd, char *number);
  char* _hb(char *cmd, char *number);

  // OD — 8->10; DO — 10->8
  char* _od(char *cmd, char *number);
  char* _do(char *cmd, char *number);

  // HD — 16->10; DH — 10->16
  char* _hd(char *cmd, char *number);
  char* _dh(char *cmd, char *number);

  // OH — 8->16; HO — 16->8
  char* _oh(char *cmd, char *number);
  char* _ho(char *cmd, char *number);
#endif
