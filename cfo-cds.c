#include "lib/library.h"

CFO_CDs *createCDsBinaryTree () {
  CFO_CDs *root = (CFO_CDs *) malloc(sizeof(CFO_CDs));
  if (root != NULL) {
    *root = NULL;
  } else {
    system("clear");
    printf("Erro ao tentar alocar ponteiro - cfo-cds.c\\createCDsBinaryTree\n");
    sleep(2);
    exit(1);
  }
  return root;
}

void releaseCDs (CDs *vertex) {
  if (vertex == NULL) {
    return;
  } else {
    /* Do Nothing. */
  }
  releaseCDs(vertex->left);
  releaseCDs(vertex->right);
  free(vertex);
  vertex = NULL;
  return;
}

void releaseBinaryTreeCDs (CFO_CDs *root) {
  if (root == NULL) {
    return;
  } else {
    /* Do Nothing. */
  }
  releaseCDs(*root);
  free(root);
  return;
}

void searchLineCDs (CFO_CDs *root) {
  FILE *readFile;
  int close = 0;
  char auxString[1000];

  readFile = fopen("./doc/dadoscfo.csv", "r");

  if (readFile == NULL) {
    system("clear");
    printf("Erro ao abrir o arquivo dadoscfo.csv - cfo-cds.c\\searchLineCDs\n");
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
    printf("Erro ao fechar o arquivo dadoscfo.csv - cfo-cds.c\\searchLineCDs\n");
    sleep(2);
    exit(1);
  } else {
    /* Do Nothing. */
  }
  return;
}

void printTreeOrderedByCDs (CFO_CDs *root) {
  if (root == NULL) {
    return;
  } else {
    /* Do Nothing. */
  }
  if (*root != NULL) {
    printTreeOrderedByCDs(&((*root)->left));
    searchLineCDs(root);
    printTreeOrderedByCDs(&((*root)->right));
  }
}

int insertVertexsOrderedByCDs (CFO_CDs *root, int line, int cds) {
  CDs *newVertex;
  newVertex = (CDs *) malloc(sizeof(CDs));
  newVertex->line = line;
  newVertex->cds = cds;
  newVertex->left = NULL;
  newVertex->right = NULL;

  if (*root == NULL) {
    *root = newVertex;
  } else {
    CDs *currentLeaf = *root;
    CDs *previousLeaf = NULL;
    while (currentLeaf != NULL) {
      previousLeaf = currentLeaf;
      if (cds > currentLeaf->cds) {
        currentLeaf = currentLeaf->right;
      } else {
        currentLeaf = currentLeaf->left;
      }
    }
    if (cds > previousLeaf->cds) {
      previousLeaf->right = newVertex;
    } else {
      previousLeaf->left = newVertex;
    }
  }
  return SUCCESS;
}

int createOrderedBinaryTreeByCDs (CFO_CDs *root) {
  FILE *readFile;
  int close = 0;
  int line = 1;
  int counter = 0;
  int cds = 0;
  int success = 0;
  char auxString[100];
  char *token;
  BAG bag;

  readFile = fopen("./doc/dadoscfo.csv", "r");

  if (readFile == NULL) {
    system("clear");
    printf("Erro ao abrir o arquivo dadoscfo.csv - cfo-cds.c\\createOrderedBinaryTreeByCDs\n");
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

      cds = atoi(bag[2].word);

      success = insertVertexsOrderedByCDs(root, line, cds);

      counter = 0;
      line++;
    }
  }

  close = fclose(readFile);

  if (close != FAIL) {
    printf("Erro ao fechar o arquivo dadoscfo.csv - cfo-cds.c\\createOrderedBinaryTreeByCDs\n");
    sleep(2);
    exit(1);
  } else {
    /* Do Nothing. */
  }
  return success;
}