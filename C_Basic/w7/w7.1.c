#include <stdio.h>
 
int binarySearch(int arr[], int l, int r, int x, int dem) {
    dem = dem + 1;
 
  if (r >= l) {
    int mid = l + (r - l) / 2; 
 
    if (arr[mid] == x){ dem = dem +1;
      return mid;
    }
    if (arr[mid] > x){
        dem = dem +1;
         return binarySearch(arr, l, mid - 1, x, dem);  
    } else{ dem = dem + 1;
    return binarySearch(arr, mid + 1, r, x, dem);
    }

  }
 
  return -1;
}
 
int main(void) {
    int dem = 0;
  int arr[99] ;
  for ( int i = 0; i < 100; i++){
    arr[i] = i + 1;
  }
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 123;
  int result = binarySearch(arr, 0, n - 1, x, dem);
  if (result == -1)
    printf("Not found\n");
  else
    printf("%d xuat hien tai chi so %d, va dem = %d", x, result, dem);
  return 0;
}