#include <stdio.h>
#include <stdbool.h>
 
#define MAX 10
 
int arr[MAX] = {6, 7, 0, 2, 8, 1, 3, 9, 4, 5};
 
void selectionSort() {
 
    int indexMin, i, j; 
 
    // lap qua ta ca cac so
    for(i = 0; i < MAX-1; i++){ 
        // thiet lap phan tu hien tai la min 
        indexMin = i;
 
        // kiem tra phan tu hien tai co phai la nho nhat khong 
        for(j = i+1; j<MAX; j++){
            if(arr[j] < arr[indexMin]){
                indexMin = j;
            }
        }
 
        if(indexMin != i) {
            //printf("Trao doi phan tu: [ %d, %d ]\n" , arr[i], arr[indexMin]); 
 
            // Trao doi cac so 
            int temp = arr[indexMin];
            arr[indexMin] = arr[i];
            arr[i] = temp;
        }
 
        //printf("Vong lap thu %d#:",(i+1));
        //display();
    }
}
 
void display() {
    int i;
    printf("[");
 
    // Duyet qua tat ca phan tu
    for(i = 0; i < MAX; i++){
        printf("%d ", arr[i]);
    }
 
    printf("]\n");
}
 
main() {
    printf("Mang du lieu dau vao: ");
    display();
    printf("-----------------------------\n");
    selectionSort();
    printf("-----------------------------\n");
    printf("Mang sau khi da sap xep: ");
    display();
}