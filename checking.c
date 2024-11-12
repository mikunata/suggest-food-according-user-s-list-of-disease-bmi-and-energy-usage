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

void printf_mlc(int g)
{
    printf("-30%s", food[g].name);
}
void printf_7(int g)
{
    printf("-30%s", food7[g].name);
}

void checking(float yourcal)
{
    int i;

    readFilemlc();
    readFile7();
    for (i = 0; i < 32; i++)
     food7[i].max_cal=food7[i].min_cal+50;
    printf("\n");
    printf("---recommended food in MLC---");
    printf("\n\n");
    for (i = 0; i < 51; i++)
    {
        if ((food[i].min_cal < yourcal) && (yourcal < (food[i].max_cal)))
        {
            printf_mlc(i);
            printf(" min = %d , max = %d", food[i].min_cal, food[i].max_cal);
            printf("\n");
        }

        else
            continue;
    }
    printf("---recommended food in 7-11---");
    printf("\n\n");
    for (i = 0; i < 32; i++)
    {
        if ((food7[i].min_cal < yourcal) && (yourcal < food7[i].max_cal))
        {
            printf_7(i);
            printf(" min = %d , max = %d", food7[i].min_cal, food7[i].max_cal);
            printf("\n");
        }

        else
            continue;
    }
}
