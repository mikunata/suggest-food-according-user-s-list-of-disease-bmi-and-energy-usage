#include <stdio.h>
#include <string.h>

char op_data[50], op_disease[50][50], decision[10];
int op_age;

float op_height, op_weight;
 // c=count
FILE *f, *p;
int goback();
int user_register();
void read_file();
int login();
void select_function(char user[50]);
int resetpassword(char passname[50], char[100]);
int verify_resetpass(char[50]);
int startresetpass(char[50]);
int forgetpass(char [50]);
int forgetpass(char forget_user[50])
{
        char i='0';
        int v=0;
        do
        {
            system("clear");
            v = verify_resetpass(forget_user);
            if (v == 15)
            {
                startresetpass(forget_user);
                login();
            }
            else
            {
                system("clear");
                do
                {
                    printf("pls check your answer again!!\n");
                    printf("******************************\n");
                    printf("1.register again\n");
                    printf("2.relogin\n");
                    printf("3.check again\n");
                    printf("******************************\n");
                    printf("choose:");
                    scanf("%c", &i);
                    switch (i)
                    {
                    case ('1'):
                        user_register();
                        break;
                    case ('2'):
                        system("clear");
                        login();
                        break;
                    }
                    if (i != '1' && i && '2' && i && '3' && i!='0')
                    {
                        system("clear");
                        printf("pls select num in menu!\n");
                    }
                } while (i != '1' && i != '2' && i != '3');
            }

        } while (v != 15);
}
int user_register()
{
    char name[50], surname[50], name2[50], data_age[50], data_sur[50], data_name[50], data_weight[50], data_height[50],
        data_disease[50], sex[10], password[50], data_password[50], data_exercise[50], disease[50][50], data_verify_qa[50], data_verify_ans[50];
    char verify_qa[100], verify_ans[100], comfirm_pass[50],data_sex[50];
    int age, num_disease, ex,r,a=0,nd;
    float  w=0, h=0;
    do
    {
        // รับข้อมูล
        system("clear");
        a = age, nd = num_disease;
        printf("\n*********************\n");
        printf("Name      : ");
        scanf("%s", name);
        printf("Surname   : ");
        scanf("%s", surname);
        do{
        printf("Sex(male/female): ");
        scanf("%s", sex);
        if(strcmp(sex,"male")!=0&&strcmp(decision,"female")!=0)
                    printf("pls select from bracklet!!\n");
        }while(strcmp(sex,"male")!=0&&strcmp(sex,"female")!=0);
        while(1)
        {  
        printf("Age       : ");
        scanf("%d", &a);
        if(a<=0)
        printf("pls enter real information!\n");
        if(a>0)
            break;
        }
        while (1)
        {
        printf("Weight(kg)   : ");
        scanf("%f", &w);
        if(w<=0)
        printf("pls enter real information!\n");
        if(w>0) break;    
        }
        while(1){    
        printf("Height(meter): ");
        scanf("%f", &h);
        if(h>2||h<=0)
        printf("pls enter real information!\n");
        if((h<2)&&(h>0))
            break;
        }  
      /* printf("Num of Disease  :");
        scanf("%d", &nd);
        for (int i = 0; i < nd; i++)
        {
            printf("%d. ", i + 1);
            scanf("%s", disease[i]);
        }*/
        printf("Exercise per week: ");
        scanf("%d", &ex);
        do
        {
            printf("Create your password: ");
            scanf("%s", password);
            printf("comfirm your password: ");
            scanf("%s", comfirm_pass);
            if (strcmp(password, comfirm_pass) != 0)
                printf("check your password!\n");
        } while (strcmp(password, comfirm_pass) != 0);
        printf("create your verify question for forgeting password: ");
        scanf(" %[^\n]", verify_qa);
        printf("correct answer for your verify: ");
        scanf(" %[^\n]", verify_ans);
        printf("*********************\n");
        if (a == 0 || w == 0 || h == 0)
        {
            printf("Error pls enter your right information!!");
            continue;
        }
        do{
        printf("Confirm your information(yes/no): ");
        scanf("%s", decision);
            if(strcmp(decision,"yes")!=0&&strcmp(decision,"no")!=0)
                printf("pls select from backlet!!\n");
        }while(strcmp(decision,"yes")!=0&&strcmp(decision,"no")!=0);
    } while (a == 0 || w == 0 || h == 0 || strcmp(decision, "No") == 0 || strcmp(decision, "NO") == 0 || strcmp(decision, "no") == 0 || strcmp(decision, "nO") == 0 ||
             strcmp(decision, "N") == 0 || strcmp(decision, "n") == 0);
    // เริ่มสร้างไฟล์เก็บข้อมูล
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
    strcpy(data_sex,name);
    strcat(data_sex,"_sex");
    f=fopen(data_sex,"w");
    fprintf(f,"%s",sex);
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
    /*strcpy(data_disease, name);
    strcat(data_disease, "_disease");
    f = fopen(data_disease, "w");
    for (i = 0; i < nd; i++)
        fprintf(f, "%s ", disease[i]);
    fclose(f);*/
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
    strcpy(data_verify_qa, name);
    strcat(data_verify_qa, "_verify_qa");
    f = fopen(data_verify_qa, "w");
    fprintf(f, "%s", verify_qa);
    fclose(f);
    strcpy(data_verify_ans, name);
    strcat(data_verify_ans, "_verify_ans");
    f = fopen(data_verify_ans, "w");
    fprintf(f, "%s", verify_ans);
    fclose(f);
    if (strcmp(decision, "Y") == 0 || strcmp(decision, "y") == 0 || strcmp(decision, "yes") == 0 || strcmp(decision, "YES") == 0 || strcmp(decision, "Yes") == 0 || strcmp(decision, "YeS") == 0 ||
        strcmp(decision, "YEs") == 0 || strcmp(decision, "yES") == 0 || strcmp(decision, "yEs") == 0 || strcmp(decision, "yeS") == 0)
    {
        goback();
    }
}
int main()
{
    char choice = '0';
    // system("clear");
    printf("********************\n");
    printf("*  1.register      *\n");
    printf("*  2.login         *\n");
    printf("*  3.Exit program  *\n");
    printf("********************\n");
    printf("choose:");
    scanf("%c", &choice);
    switch (choice)
    {
    case ('1'):
        user_register();
        break;
    case ('2'):
        system("clear");
        login();
        break;
    case ('3'):
        return (0);
        break;
    default:
        printf(" \n");
        system("clear");
        printf("pls select num in menu!\n");
        main();
        break;
    }
}
int login()
{
    char name[50], sur[50], data[50], username[50], data_password[50], password[50] = "\0", user_password[50], ans[1], real_password[50] = "\0";
    int op=0,cmp=0,count=0;
    // กรอกข้อมูลเพื่อเข้าใช้
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
        { // do186
            int c=0;
            printf("pls register first or check your username\n");
            printf("accept(y/n): ");
            scanf(" %s", ans);
            if (strcmp(ans, "y") == 0 || strcmp(ans, "Y") == 0)
            {
                do{
                system("clear");
                printf("/////////////////////\n");
                printf("\\1.register         \\ \n");
                printf("\\2.Recheck again    \\ \n");
                printf("/////////////////////\n");
                printf("choose : ");
                scanf("%d", &c);
                switch (c)
                {
                case (1):
                    user_register();
                    break;
                case (2):
                    system("clear");
                    login();
                    break;
                default:
                    system("clear");
                    printf("pls select num in menu!\n");
                break;
                }
            }while(c!=1&&c!=2);
            }
             if (strcmp(ans, "y") != 0 && strcmp(ans, "Y") != 0 && strcmp(ans, "N") != 0 && strcmp(ans, "n") != 0)
                {
                    system("clear");
                    printf("--------------------------------\n");
                    printf("Pls select choice in bracket!\n");
                    printf("--------------------------------\n");
                }
        } while(strcmp(ans,"N")==0||strcmp(ans,"n")==0||(strcmp(ans, "y") != 0 && strcmp(ans, "Y") != 0 && strcmp(ans, "N") != 0 && strcmp(ans, "n") != 0));
        //} do 186
    }
    if ((f = fopen(data_password, "r")) == NULL)
    {
        printf("pls register again!");
        user_register();
    }
    else
    {
        fscanf(f, "%s", real_password);
        fclose(f);
    }
    printf("********************\n");
    printf("*1.Enter password  *\n");
    printf("*2.Forgot password *\n");
    printf("********************\n");
    printf("choose: ");
    scanf("%d", &op);
    switch (op)
    {
    case (1):
    do{// do 236 รับรหัสผ่าน
        printf("..............\n");
        printf("password: ");
        scanf("%s", password);
        if (strcmp(password, real_password) != 0)
        {
            char D[1];
            do
            {
                printf("Your password is wrong!\nPls check your password\n");
                printf("accept(y/n): ");
                scanf("%s", D);
            } while (strcmp(D, "N") == 0 || strcmp(D, "n") == 0);
            if (strcmp(D, "Y") == 0 || strcmp(D, "y") == 0)
             {   
                system("clear");
                printf("---------------------------\n");
                printf("1.check your password again!\n");
                printf("2.forgot password\n");
                printf("---------------------------\n");
                switch (cmp)
                {
                case (1):count=1;
                    break;
                case(2):
                    forgetpass(username);
                default:
                    system("clear");
                    printf("pls select num in menu!");
                    break;
                }
             }
        }
        }while(count==1);
    //do 236
        break;
    case (2):
        forgetpass(username);
        break;
    default:
         system("clear");
         printf("pls select num in menu!");
    break;
    }
    //เอาค่ารหัสใหม่ที่รีเซ็ตแล้วมาเทียบ
       if ((f = fopen(data_password, "r")) == NULL)
       {
           printf("pls register again!");
           user_register();
       }
       else
       {
           fscanf(f, "%s", real_password);
           fclose(f);
       }
    // เช็ครหัสเข้าใช้เพื่อแสดงผล
    if (strcmp(password, real_password) == 0)
    {
        system("clear");
        printf("login successful\n");
        select_function(username);
    }
    // ตรวจสอบรหัสผ่าน
}

int resetpassword(char passname[50], char verify_ans[100])
{
    char question[100], passans[50], passqa[50];
    FILE *p;
    strcpy(passqa, passname);
    strcpy(passans, passname);
    strcat(passqa, "_verify_qa");
    if ((p = fopen(passqa, "r")) == NULL)
    {
        printf("pls register again!\n");
        user_register();
    }    
    fgets(question, 100, p);
    fclose(p);
    printf("%s\n", question);
    strcat(passans, "_verify_ans");
    if ((p = fopen(passans, "r")) == NULL)
    {
        system("clear");
        printf("Pls register again!!\n");
        user_register();
    }
    fgets(verify_ans, 100, p);
    fclose(p);
}
void select_function(char user[50]) // เอาฟังก์ชั่นที่เสร็จแล้วมาใส่ในนี้
{
    int f_c = 0;
    printf("1.calculate BMI\n");
    printf("2.calculate calaries\n");
    printf("3....\n");
    printf("4.logout\n");
    printf("choose : ");
    scanf("%d", &f_c);
    switch (f_c)
    {
    case (1):
       //funtion
        break;
    case (2):
        //function
        break;
    case (3):
        // functionใดๆๆ
        break;
    case (4):
       // char password[50] = "\0", real_password[50] = "\0";
        system("clear");
        main();
        break;
    default:
        system("clear");
        printf("pls select num in menu!\n");
        select_function(user);
        break;
    }
}
int goback()
{
    int second_time = 0;
    while (second_time != 1 && second_time != 2)
    {
        system("clear");
        printf("\n****/select/****\n");
        printf("1.login\n");
        printf("2.first page\n");
        printf("****************\n");
        printf("select:");
        scanf("%d", &second_time);
        switch (second_time)
        {
        case (1):
            login();
            break;
        case (2):
            main();
            break;
        }
        if (second_time != 1 && second_time != 2)
            printf("\npls select the num on menu");
    }
}
int verify_resetpass(char username_verify[50])
{
    char ansreset[100], ansuser[100];
    printf("////////////////////////\n");
    printf("//verify your identity//\n");
    printf("////////////////////////\n");
    resetpassword(username_verify, ansreset);
    printf("Ans verify question : ");
    scanf("%s", ansuser);
    if (strcmp(ansreset, ansuser) == 0)
    {
        return 15;
    }
    else
        return 10;
}
int startresetpass(char user[50])
{
    char resetpass[50], newpass[50], comfirm_newpass[50];
    strcpy(resetpass, user);
    strcat(resetpass, "_password");
    f = fopen(resetpass, "w");
    do
    {
        printf("Your new password :");
        scanf("%s", newpass);
        printf("comfirm your new password :");
        scanf("%s", comfirm_newpass);
        if (strcmp(newpass, comfirm_newpass) != 0)
        {
            system("clear");
            printf("-----------------------\n");
            printf("recheck your new pass!\n");
            printf("-----------------------\n");
        }
    } while (strcmp(newpass, comfirm_newpass) != 0);
    fprintf(f, "%s", newpass);
    fclose(f);
    system("clear");
    printf("complete reseting your password!\n");
    printf("''''''''''''''''''''''''''''''''\n");
}