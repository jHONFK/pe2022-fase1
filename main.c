#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "claudio.h"

int main(void) {
  int mainMenuNavigationIndex;
  printf("Bem vindo ao sistema TruckCost, caminhoneiro!\n");
  showMainMenuOptions();
  scanf("%d",&mainMenuNavigationIndex);
  mainMenu(mainMenuNavigationIndex);
  
  return 0;
}