#include <stdio.h>
#include <stdlib.h>

struct mlc {
 char name[20];
 int min_cal;
 int max_cal;
};

struct mlc food[50];

void readFile() {
 FILE *fp;

 fp = fopen("mlcfoodlist.txt", "r");
 printf("%p\n", fp);
 printf("%d\n", fp);
 if (fp == NULL) {
  printf("file not found\n");exit(0);
 }
 else{
 int i = 0;
 while (i < 50) {
        int h;
       h = fscanf(fp, "%25[^,],%d,%d\n", food[i].name, &food[i].min_cal, &food[i].max_cal);
        if (h == 3) {
            
            i++;
        } else {
            
            break;
        }
    }
 }

 fclose(fp);
}

void printFoodData(int count) {
 for (int i = 0; i < count; i++) {
  printf("Food Name: %s\n", food[i].name);
  printf("Min Calories: %d\n", food[i].min_cal);
  printf("Max Calories: %d\n\n", food[i].max_cal);
 }
}

int main() {
 readFile();//เก็บค่าที่อ่านจากไฟล์
 printf("Stored Food Data:\n\n");
 printFoodData(50);

 return 0;
}
