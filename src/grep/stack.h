#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef SRC_GREP_STACK_H_
#define SRC_GREP_STACK_H_

struct argumets {
  _Bool e;
  _Bool i;
  _Bool v;
  _Bool c;
  _Bool l;
  _Bool n;
  _Bool h;
  _Bool s;
  _Bool o;
  _Bool f;
};
struct option long_options[] = {{"line-number", 0, NULL, 'n'},
                                {"invert-match", 0, NULL, 'v'},
                                {"regexp", required_argument, NULL, 'e'},
                                {"file", required_argument, NULL, 'f'},
                                {"only-matching", 0, NULL, 'o'},
                                {"no-messages", 0, NULL, 's'},
                                {"count", 0, NULL, 'c'},
                                {"no-filename", 0, NULL, 'h'},
                                {"ignore-case", 0, NULL, 'i'},
                                {"files-with-matches", 0, NULL, 'l'},
                                {NULL, 0, NULL, 0}};

char *sub_str(char *s, regmatch_t *pmatch);
void read_me(struct argumets grep, char *Pat, char *Path, int files_flag);
int check(struct argumets *grep, int argc, char **argv);
char *check_e(struct argumets *grep, char *optarg, char *Patt,
              int *pattern_flag, char *plus);
int check_o(regex_t *reg, regmatch_t pmatch, char *line, struct argumets *grep,
            char *Path, int read, int *counter_lines, int *counter_match,
            int files_flag);
char *check_f(struct argumets *grep, char *optarg, char *Patt, long int *len,
              int *pattern_flag, char *plus, _Bool *pat_error);
void check_arg(int argc, char **argv, char *Patt, int *pattern_flag,
               struct argumets *grep, int optind);
void flag_n_and_print(struct argumets *grep, char *line, char *Path,
                      int *counter_match, int counter_lines, int files_flag);
void flag_l_c_h(struct argumets *grep, char *Path, int counter_match,
                int files_flag);

#endif  // SRC_GREP_STACK_H_