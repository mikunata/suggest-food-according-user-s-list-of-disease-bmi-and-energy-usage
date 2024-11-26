#include <stdio.h>
#include <string.h>
#include <ctype.h>
FILE *f, *p;
void hpassword(char *h_p);
int goback();
int user_register();
void read_file();
int login();
void select_function(char user[50]);
int resetpassword(char passname[50], char[100]);
int verify_resetpass(char[50]);
int startresetpass(char[50]);
int forgetpass(char[50]);
void duser();
int forgetpass(char forget_user[50]) //ลืมรหัสผ่าน
{
    char i[10];
    int v = 0;
    do
    {
        system("cls");
        v = verify_resetpass(forget_user);
        if (v == 15)
        {
            startresetpass(forget_user);
            login();
        }
        else
        {
            system("cls");
            do
            {
                printf("pls check your answer again!!\n");
                printf("******************************\n");
                printf("1.register again\n");
                printf("2.relogin\n");
                printf("3.check again\n");
                printf("******************************\n");
                printf("choose:");
                scanf("%s", i);
                if (strcmp(i, "1") == 0)
                {
                    user_register();
                }
                if (strcmp(i, "2") == 0)
                {
                    system("cls");
                    login();
                }
                if (strcmp(i, "1") != 0 && strcmp(i, "2") != 0 && strcmp(i, "3") != 0)
                {
                    system("cls");
                    printf("pls select num in menu!\n");
                }
            } while (strcmp(i, "1") != 0 && strcmp(i, "2") != 0 && strcmp(i, "3") != 0);
        }

    } while (v != 15);
}
int user_register()
{
    char name[50], surname[50], name2[50], data_age[50], data_sur[50], data_name[50], data_weight[50], data_height[50],
        data_disease[50], sex[10], password[50] = "\0", data_password[50], data_exercise[50], disease[50][50], data_verify_qa[50], data_verify_ans[50];
    char verify_qa[100], verify_ans[100], comfirm_pass[50] = "\0", data_sex[50], decision[10];
    int age, num_disease, ex, a = 0, nd;
    float w = 0, h = 0;
    do
    {
        // รับข้อมูล
        system("cls");
        printf("\n*********************\n");
        printf("Name      : ");
        scanf("%s", name);
        printf("Surname   : ");
        scanf("%s", surname);
        do
        {
            printf("Sex(male/female): ");
            scanf("%s", sex);
            if (strcmp(sex, "male") != 0 && strcmp(decision, "female") != 0)
                printf("pls select from bracklet!!\n");
        } while (strcmp(sex, "male") != 0 && strcmp(sex, "female") != 0);
        while (1)
        {
            printf("Age       : ");
            scanf("%d", &a);
            if (a <= 0)
                printf("pls enter real information!\n");
            if (a > 0)
                break;
        }
        while (1)
        {
            printf("Weight(kg)   : ");
            scanf("%f", &w);
            if (w <= 0)
                printf("pls enter real information!\n");
            if (w > 0)
                break;
        }
        while (1)
        {
            printf("Height(meter): ");
            scanf("%f", &h);
            if (h > 2 || h <= 0)
                printf("pls enter real information!\n");
            if ((h < 2) && (h > 0))
                break;
        }
        printf("Exercise per week: ");
        scanf("%d", &ex);
        do
        {
            char *p, *cp;
            p = &password[0], cp = &comfirm_pass;
            fflush(stdin);
            printf("Create your password:");
            hpassword(p);
            fflush(stdin);
            printf("comfirm your password:");
            hpassword(cp);
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
        do
        {
            printf("Confirm your information(yes/no): ");
            scanf("%s", decision);
            strlwr(decision);
            if (strcmp(decision, "yes") != 0 && strcmp(decision, "no") != 0)
                printf("pls select from backlet!!\n");
        } while (strcmp(decision, "yes") != 0 && strcmp(decision, "no") != 0);
    } while (a == 0 || w == 0 || h == 0 || strcmp(decision, "no") == 0);
    // เริ่มสร้างไฟล์เก็บข้อมูล
    strcpy(name2, name);
    strcat(name, surname);
    strcpy(data_name, name);
    f = fopen(data_name, "w");
    fprintf(f, "%s", name);
    fclose(f);
    strcpy(data_age, name);
    strcat(data_age, "_age");
    f = fopen(data_age, "w");
    fprintf(f, "%d", a);
    fclose(f);
    strcpy(data_sex, name);
    strcat(data_sex, "_sex");
    f = fopen(data_sex, "w");
    fprintf(f, "%s", sex);
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
    if (strcmp(decision, "yes") == 0)
    {
        system("cls");
        goback();
    }
}
int main()
{
    char choice[10];
    printf("********************\n");
    printf("*  1.register      *\n");
    printf("*  2.login         *\n");
    printf("*  3.Exit program  *\n");
    printf("********************\n");
    printf("choose:");
    scanf(" %s", choice);
    if (strcmp(choice, "1") == 0)
    {
        user_register();
    }
    else if (strcmp(choice, "2") == 0)
    {
        system("cls");
        login();
    }
    else if (strcmp(choice, "3") == 0)
        return (0);
    else
    {
        printf(" \n");
        system("cls");
        printf("pls select num in menu!\n");
        main();
    }
}
int login()
{
    char name[50], sur[50], dataname[50], username[50], data_password[50], password[50] = "\0", user_password[50], real_password[50] = "\0";
    int count = 0;
    char op[10], cmp[10];
    // กรอกข้อมูลเพื่อเข้าใช้
    printf("Name :");
    scanf("%s", name);
    printf("Surname :");
    scanf("%s", sur);
    strcpy(username, name);
    strcat(username, sur);
    strcpy(data_password, username);
    strcat(data_password, "_password");
    if ((f = fopen(username, "r")) == NULL)
      duser();
    fscanf(f,"%s",dataname);
    fclose(f);
    if(strcmp(username,dataname)!=0)
        duser();
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
    int p = 1;
    while (p == 1)
    {
        printf("********************\n");
        printf("*1.Enter password  *\n");
        printf("*2.Forgot password *\n");
        printf("********************\n");
        printf("choose: ");
        scanf(" %s", op);
        if (strcmp(op, "1") == 0)
        {
            p = 0;
            do
            { // do 236 รับรหัสผ่าน
                char *us_pw;
                us_pw = &password[0];
                printf("..............\n");
                printf("password: ");
                fflush(stdin);
                hpassword(us_pw);
                if (strcmp(password, real_password) != 0)
                {
                    char D[5];
                    while (1)
                    {
                        printf("Your password is wrong!\nPls check your password\n");
                        printf("accept(y/n): ");
                        scanf("%s", D);
                        strlwr(D);
                        system("cls");
                        if (strcmp(D, "y") == 0)
                            break;
                    }
                    if (strcmp(D, "y") == 0)
                    {
                        int i = 1;
                        while (i == 1)
                        {
                            system("cls");
                            printf("---------------------------\n");
                            printf("1.check your password again!\n");
                            printf("2.forgot password\n");
                            printf("---------------------------\n");
                            printf("choose:");
                            scanf(" %s", cmp);
                            if (strcmp(cmp, "1") == 0)
                            {
                                i = 0;
                            }
                            else if (strcmp(cmp, "2") == 0)
                            {
                                i = 0;
                                forgetpass(username);
                            }
                            else
                            {
                                system("cls");
                                printf("pls select num in menu!\n");
                            }
                        }
                    }
                }
                else
                    count = 1;
            } while (count == 0);
            // do 236
        }
        else if (strcmp(op, "2") == 0)
        {
            p = 0;
            forgetpass(username);
        }
        else
        {
            system("cls");
            printf("pls select num in menu!\n");
        }
    }
    // เอาค่ารหัสใหม่ที่รีเซ็ตแล้วมาเทียบ
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
        system("cls");
        printf("login successful\n");
        select_function(username);
    }
    // ตรวจสอบรหัสผ่าน
}

int resetpassword(char passname[50], char verify_ans[100]) //รีเซ็ตรหัสผ่าน
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
        system("cls");
        printf("Pls register again!!\n");
        user_register();
    }
    fgets(verify_ans, 100, p);
    fclose(p);
}
void select_function(char user[50]) // เอาparameter user ไปต่อด้วยเพื่อกำหนดให้ไฟล์ที่จะสร้างรู้ว่าเป็นของผู้ใช้คนไหน แล้วก็เพื่อให้สามารถกลับมาหน้าเมนูเรียกใช้ฟังก์ชั่นได้
{
    char f_c[10];
    printf("1.calculate BMI\n");
    printf("2.calculate calaries\n");
    printf("3....\n");
    printf("4.logout\n");
    printf("choose : ");
    scanf("%s", f_c);
    if (strcmp(f_c, "1") == 0)
    {
        // function est
    }
    else if (strcmp(f_c, "2") == 0)
    {
        // function
    }
    else if (strcmp(f_c, "3") == 0)
    {
        // functionใดๆๆ
    }
    else if (strcmp(f_c, "4") == 0)
    {
        // char password[50] = "\0", real_password[50] = "\0";
        system("cls");
        main();
    }
    else
    {
        system("cls");
        printf("pls select num in menu!\n");
        select_function(user);
    }
}
int goback() //ย้อนกลับไป
{
    int l = 1;
    char second_time[10];
    while (l == 1)
    {
        printf("\n****/select/****\n");
        printf("1.login\n");
        printf("2.first page\n");
        printf("****************\n");
        printf("select:");
        scanf("%s", second_time);
        if (strcmp(second_time, "1") == 0)
        {
            l = 0;
            system("cls");
            login();
        }
        else if (strcmp(second_time, "2") == 0)
        {
            l = 0;
            system("cls");
            main();
        }
        else
        {
            system("cls");
            printf("\npls select the num on menu");
        }
    }
}
int verify_resetpass(char username_verify[50]) //ยืนยันตัวตนเพื่อรีเซตรหัสผ่าน
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
int startresetpass(char user[50]) //รีเซตรหัส
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
            system("cls");
            printf("-----------------------\n");
            printf("recheck your new pass!\n");
            printf("-----------------------\n");
        }
    } while (strcmp(newpass, comfirm_newpass) != 0);
    fprintf(f, "%s", newpass);
    fclose(f);
    system("cls");
    printf("complete reseting your password!\n");
    printf("''''''''''''''''''''''''''''''''\n");
}
void hpassword(char *h_p) //ซ่อนรหัสไม่ให้แสดงออกจอ
{
    while (1)
    {
        *h_p = getch();
        if (*h_p == '\r')
        {
            *h_p = '\0';
            break;
        }
        else
        {
            printf("*");
            h_p++;
        }
    }
    printf("\n");
}
void duser()
{
    char ans[1];
        while (1)
        { // do512
            char c[10];
            printf("pls register first or check your username\n");
            printf("accept(y/n): ");
            scanf(" %s", ans);
            strlwr(ans);
            if (strcmp(ans, "y") == 0)
            {
                do
                {
                    system("cls");
                    printf("/////////////////////\n");
                    printf("\\1.register         \\ \n");
                    printf("\\2.Recheck again    \\ \n");
                    printf("/////////////////////\n");
                    printf("choose : ");
                    scanf(" %s", c);
                    if (strcmp(c, "1") == 0)
                    {
                        user_register();
                        break;
                    }
                    else if (strcmp(c, "2") == 0)
                    {
                        system("cls");
                        login();
                        break;
                    }
                } while (strcmp(c, "1") != 0 && strcmp(c, "2") != 0);
            }
            if (strcmp(ans, "y") != 0 && strcmp(ans, "n") != 0)
            {
                system("cls");
                printf("--------------------------------\n");
                printf("Pls select choice in bracket!\n");
                printf("--------------------------------\n");
            }
        }
        //do 512
}
