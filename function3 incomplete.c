#include<stdio.h>



 void calculate_calories()
{    
    int Prot,Car,Fat,Fit,Fi,Cal,Mo,Da,Ye,T1,T2,REC,LOUIS,Crown,knowncal ;
    char MN[20];
    system("cls");
    printf("Record and calculate calories from nutrients(gram)\n");
    printf("Meal's name/ Manu (English Only and Don't have space) :");
    scanf("%s",MN);
    printf("Date/Mont/Year(eg. 01/02/2024) :");
    scanf("%d/%d/%d",&Da,&Mo,&Ye);
    printf("Time (eg. 15:24) >>"); //ให้พิมพ์เองเพราะจะได้ระบุเวลาตามความต้องการของผู้ใช้ เช่น กินตั้งแต่เที่ยงแต่จะมาพิมพ์ตอนเวลาบ่ายเป็นต้น
    scanf("%d:%d",&T1,&T2);
    printf("%02d/%02d/%d\n",Da,Mo,Ye); 
    printf("%02d:%02d \n",T1,T2);
    do{system("cls");
    printf("Do you know the calories? \n If you know, you will type 1 ,but if you don't know, you will type 0.\n ,Or if you want to back, you will type 3\n :");
    scanf("%d",&knowncal);
    if(knowncal==1)
    { system("cls");
    Crown=1;
    printf("Meal's name/ Manu = %s\n",MN);
    printf("%02d/%02d/%d\n",Da,Mo,Ye); 
    printf("%02d:%02d \n",T1,T2);
    printf("You know your meal's calories.\n");
    printf("Please, enter your meal's calories.\n");
    scanf("%d",&Cal);
    printf("*****|| Calories in this meal is %d kilocalories ||***** \n",Cal);}
    else if(knowncal==0)
    { system("cls");
    Crown=1;
    printf("Meal's name/ Manu = %s\n",MN);
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
    else 
    {   system("cls");
        printf("incorrect");
    Crown=0;

    ;}}while(Crown==0);
    
    do{
    printf("Do you want to record this calories? \n If you want to do, you will type 1 ,but if you don't want to record, you will type 0.\n ,Or if you want to back to the first page and don't record this data, you will type 3\n :");
    scanf("%d",&REC);
    if(REC==1)
    {   char filename[] = "User_dietary_information1.txt";
        
        FILE *CLR = fopen(filename,"a+");
        LOUIS=1; printf("You want to record this data.\n"); 
        fprintf(CLR,"Meal's name/ Manu = %s ",MN);
        fprintf(CLR, "|Time = %02d:%02d ", T1,T2);
        fprintf(CLR, "|Protein = %d g ",Prot );
        fprintf(CLR, "|Carbohydrate = %d g ",Car );
        fprintf(CLR, "|Fat = %d g ",Fat );
        fprintf(CLR, "|Dietary fiber = %d g \n",Fi );
        fprintf(CLR, "%02d/%02d/%d\n ", Da,Mo,Ye);//อาร์มดึงไปใช้
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

void edit_data()
{   
    system("cls");
    printf("Edit your recorded data");
//ยังไม่เสร็จจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจ****************************************************************************************************************
}


void edit_data_calculate_calories()
{
    int Prot,Car,Fat,Fit,Fi,Cal,Mo,Da,Ye,T1,T2,Ans;
    printf("What do you want to ...? \n 1.record and calculate calories from nutrients(gram) \n 2.edit your recorded data \n 3.back to the first page \n**Your answer is 1,2 or 3** \n :");
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
{
    printf("\n ***\\ START TO LOUIS PART /***\n");
    edit_data_calculate_calories();
}
