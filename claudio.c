#include "claudio.h"

int showResultFlag=0;
float fuelExpense=0;
float tireExpense=0;
float insuranceExpense=0;
float insuranceMonthlyExpense=0;
float totalExpense=0;

//"Show" functions, basically big printf of menus
char showMonthMenuOptions(){
  printf("\n#############################\n");
  printf("1 - Janeiro\n");
  printf("2 - Fevereiro\n");
  printf("3 - Março\n");
  printf("4 - Abril\n");
  printf("5 - Maio\n");
  printf("6 - Junho\n");
  printf("7 - Julho\n");
  printf("8 - Agosto\n");
  printf("9 - Setembro\n");
  printf("10 - Outubro\n");
  printf("11 - Novembro\n");
  printf("12 - Dezembro\n");
  printf("#############################\n");
}

char showMainMenuOptions(){
  printf("\n#############################\n");
  printf("1 - Iniciar novo calculo de gastos\n");
  printf("2 - Sair\n");
  printf("#############################\n");
}

char showCostListToCalc(){
  printf("\n#############################\n");
  printf("1 - Calcular combustível\n");
  printf("2 - Calcular gasto em pneus\n");
  printf("3 - Calcular seguro\n");
  printf("4 - Voltar\n");
  printf("#############################\n");
}

//Real functions who calculate

int mainMenu(int navigationIndex){
  int costToCalc;  
  switch(navigationIndex){
    case 1:
      printf("\nIniciando novo calculo...\n");
      showCostListToCalc();
      scanf("%d",&costToCalc);
      costCalc(costToCalc);
      break;
    case 2:
      printf("\nEncerrando...\n");
      exit(0);
      break;
      
  }
}


int costCalc(int costToCalc){
  int mainMenuNavigationIndex;
  switch(costToCalc){
    case 1:
      printf("\nIniciando calculo de gastos de combustivel...\n");
      fuelCalc();
      break;
    case 2:
      printf("\nIniciando calculo de gastos em pneus...\n");
      tireCalc();
      break;
    case 3:
      printf("\nIniciando calculo de gastos de seguro...\n");
      insuranceCalc();
      break;
    case 4:
      showMainMenuOptions();
      scanf("%d",&mainMenuNavigationIndex);
      mainMenu(mainMenuNavigationIndex);
      
  }
}

float fuelCalc(){
  float fuelPrice;
  float kilometersDriven;
  float vehicleConsumption;
  float fuelConsumed;
  // float fuelExpense
  int costToCalc;
  float storeAndShowFlag;
  int overwritingCheck;
  
  //Overwriting check
  // printf("%d",fuelExpense);
  if(fuelExpense!=0){
    printf("\nATENCAO, VOCE JA INSERIU ESSES GASTOS, AO PREENCHER SOBRESCREVERA OS DADOS ATUAIS\n\n");
    printf("\nDESEJA CONTINUAR? DIGITE 0 PRA NAO E 1 PRA SIM\n\n");
    scanf("%d",&overwritingCheck);
    if(overwritingCheck==0){
      showCostListToCalc();
      scanf("%d",&costToCalc);
      costCalc(costToCalc);
    }
  }
  
  printf("Qual valor do litro do diesel onde o caminhao foi abastecido?\n");
  scanf("%f",&fuelPrice);
  
  printf("\nQuantos quilometros foram dirigidos apos abastecer?\n");
  scanf("%f",&kilometersDriven);
  
  printf("\nQual o consumo do seu caminhao? (Em km/l)\n");
  scanf("%f",&vehicleConsumption);

  fuelConsumed = kilometersDriven/vehicleConsumption;
  fuelExpense = fuelConsumed*fuelPrice;

  storeResult(fuelExpense, 1);
  
  //Continue next expense
  if(showResultFlag!=3){
    showCostListToCalc();
    scanf("%d",&costToCalc);
    costCalc(costToCalc);
  }
  
}

float tireCalc(){
  float pricePerTire;
  float tireQuantity;
  float kilometersDrivenAfterTireReplacement;
  int costToCalc;
  int overwritingCheck;
  int mainMenuNavigationIndex;
  
  //Overwriting check
  if(tireExpense!=0){
    printf("\nATENCAO, VOCE JA INSERIU ESSES GASTOS, AO PREENCHER SOBRESCREVERA OS DADOS ATUAIS\n\n");
    printf("\nDESEJA CONTINUAR? DIGITE 0 PRA NAO E 1 PRA SIM\n\n");
    scanf("%d",&overwritingCheck);
    if(overwritingCheck==0){
      showCostListToCalc();
      scanf("%d",&costToCalc);
      costCalc(costToCalc);
    }
  }

  printf("Quantos pneus você efeutou a troca?\n");
  scanf("%f",&tireQuantity);

  printf("\nQual preço pago por cada pneu\n");
  scanf("%f",&pricePerTire);

  tireExpense = tireQuantity*pricePerTire;

  storeResult(tireExpense, 2);

  //Continue next expense
  if(showResultFlag!=3){
    showCostListToCalc();
    scanf("%d",&costToCalc);
    costCalc(costToCalc);
  }
  
}

float insuranceCalc(){
  float insuranceAnnualExpense;
  int costToCalc;
  int overwritingCheck;
  
  //Overwriting check
  if(insuranceExpense!=0){
    printf("\nATENCAO, VOCE JA INSERIU ESSES GASTOS, AO PREENCHER SOBRESCREVERA OS DADOS ATUAIS\n\n");
    printf("\nDESEJA CONTINUAR? DIGITE 0 PRA NAO E 1 PRA SIM\n\n");
    scanf("%d",&overwritingCheck);
    if(overwritingCheck==0){
      showCostListToCalc();
      scanf("%d",&costToCalc);
      costCalc(costToCalc);
    }
  }
  
  printf("Informe o valor que a seguradora lhe cobra anualmente\n");
  scanf("%f",&insuranceAnnualExpense);

  insuranceMonthlyExpense = insuranceAnnualExpense/12;

  storeResult(insuranceAnnualExpense, 3);

  //Continue next expense
  if(showResultFlag!=3){
    showCostListToCalc();
    scanf("%d",&costToCalc);
    costCalc(costToCalc);
  }
    
  
}

float storeResult(float expense, float expenseType){
  //expenseType == 1 - Combustível
  //expenseType == 2 - Pneus
  //expenseType == 3 - Seguro
  
  
  
  if(expenseType == 1){
    showResultFlag++;
    fuelExpense = expense;
  }
  else if(expenseType == 2){
    showResultFlag++;
    tireExpense = expense;
  }
  else if(expenseType == 3){
    showResultFlag++;
    insuranceExpense = expense;
  }
  
  if(showResultFlag==3){
    showResult();
  }
  
}

float showResult(){
  totalExpense = fuelExpense+tireExpense+insuranceExpense;
  printf("\nSeu gasto total foi de: %.2f\n", totalExpense);
  printf("Seu gasto com combustível foi de: %.2f\n", fuelExpense);
  printf("Seu gasto com pneus foi de: %.2f\n", tireExpense);
  printf("Seu gasto anual com seguro foi de: %.2f\n", insuranceExpense);
  printf("Seu gasto mensal com seguro foi de: %.2f\n", insuranceMonthlyExpense);
  // printf("Seu gasto total por km rodado usando como base a quilometragem do combustivel foi de: %.2f\n");
  // printf("Seu gasto por km rodado de combustível foi de: %.2f\n");
  // printf("Seu gasto por km rodado de pneu foi de: %.2f\n");
  exit(0);
}

int showResultCheck(){
  if(showResultFlag==3){
    showResult();
  }
}