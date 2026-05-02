#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main ()
{
    FILE *fptr;

    fptr = fopen("trip.csv", "w"); 
    float trip_cost, disel, porter_cut, misc,profit, profit_per,disel_cost;
    int km;
    time_t t;
    char date[30];
    struct tm *tm_info;

    if (fptr == NULL)
    {
        printf("Could not create a file..\n");
        return 1;
    }

    time(&t);
    tm_info = localtime(&t);
    strftime(date, sizeof(date), "%y- %m - %d %H:%M:%S", tm_info);

    printf("\n");
    printf("-------------------------------------\n");
    printf("**********Trip Logger system*********\n");
    printf("-------------------------------------\n");
    
    printf("Trip Income:- ");
    scanf("%f", &trip_cost);

    printf("Enter the Distance in KM:- ");
    scanf("%d", &km);

    printf("Enter porter cost:- ");
    scanf("%f", &porter_cut);

    printf("Enter misllaneous expenses:-");
    scanf("%f", &misc);

    disel = (float)km/ 15;
    disel_cost =  (float)km / 15 * 90;
    profit =  trip_cost - (disel_cost+ misc + porter_cut);
    if(trip_cost != 0)
    {
        profit_per =  (profit / trip_cost) * 100;
    }
    else 
    {
        profit_per = 0;
    }
    fprintf(fptr,"Date-->trip_cost--> disel_cost--> misc--> profit-->profit_per|     |\n");
    fprintf(fptr,"%s,%.2f,%.2f,%.2f,%.2f,%.2f ",date,trip_cost,disel_cost, misc,profit,profit_per);
    fclose(fptr);
    printf("Entry Saved..\n");
    printf("|-----|---------------|-----------------|------------\n");
    printf("|-----|---------------|-----------------|------------\n");
    printf("|-----|Argument       |Description      |Details     \n");
    printf("|-----|---------------|-----------------|------------\n");
    printf("|---1.|Date and Time  |YY-MM-DD HH-MM-SS|%s\n",      date);
    printf("|---2.|Disel_cost     |Disel_cost in RUP|%.2f$\n",   disel_cost);
    printf("|---3.|Profit         |Porfir in Rupees |%.2f\n",    profit);
    printf("|---4.|Profit_Per     |Profit Per       |%.2f%% \n", profit_per);
    printf("|-----|---------------|-----------------|------------\n");
    printf("|-----|---------------|-----------------|------------\n");
   
    fclose(fptr);
    return 0;

}