#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_CUSTOMER 4

#define NAME_LEN 20
#define BIRTH_LEN 8
#define ADDR_LEN 65
#define PHONE_LEN 13

struct customer
{
	char name[NAME_LEN];
    unsigned int customer_num;
    char address[ADDR_LEN];
    char birth[BIRTH_LEN];
    char phone_num[PHONE_LEN];
    int deposit_amount;		
};

int cnt = 0;
struct customer a[MAX_CUSTOMER] = { 0, };

void setup();
void menu();

int new_acc();
int edit();
int transact();
int erase();

void see();
void view_list();


int main()
{
	int i = 0;
	
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
				new_acc();
				break;
			case 2:
				edit();
				break;
			case 3:
				transact();
				break;
			case 4:
				see();
				break;
			case 5:
				erase();
				break;
			case 6:
				view_list();
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

int new_acc()
{	
	system("cls");
	printf("\n\n\t\tnew_acc()\n");
	char *s[5] = {"Name", "Birth (YYYYMMDD)", "Customer Number(1~5)", "Address", "Phone Number (010-XXXX-XXXX)"};
	
	if(cnt > MAX_CUSTOMER)
	{
		printf("MAX CUSTOMER");
		exit(0);
	}
	
	int i;
	for(i = 0; i < 5; i++)
	{
		printf("\n\t\t%s : ", s[i]);
		
		if(i == 0)
			read(0, a[cnt].name, NAME_LEN);
		
		else if(i == 1)
			read(0, a[cnt].birth, BIRTH_LEN);
			
		else if(i == 2)
			scanf("%u", &(a[cnt].customer_num));
		
		else if(i == 3)
			read(0, a[cnt].address, ADDR_LEN);
		
		else if(i ==4)
			read(0, a[cnt].phone_num, PHONE_LEN);
	}
	cnt++;
	
	return 0;
}

int edit()
{
	int idx, tmp = 0;
	system("cls");
	
	printf("customer number : ");
	scanf("%d", &tmp);
	
	printf("\t1.edit address\n\t2.edit phone\n\t3.both");
	printf("\n\n\n\tEnter your choice: ");
	
	scanf("%d", &idx);
	
	if(idx == 1)
	{
		printf("inut new address : ");
		read(0, a[tmp-1].address, ADDR_LEN);
	}
	else if(idx == 2)
	{
		printf("input new phone number : ");
		read(0, a[tmp-1].phone_num, PHONE_LEN);
	}
	else if(idx == 3)
	{
		printf("inut new address : ");
		read(0, a[tmp-1].address, ADDR_LEN);
		
		printf("input new phone number : ");
		read(0, a[tmp-1].phone_num, PHONE_LEN);
	}
	
	else
	{
		printf("---NOP---");
		return 0;
	}
	printf("---Success---\n");
	return 0;
}

int transact()
{
	int num, amnt, tmp = 0;
	printf("input customer number : ");
	scanf("%d", &tmp);
	
 	printf("Choose\n1.Deposit\n2.Withdraw\nEnter your choice");//입금, 출금 선택 
 	scanf("%d", &num);
 	if (num == 1)//입금  
 	{
 		printf("Deposit Amount : ");
 		scanf("%d",&amnt);
 		a[tmp-1].deposit_amount += amnt;// 전에 입력한 금액에서 amnt만큼 더함 
 		printf("Deposited Successfully\n");
 		printf("Current amount: %d\n", a[tmp-1].deposit_amount);// 입금 후 잔액  
	 }
	 else if(num == 2)
	 {
	 	printf("Withdraw Amount : ");
	 	scanf("%d",&amnt);
	 	
		if(amnt > a[tmp-1].deposit_amount)
		 	printf("Insufficient Cash");
		
		else 
	 	{
			a[tmp-1].deposit_amount -= amnt;
	 		printf("Withdrawn Successfully");
	 		printf("Current amount : %d\n",a[tmp-1].deposit_amount);
		}
	 }	
	return 0;
}


void see()
{
	int tmp = 0;
	
	printf("input customer number : ");
	scanf("%d", &tmp);
	
	printf("see()\n\n");
	printf("Name: %s\n", a[tmp-1].name );//이름 
	printf("Birth: %s\n", a[tmp-1].birth);//생년월일
	printf("Address: %s\n", a[tmp-1].address );//주소  
	printf("Phone Number: %s\n", a[tmp-1].phone_num);//휴대폰번호 
	printf("Deposit Amount: %d\n",a[tmp-1].deposit_amount);//잔액
}


int erase()
{
	unsigned int tmp = 0;
	printf("customer number : ");
	scanf("%u", &tmp);
	
	memset(&a[tmp-1], 0, sizeof(struct customer));
	return 0;
}

void view_list()
{
	system("cls");
	
	int i;
	for(i = 0; i < MAX_CUSTOMER; i++)
	{
		printf("Name: %s\n", a[i].name );//이름 
		printf("Birth: %s\n", a[i].birth);//생년월일
		printf("Address: %s\n", a[i].address );//주소  
		printf("Phone Number: %s\n", a[i].phone_num);//휴대폰번호 
		printf("Deposit Amount: %d\n",a[i].deposit_amount);
		
		printf("\n\n\n");
	}
	return 0;
}
