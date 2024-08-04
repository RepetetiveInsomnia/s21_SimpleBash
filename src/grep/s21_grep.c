#include "stack.h"
int main(int argc, char **argv) {
  struct argumets grep = {0};
  check(&grep, argc, argv);
  return 0;
}
void read_me(struct argumets grep, char *Patt, char *Path, int files_flag) {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int status = 0;
  int counter_match = 0;
  int counter_lines = 0;
  regmatch_t pmatch;
  regex_t reg;
  int check = 0;
  if (grep.i == 1) {
    check = regcomp(&reg, Patt, REG_NEWLINE | REG_ICASE | REG_EXTENDED);
  } else {
    check = regcomp(&reg, Patt, REG_NEWLINE | REG_EXTENDED);
  }
  if (check == 0) {
    FILE *pFile = fopen(Path, "r");
    if (pFile == NULL) {
      if (grep.s != 1) {
        fprintf(stderr, "grep: %s: No such file or directory\n", Path);
      }
    } else {
      while ((read = getline(&line, &len, pFile)) != -1) {
        counter_lines++;

        if (check_o(&reg, pmatch, line, &grep, Path, read, &counter_lines,
                    &counter_match, files_flag) == 1)
          ;
        else {
          status = regexec(&reg, line, 0, &pmatch, 0);
          if (status == REG_NOMATCH) {
            if (grep.v == 1) {
              flag_n_and_print(&grep, line, Path, &counter_match, counter_lines,
                               files_flag);
            }
          } else if (grep.v != 1) {
            flag_n_and_print(&grep, line, Path, &counter_match, counter_lines,
                             files_flag);
          }
        }
      }
      if (line) {
        free(line);
      }
      flag_l_c_h(&grep, Path, counter_match, files_flag);
      fclose(pFile);
    }
  }
  regfree(&reg);
}
int check(struct argumets *grep, int argc, char **argv) {
  opterr = 0;
  int status = 0;
  int pattern_flag = 0;
  char plus[] = "|";
  char *Patt = NULL;
  long int len = 0;
  _Bool pat_error = 0;
  while ((status = getopt_long(argc, argv, "f:e:ivclnhso", long_options,
                               NULL)) != -1) {
    if (status == 'e' && pat_error == 0) {
      Patt = check_e(grep, optarg, Patt, &pattern_flag, plus);
    }
    if (status == 'f' && pat_error == 0) {
      Patt = check_f(grep, optarg, Patt, &len, &pattern_flag, plus, &pat_error);
    }
    if (status == 'i') {
      grep->i = 1;
    }
    if (status == 'o') {
      grep->o = 1;
    }
    if (status == 's') {
      grep->s = 1;
    }
    if (status == 'h') {
      grep->h = 1;
    }
    if (status == 'v') {
      grep->v = 1;
    }
    if (status == 'c') {
      grep->c = 1;
    }
    if (status == 'l') {
      grep->l = 1;
    }
    if (status == 'n') {
      grep->n = 1;
    }
    if (status == '?') {
      pat_error = 1;
      if (grep->s != 1) {
        fprintf(stderr, "grep: unrecognized option: '%s'\n", argv[optind - 1]);
      }
    }
  }
  if (pat_error != 1) {
    check_arg(argc, argv, Patt, &pattern_flag, grep, optind);
  }
  if (pat_error == 1 && Patt != NULL) {
    free(Patt);
  }
  return status;
}
void check_arg(int argc, char **argv, char *Patt, int *pattern_flag,
               struct argumets *grep, int optind) {
  _Bool files_flag = 0;
  char *Path = NULL;
  for (int i = optind; i < argc; i++) {
    if (*pattern_flag == 1) {
      Path = (char *)malloc((strlen(argv[i]) + 1) * sizeof(char));
      strcpy(Path, argv[i]);
      if (i != argc - 1 && *argv[i + 1] != '-') {
        files_flag = 1;
      }
      read_me(*grep, Patt, Path, files_flag);
      if (Path != NULL) {
        free(Path);
      }
    }
    if (*pattern_flag == 0) {
      Patt = (char *)calloc((strlen(argv[i]) + 1), sizeof(char));
      strcpy(Patt, argv[i]);
      *pattern_flag = 1;
    }
  }
  if (Patt != NULL) {
    free(Patt);
  }
}
char *check_e(struct argumets *grep, char *optarg, char *Patt,
              int *pattern_flag, char *plus) {
  if (Patt != NULL) {
    Patt = (char *)realloc(Patt, (strlen(optarg) + strlen(Patt) + 2));
    strcat(Patt, plus);
    strcat(Patt, optarg);
  } else {
    grep->e = 1;
    Patt = (char *)calloc((strlen(optarg) + 2), sizeof(char));
    strcat(Patt, optarg);
    *pattern_flag = 1;
  }

  return Patt;
}
char *check_f(struct argumets *grep, char *optarg, char *Patt, long int *len,
              int *pattern_flag, char *plus, _Bool *pat_error) {
  FILE *pFile = fopen(optarg, "r");
  if (pFile == NULL) {
    *pat_error = 1;
    if (grep->s != 1) {
      fprintf(stderr, "grep: %s: No such file or directory\n", optarg);
    }
  } else {
    fseek(pFile, 0L, SEEK_END);
    *len = ftell(pFile);
    rewind(pFile);
    char *line = NULL;
    line = (char *)calloc((*len + 1), sizeof(char));
    fread(line, sizeof(char), *len + 1, pFile);
    for (int i = 0; i < *len; i++) {
      if (line[i] == '\n' && i != *len - 1) {
        line[i] = 124;
      }
    }
    if (line != NULL) {
      if (Patt != NULL) {
        Patt = (char *)realloc(Patt, (strlen(Patt) + (*len + 2)));
        strcat(Patt, plus);
        strcat(Patt, line);

      } else {
        grep->f = 1;
        Patt = (char *)calloc((strlen(line) + 2), sizeof(char));
        strcat(Patt, line);
        *pattern_flag = 1;
      }
    }
    fclose(pFile);
    free(line);
  }
  return Patt;
}
void flag_n_and_print(struct argumets *grep, char *line, char *Path,
                      int *counter_match, int counter_lines, int files_flag) {
  *counter_match = *counter_match + 1;
  if (grep->c != 1 && grep->l != 1) {
    if (files_flag == 1 && grep->h != 1) {
      printf("%s:", Path);
    }
    if (grep->n == 1) {
      printf("%d:", counter_lines);
    }
    printf("%s", line);
    if (strchr(line, '\n') == 0) {
      printf("\n");
    }
  }
}
void flag_l_c_h(struct argumets *grep, char *Path, int counter_match,
                int files_flag) {
  if (grep->c == 1) {
    if (files_flag == 1 && grep->h != 1) {
      printf("%s:", Path);
    }
    if (grep->l == 1 && counter_match != 0) {
      printf("1\n");
    } else {
      printf("%d\n", counter_match);
    }
  }
  if (counter_match != 0 && grep->l == 1) {
    printf("%s\n", Path);
  }
}
char *sub_str(char *s, regmatch_t *pmatch) {
  char *buff = (char *)calloc(pmatch->rm_eo - pmatch->rm_so + 1, sizeof(char));
  int i = 0;
  while (i < pmatch->rm_eo - pmatch->rm_so) {
    buff[i] = s[i + pmatch->rm_so];
    i++;
  }
  buff[i] = '\0';

  return buff;
}
int check_o(regex_t *reg, regmatch_t pmatch, char *line, struct argumets *grep,
            char *Path, int read, int *counter_lines, int *counter_match,
            int files_flag) {
  _Bool flag = 0;
  _Bool mac_flag = 0;
  if (grep->o == 1 && grep->l != 1 && grep->v != 1 && grep->f != 1) {
    flag = 1;
    int offset = 0;
    int status;
    if (regexec(reg, line, 1, &pmatch, 0) != REG_NOMATCH) {
      *counter_match = *counter_match + 1;
      while (offset < read - 1) {
        status = regexec(reg, line + offset, 1, &pmatch, 0);
        if (status != REG_NOMATCH) {
          char *p = sub_str(line + offset, &pmatch);
          if (files_flag == 1 && grep->h != 1 && grep->c != 1 &&
              mac_flag == 0) {
            printf("%s:", Path);
          }
          if (grep->n == 1 && grep->c != 1 && mac_flag == 0) {
            printf("%d:", *counter_lines);
          }
          if (grep->c != 1) {
            printf("%s\n", p);
            mac_flag = 1;
          }
          free(p);
        }

        offset = offset + pmatch.rm_eo;
        if (pmatch.rm_eo == 0) {
          offset = read - 1;
        }
      }
    }
  }
  return flag;
}
