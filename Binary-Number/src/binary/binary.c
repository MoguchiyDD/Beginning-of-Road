/*
Developer && Owner: МогучийДД (MoguchiyDD)
LICENSE: MIT License which is located in the text file LICENSE

Goal: Write your own BINARY NUMBER for The Program
Result: Complete your own BINARY NUMBER for The Program

Past Modification: Adding The «8->10», «10->8», «16->10», «10->16», «8->16» and «16->8» BLOCKS
Last Modification: Adding The «stdint.h» LIBRARY
Modification Date: 2024.04.03, 10:10 PM

Create Date: 2024.03.24, 01:56 PM
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "binary.h"
#include "../commands/commands.h"
#include "../errors.h"

#ifndef BINARY_FILE_C
  #define BINARY_FILE_C

  #define TRUE 1
  #define FALSE 0

  #define MAX_BINARY 2
  #define MAX_OCTAL 8
  #define MAX_DECIMAL 10
  #define MAX_HEXDECIMAL 16
  #define MAX_CHARS_FT_TYPE 11

  union check_max_int {
    uint_least32_t value;
  };
  typedef struct from_and_to_type {
    char from[MAX_CHARS_FT_TYPE];
    char to[MAX_CHARS_FT_TYPE];
  } ft_type;
  typedef struct for_doh {
    const char key[2];
    const uint_least8_t value;
  } doh;
  typedef struct oh_template {
    const char key[2];
    const char value[5];
  } template;

  doh dict_binary[MAX_BINARY] = {{"0\0", 0}, {"1\0", 1}};
  doh dict_decimal[MAX_DECIMAL] = {
    {"0\0", 0}, {"1\0", 1}, {"2\0", 2}, {"3\0", 3}, {"4\0", 4},
    {"5\0", 5}, {"6\0", 6}, {"7\0", 7}, {"8\0", 8}, {"9\0", 9}
  };
  doh dict_octal[MAX_OCTAL] = {
    {"0\0", 0}, {"1\0", 1}, {"2\0", 2}, {"3\0", 3},
    {"4\0", 4}, {"5\0", 5}, {"6\0", 6}, {"7\0", 7}
  };
  doh dict_hexdecimal[MAX_HEXDECIMAL] = {
    {"0\0", 0}, {"1\0", 1}, {"2\0", 2}, {"3\0", 3},
    {"4\0", 4}, {"5\0", 5}, {"6\0", 6}, {"7\0", 7},
    {"8\0", 8}, {"9\0", 9}, {"A\0", 10}, {"B\0", 11},
    {"C\0", 12}, {"D\0", 13}, {"E\0", 14}, {"F\0", 15}
  };

  template o_temp[MAX_OCTAL] = {
    {"0\0", "000\0"}, {"1\0", "001\0"}, {"2\0", "010\0"}, {"3\0", "011\0"},
    {"4\0", "100\0"}, {"5\0", "101\0"}, {"6\0", "110\0"}, {"7\0", "111\0"}
  };
  template h_temp[MAX_HEXDECIMAL] = {
    {"0\0", "0000\0"}, {"1\0", "0001\0"}, {"2\0", "0010\0"}, {"3\0", "0011\0"},
    {"4\0", "0100\0"}, {"5\0", "0101\0"}, {"6\0", "0110\0"}, {"7\0", "0111\0"},
    {"8\0", "1000\0"}, {"9\0", "1001\0"}, {"A\0", "1010\0"}, {"B\0", "1011\0"},
    {"C\0", "1100\0"}, {"D\0", "1101\0"}, {"E\0", "1110\0"}, {"F\0", "1111\0"}
  };
#endif


// ----------------- MEMORY FULL -----------------

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError
 * @brief Error Message about MEMORY FULL
 */
static void memory_full_error() {
  printf("%s: While calculating a binary number, a memory overflow occurred. No further action is possible.\n", S_MEMORY_FULL);
  exit(D_MEMORY_FULL);
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError
 * @brief Memory Expansion
 * @param *memory Reference to Memory
 * @param size Memory SIZE
 */
static size_t memory_realloc(char *memory, size_t size) {
  size += sizeof(int) + 1;

  char *new_memory = realloc(memory, size);
  if (new_memory == NULL) {
    free(memory);
    memory_full_error();
  }

  memory = new_memory;
  return size;
}

// -----------------------------------------------


// ------------------- GENERAL -------------------

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError
 * @brief When Converting 1 NUMBER to 1 CHARACTER, it is Stored in Previously Allocated Memory
 * @param index Index for «string[]»
 * @param number Number for «string[]»
 * @param string[] String for New Numbers
 * @param size Memory SIZE
 */
static void itoa(uint_least8_t index, int_least32_t number, char string[], size_t size) {
  size_t size_minus_1 = size - 1;  // for MEMORY EXPANSION

  do {
    if (index == size_minus_1) {  // Memory Expansion
      size = memory_realloc(string, size);
      size_minus_1 = size - 1;
    }
    string[index++] = (number % 10) + '0';
  } while((number /= 10) > 0);

  string[index++] = '\0';
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @brief Reverse String | (Example, INPUT: 0101; OUTPUT: 1010)
 * @param string[] String (Line, Word)
 */
static void reverse_string(char string[]) {
  char mid;
  uint_least8_t left = 0,  // Left Side
                right = strlen(string) - 1;  // Right Size

  for (left, right; left < right; left++, right--) {
    mid = string[left];
    string[left] = string[right];
    string[right] = mid;
  };
}

// -----------------------------------------------


// ---------------- BINARY SEARCH ----------------

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception BinarySearchError
 * @brief Error Message about BINARY SEARCH
 */
static void binary_search_error() {
  printf("%s: Returns -1 from a Hard-Coded Pattern when Searching for 1 Number\n", S_BINARY_SEARCH);
  exit(D_BINARY_SEARCH);
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @brief Binary Search for CHARACTERS
 * @param target Number to Find (KEY)
 * @param *temp Template with CHARACTERS
 * @param max_temp Length «*temp»
 * @returns Number (Found) || -1 (Not Found)
 */
static int_least8_t binary_search_key(char target, template *temp, uint_least8_t max_temp) {
  uint_least8_t left = 0,  // Left Side
                right = max_temp - 1,  // Right Size
                mid = 0;  // Middle Side (REQUIRED)

  while (left <= right) {
    mid = (left + right) / 2;

    if (temp[mid].key[0] == target) {
      return mid;
    } else if (temp[mid].key[0] > target) {
      right = mid - 1;
    } else if (temp[mid].key[0] < target) {
      left = left + 1;
    }
  }

  return -1;
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @brief Binary Search for CHARACTERS
 * @param target Number to Find (VALUE)
 * @param *temp Template with CHARACTERS
 * @param max_temp Length «*temp»
 * @returns Number (Found) || -1 (Not Found)
 */
static int_least8_t binary_search_value(char target[5], template *temp, uint_least8_t max_temp) {
  uint_least8_t left = 0,  // Left Side
                right = max_temp - 1,  // Right Size
                mid = 0;  // Middle Side (REQUIRED)

  while (left <= right) {
    mid = (left + right) / 2;

    if (strcmp(temp[mid].value, target) == 0) {
      return mid;
    } else if (strcmp(temp[mid].value, target) == 1) {
      right = mid - 1;
    } else if (strcmp(temp[mid].value, target) == -1) {
      left = left + 1;
    }
  }

  return -1;
}

// -----------------------------------------------


// ------------------ INTEGERS -------------------

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MaxIntError
 * @brief Error Message about MAXIMUM INTEGER
 */
static void maximum_integer_error() {
  printf("%s: I don't Work After The %dth\n", S_MAXIMUM_INTEGER, INT_LEAST32_MAX);
  exit(D_MAXIMUM_INTEGER);
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MaxIntError
 * @brief Checks 1 NUMBER for Validity
 * @param *number String Binary Number
 */
static int b_check_number(char *number) {
  if (strlen(number) > 31) {
    maximum_integer_error();
  }
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MaxIntError
 * @brief Checks 1 NUMBER for Validity and Returns 1 INTEGER NUMBER
 * @param *number String Decimal Number
 * @returns Integer Decimal Number
 */
static int_least32_t d_check_and_convert_integer_number(char *number) {
  uint_least8_t index_number = 0;
  int_least32_t int_number = 0,  // Original Integer Number
      copy_int_number = 0;  // Copy «int_number»

  for (index_number; number[index_number] != '\0'; index_number++) {
    copy_int_number = int_number;
    int_number = int_number * 10 + (number[index_number] - 48);
    if (!(copy_int_number == (int_number / 10)) || (copy_int_number > INT_LEAST32_MAX)) {
      maximum_integer_error();
    }
  }

  return int_number;
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @brief Decimal to Binary, Octal || Hexdecimal
 * @param type Mode «b», «o» or «h»
 * @param decimal Integer Decimal Number
 * @param division 2 : Binary, 8 : Octal, 16 : Hexdecimal
 * @param *memory Reference to Memory
 * @param size Memory SIZE
 */
static void d_to_boh(char type, int_least32_t decimal, uint_least8_t division, char *memory, size_t size) {
  size_t size_minus_1 = size - 1;  // for MEMORY EXPANSION
  uint_least8_t div = 1,  // Division without Remainder
                mod = -1,  // Remainder of Division
                n = 0;  // for LOOP

  for (n; div >= 1; ++n) {
    if (n == size_minus_1) {  // Memory Expansion
      size = memory_realloc(memory, size);
      size_minus_1 = size - 1;
    }

    div = decimal / division;
    mod = decimal % division;
    decimal = div;

    if (type == 'b') {
      memory[n] = (mod != 0) ? '1' : '0';
    } else if (type == 'o') {
      memory[n] = mod + '0';
    } else if (type == 'h') {
      memory[n] = (mod >= 10) ? mod + 55 : mod + '0';
    }
  }

  memory[n] = '\0';
  reverse_string(memory);
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @brief Decimal to Binary, Octal || Hexdecimal
 * @param type Mode «b», «o» or «h»
 * @param decimal Integer Decimal Number
 * @param division 2 : Binary, 8 : Octal, 16 : Hexdecimal
 * @param *memory Reference to Memory
 * @param size Memory SIZE
 */
static void boh_to_d(char type, char *boh, uint_least8_t division, char *memory, size_t size) {
  int_least32_t sum = 0;  // Total for Number
  uint_least8_t len_number = strlen(boh),  // Length «number»
                index_memory = 0,  // Index «memory»
                np = 0,  // for LOOP (SUMMA)
                nm = len_number - 1,  // for LOOP (SUMMA)
                cur = 0;  // for LOOP (HEXDECIMAL)

  doh *hd = dict_hexdecimal;
  doh *copy_hd = hd;

  for (np; np < len_number; ++np, nm--) {
    if ((type == 'b') || (type == 'o')) {
      sum += (boh[nm] - '0') * pow(division, np);
    } else if (type == 'h') {
      for (; hd->key != NULL && ((hd->key[0] == boh[nm]) == 0); ++hd);
      sum += hd->value * pow(division, np);
      hd = copy_hd;
    }
  }

  // INTEGER to STRING
  itoa(index_memory, sum, memory, size);
  reverse_string(memory);
}

// -----------------------------------------------


// -------------------- OTHER --------------------

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception BinaryError, DecimalError, OctalError || HexdecimalError
 * @brief Checks 1 Number and Writes it to MEMORY for Further Conversion to BINARY (Example, "9A" -> "910") | `Used for The «string_to_integer» Function`
 * @param *from_type For ERROR MESSAGE «binary», «octal», «decimal» or «hexdecimal» (FROM)
 * @param *to_type For ERROR MESSAGE «binary», «octal», «decimal» or «hexdecimal» (TO)
 * @param *number Number to be Checked for Suitability for Conversion to BINARY
 * @param *bin STRUCTURE with Pre-Recorded DATA about «binary», «octal», «decimal» or «hexdecimal»
 * @param max_bin For ERROR MESSAGE «MAX_BINARY», «MAX_DECIMAL», «MAX_OCTAL» or «MAX_HEXDECIMAL» (#define)
 * @param d_bin For ERROR MESSAGE «D_BINARY», «D_OCTAL», «D_DECIMAL» or «D_HEXDECIMAL» (#define from «errors.h»)
 * @param s_bin For ERROR MESSAGE «S_BINARY», «S_OCTAL», «S_DECIMAL» or «S_HEXDECIMAL» (#define from «errors.h»)
 * @param is_error_bdoh 0 (ERRORS: BinaryError, DecimalError, OctalError || HexdecimalError) || 1 (ERROR: MaxIntError)
 */
static void inside_func_checking_number(char *from_type, char *to_type, char *number, doh *bin, uint_least8_t max_bin, int d_bin, char *s_bin, uint_least8_t is_error_bdoh) {
  size_t size = sizeof(int);  // Memory SIZE
  uint_least8_t len_number = strlen(number),  // Length «number»
                is_error = 0,  // Does The INPUT CHARACTER Exist in The STRUCT (0 | No Errors, 1 | Have Errors)
                n = 0,  // for LOOP #1 (Number)
                cur = 0;  // for LOOP #2 (Binary, Decimal, Octal || Hexdecimal) and LOOP #3 (for PRINT ERROR)

  doh *copy_bin = bin;
  for (n; n < len_number; n++) {
    bin = copy_bin;  // Clean

    // Find Number from Decimal
    for (cur = 0; bin->key != NULL && ((bin->key[0] == number[n]) == 0); ++bin, cur++) {
      if (cur == max_bin) {
        is_error += 1;
        break;
      }
    }

    if (is_error >= 1) {  // Have Errors
      if (is_error_bdoh == FALSE) {  // BinaryError, DecimalError, OctalError || HexdecimalError
        printf("%s: Conversion from %s to %s is needed ", s_bin, from_type, to_type);

        // Filling for 1 ERROR MESSAGE
        for (cur = 0; cur < max_bin; cur++, ++copy_bin) {
          if (cur == (max_bin - 1)) {
            printf("%s.\n", copy_bin->key);
          } else {
            printf("%s, ", copy_bin->key);
          }
        }
        exit(d_bin);
      } else if (is_error_bdoh == TRUE) {
        maximum_integer_error();
      }
    }
  }
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception BinaryError, DecimalError, OctalError || HexdecimalError
 * @brief Checks a NUMBER for Allowed CHARACTERS when Converting | (Example, INPUT: "9A"; OUTPUT: 910)
 * @param *cmd Command is «-bo», «-ob», «-bd», «-db», «-bh», «-hb», «-od», «-do», «-hd», «-dh», «-oh» or «-ho»
 * @param *number Number to be Checked for Suitability for Conversion to BINARY
 * @param *type For ERROR MESSAGE «binary», «octal», «decimal», or «hexdecimal» (FROM && TO)
 * @param *bdoh STRUCTURE with Pre-Recorded DATA about «binary», «octal», «decimal» or «hexdecimal»
 * @param is_error_bdoh 0 (ERRORS: BinaryError, DecimalError, OctalError || HexdecimalError) || 1 (ERROR: MaxIntError)
 */
static void checking_number(char *cmd, char *number, ft_type *type, doh *bdoh, uint_least8_t is_error_bdoh) {
  int int_cmd = int_cmd_args(cmd);
  if ((int_cmd == BO) || (int_cmd == BD) || (int_cmd == BH)) {  // 2->8, 2->10 || 2->16
    inside_func_checking_number(
      type->from, type->to, number, bdoh,
      MAX_BINARY, D_BINARY, S_BINARY, is_error_bdoh
    );
  } else if ((int_cmd == OB) || (int_cmd == OD) || (int_cmd == OH)) {  // 8->2, 8->10 || 8->16
    inside_func_checking_number(
      type->from, type->to, number, bdoh,
      MAX_OCTAL, D_OCTAL, S_OCTAL, is_error_bdoh
    );
  } else if ((int_cmd == DB) || (int_cmd == DO) || (int_cmd == DH)) {  // 10->2, 10->8 || 10->16
    inside_func_checking_number(
      type->from, type->to, number, bdoh,
      MAX_DECIMAL, D_DECIMAL, S_DECIMAL, is_error_bdoh
    );
  } else if ((int_cmd == HB) || (int_cmd == HO) || (int_cmd == HD)) {  // 16->2, 16->8 || 16->10
    inside_func_checking_number(
      type->from, type->to, number, bdoh,
      MAX_HEXDECIMAL, D_HEXDECIMAL, S_HEXDECIMAL, is_error_bdoh
    );
  }
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError, BinarySearchError, BinaryError, DecimalError, OctalError || HexdecimalError
 * @brief Filling The Variable «new_number» with DATA from The TEMPLATE for BINARY NUMBERS | (Example, INPUT: "9A"; OUTPUT: "10011010")
 * @param *temp Template with CHARACTERS
 * @param max_temp Length «*temp»
 * @param *number Number to be Checked for Suitability for Conversion to BINARY
 * @param *new_number MEMORY where The Converted Number is Written After VERIFICATION
 * @param size Amount of Memory
 */
static void template_to_binary(template *temp, uint_least8_t max_temp, char *number, char *new_number, size_t size) {
  size_t size_minus_1 = size - 1;  // for MEMORY EXPANSION
  int_least8_t find = -1;  // Found Number
  uint_least8_t len_number = strlen(number),  // Length «number»
      index_new_number = 0,  // Index for New Number
      n_not_1 = 0,  // 
      n = 0,  // for LOOP #1 (for Number)
      t = 0;  // for LOOP #2 (for Template)

  template *copy_temp = temp;
  for (n; n < len_number; n++) {
    if (n == size_minus_1) {  // Memory Expansion
      size = memory_realloc(new_number, size);
      size_minus_1 = size - 1;
    }

    // Find 1 Number
    find = binary_search_key(number[n], temp, max_temp);
    if (find == -1) {
      binary_search_error();
    }
    temp = copy_temp;

    for (t = 0; t < strlen(temp[find].value); t++) {
      if ((n == 0) && (temp[find].value[t] == '1')) {
        ++n_not_1;
      }
      if ((n_not_1 >= 1) && temp[find].value[t] != '\0') {
        if (strlen(new_number) == size_minus_1) {  // Memory Expansion
          size = memory_realloc(new_number, size);
          size_minus_1 = size - 1;
        }
        new_number[index_new_number++] = temp[find].value[t];
      }
    }
  }
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError, BinarySearchError, BinaryError, DecimalError, OctalError || HexdecimalError
 * @brief Filling The Variable «new_number» with DATA from The TEMPLATE for OCTAL, DECIMAL or HEXDECIMAL NUMBERS | (Example, INPUT: "10011010"; OUTPUT: "9A")
 * @param *temp Template with CHARACTERS
 * @param max_temp Length «*temp»
 * @param *number Number to be Checked for Suitability for Conversion to BINARY
 * @param *new_number MEMORY where The Converted Number is Written After VERIFICATION
 * @param size Amount of Memory
 */
static void template_from_binary(template *temp, uint_least8_t max_temp, char *number, char *new_number, size_t size) {
  size_t size_minus_1 = size - 1;  // for MEMORY EXPANSION
  int_least8_t find = -1;  // Found Number
  uint_least8_t len_number = strlen(number),  // Length «number»
                index_new_number = 0,  // Index for New Number
                n = len_number - 1,  // for LOOP #1 (for Number)
                t = 0;  // for LOOP #2 (for Template)

  template *copy_temp = temp;
  uint_least8_t len_temp_value = strlen(temp->value);
  char *temp_value = calloc(size, sizeof(char));
  if (temp_value == NULL) {
    memory_full_error();
  }

  for (n; n >= 0; index_new_number++) {
    if (index_new_number == size_minus_1) {  // Memory Expansion
      size = memory_realloc(new_number, size);
      size_minus_1 = size - 1;
    }

    // 000(0)\0 - 111(1)\0
    for (t = 0; t < len_temp_value; t++) {
      if (n > -1) {
        temp_value[t] = number[n--];
      } else {
        temp_value[t] = '0';
      }
    }
    temp_value[t] = '\0';
    reverse_string(temp_value);

    // Find 1 Number
    find = binary_search_value(temp_value, temp, max_temp);
    if (find == -1) {
      binary_search_error();
    }
    temp = copy_temp;

    new_number[index_new_number] = temp[find].key[0];
  }
}

// -----------------------------------------------


// -------------------- OCTAL --------------------

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError, BinarySearchError, BinaryError || MaxIntError
 * @brief Binary to Octal | (Example, INPUT: "1010"; OUTPUT: "12")
 * @param *cmd Command is «-bo»
 * @param *number Binary Number
 * @returns Octal Number
 */
char* _bo(char *cmd, char *number) {
  ft_type type[2] = {"binary\0", "octal\0"};
  checking_number(cmd, number, type, dict_binary, FALSE);
  b_check_number(number);

  size_t size = 4;  // 1 byte (000 - 111) + '\0'
  char *o = calloc(size, sizeof(char));
  if (o == NULL) {
    memory_full_error();
  }

  // Filling Out a DATA
  template_from_binary(o_temp, MAX_OCTAL, number, o, size);
  o[strlen(o)] = '\0';
  reverse_string(o);

  return o;
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError, BinarySearchError, OctalError || MaxIntError
 * @brief Octal to Binary | (Example, INPUT: "12"; OUTPUT: "1010")
 * @param *cmd Command is «-ob»
 * @param *number Octal Number
 * @returns Binary Number
 */
char* _ob(char *cmd, char *number) {
  ft_type type[2] = {"octal\0", "binary\0"};
  checking_number(cmd, number, type, dict_octal, FALSE);

  size_t size = 4;  // 1 byte (000 - 111) + '\0'
  char *o = calloc(size, sizeof(char));
  if (o == NULL) {
    memory_full_error();
  }

  // Filling Out a DATA
  template_to_binary(o_temp, MAX_OCTAL, number, o, size);
  o[strlen(o)] = '\0';

  checking_number("-bo", o, type, dict_binary, TRUE);
  b_check_number(o);

  return o;
}

// -----------------------------------------------


// -------------- OCTAL && DECIMAL ---------------

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError, OctalError || MaxIntError
 * @brief Octal to Decimal | (Example, INPUT: "12"; OUTPUT: "10")
 * @param *cmd Command is «-od»
 * @param *number Octal Number
 * @returns Decimal Number
 */
char* _od(char *cmd, char *number) {
  ft_type type[2] = {"octal\0", "decimal\0"};
  checking_number(cmd, number, type, dict_octal, FALSE);

  size_t size = 4;  // 1 byte (000 - 111) + '\0'
  char *d = calloc(size, sizeof(char));
  if (d == NULL) {
    memory_full_error();
  }

  boh_to_d('o', number, 8, d, size);  // Filling Out a DATA
  checking_number("-do", d, type, dict_decimal, TRUE);

  return d;
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError, DecimalError || MaxIntError
 * @brief Decimal to Octal | (Example, INPUT: "10"; OUTPUT: "12")
 * @param *cmd Command is «-do»
 * @param *number Decimal Number
 * @returns Octal Number
 */
char* _do(char *cmd, char *number) {
  ft_type type[2] = {"decimal\0", "octal\0"};
  checking_number(cmd, number, type, dict_decimal, FALSE);

  int_least32_t decimal = d_check_and_convert_integer_number(number);  // Number
  size_t size = 4;  // 1 byte (000 - 111) + '\0'

  char *d = calloc(size, sizeof(char));
  if (d == NULL) {
    memory_full_error();
  }

  d_to_boh('o', decimal, 8, d, size);  // Filling Out a DATA
  return d;
}

// -----------------------------------------------


// ------------------- DECIMAL -------------------

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError, BinaryError || MaxIntError
 * @brief Binary to Decimal | (Example, INPUT: "1010"; OUTPUT: "10")
 * @param *cmd Command is «-bd»
 * @param *number Binary Number
 * @returns Decimal Number
 */
char* _bd(char *cmd, char *number) {
  ft_type type[2] = {"binary\0", "decimal\0"};
  checking_number(cmd, number, type, dict_binary, FALSE);
  b_check_number(number);

  size_t size = 4;  // 1 byte (000 - 111) + '\0'
  char *d = calloc(size, sizeof(char));
  if (d == NULL) {
    memory_full_error();
  }

  boh_to_d('b', number, 2, d, size);  // Filling Out a DATA
  return d;
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError, DecimalError || MaxIntError
 * @brief Decimal to Binary | (Example, INPUT: "10"; OUTPUT: "1010")
 * @param *cmd Command is «-db»
 * @param *number Decimal Number
 * @returns Binary Number
 */
char* _db(char *cmd, char *number) {
  ft_type type[2] = {"decimal\0", "binary\0"};
  checking_number(cmd, number, type, dict_decimal, FALSE);

  int_least32_t decimal = d_check_and_convert_integer_number(number);  // Number
  size_t size = 4;  // 1 byte (000 - 111) + '\0'

  char *d = calloc(size, sizeof(char));
  if (d == NULL) {
    memory_full_error();
  }

  d_to_boh('b', decimal, 2, d, size);  // Filling Out a DATA
  return d;
}

// -----------------------------------------------


// ------------ HEXDECIMAL && DECIMAL ------------

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError, HexdecimalError || MaxIntError
 * @brief Hexdecimal to Decimal | (Example, INPUT: "A"; OUTPUT: "10")
 * @param *cmd Command is «-hd»
 * @param *number Hexdecimal Number
 * @returns Decimal Number
 */
char* _hd(char *cmd, char *number) {
  ft_type type[2] = {"hexdecimal\0", "decimal\0"};
  checking_number(cmd, number, type, dict_hexdecimal, FALSE);

  size_t size = 4;  // 1 byte (000 - 111) + '\0'
  char *d = calloc(size, sizeof(char));
  if (d == NULL) {
    memory_full_error();
  }

  boh_to_d('h', number, 16, d, size);  // Filling Out a DATA
  checking_number("-dh", d, type, dict_decimal, TRUE);

  return d;
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError, DecimalError || MaxIntError
 * @brief Decimal to Hexdecimal | (Example, INPUT: "10"; OUTPUT: "A")
 * @param *cmd Command is «-dh»
 * @param *number Decimal Number
 * @returns Hexdecimal Number
 */
char* _dh(char *cmd, char *number) {
  ft_type type[2] = {"decimal\0", "hexdecimal\0"};
  checking_number(cmd, number, type, dict_decimal, FALSE);

  int_least32_t decimal = d_check_and_convert_integer_number(number);  // Number
  size_t size = 4;  // 1 byte (000 - 111) + '\0'

  char *d = calloc(size, sizeof(char));
  if (d == NULL) {
    memory_full_error();
  }

  d_to_boh('h', decimal, 16, d, size);  // Filling Out a DATA
  return d;
}

// -----------------------------------------------


// ----------------- HEXDECIMAL ------------------

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError, BinarySearchError, BinaryError || MaxIntError
 * @brief Binary to Hexdecimal | (Example, INPUT: "1010"; OUTPUT: "A")
 * @param *cmd Command is «-bh»
 * @param *number Binary Number
 * @returns Hexdecimal Number
 */
char* _bh(char *cmd, char *number) {
  ft_type type[2] = {"binary\0", "hexdecimal\0"};
  checking_number(cmd, number, type, dict_binary, FALSE);
  b_check_number(number);

  size_t size = 5;  // 1 byte (0000 - 1111) + '\0'
  char *h = calloc(size, sizeof(char));
  if (h == NULL) {
    memory_full_error();
  }

  // Filling Out a DATA
  template_from_binary(h_temp, MAX_HEXDECIMAL, number, h, size);
  h[strlen(h)] = '\0';
  reverse_string(h);

  return h;
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError, BinarySearchError, HexdecimalError || MaxIntError
 * @brief Hexdecimal to Binary | (Example, INPUT: "A"; OUTPUT: "1010")
 * @param *cmd Command is «-hb»
 * @param *number Hexdecimal Number
 * @returns Binary Number
 */
char* _hb(char *cmd, char *number) {
  ft_type type[2] = {"hexdecimal\0", "binary\0"};
  checking_number(cmd, number, type, dict_hexdecimal, FALSE);

  size_t size = 5;  // 1 byte (0000 - 1111) + '\0'
  char *h = calloc(size, sizeof(char));
  if (h == NULL) {
    memory_full_error();
  }

  // Filling Out a DATA
  template_to_binary(h_temp, MAX_HEXDECIMAL, number, h, size);
  h[strlen(h)] = '\0';

  checking_number("-bh", h, type, dict_binary, TRUE);
  b_check_number(h);

  return h;
}

// -----------------------------------------------


// ------------- OCTAL && HEXDECIMAL -------------

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError, OctalError || MaxIntError
 * @brief Octal to Hexdecimal | (Example, INPUT: "12"; OUTPUT: "A")
 * @param *cmd Command is «-oh»
 * @param *number Octal Number
 * @returns Hexdecimal Number
 */
char* _oh(char *cmd, char *number) {
  ft_type type[2] = {"octal\0", "hexdecimal\0"};
  checking_number(cmd, number, type, dict_octal, FALSE);

  size_t size = 4;  // 1 byte (000 - 111) + '\0'
  char *o = calloc(size, sizeof(char));
  if (o == NULL) {
    memory_full_error();
  }

  boh_to_d('o', number, 8, o, size);  // 8->10
  checking_number("-do", o, type, dict_decimal, TRUE);

  int_least32_t decimal = d_check_and_convert_integer_number(o);  // Number
  d_to_boh('h', decimal, 16, o, size); // 10->16

  return o;
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError, HexdecimalError || MaxIntError
 * @brief Hexdecimal to Octal | (Example, INPUT: "A"; OUTPUT: "12")
 * @param *cmd Command is «-ho»
 * @param *number Hexdecimal Number
 * @returns Octal Number
 */
char* _ho(char *cmd, char *number) {
  ft_type type[2] = {"hexdecimal\0", "decimal\0"};
  checking_number(cmd, number, type, dict_hexdecimal, FALSE);

  size_t size = 4;  // 1 byte (000 - 111) + '\0'
  char *h = calloc(size, sizeof(char));
  if (h == NULL) {
    memory_full_error();
  }

  boh_to_d('h', number, 16, h, size);  // 16->10
  checking_number("-dh", h, type, dict_decimal, TRUE);

  int_least32_t decimal = d_check_and_convert_integer_number(h);  // Number
  d_to_boh('o', decimal, 8, h, size); // 16->8

  return h;
}

// -----------------------------------------------
