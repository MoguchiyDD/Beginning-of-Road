/*
Developer && Owner: МогучийДД (MoguchiyDD)
LICENSE: MIT License which is located in the text file LICENSE

Goal: Write your own BINARY NUMBER for The Program
Result: Complete your own BINARY NUMBER for The Program

Past Modification: Adding The «8->2» and «16->2» BLOCKS
Last Modification: Adding The «2->8», «2->10» and «2->16» BLOCKS
Modification Date: 2024.03.30, 11:48 PM

Create Date: 2024.03.24, 01:56 PM
*/


#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "binary.h"
#include "../commands/commands.h"
#include "../errors.h"

#ifndef BINARY_FILE_C
  #define BINARY_FILE_C

  #define MAX_INT_OCT "17777777777"
  #define MAX_INT_DEC "2147483647"
  #define MAX_INT_HEX "7FFFFFFF"

  #define MAX_BINARY 2
  #define MAX_OCTAL 8
  #define MAX_DECIMAL 10
  #define MAX_HEXDECIMAL 16
  #define MAX_CHARS_FT_TYPE 11

  union check_max_int {
    unsigned int value;
  };
  typedef struct from_and_to_type {
    char from[MAX_CHARS_FT_TYPE];
    char to[MAX_CHARS_FT_TYPE];
  } ft_type;
  typedef struct for_doh {
    const char key[2];
    const int value;
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


// ------------- MEMORY FULL -------------

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
static int memory_realloc(char *memory, int size) {
  size += sizeof(int) + 1;

  char *new_memory = realloc(memory, size);
  if (new_memory == NULL) {
    free(memory);
    memory_full_error();
  }

  memory = new_memory;
  return size;
}

// ---------------------------------------


// ------------ BINARY SEARCH ------------

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
static int binary_search_key(char target, template *temp, int max_temp) {
  int left = 0, right = max_temp - 1, mid;
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
static int binary_search_value(char target[5], template *temp, int max_temp) {
  int left = 0, right = max_temp - 1, mid;
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

// ---------------------------------------


// --------------- GENERAL ---------------

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError
 * @brief When Converting 1 NUMBER to 1 CHARACTER, it is Stored in Previously Allocated Memory
 * @param index Index for «string[]»
 * @param number Number for «string[]»
 * @param string[] String for New Numbers
 * @param size Memory SIZE
 */
static void itoa(int index, int number, char string[], int size) {
  int size_minus_1 = size - 1;
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
  int left = 0, right = strlen(string) - 1;
  char mid;

  for (left, right; left < right; left++, right--) {
    mid = string[left];
    string[left] = string[right];
    string[right] = mid;
  };
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MaxIntError
 * @brief Error Message about MAXIMUM INTEGER
 */
static void maximum_integer_error() {
  printf("%s: I don't Work After The %dth\n", S_MAXIMUM_INTEGER, INT32_MAX);
  exit(D_MAXIMUM_INTEGER);
}

// ---------------------------------------


// ---------------- OTHER ----------------

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
 */
static void inside_func_checking_number(char *from_type, char *to_type, char *number, doh *bin, int max_bin, int d_bin, char *s_bin) {
  int len_number = strlen(number),  // Length «number»
      size = sizeof(int),  // Memory SIZE
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
    }
  }
}

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception BinaryError, DecimalError, OctalError || HexdecimalError
 * @brief Checks a NUMBER for Allowed CHARACTERS when Converting | (Example, INPUT: "9A"; OUTPUT: 910)
 * @param *cmd Command is «-bo», «-ob», «-bd», «-db», «-bh» or «-hb»
 * @param *number Number to be Checked for Suitability for Conversion to BINARY
 * @param *type For ERROR MESSAGE «binary», «octal», «decimal», or «hexdecimal» (FROM && TO)
 * @param *bdoh STRUCTURE with Pre-Recorded DATA about «binary», «octal», «decimal» or «hexdecimal»
 */
static void checking_number(char *cmd, char *number, ft_type *type, doh *bdoh) {
  int int_cmd = int_cmd_args(cmd);
  if ((int_cmd == BO) || (int_cmd == BD) || (int_cmd == BH)) {  // 2->8, 2->10 && 2->16
    inside_func_checking_number(
      type->from, type->to, number, bdoh,
      MAX_BINARY, D_BINARY, S_BINARY
    );
  } else if (int_cmd == OB) {  // 8->2
    inside_func_checking_number(
      type->from, type->to, number, bdoh,
      MAX_OCTAL, D_OCTAL, S_OCTAL
    );
  } else if (int_cmd == DB) {  // 10->2
    inside_func_checking_number(
      type->from, type->to, number, bdoh,
      MAX_DECIMAL, D_DECIMAL, S_DECIMAL
    );
  } else if (int_cmd == HB) {  // 16->2
    inside_func_checking_number(
      type->from, type->to, number, bdoh,
      MAX_HEXDECIMAL, D_HEXDECIMAL, S_HEXDECIMAL
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
static void template_to_binary(template *temp, int max_temp, char *number, char *new_number, int size) {
  int len_number = strlen(number),  // Length «number»
      index_new_number = 0,  // Index for New Number
      size_minus_1 = size - 1,  // for MEMORY EXPANSION
      find = -1,  // Found Number
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
    if (find == -1) { binary_search_error(); }
    temp = copy_temp;

    for (t = 0; t < strlen(temp[find].value); t++) {
      if ((n == 0) && (temp[find].value[t] == '1')) { ++n_not_1; }
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
static void template_from_binary(template *temp, int max_temp, char *number, char *new_number, int size) {
  int len_number = strlen(number),  // Length «number»
      index_new_number = 0,  // Index for New Number
      size_minus_1 = size - 1,  // for MEMORY EXPANSION
      find = -1,  // Found Number
      n = len_number - 1,  // for LOOP #1 (for Number)
      t = 0;  // for LOOP #2 (for Template)

  template *copy_temp = temp;
  int len_temp_value = strlen(temp->value);
  char *temp_value = calloc(size, sizeof(char));
  if (temp_value == NULL) { memory_full_error(); }

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
    if (find == -1) { binary_search_error(); }
    temp = copy_temp;

    new_number[index_new_number] = temp[find].key[0];
  }
}


// ---------------------------------------


// ---------------- OCTAL ----------------

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError, BinarySearchError, BinaryError || MaxIntError
 * @brief Binary to Octal | (Example, INPUT: "1010"; OUTPUT: "12")
 * @param *cmd Command is «-bo»
 * @param *number Binary Number
 * @returns Octal Number
 */
char *bo(char *cmd, char *number) {
  ft_type type[2] = {"binary\0", "octal\0"};
  checking_number(cmd, number, type, dict_binary);

  int size = 4;  // 1 byte (000 - 111) + '\0'
  char *o = calloc(size, sizeof(char));
  if (o == NULL) { memory_full_error(); }

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
char* ob(char *cmd, char *number) {
  ft_type type[2] = {"octal\0", "binary\0"};
  checking_number(cmd, number, type, dict_octal);

  int size = 4;  // 1 byte (000 - 111) + '\0'
  char *o = calloc(size, sizeof(char));
  if (o == NULL) { memory_full_error(); }

  // Filling Out a DATA
  template_to_binary(o_temp, MAX_OCTAL, number, o, size);
  o[strlen(o)] = '\0';

  return o;
}

// ---------------------------------------


// --------------- DECIMAL ---------------

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError, BinaryError || MaxIntError
 * @brief Binary to Decimal | (Example, INPUT: "1010"; OUTPUT: "10")
 * @param *cmd Command is «-bd»
 * @param *number Binary Number
 * @returns Decimal Number
 */
char* bd(char *cmd, char *number) {
  ft_type type[2] = {"binary\0", "decimal\0"};
  checking_number(cmd, number, type, dict_binary);

  uint32_t sum = 0;  // Total for Number
  int len_number = strlen(number),  // Length «number»
      index_new_number = 0,  // Index for New Number
      size = 4,  // 1 byte (000 - 111) + '\0'
      np = 0,  // for LOOP
      nm = len_number - 1;  // for LOOP

  char *d = calloc(size, sizeof(char));
  if (d == NULL) { memory_full_error(); }

  // Filling Out a DATA
  for (np; np < len_number; ++np, nm--) {
    sum += (number[nm] - '0') * pow(2, np);
    if (sum > INT32_MAX) { maximum_integer_error(); }
  }

  // INTEGER to STRING
  itoa(index_new_number, sum, d, size);
  reverse_string(d);

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
char* db(char *cmd, char *number) {
  ft_type type[2] = {"decimal\0", "binary\0"};
  checking_number(cmd, number, type, dict_decimal);
  if (strcmp(number, MAX_INT_DEC) >= 1) { maximum_integer_error(); }

  int decimal = atoi(number),  // Number
      size = 4,  // 1 byte (000 - 111) + '\0'
      size_minus_1 = size - 1,  // for MEMORY EXPANSION
      div = 1,  // Division without Remainder
      mod = -1,  // Remainder of Division
      n = 0;  // for LOOP

  char *d = calloc(size, sizeof(char));
  if (d == NULL) { memory_full_error(); }

  // Filling Out a DATA
  for (n; div >= 1; ++n) {
    if (n == size_minus_1) {  // Memory Expansion
      size = memory_realloc(d, size);
      size_minus_1 = size - 1;
    }

    div = decimal / 2;
    mod = decimal % 2;
    decimal = div;

    if (mod != 0) {
      d[n] = '1';
    } else {
      d[n] = '0';
    }
  }

  d[n] = '\0';
  reverse_string(d);

  return d;
}

// ---------------------------------------


// ------------- HEXDECIMAL --------------

/**
 * @copyright Copyright (c) 2024 MoguchiyDD
 * @exception MemoryFullError, BinarySearchError, BinaryError || MaxIntError
 * @brief Binary to Hexdecimal | (Example, INPUT: "1010"; OUTPUT: "A")
 * @param *cmd Command is «-bh»
 * @param *number Binary Number
 * @returns Hexdecimal Number
 */
char* bh(char *cmd, char *number) {
  ft_type type[2] = {"binary\0", "hexdecimal\0"};
  checking_number(cmd, number, type, dict_binary);

  int size = 5;  // 1 byte (0000 - 1111) + '\0'
  char *h = calloc(size, sizeof(char));
  if (h == NULL) { memory_full_error(); }

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
char* hb(char *cmd, char *number) {
  ft_type type[2] = {"hexdecimal\0", "binary\0"};
  checking_number(cmd, number, type, dict_hexdecimal);

  int size = 5;  // 1 byte (0000 - 1111) + '\0'
  char *h = calloc(size, sizeof(char));
  if (h == NULL) { memory_full_error(); }

  // Filling Out a DATA
  template_to_binary(h_temp, MAX_HEXDECIMAL, number, h, size);
  h[strlen(h)] = '\0';

  return h;
}

// ---------------------------------------
