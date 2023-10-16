#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
void add();
void del();
void view();
void modify();
void buy();
// void update(int, int);
// void generatebill();
// struct product findproduct(int);
// int billfileno();
// void sold();
// void buy();
struct product
{
    int id;
    char name[20];
    int price;
    int expdate;
    int quantity;
    char category[20];
} details;
// struct bill
// {
//     int pid;
//     char pname[20];
//     int pprice;
// };
int main()
{
    int choice;
    printf("Which function ?");
    scanf("%d", &choice);
    if (choice == 1)
    {
        add();
    }
    else if (choice == 2)
    {
        view();
    }
    else if (choice == 3)
    {
        del();
    }
    else if (choice == 4)
    {
        modify();
    }
    else  
    {
        buy();
    }
    // else
    //     // generatebill();
    //     exit(0);
}
void add()
{
    int num;
    printf("How many Poducts you wan to add:");
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
    fclose(ptr);
}
void view()
{
    FILE *ptr = fopen("store.txt", "r");
    printf("\n************************************************************************\n");
    printf("Id\tName\t\tPrice\tCategory\tExp. Date\tQuantity");
    printf("\n************************************************************************");
    while (fread(&details, sizeof(struct product), 1, ptr) == 1)
    {
        printf("\n%d\t%s\t\t%d\t%s\t\t%d\t\t%d", details.id, details.name, details.price, details.category, details.expdate, details.quantity);
    }
    fclose(ptr);
}
void del()
{
    int remove1;
    FILE *fp1, *fp2;
    printf("Enter the ID of Product to remove");
    scanf("%d", &remove1);
    fp1 = fopen("store.txt", "r+");
    fp2 = fopen("copy.txt", "a+");
    if (fp1 == NULL)
    {
        fprintf(stderr, "Can't open file");
        // exit(0);
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
    printf("record deleted successfully");
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
    printf("\nNew Name:");
    scanf("%s", &details2.name);
    printf("\nNew price:");
    scanf("%d", &details2.price);
    printf("New Category:");
    scanf("%s", &details2.category);
    printf("New Expiry Year:");
    scanf("%d", &details2.expdate);
    printf("New Quantity");
    scanf("%d", &details2.quantity);
    fwrite(&details2, sizeof(struct product), 1, fp2);

    fclose(fp1);
    fclose(fp2);
    remove("store.txt");
    rename("copy.txt", "store.txt");
    printf("\nUpdated....");
}
void buy()
{
    int buyid,count=0;
    int quan;
    char name[20];
    FILE *ptr=fopen("store.txt","a+");
    printf("\nEnter Id of product to Buy:");
    scanf("%d",&buyid);
    while(fread(&details,sizeof(struct product),1,ptr)==1);
    {
		if (buyid==details.id)
		{	
			printf("Quantity:");
			scanf("%d",&quan);
			getchar();
            printf("Enter your name:");
			gets(name);
            fseek(ptr,ftell(ptr)-sizeof(struct product),0);
			fwrite(&details,sizeof(struct product),1,ptr);
			count++;
    }
}
    if(count==0)
	printf("\n\n\n\t\t\t|********Record not found********|\n");
	else
printf("\n\n\t\t%s your item is purchased",name);
	fclose(ptr);
printf("\n\n\t\tPress any key to go back to Main Menu..........");
	getch();
	system("cls");
}