#include "lib/library.h"

int seekLine (FILE *infile, int lineNumber, char *line) {
  int currentSeek = ftell(infile);
  fseek(infile, 0, SEEK_SET);
  while (--lineNumber && (fgets(line, 256, infile) != NULL));

  if (!lineNumber) {
    fgets(line, 256, infile);
  } else {
    /* Do Nothing. */
  }

  fseek(infile, currentSeek, SEEK_SET);

  return !lineNumber;
}


void removeLineBreak (char *string) {
  size_t size;
  size = strlen (string);
  if (string[size - 1] == '\n') {
    string[--size] = '\0';
  }
}

void readString (char *string) {
  char character = ' ';
  int counter = 0;
  do {
    character = getchar();
    if (character != '\n') {
      string[counter] = character;
    } else {
      /* Do Nothing. */
    }
    counter++;
  } while (character != '\n' && character != '\0');
  string[--counter] = '\0';
}

void cleanReadBuffer () {
  int auxInteger = 0;
  do {
    auxInteger = fgetc(stdin);
  } while (auxInteger != EOF && auxInteger != '\n');
}