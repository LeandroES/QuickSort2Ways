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

void quickSortMiddle(int arr[], int low, int high)
{
    if(low >= high) return;
    int l1 = low;
    int h1 = high;
    int pivot = arr[low + (high - low)/2];
    while(l1<=h1)
    {
        while(arr[l1] < pivot ){
            l1++;
        }
        while(arr[h1] > pivot ){
            h1--;
        }
        if(l1 <=h1){
            swap(arr[l1], arr[h1]);
            l1++;
            h1--;
        }
    }
    if(low < h1)quickSortMiddle(arr,low,h1); // < not <=
    if(l1 < high)quickSortMiddle(arr,l1,high); // < not <=
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
    
    printf("////////////// Mid-Pivot ------>");
    int A2[ size ] = { 0 };
       srand( time( 0 ) );
    for ( int i = 0; i < size; ++i ){
          A2[ i ] = rand() % MAX;
    }
    int n2 = (sizeof(A2)/sizeof(A2[0]));
    
    printf("\r\n");
    printf("Input Array: \r\n");
    displayArray(A2,n2);
    cout<<endl;
    quickSortMiddle(A2, 0, n2-1);
    printf("QuickSort Mid-Pivot way results: \r\n");
    displayArray(A2,n2);
    printf("\r\n");
    
    
}

