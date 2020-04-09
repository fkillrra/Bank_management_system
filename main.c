#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_CUSTOMER 5

#define NAME_LEN 20
#define BIRTH_LEN 8
#define ADDR_LEN 65
#define PHONE_LEN 13

struct customer
{									// Input Format
	char name[NAME_LEN];			// ex) Hwang Sunhong
	char birth[BIRTH_LEN];			// ex) 970414 -> YYYYMMDD
	unsigned int customer_num;		// ex) 1,2,3.. 
	char address[ADDR_LEN];			// ex) 65, Eunpyeong tunnel-ro, Eunpyeong-gu, Seoul, Republic of Korea
	char phone_num[PHONE_LEN];		// ex) 010-3342-9762
};

void setup();
void menu();

int new_acc(struct customer *a);
int edit(struct customer *a);
int transact(struct customer *a);
int erase(struct customer *a);

void see();
void view_list(struct customer *a);


int main()
{
	int i = 0;
	struct customer *a[MAX_CUSTOMER];
	
	for(i = 0; i < MAX_CUSTOMER; i++)
	{
		a[i] = (struct customer *)malloc(sizeof(struct customer));
		memset(a[i], 0, sizeof(struct customer));
	}
	
	setup();
	int idx = 0;
	while(1)
	{
		menu();
		scanf("%d", &idx);
		
		if(idx < 1 || idx > 7)
		{
			printf("\n\n\tPlease use it properly...\n");	// exception handling
			printf("\tidx error!\n");
			exit(-1);
		}
		
		switch(idx)
		{
			case 1:
				new_acc((struct customer *)&a);
				break;
			case 2:
				edit((struct customer *)&a);
				break;
			case 3:
				transact((struct customer *)&a);
				break;
			case 4:
				see();
				break;
			case 5:
				erase((struct customer *)&a);
				break;
			case 6:
				view_list((struct customer *)&a);
				break;
			case 7:
				printf("\n\tBye..!");
				exit(0);
		}
		
//		system("cls");
		printf("\n\n\t[+]------------ MAIN MENU ------------[+] \n\n");
	}
	
	return 0;
}

void setup()
{
	system("title Bank Management System");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
	
	printf("\n\n\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n\n\n");
	printf("\t\t[+]----- WELCOME TO THE MAIN MENU -----[+] \n\n");
}

void menu()
{
	printf("\t1.Create new account\n");
	printf("\t2.Update information of existing account\n");
	printf("\t3.For transactions\n");
	printf("\t4.Check the details of existing account\n");
	printf("\t5.Removing existing account\n");
	printf("\t6.View customer\'s list\n");
	printf("\t7.Exit\n");
	printf("\n\n\n\tEnter your choice: ");
	
}

int new_acc(struct customer *a)
{
	FILE *fd;
	fd = fopen("data.txt", "a+");
	
	system("cls");
	printf("\n\n\t\tnew_acc()\n");
	char *s[5] = {"Name", "Birth (YYYYMMDD)", "Customer Number(1~5)", "Address", "Phone Number (010-XXXX-XXXX)"};

	int i;
	for(i = 0; i < 5; i++)
	{
		printf("\n\t\t%s : ", s[i]);
		
		if(i == 0)
			read(0, a->name, NAME_LEN);
		
		else if(i == 1)
			read(0, a->birth, BIRTH_LEN);
			
		else if(i == 2)
			scanf("%u", &(a->customer_num));
		
		else if(i == 3)
			read(0, a->address, ADDR_LEN);
		
		else if(i ==4)
			read(0, a->phone_num, PHONE_LEN);
	}
	fprintf(fd, "Name : %sBirth : %sCustomer Number : %u\n\nAddress : %sPhone Number : %s", a->name, a->birth, a->customer_num, a->address, a->phone_num);
	fclose(fd);
	
	return 0;
}

int edit(struct customer *a)
{
	int idx = 0;
	system("cls");
	printf("\t1.edit address\n\t2.edit phone\n\t3.both");
	printf("\n\n\n\tEnter your choice: ");
	
	scanf("%d", &idx);
	
	if(idx == 1)
	{
		printf("inut new address : ");
		read(0, a->address, ADDR_LEN);
	}
	else if(idx == 2)
	{
		printf("input new phone number : ");
		read(0, a->phone_num, PHONE_LEN);
	}
	else if(idx == 3)
	{
		printf("inut new address : ");
		read(0, a->address, ADDR_LEN);
		
		printf("input new phone number : ");
		read(0, a->phone_num, PHONE_LEN);
	}
	
	else
	{
		printf("---NOP---");
		return 0;
	}
	printf("---Success---\n");
	return 0;
}

int transact(struct customer *a)
{
	return 0;
}


void see()
{
	printf("see()");
	return 0;
}


int erase(struct customer *a)
{
	int idx;
	printf("customer number : ");
	scanf("%u", &idx);
	

	return 0;
}

void view_list(struct customer *a)
{
	system("cls");
	
	FILE *fd;
	
	fd = fopen("data.txt","r");
	char buffer[5] = {0,};
	
	while(feof(fd) == 0)
	{
		fread(buffer, sizeof(char), 4, fd);
		printf("%s", buffer);
		memset(buffer, 0, 5);
	}
	
	fclose(fd);
}
