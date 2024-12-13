#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#define MAX_RECORDS 100
#define MAX_LINE_LENGTH 256
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

typedef struct
{
    char foodName[50];
    char time[10];
    int protein;
    int carbs;
    int fat;
    int fiber;
    char date[11];
    int calories;
} FoodRecord;

FILE *f, *p;
void hpassword(char *h_p);
int goback();
int main();
void duser();
int user_register();
void read_file();
int login();
// function2
float calculate_bmi(float weight, float height, char uname[50]);
float calculate_bmr(float weight, float height, int age, char bmrname[50]);
float calculate_tdee(float bmr, char exname[50]);
int callfunction2(char name[50]);
//
// function3
void calculate_calories(char user[50]);
int readFile(FoodRecord data[], char *, char user[50]);
void writeFile(FoodRecord data[], int count, const char *fileName, char user[50]);
void displayData(FoodRecord data[], int count);
void editRecord(FoodRecord *record, FoodRecord *Real, FoodRecord *data);
void edit_data(char user[50]);
void edit_data_calculate_calories(char user[50]);
void replaceSpacesWithUnderscore(char str[]);
void replaceUnderscoreWithSpace(char str[]);
int isLeapYear(int year);
int isValidDate(int day, int month, int year);
int convertToAD(int year);
void Encorage();
//
// function4
float checking(int yourcal);
void displaySummary(const char responses[], const char *diseases[], int count);
void collectResponses(char responses[], const char *diseases[], int count, int *p);
int confirmAction();
void flush_input();
//
// function5
void drawgraph(FILE *dietaryinfo);
int finddate(FILE *dietaryinfo);
int function5(char u[50]);
char monthname[12][15] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
char inputdate[15];
void black();
void green();
void reset();
void BGgreen();
void BGreset();
//
void clearspace(char *);
void select_function(char user[50]);
int resetpassword(char passname[50], char[100]);
int verify_resetpass(char[50]);
int startresetpass(char[50]);
int forgetpass(char[50]);
int showdatatous(char n[50]);
// function 1
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
    char verify_qa[100], verify_ans[100], comfirm_pass[50] = "\0", data_sex[50], decision[10], *c, *su;
    int age, num_disease, ex, a = 0, nd;
    float w = 0, h = 0;
    while (1)
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
            if (strcmp(sex, "male") != 0 && strcmp(sex, "female") != 0)
                printf("pls select from bracklet!!\n");
        } while (strcmp(sex, "male") != 0 && strcmp(sex, "female") != 0);
        while (1)
        {
            char agi[10];
            printf("Age       : ");
            scanf("%d", &a);
            gets(agi);
            if (a > 0 && agi[0] == '\0')
                break;
            else
                printf("pls enter real information!\n");
        }
        while (1)
        {
            char wei[10];
            printf("Weight(kg)   : ");
            scanf("%f", &w);
            gets(wei);
            if (w > 0 && wei[0] == '\0')
                break;
            else
                printf("pls enter real information!\n");
        }
        while (1)
        {
            char hei[10];
            printf("Height(meter): ");
            scanf("%f", &h);
            gets(hei);
            if ((h <= 2) && (h > 0) && hei[0] == '\0')
                break;
            else
                printf("pls enter real information!\n");
        }
        while (1)
        {
            char exe[10];
            printf("Exercise per week(max is 5): ");
            scanf("%d", &ex);
            gets(exe);
            if (ex <= 5 && ex >= 0 && exe[0] == '\0')
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
        scanf(" %[^\n]", verify_ans);
        printf("---------------------------------------\n");
        do
        {
            printf("Confirm your information(yes/no): ");
            getchar();
            scanf("%[^\n]", decision);
            strlwr(decision);
            if (strcmp(decision, "yes") != 0 && strcmp(decision, "no") != 0)
                printf("pls select from backlet!!\n");
        } while (strcmp(decision, "yes") != 0 && strcmp(decision, "no") != 0);
        if (strcmp(decision, "yes") == 0)
            break;
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
    printf("---home page---------\n");
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
    char op[10], cmp[10], *us_pw, *c, *ln, *ls;
    // กรอกข้อมูลเพื่อเข้าใช้
    printf("-------------------------------\n");
    printf("Enter 'back' if want to go back\n");
    printf("name:");
    getchar();
    gets(name);
    ln = name;
    clearspace(ln);
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
        ls = sur;
        clearspace(ls);
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
    printf("----select function-----------\n");
    printf("1.calculate BMI\n");
    printf("2.calculate calaries\n");
    printf("3.display your data\n");
    printf("4.summary in graph\n");
    printf("5.logout\n");
    printf("------------------------------\n");
    printf("choose : ");
    scanf("%s", f_c);
    if (strcmp(f_c, "1") == 0)
    {
        system("cls");
        callfunction2(user);
    }
    else if (strcmp(f_c, "2") == 0)
    {
        system("cls");
        edit_data_calculate_calories(user);
    }
    else if (strcmp(f_c, "3") == 0)
    {
        system("cls");
        showdatatous(user);
    }
    else if (strcmp(f_c, "4") == 0)
    {
        function5(user);
    }
    else if (strcmp(f_c, "5") == 0)
    {
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
    char ansreset[100], ansuser[100], *as;
    printf("////////////////////////\n");
    printf("//verify your identity//\n");
    printf("////////////////////////\n");
    resetpassword(username_verify, ansreset);
    printf("Ans verify question : ");
    as = ansuser;
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
// end function1
// function2
//  Function to calculate BMI
float calculate_bmi(float weight, float height, char uname[50])
{

    // Open the weight file
    char bminame[50];
    float bmi;

    bmi = weight / (height * height);
    strcpy(bminame, uname);
    strcat(bminame, "_bmi");

    return bmi;
}

// Function to calculate BMR
float calculate_bmr(float weight, float height, int age, char bmrname[50])
{
    float bmr;
    char gender[10];
    char bmrsex[50], bmrresult[50];
    strcpy(bmrsex, bmrname);
    strcat(bmrsex, "_sex");
    p = fopen(bmrsex, "r");
    if (p == NULL)
    {
        printf("Error opening sex data file\n");
        return -1;
    }
    fscanf(p, "%s", gender);
    fclose(p);
    strlwr(gender);
    // Mifflin-St Jeor equation for BMR calculation
    if (strcmp(gender, "male") == 0)
    {
        bmr = 10 * weight + 6.25 * height - 5 * age + 5; // For men
    }
    else if (strcmp(gender, "female") == 0)
    {
        bmr = 10 * weight + 6.25 * height - 5 * age - 161; // For women
    }
    else
    {
        printf("Invalid gender input\n");
        return -1; // Error if gender is invalid
    }

    return bmr;
}

// Function to calculate TDEE (Total Daily Energy Expenditure)
float calculate_tdee(float bmr, char exname[50])
{
    float tdee;
    int activity_level;
    char nameex[50], nametd[50];
    strcpy(nameex, exname);
    strcat(nameex, "_exercise");
    p = fopen(nameex, "r");
    fscanf(p, "%d", &activity_level);
    fclose(p);

    // Activity factor based on activity level
    switch (activity_level)
    {
    case 1:
        tdee = bmr * 1.2; // Sedentary
        break;
    case 2:
        tdee = bmr * 1.375; // Lightly active
        break;
    case 3:
        tdee = bmr * 1.55; // Moderately active
        break;
    case 4:
        tdee = bmr * 1.725; // Very active
        break;
    case 5:
        tdee = bmr * 1.9; // Super active
        break;
    default:
        printf("Invalid activity level\n");
        return -1; // Error if activity level is invalid
    }

    return tdee;
}

int callfunction2(char name[50])
{
    float weight, height, bmi, bmr, tdee;

    char wnoname[50], hnoname[50], agename[50];
    int age;
    // First, calculate BMI
    strcpy(wnoname, name);
    strcat(wnoname, "_weight");
    p = fopen(wnoname, "r");
    if (p == NULL)
    {
        printf("Error opening weight file\n");
        return -1;
    }
    if (fscanf(p, "%f", &weight) != 1)
    {
        printf("Error reading weight value\n");
        fclose(p);
        return -1;
    }
    fclose(p);
    strcpy(hnoname, name);
    strcat(hnoname, "_height");
    // Open the height file
    p = fopen(hnoname, "r");
    if (p == NULL)
    {
        printf("Error opening height file\n");
        return -1;
    }
    if (fscanf(p, "%f", &height) != 1)
    {
        printf("Error reading height value\n");
        fclose(p);
        return -1;
    }
    fclose(p);
    strcpy(agename, name);
    strcat(agename, "_age");
    p = fopen(agename, "r");
    if (p == NULL)
    {
        printf("Error opening height file\n");
        return -1;
    }
    if (fscanf(p, "%d", &age) != 1)
    {
        printf("Error reading age value\n");
        fclose(p);
        return -1;
    }
    fclose(p);
    bmi = calculate_bmi(weight, height, name);
    if (bmi != -1)
    {
        printf("BMI calculated: %.2f\n", bmi);
    }

    // Calculate BMR
    bmr = calculate_bmr(weight, height, age, name);
    if (bmr != -1)
    {
        printf("BMR calculated: %.2f\n", bmr);
    }

    // Calculate TDEE (Calories needed per day)
    tdee = calculate_tdee(bmr, name);
    if (tdee != -1)
    {
        printf("Calories needed per day (TDEE): %.2f\n", tdee);
        printf("Calories needed per meal : %.2f\n", tdee / 3);
    }

    checking(tdee / 3);
    char c[5];
    getch();
    {
        system("cls");
        select_function(name);
    }
}

// end function2
// function3

void Encorage()
{

    const char *messages[] = {
        "You can do it!",
        "Keep going strong!",
        "Stay focused, you're doing great!",
        "One step at a time!",
        "Your discipline is your power!",
        "You are in control!",
        "Believe in yourself, keep it up ,Here goes nothing! ",
        "Success is built on consistency!",
        "Stay strong, stay healthy!",
        "Every healthy choice counts!"};

    int ranIndex = rand() % 10; // เศษที่ได้=สมาชิก
    printf("i|*!||--%s--||!*|i", messages[ranIndex]);
}

//  ฟังก์ชันเปลี่ยนเว้นวรรคเป็น "_"
void replaceSpacesWithUnderscore(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {                 // ถ้าเจอเว้นวรรค
            str[i] = '_'; // แทนที่ด้วย _
        }
    }
}

// ฟังก์ชันเปลี่ยน "_" เป็นเว้นวรรค
void replaceUnderscoreWithSpace(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '_')
        {                 // ถ้าเจอ _
            str[i] = ' '; // แทนที่ด้วยเว้นวรรค
        }
    }
}

// ตรวจว่าใช่ปีที่มีอธิกสุรทินหรือไม่ คืนค่า เป็น 1 กับ 0
int isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int isValidDate(int day, int month, int year)
{
    if (month < 1 || month > 12 || day < 1)
    {
        return 0; // ไม่ถูกต้อง
    }

    int daysInMonth[] = {31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day > daysInMonth[month - 1])
    {
        return 0; // ไม่ถูกต้อง
    }

    return 1; // ถูกต้อง
}

// แปลงปีจาก พ.ศ. เป็น ค.ศ.
int convertToAD(int year)
{
    return (year - 543); // แปลงจาก พ.ศ. เป็น ค.ศ.
}

void calculate_calories(char user[50])
{
    int Qin, Neg, A, Prot, Car, Fat, Fit, Fi, Cal, Mo, Da, Ye, T1, T2, REC, LOUIS, Crown, knowncal, date_mont_correct, Time_correct, result1, result2, result3, result4, result5, result6, result7, result8, result9;
    char MN[20];
    char Bud_ADom;
    system("cls");
    fflush(stdin);
    printf("Record or calculate calories from format recorded 1.calories(Kcal) or 2.nutrients(gram)\n");
    printf("Meal's name/ Menu (English Only ) :");
    fflush(stdin);
    gets(MN);
    date_mont_correct = 0;
    Time_correct = 0;
    do
    {
        if (date_mont_correct == 0)
        {
            A = 0;
            while (A == 0)
            {
                A = 1;
                printf("Date/Mont/Year(eg. 01/02/2024)\n ( **1. It is a real date according to the calendar.)\n ( **2. It is not a word or letter.)\n ( **3. Please check carefully whether it is B.E.(Buddhist Era) or A.D.(Anno Domini).(We can estimate roughly.))\n :");
                result4 = scanf("%d/%d/%d", &Da, &Mo, &Ye);
                if (result4 != 3)
                {
                    A = 0; // หากไม่ได้รับค่าจำนวนเต็ม 3 ค่า
                    printf("Invalid input! Please enter three integers separated by slashes.\n");

                    // เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                    while (getchar() != '\n')
                        ; // ข้ามจนกว่าจะถึงบรรทัดใหม่
                }
            }
            date_mont_correct = 1;
        }
        else if (date_mont_correct == 1)
        {
            A = 0;
            while (A == 0)
            {
                A = 1;
                printf("   Date/Mont/year is incorrect.\n ( **1. It is a real date according to the calendar.) \n ( **2. It is not a word or letter.) \n ( **3. Please check carefully whether it is B.E.(Buddhist Era) or A.D.(Anno Domini).(We can estimate roughly.)) \n !! Try again.\n");
                printf("Date/Mont/Year(eg. 01/02/2024) :");
                result3 = scanf("%d/%d/%d", &Da, &Mo, &Ye);
                if (result3 != 3)
                {
                    A = 0; // หากไม่ได้รับค่าจำนวนเต็ม 3 ค่า
                    printf("Invalid input! Please enter three integers separated by slashes.\n");

                    // เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                    while (getchar() != '\n')
                        ; // ข้ามจนกว่าจะถึงบรรทัดใหม่
                }
            }
        } /*เดาคร่าวๆ ว่าเป็น พ.ศ. หรือ คศ.โดยเทียบกับปี2500*/

        if ((Ye > 543 && Ye > 2099) && A != 0)
        {

            fflush(stdin);
            Qin = 0;
            while (Qin == 0)
            {
                while (1)
                {
                    printf("        %4d|--> Is this year in B.E.(Buddhist Era)?\n", Ye);
                    printf("B.E.:%d ?\n (Y/N):", Ye);
                    char result10[14];

                    scanf(" %c", &Bud_ADom);
                    gets(result10);
                    if (result10[0] == '\0')
                        break;
                    else
                        printf("Please do it correctly, I beg you, my dear.\n");

                }

                Qin = (tolower(Bud_ADom) == 'y' || tolower(Bud_ADom) == 'n' ? 1 : 0);
                if (tolower(Bud_ADom) == 'y' && Qin == 1)
                {
                    Ye = convertToAD(Ye);
                    printf("A.D(Anno Domini):%d\n", Ye);
                }
                else if (tolower(Bud_ADom) == 'n' && Qin == 1)
                {
                    printf("A.D(Anno Domini):%d\n", Ye);
                }
            }
        }
        else if ((Ye <= 2099 || Ye < 543) && A != 0)
        {

            fflush(stdin);
            Qin = 0;
            while (Qin == 0)
            {
                while (1)
                {
                    printf("           |--> Is this year in A.D(Anno Domini)?\n");
                    printf("A.D.:%d ?\n(Y/N):", Ye);
                    char re1[14];

                    scanf(" %c", &Bud_ADom);
                    gets(re1);
                    if (re1[0] == '\0')
                        break;
                    else
                        printf("Please do it correctly, I beg you, my dear.\n");

                }
                Qin = (tolower(Bud_ADom) == 'y' || tolower(Bud_ADom) == 'n' ? 1 : 0);
                if (tolower(Bud_ADom) == 'n' && Qin == 1)
                {
                    Ye = convertToAD(Ye);
                    printf("A.D.(Anno Domini):%d\n", Ye);
                }
                else if (tolower(Bud_ADom) == 'y' && Qin == 1)
                {
                    printf("A.D.(Anno Domini):%d\n", Ye);
                }
            }
        }
    } while (isValidDate(Da, Mo, Ye) == 0); /*Da<=0||Da>=32||Mo<=0||Mo>=13||*/

    do
    {
        if (Time_correct == 0)
        {
            A = 0;
            while (A == 0)
            {
                A = 1;
                printf("Time (eg. 15:24) >>"); // ให้พิมพ์เองเพราะจะได้ระบุเวลาตามความต้องการของผู้ใช้ เช่น กินตั้งแต่เที่ยงแต่จะมาพิมพ์ตอนเวลาบ่ายเป็นต้น
                result2 = scanf("%d:%d", &T1, &T2);
                Time_correct = 1;
                if (result2 != 2)
                {
                    A = 0; // หากไม่ได้รับค่าจำนวนเต็ม 2 ค่า
                    printf("Invalid input! Please enter two integers separated by colon.\n");

                    // เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                    while (getchar() != '\n')
                        ; // ข้ามจนกว่าจะถึงบรรทัดใหม่
                }
            }
        }
        else if (Time_correct == 1)
        {
            A = 0;
            while (A == 0)
            {
                A = 1;
                printf("   Time is incorrect.\nTry again.\n");
                printf("Time (eg. 15:24) >>"); // ให้พิมพ์เองเพราะจะได้ระบุเวลาตามความต้องการของผู้ใช้ เช่น กินตั้งแต่เที่ยงแต่จะมาพิมพ์ตอนเวลาบ่ายเป็นต้น
                result1 = scanf("%d:%d", &T1, &T2);
                Time_correct = 1;
                if (result1 != 2)
                {
                    A = 0; // หากไม่ได้รับค่าจำนวนเต็ม 2 ค่า
                    printf("Invalid input! Please enter two integers separated by colon.\n");

                    // เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                    while (getchar() != '\n')
                        ; // ข้ามจนกว่าจะถึงบรรทัดใหม่
                }
            }
        }
    } while (T1 < 0 || T1 >= 24 || T2 < 0 || T2 >= 60); // อ่าน newline เพื่อป้องกันปัญหา

    printf("%02d/%02d/%d\n", Da, Mo, Ye);
    printf("%02d:%02d \n", T1, T2);
    do
    {
        while (1)
        {
            system("cls");
            printf("Do you know the calories? \n If you know, you will type 1 (Know your calories(format1)) ,but if you don't know, you will type 0.(calculate your calories(format2))\n ,Or if you want to back, you will type 3\n :");
            char ree1[14];

            scanf("%d", &knowncal);
            gets(ree1);
            if (ree1[0] == '\0')
                break;
            else
                printf("Please do it correctly, I beg you, my dear.\n");

        }

        if (knowncal == 1)
        {
            system("cls");
            Crown = 1;
            printf("Meal's name/ Menu = %s\n", MN);
            printf("%02d/%02d/%d\n", Da, Mo, Ye);
            printf("%02d:%02d \n", T1, T2);
            printf("You know your meal's calories.(Format Recorded 1)\n");
            A = 0;
            while (A == 0)
            {
                A = 1;
                Neg = 0;
                do
                {
                    if (Neg == 1)
                    {
                        printf("Please, enter Positive Integer.\n");
                    }
                    printf("(----------\\\\*_*//----------)\n");
                    /*Cal=getNumericInputWithComma();*/
                    while (1)
                    {
                        printf("Please, enter your meal's calories(Kcal).\n: ");

                        char ree114[14];
                        scanf("%d", &Cal);
                        gets(ree114);
                        if (ree114[0] == '\0')
                        {
                            break;
                        }
                        else
                            printf("Please do it correctly, I beg you, my Honey.\n");

                    }
                    Neg = 1;
                } while (Cal < 0);
            }
            system("cls");
            printf("*****|| Calories in this meal is %d kilocalories ||***** \n\n", Cal);
            Prot = 0;
            Car = 0;
            Fat = 0;
            Fi = 0;
            printf("-*-*-*-*-*-* I belive in yourself. my friend *-*-*-*-*-*-\n");
            printf("-*-*\\*\\*\\");
            srand(time(NULL));
            Encorage();
            printf("/*/*/*-*- \n\n");
        }
        else if (knowncal == 0)
        {
            system("cls");
            Crown = 1;
            printf("Meal's name/ Menu = %s\n", MN);
            printf("%02d/%02d/%d\n", Da, Mo, Ye);
            printf("%02d:%02d \n", T1, T2);
            printf("You want to calculate your meal's calories.(Format Recorded 2)\n");
            printf("Please, enter the number of grams of protein, carbohydrate, fat and dietary fiber.\n");
            A = 0;
            while (A == 0)
            {
                A = 1;
                Neg = 0;
                do
                {
                    if (Neg == 1)
                    {
                        printf("Please, enter Positive Integer.\n");
                    }
                    while (1)
                    {
                        printf("Protein (g): ");

                        char ree113[14];
                        scanf("%d", &Prot);
                        gets(ree113);
                        if (ree113[0] == '\0')
                        {
                            break;
                        }
                        else
                            printf("Please do it correctly, I beg you, my Honey.\n");

                    }
                    Neg = 1;
                } while (Prot < 0);
            }
            A = 0;
            while (A == 0)
            {
                A = 1;
                Neg = 0;
                do
                {
                    if (Neg == 1)
                    {
                        printf("Please, enter Positive Integer.\n");
                    }
                    while (1)
                    {
                        printf("Carbohydrates(sugar&starch) (g): ");

                        char ree182[14];
                        scanf("%d", &Car);
                        gets(ree182);
                        if (ree182[0] == '\0')
                        {
                            break;
                        }
                        else
                            printf("Please do it correctly, I beg you, my Sweetie.\n");

                    }
                    Neg = 1;
                } while (Car < 0);
            }
            A = 0;
            while (A == 0)
            {
                A = 1;
                Neg = 0;
                do
                {
                    if (Neg == 1)
                    {
                        printf("Please, enter Positive Integer.\n");
                    }
                    while (1)
                    {
                        printf("Fat(g): ");

                        char ree132[14];
                        scanf("%d", &Fat);
                        gets(ree132);
                        if (ree132[0] == '\0')
                        {
                            break;
                        }
                        else
                            printf("Please do it correctly, I beg you, my dear.\n");

                    }
                    Neg = 1;
                } while (Fat < 0);
            }
            A = 0;
            while (A == 0)
            {
                A = 1;
                Neg = 0;
                do
                {
                    if (Neg == 1)
                    {
                        printf("Please, enter Positive Integer.\n");
                    }
                    while (1)
                    {
                        printf("Dietary fiber (g): ");

                        char ree172[14];
                        scanf("%d", &Fi);
                        gets(ree172);
                        if (ree172[0] == '\0')
                        {
                            break;
                        }
                        else
                            printf("Please do it correctly, I beg you, my dear.\n");

                    }
                    Neg = 1;
                } while (Fi < 0);
            }
            system("cls");
            printf("Protein = %d g,Carbohydrate = %d g, Fat = %d g, Dietary fiber = %d g\n", Prot, Car, Fat, Fi);
            Cal = Prot * 4 + Car * 4 + Fat * 9 + Fi * 0;
            printf(" *****|| Calories in this meal is %d kilocalories ||***** \n\n", Cal);
            printf("-*-*-*-*-*-* I belive in yourself. my friend *-*-*-*-*-*-\n");
            printf("-*-*\\*\\*\\");
            srand(time(NULL));
            Encorage();
            printf("/*/*/*-*- \n\n");
        }
        else if (knowncal == 3)
        {
            system("cls");
            printf("Already back\n");
            Crown = 1;
            calculate_calories(user);
        }
        else if (knowncal != 0 && knowncal != 1 && knowncal != 3)
        {
            system("cls");
            printf("incorrect");
            Crown = 0;
        }
    } while (Crown == 0);

    do
    {
        while (1)
        {
            printf("Do you want to record this calories? \n If you want to do, you will type 1 ,but if you don't want to record, you will type 0.\n ,Or if you want to back to the calculate calories page and don't record this data, you will type 3\n :");

            char ree142[14];
            scanf("%d", &REC);
            gets(ree142);
            if (ree142[0] == '\0')
            {
                break;
            }
            else
                printf("Please do it correctly, I beg you, my dear.\n");
        }

        if (REC == 1)
        {
            char filename[50];
            strcpy(filename, user);
            strcat(filename, "_dietary_information");
            FILE *CLR = fopen(filename, "a+");
            LOUIS = 1;
            printf("You want to record this data.\n");
            replaceSpacesWithUnderscore(MN);
            fprintf(CLR, "%s ", MN);
            fprintf(CLR, "%02d:%02d ", T1, T2);
            fprintf(CLR, "%d ", Prot);
            fprintf(CLR, "%d ", Car);
            fprintf(CLR, "%d ", Fat);
            fprintf(CLR, "%d ", Fi);
            fprintf(CLR, "%02d/%02d/%d ", Da, Mo, Ye);
            fprintf(CLR, "%d\n", Cal);

            fclose(CLR);
            system("cls");
            printf("Write data to file %s complete.\n", filename);
            printf("Go to the calculate calories page.");
            edit_data_calculate_calories(user); // อย่าลืมเชื่อมไปหน้ารวมฟังก์ชั่น;
        }
        else if (REC == 3)
        {
            system("cls");
            LOUIS=1;
            printf("You want to back to the calculate calories page.\n");
            printf("Go to the calculate calaries page.\n");
            edit_data_calculate_calories(user); // อย่าลืมเชื่อมไปหน้ารวมฟังก์ชั่น;
        }
        else if (REC == 0)
        {
            system("cls");
            LOUIS = 1;
            printf("You don't want to record this data.\n");
            printf("And you want to calculate calories again.\n");
            calculate_calories(user);
        }
        else if (REC != 0 && REC != 1 && REC != 3)
        {
            system("cls");
            LOUIS = 0;
            printf("You are incorrect.\n You must type again.\n");
        }
    } while (LOUIS == 0);
}

// ฟังก์ชันสำหรับอ่านข้อมูลจากไฟล์
int readFile(FoodRecord data[], char Name[50], char user[50])
{
    FILE *file = fopen(Name, "r");
    if (file == NULL)
    {
        printf("/*/*/Unable to open file.\\*\\*\\ \n***Record your calories first.***\n");
        edit_data_calculate_calories(user);
    }
    else
    {
        int count = 0;
        while (count < MAX_RECORDS &&
               fscanf(file, "%s %s %d %d %d %d %s %d",
                      data[count].foodName, data[count].time,
                      &data[count].protein, &data[count].carbs,
                      &data[count].fat, &data[count].fiber,
                      data[count].date, &data[count].calories) == 8)
        {
            replaceUnderscoreWithSpace(data[count].foodName);
            count++;
        }
        fclose(file);
        return count;
    }
}

// ฟังก์ชันสำหรับเขียนข้อมูลกลับไปยังไฟล์
void writeFile(FoodRecord data[], int count, const char *fileName, char user[50])
{
    FILE *file = fopen(fileName, "w");
    if (file == NULL)
    {
        printf("Unable to write file\n BACK TO THE CALCULATE CALORIES PAGE.\n");
        edit_data_calculate_calories(user); // เชื่อมไปhomepage
    }

    for (int i = 0; i < count; i++)
    {
        replaceSpacesWithUnderscore(data[i].foodName);
        fprintf(file, "%s %s %d %d %d %d %s %d\n",
                data[i].foodName, data[i].time,
                data[i].protein, data[i].carbs,
                data[i].fat, data[i].fiber,
                data[i].date, data[i].calories);
    }
    fclose(file);
}

// ฟังก์ชันสำหรับแสดงข้อมูลทั้งหมด
void displayData(FoodRecord data[], int count)
{
    printf("\nYour data:\n");

    for (int i = 0; i < count; i++)
    {
        if (data[i].protein == 0 && data[i].carbs == 0 && data[i].fat == 0 && data[i].fiber == 0 && data[i].calories != 0)
        {
            replaceUnderscoreWithSpace(data[i].foodName);
            printf("\nItem number(In.) %d:\n", i + 1);
            printf("***|Format-Recorded(FR.) : 1.\n   |-> You recorded your calories by entering the calories you knew,\n and you didn't enter grams of protein, carbohydrates, fat, dietary fiber.***\n\n");
            printf("Menu/meal: %s\nTime: %s\n", data[i].foodName, data[i].time);
            printf("Date: %s\nCalories: %d\n\n", data[i].date, data[i].calories);
            printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< FR. 1 >>>>>>>>>>>>>>>> (*^_^*) <<<<<<<<<<<<<<<< In. %d >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n", i + 1);
        }
        else
        {
            replaceUnderscoreWithSpace(data[i].foodName);
            printf("\nItem number(In.) %d:\n", i + 1);
            printf("***|Format-Recorded(FR.) : 2.\n   |-> You recorded your calories by entering grams of protein, carbohydrates, fat, and dietary fiber\n, and then used the values you entered to calculate the calories.***\n\n");
            printf("Menu/meal: %s \nTime: %s\n", data[i].foodName, data[i].time);
            printf("Protein: %d g, \nCarbohydrate: %d g, \nFat: %d g,\nDietary fiber : %d g\n",
                   data[i].protein, data[i].carbs, data[i].fat, data[i].fiber);
            printf("Date: %s \nCalories: %d\n\n", data[i].date, data[i].calories);
            printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< FR. 2 >>>>>>>>>>>>>>>> (*^o^*) <<<<<<<<<<<<<<<< In. %d >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n", i + 1);
        }
    }
}

// ฟังก์ชันสำหรับแก้ไขข้อมูล
void editRecord(FoodRecord *record, FoodRecord *Real, FoodRecord *data)
{
    int Qin, Neg, Neg1, Quay, Mi_Bazi, i, n, date_mont_correct, Da = 0, Mo = 0, Ye = 0, T1 = 0, T2 = 0, Time_correct, result, result1, B;
    char Kung_Fu[100];
    char Bud_ADom;
    do
    {
        char choice[10];
        Quay = 0;
        if (data->protein == 0 && data->carbs == 0 && data->fat == 0 && data->fiber == 0 && data->calories != 0)
        {
            printf("\nSelect the information you want to edit.(Choose Number ONLY!):\n");
            printf("1. Name of Menu/meal\n");
            printf("2. Time\n");
            printf("3. Date\n");
            printf("4. Calories\n");
            printf("Your options: ");
        }
        else
        {
            printf("\nSelect the information you want to edit.(Choose Number ONLY!):\n");
            printf("1. Name of Menu/meal\n");
            printf("2. Time\n");
            printf("3. Protein\n");
            printf("4. Carbohydrate\n");
            printf("5. Fat\n");
            printf("6. Dietary fiber\n");
            printf("7. Date\n");

            printf("Your options: ");
        }
        int result16;
        result16 = scanf("%s", choice);
        if (result16 != 1)
        {

            printf("Invalid input! Please enter an integer.\n");

            while (getchar() != '\n')
                ;
        }
        if (data->protein == 0 && data->carbs == 0 && data->fat == 0 && data->fiber == 0 && data->calories != 0)
        {
            if (strcmp(choice, "1") == 0)
            {
                printf("New food name: ");
                fflush(stdin);
                gets(record->foodName);
                replaceSpacesWithUnderscore(record->foodName);
            }
            else if (strcmp(choice, "2") == 0)
            {
                B = 0;
                while (B == 0)
                {
                    B = 1;
                    printf("New time (15:24): ");
                    Time_correct = 0;
                    if (Time_correct == 0)
                    {
                        result = scanf("%d:%d", &T1, &T2);
                        if (result != 2)
                        {
                            B = 0;
                            printf("Invalid input! Please enter two integers separated by a colon.\n");
                            while (getchar() != '\n')
                                ;
                        }
                        Time_correct = 1;
                    }
                }
                while (T1 < 0 || T1 >= 24 || T2 < 0 || T2 >= 60)
                {
                    if (Time_correct == 1)
                    {
                        printf("   Time is incorrect.\nTry again.\n");
                        B = 0;
                        while (B == 0)
                        {
                            B = 1;
                            printf("Time (eg. 15:24) >>"); // ให้พิมพ์เองเพราะจะได้ระบุเวลาตามความต้องการของผู้ใช้ เช่น กินตั้งแต่เที่ยงแต่จะมาพิมพ์ตอนเวลาบ่ายเป็นต้น
                            result1 = scanf("%d:%d", &T1, &T2);
                            Time_correct = 1;
                            if (result1 != 2)
                            {
                                B = 0; // หากไม่ได้รับค่าจำนวนเต็ม 2 ค่า
                                printf("Invalid input! Please enter two integers separated by a colon.\n");

                                // เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                                while (getchar() != '\n')
                                    ; // ข้ามจนกว่าจะถึงบรรทัดใหม่
                            }
                        }
                    }
                    else if (Time_correct == 0)
                    {
                    }
                }
                sprintf(Kung_Fu, "%d:%d", T1, T2);
                printf("%s\n", Kung_Fu);
                strcpy(record->time, Kung_Fu);
                // scanf("%9s", record->time);
                /*if(Time_correct==0){printf("Time (eg. 15:24) >>"); //ให้พิมพ์เองเพราะจะได้ระบุเวลาตามความต้องการของผู้ใช้ เช่น กินตั้งแต่เที่ยงแต่จะมาพิมพ์ตอนเวลาบ่ายเป็นต้น
        scanf("%d:%d",&T1,&T2);Time_correct=1;}
        else if(Time_correct==1){printf("   Time is incorrect.\nTry again.\n");
        printf("Time (eg. 15:24) >>"); //ให้พิมพ์เองเพราะจะได้ระบุเวลาตามความต้องการของผู้ใช้ เช่น กินตั้งแต่เที่ยงแต่จะมาพิมพ์ตอนเวลาบ่ายเป็นต้น
        scanf("%d:%d",&T1,&T2);Time_correct=1;}}while(T1<0||T1>=24||T2<0||T2>=60);*/
            }
            else if (strcmp(choice, "3") == 0)
            {
                B = 0;
                while (B == 0)
                {
                    B = 1;
                    printf("New Date (dd/mm/yyyy)\n ( **1. It is a real date according to the calendar.)\n ( **2. It is not a word or letter.)\n ( **3. Please check carefully whether it is B.E.(Buddhist Era) or A.D.(Anno Domini).(We can estimate roughly.))\n : ");
                    date_mont_correct = 0;
                    if (date_mont_correct == 0)
                    {
                        result = scanf("%d/%d/%d", &Da, &Mo, &Ye);
                        if (result != 3)
                        {
                            B = 0;
                            printf("Invalid input! Please enter three integers seperated by slashes.\n ");
                            while (getchar() != '\n')
                                ;
                        }
                    }
                    date_mont_correct = 1;
                    if ((Ye > 543 && Ye > 2099) && B != 0)
                    {

                        fflush(stdin);
                        Qin = 0;
                        while (Qin == 0)
                        {
                            while (1)
                            {
                                printf("           |--> Is this year in B.E.(Buddhist Era)?\n");
                                printf("B.E.:%d ?\n(Y/N):", Ye);
                                char re12[14];

                                scanf(" %c", &Bud_ADom);
                                gets(re12);
                                if (re12[0] == '\0')
                                    break;
                                else
                                    printf("Please do it correctly, I beg you, my dear.\n");

                            }
                            Qin = (tolower(Bud_ADom) == 'y' || tolower(Bud_ADom) == 'n' ? 1 : 0);
                            if (tolower(Bud_ADom) == 'y' && Qin == 1)
                            {
                                Ye = convertToAD(Ye);
                                printf("A.D(Anno Domini):%d\n", Ye);
                            }
                            else if (tolower(Bud_ADom) == 'n' && Qin == 1)
                            {
                                printf("A.D(Anno Domini):%d\n", Ye);
                            }
                        }
                    }
                    else if ((Ye <= 2099 || Ye < 543) && B != 0)
                    {
                        fflush(stdin);
                        Qin = 0;
                        while (Qin == 0)
                        {
                            while (1)
                            {
                                printf("           |--> Is this year in A.D(Anno Domini)?\n");
                                printf("A.D.:%d ?\n(Y/N):", Ye);
                                char re123[14];

                                scanf(" %c", &Bud_ADom);
                                gets(re123);
                                if (re123[0] == '\0')
                                    break;
                                else
                                    printf("Please do it correctly, I beg you, my dear.\n");

                            }

                            Qin = (tolower(Bud_ADom) == 'y' || tolower(Bud_ADom) == 'n' ? 1 : 0);
                            if (tolower(Bud_ADom) == 'n' && Qin == 1)
                            {
                                Ye = convertToAD(Ye);
                                printf("A.D.(Anno Domini):%d\n", Ye);
                            }
                            else if (tolower(Bud_ADom) == 'y' && Qin == 1)
                            {
                                printf("A.D.(Anno Domini):%d\n", Ye);
                            }
                        }
                    }
                }
                while (isValidDate(Da, Mo, Ye) == 0)
                {
                    if (date_mont_correct == 1)
                    {
                        printf("   Date/Mont/year is incorrect!!!.\n ( **1. It is a real date according to the calendar.)\n ( **2. It is not a word or letter.)\n ( **3. Please check carefully whether it is B.E.(Buddhist Era) or A.D.(Anno Domini).(We can estimate roughly.))\n !!!Try again.\n");
                        B = 0;
                        while (B == 0)
                        {
                            B = 1;
                            printf("Date/Mont/Year(eg. 01/02/2024)\n ( **1. It is a real date according to the calendar.)\n ( **2. It is not a word or letter.)\n ( **3. Please check carefully whether it is B.E.(Buddhist Era) or A.D.(Anno Domini).(We can estimate roughly.))\n :");
                            result1 = scanf("%d/%d/%d", &Da, &Mo, &Ye);
                            if (result1 != 3)
                            {
                                B = 0; // หากไม่ได้รับค่าจำนวนเต็ม 3 ค่า
                                printf("Invalid input! Please enter three integers separated by slashes.\n");

                                //  เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                                while (getchar() != '\n')
                                    ; // ข้ามจนกว่าจะถึงบรรทัดใหม่
                            }
                        }
                    }
                    else if (date_mont_correct == 0)
                    {
                    }
                    if ((Ye > 543 && Ye > 2099) && B != 0)
                    {

                        fflush(stdin);
                        Qin = 0;
                        while (Qin == 0)
                        {
                            while (1)
                            {
                                printf("           |--> Is this year in B.E.(Buddhist Era)?\n");
                                printf("B.E.:%d ?\n(Y/N):", Ye);
                                char re1234[14];

                                scanf(" %c", &Bud_ADom);
                                gets(re1234);
                                if (re1234[0] == '\0')
                                    break;
                                else
                                    printf("Please do it correctly, I beg you, my dear.\n");

                            } 

                            Qin = (tolower(Bud_ADom) == 'y' || tolower(Bud_ADom) == 'n' ? 1 : 0);
                            if (tolower(Bud_ADom) == 'y' && Qin == 1)
                            {
                                Ye = convertToAD(Ye);
                                printf("A.D(Anno Domini):%d\n", Ye);
                            }
                            else if (tolower(Bud_ADom) == 'n' && Qin == 1)
                            {
                                printf("A.D(Anno Domini):%d\n", Ye);
                            }
                        }
                    }
                    else if ((Ye <= 2099 || Ye < 543) && B != 0)
                    {
                        fflush(stdin);
                        Qin = 0;
                        while (Qin == 0)
                        {
                            while (1)
                            {
                                printf("           |--> Is this year in A.D(Anno Domini)?\n");
                                printf("A.D.:%d?\n(Y/N):", Ye);
                                char re12345[14];

                                scanf(" %c", &Bud_ADom);
                                gets(re12345);
                                if (re12345[0] == '\0')
                                    break;
                                else
                                    printf("Please do it correctly, I beg you, my dear.\n");

                            }

                            Qin = (tolower(Bud_ADom) == 'y' || tolower(Bud_ADom) == 'n' ? 1 : 0);
                            if (tolower(Bud_ADom) == 'n' && Qin == 1)
                            {
                                Ye = convertToAD(Ye);
                                printf("A.D.(Anno Domini):%d\n", Ye);
                            }
                            else if (tolower(Bud_ADom) == 'y' && Qin == 1)
                            {
                                printf("A.D.(Anno Domini):%d\n", Ye);
                            }
                        }
                    }
                }
                sprintf(Kung_Fu, "%d/%d/%d", Da, Mo, Ye);
                printf("%s\n", Kung_Fu);
                strcpy(record->date, Kung_Fu);
                /*fflush(stdin);
                gets(record->date);
                n=strlen(record->date);*/
            }
            else if (strcmp(choice, "4") == 0)
            {
                B = 0;
                while (B == 0)
                {
                    B = 1;
                    Neg = 0;
                    do
                    {
                        if (Neg == 1)
                        {
                            printf("Please, enter Positive Integer.\n");
                        }
                        while (1)
                        {
                            printf("New Calories (g): ");

                            char ree12[14];
                            scanf("%d", &record->calories);
                            gets(ree12);
                            if (ree12[0] == '\0')
                            {
                                break;
                            }
                            else
                                printf("Please do it correctly, I beg you, my dear.\n");

                        }
                        Neg = 1;
                    } while (record->calories < 0);
                }
            }
            else
            {
                printf("Incorrect option\n");
                Quay = 1;
            }
        }
        else
        {
            if (strcmp(choice, "1") == 0)
            {
                printf("New food name: ");
                fflush(stdin);
                gets(record->foodName);
                replaceSpacesWithUnderscore(record->foodName);
            }
            else if (strcmp(choice, "2") == 0)
            {
                B = 0;
                while (B == 0)
                {
                    B = 1;
                    printf("New time (15:24): ");
                    Time_correct = 0;
                    if (Time_correct == 0)
                    {
                        result = scanf("%d:%d", &T1, &T2);
                        if (result != 2)
                        {
                            B = 0; // หากไม่ได้รับค่าจำนวนเต็ม 2 ค่า
                            printf("Invalid input! Please enter two integers separated by a colon.\n");

                            //  เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                            while (getchar() != '\n')
                                ; // ข้ามจนกว่าจะถึงบรรทัดใหม่
                        }
                        Time_correct = 1;
                    }
                }
                while (T1 < 0 || T1 >= 24 || T2 < 0 || T2 >= 60)
                {
                    if (Time_correct == 1)
                    {
                        printf("   Time is incorrect.\nTry again.\n");
                        B = 0;
                        while (B == 0)
                        {
                            B = 1;
                            printf("Time (eg. 15:24) >>"); // ให้พิมพ์เองเพราะจะได้ระบุเวลาตามความต้องการของผู้ใช้ เช่น กินตั้งแต่เที่ยงแต่จะมาพิมพ์ตอนเวลาบ่ายเป็นต้น
                            result1 = scanf("%d:%d", &T1, &T2);
                            if (result1 != 2)
                            {
                                B = 0; // หากไม่ได้รับค่าจำนวนเต็ม 2 ค่า
                                printf("Invalid input! Please enter two integers separated by a colon.\n");

                                // เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                                while (getchar() != '\n')
                                    ; // ข้ามจนกว่าจะถึงบรรทัดใหม่
                            }
                            Time_correct = 1;
                        }
                    }
                    else if (Time_correct == 0)
                    {
                    }
                }
                sprintf(Kung_Fu, "%d:%d", T1, T2);
                printf("%s\n", Kung_Fu);
                strcpy(record->time, Kung_Fu);
                // scanf("%9s", record->time);
            }
            else if (strcmp(choice, "3") == 0)
            {
                B = 0;
                while (B == 0)
                {
                    B = 1;
                    record->protein;
                    Mi_Bazi = record->protein;
                    Neg = 0;
                    do
                    {
                        if (Neg == 1)
                        {
                            printf("Please, enter Positive Integer.\n");
                        }
                        while (1)
                        {
                            printf("New proteins (g): ");

                            char ree12[14];
                            scanf("%d", &record->protein);
                            gets(ree12);
                            if (ree12[0] == '\0')
                            {
                                break;
                            }
                            else
                                printf("Please do it correctly, I beg you, my dear.\n");

                        } 
                        Neg = 1;
                    } while (record->protein < 0);
                }
                Real->calories;
                Real->calories = Real->calories - 4 * Mi_Bazi + 4 * record->protein;
                printf("\nThis is the new calories: %d Kcal\n", Real->calories);
            }
            else if (strcmp(choice, "4") == 0)
            {
                B = 0;
                while (B == 0)
                {
                    B = 1;
                    record->carbs;
                    Mi_Bazi = record->carbs;
                    Neg = 0;
                    do
                    {
                        if (Neg == 1)
                        {
                            printf("Please, enter Positive Integer.\n");
                        }
                        while (1)
                        {
                            printf("New carbohydrates (g): ");

                            char ree12[14];
                            scanf("%d", &record->carbs);
                            gets(ree12);
                            if (ree12[0] == '\0')
                            {
                                break;
                            }
                            else
                                printf("Please do it correctly, I beg you, my dear.\n");

                        }
                        Neg = 1;
                    } while (record->carbs < 0);
                } // อ่าน newline เพื่อป้องกันปัญหา
                Real->calories;
                Real->calories = Real->calories - 4 * Mi_Bazi + 4 * record->carbs;
                printf("\nThis is the new calories: %d Kcal\n", Real->calories);
            }
            else if (strcmp(choice, "5") == 0)
            {
                B = 0;
                while (B == 0)
                {
                    B = 1;
                    record->fat;
                    Mi_Bazi = record->fat;
                    Neg = 0;
                    do
                    {
                        if (Neg == 1)
                        {
                            printf("Please, enter Positive Integer.\n");
                        }
                        while (1)
                        {
                            printf("New fat (g): ");

                            char ree12[14];
                            scanf("%d", &record->fat);
                            gets(ree12);
                            if (ree12[0] == '\0')
                            {
                                break;
                            }
                            else
                                printf("Please do it correctly, I beg you, my dear.\n");

                        }
                        Neg = 1;
                    } while (record->fat < 0);
                } // อ่าน newline เพื่อป้องกันปัญหา
                Real->calories;
                Real->calories = Real->calories - 9 * Mi_Bazi + 9 * record->fat;
                printf("\nThis is the new calories: %d Kcal\n", Real->calories);
            }
            else if (strcmp(choice, "6") == 0)
            {
                B = 0;
                char yu1[14];
                while (B == 0)
                {
                    B = 1;
                    record->fiber;
                    Mi_Bazi = record->fiber;
                    Neg = 0;
                    do
                    {
                        if (Neg == 1)
                        {
                            printf("Please, enter Positive Integer.\n");
                        }
                        while (1)
                        {
                            printf("New dietary fiber (g): ");

                            char ree12[14];
                            scanf("%d", &record->fiber);
                            gets(ree12);
                            if (ree12[0] == '\0')
                            {
                                break;
                            }
                            else
                                printf("Please do it correctly, I beg you, my dear.\n");

                        }
                        Neg = 1;
                    } while (record->fiber < 0);
                }

                Real->calories;
                Real->calories = Real->calories - 0 * Mi_Bazi + 0 * record->fiber;
                printf("\nThis is the new calories: %d Kcal\n", Real->calories);
            }
            else if (strcmp(choice, "7") == 0)
            {
                B = 0;
                while (B == 0)
                {
                    B = 1;
                    printf("New Date (dd/mm/yyyy)\n ( **1. It is a real date according to the calendar.)\n ( **2. It is not a word or letter.)\n ( **3. Please check carefully whether it is B.E.(Buddhist Era) or A.D.(Anno Domini).(We can estimate roughly.))\n : ");
                    date_mont_correct = 0;
                    if (date_mont_correct == 0)
                    {
                        result = scanf("%d/%d/%d", &Da, &Mo, &Ye);
                        if (result != 3)
                        {
                            B = 0; // หากไม่ได้รับค่าจำนวนเต็ม 3 ค่า
                            printf("Invalid input! Please enter three integers separated by slashes.\n");

                            // เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                            while (getchar() != '\n')
                                ;
                        } // ข้ามจนกว่าจะถึงบรรทัดใหม่
                        date_mont_correct = 1;
                    }
                    if ((Ye > 543 && Ye > 2099) && B != 0)
                    {

                        fflush(stdin);
                        Qin = 0;
                        while (Qin == 0)
                        {
                            while (1)
                            {
                                printf("           |--> Is this year in B.E.(Buddhist Era)?\n");
                                printf("B.E.:%d ?\n(Y/N):", Ye);
                                char re123456[14];

                                scanf(" %c", &Bud_ADom);
                                gets(re123456);
                                if (re123456[0] == '\0')
                                    break;
                                else
                                    printf("Please do it correctly, I beg you, my dear.\n");

                            }

                            Qin = (tolower(Bud_ADom) == 'y' || tolower(Bud_ADom) == 'n' ? 1 : 0);
                            if (tolower(Bud_ADom) == 'y' && Qin == 1)
                            {
                                Ye = convertToAD(Ye);
                                printf("A.D(Anno Domini):%d\n", Ye);
                            }
                            else if (tolower(Bud_ADom) == 'n' && Qin == 1)
                            {
                                printf("A.D(Anno Domini):%d\n", Ye);
                            }
                        }
                    }
                    else if ((Ye <= 2099 || Ye < 543) && B != 0)
                    {
                        fflush(stdin);
                        Qin = 0;
                        while (Qin == 0)
                        {
                            while (1)
                            {
                                printf("           |--> Is this year in A.D(Anno Domini)?\n");
                                printf("A.D.:%d ?\n(Y/N):", Ye);
                                char re1234567[14];

                                scanf(" %c", &Bud_ADom);
                                gets(re1234567);
                                if (re1234567[0] == '\0')
                                    break;
                                else
                                    printf("Please do it correctly, I beg you, my dear.\n");

                            }

                            Qin = (tolower(Bud_ADom) == 'y' || tolower(Bud_ADom) == 'n' ? 1 : 0);
                            if (tolower(Bud_ADom) == 'n' && Qin == 1)
                            {
                                Ye = convertToAD(Ye);
                                printf("A.D.(Anno Domini):%d\n", Ye);
                            }
                            else if (tolower(Bud_ADom) == 'y' && Qin == 1)
                            {
                                printf("A.D.(Anno Domini):%d\n", Ye);
                            }
                        }
                    }
                }
                while (isValidDate(Da, Mo, Ye) == 0)
                {
                    if (date_mont_correct == 1)
                    {
                        printf("   Date/Mont/year is incorrect!!!.\n ( **1. It is a real date according to the calendar.)\n ( **2. It is not a word or letter.)\n ( **3. Please check carefully whether it is B.E.(Buddhist Era) or A.D.(Anno Domini).(We can estimate roughly.))\n !!!Try again.\n");
                        B = 0;
                        while (B == 0)
                        {
                            B = 1;
                            printf("Date/Mont/Year(eg. 01/02/2024)\n ( **1. It is a real date according to the calendar.)\n ( **2. It is not a word or letter.)\n ( **3. Please check carefully whether it is B.E.(Buddhist Era) or A.D.(Anno Domini).(We can estimate roughly.))\n  :");
                            result1 = scanf("%d/%d/%d", &Da, &Mo, &Ye);
                            if (result1 != 3)
                            {
                                B = 0; // หากไม่ได้รับค่าจำนวนเต็ม 3 ค่า
                                printf("Invalid input! Please enter three integers separated by slashes.\n");

                                //  เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                                while (getchar() != '\n')
                                    ; // ข้ามจนกว่าจะถึงบรรทัดใหม่
                            }
                        }
                    }
                    else if (date_mont_correct == 0)
                    {
                    }
                    if ((Ye > 543 && Ye > 2099) && B != 0)
                    {

                        fflush(stdin);
                        Qin = 0;
                        while (Qin == 0)
                        {
                            while (1)
                            {
                                printf("           |--> Is this year in B.E.(Buddhist Era)?\n");
                                printf("B.E.:%d ?\n(Y/N):", Ye);
                                char re12345678[14];

                                scanf(" %c", &Bud_ADom);
                                gets(re12345678);
                                if (re12345678[0] == '\0')
                                    break;
                                else
                                    printf("Please do it correctly, I beg you, my dear.\n");

                            }

                            Qin = (tolower(Bud_ADom) == 'y' || tolower(Bud_ADom) == 'n' ? 1 : 0);
                            if (tolower(Bud_ADom) == 'y' && Qin == 1)
                            {
                                Ye = convertToAD(Ye);
                                printf("A.D(Anno Domini):%d\n", Ye);
                            }
                            else if (tolower(Bud_ADom) == 'n' && Qin == 1)
                            {
                                printf("A.D(Anno Domini):%d\n", Ye);
                            }
                        }
                    }
                    else if ((Ye <= 2099 || Ye < 543) && B != 0)
                    {
                        fflush(stdin);
                        Qin = 0;
                        while (Qin == 0)
                        {
                            while (1)
                            {
                                printf("           |--> Is this year in A.D(Anno Domini)?\n");
                                printf("A.D.:%d ?\n(Y/N):", Ye);
                                char re123456789[14];

                                scanf(" %c", &Bud_ADom);
                                gets(re123456789);
                                if (re123456789[0] == '\0')
                                    break;
                                else
                                    printf("Please do it correctly, I beg you, my dear.\n");

                            }

                            Qin = (tolower(Bud_ADom) == 'y' || tolower(Bud_ADom) == 'n' ? 1 : 0);
                            if (tolower(Bud_ADom) == 'n' && Qin == 1)
                            {
                                Ye = convertToAD(Ye);
                                printf("A.D.(Anno Domini):%d\n", Ye);
                            }
                            else if (tolower(Bud_ADom) == 'y' && Qin == 1)
                            {
                                printf("A.D.(Anno Domini):%d\n", Ye);
                            }
                        }
                    }
                }
                sprintf(Kung_Fu, "%d/%d/%d", Da, Mo, Ye);
                printf("%s\n", Kung_Fu);
                strcpy(record->date, Kung_Fu);
                // scanf("%10s", record->date);
            }
            else
            {
                printf("Incorrect option\n");
                Quay = 1;
            }
        }
    } while (Quay == 1); // do 606
}

void edit_data(char user[50])
{
    system("cls");
    printf("Edit your recorded data\n");
    FoodRecord data[MAX_RECORDS];
    int count;
    char fileName[50];
    strcpy(fileName, user);
    strcat(fileName, "_dietary_information");
    // อ่านข้อมูลจากไฟล์
    count = readFile(data, fileName, user);
    if (count == 0)
    {
        printf("There is no data in the file.\n Record your calories first.\n");
        edit_data_calculate_calories(user);
    }
    else
    {
        // แสดงข้อมูลทั้งหมด
        displayData(data, count);

        // ให้ผู้ใช้เลือกแก้ไข
        int recordIndex;
        int Emperor;
        do
        {
            Emperor = 0;
            while (1)
            {
                printf("\nEnter the item number you want to edit.(choose In. 1-%d): ", count);
                int result25;
                char hurry[14];
                scanf("%d", &recordIndex);
                gets(hurry);

                if (hurry[0] == '\0')
                    break;
                else
                    printf("Please do it correctly, I beg you, my dear.\n");
            }

            if (recordIndex < 1 || recordIndex > count)
            {
                printf("Item number is invalid.\n");
                Emperor = 1;
            }
        } while (Emperor == 1);

        // แก้ไขข้อมูล
        editRecord(&data[recordIndex - 1], &data[recordIndex - 1], &data[recordIndex - 1]);

        // บันทึกข้อมูลกลับไปที่ไฟล์
        writeFile(data, count, fileName, user);
        system("cls");
        printf("Data has been edited successfully.\n");
        char I_want_to_Sleep[10];
        int Puvit_Sleep_at_6_am;
        do
        {
            Puvit_Sleep_at_6_am = 0;
            printf("Will you continue to make corrections? (1.Yes/2.No)\n(1 or 2):");
            int result26;
            result26 = scanf("%s", I_want_to_Sleep);
            if (result26 != 1)
            {

                printf("Invalid input! Please enter an integer.\n");

                while (getchar() != '\n')
                    ;
            }
            if (strcmp(I_want_to_Sleep, "1") == 0)
            {
                Puvit_Sleep_at_6_am = 1;
                system("cls");
                edit_data(user);
            }
            else if (strcmp(I_want_to_Sleep, "2") == 0)
            {
                Puvit_Sleep_at_6_am = 1;
                system("cls");
                edit_data_calculate_calories(user);
            } // ไปhomepage
        } while (Puvit_Sleep_at_6_am == 0);
    }
}

void edit_data_calculate_calories(char user[50])
{
    int Prot, Car, Fat, Fit, Fi, Cal, Mo, Da, Ye, T1, T2, io;
    char Ans[10];
    printf("What do you want to ...? \n 1.Record or calculate calories from format recorded [ 1.calories(Kcal) or 2.nutrients(gram) ] \n 2.edit your recorded data \n 3.back to the selectfunction page \n**Your answer is 1,2 or 3** \n :");
    gets(Ans);
    io = 0;
    if (strcmp(Ans, "1") == 0)
    {
        calculate_calories(user);
    }
    else if (strcmp(Ans, "2") == 0)
    {

        edit_data(user);
    }
    else if (strcmp(Ans, "3") == 0)
    {

        system("cls");
        select_function(user); // อย่าลืมเชื่อมไปหน้าแรก main();
    }
    else
    {
        printf("That is not correct.");
        system("cls");
        edit_data_calculate_calories(user); // อย่าลืมเชื่อมไปหน้าแรก main();
    }
}
// end function3
// function4
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
        while (i < 76)
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
        while (i < 31)
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
void flush_input()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ; // Clear input buffer
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
    int matcher, counter = 0;

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
    if (Dia.state == 1)
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
    for (i = 0; i < 31; i++)
        food7[i].max_cal = food7[i].min_cal + 100;
    for (i = 0; i < 76; i++)
        food[i].max_cal = food[i].min_cal + 100;

    int h, j;
    system("cls");
    printf("---recommended food in MLC---");
    printf("\n\n");
    matcher = 0;
    for (i = 0; i < 76; i++)
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
        {
            matcher += 1; // Output the valid food
            printf("%-30s ", food[i].name);
            printf(" min = %d , max = %d\n", food[i].min_cal, food[i].max_cal);
        }
    }
    if (matcher == 0)
    {
        printf("No match food\n");
        counter += 1;
    }
    printf("---recommended food in 7-11---");
    printf("\n\n");
    matcher = 0;
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
            matcher += 1;
            printf(" min = %d , max = %d\n", food7[i].min_cal, food7[i].max_cal);
        }
    }
    if (matcher == 0)
    {
        printf("No match food\n");
        counter += 1;
    }
    char k;
    if (counter == 2)
    {
        system("cls");
        printf("****************************************************\n");
        printf("*   \033[1;31mNo matching food found in this area!\033[0m           *\n");
        printf("*   \033[1;31mBut don't worry, you can create your own\033[0m       *\n");
        printf("*   \033[1;31mdelicious meals and calculate calories using\033[0m   *\n");
        printf("*   \033[1;31mFunction 2.\033[0m                                    *\n");
        printf("****************************************************\n");
    }

    printf("      \033[0;36m Tap anything Back to select function page\033[0m\n");
}

void collectResponses(char responses[], const char *diseases[], int count, int *p)
{
    int i;
    char input[30];
    char ui;
    char response;

    printf("\n");
    printf("-----Answer the following questions with 'y' (yes) or 'n' (no)-----\n");
    printf("-----         Please recheck your ans before submitting       -----\n");
    printf("-----                Understand? Type soneting                -----\n");
    getchar();
    flush_input();

    printf("\033[A\033[2K");
    for (i = 0; i < count; i++)
    {
        int valid = 0;

        while (!valid)
        {
            printf("%d.) Do you have %s? (y/n): ", i + 1, diseases[i]);

            if (fgets(input, sizeof(input), stdin) == NULL)
            {
                printf("\033[1;31mError reading input. Please try again.\033[0m\n");
                continue;
            }

            input[strcspn(input, "\n")] = '\0';

            if (strlen(input) != 1)
            {
                printf("\033[1;31mInvalid input. Please enter 'y' or 'n'.\033[0m\n");
                continue;
            }

            response = tolower(input[0]);
            if (response == 'y' || response == 'n')
            {
                responses[i] = response;        // Store response
                *p = (response == 'y') ? 1 : 0; // Update result
                valid = 1;                      // Mark as valid and exit the loop
            }
            else
            {
                printf("\033[1;31mInvalid input. Please enter 'y' or 'n'.\033[0m\n");
            }
        }
        p++; // Move to the next result
    }
}

int confirmAction()
{
    char response[10]; // Buffer to handle excessive input

    do
    {
        printf("\n");
        printf("-----Do you want to confirm these responses?-----\n(y/n): ");

        if (fgets(response, sizeof(response), stdin) == NULL)
        {
            printf("Error reading input. Please try again.\n");
            continue;
        }

        response[strcspn(response, "\n")] = '\0';

        if (strlen(response) != 1)
        {
            printf("\033[1;31mInvalid input. Please enter 'y' or 'n'.\033[0m\n");
            continue;
        }

        response[0] = tolower(response[0]);

        if (response[0] == 'y')
        {
            return 1;
        }
        else if (response[0] == 'n')
        {
            printf("Restarting...\n");
            system("cls");

            return 0;
        }
        else
        {
            printf("\033[1;31mInvalid input. Please enter 'y' or 'n'.\033[0m\n");
        }
    } while (1);
}
void displaySummary(const char responses[], const char *diseases[], int count)
{
    printf("\n-----Summary of Responses-----\n");
    for (int i = 0; i < count; i++)
    {
        printf("%s: \033[1;33m%s\033[0m\n", diseases[i], (responses[i] == 'y' ? "Yes" : "No"));
    }
}
// end function4

int showdatatous(char n[50])
{
    FoodRecord data[MAX_RECORDS];
    char filename[50];
    int num;
    strcpy(filename, n);
    strcat(filename, "_dietary_information");
    num = readFile(data, filename, n);
    displayData(data, num);
    printf("Tap any botton to go select function page\n");
    getch();
    system("cls");
    select_function(n);
}
// function 5
int function5(char u[50])
{
    FILE *dietaryinfo;
    char nus[50];
    strcpy(nus, u);
    strcat(nus, "_dietary_information");
    dietaryinfo = fopen(nus, "r");
    char choice[100];
    int v = 0;
    while (1)
    {
        system("cls");
        if (!dietaryinfo)
        {
            char es[10];
            while (1)
            {
                system("cls");
                printf("Error opening file\n");
                printf("pls enter data first\n");
                printf("--------------------\n");
                printf("1.select fuction\n");
                printf("2.enter data\n");
                printf("--------------------\n");
                printf("select: ");
                fflush(stdin);
                gets(es);
                if (strcmp(es, "1") == 0)
                {
                    system("cls");
                    v = 1;
                    select_function(u);
                }
                else if (strcmp(es, "2") == 0)
                {
                    system("cls");
                    v = 1;
                    edit_data_calculate_calories(u);
                }
                else
                    printf("pls select one in choice\n");
                if (v == 1)
                    break;
            }
        }
        else
        {
            int found;
            found = finddate(dietaryinfo);
            if (found == 1)
            {
                drawgraph(dietaryinfo);
            }
            while (1)
            {
                printf("Would you like another graph? (Y/N) : ");
                fflush(stdin);
                scanf("%s", choice);
                if (strcmp(choice, "y") == 0 || strcmp(choice, "Y") == 0)
                    break;
                if (strcmp(choice, "N") == 0 || strcmp(choice, "n") == 0)
                    break;
                if (strcmp(choice, "y") != 0 && strcmp(choice, "Y") != 0 && strcmp(choice, "N") != 0 && strcmp(choice, "n") != 0)
                    continue;
            }
            if (strcmp(choice, "y") == 0 || strcmp(choice, "Y") == 0)
                continue;
            if (strcmp(choice, "n") == 0 || strcmp(choice, "N") == 0)
            {
                v = 1;
                system("cls");
                select_function(u);
            }
            fclose(dietaryinfo);
        }
        if (v == 1)
            break;
    }
}

int finddate(FILE *dietaryinfo)
{
    printf("Input date (dd/mm/yyyy): ");
    scanf("%s", inputdate);
    rewind(dietaryinfo);
    char line[256], date[15];
    int found = 0;
    while (fgets(line, 256, dietaryinfo))
    {
        sscanf(line, "%*s %*s %*d %*d %*d %*d %s %*d", date);
        if (strcmp(date, inputdate) == 0)
        {
            found = 1;
            break;
        }
    }
    if (found == 0)
        printf("No match found. Please try again.\n");
    return found;
}
void drawgraph(FILE *dietaryinfo)
{
    system("cls");
    int day, month, year;
    sscanf(inputdate, "%d/%d/%d", &day, &month, &year);
    int i, j, bars[7] = {0};
    rewind(dietaryinfo);
    char line[256], date[15];
    int calories, meal_day, meal_month, meal_year;
    
    while (fgets(line, 256, dietaryinfo))
    {
        if (sscanf(line, "%*s %*s %*d %*d %*d %*d %s %d", date, &calories) == 2)
        {
            sscanf(date, "%d/%d/%d", &meal_day, &meal_month, &meal_year);
            int start_day_of_week = 1 + ((day - 1) / 7) * 7;
            int end_day_of_week = start_day_of_week + 6;
            if (meal_month == month && meal_year == year &&meal_day >= start_day_of_week && meal_day <= end_day_of_week )
            {   
                int week_index = (meal_day-1) % 7;
                bars[week_index] += calories;
            }
            
        }
    }
    for (i = 0; i < 30; i++)
        printf(" ");
    printf("%s %d\n  kcal\n    |\n", monthname[month - 1], year);
    for (i = 30; i > 0; i--)
    {
        if (i % 5 == 0)
        {
            printf("%4d+    ", i * 100);
            for (j = 0; j < 7; j++)
            {
                if (bars[j] >= i * 100)
                {
                    BGgreen();
                    green();
                    printf("####");
                    BGreset();
                    black();
                    printf("####");
                    reset();
                }
                else
                    printf("        ");
            }
            printf("\n");
        }
        else if (i % 5 != 0 && i != 1)
        {
            printf("    |    ");
            for (j = 0; j < 7; j++)
            {
                if (bars[j] >= i * 100)
                {
                    BGgreen();
                    green();
                    printf("####");
                    BGreset();
                    black();
                    printf("####");
                    ;
                    reset();
                }
                else
                    printf("        ");
            }
            printf("\n");
        }
        else
        {
            printf("    |    ");
            for (j = 0; j < 7; j++)
            {
                if (bars[j] >= i * 100)
                {
                    BGgreen();
                    black();
                    printf("%4d", bars[j]);
                    BGreset();
                    black();
                    printf("####");
                    reset();
                }
                else
                    printf("        ");
            }
            printf("\n");
        }
    }
    printf("   0-------------------------------------------------------------day\n     ");
    if (day <= 7)
    {
        for (i = 0; i < 7; i++)
            printf("%8d", i + 1);
    }
    if (day > 7 && day <= 14)
    {
        for (i = 0; i < 7; i++)
            printf("%8d", i + 8);
    }
    if (day > 14 && day <= 21)
    {
        for (i = 0; i < 7; i++)
            printf("%8d", i + 15);
    }
    if (day > 21 && day <= 28)
    {
        for (i = 0; i < 7; i++)
            printf("%8d", i + 22);
    }
    if (day > 28)
    {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            for (i = 0; i < 3; i++)
                printf("%8d", i + 29);
        if (month == 4 || month == 6 || month == 9 || month == 11)
            for (i = 0; i < 2; i++)
                printf("%8d", i + 29);
        if (month == 2 && (year % 4) == 0)
            printf("%8d", 29);
    }
    printf("\n");
}

void black()
{
    printf("\x1b[30m");
}

void green()
{
    printf("\x1b[32m");
}

void reset()
{
    printf("\033[0m");
}

void BGgreen()
{
    printf("\x1b[42m");
}

void BGreset()
{
    printf("\x1b[40m");
}
