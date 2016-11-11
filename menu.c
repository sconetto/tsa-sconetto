#include "lib/library.h"

int interface () {
  int option = 0;
  system("clear");
  printf("------------------------------------------------------------------------------------------\n");
  printf("----     Consulta de cadastro do Conselho Federal de Odontologia (CFO) - Gerencial    ----\n");
  printf("------------------------------------------------------------------------------------------\n");
  printf("----                               Menu de Opções                                     ----\n");
  printf("------------------------------------------------------------------------------------------\n");
  printf("---- Escolha uma das opções listadas abaixo para consulta:                            ----\n");
  printf("---- 1) Importar Dados do CSV (dadoscfo.csv)                                          ----\n");
  printf("---- 2) Relatório Completo                                                            ----\n");
  printf("---- 3) Relatório por UF                                                              ----\n");
  printf("---- 4) Consultar dados por munípio                                                   ----\n");
  printf("---- 5) Sair                                                                          ----\n");
  printf("------------------------------------------------------------------------------------------\n");
  printf("---- OBS: Qualquer opção fora do intervalo de 1 e 5 é inválido para execução          ----\n");
  printf("---- OBS: Para consultar os relatórios é preciso primeiramente                        ----\n");
  printf("----      importar todos os dados, senão os relatórios ficarão em branco!             ----\n");
  printf("------------------------------------------------------------------------------------------\n\n");

  while (1) {
    printf("Insira a opção desejada: ");
    scanf("%d", &option);

    if (option <= 0 || option > 5) {
      printf("Opção inválida!\nTerminando execução\n");
      exit(1);
    } else {
      break;
    }
  }

  return option;
}

int orderMenu () {
  int option = 0;
  system("clear");
  printf("------------------------------------------------------------------------------------------\n");
  printf("---- A opção escolhida foi: 2) Relatório Completo                                     ----\n");
  printf("---- Qual forma deseja que o relatório esteja ordenado?:                              ----\n");
  printf("------------------------------------------------------------------------------------------\n");
  printf("---- 1) Ordenar por município                                                         ----\n");
  printf("---- 2) Ordenar por CD                                                                ----\n");
  printf("---- 3) Ordenar por Total                                                             ----\n");
  printf("---- 4) Voltar ao menu inicial                                                        ----\n");
  printf("------------------------------------------------------------------------------------------\n\n");

  while (1) {
    printf("Insira a opção desejada: ");
    scanf("%d", &option);

    if (option <= 0 || option > 4) {
      printf("Opção inválida!\nRetornando ao menu incial\n");
      sleep(3);
      return 4;
    } else {
      break;
    }
  }

  return option;
}

void menu (int option, CFO_CITY *cityRoot, CFO_CDs *cdsRoot, CFO_TOTAL *totalRoot) {
  char UF[10];
  char city[50];
  int counter = 0;
  int size = 0;
  int successCity = 0;
  int successTotal = 0;
  int successCDs = 0;

  system("clear");
  printf("------------------------------------------------------------------------------------------\n");
  switch (option) {
    case 1:
      printf("---- A opção escolhida foi: 1) Importar Dados para CSV                                ----\n");

      successCity = createOrderedBinaryTreeByCity(cityRoot);
      successTotal = createOrderedBinaryTreeByTotal(totalRoot);
      successCDs = createOrderedBinaryTreeByCDs(cdsRoot);

      if (successCity && successTotal && successCDs) {
        printf("---- Dados importados com sucesso!!                                                   ----\n");
        printf("------------------------------------------------------------------------------------------\n");
      } else {
        printf("---- Houve um erro na importação dos dados!!                                          ----\n");
        printf("------------------------------------------------------------------------------------------\n");
      }
      break;

    case 2:
      option = orderMenu();

      if (option == 1) {
        printf("---- A opção escolhida foi: 1) Ordenar por município                                  ----\n");
        printf("------------------------------------------------------------------------------------------\n");
        printf("---- Relatório ordenado por municípios                                                ----\n");
        printf("------------------------------------------------------------------------------------------\n");
        printf("---- UF - CIDADE - CDs - EPAOs - TPDs - LBs - TSBs - ASBs - APDs - EPOs - TOTAL       ----\n");
        printTreeOrderedByCity(cityRoot);
        printf("------------------------------------------------------------------------------------------\n");

      } else if (option == 2) {
        printf("---- A opção escolhida foi: 2) Ordenar por CD                                         ----\n");
        printf("------------------------------------------------------------------------------------------\n");
        printf("---- Relatório ordenado por CDs                                                       ----\n");
        printf("------------------------------------------------------------------------------------------\n");
        printf("---- UF - CIDADE - CDs - EPAOs - TPDs - LBs - TSBs - ASBs - APDs - EPOs - TOTAL       ----\n");
        printTreeOrderedByCDs(cdsRoot);
        printf("------------------------------------------------------------------------------------------\n");
      } else if (option == 3) {
        printf("---- A opção escolhida foi: 3) Ordenar por Total                                      ----\n");
        printf("------------------------------------------------------------------------------------------\n");
        printf("---- Relatório ordenado por Total                                                     ----\n");
        printf("------------------------------------------------------------------------------------------\n");
        printf("---- UF - CIDADE - CDs - EPAOs - TPDs - LBs - TSBs - ASBs - APDs - EPOs - TOTAL       ----\n");
        printTreeInOrderOfTotal(totalRoot);
        printf("------------------------------------------------------------------------------------------\n");
      } else if (option == 4) {
        option = interface();
        menu(option, cityRoot, cdsRoot, totalRoot);
      } else {
        /* Should never enter this. */
        printf("STDERR - ERROR!\n");
      }
      break;

    case 3:
      printf("---- A opção escolhida foi: 3) Relatório por UF                                       ----\n");
      printf("------------------------------------------------------------------------------------------\n");
      printf("Insira o UF (Estado) da consulta: ");
      cleanReadBuffer();
      readString(UF);
      size = strlen(UF);

      for (counter = 0; counter < size; ++counter) {
        UF[counter] = toupper(UF[counter]);
      }
      printf("------------------------------------------------------------------------------------------\n");
      printf("---- UF - CIDADE - CDs - EPAOs - TPDs - LBs - TSBs - ASBs - APDs - EPOs - TOTAL       ----\n");
      printTreeInDownwardOrder(totalRoot, UF);
      break;

    case 4:
      printf("---- A opção escolhida foi: 4) Consultar dados por município                          ----\n");
      printf("------------------------------------------------------------------------------------------\n");
      printf("Insira o município (Cidade) da consulta: ");
      cleanReadBuffer();
      readString(city);
      size = strlen(city);

      for (counter = 0; counter < size; ++counter) {
        city[counter] = toupper(city[counter]);
      }
      printf("------------------------------------------------------------------------------------------\n");
      printf("---- UF - CIDADE - CDs - EPAOs - TPDs - LBs - TSBs - ASBs - APDs - EPOs - TOTAL       ----\n");
      queryCityBinaryTree(cityRoot, city);
      break;

    case 5:
      printf("---- A opção escolhida foi: 5) Sair                                                   ----\n");
      printf("---- Finalizando a execução!                                                          ----\n");
      printf("------------------------------------------------------------------------------------------\n");
      releaseBinaryTreeCity(cityRoot);
      releaseBinaryTreeTotal(totalRoot);
      releaseBinaryTreeCDs(cdsRoot);
      exit(0);
      break;

    default:
      /* Should never enter this. */
      printf("STDERR - ERROR!\n");
      break;
  }
}