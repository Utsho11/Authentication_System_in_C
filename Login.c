#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8

struct user
{
    char fullName[50];
    char email[50];
    char password[50];
    char username[50];
    char phone[50];
};

void takeinput(char ch[50])
{
    fgets(ch, 50, stdin);
    ch[strlen(ch) - 1] = 0;
}

char generateUsername(char email[50], char username[50])
{
    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
            break;
        else
            username[i] = email[i];
    }
}

void takepassword(char pwd[50])
{
    int i;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == ENTER || ch == TAB)
        {
            pwd[i] = '\0';
            break;
        }
        else if (ch == BCKSPC)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            pwd[i++] = ch;
            printf("* \b");
        }
    }
}

void signup()
{
    FILE *fp;
    fp = fopen("Users.txt", "w");
    struct user user;
    char password2[50];

    system("cls");
    printf("\t\t\t\t\tPlease Signup First");
    printf("\nEnter your full name:\t");
    takeinput(user.fullName);
    printf("Enter your email:\t");
    takeinput(user.email);
    printf("Enter your contact no:\t");
    takeinput(user.phone);
    printf("Enter your password:\t");
    takepassword(user.password);
    printf("\nConfirm your password:\t");
    takepassword(password2);

    if (!strcmp(user.password, password2))
    {
        generateUsername(user.email, user.username);
        fwrite(&user, sizeof(struct user), 1, fp);
        if (fwrite != 0)
        {
            printf("\n\nUser registration success, Your username is %s", user.username);
        }
        else
        {
            printf("\n\nSorry! Something went wrong :(");
            fclose(fp);
        }
    }
    else
    {
        printf("\n\nPassword does not match");
        Beep(750, 300);
    }
}

void login()
{
    char username[50], pword[50];
    FILE *fp;
    fp = fopen("Users.txt", "r");
    struct user user;
    int usrFound = 0;

    system("cls");
    printf("\t\t\t\t\tPlease Log in");
    printf("\nEnter your username:\t");
    takeinput(username);
    printf("Enter your password:\t");
    takepassword(pword);

    while (fread(&user, sizeof(user), 1, fp))
    {
        if (strcmp(user.username, username) == 0 && strcmp(user.password, pword) == 0)
            {
                system("cls");
                printf("\n\t\t\t\t\t\tWelcome %s", user.fullName);
                printf("\n\n|Full Name:\t%s", user.fullName);
                printf("\n|Email:\t\t%s", user.email);
                printf("\n|Username:\t%s", user.username);
                printf("\n|Contact no.:\t%s", user.phone);
            }
            else
            {
                printf("\n\nInvalid Password or Username!");
                Beep(800, 300);
                login();
            }
            usrFound = 1;
            break;

    }

    if (!usrFound)
    {
        printf("\n\nUser is not registered!");
        Beep(800, 300);
    }
    fclose(fp);
}

int main()
{
    system("cls");
    system("color 0b");
    int opt;
    printf("\n\t\t\t\t---------- Welcome to authentication system of Taka Mare khabo Bank ltd. ----------");
    printf("\nPlease choose your operation");
    printf("\n1.Signup");
    printf("\n2.Login");
    printf("\n3.Exit");

    printf("\n\nYour choice: ");
    scanf("%d", &opt);
    fgetc(stdin);

    switch (opt)
    {
    case 1:
        signup();
        break;

    case 2:
        login();
        break;

    case 3:
        printf("\t\t\tBye Bye :)");
        return 0;
    }

    return 0;
}
