#include<stdio.h>
#include<string.h>
typedef struct{
    char name[50];
    char telephone[20];
    char email[100];
}Info;

void swap(Info *a, Info *b)
{
    Info t = *a;
    *a = *b;
    *b = t;
}

void read_file(char *file_name,Info *tmp,int *amount){
    FILE *fp = fopen(file_name,"r");
    if(fp == NULL){
        printf("File not found \n");
    }
    else{
        fscanf(fp,"%d",amount);
        for(int i = 0 ; i < *amount ; i++){
            fscanf(fp,"%s",tmp[i].name);
            fscanf(fp,"%s",tmp[i].telephone);
            fscanf(fp,"%s",tmp[i].email);

        }
    }
}

int partition (Info arr[], int low, int high)
{
    Info pivot = arr[high]; 
    int left = low;
    int right = high - 1;
    while(1==1){
        while(left <= right && strcmp(arr[left].name , pivot.name)<0) left++;
        while(right >= left && strcmp(arr[right].name , pivot.name)>0) right--;
        if (left >= right) break;
        swap(&arr[left], &arr[right]);
        left++;
        right--;
    }
    swap(&arr[left], &arr[high]);
    return left;
}
 
void quickSort(Info arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
int main()
{   int amount = 0;
    Info arr[100];

    read_file("input.txt",arr,&amount);
    quickSort(arr, 0, amount - 1);
    printf("Sorted array: \n");
    for(int i = 0 ; i < amount ; i++){
        printf("%s \n %s \n %s \n",arr[i].name, arr[i].telephone, arr[i].email);
    }
    return 0;
}