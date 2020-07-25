// Copyright @StimDoarC (Petruc Rares, Mircea Andrei, Ciineanu Stefan Andrei) 08.03.2020 HackItAll preselectii
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 20 // MAX SIZE OF A NAME OF A PRODUCT
#define KRED  "\x1B[31m"
#define KBLU  "\x1B[34m"
#define KYEL  "\x1B[33m"
#define KGRN  "\x1B[32m"
#define KCYN  "\x1B[36m"
#define KNRM  "\x1B[0m"

#define entr() (printf("\n"))


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

void printIndexes(product* products) {
	printf("[0] - Avira Prime\n");
	printf("[1] - Antivirus PRO\n");
	printf("[2] - Phantom VPN\n");
	printf("[3] - Password Manager\n");
	printf("[4] - Optimizer\n");
	printf("[5] - System Speedup\n");
}

int answer1 (int securityCode) {
	int newPassword1, newPassword2;
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
	return securityCode;
}

void answer2(product *products) {
	float s=0;
	int i, nbProducts = 6;
	printf("Up to this point of the day, there have been sold:\n\n");
	for(i = 0;i <nbProducts; i++){
		printf("%hhu products of this type %s in value of %.2f$ \n",products[i].sold,products[i].nume,products[i].sold*products[i].price);
		s += products[i].sold*products[i].price;
	}
	printf("You have sold products in total value of %.2f$\n\n\n", s);
}

void answer3(product* products) {
	float s = 0;
	unsigned char i, nbProducts = 6;
	for (i = 0; i <nbProducts; i++) {
		s += products[i].sold * products[i].price;
		products[i].sold = 0;
	}
	printf("Total income: %.2f$\n\n", s);
}

int managerRun(product* products, int *securityCode) {
	unsigned char answer, nbProducts = 6, i;
	printf("Welcome Manager!\n");
	while(1) {
		printf("EXIT: [0]\nCHANGE PASSWORD: [1]\nSALLING DATA: [2]\nREFUEL STOCK: [3]\n");
		scanf("%hhu", &answer);
		// exit administrator run
		if (answer == 0) {
			return answer;
		} else if (answer == 1) {
			*securityCode = answer1(*securityCode);
		} 
		else if (answer == 2) {
			answer2(products);
		} else if (answer == 3) {
			answer3(products);
		} else {
			printf("Invalid code! Choose another one!\n");
			}
		}
}

void centre() {
	for (int i = 0; i < 15; i++)
    	printf(" ");
}

void top() {
	centre(); 
    printf(" "); 
    for (int i = 0; i < 48; i++) printf("_");
    printf(" ");	
    entr(); 
}
void bottom() {
	centre(); printf("|"); 
    for (int i = 0; i < 48; i++) printf("_");
    printf("|");	
    entr(); 
}

void sides() {
   	centre(); printf("|"); 
   	for (int i = 0; i < 22; i++) printf(" ");
   	printf("%s|", KBLU);	
   	for (int i = 0; i < 25; i++) printf(" ");	
   	printf("%s|", KNRM);
   	entr();
}

void line1() {
	centre(); printf("|"); 
   	for (int i = 0; i < 6; i++) printf(" ");
   	printf("_");
   	for (int i = 0; i < 15; i++) printf(" ");
   	printf("%s|", KBLU);
   	for (int i = 0; i < 25; i++) printf(" ");		
   	printf("%s|", KNRM);
   	entr();
}

void line2() {
	centre(); printf("|"); 
   	for (int i = 0; i < 5; i++) printf(" ");
   	printf("| |");
   	for (int i = 0; i < 5; i++) printf(" ");
   	printf("/|");
   	for (int i = 0; i < 7; i++) printf(" ");	
   	printf("%s|", KBLU);	
   	for (int i = 0; i < 5; i++) printf(" ");	
   	printf("%s( 0 )", KNRM);	
   	for (int i = 0; i < 5; i++) printf(" ");	
   	printf("%s( 1 )", KNRM);	
   	for (int i = 0; i < 5; i++) printf(" ");	
   	printf("%s|", KNRM);
   	entr();
}

void line3() {
	centre(); printf("|"); 
   	for (int i = 0; i < 5; i++) printf(" ");
   	printf("|_|");
   	for (int i = 0; i < 5; i++) printf(" ");
   	printf(" |");
   	for (int i = 0; i < 7; i++) printf(" ");	
   	printf("%s|", KBLU);	
   	for (int i = 0; i < 4; i++) printf(" ");	
   	printf("%s*CARD*", KYEL);	
   	for (int i = 0; i < 5; i++) printf(" ");	
   	printf("%s*CASH*", KYEL);	
   	for (int i = 0; i < 4; i++) printf(" ");
   	printf("%s|", KNRM);
   	entr();
}

void lines() {
	centre(); printf("|");
	for (int i = 0; i < 2; i++) printf(" ");
	for (int i = 0; i < 17; i++) printf("%s-", KRED);
	for (int i = 0; i < 3; i++) printf(" ");	
   	printf("%s|", KBLU);	
   	for (int i = 0; i < 25; i++) printf(" ");	
	printf("%s|", KNRM);
   	entr();
}

void line5() {
	centre(); printf("|"); 
   	for (int i = 0; i < 6; i++) printf(" ");
   	printf("_");
   	for (int i = 0; i < 7; i++) printf(" ");
   	printf("_");
   	for (int i = 0; i < 7; i++) printf(" ");	
   	printf("%s|", KBLU);	
   	for (int i = 0; i < 4; i++) printf(" ");		
   	for (int i = 0; i < 17; i++) printf("%s_", KGRN);	
   	for (int i = 0; i < 4; i++) printf(" ");
   	printf("%s|", KNRM);
   	entr();	
}

void line6() {
	centre(); printf("|"); 
   	for (int i = 0; i < 6; i++) printf(" ");
   	printf("_|");
   	for (int i = 0; i < 6; i++) printf(" ");
   	printf("_|");
   	for (int i = 0; i < 6; i++) printf(" ");	
   	printf("%s|", KBLU);	
   	for (int i = 0; i < 4; i++) printf(" ");	
   	printf("%s|  ", KGRN);
   	printf("%s1", KCYN);
   	printf("%s |  ", KGRN);
   	printf("%s2", KCYN);
   	printf("%s  | ", KGRN);
   	printf("%s3", KCYN);
   	printf("%s  |", KGRN);
   	for (int i = 0; i < 4; i++) printf(" ");
   	printf("%s|", KNRM);
   	entr();	
}

void line7() {
	centre(); printf("|"); 
   	for (int i = 0; i < 5; i++) printf(" ");
   	printf("|_");
   	for (int i = 0; i < 7; i++) printf(" ");
   	printf("_|");
   	for (int i = 0; i < 6; i++) printf(" ");	
   	printf("%s|", KBLU);	
    for (int i = 0; i < 4; i++) printf(" ");	
   	printf("%s|  ", KGRN);
   	printf("%s4", KCYN);
   	printf("%s |  ", KGRN);
   	printf("%s5", KCYN);
   	printf("%s  | ", KGRN);
   	printf("%s6", KCYN);
   	printf("%s  |", KGRN);
   	for (int i = 0; i < 4; i++) printf(" ");
   	printf("%s|", KNRM);
   	entr();
}

void lines8() {
	centre(); printf("|");
	for (int i = 0; i < 2; i++) printf(" ");
	for (int i = 0; i < 17; i++) printf("%s-", KRED);
	for (int i = 0; i < 3; i++) printf(" ");	
   	printf("%s|", KBLU);	
   	for (int i = 0; i < 4; i++) printf(" ");	
   	printf("%s|  ", KGRN);
   	printf("%s7", KCYN);
   	printf("%s |  ", KGRN);
   	printf("%s8", KCYN);
   	printf("%s  | ", KGRN);
   	printf("%s9", KCYN);
   	printf("%s  |", KGRN);
   	for (int i = 0; i < 4; i++) printf(" ");
	printf("%s|", KNRM);
   	entr();
}

void line9() {
	centre(); printf("|"); 
   	for (int i = 0; i < 7; i++) printf(" ");
   	for (int i = 0; i < 7; i++) printf(" ");
   	printf("_");
   	for (int i = 0; i < 7; i++) printf(" ");	
   	printf("%s|", KBLU);	
   	for (int i = 0; i < 4; i++) printf(" ");	
   	printf("%s|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|  ", KGRN);
   	for (int i = 0; i < 2; i++) printf(" ");
   	printf("%s|", KNRM);
   	entr();	
}

void line10() {
	centre(); printf("|"); 
   	for (int i = 0; i < 5; i++) printf(" ");
   	printf("|_");	
   	for (int i = 0; i < 6; i++) printf(" ");
   	printf("|_");
   	for (int i = 0; i < 7; i++) printf(" ");	
   	printf("%s|", KBLU);	
   	for (int i = 0; i < 25; i++) printf(" ");	
   	printf("%s|", KNRM);
   	entr();	
}

void line11() {
	centre(); printf("|"); 
   	for (int i = 0; i < 6; i++) printf(" ");
   	printf(" |");	
   	for (int i = 0; i < 6; i++) printf(" ");
   	printf("_|");
   	for (int i = 0; i < 6; i++) printf(" ");	
   	printf("%s|", KBLU);	
   	for (int i = 0; i < 4; i++) printf(" ");		
   	for (int i = 0; i < 17; i++) printf("%s_", KYEL);	
   	for (int i = 0; i < 4; i++) printf(" ");
   	printf("%s|", KNRM);
   	entr();	
}

void lines12() {
	centre(); printf("|");
	for (int i = 0; i < 2; i++) printf(" ");
	for (int i = 0; i < 17; i++) printf("%s-", KRED);
	for (int i = 0; i < 3; i++) printf(" ");	
   	printf("%s|", KBLU);	
   	for (int i = 0; i < 4; i++) printf(" ");	
   	printf("%s|", KYEL);
    for (int i = 0; i < 15; i++) printf("%s ", KYEL);
    printf("%s|", KYEL);	
   	for (int i = 0; i < 4; i++) printf(" ");
	printf("%s|", KNRM);
   	entr();
}

void lines12i() {
	centre(); printf("|");
	for (int i = 0; i < 2; i++) printf(" ");
	for (int i = 0; i < 17; i++) printf("%s-", KRED);
	for (int i = 0; i < 3; i++) printf(" ");	
   	printf("%s|", KBLU);	
   	for (int i = 0; i < 4; i++) printf(" ");	
   	printf("%s|", KYEL);
    for (int i = 0; i < 4; i++) printf(" ");	
    for (int i = 0; i < 7; i++) printf("%s_", KRED);
    for (int i = 0; i < 4; i++) printf(" ");		
    printf("%s|", KYEL);	
   	for (int i = 0; i < 4; i++) printf(" ");
	printf("%s|", KNRM);
   	entr();
}

void sides13() {
   	centre(); printf("|"); 
   	for (int i = 0; i < 22; i++) printf(" ");
   	printf("%s|", KBLU);	
   	for (int i = 0; i < 4; i++) printf(" ");	
   	printf("%s|", KYEL);
    for (int i = 0; i < 15; i++) printf("%s ", KYEL);
    printf("%s|", KYEL);	
   	for (int i = 0; i < 4; i++) printf(" ");
   	printf("%s|", KNRM);
   	entr();
}

void sides13i(int n) {
   	centre(); printf("|"); 
   	for (int i = 0; i < 22; i++) printf(" ");
   	printf("%s|", KBLU);	
   	for (int i = 0; i < 4; i++) printf(" ");	
   	printf("%s|", KYEL);	
    for (int i = 0; i < 4; i++) printf(" ");
    printf("%s|__", KRED); 
	printf("%s", KNRM);
    printf("%d", n);	
    printf("%s__|", KRED);
   	for (int i = 0; i < 4; i++) printf(" ");
   	printf("%s|", KYEL);	
   	for (int i = 0; i < 4; i++) printf(" ");	
   	printf("%s|", KNRM);
   	entr();
}

void sides14() {
   	centre(); printf("|"); 
   	for (int i = 0; i < 22; i++) printf(" ");
   	printf("%s|", KBLU);	
   	for (int i = 0; i < 4; i++) printf(" ");	
   	printf("%s|_", KYEL);
    for (int i = 0; i < 13; i++) printf("%s_", KYEL);
    printf("%s_|", KYEL);	
   	for (int i = 0; i < 4; i++) printf(" ");
   	printf("%s|", KNRM);
   	entr();
}

void call_me() {
	top(); 
   	sides();
   	line1();	
   	line2();
   	line3();
   	lines();
   	line5();
   	line6();
   	line7();
   	lines8();
   	line9();
   	line10();
   	line11();
   	lines12();
   	sides13();
   	sides14();
   	sides();
   	bottom();	
   	entr();
}

void call_i(int nr) {
	top(); 
   	sides();
   	line1();	
   	line2();
   	line3();
   	lines();
   	line5();
   	line6();
   	line7();
   	lines8();
   	line9();
   	line10();
   	line11();
   	lines12i();
   	sides13i(nr);
   	sides14();
   	sides();
   	bottom();	
   	entr();
}

void wait() {
        clock_t t_start = clock(), t_stop = clock();
        while ((t_stop - t_start) / CLOCKS_PER_SEC < 3) {
                t_stop = clock();
        }
        return;
}

int payWithCash(product* products, int i) {
	float money1, money2, change;
	printf("Introduce the money: || EXIT: 0\n\n");
	scanf("%f", &money1);
	if (money1 == 0) return 0;
	printf("Credit: %.2f$\n", money1);
	while (money1 < products[i].price) {
		printf("Left to introduce: %.2f$\n", products[i].price - money1);
		scanf("%f", &money2);
		if (money2 == 0) {
			return 0;
		}
			money1 += money2;
			printf("Credit: %.2f$\n", money1);
		}
	products[i].sold++;
	printf("Payment approved!\n");
	call_i(i);
	change = money1 - products[i].price;
	printf("Your change: %.2f$\n\n\n", change); // change is returned
	money1 = 0;
	wait();
	return 1;
}


int payWithCard(product* products, int i) {
	int price = (int)products[i].price * 2;
	int funds = rand() % (price);
	if (funds > products[i].price) {
		funds -= products[i].price; // extraction from the card
		products[i].sold++; // products of type i sold
		printf("Payment approved\n\n\n");
		call_i(i);
		wait();
		return 1;
	} else {
		printf("Insufficient funds\n\n\n");
		printf("Press 1 if you want to go back\n");
		//int answer;
		return 0;
	}
}

int main() {
	srand((unsigned)time(NULL));
	unsigned char nbProducts = 6, answer;
	int securityCode = 7442, i;
	product* products = (product*) malloc (nbProducts * sizeof(product)); 
	if (!products) {
		printf("Allocation failed for products");
		exit(1);
	} else {
		read(products);
	}
	//print(products);
	printIndexes(products);
	// while vendor machine is on
	while (1) {
		call_me();
		// show vendor machine
		// checking codes inserted
		while (1) {
			printf ("Insert the code of the desired product:\n");
			// i = code of the product;
			scanf("%d", &i);
			if (i > 5) {
				if (i == securityCode) { 
					managerRun(products, &securityCode);
				} else {
					printf("Incorrect Code\n");
				}
			} else {
				break;
			}
		}
		if (i != securityCode) {
			if (products[i].sold == products[i].initStock) {
				printf("Unavailable product! Choose another one!\n");
			} else {
				printf("\nProduct price: %.2f$\n", products[i].price);
				printf("How do you want to pay?\n\n");
				while (1) {
					printf("Card:0 || Cash:1 || GoBack: any other key\n\n");
					scanf("%hhu", &answer);
					if (answer > 1) {
						break; // it regoes to the insertion of the code
					} else {
						// card payment selected
						if (answer == 0) {
							printf("Approach the card!\n\n");
							if (payWithCard(products, i)) break;
							else continue;
						}
						// cash payment selected 
						else {
							// read money introduced
							// arata produsul
							//printf("Introduce the money!\n\n");
							if (payWithCash(products, i) == 0) continue;
							else break;
						}
					}
				}
			}
		}
	}
	return 0;
}