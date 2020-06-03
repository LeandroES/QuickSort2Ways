//
//  main.cpp
//  QuickSort2Ways
//
//  Created by Leandro Smirnovff on 6/2/20.
//  Copyright © 2020 Leandro Igor Estrada Santos. All rights reserved.
//


#include <iostream>
#include <ctime>
const int size=15, MAX = 1000;

using namespace std;

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high){
    
    int pivot = arr[high];
    int i = (low - 1);
   
    for (int j = low; j <= high- 1; j++){

        if (arr[j] <= pivot){
            
            i++;
            swap(&arr[i], &arr[j]);
            
        }
        
    }
    
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
    
}

void quickSort(int arr[], int low, int high){
    if (low < high){
        
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
        
    }
    
}


   
void displayArray(int arr[], int size)
{
    
    int i;
    for (i=0; i < size; i++){
        
        cout<<arr[i]<<"\t";
        
    }
    
}
   
int main()
{
    //cout<<"Type size: "<<endl;
    //cin>>size;
    
    int A[ size ] = { 0 };
       srand( time( 0 ) );
    for (int i = 0; i < size; ++i ){
          A[ i ] = rand() % MAX;
    }
    int n = (sizeof(A)/sizeof(A[0]));
    
    printf("Input Array: \r\n");
    displayArray(A,n);
    cout<<endl;
    quickSort(A, 0, n-1);
    printf("QuickSort way results: \r\n");
    displayArray(A,n);
    printf("\r\n");
    
    
    
}

