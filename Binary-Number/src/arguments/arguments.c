/*
Developer && Owner: МогучийДД (MoguchiyDD)
LICENSE: MIT License which is located in the text file LICENSE

Goal: Handling ARGUMENTS
Result: Variables from ARGUMENTS are Ready for Use

Past Modification: Adding COPYRIGHT
Last Modification: Adding The «primary_validity_arg» FUNCTION
Modification Date: 2024.04.05, 09:46 PM

Create Date: 2024.04.05, 07:51 PM
*/


#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include "arguments.h"


/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @brief Checks 1 NUMBER for Primary Validity
 * @param *argv ARGUMENT After Checking Transfers The RESULT to The «number» Variable
 * @param *number Dedicated MEMORY
 */
void primary_validity_arg(char *argv, char *number) {
  uint_least8_t a = 0,  // for «argv»
                n = 0,  // for «number»
                fixed = 0;  // NUMBER SYMBOL Encountered NON-ZERO

  do {
    if ((argv[a] != '0') && (strlen(argv) >= 2) && (fixed == 0)) {  // for 0
      ++fixed;
    }

    if (fixed >= 1) {  // not for 0
      if (isalpha(argv[a]) != 0) {
        number[n++] = toupper(argv[a]);
      } else {
        number[n++] = argv[a];
      }
    }

    a++;
  } while (argv[a]);

  if (strlen(number) >= 1) {
    number[strlen(number)] = '\0';
  } else {  // «argv» == 0
    number[0] = '0';
    number[1] = '\0';
  }
}
