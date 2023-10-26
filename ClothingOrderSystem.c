#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) 
{
		
	char gender[2]; 
	char clothing[20]; 
	char size[2]; 
	char payment[10]; 
	char confirm[5] = "Yes";
	int num;
	int num_r_upologisti; 
	int num_r_xristi;
	int num_1;
	int num_2;
	int num_3;
	int c = 0; 
	int upoloipo_upologisti = 0; 
	int upoloipo_xristi = 0; 
	int counter_card = 0;
	float cost;
	float cost_new;
	
	do
	{	
		if(strcmp(confirm, "Yes") != 0)
		{
			system("cls");
			printf("Payment cancelled.\n");
		}
		
		printf("Welcome to Dem & Oup.\nPlease type your gender(M for Male/F for Female).\n");
		do
		{
		scanf("%s", &gender);
		if(strcmp(gender, "M") != 0 && strcmp(gender, "F") != 0)
			printf("Wrong input.\nPlease type correctly your gender(M for Male/F for Female).\n");
		}
		while(strcmp(gender, "M") != 0 && strcmp(gender, "F") != 0);
		
		
		printf("What would you like to buy?(Tops/Bottoms/Accessories)\n");
		do
		{
		scanf("%s", &clothing);
		if(strcmp(clothing,"Tops") != 0 && strcmp(clothing,"Bottoms") != 0 && strcmp(clothing,"Accessories") != 0)
			printf("Wrong input.\nPlease type correctly the category of clothing you would you like to buy.\n(Tops/Bottoms/Accessories)\n");
		}
		while(strcmp(clothing,"Tops") != 0 && strcmp(clothing,"Bottoms") != 0 && strcmp(clothing,"Accessories") != 0);
	
		printf("Available sizes: 1 Small, 1 Medium, 1 Large.\n");
		
		printf("Please pick size(Type S for Small/M for Medium/L for Large).\n");
		do
		{
			scanf("%s", &size);
			if(strcmp(size, "S") != 0 && strcmp(size, "M") != 0 && strcmp(size, "L") != 0)
				printf("Wrong input.\nPlease type correctly the size you would like to buy.\n(S for Small/M for Medium/L for Large)\n");
		}
		while(strcmp(size, "S") != 0 && strcmp(size, "M") != 0 && strcmp(size, "L") != 0);
		
		
		if(strcmp(gender, "F") == 0)
		{
			if(strcmp(clothing, "Tops") == 0)
			{
				cost = 4.99;
			}
			else if(strcmp(clothing, "Bottoms") == 0)
			{
				cost = 12.99;
			}
			else if(strcmp(clothing, "Accessories") == 0)
			{
				cost = 7.99;
			}
		}
		else if(strcmp(gender, "M") == 0)
		{
			if(strcmp(clothing, "Tops") == 0)
			{
				cost = 5.99;
			}
			else if(strcmp(clothing, "Bottoms") == 0)
			{
				cost = 15.99;
			}
			else if(strcmp(clothing, "Accessories") == 0)
			{
				cost = 1.99;
			}
		}
		
		printf("You chose: %s.\nPrice: %.2f Euros.\n", clothing, cost);
				
		do
		{
			printf("How would you like to pay?(Type Card/Store)\n");
			scanf("%s", &payment);
			if(strcmp(payment,"Card") != 0 && strcmp(payment,"Store") != 0)
				printf("Wrong input.\nPlease type correctly the payment method.(Card/Store)\n");
		}
		while(strcmp(payment,"Card") != 0 && strcmp(payment,"Store") != 0);
	
	
		if(strcmp(payment,"Card") == 0)
		{
			
			printf("Please type a 5-digit integer number.\n");
			
			do
			{
				scanf("%d", &num);
				if(num < 10000 || num > 99999)  
				{
					printf("Wrong input:This is not a 5-digit integer number.\nPlease type a 5-digit integer number.\n");
				}
			}
			while(num < 10000 || num > 99999);
			
			upoloipo_upologisti = num % 5;
			
			printf("Please type the division remainder of the division: %d / 5.\n", num);
			scanf("%d", &upoloipo_xristi);
				
			if(upoloipo_upologisti == upoloipo_xristi)
			{
				printf("Correct.\nYou shall continue with the payment.\n");
			}
			else if(upoloipo_upologisti != upoloipo_xristi)
			{
				do
				{
					counter_card++;
					printf("Wrong number.\nPlease type the correct division remainder of the division: %d / 5.\n", num);
					scanf("%d", &upoloipo_xristi);
				}
		 		while((counter_card < 2) && (upoloipo_upologisti != upoloipo_xristi));
			  		
				if(upoloipo_upologisti == upoloipo_xristi)
				{
					printf("Correct.\nYou shall continue with the payment.\n");
				}
				else if(upoloipo_upologisti != upoloipo_xristi)
				{
					break;
				}
			}  	
		}
		else if(strcmp(payment,"Store") == 0)	
		{
			printf("Please type a 3-digit number.\n");
			do
			{
				scanf("%d", &num);
				if(num < 100 || num > 999)  
				{
					printf("Wrong input:This is not a 3-digit integer number.\nPlease type a 3-digit integer number.\n");
				}
			}
			while(num < 100 || num > 999);	
		
			// px 387 
			num_1 = num / 100; // 387 / 100 = 3
			num_2 = (num % 100)/10; // 87 / 10 = 8 
			num_3 = (num % 10); // 387 % 10 = 7
			num_r_upologisti = num_3 * 100 + num_2 * 10 + num_1;
			
			printf("Please type the reverse number of the one you just entered.\n");
			
			do 
			{
				scanf("%d", &num_r_xristi);
				if(num_r_xristi != num_r_upologisti)
				{
					printf("Wrong reverse number.\nPlease type the correct reverse number.\n");	
				}
				else if(num_r_xristi == num_r_upologisti)
				{
					c = 1;
					cost_new = cost - (0.20 * cost);
					printf("Correct reverse number.\nTherefore: You just earned a 20 percent discount. New price: %.2f Euros.\n", cost_new);
				}
			}
			while(num_r_xristi != num_r_upologisti);	
		}
		
		
		printf("Your gender is: %s.\n", gender);	
		printf("You chose: %s.\n", clothing);
		printf("You chose the size: %s.\n", size);
		printf("You chose: %s as a method of payment.\n", payment);
		if(c == 1)
			printf("Final price: %.2f Euros.\n", cost_new);
		else if(c == 0)
			printf("Final price: %.2f Euros.\n", cost);
			
		printf("Do you confirm those data?(Type Yes/No)\n");
		scanf("%s", &confirm);
		
		
	}
	while(strcmp(confirm, "Yes") != 0);
	
	
	system("cls");
	
	
	if(upoloipo_upologisti != upoloipo_xristi)
		printf("You have entered three times in a row the wrong remainder.\nTherefore: Payment cancelled.\n");
	
	if(!(strcmp(payment,"Card") == 0 && upoloipo_upologisti != upoloipo_xristi))
	{
		printf("Thanks for your purchase. Here is your receipt:\n");
		printf("--------------------------------------------------------------------------------\n");
		printf("Payment method: %s\n", payment);
		printf("\t\t\tTotal products bought: 1\n");
		printf("\t\t\t   Price: %.2f euro\n", cost);
		if(c == 1)
		{	
			printf("\t\t\t  Discount: 20 percent\n");
			printf("\t\tFinal Price (after discount): %.2f euro\n\n", cost_new);
		}
		printf("\t\t\t  See you soon!\n");
		printf("--------------------------------------------------------------------------------\n");
	}
	return 0;
}
