#include<stdio.h>
#include <stdlib.h>
#include <string.h>
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
void calculate_calories();
int readFile(FoodRecord data[], const char *fileName) ;
void writeFile(FoodRecord data[], int count, const char *fileName);
void writeFile(FoodRecord data[], int count, const char *fileName);
void displayData(FoodRecord data[], int count);
void editRecord(FoodRecord *record);
void edit_data();
void edit_data_calculate_calories();


 void calculate_calories()
{    
    int Prot,Car,Fat,Fit,Fi,Cal,Mo,Da,Ye,T1,T2,REC,LOUIS,Crown,knowncal,date_mont_correct,Time_correct ;
    char MN[20];
    system("cls");
    printf("Record and calculate calories from nutrients(gram)\n");
    printf("Meal's name/ Manu (English Only and Don't have space) :");
    scanf("%s",MN);
    date_mont_correct=0;
    Time_correct=0;
    do{ 
        if(date_mont_correct==0){
    printf("Date/Mont/Year(eg. 01/02/2024) :");
    scanf("%d/%d/%d",&Da,&Mo,&Ye);date_mont_correct=1;}
    else if(date_mont_correct==1){printf("   Date/Mont/year is incorrect.\nTry again.\n");
    printf("Date/Mont/Year(eg. 01/02/2024) :");
    scanf("%d/%d/%d",&Da,&Mo,&Ye);}}while(Da<=0||Da>=32||Mo<=0||Mo>=13);
    
    do{
        if(Time_correct==0){printf("Time (eg. 15:24) >>"); //ให้พิมพ์เองเพราะจะได้ระบุเวลาตามความต้องการของผู้ใช้ เช่น กินตั้งแต่เที่ยงแต่จะมาพิมพ์ตอนเวลาบ่ายเป็นต้น
    scanf("%d:%d",&T1,&T2);Time_correct=1;}
    else if(Time_correct==1){printf("   Time is incorrect.\nTry again.\n");
    printf("Time (eg. 15:24) >>"); //ให้พิมพ์เองเพราะจะได้ระบุเวลาตามความต้องการของผู้ใช้ เช่น กินตั้งแต่เที่ยงแต่จะมาพิมพ์ตอนเวลาบ่ายเป็นต้น
    scanf("%d:%d",&T1,&T2);Time_correct=1;}}while(T1<0||T1>=24||T2<0||T2>=60);
    
    printf("%02d/%02d/%d\n",Da,Mo,Ye); 
    printf("%02d:%02d \n",T1,T2);
    do{system("cls");
    printf("Do you know the calories? \n If you know, you will type 1 ,but if you don't know, you will type 0.\n ,Or if you want to back, you will type 3\n :");
    scanf("%d",&knowncal);
    if(knowncal==1)
    { system("cls");
    Crown=1;
    printf("Meal's name/ Menu = %s\n",MN);
    printf("%02d/%02d/%d\n",Da,Mo,Ye); 
    printf("%02d:%02d \n",T1,T2);
    printf("You know your meal's calories.\n");
    printf("Please, enter your meal's calories.\n");
    scanf("%d",&Cal);
    printf("*****|| Calories in this meal is %d kilocalories ||***** \n",Cal);
    Prot=0;Car=0;Fat=0;Fi=0;
    }
    else if(knowncal==0)
    { system("cls");
    Crown=1;
    printf("Meal's name/ Menu = %s\n",MN);
    printf("%02d/%02d/%d\n",Da,Mo,Ye); 
    printf("%02d:%02d \n",T1,T2);
    printf("You want to calculate your meal's calories.\n");
    printf("Please, enter the number of grams of protein, carbohydrate, fat and dietary fiber.\n");
    printf("Protein(gram) :");
    scanf("%d",&Prot); 
    printf("Carbohydrate(gram) :");
    scanf("%d",&Car); 
    printf("Fat(gram) :");
    scanf("%d",&Fat); 
    printf("Dietary fiber(gram) :");
    scanf("%d",&Fi); 
    printf("Protein = %d g,Carbohydrate = %d g, Fat = %d g, Dietary fiber = %d g\n",Prot,Car,Fat,Fi);
    Cal=Prot*4+Car*4+Fat*9+Fi*0;
    printf("*****|| Calories in this meal is %d kilocalories ||***** \n",Cal);} 
    else if(knowncal==3)
    { system("cls");printf("Already back\n");
    Crown=1;calculate_calories();}
    else if(knowncal!=0 && knowncal!=1&&knowncal!=3)
    {   system("cls");
        printf("incorrect");
    Crown=0;

    ;}}while(Crown==0);
    
    do{
    printf("Do you want to record this calories? \n If you want to do, you will type 1 ,but if you don't want to record, you will type 0.\n ,Or if you want to back to the homepage and don't record this data, you will type 3\n :");
    scanf("%d",&REC);
    if(REC==1)
    {   char filename[] = "User_dietary_information1.txt";
        
        FILE *CLR = fopen(filename,"a+");
        LOUIS=1; printf("You want to record this data.\n"); 
        fprintf(CLR,"%s ",MN);
        fprintf(CLR, "%02d:%02d ", T1,T2);
        fprintf(CLR, "%d ",Prot );
        fprintf(CLR, "%d ",Car );
        fprintf(CLR, "%d ",Fat );
        fprintf(CLR, "%d\n",Fi );
        fprintf(CLR, "%02d/%02d/%d\n", Da,Mo,Ye);//อาร์มดึงไปใช้
        fprintf(CLR, "%d\n",Cal );//อาร์มดึงไปใช้
        
        fclose(CLR);
        system("cls");
        printf("Write data to file %s complete.\n",filename);
        printf("Go to the homepage.");
        main(); // อย่าลืมเชื่อมไปหน้ารวมฟังก์ชั่น;
    }
    else if(REC==3)
    {   system("cls");
        printf("You want to back to the homepage.\n");
        printf("Go to the homepage.");
        main(); // อย่าลืมเชื่อมไปหน้ารวมฟังก์ชั่น;
    }
    else if(REC==0)
    {   system("cls");
        LOUIS=1;
        printf("You don't want to record this data.\n");
        printf("And you want to calculate calories again.\n");
        calculate_calories();
        
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
int readFile(FoodRecord data[], const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Unable to open file. Record your calories first.\n");
        edit_data_calculate_calories();
        
    }
    
    int count = 0;
    while (count < MAX_RECORDS && 
           fscanf(file, "%s %s %d %d %d %d %s %d", 
                  data[count].foodName, data[count].time, 
                  &data[count].protein, &data[count].carbs, 
                  &data[count].fat, &data[count].fiber, 
                  data[count].date, &data[count].calories) == 8) {
        count++;
    }
    fclose(file);
    return count;
}

// ฟังก์ชันสำหรับเขียนข้อมูลกลับไปยังไฟล์
void writeFile(FoodRecord data[], int count, const char *fileName) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Unable to write file\n BACK TO THE HOMEPAGE\n");
        main();//เชื่อมไปhomepage
        
    }
    
    for (int i = 0; i < count; i++) {
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
        printf("Item number %d:\n", i + 1);
        printf("Menu/meal: %s, Time: %s\n", data[i].foodName, data[i].time);
        printf("Protein: %d g, Carbohydrate: %d g, Fat: %d g,Dietary fiber : %d g\n", 
               data[i].protein, data[i].carbs, data[i].fat, data[i].fiber);
        printf("Date: %s, Calories: %d\n", data[i].date, data[i].calories);
        printf("----------------------------------\n");
    }
}

// ฟังก์ชันสำหรับแก้ไขข้อมูล
void editRecord(FoodRecord *record) {
    int Quay;
    do
    {
    int choice; Quay=0;
    printf("\nSelect the information you want to edit.:\n");
    printf("1. Menu/meal\n");
    printf("2. Time\n");
    printf("3. Protein\n");
    printf("4. Carbohydrate\n");
    printf("5. Fat\n");
    printf("6. Dietary fiber\n");
    printf("7. Date\n");
    printf("8. Calories\n");
    printf("Your options: ");
    scanf("%d", &choice);
    getchar(); // อ่าน newline เพื่อป้องกันปัญหา
    
    switch (choice) {
        case 1:
            printf("New food name: ");
            scanf("%49s", record->foodName);
            break;
        case 2:
            printf("New time (15:24): ");
            scanf("%9s", record->time);
            break;
        case 3:
            printf("New proteins (g): ");
            scanf("%d", &record->protein);
            break;
        case 4:
            printf("New carbohydrates (g): ");
            scanf("%d", &record->carbs);
            break;
        case 5:
            printf("New fat (g): ");
            scanf("%d", &record->fat);
            break;
        case 6:
            printf("New dietary fiber (g): ");
            scanf("%d", &record->fiber);
            break;
        case 7:
            printf("New Date (dd/mm/yyyy): ");
            scanf("%10s", record->date);
            break;
        case 8:
            printf("New Calories: ");
            scanf("%d", &record->calories);
            break;
        default:
          {  printf("Incorrect option\n"); Quay=1; }
    }}while(Quay==1);
}

void edit_data()
{   
    system("cls");
    printf("Edit your recorded data\n");
    FoodRecord data[MAX_RECORDS];
    int count;
    const char *fileName = "User_dietary_information1.txt";
    
    // อ่านข้อมูลจากไฟล์
    count = readFile(data, fileName);
    if (count == 0) {
        printf("There is no data in the file.\n Record your calories first.\n");
        edit_data_calculate_calories();
        
    }
    
    // แสดงข้อมูลทั้งหมด
    displayData(data, count);
    
    // ให้ผู้ใช้เลือกแก้ไข
    int recordIndex;
    int Emperor;
    do{ Emperor=0;
    printf("\nEnter the item number you want to edit.(1-%d): ", count);
    scanf("%d", &recordIndex);
    if (recordIndex < 1 || recordIndex > count) {
        printf("Item number is invalid.\n");
        Emperor=1;
    }
    }while(Emperor==1);
    // แก้ไขข้อมูล
    editRecord(&data[recordIndex - 1]);
    
    // บันทึกข้อมูลกลับไปที่ไฟล์
    writeFile(data, count, fileName);
    
    printf("Data has been edited successfully.\n" );
    int I_want_to_Sleep;
    int Puvit_Sleep_at_6_am;
    do{ Puvit_Sleep_at_6_am=0;
    printf("Will you continue to make corrections? (1.Yes/2.No)\n(1 or 2):");
    scanf("%d",&I_want_to_Sleep);
    if(I_want_to_Sleep==1)
    { Puvit_Sleep_at_6_am=1;edit_data();}
    else if(I_want_to_Sleep==2)
    {Puvit_Sleep_at_6_am=1; main();}//ไปhomepage
    }while(Puvit_Sleep_at_6_am==0);
  
    
}
//ยังไม่เสร็จจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจ****************************************************************************************************************



void edit_data_calculate_calories()
{
    int Prot,Car,Fat,Fit,Fi,Cal,Mo,Da,Ye,T1,T2,Ans;
    printf("What do you want to ...? \n 1.record and calculate calories from nutrients(gram) \n 2.edit your recorded data \n 3.back to the homepage \n**Your answer is 1,2 or 3** \n :");
    scanf("%d",&Ans);
    switch (Ans)
    {
    case (1):
        calculate_calories();
        break;
    case (2):
        edit_data();
        break;
    case (3):
        system("cls");
        main(); // อย่าลืมเชื่อมไปหน้าแรก main();
        break;
    default: { printf("That is not correct.");system("cls"); main(); // อย่าลืมเชื่อมไปหน้าแรก main();
    }
}}

void main() //ตอนไปรวมกับเพื่อนให้ลบออก main() หลัก จะได้เป็นหน้าแรก
{   system("cls");
    printf("\n ***\\ START TO LOUIS PART /***\n");

    edit_data_calculate_calories();
}