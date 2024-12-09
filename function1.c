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
void clearspace(char *);
int main();
int forgetpass(char forget_user[50]) // ลืมรหัสผ่าน
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
                printf("------------------------------\n");
                printf("1.register again\n");
                printf("2.relogin\n");
                printf("3.check again\n");
                printf("------------------------------\n");
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
    char verify_qa[100], verify_ans[100], comfirm_pass[50] = "\0", data_sex[50], decision[10], *c, *su,*va;
    int age, num_disease, ex, a = 0, nd;
    float w = 0, h = 0;
    while (a == 0 || w == 0 || h == 0 || strcmp(decision, "no") == 0)
    {
        // รับข้อมูล
        system("cls");
        printf("\n------------------------------------\n");
        printf("Enter 'back' if you want to go back--\n");
        getchar();
        printf("Name      : ");
        scanf("%[^\n]", name);
        c = name;
        clearspace(c);
        strcpy(name2, name);
        if (strcmp(strlwr(name2), "back") == 0)
        {
            system("cls");
            main();
            break;
        }
        getchar();
        printf("Surname   : ");
        scanf("%[^\n]", surname);
        su = surname;
        clearspace(su);
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
        while (1)
        {
            printf("Exercise per week(max is 5): ");
            scanf("%d", &ex);
            if (ex <= 5 && ex > 0)
                break;
            else
                printf("pls select from bracklet!!\n");
        }
        do
        {
            char *p, *cp;
            p = &password[0], cp = &comfirm_pass[0];
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
        va=verify_ans;
        hpassword(va);
        printf("---------------------------------------\n");
        do
        {
            printf("Confirm your information(yes/no): ");
            scanf("%s", decision);
            strlwr(decision);
            if (strcmp(decision, "yes") != 0 && strcmp(decision, "no") != 0)
                printf("pls select from backlet!!\n");
        } while (strcmp(decision, "yes") != 0 && strcmp(decision, "no") != 0);
    }
    // เริ่มสร้างไฟล์เก็บข้อมูล
    if (strcmp(decision, "yes") == 0)
    {

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
}
int main()
{
    char choice[10];
    printf("---select------------\n");
    printf("1.register      \n");
    printf("2.login         \n");
    printf("3.Exit program  \n");
    printf("---------------------\n");
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
    char name[50], sur[50], dataname[50], username[50], cusername[50], data_password[50], password[50] = "\0", user_password[50], real_password[50] = "\0";
    int count = 0;
    char op[10], cmp[10], *us_pw, *c;
    // กรอกข้อมูลเพื่อเข้าใช้
    printf("-------------------------------\n");
    printf("Enter 'back' if want to go back\n");
    printf("name:");
    fflush(stdin);
    gets(name);
    strcpy(cusername, name);
    if (strcmp(strlwr(cusername), "back") == 0)
    {
        system("cls");
        main();
    }
    else
    {
        printf("surname:");
        fflush(stdin);
        gets(sur);
        strcpy(username, name);
        strcat(username, sur);
        strcpy(data_password, username);
        strcat(data_password, "_password");
        if ((f = fopen(username, "r")) == NULL)
        {
            duser();
            fclose(f);
        }
        else
        {
            fscanf(f, "%s", dataname);
            fclose(f);
            if (strcmp(username, dataname) != 0)
            {
                duser();
                count = 1;
            }
            else if ((f = fopen(data_password, "r")) == NULL)
            {
                printf("pls register again!");
                user_register();
            }
            else
            {
                fscanf(f, "%s", real_password);
                fclose(f);
            }
            if (count == 0)
            {
                printf("Enter 'forget' to reset password\n");
                printf("password: ");
                fflush(stdin);
                us_pw = &password[0];
                hpassword(us_pw);
                if (strcmp(strlwr(password), "forget") == 0)
                {
                    forgetpass(username);
                }
                else if (strcmp(password, real_password) != 0)
                {
                    char D[5];
                    while (1)
                    {
                        printf("---------------\nYour password is wrong!\nPls check your password\n");
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
                                system("cls");
                                login();
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
                // เอาค่ารหัสใหม่ที่รีเซ็ตแล้วมาเทียบ
                else
                {
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
            }
        }
    }
}

int resetpassword(char passname[50], char verify_ans[100]) // รีเซ็ตรหัสผ่าน
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
int goback() // ย้อนกลับไป
{
    int l = 1;
    char second_time[10];
    while (l == 1)
    {
        printf("\n-----select------\n");
        printf("1.login\n");
        printf("2.first page\n");
        printf("-------------------\n");
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
int verify_resetpass(char username_verify[50]) // ยืนยันตัวตนเพื่อรีเซตรหัสผ่าน
{
    char ansreset[100], ansuser[100],*as;
    printf("////////////////////////\n");
    printf("//verify your identity//\n");
    printf("////////////////////////\n");
    resetpassword(username_verify, ansreset);
    printf("Ans verify question : ");
    as=ansuser;
    hpassword(as);
    if (strcmp(ansreset, ansuser) == 0)
    {
        return 15;
    }
    else
        return 10;
}
int startresetpass(char user[50]) // รีเซตรหัส
{
    char resetpass[50], newpass[50], comfirm_newpass[50], *cn, *n;
    strcpy(resetpass, user);
    strcat(resetpass, "_password");
    f = fopen(resetpass, "w");
    do
    {
        printf("Your new password :");
        n = newpass;
        hpassword(n);
        printf("comfirm your new password :");
        cn = comfirm_newpass;
        hpassword(cn);
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
void hpassword(char *h_p) // ซ่อนรหัสไม่ให้แสดงออกจอ
{
    while (1)
    {
        *h_p = getch();
        if (*h_p == '\b')
        {
            h_p--;
            printf("\b \b");
        }
        else if (*h_p == '\r')
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
            while (strcmp(c, "1") != 0 && strcmp(c, "2") != 0)
            {
                system("cls");
                printf("----------------------\n");
                printf("1.register          \n");
                printf("2.Recheck again     \n");
                printf("----------------------\n");
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
            }
            break;
        }
        if (strcmp(ans, "y") != 0 && strcmp(ans, "n") != 0)
        {
            system("cls");
            printf("--------------------------------\n");
            printf("Pls select choice in bracket!\n");
            printf("--------------------------------\n");
        }
    }
    // do 512
}
void clearspace(char *s)
{
    for (s; *s != '\0'; s++)
        if (*s == ' ')
            *s = '\0';
}
