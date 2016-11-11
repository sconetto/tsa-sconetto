#include "lib/library.h"

CFO_TOTAL *createTotalBinaryTree () {
  CFO_TOTAL *root = (CFO_TOTAL *) malloc(sizeof(CFO_TOTAL));
  if (root != NULL) {
    *root = NULL;
  } else {
    /* Do Nothing. */
  }
  return root;
}

void releaseTotal (TOTAL *vertex) {
  if (vertex == NULL) {
    return;
  } else {
    /* Do Nothing. */
  }
  releaseTotal(vertex->left);
  releaseTotal(vertex->right);
  free(vertex);
  vertex = NULL;
  return;
}

void releaseBinaryTreeTotal (CFO_TOTAL *root) {
  if (root == NULL) {
    return;
  } else {
    /* Do Nothing. */
  }
  releaseTotal(*root);
  free(root);
  return;
}

void searchLineTotal (CFO_TOTAL *root) {
  FILE *readFile;
  int close = 0;
  char auxString[1000];

  readFile = fopen("./doc/dadoscfo.csv", "r");

  if (readFile == NULL) {
    system("clear");
    printf("Erro ao abrir o arquivo dadoscfo.csv - cfo-total.c\\searchLineTotal\n");
    sleep(2);
    exit(1);
  } else {
    /* Do Nothing. */
  }

  if (seekLine(readFile, (*root)->line, auxString)) {
    printf("%s", auxString);
  } else {
    /* Do Nothing. */
  }

  close = fclose(readFile);

  if (close != FAIL) {
    printf("Erro ao fechar o arquivo dadoscfo.csv - cfo-total.c\\searchLineTotal\n");
    sleep(2);
    exit(1);
  } else {
    /* Do Nothing. */
  }
  return;
}

int queryUFBinaryTree (CFO_TOTAL *root, char *UF) {
  TOTAL *currentLeaf = *root;
  if (strcmp(UF, currentLeaf->UF) == 0) {
    return SUCCESS;
  } else {
    return FAIL;
  }
}

void printTreeInOrderOfTotal (CFO_TOTAL *root) {
  if (root == NULL) {
    return;
  } else {
    /* Do Nothing. */
  }
  if (*root != NULL) {
    printTreeInOrderOfTotal(&((*root)->left));
    searchLineTotal(root);
    printTreeInOrderOfTotal(&((*root)->right));
  }
}

void printTreeInDownwardOrder (CFO_TOTAL *root, char *UF) {
  if (root == NULL) {
    return;
  } else {
    /* Do Nothing. */
  }
  if (*root != NULL) {
    printTreeInDownwardOrder(&((*root)->left), UF);
    if (queryUFBinaryTree(root, UF)) {
      searchLineTotal(root);
    } else {
      /* Do Nothing. */
    }
    printTreeInDownwardOrder(&((*root)->right), UF);
  }
}

int insertVertexsOrderedByTotal (CFO_TOTAL *root, int line, char *UF, int total) {
  TOTAL *newVertex;
  newVertex = (TOTAL *) malloc(sizeof(TOTAL));
  newVertex->line = line;
  strcpy(newVertex->UF, UF);
  newVertex->total = total;
  newVertex->left = NULL;
  newVertex->right = NULL;

  if (*root == NULL) {
    *root = newVertex;
  } else {
    TOTAL *currentLeaf = *root;
    TOTAL *previousLeaf = NULL;
    while (currentLeaf != NULL) {
      previousLeaf = currentLeaf;
      if (total > currentLeaf->total) {
        currentLeaf = currentLeaf->right;
      } else {
        currentLeaf = currentLeaf->left;
      }
    }
    if (total > previousLeaf->total) {
      previousLeaf->right = newVertex;
    } else {
      previousLeaf->left = newVertex;
    }
  }
  return SUCCESS;
}

int createOrderedBinaryTreeByTotal (CFO_TOTAL *root) {
  FILE *readFile;
  int close = 0;
  int line = 1;
  int counter = 0;
  int total = 0;
  int success = 0;
  char auxString[100];
  char UF[10];
  char *token;
  BAG bag;

  readFile = fopen("./doc/dadoscfo.csv", "r");

  if (readFile == NULL) {
    system("clear");
    printf("Erro ao abrir o arquivo dadoscfo.csv - cfo-total.c\\createOrderedBinaryTreeByTotal\n");
    sleep(2);
    exit(1);
  } else {
    /* Do Nothing. */
  }

  while (1) {
    if (feof(readFile)) {
      break;
    } else {
      fgets(auxString, 100, readFile);
      removeLineBreak(auxString);

      token = strtok(auxString, ";");
      while (token != NULL) {
        strcpy(bag[counter].word, token);
        token = strtok(NULL, ";");
        counter++;
      }

      strcpy(UF, bag[0].word);
      total = atoi(bag[10].word);

      success = insertVertexsOrderedByTotal(root, line, UF, total);

      counter = 0;
      line++;
    }
  }

  close = fclose(readFile);

  if (close != FAIL) {
    printf("Erro ao fechar o arquivo dadoscfo.csv - cfo-total.c\\createOrderedBinaryTreeByTotal\n");
    sleep(2);
    exit(1);
  } else {
    /* Do Nothing. */
  }
  return success;
}