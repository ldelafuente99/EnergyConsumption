#include <bits/stdc++.h>

using namespace std;

void bucketSort(vector<int> &arr, int n){ 
    // 1) Create n empty buckets 
    vector<int> b[n]; 
  
    // 2) Put array elements in different buckets 
    for (int i = 0; i < n; i++) { 
        int bi = arr[i]; // Index in bucket 
        b[bi].push_back(arr[i]); 
    } 
  
    // 3) Sort individual buckets 
    for (int i = 0; i < n; i++) 
        sort(b[i].begin(), b[i].end()); 
  
    // 4) Concatenate all buckets into arr[] 
    int index = 0; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < b[i].size(); j++) 
            arr[index++] = b[i][j]; 
} 
  
/* Driver program to test above function */
int main(){ 
    vector<int> array;
    int size,i,aux;
    ifstream fin("input_ordenar.txt");
    fin>>size;
    for(i=0;i<size;i++){
    	fin>>aux;
    	array.push_back(aux);
    } 
    bucketSort(array,size); 
  
    cout << "Sorted array is \n"; 
    for (i = 0; i < size; i++) 
        cout << array[i] << " "; 
    return 0; 
} 