#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
float checking(int yourcal);
void displaySummary(const char responses[], const char *diseases[], int count);

void collectResponses(char responses[], const char *diseases[], int count, int *p);
int confirmAction();
struct mlc
{
    char name[20];
    int min_cal, max_cal; /*Sugar, Car, Sodium, Fats, Chol, Pota, Phos, Purine, Fruc, spicy;*/
    int lim[10];
};
struct mlc food[75];
struct seven7
{
    char name[50];
    int min_cal, max_cal, price; /*,Sugar,Car,Sodium,Fats,Chol,Pota,Phos,Purine,Fruc,spicy;*/
    int lim[10];
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
        while (i < 75)
        {
            int h;
            h = fscanf(fp, "%30[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", food[i].name, &food[i].min_cal, &food[i].lim[0], &food[i].lim[1], &food[i].lim[2], &food[i].lim[3], &food[i].lim[4], &food[i].lim[5], &food[i].lim[6], &food[i].lim[7], &food[i].lim[8], &food[i].lim[9]);
            if (h == 12)
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
        while (i < 32)
        {
            int h;
            h = fscanf(fp2, "%30[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", food7[i].name, &food7[i].min_cal, &food7[i].price, &food7[i].lim[0], &food7[i].lim[1], &food7[i].lim[2], &food7[i].lim[3], &food7[i].lim[4], &food7[i].lim[5], &food7[i].lim[6], &food7[i].lim[7], &food7[i].lim[8], &food7[i].lim[9]);
            if (h == 13)
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

float checking(int yourcal)
{
    typedef struct
    {
        int state;
        /*int Sugar, Car, Sodium, Fats, Chol, Pota, Phos, Purine, Fruc,spicy;*/
        int lim[10];

    } nutrie;
    nutrie Dia = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    nutrie Hyper = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    nutrie Card = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    nutrie Kidney = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    nutrie GERD = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    nutrie Gout = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    nutrie Obesity = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    nutrie Liver = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    nutrie Allergies = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    nutrie Peptic = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // Array of disease names
    int *pt, i = 0;
    int check[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    const char *diseases[] = {
        "Diabetes Mellitus",
        "Hypertension",
        "Cardiovascular Diseases",
        "Kidney Diseases",
        "GERD",
        "Gout",
        "Obesity",
        "Liver Diseases",
        "Allergies",
        "Peptic Ulcer"};

    const int numDiseases = 10;
    char responses[10];
    pt = &check[0];

    do
    {
        collectResponses(responses, diseases, numDiseases, pt);
        system("cls");
        displaySummary(responses, diseases, numDiseases);
    } while (confirmAction() != 1);
    Dia.state = check[0];
    Hyper.state = check[1];
    Card.state = check[2];
    Kidney.state = check[3];
    GERD.state = check[4];
    Gout.state = check[5];
    Obesity.state = check[6];
    Liver.state = check[7];
    Allergies.state = check[8];
    Peptic.state = check[9];
    if ((Dia.state) == 1)
    {

        Dia.lim[0] = 1;
        Dia.lim[1] = 1;
        Dia.lim[3] = 1;
    }

    if (Hyper.state == 1)
    {
        Hyper.lim[0] = 1;
        Hyper.lim[2] = 1;
        Hyper.lim[3] = 1;
    }

    if (Card.state == 1)
    {

        Card.lim[2] = 1;
        Card.lim[3] = 1;
        Card.lim[4] = 1;
    }

    if (Kidney.state == 1)
    {

        Kidney.lim[2] = 1;
        Kidney.lim[5] = 1;
        Kidney.lim[6] = 1;
    }

    if (GERD.state == 1)
    {

        GERD.lim[3] = 1;
        GERD.lim[9] = 1;
    }

    if (Gout.state == 1)
    {
        Gout.lim[7] = 1;
        Gout.lim[8] = 1;
    }

    if (Obesity.state == 1)
    {
        Obesity.lim[0] = 1;
        Obesity.lim[3] = 1;
    }

    if (Liver.state == 1)
    {

        Liver.lim[3] = 1;
        Liver.lim[8] = 1;
    }

    if (Allergies.state == 1)
    {
        Allergies.lim[9] = 1;
    }

    if (Peptic.state == 1)
    {

        Peptic.lim[9] = 1;
    }
    readFilemlc();
    readFile7();
    for (i = 0; i < 75; i++)
        food7[i].max_cal = food7[i].min_cal + 50;
    for (i = 0; i < 34; i++)
        food[i].max_cal = food[i].min_cal + 50;

    int h, j;
    system("cls");
    printf("---recommended food in MLC---");
    printf("\n\n");
    for (i = 0; i < 75; i++)
    {
        h = 0;

        // Check calorie range
        if (food[i].min_cal <= yourcal && yourcal <= food[i].max_cal)
        {
        }
        else
            h++;

        // Check limitations for all conditions in one loop
        for (j = 0; j < 10; j++)
        {
            if (food[i].lim[j] == 1)
            {
                if (food[i].lim[j] == Dia.lim[j] ||
                    food[i].lim[j] == Hyper.lim[j] ||
                    food[i].lim[j] == Card.lim[j] ||
                    food[i].lim[j] == Kidney.lim[j] ||
                    food[i].lim[j] == GERD.lim[j] ||
                    food[i].lim[j] == Gout.lim[j] ||
                    food[i].lim[j] == Obesity.lim[j] ||
                    food[i].lim[j] == Liver.lim[j] ||
                    food[i].lim[j] == Allergies.lim[j] ||
                    food[i].lim[j] == Peptic.lim[j])
                {
                    h++;
                    // Exit loop early if any condition matches
                }
                
            }
            
            // Skip the current food if any limitation applies
            
        }
        if (h != 0)
            {
                
            }

            else
            { // Output the valid food
                printf("%-30s ", food[i].name);
                printf(" min = %d , max = %d\n", food[i].min_cal, food[i].max_cal);
            }
    }

    printf("---recommended food in 7-11---");
    printf("\n\n");
    for (i = 0; i < 31; i++)
    {
        h = 0;

        // Check calorie range
        if (food7[i].min_cal <= yourcal && yourcal <= food7[i].max_cal)
        {
        }
        else
            h++;

        // Check limitations for all conditions in one loop
        for (j = 0; j < 10; j++)
        {
            if (food7[i].lim[j] == 1)
            {
                if (food7[i].lim[j] == Dia.lim[j] ||
                    food7[i].lim[j] == Hyper.lim[j] ||
                    food7[i].lim[j] == Card.lim[j] ||
                    food7[i].lim[j] == Kidney.lim[j] ||
                    food7[i].lim[j] == GERD.lim[j] ||
                    food7[i].lim[j] == Gout.lim[j] ||
                    food7[i].lim[j] == Obesity.lim[j] ||
                    food7[i].lim[j] == Liver.lim[j] ||
                    food7[i].lim[j] == Allergies.lim[j] ||
                    food7[i].lim[j] == Peptic.lim[j])
                {
                    h++;
                    // Exit loop early if any condition matches
                }
                
            }
            
            // Skip the current food if any limitation applies
            
        }
        if (h != 0)
            {
                
            }

            else
            { // Output the valid food
                printf("%-30s ", food7[i].name);
                printf(" min = %d , max = %d\n", food7[i].min_cal, food7[i].max_cal);
            }
    }
    }

void collectResponses(char responses[], const char *diseases[], int count, int *p)
{
    int i;
    char response;
    printf("\n");

    printf("-----Answer the following questions with----- \n'y' (yes) or 'n' (no)");
    printf("\n");
    for (i = 0; i < count; i++)
    {

        do
        {
            printf("%d.)Do you have %s? (y/n): ", i + 1, diseases[i]);
            scanf(" %c", &response);
            response = tolower(response);

            if (response == 'y')
            {
                responses[i] = response;
                *p = 1;
                break;
            }
            else if (response == 'n')
            {
                responses[i] = response;
                *p = 0;
                break;
            }
            else
            {
                printf("Invalid input. Please enter 'y' or 'n'.\n");
            }

        } while (1);
        p++;
    }
}

int confirmAction()
{
    char response;
    
    do
    {  
        printf("\n");
        printf("-----Do you want to confirm these responses?-----\n(y/n): ");
        printf("\n");
        scanf(" %c", &response); // Space before %c to handle input buffer
        response = tolower(response);

        if (response == 'y')
        {
            return 1; // Confirm
        }
        else if (response == 'n')
        {
            printf("Restarting...\n");
            system("cls");
            return 0; // Restart
        }
        else
        {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    } while (1);
}
void displaySummary(const char responses[], const char *diseases[], int count) {
    printf("\n-----Summary of Responses-----\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", diseases[i], (responses[i] == 'y' ? "Yes" : "No"));
    }
}
