#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void add(); // FUNCTIONS
void list();
void edit(); // GLOBALLY DECLARED FUNCTIONS N VARIABLE
void delete1();
void search();
void casino();
void feedback();
void feed();
void login()
{

	int a = 0, i = 0;
	char uname[10], c = ' ';
	char pword[10], code[10];
	char user[10] = "vikash";
	char pass[10] = "56080";
	do
	{
		system("cls");
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 14);

		printf("\n  **************************  LOGIN FORM  **************************  ");
		printf(" \n                          ENTER USERNAME:- ");
		scanf("%s", &uname);
		printf(" \n                          ENTER PASSWORD:- ");
		while (i < 10)
		{
			pword[i] = getch();
			c = pword[i];
			if (c == 13)
				break;
			else
				printf("*");
			i++;
		}
		pword[i] = '\0';
		// char code=pword;
		i = 0;
		// scanf("%s",&pword);
		if (strcmp(uname, user) == 0 && strcmp(pword, pass) == 0)
		{
			printf("  \n\n\n\n         WELCOME !!!! LOGIN IS SUCCESSFUL");

			break;
		}
		else
		{
			printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
			a++;

			getch();
		}
	} while (a <= 2);
	if (a > 2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();
	}
	system("cls");
}

struct CustomerDetails // STRUCTURE DECLARATION
{
	char roomnumber[11];
	char name[20];
	char address[25];
	char phonenumber[15];
	char nationality[15];
	char email[20];
	char period[10];
	char arrivaldate[10];
	char feedback[100];
} s;

int main()
{ // MAIN FUNCTION
	int i = 0;

	time_t t;
	time(&t);
	char customername;
	char choice;
	login();
	system("cls");
	while (1) // INFINITE LOOP
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 2);
		system("cls");
		for (i = 0; i < 80; i++)
			printf("-");
		printf("\n");
		printf("   ******************************  |HOTEL TAJ|  ***************************** \n");
		for (i = 0; i < 80; i++)
			printf("-");
		printf("\n");
		printf("\t\t *Please enter your choice for menu*:");
		printf("\n\n");
		printf(" \n Enter 1 -> Book a room");
		printf("\n-----------------------------");
		printf(" \n Enter 2 -> View Customer Record");
		printf("\n----------------------------------");
		printf(" \n Enter 3 -> Delete Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 4 -> Search Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 5 -> Edit Record");
		printf("\n-----------------------");
		printf(" \n Enter 6 -> Casino");
		printf("\n------------------");
		printf(" \n Enter 7 -> Feedback");
		printf("\n--------------------");
		printf(" \n Enter 8 -> Exit");
		printf("\n");
		for (i = 0; i < 100; i++)
			printf("-");
		printf("\nCurrent date and time : %s", ctime(&t));
		for (i = 0; i < 80; i++)
			printf("-");

		choice = getche();
		choice = toupper(choice);
		switch (choice) // SWITCH STATEMENT
		{
		case '1':
			add();
			break;
		case '2':
			list();
			break;
		case '3':
			delete1();
			break;
		case '4':
			search();
			break;
		case '5':
			edit();
			break;
		case '6':
			casino();
			break;
		case '7':
			feedback();
			break;
		case '8':
			system("cls");
			printf("\n\n\t *****THANK YOU*****");
			printf("\n\t FOR TRUSTING OUR SERVICE");
			//	Sleep(2000);
			exit(0);
			break;
		default:
			system("cls");
			printf("Incorrect Input");
			printf("\n Press any key to continue");
			getch();
		}
	}
}

void add()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 12);
	int count = 0, i, j, p = 0;
	FILE *f;
	char test;
	f = fopen("add.txt", "a+");
	if (f == 0)
	{
		f = fopen("add.txt", "w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while (1)
	{
		system("cls");
		printf("\n Enter Customer Details:");
		printf("\n**************************");
		fflush(stdin);
		count = 0;
		printf("\n Enter Room number     : ");
		scanf("\n%s", &s.roomnumber);
		fflush(stdin);
		// gets(s.roomnumber);
		for (i = 0; s.roomnumber[i] != '\0'; i++)
		{
			if (s.roomnumber[i] >= 48 && s.roomnumber[i] <= 57)
			{
				count++;
			}
		}
		if (count == 4)
		{
			//	fflush(stdin);
			printf("\nEnter Name             : ");
			gets(s.name);
			printf("\nEnter Address          : ");
			gets(s.address);
			printf("\nEnter Phone Number     : ");
			gets(s.phonenumber);
			count = 0;
			for (i = 0; s.phonenumber[i] != '\0'; i++)
			{
				if (s.phonenumber[0] >= 54)
				{
					if (s.phonenumber[i] >= 48 && s.phonenumber[i] <= 57)
					{
						count++;
					}
				}
			}
			if (count == 10)
			{
				printf("\nEnter Nationality      : ");
				scanf("%s", s.nationality);
				printf("\nEnter Email            : ");
				scanf(" %s", s.email);
				printf("\nEnter Period(\'x\'days)   : ");
				scanf("%s", &s.period);
				printf("\nEnter Arrival date(dd\\mm\\yyyy) : ");
				scanf("%s", &s.arrivaldate);
				fwrite(&s, sizeof(s), 1, f);
				fflush(stdin);
				printf("\n\n1 Room is successfully booked!!");
				printf("\n Press esc key to exit,  any other key to add another customer detail:");
			}
			else
			{
				printf("please enter correct mobile number");
				printf("\n Press esc key to exit,  any other key to add another customer detail:");
			}
		}

		else
		{
			printf("please enter 4 digit room number");
			printf("\nPress esc key to exit,  any other key to add another customer detail:");
		}

		test = getche();
		if (test == 27)
			break;
	}
	fclose(f);
}
void feedback()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 11);
	FILE *f;
	char test;
	f = fopen("feed.txt", "b+");
	if (f == 0)
	{
		f = fopen("feed.txt", "w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while (1)
	{
		system("cls");
		fflush(stdin);
		printf("Enter Your Room number:- ");
		scanf("%s", s.roomnumber);
		fflush(stdin);
		printf("Enter Your Valueable Feedback:- ");
		gets(s.feedback);
		fflush(stdin);
		fwrite(&s, sizeof(s), 1, f);
		printf("\nThank You For Giving Your Valueable Feedback!!");
		printf("\n\n------------------------------------------------------------------------");
		printf("\n Press esc key to exit,  any other key to add another Feedback:");
		test = getche();
		if (test == 27)
			break;
	}
	fclose(f);
}

void list()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 13);
	FILE *f;
	int i;
	if ((f = fopen("add.txt", "r")) == NULL)
		exit(0);
	system("cls");
	printf("ROOM    ");
	printf("\tNAME\t ");
	printf("\t\tADDRESS\t ");
	printf("\t\tPHONENUMBER\t ");
	printf("\t\t\tNATIONALITY");
	printf(" \t\t\tEMAIL\t");
	printf("\t\t  PERIOD");
	printf("\t\tARRIVALDATE \n");

	for (i = 0; i < 180; i++)
		printf("-");
	while (fread(&s, sizeof(s), 1, f) == 1)
	{
		printf("\n%s \t%s \t\t%s \t\t%s \t\t\t\t%s  \t\t%s   \t    %s   \t\t%s", s.roomnumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period, s.arrivaldate);
	}
	printf("\n");
	for (i = 0; i < 180; i++)
		printf("-");

	fclose(f);
	getch();
}

void delete1()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 3);
	FILE *f, *t;
	int i = 1, flag = 1;
	char roomnumber[20];
	if ((t = fopen("temp.txt", "w")) == NULL)
		exit(0);
	if ((f = fopen("add.txt", "r")) == NULL)
		exit(0);
	system("cls");
	printf("Enter the Room Number of the hotel to be deleted from the database: \n");
	fflush(stdin);
	scanf("%s", roomnumber);

	while (fread(&s, sizeof(s), 1, f) == 1)
	{
		if (strcmp(s.roomnumber, roomnumber) == 0)
		{
			i = 0;
			continue;
		}
		else
			fwrite(&s, sizeof(s), 1, t);
	}
	if (i == 1)
	{
		printf("\n\n Records of Customer in this  Room number is not found!!");
		// remove("E:/file.txt");
		// rename("E:/temp.txt","E:/file.txt");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt", "add.txt");
	printf("\n\tRecord Found\n ");
	printf("\nRoom Number   :\t%s", s.roomnumber);
	printf("\nName          :\t%s", s.name);
	printf("\nAddress       :\t%s", s.address);
	printf("\nPhone number  :\t%s", s.phonenumber);
	printf("\nNationality   :\t%s", s.nationality);
	printf("\nEmail         :\t%s", s.email);
	printf("\nPeriod        :\t%s", s.period);
	printf("\nArrival date  :\t%s", s.arrivaldate);
	printf("\n\nThe Customer is successfully removed....");
	fclose(f);
	fclose(t);
	getch();
}

void search()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 2);
	system("cls");
	FILE *f;
	char roomnumber[20];
	int flag = 1;
	f = fopen("add.txt", "r+");
	if (f == 0)
		exit(0);
	fflush(stdin);
	printf("Enter Room number of the customer to search its details: \n");
	scanf("%s", roomnumber);
	while (fread(&s, sizeof(s), 1, f) == 1)
	{
		if (strcmp(s.roomnumber, roomnumber) == 0)
		{
			flag = 0;
			printf("\n\tRecord Found\n ");
			printf("\nRoom Number   :\t%s", s.roomnumber);
			printf("\nName          :\t%s", s.name);
			printf("\nAddress       :\t%s", s.address);
			printf("\nPhone number  :\t%s", s.phonenumber);
			printf("\nNationality   :\t%s", s.nationality);
			printf("\nEmail         :\t%s", s.email);
			printf("\nPeriod        :\t%s", s.period);
			printf("\nArrival date  :\t%s", s.arrivaldate);
			flag = 0;
			break;
		}
	}
	if (flag == 1)
	{
		printf("\n\tRequested Customer could not be found!");
	}
	getch();
	fclose(f);
}

void GuessGame(int amount_bet, int *inhand_cash)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 1);
	char num[3] = {'N', 'R', 'N'};
	printf("\nWait !! number is shuffling its position...\n");
	srand((time(NULL)));
	int i, x, y, temp;
	/*Swapping the number's position five times using
	the random number for random index*/
	for (i = 0; i < 5; i++)
	{
		x = rand() % 3;
		y = rand() % 3;
		temp = num[x];
		num[x] = num[y];
		num[y] = temp;
	}
	int PlayerGuess;
	printf("\n   * *    * *    * *  ");
	printf("\n   * *    * *    * *  ");
	printf("\n  * 1 *  * 2 *  * 3 * ");
	printf("\n   ***    ***    ***  ");
	printf("\n--------------------------------------------------------------------\n");
	printf("There are three bottles which may call by the numbers 1,2 and 3:");
	printf("\n-----------------------------------------------------------------");
	printf("\nYou may now guess the bottle number in which R is present: ");
	scanf("%d", &PlayerGuess);
	if (num[PlayerGuess - 1] == 'R')
	{
		(*inhand_cash) += amount_bet;
		system("cls");
		printf("YOU CHOOSE %d\n", PlayerGuess);
		printf("\nYou win ! The numbers are as follows: \n");
		printf("\"%c %c %c\" ", num[0], num[1], num[2]);
		printf("\nYour inhand_cash is now = %d \n", *inhand_cash);
	}
	else
	{
		(*inhand_cash) -= amount_bet;
		system("cls");
		printf("YOU CHOOSE %d\n", PlayerGuess);
		printf("You Loose ! The numbers are as follows: ");
		printf("\"%c %c %c\" ", num[0], num[1], num[2]);
		printf("\nYour inhand_cash is now = %d \n", *inhand_cash);
	}
}

void casino()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 1);
	system("cls");
	FILE *f;
	char test;
	int amount_bet, inhand_cash;

	printf("\n////////-WELCOME TO  DIAMOND CASINO-\\\\\\\\\\\\ \n");
	printf("\n----Enter the inhand_cash you have right now---- :\n ");
	scanf("%d", &inhand_cash);
	while (inhand_cash > 0)
	{
		printf("\nEnter the amount_bet you want to play for : \n");
		scanf("%d", &amount_bet);
		if (inhand_cash == 0 || amount_bet > inhand_cash || amount_bet == 0)
			break;
		else
			GuessGame(amount_bet, &inhand_cash);
	}
	while (1)
	{
		if (inhand_cash == 0 || amount_bet > inhand_cash || amount_bet == 0)
		{
			printf("\n\""
				   " \nSorry you don't have enough cash to play more,\n ");
			printf("\nDo come next time\""
				   "\n\n");
			printf("\nThank You for playing \n");
			printf("-----------------------------------");
			printf("\n Press esc key to exit:");
			test = getche();
			if (test == 27)
				break;
			getch();
		}
		fclose(f);
	}
}

void edit()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 12);
	FILE *f;
	int k = 1;
	char roomnumber[20];
	long int size = sizeof(s);
	if ((f = fopen("add.txt", "r+")) == NULL)
		exit(0);
	system("cls");
	printf("Enter Room number of the customer to edit:\n\n");
	scanf("%[^\n]", roomnumber);
	fflush(stdin);
	while (fread(&s, sizeof(s), 1, f) == 1)
	{
		if (strcmp(s.roomnumber, roomnumber) == 0)
		{
			k = 0;
			printf("\nEnter Room Number  :");
			gets(s.roomnumber);
			printf("\nEnter Name         :");
			fflush(stdin);
			gets(s.name);
			printf("\nEnter Address      :");
			gets(s.address);
			printf("\nEnter Phone number :");
			scanf("%s", &s.phonenumber);
			printf("\nEnter Nationality  :");
			scanf("%s", &s.nationality);
			printf("\nEnter Email        :");
			scanf("%s", &s.email);
			printf("\nEnter Period       :");
			scanf("%s", &s.period);
			printf("\nEnter Arrival date :");
			scanf("%s", &s.arrivaldate);
			fseek(f, size, SEEK_CUR); // to go to desired position infile
			fwrite(&s, sizeof(s), 1, f);
			break;
		}
	}
	if (k == 1)
	{
		printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
		fclose(f);
		getch();
	}
	else
	{
		fclose(f);
		printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
		getch();
	}
}
