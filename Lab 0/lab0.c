#include <stdio.h>
//#define _CRT_SECURE_NO_WARNINGS
//#include 
// Omar Mosaad Atalla Abdellatif Diab [20p3176]
#include "function.c"
int global_Local=10;

extern int counter;

void Task1(){
    int global_Local=5;
}

void Task5(int grade){
    printf("your grade is: ");
if (grade<=100 && grade>=93){
    printf("A");
}else if(grade>=85){
printf("B+");
}else if(grade>=75){
    printf("B");
}else if(grade>=70){
    printf("C+");
}else if(grade>=61){
    printf("C");
}else if(grade>=60){
    printf("D");
}else{
    printf("F");
}



}
int main(){

    // Task 1
    printf("%d \n", global_Local); // prints 10 (global)
    // Task 2
    function();
    function();
    function();
    function();
    printf("counter = %d\n", counter);

    // Task 3
    int a=5;
    printf("initially a = %d\n",a);
    printf("a++ = %d\n",a++);
    printf("a-- = %d\n",a--);
    printf("++a = %d\n",++a);
    printf("--a = %d\n",--a);

    // Task 4
    int rows=0;
    printf("enter number of rows:");
    printf("\n");
    scanf_s("%d",&rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    //Task 5
    int Grade;
    printf("enter ur grade in (cap): \n");
    scanf_s("%d",&Grade);
    Task5(Grade);
    
    return 0;

}