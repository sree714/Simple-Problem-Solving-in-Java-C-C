#include <stdio.h>
#include <stdlib.h>


//Radix sort

int getMax (int a[], int n){
   int max = a[0];
   for (int i = 1; i < n; i++)
      if (a[i] > max)
         max = a[i];
   return max;
}

void radixSort (int a[], int n){
   int bucket[10][10], bucket_cnt[10];
   int i, j, k, r, NOP = 0, divisor = 1, lar, pass;
   lar = getMax (a, n);
   while (lar > 0){
      NOP++;
      lar /= 10;
   }
   for (pass = 0; pass < NOP; pass++){
      for (i = 0; i < 10; i++){
         bucket_cnt[i] = 0;
      }
      for (i = 0; i < n; i++){
         r = (a[i] / divisor) % 10;
         bucket[r][bucket_cnt[r]] = a[i];
         bucket_cnt[r] += 1;
      }
      i = 0;
      for (k = 0; k < 10; k++){
         for (j = 0; j < bucket_cnt[k]; j++){
            a[i] = bucket[k][j];
            i++;
         }
      }
      divisor *= 10;
   }
}
//End radix sort


//Start marge sort

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    i = 0;  
    j = 0; 
    k = l;
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 



void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
       
        int m = l + (r - l) / 2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
//End marge sort


//Start quick sort
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];     
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
       
        if (arr[j] < pivot) 
        { 
            i++;   
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 



void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
  
        int pi = partition(arr, low, high); 
  
        
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
//End quick sort


//print array element
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]);  
} 


int main()
{
	int choice,size,i;
	while(1){
		printf("\n\n1.Quick Sort\n2.Marge Sort\n3.Radix Sort\n4.Exit\n\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		if(choice==4)
			exit(-1);
		else if(choice>4 || choice<1){
		printf("Wrong choice");
		main();
		}
		
		//Array input
		printf("Enter the size of array: ");
		scanf("%d",&size);
		int arr[size];
		
		
		printf("Enter array elements: ");
		for(i=0;i<size;i++)
		{
			scanf("%d",&arr[i]);
		}
		int n = sizeof(arr)/sizeof(arr[0]);
				
		switch(choice){
			case 1: 
				quickSort(arr, 0, n-1); 
				printf("Quick sorted array: "); 
				printArray(arr, n); 
				break;
			case 2:
				mergeSort(arr, 0, n-1);
				printf("Marge sorted array: "); 
				printArray(arr, n); 
				break;
			case 3:
				radixSort (arr, n);
				printf("Radix sorted array: ");
				printArray(arr, n);
				break;
		}
	}
	return 0;
}
