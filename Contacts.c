#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#define max 10000

void mainmenu();
void newcontact();
void edit();
void deletecontact();
void searchname();
void searchnumber();
void showinfo();
void exitt();

int count=0;
char empty[10]="    ";

struct contacts
{
    char firstname[30], lastname[30], phonenumber[15];
};
struct contacts c[max];
struct edit
{
    char firstname[30], lastname[30], phonenumber[15];
};
struct edit f[max];

main()
{
    mainmenu();
}

void mainmenu()
{
    int a;
    system("clear");
    printf("\t\t\t____________________________________________________________\n");
    printf("\t\t\t|                                                          |\n");
    printf("\t\t\t| If you want to add a new contact, please enter 1.        |\n");
    printf("\t\t\t|                                                          |\n");
    printf("\t\t\t| If you want to edit a contact, please enter 2.           |\n");
    printf("\t\t\t|                                                          |\n");
    printf("\t\t\t| If you want to delete a contact, please enter 3.         |\n");
    printf("\t\t\t|                                                          |\n");
    printf("\t\t\t| If you want to search a name, please enter 4.            |\n");
    printf("\t\t\t|                                                          |\n");
    printf("\t\t\t| If you want to search a phone number, please enter 5.    |\n");
    printf("\t\t\t|                                                          |\n");
    printf("\t\t\t| If you want to see all contacts, please enter 6.         |\n");
    printf("\t\t\t|                                                          |\n");
    printf("\t\t\t| If you want to exit, please enter 7.                     |\n");
    printf("\t\t\t|__________________________________________________________|\n");
    printf("\n\t\t\tPlease enter your number here: ");
    scanf("%d", &a);
    if (a==1)
    {
        newcontact();
    }
    if (a==2)
    {
        edit();
    }
    if (a==3)
    {
        deletecontact();
    }
    if (a==4)
    {
        searchname();
    }
    if (a==5)
    {
        searchnumber();
    }
    if (a==6)
    {
        showinfo();
    }
    if (a==7)
    {
        exitt();
    }
    else
    {
        printf("You have entered invalid number.");
    }
}

void newcontact()
{
    system("clear");
    printf("Add a new contact.\n**************************************\n");
    printf("First Name: ");
    scanf("%s",c[count].firstname);
    printf("Last Name: ");
    scanf("%s",c[count].lastname);
    printf("Phone Number: +98 ");
    scanf("%s",c[count].phonenumber);
    printf("Your contact has been added succesfully!\n");
    count++;
    sleep(1);
    mainmenu();
}

void edit()
{
    system("clear");
    int a,b;
    printf("Edit a contact.\n**************************************\n");
    for (a=0; a<count; a++)
    {
        printf("%d-\n",a);
        printf("First name: %s\n", c[a].firstname);
        printf("Last name: %s\n", c[a].lastname);
        printf("Phone number: +98 %s\n", c[a].phonenumber);
        printf("____________________________\n");
    }
    printf("\n**************************************\n");
    printf("Please enter number of the contact you want to edit. ");
    scanf("%d", &b);
    sleep(1);
    system("clear");
    printf("Edit contact No. %d", b);
    printf("\n**************************************\n");
    printf("First Name: %s\n",c[b].firstname);
    printf("Last Name: %s\n", c[b].lastname);
    printf("Phone Number: +98 %s\n", c[b].phonenumber);
    printf("\n**************************************\n");
    printf("\n\nNow enter the new information for the contact.\n");
    printf("First Name: ");
    scanf("%s",f[b].firstname);
    printf("Last Name: ");
    scanf("%s", f[b].lastname);
    printf("Phone Number: +98 ");
    scanf("%s",f[b].phonenumber);
    strcpy(c[b].firstname, f[b].firstname);
    strcpy(c[b].lastname, f[b].lastname);
    strcpy(c[b].phonenumber, f[b].phonenumber);
    printf("Your contact has been edited succesfully!\n");
    sleep(1);
    mainmenu();
}

void deletecontact()
{
    system("clear");
    int a, b, d;
    printf("Delete a contact.\n**************************************\n");
    for (a=0; a<count; a++)
    {
        printf("%d-\n",a);
        printf("First name: %s\n", c[a].firstname);
        printf("Last name: %s\n", c[a].lastname);
        printf("Phone number: +98 %s\n", c[a].phonenumber);
        printf("____________________________\n");
    }
    printf("\n**************************************\n");
    printf("Please enter number of the contact you want to delete. ");
    scanf("%d", &b);
    sleep(1);
    system("clear");
    printf("Delete contact No. %d", b);
    printf("\n**************************************\n");
    printf("First Name: %s\n",c[b].firstname);
    printf("Last Name: %s\n", c[b].lastname);
    printf("Phone Number: +98 %s\n", c[b].phonenumber);
    printf("\nAre you sure you want to delete this contact?\n1- Yes\n2- No\n");
    scanf("%d", &d);
    if (d==1)
    {
        strcpy(c[b].firstname, empty);
        strcpy(c[b].lastname, empty);
        strcpy(c[b].phonenumber, empty);
        printf("You have deleted your contact succesfully!\n");
        sleep(1);
        mainmenu();
    }
    else
    {
        sleep(1);
        mainmenu();
    }
}

void searchname()
{
    system("clear");
    char fn[50], ln[50];
    int a, b, d;
    d=0;
    printf("Search a name.\n**************************************\n");
    printf("Please enter the first name of the contact you are searching for: ");
    scanf("%s", fn);
    printf("Please enter the last name of the contact you are searching for: ");
    scanf("%s", ln);
    for (a=0 ; a<count; a++)
    {
        if (strcmp(c[a].firstname, fn)==0 && strcmp(c[a].lastname, ln)==0)
        {
            printf("First Name: %s\n", c[a].firstname);
            printf("Last Name: %s\n", c[a].lastname);
            printf("Phone Number: +98 %s\n", c[a].phonenumber);
            printf("____________________________\n");
            d++;
        }
    }
    printf("Do you want to go to main menu?\n1-Yes\n2-No\n");
    scanf("%d", &b);
    if (b==1)
    {
        sleep(1);
        mainmenu();
    }
    if (b==2)
    {
        sleep(1);
        searchname();
    }
    else
    {
        printf("You have entered invalid number.");
        sleep(2);
        searchname();
    }
}

void searchnumber()
{
    system("clear");
    char phn[50];
    int a, b, d;
    d=0;
    printf("Search a phone number.\n**************************************\n");
    printf("Please enter the phone number of the contact you are searching for: +98 ");
    scanf("%s", phn);
    for (a=0; a<count; a++)
    {
        if (strcmp(c[a].phonenumber, phn)==0)
        {
            printf("First Name: %s\n", c[a].firstname);
            printf("Last Name: %s\n", c[a].lastname);
            printf("Phone Number: +98 %s\n", c[a].phonenumber);
            printf("____________________________\n");
        }
    }
    printf("Do you want to go to main menu?\n1-Yes\n2-No\n");
    scanf("%d", &b);
    if (b==1)
    {
        mainmenu();
    }
    if (b==2)
    {
        searchnumber();
    }
    else
    {
        printf("You have entered invalid number.\n");
        sleep(2);
        searchnumber();
    }
}

void showinfo()
{
    system("clear");
    int a, b;
    printf("Show all contacts.\n**************************************\n");
    for (a=0; a<count; a++)
    {
        printf("%d-\n", a+1);
        printf("First Name: %s\n", c[a].firstname);
        printf("Last Name: %s\n", c[a].lastname);
        printf("Phone Number: +98 %s\n", c[a].phonenumber);
        printf("____________________________\n");
    }
    printf("\n**************************************\n");
    printf("Do you want to go to main menu?\n1-Yes\n2-No\n");
    scanf("%d", &b);
    if (b==1)
    {
        sleep(1);
        mainmenu();
    }
    if (b==2)
    {
        sleep(1);
        showinfo();
    }
    else
    {
        printf("You have entered invalid number.\n");
        sleep(2);
        showinfo();
    }
}

void exitt()
{
    system("clear");
    int a;
    printf("Exit.\n**************************************\n");
    printf("Are you sure that you want to close the program?\n1- Yes\n2- No\n");
    scanf("%d", &a);
    if (a==1)
    {
        printf("The program will be closed in a few seconds.\n");
        sleep(2);
        exit(0);
    }
    if (a==2)
    {
        sleep(1);
        mainmenu();
    }
    else
    {
        printf("You have entered the wrong number.\n");
        sleep(2);
        exitt();
    }
}