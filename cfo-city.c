#include "lib/library.h"

CFO_CITY *createCityBinaryTree () {
  CFO_CITY *root = (CFO_CITY *) malloc(sizeof(CFO_CITY));
  if (root != NULL) {
    *root = NULL;
  } else {
    system("clear");
    printf("Erro ao tentar alocar ponteiro - cfo-city.c\\createCityBinaryTree\n");
    sleep(2);
    exit(1);
  }
  return root;
}

void releaseCity (CITY *vertex) {
  if (vertex == NULL) {
    return;
  } else {
    /* Do Nothing. */
  }
  releaseCity(vertex->left);
  releaseCity(vertex->right);
  free(vertex);
  vertex = NULL;
  return;
}

void releaseBinaryTreeCity (CFO_CITY *root) {
  if (root == NULL) {
    return;
  } else {
    /* Do Nothing. */
  }
  releaseCity(*root);
  free(root);
  return;
}

void searchLineCity (CFO_CITY *root) {
  FILE *readFile;
  int close = 0;
  char auxString[1000];

  readFile = fopen("./doc/dadoscfo.csv", "r");

  if (readFile == NULL) {
    system("clear");
    printf("Erro ao abrir o arquivo dadoscfo.csv - cfo-city.c\\searchLineCity\n");
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
    printf("Erro ao fechar o arquivo dadoscfo.csv - cfo-city.c\\searchLineCity\n");
    sleep(2);
    exit(1);
  } else {
    /* Do Nothing. */
  }
  return;
}

void queryCityBinaryTree (CFO_CITY *root, char *city) {
  CITY *currentLeaf = *root;
  while (currentLeaf != NULL) {
    if (strcmp(city, currentLeaf->city) == 0) {
      searchLineCity(&currentLeaf);
    } else {
      /* Do Nothing. */
    }

    if (strcmp(city, currentLeaf->city) > 0) {
      currentLeaf = currentLeaf->right;
    } else {
      currentLeaf = currentLeaf->left;
    }
  }
  return;
}

void printTreeOrderedByCity (CFO_CITY *root) {
  if (root == NULL) {
    return;
  } else {
    /* Do Nothing. */
  }
  if (*root != NULL) {
    printTreeOrderedByCity(&((*root)->left));
    searchLineCity(root);
    printTreeOrderedByCity(&((*root)->right));
  }
}

int insertVertexsOrderedByCity (CFO_CITY *root, int line, char *city) {
  CITY *newVertex;
  newVertex = (CITY *) malloc(sizeof(CITY));
  newVertex->line = line;
  strcpy(newVertex->city, city);
  newVertex->left = NULL;
  newVertex->right = NULL;

  if (*root == NULL) {
    *root = newVertex;
  } else {
    CITY *currentLeaf = *root;
    CITY *previousLeaf = NULL;
    while (currentLeaf != NULL) {
      previousLeaf = currentLeaf;
      if (strcmp(city, currentLeaf->city) > 0) {
        currentLeaf = currentLeaf->right;
      } else {
        currentLeaf = currentLeaf->left;
      }
    }
    if (strcmp(city, previousLeaf->city) > 0) {
      previousLeaf->right = newVertex;
    } else {
      previousLeaf->left = newVertex;
    }
  }
  return SUCCESS;
}

int createOrderedBinaryTreeByCity (CFO_CITY *root) {
  FILE *readFile;
  int close = 0;
  int line = 1;
  int counter = 0;
  int success = 0;
  char auxString[100];
  char city[50];
  char *token;
  BAG bag;

  readFile = fopen("./doc/dadoscfo.csv", "r");

  if (readFile == NULL) {
    system("clear");
    printf("Erro ao abrir o arquivo dadoscfo.csv - cfo-city.c\\createOrderedBinaryTreeByCity\n");
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

      strcpy(city, bag[1].word);

      success = insertVertexsOrderedByCity(root, line, city);

      counter = 0;
      line++;
    }
  }

  close = fclose(readFile);

  if (close != FAIL) {
    printf("Erro ao fechar o arquivo dadoscfo.csv - cfo-city.c\\createOrderedBinaryTreeByCity\n");
    sleep(2);
    exit(1);
  } else {
    /* Do Nothing. */
  }
  return success;
}