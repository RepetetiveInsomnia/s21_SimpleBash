#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef SRC_CAT_STACK_H_
#define SRC_CAT_STACK_H_

struct argumets {
  _Bool v;
  _Bool n;
  _Bool b;
  _Bool s;
  _Bool e;
  _Bool t;
  _Bool E;
  _Bool T;
};

struct option long_options[] = {
    {"number", 0, NULL, 'n'},        {"show-nonprinting", 0, NULL, 'v'},
    {"squeeze-blank", 0, NULL, 's'}, {"number-nonblank", 0, NULL, 'b'},
    {"show-ends", 0, NULL, 'E'},     {"show-tabs", 0, NULL, 'T'},
    {"show-all", 0, NULL, 'A'},      {NULL, 0, NULL, 0}};

void read_me(struct argumets cat, int argc, char **path);
int check(struct argumets *cat, int argc, char **argv);
int ANCII_check(int ch);
void flag_b(struct argumets cat, int memo, int ch, int *counter_one);
void flag_n(struct argumets cat, int memo, int ch, int *counter_one);
int flag_s(struct argumets cat, int ch, int *counter_three);
void flag_E(struct argumets cat, int ch);
void print(struct argumets cat, int ch);
_Bool flag_T(struct argumets cat, int ch);

#endif  // SRC_CAT_STACK_H_