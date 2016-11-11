#include "lib/library.h"

int main () {
  int option = 0;
  char exit = ' ';
  CFO_CITY *cityRoot;
  CFO_TOTAL *totalRoot;
  CFO_CDs *cdsRoot;

  setlocale(LC_ALL, "Portuguese");

  cityRoot = createCityBinaryTree();
  totalRoot = createTotalBinaryTree();
  cdsRoot = createCDsBinaryTree();

  while (1) {
    system("clear");
    option = interface();
    menu(option, cityRoot, cdsRoot, totalRoot);
    printf("Deseja retornar ao menu? (S\\N): ");
    scanf(" %c", &exit);
    exit = toupper(exit);
    if (exit == 'N') {
      printf("---- Finalizando a execução!                                                          ----\n");
      printf("------------------------------------------------------------------------------------------\n");
      releaseBinaryTreeCity(cityRoot);
      releaseBinaryTreeTotal(totalRoot);
      releaseBinaryTreeCDs(cdsRoot);
      break;
    } else {
      /* Do Nothing. */
    }
  }
  return 0;
}
