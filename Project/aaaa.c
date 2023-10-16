void buy()
{
    char ch1, ch2;
    int id;
    while (1)
    {
    again:
        view();
        fflush(stdin);
        printf("\nDo you want to purchase[Y,N]:");
        scanf("%c", &ch1);
        if (ch1 == 'Y' || ch1 == 'y')
        {
            FILE *fp;
            struct bill t1;
            struct product t2;
            fp = fopen("fbill", "ab");
            printf("\nEnter the id to purchase:");
            scanf("%d", &id);
            t2 = findproduct(id);
            t1.pid = t2.id;
            strcpy(t1.pname, t2.name);
            t1.pprice = t2.price;
            fwrite(&t1, sizeof(t1), 1, fp);
            fclose(fp);
        }
        fflush(stdin);
        printf("Want to continue [Y/N]:");
        scanf("%c", &ch2);
        if (ch2 == 'y' || ch2 == 'Y')
        {
            goto again;
        }
        else
        {
            generatebill();
        }
        getch();
    }
}
struct product findproduct(int id)
{
    FILE *fp;
    struct product t;
    fp = fopen("store.txt", "rb");
    while (1)
    {
        fread(&t, sizeof(t), 1, fp);
        if (feof(fp))
        {
            break;
        }
        if (t.id == id)
        {
            update(id, t.quantity - 1);
            break;
        }
    }
    fclose(fp);
    return t;
}
void update(int id, int quantity)
{
    FILE *fp, *fp1;
    struct product t, t1;
    int found = 0;
    fp = fopen("store.txt", "rb");
    fp1 = fopen("temp.dat", "wb");
    while (1)
    {
        fread(&t, sizeof(t), 1, fp);
        if (feof(fp))
        {
            break;
        }
        if (t.id == id)
        {
            found = 1;
            t.quantity = quantity;
            fwrite(&t, sizeof(t), 1, fp1);
        }
        else
        {
            fwrite(&t, sizeof(t), 1, fp1);
        }
        fclose(fp);
        fclose(fp1);
    }
    if (found == 0)
    {
        printf("No record found\n");
    }
    else
    {
        fp = fopen("store.txt", "wb");
        fp1 = fopen("temp.dat ", "rb");
        while (1)
        {
            fread(&t, sizeof(t), 1, fp1);
            if (feof(fp))
            {
                break;
            }
            fwrite(&t, sizeof(t), 1, fp);
        }
    }
    fclose(fp);
    fclose(fp1);
}
void generatebill()
{
    FILE *fp, *fp1;
    struct bill t;
    int id, found = 0, total = 0;
    char ch1;
    int brel = 0;
    char billname[20];
    system("cls");
    fp = fopen("fbill", "rb");
    printf("Bill Details\n");
    while (1)
    {
        fread(&t, sizeof(t), 1, fp);
        if (feof(fp))
        {
            break;
        }
        printf("%d\t", t.pid);
        printf("%s\t", t.pname);
        printf("%d\t\t\n", t.pprice);
        total = total + t.pprice;
    }
    printf("Total Bill Amount:\t%d Rs", total);
    fclose(fp);
    if (total != 0)
    {
        fflush(stdin);
        printf("\ndo you want final bill[Y/N]");
        scanf("%d", &ch1);
        if (ch1 == 'Y' || ch1 == 'y')
        {
            brel = billfileno();
            sprintf(billname, "%s%d", "", brel);
            strcat(billname, ".txt");
            fp = fopen("fbill", "rb");
            fp1 = fopen("billname", "wb");
            while (1)
            {
                fread(&t, sizeof(t), 1, fp);
                if (feof(fp))
                {
                    break;
                }
                fwrite(&t, sizeof(t), 1, fp1);
            }
            fclose(fp);
            fclose(fp1);
            fp = fopen("fbill", "wb");
            fclose(fp);
            total = 0;
        }
        else
        {
            printf("No file found");
        }
    }
}
int billfileno()
{
    FILE *fp;
    int value = 0;
    fp = fopen("billno.txt", "r");
    if (fp == NULL)
    {
        fp = fopen("billno.txt", "w");
        fprintf(fp, "%d", 0);
        fclose(fp);
        fp = fopen("billno.txt", "r");
    }
    fscanf(fp, "%d", &value);
    fclose(fp);
    fp = fopen("billno.txt", "w");
    fprintf(fp, "%d", value + 1);
    fclose(fp);
    return value + 1;
}