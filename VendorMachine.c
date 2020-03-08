#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 20 // MAX SIZE OF A NAME OF A PRODUCT

typedef struct {
	unsigned char initStock;
	unsigned char sold;
	float price;
	char* nume;

} product;

void read(product *product) {
	unsigned char nbProducts = 6, i;
	for (i = 0; i < nbProducts; i++) {
		product[i].nume = (char*) malloc(MAXN);
		if (!product[i].nume) {
			printf("Allocation failed for product with number %d", i);
			exit(1);
		} else {
			if (i == 0) {
				strcpy(product[i].nume, "Avira Prime");
				product[i].price = 75;
				product[i].initStock = 10;
			} else if (i == 1) {
				strcpy(product[i].nume, "Antivirus PRO");
				product[i].price = 35;
				product[i].initStock = 10;
			} else if (i == 2) {
				strcpy(product[i].nume, "Phantom VPN");
				product[i].price = 50;
				product[i].initStock = 10;
			} else if (i == 3) {
				strcpy(product[i].nume, "Password Manager");
				product[i].price = 20;
				product[i].initStock = 10;
			} else if (i == 4) {
				strcpy(product[i].nume, "Optimizer");
				product[i].price = 10;
				product[i].initStock = 10;
			} else {
				strcpy(product[i].nume, "System Speedup");
				product[i].price = 25;
				product[i].initStock = 10;
			} 
		}
	}
}

void print(product *product) {
	unsigned char nbProducts = 6, i;
	for (i = 0; i < nbProducts; i++) {
		printf("Numele Produsului: %s\n", product[i].nume);
		printf("Stocul la inceputul zilei: %hhu\n", product[i].initStock);
		printf("Numarul de produse vandute: %hhu \n", product[i].sold);
		printf("Pretul produsului: %.2f$\n", product[i].price);
		printf("\n\n");
	}
}

int payWithCard(product* products, int i) {
	int price = (int)products[i].price * 2;
	int funds = rand() % (price);
	if (funds > products[i].price) {
		funds -= products[i].price; // extraction from the card
		products[i].sold++; // products of type i sold
		printf("Payment approved\n");
		//return 1;
	} else {
		printf("Insufficient funds\n");
		//return 0;
	}
}

void printIndexes(product* products) {
	printf("[0] - Avira Prime\n");
	printf("[1] - Antivirus PRO\n");
	printf("[2] - Phantom VPN\n");
	printf("[3] - Password Manager\n");
	printf("[4] - Optimizer\n");
	printf("[5] - System Speedup\n");
}

int main() {
	srand((unsigned)time(NULL));
	unsigned char nbProducts = 6, answer;
	float money1 = 0, money2, change;
	int i, securityCode = 7442, newPassword1, newPassword2;
	clock_t t_start, t_stop;
	product* products = (product*) malloc (nbProducts * sizeof(product)); 
	if (!products) {
		printf("Allocation failed for products");
		exit(1);
	} else {
		read(products);
	}
	print(products);
	printIndexes(products);
	// while vendor machine is on
	while (1) {
		// show vendor machine
		// checking codes inserted
		while (1) {
			printf ("Insert the code of the desired product:\n");
			// i = code of the product;
			scanf("%d", &i);
			if (i > 5) {
				if (i == securityCode) {
					printf("Welcome Manager!\n");
					while(1) {
						printf("EXIT: [0]\nCHANGE PASSWORD: [1]\nSALLING DATA: [2]\nREFUEL STOCK: [3]\n");
						scanf("%hhu", &answer);
						// exit administrator run
						if (answer == 0) {
							break;
						} else if (answer == 1) {
							printf("Introduce a code between 4 and 8 digits:\n");
							printf("New Password: \n");
							scanf("%d", &newPassword1);
							printf("Enter Password Again: \n");
							scanf("%d", &newPassword2);
							if ((newPassword1 == newPassword2) && (1000 <= newPassword1) && (newPassword1 <= 99999999)) {
								securityCode = newPassword1;
							} else {
								printf ("Passwords are not matching or are not having the number of digits required\n");
							}
						} 
						else if (answer == 2) {
								float s=0;
								printf("Up to this point of the day, there have been sold:\n\n");
								for(i = 0;i <nbProducts; i++){
									printf("%hhu products of this type %s in value of %.2f \n",products[i].sold,products[i].nume,products[i].sold*products[i].price);
									s += products[i].sold*products[i].price;
								}
								printf("You have sold products in total value of %.2f\n\n\n", s);

						} else if (answer == 3) {
							float s = 0;
							for (i = 0; i <nbProducts; i++) {
								s += products[i].sold * products[i].price;
								products[i].sold = 0;
							}
							printf("Total income: %.2f$\n\n", s);
						} else {
							printf("Invalid code! Choose another one!\n");
						}
					}
				} else { 
					printf("Incorrect Code\n");
				}
			} else {
				t_start = clock();
				break;
			}
		}
		if (i != securityCode) {
			if (products[i].sold == products[i].initStock) {
				printf("Unavailable product! Choose another one!\n");
			} else {
				printf("Product price: %.2f$\n", products[i].price);
				printf("How do you want to pay?\n");
				printf("Card:0 Cash:1\n");
				// aici dau stop la timer
				/*t_stop = clock();
				//printf("HAHA\n");
				answer = 10;
				while (answer == 10) {
					t_stop = clock();
					if ((t_stop - t_start) / CLOCKS_PER_SEC >= 2) {
						answer = 10;
						break;
					}
				}		
				//scanf("%hhu", &answer);
				//printf("SUNT AICI!!!");
				if (answer == 10) {
					printf("Timp pierdut\n");
					break;
				}/*
				/*while ((t_stop - t_start) / CLOCKS_PER_SEC < 2) {
					t_stop = clock();
				}*/
				//printf("HAHA1\n");
				// daca stop - start >= 15 reia ciclu;
				scanf("%hhu", &answer);
				if (answer > 1) {
					; // it regoes to the insertion of the code
				} else {
					// card payment selected
					if (answer == 0) {
						printf("Approach the card!\n");
						payWithCard(products, i);
					}
					// cash payment selected 
					else {
						// read money introduced
						// arata produsul
						printf("Introduce the money:\n");
						scanf("%f", &money1);
						printf("Credit: %.2f\n", money1);
						while (money1 < products[i].price){
							printf("Left to introduce: %.2f\n", products[i].price - money1);
							scanf("%f", &money2);
							money1 += money2;
							printf("Credit: %.2f\n", money1);
						}
						products[i].sold++;
						printf("Payment approved!\n");
						change = money1 - products[i].price;
						//grafic(product[i].nume)
						printf("Your change: %.2f\n", change); // change is returned
						money1 = 0;
					}
				}
			}
		}
	}
	return 0;
}