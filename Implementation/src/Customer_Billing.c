 #include "Customer_billing.h"
  struct account {
	char name[100];
	int acct_no;
	long mobile_no;
	char city[100];
	float balance;
  }customer[1000];
int cust_count = 0,act_no = 0, id = 1001;
int i = 0;
char ch, decision;
void main(){
	    printf("1: To add account on list\n");
	    printf("2: To search customer account\n");
        printf("3: TO pay a bill\n");
        printf("4: To print info of all customers\n");
        printf("5: Add balance\n");
        printf("6: exit\n");

        printf("\nselect what do you want to do?\n");
	    
    while(1){
        scanf("%c", &ch); 
        switch(ch){
            case '1':
                cust_count += 1;
                printf("%d", cust_count);
                int id = createAccount(i);
                i += 1;
                printf("\nYour Account Number is: %d\n\n", id);
                main();
                break;
            case '2':
                printf("Please enter the account number\n");
                scanf("%d", &act_no);
                searchACustomer(act_no);
                main();
                break;
            case '3':
                printf("Please enter the account no");
                scanf("%d", &act_no);
                payBill(act_no);
                main();
                break;
            case '4':
                printAllCustomers();
                main();
                break;
            case '5':
                printf("Please enter account no\n");
                scanf("%d", &act_no);
                addBalance(act_no);
                main();
                break;
            case '6':
                exit(0);
                break;
        }

    }
      return;
 }
    int createAccount(int ind){
          customer[ind].acct_no = id++;
          printf("Enther the name of the customer\n");
          scanf("%s", customer[ind].name);
          printf("mobile no.\n");
          scanf("%ld", &customer[ind].mobile_no);
          printf("city\n");
          scanf("%s", customer[ind].city);
          printf("How much balance you want to maintain\n");
          scanf("%f", &customer[ind].balance);
          return customer[ind].acct_no;
      }
      void searchACustomer(int act_no){
          for(int i = 0; i < cust_count; i++){
              if(customer[i].acct_no == act_no){
                  printf("Customer ID is: %d\n", customer[i].acct_no);
                  printf("Customer name: %s\n", customer[i].name);
                  printf("Customer mobile number: %ld\n", customer[i].mobile_no);
                  printf("customer city name: %s\n", customer[i].city);
                  printf("Account balance %.2f\n", customer[i].balance);
              }
          }
          return;
      }
      void payBill(int act_no){
          float amount = 0;
          printf("Enter the bill amount: ");
          scanf("%f", &amount);
          for(int i = 0; i < cust_count; i++){
              if (customer[i].acct_no == act_no){
                  if (customer[i].balance >= amount){
                      customer[i].balance -= amount;
                      printf("Updated Balance is: &.2f\n", customer[i].balance);
                  } else {
                      printf("please add balance\n");
                      addBalance(act_no);
                  }
              }
          }
          return;
      }
      void addBalance(int act_no){
          float amount = 0;
          printf("Enter the amount you want to add\n");
          scanf("%f", &amount);
          for(int i =0; i < cust_count; i++){
              if (customer[i].acct_no == act_no){
                  customer[i].balance += amount;
                  printf("Updated account balance: %.2f", customer[i].balance);
              }
          }
          return;
      }
      void printAllCustomers(){
          for(int i =0; i  <cust_count; i++){
              printf("CUSTOMER %d\n", (i+1));
              printf("\t Customer ID: %d\n", customer[i].acct_no);
              printf("\t customer name: %s\n", customer[i].name);
              printf("\t customer mobile: %d\n", customer[i].mobile_no);
              printf("\t Customer city: %s\n", customer[i].city);
              printf("\t Customer Balance: %.2f\n", customer[i].balance);
          }
          return;
      }
