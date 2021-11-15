#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int a[10];
    for( int i = 0; i < 10; i ++){
        //printf("Nhap so:\n");
        scanf("%d", &a[i]);
    }
    printf("%d", a[0]);
}