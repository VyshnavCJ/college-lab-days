#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<ctype.h>

int main(int argc, char * argv[]) {
  int state = 0, flag = 0, i, p = 0, id = 0;
  char ch, word[200], kw[][10] = {
    "auto",
    "break",
    "case",
    "char",
    "const",
    "continue",
    "default",
    "do",
    "double",
    "else",
    "enum",
    "extern",
    "float",
    "for",
    "goto",
    "if",
    "int",
    "long",
    "register",
    "return",
    "short",
    "signed",
    "sizeof",
    "static",
    "struct",
    "switch",
    "typedef",
    "union",
    "unsigned",
    "void",
    "volatile",
    "while"
  };
  if (argc < 2) {
    printf("Usage %s <input file name>\n", argv[0]);
    return 1;
  }

  FILE * f;
  f = fopen(argv[1], "r");
  while (flag != 1) //flag is used to check EOF
  {
    switch (state) {
    case 0:
      ch = fgetc(f);
      if (isalnum(ch) || ch == '_') //check for identifiers & integers
      {
        if (isalpha(ch) || ch == '_') //may be identifier
          state = 2;
        else //may be integer
          state = 4;
      } else if (ch == '<' || ch == '>' || ch == '=') //check for relational operator
      {
        char c = ch;
        ch = fgetc(f); //read forward one character
        if (ch == '=')
          printf("\n%c= is a relational operator", c);
        else if (c == '=') {
          printf("\n%c is an assignment operator", c);
          fseek(f, -1, SEEK_CUR); //put back the look ahead character
        } else {
          printf("\n%c is an relational operator", c);
          fseek(f, -1, SEEK_CUR); //put back the look ahead character
        }
        state = 0;
      } else if (ch == '!') {
        char c = ch;
        ch = fgetc(f); //look ahead
        if (ch == '=')
          printf("\n%c= is a relational operator", c);
        else {
          printf("\n%c is a logical operator", c);
          fseek(f, -1, SEEK_CUR); //put back the look ahead character
        }
      } else if (ch == '&' || ch == '|') {
        char c = ch;
        ch = fgetc(f); //look ahead
        if (ch == '&' || ch == '|')
          printf("\n%c%c is a logical operator", c, ch);
        else {
          printf("\n%c is a bitwise operator", c);
          fseek(f, -1, SEEK_CUR); //put back the look ahead character
        }

      } else if (ch == '/') {
        state = 5;
      } else if (ch == '+' || ch == '-' || ch == '*' || ch == '%') {
        char c = ch;
        ch = fgetc(f); //look ahead
        if (ch == '=') {
          printf("\n%c= is an assignment operator", c);

        } else {
          printf("\n%c is an arithmetic operator", c);
          fseek(f, -1, SEEK_CUR); //put back the look ahead character
        }

      } else if (ch == ';' || ch == '\'' || ch == ',' || ch == '[' || ch == ']' || ch == '{' || ch == '}' || ch == '(' || ch == ')' || ch == ':')
        printf("\n%c is a punctuator.", ch);

      else if (ch == '\"') //check for strings
      {
        p = 0;
        word[p++] = ch;
        do {
          ch = fgetc(f);
          word[p++] = ch;
        } while (ch != '\"');
        word[p] = '\0';
        p = 0;
        printf("\n%s is a string literal", word);
      }
      break;
    case 1:
      ch = fgetc(f);
      if (ch == '=')
        state = 2;
      else
        state = 3;
      break;

    case 2: //get the identifier
      word[p++] = ch;
      while (isalnum(ch = fgetc(f)) || ch == '_') {
        word[p++] = ch;
      }
      fseek(f, -1, SEEK_CUR); //put back the character not part of the id
      word[p] = '\0';
      state = 3; //check if keyword
      p = 0;
      break;
    case 3:
      for (i = 0; i < 32; i++)
        if (strcmp(kw[i], word) == 0) {
          printf("\n%s is a keyword.", word);
          id = 1;
          break;
        }
      if (id == 0) //not a keyword
        printf("\n%s is an identifier.", word);
      state = 0;
      id = 0;
      break;

    case 4:
      word[p++] = ch; //get the integer
      while (isdigit(ch = fgetc(f))) {
        word[p++] = ch;
      }
      if (isalpha(ch) || ch == '_') //non digit or non punctuation character - error
      {
        printf("\n Invalid token\n");
        exit(1);
      }
      fseek(f, -1, SEEK_CUR);
      word[p] = '\0';
      p = 0;
      printf("\n%s is an integer.", word);
      state = 0;
      break;

    case 5:
      ch = fgetc(f);
      if (ch == '*')
        state = 6;
      else if (ch == '/')
        state = 7;
      else if (ch == '=') {
        printf("\n/= is an assignment operator");
        state = 0;
      } else {
        fseek(f, -2, SEEK_CUR); //put back the look ahead character
        ch = fgetc(f);
        printf("\n%c is an arithmetic operator", ch);
        state = 0;
      }

      break;
    case 6:
      do {
        ch = fgetc(f);
      } //ignore a multiline comment
      while (ch != '*');
      if (ch == '*') {
        ch = fgetc(f);
        if (ch == '/') {
          printf("\nMultiline comment ignored");
          state = 0;
        } else
          state = 6;
      }
      break;
    case 7:
      do {
        ch = fgetc(f);
      } //ignore a single line comment
      while (ch != '\n');
      printf("\nSingle line comment ignored");
      state = 0;
      break;

    default:
      break;
    }
    if (ch == EOF)
      flag = 1;
  }
  printf("\n");
  fclose(f);
  return 0;
}
