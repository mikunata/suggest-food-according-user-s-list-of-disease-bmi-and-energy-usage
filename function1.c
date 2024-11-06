#include <stdio.h>
#include <string.h>

char op_data[50], op_disease[50][50], decision[10];
int op_age;
float weight, height, w, h;
float op_height, op_weight;
int a, nd, n, c, i, choice; // c=count
FILE *f, *p;
void user_register();
void read_file();
int login();
void select_function();
void user_register()
{
    char name[50], surname[50], name2[50], data_age[50], data_sur[50], data_name[50], data_weight[50], data_height[50],
        data_disease[50], sex[10], password[50], data_password[50], data_exercise[50],disease[100][50];
    int age, num_disease, ex;
    do
    {
        system("clear");
        a = age, nd = num_disease, w = weight, h = height;
        printf("\n*********************\n");
        printf("Name      : ");
        scanf("%s", name);
        printf("Surname   : ");
        scanf("%s", surname);
        printf("Sex       : ");
        scanf("%s", sex);
        printf("Age       : ");
        scanf("%d", &a);
        printf("Weight(kg)   : ");
        scanf("%f", &w);
        printf("Height(meter): ");
        scanf("%f", &h);
        printf("Num of Disease  :");
        scanf("%d", &nd);
        for (i = 0; i < nd; i++)
        {
            printf("%d. ", i + 1);
            scanf("%s", disease[i]);
        }
        printf("Exercise per week: ");
        scanf("%d", &ex);
        printf("Create your password: ");
        scanf("%s", password);
        printf("*********************\n");
          if (a == 0 || w == 0 || h == 0)
        {
            printf("Error pls enter your right information!!");
            continue;
        }
        printf("Confirm your information(yes/no): ");
        scanf("%s", decision);
    } while (a == 0 || w == 0 || h == 0 || strcmp(decision, "No") == 0 || strcmp(decision, "NO") == 0 || strcmp(decision, "no") == 0 || strcmp(decision, "nO") == 0 ||
             strcmp(decision, "N") == 0 || strcmp(decision, "n") == 0);
        strcpy(name2, name);
        strcat(name, surname);
        f = fopen(name, "w");
        fprintf(f, "%s", name);
        fclose(f);
        strcpy(data_name, name);
        strcat(data_name, "_name");
        f = fopen(data_name, "w");
        fprintf(f, "%s", name2);
        fclose(f);
        strcpy(data_sur, name);
        strcat(data_sur, "_surname");
        f = fopen(data_sur, "w");
        fprintf(f, "%s", surname);
        fclose(f);
        strcpy(data_age, name);
        strcat(data_age, "_age");
        f = fopen(data_age, "w");
        fprintf(f, "%d", a);
        fclose(f);
        strcpy(data_weight, name);
        strcat(data_weight, "_weight");
        f = fopen(data_weight, "w");
        fprintf(f, "%.2f", w);
        fclose(f);
        strcpy(data_height, name);
        strcat(data_height, "_height");
        f = fopen(data_height, "w");
        fprintf(f, "%.2f", h);
        fclose(f);
        strcpy(data_disease, name);
        strcat(data_disease, "_disease");
        f = fopen(data_disease, "w");
        for (i = 0; i < nd; i++)
            fprintf(f, "%s ", disease[i]);
        fclose(f);
        strcpy(data_password, name);
        strcat(data_password, "_password");
        f = fopen(data_password, "w");
        fprintf(f, "%s", password);
        fclose(f);
        strcpy(data_exercise, name);
        strcat(data_exercise, "_exercise");
        f = fopen(data_exercise, "w");
        fprintf(f, "%d", ex);
        fclose(f);
        if (strcmp(decision, "Y") == 0 ||strcmp(decision, "y") == 0 ||strcmp(decision, "yes") == 0 || strcmp(decision, "YES") == 0 || strcmp(decision, "Yes") == 0 || strcmp(decision, "YeS") == 0 ||
            strcmp(decision, "YEs") == 0 || strcmp(decision, "yES") == 0 || strcmp(decision, "yEs") == 0 || strcmp(decision, "yeS") == 0)
            {
                printf("Complete your register!");
                return main();
            }
}
int main()
{
        system("clear");
        printf("\n********************\n");
        printf("*  1.register      *\n");
        printf("*  2.login         *\n");
        printf("*  3.Exit program  *\n");
        printf("********************\n");
        printf("choose:");
        scanf("%d", &choice);
        switch (choice)
        {
        case (1):
            user_register();
            break;
        case (2):
            login();
            break;
        }
        if (choice == 3)
            return (0);
}
int login()
{
    char name[50], sur[50], data[50], username[50], data_password[50], password[50]="\0", user_password[50], ans[1], real_password[50]="\0";
    int age;
    do
    {
        system("clear");
        if(strcmp(password,real_password)!=0)
        { 
            char D[1];
            do{
            printf("Your password is wrong!\nPls check your password\n");
            printf("accept(y/n): ");
            scanf("%s",D);
            }while(strcmp(D, "N") == 0 || strcmp(D, "n") == 0);
            if(strcmp(D, "Y") == 0 || strcmp(D, "y") == 0)
                system("clear");
        }
        printf("Name :");
        scanf(" %s", name);
        printf("Surname :");
        scanf(" %s", sur);
        strcpy(username, name);
        strcat(username, sur);
        strcpy(data_password, username);
        strcat(data_password, "_password");
        if ((f = fopen(username, "r")) == NULL)
        {
            do
            {
                system("clear");
                printf("pls register first or check your username\n");
                printf("accept(y/n): ");
                scanf(" %s", ans);
            } while (strcmp(ans, "N") == 0 || strcmp(ans, "n") == 0);
            if(strcmp(ans,"y")==0||strcmp(ans,"Y")==0)
                {
                    int c;
                    printf("/////////////////////");
                    printf("\\1.register         \\\n ");
                    printf("\\2.Recheck again    \\\n");
                    printf("/////////////////////");
                    printf("choose : ");
                    scanf("%d",&c);
                    if(c==1)user_register();
                    else continue; 
                }
        }
        else
        {
            if (f = fopen(data_password, "r") == NULL)
             { 
                  printf("Error");
                  break;
             }
            else
            {
                f=fopen(data_password,"r");
                fscanf(f, "%s", real_password);
                fclose(f);
                printf("password: ");
                scanf("%s", password);
                if (strcmp(password, real_password) == 0)
                {
                    system("clear");
                    printf("login successful\n");
                }
            }
        }
    } while (strcmp(password, real_password) != 0);
    select_function();
}
void select_function() //เอาฟังก์ชั่นที่เสร็จแล้วมาใส่ในนี้
{
    int f_c;
    printf("1....\n");
    printf("2....\n");
    printf("3....\n");
    printf("4.logout\n");
    printf("choose : ");
    scanf("%d",&f_c);
    switch (f_c)
    {
    case(1) :
        //funtion ใดๆๆ
        break;
    case(2):
        //functionใดๆๆ
        break;
    case(3):
        //functionใดๆๆ
        break;  
    case(4):
        main();
        break;  
    }
}


    /*  ตัวอย่างอ่านข้อมูล2
    void read_data(char name[50],char sur[50],char data[50])
    {
        char data_name[50];
        int age,height;
        strcpy(data_name,name);
        strcat(data_name,sur);
        strcat(data_name,data);
        f=fopen(data_name,"r");
        if(data=="_age")
        {
            fscanf(f,"%d",&age);
            fclose(f);
        }
        else if(data=="_height")
     {
            fscanf(f,"&d",&height);
            fclose(f);
     }
        }*/
    /*  ตัวอย่างอ่านข้อมูล1
 void read_file()
 {
     char name[50], surname[50];
     system("clear");
     printf("***********************\n");
     printf("Your name :");
     scanf("%s", name);
     printf("Your surname :");
     scanf("%s", surname);
     strcat(name, surname);
     printf("What info do you want ?\n");
     printf("1.age\n2.weight\n3.height\n4.disease\n");
     printf("choose:");
     scanf("%d", &c);
     printf("***********************\n");
     strcpy(op_data, name);
     switch (c)
     {
     case (1):
         strcat(op_data, "_age");
         f = fopen(op_data, "rb");
         fscanf(f, "%d", &op_age);
         printf("%d", op_age);
         fclose(f);
         break;
     case (2):
         strcat(op_data, "_weight");
         f = fopen(op_data, "rb");
         fscanf(f, "%f", &op_weight);
         printf("%.2f", op_weight);
         fclose(f);
         break;
     case (3):
         strcat(op_data, "_height");
         f = fopen(op_data, "rb");
         fscanf(f, "%f", &op_height);
         printf("%.2f", op_height);
         fclose(f);
         break;
     case (4):
         strcat(op_data, "_disease");
         f = fopen(op_data, "rb");
         for (i = 0; i < sizeof(f); i++)
         {
             fscanf(f, "%s,", op_disease[i]);
             printf("%s", op_disease[i]);
         }
         fclose(f);
         break;
     }
 }*/