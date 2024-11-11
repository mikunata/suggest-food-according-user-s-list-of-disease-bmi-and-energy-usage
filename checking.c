#include <stdio.h>
#include <stdlib.h>

struct mlc
{
    char name[20];
    int min_cal;
    int max_cal;
};

struct mlc food[50];

struct seven7
{
    char name[50];
    int min_cal;
    int max_cal;
};

struct seven7 food7[50];

void readFilemlc()
{
    FILE *fp;

    fp = fopen("mlcfoodlist.txt", "r");

    if (fp == NULL)
    {
        printf("file not found\n");
        exit(0);
    }
    else
    {
        int i = 0;
        while (i < 50)
        {
            int h;
            h = fscanf(fp, "%25[^,],%d,%d\n", food[i].name, &food[i].min_cal, &food[i].max_cal);
            if (h == 3)
            {

                i++;
            }
            else
            {

                break;
            }
        }
    }

    fclose(fp);
}

void readFile7()
{
    FILE *fp2;

    fp2 = fopen("sevenfoodlist.txt", "r");

    if (fp2 == NULL)
    {
        printf("file not found\n");
        exit(0);
    }
    else
    {
        int i = 0;
        while (i < 50)
        {
            int h;
            h = fscanf(fp2, "%30[^,],%d\n", food7[i].name, &food7[i].min_cal);
            if (h == 2)
            {

                i++;
            }
            else
            {

                break;
            }
        }
    }

    fclose(fp2);
}

void printFoodData(int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("Food Name: %s\n", food[i].name);
        printf("Min Calories: %d\n", food[i].min_cal);
        printf("Max Calories: %d\n\n", food[i].max_cal);
    }
}
void printFoodData7(int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("Food Name: %s\n", food7[i].name);
        printf("Min Calories: %d\n", food7[i].min_cal);
        printf("\n");
    }
}

void printf_mlc(int g)
{
  printf("%s",food[g].name);


}

int main()
{
    int i, count, m;

    printf("Your calories : ");
    scanf("%d",&m);
    printf("%d \n",m);
    readFilemlc();
    readFile7(); // เก็บค่าที่อ่านจากไฟล์

   /* printf("---Stored Food mlc Data:---\n\n");
    printFoodData(51);
    //เก็บค่าที่อ่านจากไฟล์
    printf("---Stored Food 7 Data:---\n\n");
    printFoodData7(32);
    return 0;*/

    // checking for output

    for (i = 0; i < 51; i++)
    {
        if((food[i].min_cal < m)&&(m < (food[i].max_cal)))
        {
           printf_mlc(i);
           printf("%d-%d",food[i].min_cal,food[i].max_cal);
           printf("\n");
        }

        else
         continue;



    }}


