#include "stack.h"
int main(int argc, char **argv) {
  struct argumets cat = {0};

  if (check(&cat, argc, argv) != 1) {
    read_me(cat, argc, argv);
  }

  return 0;
}
void read_me(struct argumets cat, int argc, char **path) {
  int counter_one = 1;
  int counter_three = 1;
  int ch;
  int memo = '\n';
  for (int i = 1; i < argc; i++) {
    if (*path[i] != '-') {
      FILE *pFile = fopen(path[i], "r");
      if (pFile == NULL) {
        fprintf(stderr, "cat: %s: No such file or directory\n", path[i]);
      } else {
        while ((ch = getc(pFile)) != EOF) {
          if (flag_s(cat, ch, &counter_three) == 1) {
            continue;
          }
          flag_b(cat, memo, ch, &counter_one);
          flag_n(cat, memo, ch, &counter_one);
          flag_E(cat, ch);
          if (flag_T(cat, ch) == 0) {
            print(cat, ch);
          }
          memo = ch;
        }
        fclose(pFile);
      }
    }
  }
}
int check(struct argumets *cat, int argc, char **argv) {
  int status = 0;
  _Bool err_flag = 0;
  while ((status = getopt_long(argc, argv, "vnbsetEA", long_options, NULL)) !=
         -1) {
    if (status == 'n') {
      cat->n = 1;
    }
    if (status == 'b') {
      cat->b = 1;
    }
    if (status == 's') {
      cat->s = 1;
    }
    if (status == 'e') {
      cat->e = 1;
    }
    if (status == 't') {
      cat->t = 1;
    }
    if (status == 'T') {
      cat->T = 1;
    }
    if (status == 'E') {
      cat->E = 1;
    }
    if (status == 'v') {
      cat->v = 1;
    }
    if (status == 'A') {
      cat->e = 1;
      cat->t = 1;
    }
    if (status == '?') {
      err_flag = 1;
    }
  }

  return err_flag;
}
int ANCII_check(int ch) {
  _Bool flag = 0;
  if ((ch >= 0 && ch <= 8) || (ch >= 11 && ch <= 31)) {
    printf("^%c", ch + 64);
    flag = 1;
  }
  if (ch == 127) {
    printf("^%c", ch - 64);
    flag = 1;
  }
  return flag;
}
void flag_b(struct argumets cat, int memo, int ch, int *counter_one) {
  if (cat.b == 1 && memo == '\n' && memo != ch) {
    printf("%6d\t", *counter_one);
    *counter_one = *counter_one + 1;
  }
}
void flag_n(struct argumets cat, int memo, int ch, int *counter_one) {
  if (cat.n == 1 && memo == '\n' && ch != EOF && cat.b != 1) {
    printf("%6d\t", *counter_one);
    *counter_one = *counter_one + 1;
  }
}
void flag_E(struct argumets cat, int ch) {
  if ((cat.e == 1 && ch == '\n') || (cat.E == 1 && ch == '\n')) {
    printf("$");
  }
}
_Bool flag_T(struct argumets cat, int ch) {
  _Bool flag = 0;
  if ((cat.t == 1 && ch == 9) || (cat.T == 1 && ch == 9)) {
    printf("^I");
    flag = 1;
  }
  return flag;
}
void print(struct argumets cat, int ch) {
  if (cat.t == 1 || cat.e == 1 || cat.v == 1) {
    if (ANCII_check(ch) == 0) {
      printf("%c", ch);
    }
  } else {
    printf("%c", ch);
  }
}
int flag_s(struct argumets cat, int ch, int *counter_three) {
  _Bool flag = 0;
  if (ch == '\n') {
    *counter_three = *counter_three + 1;
  } else {
    *counter_three = 0;
  }
  if (cat.s == 1 && *counter_three > 2) {
    flag = 1;
  }
  return flag;
}