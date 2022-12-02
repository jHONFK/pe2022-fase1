#include <stdio.h>
#define CLAUDIO_H_INCLUDED

char showMonthMenuOptions();
char showMainMenuOptions();
char showCostListToCalc();
int mainMenu(int navigationIndex);
int costCalc(int costToCalc);
float fuelCalc();
float tireCalc();
float insuranceCalc();
float storeResult(float expense, float expenseType);
float showResult();
int showResultCheck();