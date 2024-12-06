#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#define MAX_RECORDS 100
#define MAX_LINE_LENGTH 256
typedef struct {
    char foodName[50];
    char time[10];
    int protein;
    int carbs;
    int fat;
    int fiber;
    char date[11];
    int calories;
} FoodRecord;
void calculate_calories(char user[50]);
int readFile(FoodRecord data[], const char *fileName,char user[50]) ;
void writeFile(FoodRecord data[], int count, const char *fileName,char user[50]);
void displayData(FoodRecord data[], int count);
void editRecord(FoodRecord *record,FoodRecord *Real,FoodRecord *data);
void edit_data(char user[50]);
void edit_data_calculate_calories(char user[50]);
void replaceSpacesWithUnderscore(char str[]);
void replaceUnderscoreWithSpace(char str[]);
int isLeapYear(int year);
int isValidDate(int day, int month, int year);
int convertToAD(int year);
//int getNumericInputWithComma();
//void convertToLowercase(char *str);
//void getValidDate(int *day, int *month, int *year);


// ฟังก์ชันเปลี่ยนเว้นวรรคเป็น "_"
void replaceSpacesWithUnderscore(char str[]) { int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {  // ถ้าเจอเว้นวรรค
            str[i] = '_';      // แทนที่ด้วย _
        }
    }
}

// ฟังก์ชันเปลี่ยน "_" เป็นเว้นวรรค
void replaceUnderscoreWithSpace(char str[]) { int i;
    for ( i = 0; str[i] != '\0'; i++) {
        if (str[i] == '_') {  // ถ้าเจอ _
            str[i] = ' ';      // แทนที่ด้วยเว้นวรรค
        }
    }
}

// ตรวจว่าใช่ปีที่มีอธิกสุรทินหรือไม่ คืนค่า เป็น 1 กับ 0
int isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12 || day < 1) {
        return 0; // ไม่ถูกต้อง
    }
    
    int daysInMonth[] = {31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (day > daysInMonth[month - 1]) {
        return 0; // ไม่ถูกต้อง
    }
    
    return 1; // ถูกต้อง
}

// แปลงปีจาก พ.ศ. เป็น ค.ศ.
int convertToAD(int year) {
    return (year - 543); // แปลงจาก พ.ศ. เป็น ค.ศ.
}

// รับค่าตัวเลขที่มีลูกน้ำคั่นหลัก
/*int getNumericInputWithComma() {
    char input[200],output[200];
    char *ptr;
    int num;
    while (1) {
        printf("Enter value: ");
        fgets(input, sizeof(input), stdin);
        
        int j = 0;
    
    
    for (int i = 0; input[i] != '\0'; i++) {
        
        if (input[i] != ',') {
            output[j++] = input[i];
        }
    }
    
    output[j] = '\0';
        
        // ตรวจสอบว่าเป็นตัวเลขหรือไม่
        num = strtol(output[], &ptr, 10);
        if (*ptr == '\0') { 
            return num;
            break;
        } else {
            printf("Invalid input! Please enter a number.\n");
        }
    } 
 }*/

/*
void convertToLowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
} */

// รับค่าวันที่
/*void getValidDate(int *day, int *month, int *year) {
    char input[15];
    int valid = 0;
    while (!valid) {
        
        
        // ตรวจสอบรูปแบบวัน/เดือน/ปี
        if (sscanf(input, "%d/%d/%d", day, month, year) != 3 ) {
            printf("Invalid date format! Please use dd/mm/yyyy or yyyy-mm-dd.\n");
        } else {
            // ถ้าเป็น พ.ศ. ให้แปลงเป็น ค.ศ.
            if (*year > 543) {
                *year = convertToAD(*year);
            }
            // ตรวจสอบความถูกต้องของวันที่
            valid = isValidDate(*day, *month, *year);
            if (!valid) {
                printf("Invalid date! Please enter a valid date.\n");
            }
        }
    }
}*/






 void calculate_calories(char user[50])
{    
    int Qin,Neg,A,Prot,Car,Fat,Fit,Fi,Cal,Mo,Da,Ye,T1,T2,REC,LOUIS,Crown,knowncal,date_mont_correct,Time_correct,result1,result2,result3,result4,result5,result6,result7,result8,result9 ;
    char MN[20];
char Bud_ADom;
    system("cls");
    printf("Record or calculate calories from format recorded 1.calories(Kcal) or 2.nutrients(gram)\n");
    printf("Meal's name/ Menu (English Only ) :");
    fflush(stdin);
    gets(MN);
    date_mont_correct=0;
    Time_correct=0;
    do{ 
        if(date_mont_correct==0){ 
            A=0;
            while(A==0){
                A=1;
                printf("Date/Mont/Year(eg. 01/02/2024)\n ( **1. It is a real date according to the calendar.)\n ( **2. It is not a word or letter.)\n ( **3. Please check carefully whether it is B.E.(Buddhist Era) or A.D.(Anno Domini).(We can estimate roughly.))\n :");
                result4 = scanf("%d/%d/%d",&Da,&Mo,&Ye);  
                if (result4 != 3) { 
                    A=0; // หากไม่ได้รับค่าจำนวนเต็ม 3 ค่า
                    printf("Invalid input! Please enter three integers separated by slashes.\n");
        
                    // เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                    while (getchar() != '\n');  // ข้ามจนกว่าจะถึงบรรทัดใหม่
                }
            }
            date_mont_correct=1; 
        }
        else if(date_mont_correct==1){
            A=0;
            while(A==0){
                A=1; 
                printf("   Date/Mont/year is incorrect.\n ( **1. It is a real date according to the calendar.) \n ( **2. It is not a word or letter.) \n ( **3. Please check carefully whether it is B.E.(Buddhist Era) or A.D.(Anno Domini).(We can estimate roughly.)) \n !! Try again.\n");
                printf("Date/Mont/Year(eg. 01/02/2024) :");
                result3 = scanf("%d/%d/%d",&Da,&Mo,&Ye); 
                if (result3 != 3) { 
                    A=0;  // หากไม่ได้รับค่าจำนวนเต็ม 3 ค่า
                    printf("Invalid input! Please enter three integers separated by slashes.\n");
        
                    // เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                    while (getchar() != '\n');  // ข้ามจนกว่าจะถึงบรรทัดใหม่
                }
            }
        }/*เดาคร่าวๆ ว่าเป็น พ.ศ. หรือ คศ.โดยเทียบกับปี2500*/
    
        if((Ye>543&&Ye>2099)&&A!=0){
        
        fflush(stdin); Qin=0;
        while(Qin==0) { printf("           |--> Is this year in B.E.(Buddhist Era)?\n");
            printf("B.E.:%d ?\n (Y/N):",Ye); 
            scanf(" %c", &Bud_ADom); getchar(); 
            Qin=(tolower(Bud_ADom)=='y'||tolower(Bud_ADom)=='n' ? 1:0); 
            if(tolower(Bud_ADom)=='y'&&Qin==1){Ye=convertToAD(Ye);
                printf("A.D(Anno Domini):%d\n",Ye);} 
            else if(tolower(Bud_ADom)=='n'&&Qin==1){printf("A.D(Anno Domini):%d\n",Ye);}}
        }else if((Ye<=2099||Ye<543)&&A!=0){
        
            fflush(stdin); Qin=0;
            while(Qin==0) {
                printf("           |--> Is this year in A.D(Anno Domini)?\n");
                printf("A.D.:%d ?\n(Y/N):",Ye);
                scanf(" %c", &Bud_ADom); getchar();
                Qin=(tolower(Bud_ADom)=='y'||tolower(Bud_ADom)=='n' ? 1:0); 
                if(tolower(Bud_ADom)=='n'&&Qin==1){
                    Ye=convertToAD(Ye);
                    printf("A.D.(Anno Domini):%d\n",Ye);
                } 
                else if(tolower(Bud_ADom)=='y'&&Qin==1){
                    printf("A.D.(Anno Domini):%d\n",Ye);
                }
            }
        }
    }while(isValidDate(Da,Mo,Ye)==0); /*Da<=0||Da>=32||Mo<=0||Mo>=13||*/
    
    do{
        if(Time_correct==0){
            A=0;
            while(A==0){
                A=1;
                printf("Time (eg. 15:24) >>"); //ให้พิมพ์เองเพราะจะได้ระบุเวลาตามความต้องการของผู้ใช้ เช่น กินตั้งแต่เที่ยงแต่จะมาพิมพ์ตอนเวลาบ่ายเป็นต้น
                result2 = scanf("%d:%d",&T1,&T2);
                Time_correct=1; 
                if (result2 != 2) { 
                    A=0; // หากไม่ได้รับค่าจำนวนเต็ม 2 ค่า
                    printf("Invalid input! Please enter two integers separated by colon.\n");
        
        // เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                    while (getchar() != '\n'); // ข้ามจนกว่าจะถึงบรรทัดใหม่
                }
            }
        }
        else if(Time_correct==1){
            A=0;
            while(A==0){
                A=1;
                printf("   Time is incorrect.\nTry again.\n");
                printf("Time (eg. 15:24) >>"); //ให้พิมพ์เองเพราะจะได้ระบุเวลาตามความต้องการของผู้ใช้ เช่น กินตั้งแต่เที่ยงแต่จะมาพิมพ์ตอนเวลาบ่ายเป็นต้น
                result1 = scanf("%d:%d",&T1,&T2);
                Time_correct=1; 
                if (result1 != 2) { 
                    A=0; // หากไม่ได้รับค่าจำนวนเต็ม 2 ค่า
                    printf("Invalid input! Please enter two integers separated by colon.\n");
        
        // เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                    while (getchar() != '\n');  // ข้ามจนกว่าจะถึงบรรทัดใหม่
                }
            } 
        }
    }while(T1<0||T1>=24||T2<0||T2>=60); // อ่าน newline เพื่อป้องกันปัญหา
    
    printf("%02d/%02d/%d\n",Da,Mo,Ye); 
    printf("%02d:%02d \n",T1,T2);
    do{
        system("cls");
        printf("Do you know the calories? \n If you know, you will type 1 (Format Recorded 1) ,but if you don't know, you will type 0.(Format Recorded 2)\n ,Or if you want to back, you will type 3\n :");
        scanf("%d",&knowncal); getchar(); // อ่าน newline เพื่อป้องกันปัญหา
        if(knowncal==1){ 
            system("cls");
            Crown=1;
            printf("Meal's name/ Menu = %s\n",MN);
            printf("%02d/%02d/%d\n",Da,Mo,Ye); 
            printf("%02d:%02d \n",T1,T2);
            printf("You know your meal's calories.(Format Recorded 1)\n");A=0;
            while(A==0){
                A=1; 
                Neg=0;
                do{ 
                    if(Neg==1){
                        printf("Please, enter Positive Integer.\n");
                    }
                    printf("Please, enter your meal's calories(Kcal).\n:");
    /*Cal=getNumericInputWithComma();*/
                    result9=scanf("%d",&Cal);  
                    if (result9 != 1) {
                        A=0;  // ถ้าไม่สามารถอ่านได้ 1 ค่า (ตัวเลข)
                        printf("Invalid input! Please enter an integer.\n");
        
                        while(getchar() != '\n');  // ข้ามข้อมูลที่เหลืออยู่ในบัฟเฟอร์
                    }
                    Neg=1;
                }while(Cal<0);
            }
            printf("*****|| Calories in this meal is %d kilocalories ||***** \n",Cal);
            Prot=0;Car=0;Fat=0;Fi=0;
        }
        else if(knowncal==0){ 
            system("cls");
            Crown=1;
            printf("Meal's name/ Menu = %s\n",MN);
            printf("%02d/%02d/%d\n",Da,Mo,Ye); 
            printf("%02d:%02d \n",T1,T2);
            printf("You want to calculate your meal's calories.(Format Recorded 2)\n");
            printf("Please, enter the number of grams of protein, carbohydrate, fat and dietary fiber.\n");
            A=0;
            while(A==0){
                A=1;
                Neg=0;
                do{ 
                    if(Neg==1){
                        printf("Please, enter Positive Integer.\n");
                    }
                    printf("Protein(gram) :");
                    result5=scanf("%d",&Prot);
                    if (result5 != 1) {
                        A=0;  // ถ้าไม่สามารถอ่านได้ 1 ค่า (ตัวเลข)
                        printf("Invalid input! Please enter an integer.\n");
        
                        while (getchar() != '\n');  // ข้ามข้อมูลที่เหลืออยู่ในบัฟเฟอร์
                    }
                    Neg=1;
                }while(Prot<0);
            } 
            A=0;
            while(A==0){
                A=1;
                Neg=0;
                do{ 
                    if(Neg==1){
                        printf("Please, enter Positive Integer.\n");
                    }
                    printf("Carbohydrate(gram) :");
                    result6=scanf("%d",&Car);
                    if (result6 != 1) {
                         A=0; // ถ้าไม่สามารถอ่านได้ 1 ค่า (ตัวเลข)
                        printf("Invalid input! Please enter an integer.\n");
        
                        while (getchar() != '\n');   // ข้ามข้อมูลที่เหลืออยู่ในบัฟเฟอร์
                    }
                    Neg=1;
                }while(Car<0);
            } 
            A=0;
            while(A==0){
                A=1; 
                Neg=0;
                do{ 
                    if(Neg==1){
                        printf("Please, enter Positive Integer.\n");
                    }
                    printf("Fat(gram) :");
                    result7=scanf("%d",&Fat);
                    if (result7 != 1) {
                        A=0; // ถ้าไม่สามารถอ่านได้ 1 ค่า (ตัวเลข)
                        printf("Invalid input! Please enter an integer.\n");
        
                        while (getchar() != '\n');  // ข้ามข้อมูลที่เหลืออยู่ในบัฟเฟอร์
                    }
                    Neg=1;
                }while(Fat<0);
            } A=0;
            while(A==0){
                A=1;
                Neg=0;
                do{ 
                    if(Neg==1){
                        printf("Please, enter Positive Integer.\n");
                    }printf("Dietary fiber(gram) :");
                    result8=scanf("%d",&Fi);
                    if (result8 != 1) { 
                        A=0; // ถ้าไม่สามารถอ่านได้ 1 ค่า (ตัวเลข)
                        printf("Invalid input! Please enter an integer.\n");
        
                        while (getchar() != '\n');  // ข้ามข้อมูลที่เหลืออยู่ในบัฟเฟอร์
                    }
                    Neg=1;
                }while(Fi<0);
            }
            printf("Protein = %d g,Carbohydrate = %d g, Fat = %d g, Dietary fiber = %d g\n",Prot,Car,Fat,Fi);
            Cal=Prot*4+Car*4+Fat*9+Fi*0;
            printf("*****|| Calories in this meal is %d kilocalories ||***** \n",Cal);} 
            else if(knowncal==3){ 
                system("cls");printf("Already back\n");
                Crown=1;
                calculate_calories(user);
            }
            else if(knowncal!=0 && knowncal!=1&&knowncal!=3){
                system("cls");
                printf("incorrect");
                Crown=0;

            }
    }while(Crown==0);
    
    do{
    printf("Do you want to record this calories? \n If you want to do, you will type 1 ,but if you don't want to record, you will type 0.\n ,Or if you want to back to the homepage and don't record this data, you will type 3\n :");
    scanf("%d",&REC); getchar(); // อ่าน newline เพื่อป้องกันปัญหา
    if(REC==1)
    {   char filename[] = "User_dietary_information1.txt";
        
        FILE *CLR = fopen(filename,"a+");
        LOUIS=1; printf("You want to record this data.\n");
        replaceSpacesWithUnderscore(MN); 
        fprintf(CLR,"%s ",MN);
        fprintf(CLR, "%02d:%02d ", T1,T2);
        fprintf(CLR, "%d ",Prot );
        fprintf(CLR, "%d ",Car );
        fprintf(CLR, "%d ",Fat );
        fprintf(CLR, "%d ",Fi );
        fprintf(CLR, "%02d/%02d/%d ", Da,Mo,Ye);
        fprintf(CLR, "%d\n",Cal );
        
        fclose(CLR);
        system("cls");
        printf("Write data to file %s complete.\n",filename);
        printf("Go to the homepage.");
        main(user); // อย่าลืมเชื่อมไปหน้ารวมฟังก์ชั่น;
    }
    else if(REC==3)
    {   system("cls");
        printf("You want to back to the homepage.\n");
        printf("Go to the homepage.");
        main(user); // อย่าลืมเชื่อมไปหน้ารวมฟังก์ชั่น;
    }
    else if(REC==0)
    {   system("cls");
        LOUIS=1;
        printf("You don't want to record this data.\n");
        printf("And you want to calculate calories again.\n");
        calculate_calories(user);
        
    }
    else if(REC!=0 && REC!=1&&REC!=3)
    {   
        system("cls");
        LOUIS=0;
        printf("You are incorrect.\n You must type again.\n");
        
    }
    }while(LOUIS==0);
    

}

// ฟังก์ชันสำหรับอ่านข้อมูลจากไฟล์
int readFile(FoodRecord data[], const char *fileName,char user[50]) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("/*/*/Unable to open file.\\*\\*\\ \n***Record your calories first.***\n");
        edit_data_calculate_calories(user);
        
    }
    
    int count = 0;
    while (count < MAX_RECORDS && 
           fscanf(file, "%s %s %d %d %d %d %s %d", 
                  data[count].foodName, data[count].time, 
                  &data[count].protein, &data[count].carbs, 
                  &data[count].fat, &data[count].fiber, 
                  data[count].date, &data[count].calories) == 8) { replaceUnderscoreWithSpace(data[count].foodName);
        count++;
    }
    fclose(file);
    return count;
}

// ฟังก์ชันสำหรับเขียนข้อมูลกลับไปยังไฟล์
void writeFile(FoodRecord data[], int count, const char *fileName,char user[50]) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Unable to write file\n BACK TO THE HOMEPAGE\n");
        main(user);//เชื่อมไปhomepage
        
    }
    
    for (int i = 0; i < count; i++) { replaceSpacesWithUnderscore(data[i].foodName);
        fprintf(file, "%s %s %d %d %d %d %s %d\n", 
                data[i].foodName, data[i].time, 
                data[i].protein, data[i].carbs, 
                data[i].fat, data[i].fiber, 
                data[i].date, data[i].calories);
    }
    fclose(file);
}

// ฟังก์ชันสำหรับแสดงข้อมูลทั้งหมด
void displayData(FoodRecord data[], int count) {
    printf("\nYour data:\n");
    
    for (int i = 0; i < count; i++) {
        if(data[i].protein==0&&data[i].carbs==0&&data[i].fat==0&&data[i].fiber==0&&data[i].calories!=0)
        { 
            replaceUnderscoreWithSpace(data[i].foodName);
            printf("\nItem number(In.) %d:\n", i + 1);
            printf("***|Format-Recorded(FR.) : 1.\n   |-> You recorded your calories by entering the calories you knew\n, and you didn't enter grams of protein, carbohydrates, fat, dietary fiber.***\n\n");
            printf("Menu/meal: %s,\nTime: %s\n", data[i].foodName, data[i].time);
            printf("Date: %s,\nCalories: %d\n\n", data[i].date, data[i].calories);
            printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< FR. 1 >>>>>>>>>>>>>>>> (*^_^*) <<<<<<<<<<<<<<<< In. %d >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n",i+1);
        }
        else { replaceUnderscoreWithSpace(data[i].foodName);
            printf("\nItem number(In.) %d:\n", i + 1);
            printf("***|Format-Recorded(FR.) : 2.\n   |-> You recorded your calories by entering grams of protein, carbohydrates, fat, and dietary fiber\n, and then used the values you entered to calculate the calories.***\n\n");
            printf("Menu/meal: %s, \nTime: %s\n",data[i].foodName, data[i].time);
            printf("Protein: %d g, \nCarbohydrate: %d g, \nFat: %d g,\nDietary fiber : %d g\n", 
                data[i].protein, data[i].carbs, data[i].fat, data[i].fiber);
            printf("Date: %s, \nCalories: %d\n\n", data[i].date, data[i].calories);
            printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< FR. 2 >>>>>>>>>>>>>>>> (*^o^*) <<<<<<<<<<<<<<<< In. %d >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n",i+1);
        }
    }
}

// ฟังก์ชันสำหรับแก้ไขข้อมูล
void editRecord(FoodRecord *record,FoodRecord *Real,FoodRecord *data) {
    int Qin,Neg,Neg1,Quay,Mi_Bazi,i,n,date_mont_correct,Da=0,Mo=0,Ye=0,T1=0,T2=0,Time_correct,result,result1,B;
    char Kung_Fu[100];
    char Bud_ADom;
    do
    {
    int choice; Quay=0;
    if(data->protein==0&&data->carbs==0&&data->fat==0&&data->fiber==0&&data->calories!=0){
    printf("\nSelect the information you want to edit.(Choose Number ONLY!):\n");
    printf("1. Name of Menu/meal\n");
    printf("2. Time\n");
    printf("3. Date\n");
    printf("4. Calories\n");
    printf("Your options: ");}
    else { printf("\nSelect the information you want to edit.(Choose Number ONLY!):\n");
    printf("1. Name of Menu/meal\n");
    printf("2. Time\n");
    printf("3. Protein\n");
    printf("4. Carbohydrate\n");
    printf("5. Fat\n");
    printf("6. Dietary fiber\n");
    printf("7. Date\n");
    
    printf("Your options: ");}
    scanf("%d", &choice);
    getchar(); // อ่าน newline เพื่อป้องกันปัญหา
    if(data->protein==0&&data->carbs==0&&data->fat==0&&data->fiber==0&&data->calories!=0)
    {switch (choice) {
        case 1:
            printf("New food name: ");
            fflush(stdin);
            gets(record->foodName);
            replaceSpacesWithUnderscore(record->foodName);
            break;
        case 2: B=0;
            while(B==0){
                B=1;
                printf("New time (15:24): ");
                Time_correct=0;
                if(Time_correct==0){
                    result=scanf("%d:%d",&T1,&T2);
                    if(result!=2){
                        B=0; 
                        printf("Invalid input! Please enter two integers separated by a colon.\n"); 
                        while(getchar()!='\n');
                    }
                Time_correct=1;
                }
            }
            while(T1<0||T1>=24||T2<0||T2>=60){
                if(Time_correct==1){
                    printf("   Time is incorrect.\nTry again.\n");
                    B=0;
                    while(B==0){
                        B=1;
                        printf("Time (eg. 15:24) >>"); //ให้พิมพ์เองเพราะจะได้ระบุเวลาตามความต้องการของผู้ใช้ เช่น กินตั้งแต่เที่ยงแต่จะมาพิมพ์ตอนเวลาบ่ายเป็นต้น
                        result1=scanf("%d:%d",&T1,&T2);
                        Time_correct=1; 
                        if (result1 != 2) { 
                            B=0; // หากไม่ได้รับค่าจำนวนเต็ม 2 ค่า
                            printf("Invalid input! Please enter two integers separated by a colon.\n");
                            
        // เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                            while (getchar() != '\n');  // ข้ามจนกว่าจะถึงบรรทัดใหม่
                        } 
                    }
                }
                else if(Time_correct==0){}
            }
            sprintf(Kung_Fu,"%d:%d",T1,T2);
            printf("%s\n",Kung_Fu);
            strcpy(record->time,Kung_Fu);
            //scanf("%9s", record->time);
            /*if(Time_correct==0){printf("Time (eg. 15:24) >>"); //ให้พิมพ์เองเพราะจะได้ระบุเวลาตามความต้องการของผู้ใช้ เช่น กินตั้งแต่เที่ยงแต่จะมาพิมพ์ตอนเวลาบ่ายเป็นต้น
    scanf("%d:%d",&T1,&T2);Time_correct=1;}
    else if(Time_correct==1){printf("   Time is incorrect.\nTry again.\n");
    printf("Time (eg. 15:24) >>"); //ให้พิมพ์เองเพราะจะได้ระบุเวลาตามความต้องการของผู้ใช้ เช่น กินตั้งแต่เที่ยงแต่จะมาพิมพ์ตอนเวลาบ่ายเป็นต้น
    scanf("%d:%d",&T1,&T2);Time_correct=1;}}while(T1<0||T1>=24||T2<0||T2>=60);*/            
            break;
        case 3: B=0;
                while(B==0){
                    B=1;
                    printf("New Date (dd/mm/yyyy)\n ( **1. It is a real date according to the calendar.)\n ( **2. It is not a word or letter.)\n ( **3. Please check carefully whether it is B.E.(Buddhist Era) or A.D.(Anno Domini).(We can estimate roughly.))\n : ");
                    date_mont_correct=0;
                    if(date_mont_correct==0){
                        result = scanf("%d/%d/%d",&Da,&Mo,&Ye); 
                        if(result!=3){ 
                            B=0; 
                            printf("Invalid input! Please enter three integers seperated by slashes.\n ");
                            while(getchar() != '\n');
                            }
                        }
                    date_mont_correct=1;
                    if((Ye>543&&Ye>2099)&&B!=0){
                        
                        fflush(stdin); 
                        Qin=0;
                        while(Qin==0) { 
                            printf("           |--> Is this year in B.E.(Buddhist Era)?\n");
                            printf("B.E.:%d ?\n(Y/N):",Ye); 
                            scanf(" %c", &Bud_ADom); getchar(); 
                            Qin=(tolower(Bud_ADom)=='y'||tolower(Bud_ADom)=='n' ? 1:0); 
                            if(tolower(Bud_ADom)=='y'&&Qin==1){
                                Ye=convertToAD(Ye);
                                printf("A.D(Anno Domini):%d\n",Ye);
                            }                                   
                            else if(tolower(Bud_ADom)=='n'&&Qin==1){ printf("A.D(Anno Domini):%d\n",Ye); }
                        }
                    } else if((Ye<=2099||Ye<543)&&B!=0){
                        fflush(stdin); Qin=0;
                        while(Qin==0) {
                            printf("           |--> Is this year in A.D(Anno Domini)?\n");
                            printf("A.D.:%d ?\n(Y/N):",Ye);
                            scanf(" %c", &Bud_ADom); getchar(); 
                            Qin=(tolower(Bud_ADom)=='y'||tolower(Bud_ADom)=='n' ? 1:0); 
                            if(tolower(Bud_ADom)=='n'&&Qin==1){Ye=convertToAD(Ye);
                                printf("A.D.(Anno Domini):%d\n",Ye);
                            } 
                            else if(tolower(Bud_ADom)=='y'&&Qin==1){printf("A.D.(Anno Domini):%d\n",Ye);}
                        }
                    }
                }
    while(isValidDate(Da,Mo,Ye)==0){
        if(date_mont_correct==1){
            printf("   Date/Mont/year is incorrect!!!.\n ( **1. It is a real date according to the calendar.)\n ( **2. It is not a word or letter.)\n ( **3. Please check carefully whether it is B.E.(Buddhist Era) or A.D.(Anno Domini).(We can estimate roughly.))\n !!!Try again.\n");
            B=0; 
            while(B==0){
                B=1;
                printf("Date/Mont/Year(eg. 01/02/2024)\n ( **1. It is a real date according to the calendar.)\n ( **2. It is not a word or letter.)\n ( **3. Please check carefully whether it is B.E.(Buddhist Era) or A.D.(Anno Domini).(We can estimate roughly.))\n :");
                result1=scanf("%d/%d/%d",&Da,&Mo,&Ye); 
                if (result1 != 3) { 
                    B=0;// หากไม่ได้รับค่าจำนวนเต็ม 3 ค่า
                    printf("Invalid input! Please enter three integers separated by slashes.\n");
                    
                    //  เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                    while (getchar() != '\n');  // ข้ามจนกว่าจะถึงบรรทัดใหม่
                } 
            }
        }
        else if(date_mont_correct==0){}
        if((Ye>543&&Ye>2099)&&B!=0){
                        
                        fflush(stdin); 
                        Qin=0;
                        while(Qin==0) { 
                            printf("           |--> Is this year in B.E.(Buddhist Era)?\n");
                            printf("B.E.:%d ?\n(Y/N):",Ye);
                            scanf(" %c", &Bud_ADom); getchar(); 
                             
                            Qin=(tolower(Bud_ADom)=='y'||tolower(Bud_ADom)=='n' ? 1:0); 
                            if(tolower(Bud_ADom)=='y'&&Qin==1){
                                Ye=convertToAD(Ye);
                                printf("A.D(Anno Domini):%d\n",Ye);
                            }                                   
                            else if(tolower(Bud_ADom)=='n'&&Qin==1){ printf("A.D(Anno Domini):%d\n",Ye); }
                        }
        } 
        else if((Ye<=2099||Ye<543)&&B!=0){
                        fflush(stdin); Qin=0;
                        while(Qin==0) {
                            printf("           |--> Is this year in A.D(Anno Domini)?\n");
                            printf("A.D.:%d?\n(Y/N):",Ye);
                            scanf(" %c", &Bud_ADom); getchar(); 
                             
                            Qin=(tolower(Bud_ADom)=='y'||tolower(Bud_ADom)=='n' ? 1:0); 
                            if(tolower(Bud_ADom)=='n'&&Qin==1){Ye=convertToAD(Ye);
                                printf("A.D.(Anno Domini):%d\n",Ye);
                            } 
                            else if(tolower(Bud_ADom)=='y'&&Qin==1){printf("A.D.(Anno Domini):%d\n",Ye);}
                        }
        }
    }
            sprintf(Kung_Fu,"%d/%d/%d",Da,Mo,Ye);
            printf("%s\n",Kung_Fu);
            strcpy(record->date,Kung_Fu);
            /*fflush(stdin);
            gets(record->date);
            n=strlen(record->date);*/
            break;
        case 4:B=0;
        while(B==0){  
            B=1;         
            Neg=0;
            do{ 
                if(Neg==1){
                    printf("Please, enter Positive Integer.\n");
                }
                printf("New Calories: ");
                result1=scanf("%d", &record->calories);
                if (result1 != 1) {  B=0;// หากไม่ได้รับค่าจำนวนเต็ม 3 ค่า
                    printf("Invalid input! Please enter an integer\n");
                    
                    //  เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                    while (getchar() != '\n');  // ข้ามจนกว่าจะถึงบรรทัดใหม่
                }
                Neg=1;
            }while(record->calories<0);
            } 
            break;
        default:
          {  printf("Incorrect option\n"); Quay=1; }
    }}
    else {switch (choice) {
        case 1: 
            printf("New food name: ");
            fflush(stdin);
            gets(record->foodName);
            replaceSpacesWithUnderscore(record->foodName);
            break;
        case 2:B=0;
            while(B==0){
                B=1;
                printf("New time (15:24): ");
                Time_correct=0;
                if(Time_correct==0){
                    result = scanf("%d:%d",&T1,&T2); 
                    if (result != 2) {
                        B=0; // หากไม่ได้รับค่าจำนวนเต็ม 2 ค่า
                        printf("Invalid input! Please enter two integers separated by a colon.\n");
                        
                        //  เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                        while (getchar() != '\n'); // ข้ามจนกว่าจะถึงบรรทัดใหม่
                        
                    } 
                    Time_correct=1;
                }
            }
            while(T1<0||T1>=24||T2<0||T2>=60){
                if(Time_correct==1){
                    printf("   Time is incorrect.\nTry again.\n");
                    B=0;
                    while(B==0){
                        B=1;
                        printf("Time (eg. 15:24) >>"); //ให้พิมพ์เองเพราะจะได้ระบุเวลาตามความต้องการของผู้ใช้ เช่น กินตั้งแต่เที่ยงแต่จะมาพิมพ์ตอนเวลาบ่ายเป็นต้น
                        result1 = scanf("%d:%d",&T1,&T2);
                        if (result1 != 2) { 
                            B=0; // หากไม่ได้รับค่าจำนวนเต็ม 2 ค่า
                            printf("Invalid input! Please enter two integers separated by a colon.\n");
                            
                            // เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                            while (getchar() != '\n');  // ข้ามจนกว่าจะถึงบรรทัดใหม่
                            
                        } Time_correct=1;
                    }
                }
                else if(Time_correct==0){}
            }
            sprintf(Kung_Fu,"%d:%d",T1,T2);
            printf("%s\n",Kung_Fu);
            strcpy(record->time,Kung_Fu);
            //scanf("%9s", record->time);
            break;
        case 3: B=0;
            while(B==0){
                B=1;
                record->protein;
                Mi_Bazi=record->protein;
                Neg=0;
                do{ 
                    if(Neg==1){
                        printf("Please, enter Positive Integer.\n");
                    }
                    printf("New proteins (g): ");
                    
                    result1=scanf("%d", &record->protein); 
                    if (result1 != 1) { 
                        B=0; // หากไม่ได้รับค่าจำนวนเต็ม 2 ค่า
                        printf("Invalid input! Please enter an integer.\n");
                        
                        // เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                        while (getchar() != '\n');  // ข้ามจนกว่าจะถึงบรรทัดใหม่
                    }
                    Neg=1;
                }while(record->protein<0);
            } 
            Real->calories;
            Real->calories = Real->calories-4*Mi_Bazi+4*record->protein;
            printf("\nThis is the new calories: %d Kcal\n",Real->calories);
            break;
        case 4: B=0;
            while(B==0){
                B=1;
                record->carbs;
                Mi_Bazi=record->carbs;
                Neg=0;
                do{ 
                    if(Neg==1){
                        printf("Please, enter Positive Integer.\n");
                    } 
                    printf("New carbohydrates (g): ");
                    
                    result1=scanf("%d", &record->carbs); 
                    if (result1 != 1) { 
                        B=0; // หากไม่ได้รับค่าจำนวนเต็ม 2 ค่า
                        printf("Invalid input! Please enter an integer.\n");
                        
                        // เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                        while (getchar() != '\n');  // ข้ามจนกว่าจะถึงบรรทัดใหม่
                        
                    }
                    Neg=1;
                }while(record->carbs<0);
            } // อ่าน newline เพื่อป้องกันปัญหา
            Real->calories;
            Real->calories = Real->calories-4*Mi_Bazi+4*record->carbs;
            printf("\nThis is the new calories: %d Kcal\n",Real->calories);
            break;
        case 5:B=0;
            while(B==0){
                B=1;
                record->fat;
                Mi_Bazi=record->fat;
                Neg=0;
                do{ 
                    if(Neg==1){
                        printf("Please, enter Positive Integer.\n");
                    } 
                    printf("New fat (g): ");
                    
                    result1=scanf("%d", &record->fat); 
                    if (result1 != 1) { 
                        B=0; // หากไม่ได้รับค่าจำนวนเต็ม 2 ค่า
                        printf("Invalid input! Please enter an integer.\n");
                        
                        // เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                        while (getchar() != '\n');  // ข้ามจนกว่าจะถึงบรรทัดใหม่
                    }
                    Neg=1;
                }while(record->fat<0);
            } // อ่าน newline เพื่อป้องกันปัญหา
            Real->calories;
            Real->calories = Real->calories-9*Mi_Bazi+9*record->fat;
            printf("\nThis is the new calories: %d Kcal\n",Real->calories);
            
            break;
        case 6:B=0;
            while(B==0){
                B=1;
                record->fiber;
                Mi_Bazi=record->fiber;
                Neg=0;
                do{ 
                    if(Neg==1){
                        printf("Please, enter Positive Integer.\n");
                    }
                    printf("New dietary fiber (g): ");
                    result1=scanf("%d", &record->fiber);
                    if (result1 != 1) { 
                        B=0; // หากไม่ได้รับค่าจำนวนเต็ม 2 ค่า
                        printf("Invalid input! Please enter an integer.\n");
                    
        // เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                        while (getchar() != '\n');  // ข้ามจนกว่าจะถึงบรรทัดใหม่
                    }
                    Neg=1;
                }while(record->fiber<0);
            }// อ่าน newline เพื่อป้องกันปัญหา
            Real->calories;
            Real->calories = Real->calories-0*Mi_Bazi+0*record->fiber;
            printf("\nThis is the new calories: %d Kcal\n",Real->calories);
            break;
        case 7:B=0;
            while(B==0){
                B=1;
                printf("New Date (dd/mm/yyyy)\n ( **1. It is a real date according to the calendar.)\n ( **2. It is not a word or letter.)\n ( **3. Please check carefully whether it is B.E.(Buddhist Era) or A.D.(Anno Domini).(We can estimate roughly.))\n : ");
                date_mont_correct=0;
                if(date_mont_correct==0){
                    result = scanf("%d/%d/%d",&Da,&Mo,&Ye); 
                    if (result != 3) { 
                        B=0; // หากไม่ได้รับค่าจำนวนเต็ม 3 ค่า
                        printf("Invalid input! Please enter three integers separated by slashes.\n");
        
        // เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                        while (getchar() != '\n'); 
                    } // ข้ามจนกว่าจะถึงบรรทัดใหม่
                    date_mont_correct=1;
                }
                if((Ye>543&&Ye>2099)&&B!=0){
                        
                        fflush(stdin); 
                        Qin=0;
                        while(Qin==0) { 
                            printf("           |--> Is this year in B.E.(Buddhist Era)?\n");
                            printf("B.E.:%d ?\n(Y/N):",Ye);
                            scanf(" %c", &Bud_ADom); getchar(); 
                             
                            Qin=(tolower(Bud_ADom)=='y'||tolower(Bud_ADom)=='n' ? 1:0); 
                            if(tolower(Bud_ADom)=='y'&&Qin==1){
                                Ye=convertToAD(Ye);
                                printf("A.D(Anno Domini):%d\n",Ye);
                            }                                   
                            else if(tolower(Bud_ADom)=='n'&&Qin==1){ printf("A.D(Anno Domini):%d\n",Ye); }
                        }
                    } else if((Ye<=2099||Ye<543)&&B!=0){
                        fflush(stdin); Qin=0;
                        while(Qin==0) {
                            printf("           |--> Is this year in A.D(Anno Domini)?\n");
                            printf("A.D.:%d ?\n(Y/N):",Ye);
                            scanf(" %c", &Bud_ADom); getchar(); 
                             
                            Qin=(tolower(Bud_ADom)=='y'||tolower(Bud_ADom)=='n' ? 1:0); 
                            if(tolower(Bud_ADom)=='n'&&Qin==1){Ye=convertToAD(Ye);
                                printf("A.D.(Anno Domini):%d\n",Ye);
                            } 
                            else if(tolower(Bud_ADom)=='y'&&Qin==1){printf("A.D.(Anno Domini):%d\n",Ye);}
                        }
                    }
            }
            while(isValidDate(Da,Mo,Ye)==0){
                if(date_mont_correct==1){
                    printf("   Date/Mont/year is incorrect!!!.\n ( **1. It is a real date according to the calendar.)\n ( **2. It is not a word or letter.)\n ( **3. Please check carefully whether it is B.E.(Buddhist Era) or A.D.(Anno Domini).(We can estimate roughly.))\n !!!Try again.\n");
                    B=0;
                    while(B==0){
                        B=1;
                        printf("Date/Mont/Year(eg. 01/02/2024)\n ( **1. It is a real date according to the calendar.)\n ( **2. It is not a word or letter.)\n ( **3. Please check carefully whether it is B.E.(Buddhist Era) or A.D.(Anno Domini).(We can estimate roughly.))\n  :");
                        result1 = scanf("%d/%d/%d",&Da,&Mo,&Ye);
                        if (result1 != 3) { 
                            B=0; // หากไม่ได้รับค่าจำนวนเต็ม 3 ค่า
                            printf("Invalid input! Please enter three integers separated by slashes.\n");
        
        //  เพื่อข้ามข้อมูลที่เหลือจากการป้อนผิด
                            while (getchar() != '\n');  // ข้ามจนกว่าจะถึงบรรทัดใหม่
                        }
                    }
                }
                else if(date_mont_correct==0){}
                if((Ye>543&&Ye>2099)&&B!=0){
                        
                        fflush(stdin); 
                        Qin=0;
                        while(Qin==0) { 
                            printf("           |--> Is this year in B.E.(Buddhist Era)?\n");
                            printf("B.E.:%d ?\n(Y/N):",Ye);
                            scanf(" %c", &Bud_ADom); getchar(); 
                             
                            Qin=(tolower(Bud_ADom)=='y'||tolower(Bud_ADom)=='n' ? 1:0); 
                            if(tolower(Bud_ADom)=='y'&&Qin==1){
                                Ye=convertToAD(Ye);
                                printf("A.D(Anno Domini):%d\n",Ye);
                            }                                   
                            else if(tolower(Bud_ADom)=='n'&&Qin==1){ printf("A.D(Anno Domini):%d\n",Ye); }
                        }
                } 
                else if((Ye<=2099||Ye<543)&&B!=0){
                        fflush(stdin); Qin=0;
                        while(Qin==0) {
                            printf("           |--> Is this year in A.D(Anno Domini)?\n");
                            printf("A.D.:%d ?\n(Y/N):",Ye); 
                            scanf(" %c", &Bud_ADom); getchar(); 
                            
                            Qin=(tolower(Bud_ADom)=='y'||tolower(Bud_ADom)=='n' ? 1:0); 
                            if(tolower(Bud_ADom)=='n'&&Qin==1){Ye=convertToAD(Ye);
                                printf("A.D.(Anno Domini):%d\n",Ye);
                            } 
                            else if(tolower(Bud_ADom)=='y'&&Qin==1){printf("A.D.(Anno Domini):%d\n",Ye);}
                        }
                }
            }
            sprintf(Kung_Fu,"%d/%d/%d",Da,Mo,Ye);
            printf("%s\n",Kung_Fu);
            strcpy(record->date,Kung_Fu);
            //scanf("%10s", record->date);
            break;
        default:
          {  printf("Incorrect option\n"); Quay=1; }
                            }
         }
    }while(Quay==1);
}

void edit_data(char user[50])
{   
    system("cls");
    printf("Edit your recorded data\n");
    FoodRecord data[MAX_RECORDS];
    int count;
    const char *fileName = "User_dietary_information1.txt";
    
    // อ่านข้อมูลจากไฟล์
    count = readFile(data, fileName,user);
    if (count == 0) {
        printf("There is no data in the file.\n Record your calories first.\n");
        edit_data_calculate_calories(user);
        
    }
    
    // แสดงข้อมูลทั้งหมด
    displayData(data, count);
    
    // ให้ผู้ใช้เลือกแก้ไข
    int recordIndex;
    int Emperor;
    do{ Emperor=0;
    printf("\nEnter the item number you want to edit.(choose In. 1-%d): ", count);
    scanf("%d", &recordIndex);
    getchar(); // อ่าน newline เพื่อป้องกันปัญหา
    if (recordIndex < 1 || recordIndex > count) {
        printf("Item number is invalid.\n");
        Emperor=1;
    }
    }while(Emperor==1);
    
    // แก้ไขข้อมูล
    editRecord(&data[recordIndex - 1],&data[recordIndex - 1],&data[recordIndex - 1]);
    
    // บันทึกข้อมูลกลับไปที่ไฟล์
    writeFile(data, count, fileName,user);
    
    printf("Data has been edited successfully.\n" );
    int I_want_to_Sleep;
    int Puvit_Sleep_at_6_am;
    do{ Puvit_Sleep_at_6_am=0;
    printf("Will you continue to make corrections? (1.Yes/2.No)\n(1 or 2):");
    scanf("%d",&I_want_to_Sleep);
    getchar(); // อ่าน newline เพื่อป้องกันปัญหา
    if(I_want_to_Sleep==1)
    { Puvit_Sleep_at_6_am=1;edit_data(user);}
    else if(I_want_to_Sleep==2)
    {Puvit_Sleep_at_6_am=1; main(user);}//ไปhomepage
    }while(Puvit_Sleep_at_6_am==0);
  
    
}




void edit_data_calculate_calories(char user[50])
{
    int Prot,Car,Fat,Fit,Fi,Cal,Mo,Da,Ye,T1,T2,Ans,io;
    printf("What do you want to ...? \n 1.Record or calculate calories from format recorded [ 1.calories(Kcal) or 2.nutrients(gram) ] \n 2.edit your recorded data \n 3.back to the homepage \n**Your answer is 1,2 or 3** \n :");
    scanf("%d",&Ans);
    getchar(); // อ่าน newline เพื่อป้องกันปัญหา
    do{ io=0;
    switch (Ans)
    {
    case (1): io=1;
        calculate_calories(user);
        break;
    case (2): io=1;
        edit_data(user);
        break;
    case (3): io=1;
        system("cls");
        main(user); // อย่าลืมเชื่อมไปหน้าแรก main();
        break;
    default: { io=0;printf("That is not correct.");system("cls"); main(user); // อย่าลืมเชื่อมไปหน้าแรก main();
    }}
}while(io==0); }

void main(char user[50]) //ตอนไปรวมกับเพื่อนให้ลบออก main() หลัก จะได้เป็นหน้าแรก
{   system("cls");
    printf("\n ***\\ START TO LOUIS PART /***\n");

    edit_data_calculate_calories(user);
}
