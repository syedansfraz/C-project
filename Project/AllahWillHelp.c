#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
void add();
void del();
void view();
void login();
void welcome();
void mainmenu1();
void mainmenu2();
void modify();
void view2();
// void order();
// void bill();
// void verify_order(); 
// void sold();
struct product
{
    int id;
    char name[20];
    int price;
    int expdate;
    int quantity;
    char category[20];
} details;
int main()
{
    system("color f4");
    printf("\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SUPER STORE MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    login();
}
// Login function

void login()
{
    int i;
    char username[6];
    char pass[5];
    int psw, choice;
again2:
    printf("\n\n\n\t\t\t\t\t     Enter login details");
    printf("\n\n\n1.Manager\n2.Customer\n");
    scanf("\t%d", &choice);
    if (choice == 1)
    {
        while (1)
        {
            printf("\n\t\t\tEnter the username: ");
            scanf("%s", &username);
            if (strcmp(username, "admin") != 0)
                continue;
            else
                break;
        }
    again:
        i = 0;
        printf("\n\t\t\tEnter the 4 digit pin: ");
        scanf("%d", &psw);
        if (psw == 4454)
        {
            printf("\n\n\t\t\t\t\tYou are Successfully Logged in\n\n\t\t\t\t\tPress any key to Continue......");
            getch();
            welcome();
            mainmenu1();
        }
        else
            goto again;
    }
    else if (choice == 2)
    {
        welcome();
        mainmenu2();
    }
    else
    {
        printf("\n\t\tWRONG CHOICE!!");
        goto again2;
    }
}

// Welcome function

void welcome()
{
    system("cls");
    printf("\n\t\t###            ###  ######## ###         #######     ######     ######  #####   ######## \n");
    Sleep(400); // Slows the time and defined in windows header
    printf("\t\t###            ###  ###      ###        ##    ###   ##    ##   ##  #######  ##  ###      \n");
    Sleep(400);
    printf("\t\t###            ###  ###      ###       ###         ###    ### ###   #####   ### ###      \n");
    Sleep(400);
    printf("\t\t###     ##     ###  ######## ###       ###         ###    ### ###    ###    ### ######## \n");
    Sleep(400);
    printf("\t\t###    ####    ###  ###      ###       ###         ###    ### ###           ### ###      \n");
    Sleep(400);
    printf("\t\t###  ###  ###  ###  ###      ###        ##    ###   ##    ##  ###           ### ###      \n");
    Sleep(400);
    printf("\t\t ## ####  #### ##   ######## #########   ######      ######   ###           ### ######## \n");
}

// Mainmenu function

void mainmenu1()
{
    int choice;
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\t\t\xB2\xB2\xB2\t\t\t   \xB2\xB2\xB2\n\t\t\t\xB2\xB2\xB2 1.Add Product          \xB2\xB2\xB2");
    printf("\n\t\t\t\xB2\xB2\xB2\t\t\t   \xB2\xB2\xB2\n\t\t\t\xB2\xB2\xB2 2.View Product         \xB2\xB2\xB2");
    printf("\n\t\t\t\xB2\xB2\xB2\t\t\t   \xB2\xB2\xB2\n\t\t\t\xB2\xB2\xB2 3.Delete Product       \xB2\xB2\xB2");
    printf("\n\t\t\t\xB2\xB2\xB2\t\t\t   \xB2\xB2\xB2\n\t\t\t\xB2\xB2\xB2 4.Modify Product       \xB2\xB2\xB2");
    printf("\n\t\t\t\xB2\xB2\xB2\t\t\t   \xB2\xB2\xB2\n\t\t\t\xB2\xB2\xB2 5.Exit                 \xB2\xB2\xB2");
    printf("\n\t\t\t\xB2\xB2\xB2\t\t\t   \xB2\xB2\xB2\n\t\t\t\xB2\xB2\xB2\t\t\t   \xB2\xB2\xB2\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    do
    {
        printf("\n\n\n\t\t\t\xB2\xB2\xB2 Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            add();
            break;
        case 2:
            system("cls");
            view();
            break;
        case 3:
            system("cls");
            del();
            break;
        case 4:
            system("cls");
            modify();
            break;
        case 5:
            printf("\t\t\tTHANK YOU");
            exit(0);
            break;
        default:
            printf("Enter valid  choice");
        }
    } while (choice != 5);
    system("cls");
}
void add()
{
    int num;
    printf("How many Products you want to add:");
    scanf("%d", &num);
    FILE *ptr = fopen("store.txt", "a");
    for (int i = 0; i < num; i++)
    {
        printf("ID:");
        scanf("%d", &details.id);
        printf("Name:");
        scanf("%s", &details.name);
        printf("Product price:");
        scanf("%d", &details.price);
        printf("Category:");
        scanf("%s", &details.category);
        printf("Expiry year:");
        scanf("%d", &details.expdate);
        printf("Quantity:");
        scanf("%d", &details.quantity);
        fwrite(&details, sizeof(struct product), 1, ptr);
    }
    printf("\n\t\tDetails Entered successfully\n\t\tpress any key to go to Main Menu.....");
    fclose(ptr);
    getch();
    system("cls");
    mainmenu1();
}
void view()
{

    FILE *ptr = fopen("store.txt", "r+");
    printf("\n************************************************************************\n");
    printf("Id\tName\t\tPrice\tCategory\tExp. Date\tQuantity");
    printf("\n************************************************************************");
    while (fread(&details, sizeof(struct product), 1, ptr) == 1)
    {
        printf("\n%d\t%s\t\t%d\t%s\t\t%d\t\t%d", details.id, details.name, details.price, details.category, details.expdate, details.quantity);
    }
    printf("\n************************************************************************");
    printf("\nPress any key to go to Main Menu.....");
    fclose(ptr);
    getch();
    system("cls");
    mainmenu1();
}
void del()
{
    int remove1;
    FILE *fp1, *fp2;
    printf("Enter the ID of Product to remove:");
    scanf("%d", &remove1);
    fp1 = fopen("store.txt", "r+");
    fp2 = fopen("copy.txt", "a+");
    if (fp1 == NULL)
    {
        fprintf(stderr, "Can't open file");
        exit(0);
    }
    while (fread(&details, sizeof(struct product), 1, fp1))
    {
        if (details.id != remove1)
        {
            fwrite(&details, sizeof(struct product), 1, fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("store.txt");
    rename("copy.txt", "store.txt");
    printf("Deleted Successfully...\n");
    printf("\nPress any key to go to Main Menu.....");
    getch();
    system("cls");
    mainmenu1();
}
void modify()
{
    struct product details2;
    FILE *fp1, *fp2;
    int newid;
    printf("Enter ID for updation");
    scanf("%d", &newid);
    fp1 = fopen("store.txt", "r+");
    fp2 = fopen("copy.txt", "a+");
    if (fp1 == NULL)
    {
        fprintf(stderr, "Can't open file");
        // exit(0);
    }
    while (fread(&details, sizeof(struct product), 1, fp1))
    {
        if (details.id != newid)
        {
            fwrite(&details, sizeof(struct product), 1, fp2);
        }
    }
    printf("\nNew id:");
    scanf("%d", &details2.id);
    printf("New Name:");
    scanf("%s", &details2.name);
    printf("New price:");
    scanf("%d", &details2.price);
    printf("New Category:");
    scanf("%s", &details2.category);
    printf("New Expiry Year:");
    scanf("%d", &details2.expdate);
    printf("New Quantity:");
    scanf("%d", &details2.quantity);
    fwrite(&details2, sizeof(struct product), 1, fp2);

    fclose(fp1);
    fclose(fp2);
    remove("store.txt");
    rename("copy.txt", "store.txt");
    printf("\nUpdated....");
    printf("\nPress any key to go to Main Menu.....");
    getch();
    system("cls");
    mainmenu1();
}
void mainmenu2()
{
    int choice;
printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
printf("\n\t\t\t\xB2\xB2\xB2\t\t\t   \xB2\xB2\xB2\n\t\t\t\xB2\xB2\xB2 1.View Poduct          \xB2\xB2\xB2");
printf("\n\t\t\t\xB2\xB2\xB2\t\t\t   \xB2\xB2\xB2\n\t\t\t\xB2\xB2\xB2 2.Order Poduct         \xB2\xB2\xB2");	
printf("\n\t\t\t\xB2\xB2\xB2\t\t\t   \xB2\xB2\xB2\n\t\t\t\xB2\xB2\xB2 3.View Bill            \xB2\xB2\xB2");
printf("\n\t\t\t\xB2\xB2\xB2\t\t\t   \xB2\xB2\xB2\n\t\t\t\xB2\xB2\xB2 4.Exit                 \xB2\xB2\xB2");
printf("\n\t\t\t\xB2\xB2\xB2\t\t\t   \xB2\xB2\xB2\n\t\t\t\xB2\xB2\xB2\t\t\t   \xB2\xB2\xB2\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
do{
printf("\n\n\n\t\t\t\xB2\xB2\xB2 Enter your choice: ");
scanf("%d",&choice);
switch(choice)
{
	case 1:
	system("cls");
	view2();
	// case 2:
 	// system("cls");
 	// order();
 	// case 3:
 	// system("cls");
 	// bill(); 
	case 2:
    printf("\t\t\tTHANK YOU");
	exit(0);
	default:
	printf("Enter valid  choice");
}
}while(choice!=5);
}
void view2()
{
    FILE *ptr = fopen("store.txt", "r+");
    printf("\n************************************************************************\n");
    printf("Id\tName\t\tPrice\tCategory\tExp. Date\tQuantity");
    printf("\n************************************************************************");
    while (fread(&details, sizeof(struct product), 1, ptr) == 1)
    {
        printf("\n%d\t%s\t\t%d\t%s\t\t%d\t\t%d", details.id, details.name, details.price, details.category, details.expdate, details.quantity);
    }
    printf("\n************************************************************************");
    printf("\nPress any key to go to Main Menu.....");
    fclose(ptr);
    getch();
    system("cls");
    mainmenu2();
}
void buy()
{
    int buyid;
    FILE *ptr=fopen("store.txt","w+");
    printf("\nEnter Id of product to Buy:");
    scanf("%d",&buyid);
    
}
