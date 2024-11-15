#include <stdio.h>
#include <string.h>
#include"checking.c"
#include"function3 incomplete.c"
char op_data[50], op_disease[50][50], decision[10];
int op_age;
float weight, height, w, h;
float op_height, op_weight;
int a, nd, n, c, i; // c=count
FILE *f, *p;
int goback();
void user_register();
void read_file();
int login();
void select_function(char user[50]);
int resetpassword(char passname[50],char [100]);
void user_register()
{
    char name[50], surname[50], name2[50], data_age[50], data_sur[50], data_name[50], data_weight[50], data_height[50],
        data_disease[50], sex[10], password[50], data_password[50], data_exercise[50],disease[50][50],data_verify_qa[50],data_verify_ans[50];
    char verify_qa[100],verify_ans[100];
    int age, num_disease, ex;
    do
    {
        //รับข้อมูล
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
        printf("create your verify question for forgeting password: ");
        scanf(" %[^\n]",verify_qa);
        printf("correct answer for your verify: ");
        scanf(" %[^\n]",verify_ans);
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
        //เริ่มสร้างไฟล์เก็บข้อมูล
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
        strcpy(data_verify_qa,name);
        strcat(data_verify_qa,"_verify_qa");
        f=fopen(data_verify_qa,"w");
        fprintf(f, "%s", verify_qa);
        fclose(f);
        strcpy(data_verify_ans,name);
        strcat(data_verify_ans,"_verify_ans");
        f=fopen(data_verify_ans,"w");
        fprintf(f, "%s", verify_ans);
        fclose(f);
        if (strcmp(decision, "Y") == 0 ||strcmp(decision, "y") == 0 ||strcmp(decision, "yes") == 0 || strcmp(decision, "YES") == 0 || strcmp(decision, "Yes") == 0 || strcmp(decision, "YeS") == 0 ||
            strcmp(decision, "YEs") == 0 || strcmp(decision, "yES") == 0 || strcmp(decision, "yEs") == 0 || strcmp(decision, "yeS") == 0)
            {
                goback();
            }
}
int main()
{
    int choice;
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
       /* if (choice == 3)
            return (0);*/
}
int login()
{
    char name[50], sur[50], data[50], username[50], data_password[50], password[50]="\0", user_password[50], ans[1], real_password[50]="\0";
    char ansreset[100],ansuser[100],resetpass[50],newpass[50]; 
    int op;
    do
    {
        system("clear");
        //ถ้ารหัสผิด
        if(strcmp(password,real_password)!=0)
        { 
            char D[1];
            do{
            printf("Your password is wrong!\nPls check your password\n");
                //ต้องไปทำลืมรหัสผ่าน
            printf("accept(y/n): ");
            scanf("%s",D);
            }while(strcmp(D, "N") == 0 || strcmp(D, "n") == 0);
            if(strcmp(D, "Y") == 0 || strcmp(D, "y") == 0)
                system("clear");
        }
        //กรอกข้อมูลเพื่อเข้าใช้
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
                //ตรวจสอบรหัสผ่าน
                f=fopen(data_password,"r");
                fscanf(f, "%s", real_password);
                fclose(f);
                printf("********************\n");
                printf("*1.Enter password  *\n");
                printf("*2.Forgot password *\n");
                printf("********************\n");
                printf("choose: ");
                scanf("%d",&op);
                switch (op)
                {
                case (1) :
                          printf("password: ");
                          scanf("%s", password);
                    break;
                case (2) :
                    printf("////////////////////////\n");
                    printf("//verify your identity//\n");
                    printf("////////////////////////\n");
                    resetpassword(username,ansreset);
                    printf("Ans verify question : ");
                    scanf("%s",ansuser);
                    if(strcmp(ansreset,ansuser)==0)
                        {
                            strcpy(resetpass,username);
                            strcat(resetpass,"_password");
                            f=fopen(resetpass,"w");
                            printf("Your new password :");
                            scanf("%s",newpass);
                            fprintf(f,"%s",newpass);
                            fclose(f);
                            login();
                        }
                    else{
                        int i;
                        printf("pls check your answer again!!\n");
                        printf("******************************\n");
                        printf("1.register again\n");
                        printf("2.relogin\n");
                        printf("******************************\n");
                        scanf("%d",&i);
                        switch (i)
                        {
                        case (1): user_register();
                        break;
                        case(2): login();
                        break;
                        }
                    }
                    break; 
                }
                if (strcmp(password, real_password) == 0)
                {
                    system("clear");
                    printf("login successful\n");
                }
            }
        }
    } while (strcmp(password, real_password) != 0);
    select_function(username);
}
int resetpassword(char passname[50],char verify_ans[100])
{
    char question[100],passans[50],passqa[50];
    FILE *p;
    strcpy(passqa,passname);
    strcpy(passans,passname);
    strcat(passqa,"_verify_qa");
    if((p=fopen(passqa,"r"))==NULL)
    {
        printf("ERROR");
        return 15;
    }
    fgets(question,100,p);
    fclose(p);
    printf("%s\n",question);
    strcat(passans,"_verify_ans");
     if((p=fopen(passans,"r"))==NULL)
    {
        printf("ERROR");
        return 10;
    }
    fgets(verify_ans,100,p);
    fclose(p);
}
void select_function(char user[50]) //เอาฟังก์ชั่นที่เสร็จแล้วมาใส่ในนี้
{
    int f_c;
    printf("1....\n");
    printf("2.calculating calories\n");
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
        edit_data_calculate_calories();
        break;
    case(3):
        //functionใดๆๆ
        break;  
    case(4):
        main();
        break;  
    }
}
int goback(){
    int second_time=0;
    while(second_time!=1||second_time!=2){
                system("clear");
                printf("\n****/select/****\n");
                printf("1.login\n");
                printf("2.first page\n");
                printf("****************\n");
                printf("select:");
                scanf("%d",&second_time);
                switch (second_time)
                {
                case (1):
                    return login();
                    break;
                case(2):
                    return main();
                break;
                } 
            if(second_time!=1||second_time!=2)    
            printf("\npls select the num on menu");
            }
}
