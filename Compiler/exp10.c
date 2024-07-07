#include<stdio.h>

#include<string.h>

#include<ctype.h>

char input[20];
int i, error;
void E();
void Eprime();
void T();
void Tprime();
void F();
int main() {
  i = 0;
  error = 0;
  printf("Enter the expression without whitespace: ");
  scanf("%s", input);
  E();
  if (strlen(input) == i && error == 0) {
    printf("Input Accepted!\n");
  } else {
    printf("Input Rejected!\n");
  }
  return 0;
}
void E() {
  T();
  Eprime();
}
void Eprime() {
  if (input[i] == '+' || input[i] == '-') {
    i++;
    T();
    Eprime();
  }
}
void T() {
  F();
  Tprime();
}
void Tprime() {
  if (input[i] == '*' || input[i] == '/') {
    i++;
    F();
    Tprime();
  }
}
void F() {
  if (isalnum(input[i])) {
    i++;
  } else if (input[i] == '(') {
    i++;
    E();
    if (input[i] == ')') {
      i++;
    } else {
      error = 1;
    }
  } else {
    error = 1;
  }
}
