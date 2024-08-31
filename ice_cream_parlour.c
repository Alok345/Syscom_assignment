#include <stdio.h>
#define MAX_FLAVOURS 5
typedef struct{
  char name[30];
  float price;
  int stock;
}IceCreamFlavour;
void displayMenu(IceCreamFlavour flavours[], int numFlavours){{
  printf("Available Ice Cream Flavours:\n");
  for(int i=0; i<numFlavours; i++){
    printf("%d. %s - $%.2f (Stock: %d)\n", i+1, flavours[i].name, flavours[i].price, flavours[i].stock);
  }
}

void takeOrders(IceCreamFlavour flavor[],int numFlavours){
  int choice,quantity;
  float total=0;

  displayMenu(flavor,numFlavours);
  printf("\nEnter the number of the flavour you want to order: ");
  scanf("%d", &choice);

  if(choice<1 || choice>numFlavours){
    printf("Invalid choice. Please try again.\n");
    return;
  
}

  printf("Enter the quantity of the flavour: ");
  scanf("%d", &quantity);
  if(quantity>flavor[choice-1].stock){
    printf("Sorry, we don't have enough stock for that quantity.\n");
    return;
  }
  
  flavor[choice-1].stock -= quantity;
  total =quantity*flavor[choice-1].price;

  printf("\nYour order summary is:\n");
  printf("Flavour: %s\n", flavor[choice-1].name);
  printf("Quantity: %d\n", quantity);
  printf("Total cost: $%.2f\n", total);

}

int main(){
  IceCreamFlavour flavor[MAX_FLAVOURS]={
    {"vanila",3.50,10},
    {"choclate",4.00,10},
    {"strawberry",3.75,10},
    {"mango",4.25,10},
    {"blueberry",4.00,10}
  };
  int option;

  while(1){
    printf("1. display options");
    printf("\n2. place order ice cream");
    printf("\n3. exit");
    printf("\nEnter your choice: ");
    scanf("%d", &option);

    switch(option){
      case 1:
        displayMenu(flavor,MAX_FLAVOURS);
        break;
      case 2:
        takeOrders(flavor,MAX_FLAVOURS);
        break;
      case 3:
        printf("Thank you for visiting our ice cream parlour.\n");
        return 0;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }
  return 0;
}

