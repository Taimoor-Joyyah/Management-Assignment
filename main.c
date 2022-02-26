#include <stdio.h>
#include <stdlib.h>

struct tool
{
    char name[16];
    int quantity;
    float cost;
};

int menu();
void listT(struct tool no[100]);
void newT(struct tool no[100]);
void updateT(struct tool no[100]);
void delT(struct tool no[100]);

int main()
{
    int i;
    static struct tool no[100];
    int rec[] = {3, 17, 24, 39, 56, 68, 77, 83};
    char name[][32] = {"Electric sander", "Hammer", "Jigsaw", "Lawnmower", "Powersaw", "Screwdriver", "Sledgehammer", "Wrench"};
    int quantity[] = {7, 76, 21, 3, 18, 106, 11, 34};
    float cost[] = {57.98, 11.98, 11.00, 79.50,99.99, 6.99, 21.50, 7.50};
    for(i = 0; i < 8; i++)
    {
        strcpy(no[rec[i]].name, name[i]);
        no[rec[i]].quantity = quantity[i];
        no[rec[i]].cost = cost[i];
    }
    do
    {
        switch(menu())
        {
        case 1:
            listT(no);
            system("cls");
            break;
        case 2:
            newT(no);
            system("cls");
            break;
        case 3:
            updateT(no);
            system("cls");
            break;
        case 4:
            delT(no);
            system("cls");
            break;
        }
    }
    while(1);
    return 0;
}
//Main Menu
int menu()
{
    printf("\t\tMENU\n\n");
    printf("\t1. List Tool\n");
    printf("\t2. New Tool\n");
    printf("\t3. Update Tool\n");
    printf("\t4. Delete Tool\n");
    printf("\nSelect Option.");
    char key;
    do
    {
        key = getch();
    }
    while(key < '1' || key > '4');
    system("cls");
    return key - '0';
}
//List Record
void listT(struct tool no[100])
{
    printf("Record\tToolName\tQuantity\tCost\n");
    for(int i = 0; i < 100; i++)
    {
        if(no[i].name[0] != NULL)
            printf("%-6d\t%-8s\t%6d\t%12.2f\n", i, no[i].name, no[i].quantity, no[i].cost);
    }
    getch();
}
//Create New Record
void newT(struct tool no[100])
{
    int rec;
    printf("Enter Tool No : ");
    scanf("%d", &rec);
    printf("Enter Name : ");
    scanf("%s", no[rec].name);
    printf("Enter Quantity : ");
    scanf("%d", &no[rec].quantity);
    printf("Enter Cost : ");
    scanf("%f", &no[rec].cost);
}
//Update Record
void updateT(struct tool no[100])
{
    int rec;
    printf("Enter Tool No : ");
    scanf("%d", &rec);
    printf("Name : %s\n", no[rec].name);
    printf("Quantity : %d\n", no[rec].quantity);
    printf("Cost : %.2f\n", no[rec].cost);
    printf("\nEnter 1 for Changing Quantity and 2 for Cost.");
    switch(getch())
    {
    case '1':
        printf("\nEnter Quantity : ");
        scanf("%d", &no[rec].quantity);
        break;
    case '2':
        printf("\nEnter Cost : ");
        scanf("%f", &no[rec].cost);
        break;
    case 27:
        return;
    }
}
//Delete Record
void delT(struct tool no[100])
{
    int rec;
    printf("Enter Tool No : ");
    scanf("%d", &rec);
    if(no[rec].quantity == 0)
    {
        no[rec].name[0] = 0;
        no[rec].cost = 0;
        printf("deleted...");
    }
    else
        printf("The Tool is Available so it cannot be deleted...");
    getch();
}
