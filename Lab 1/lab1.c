#include <stdio.h>
// Omar Mosaad Atalla Abdellatif Diab      [20p3176]
// Team [30]

// [on/off Task]
#define Task7

void Task_2(int*arr,int size,int mult_num){
for (int i = 0; i < size; i++)
{
    arr[i]=arr[i]*mult_num;
}
}

void Task3_swap(int*a,int*b){
int temp=*b;
*b=*a;
*a=temp;
}

int Task4_strlength(char*name){
    int length=0;   
while (*name != '\0') {
        length++;
        name++;

    }
    return length;
}

void Task5_concatenation(char* arr1,char* arr2,int size1 , int size2,char* conc){
for (int i = 0; i < size1; i++)
{
    conc[i]=arr1[i];
}
for (int i = 0; i < size2; i++)
{
    conc[size1]=arr2[i];
    size1++;
}}

void Task6_Sorting(int* arr,int size){
for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                Task3_swap(&arr[j],&arr[j+1]);
            }
        }
}}

int Task7_index_Finder(int*arr,int size, int element){
for (int i=0; i<size; i++){
if(element==arr[i]){
    return i;}
    }
return -404;// indicates not found
}

void print_array(int* arr,int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
}


int main(){

    // Task 1
#ifdef Task1
int num1 =10;
int * num1ptr =&num1;
int num2 =5;
int * num2ptr=&num2;
printf("the sume of 2 numbers = %d",*num1ptr+*num2ptr);
#endif

#ifdef Task2
int arr[]={1,2,3,4,5};
int size= sizeof(arr)/sizeof(arr[0]);
printf("before Multiplying:- \n");
print_array(arr,size);
int mult_num=5;             // Multiplying Factor
Task_2(arr,size,mult_num); // multiplying function 
printf("\nAfter multiplying:-\n");
print_array(arr,size);
#endif

#ifdef Task3
int a =5;
int b =10;
Task3_swap(&a,&b);
printf("variables after swapping:-\n");
printf("a = %d , b = %d \n",a,b);
#endif


#ifdef Task4
char arr[10]="Omar";
int Length=Task4_strlength(arr);
printf("The length of your name is %d ", Length);
#endif

#ifdef Task5
char arr1[10]= "Omar ";
char arr2[10]="Mosaad";
char conc[20];
int l_arr1=Task4_strlength(arr1);
int l_arr2=Task4_strlength(arr2);
Task5_concatenation(arr1,arr2,l_arr1,l_arr2,conc);
printf("the concatentaded string is: -\n");

for (int i = 0; i < Task4_strlength(conc); i++)
{
    printf("%c",conc[i]);
}
printf("\n\n");
#endif

#ifdef Task6
int arr[]={6,3,8,2,9,1,0,3};
int size = sizeof(arr)/sizeof(arr[0]);
Task6_Sorting(arr,size);
print_array(arr,size);
#endif

#ifdef Task7
int arr[]={6,3,8,2,9,1,0,4,5,7,10};
int size = sizeof(arr)/sizeof(arr[0]);
int search_element=5;
int index=Task7_index_Finder(arr,size,search_element);
if (index!=404){
    printf("the index of element %d is %d", search_element,index);
}else{
    printf("element is not found!");
}

#endif

return 0;
}