
#include <bits/stdc++.h>

using namespace std;

// minimo entre dos numeros
int min(int x, int y)
{
  return (x < y) ? x : y;
}

// divide y conquistaras
void merge(int A[], int temp[], int from, int mid, int to, int high)
{
  int k = from, i = from, j = mid + 1;

  // loop till there are elements in the left and right runs
  while (i <= mid && j <= to)
  {
    if (A[i] < A[j])
      temp[k++] = A[i++];
    else
      temp[k++] = A[j++];
  }

  // Copy remaining elements
  while (i < high && i <= mid)
    temp[k++] = A[i++];

  // Don't need to copy second half

  // copy back to the original array to reflect sorted order
  for (int i = from; i <= to; i++)
    A[i] = temp[i];
}

// Iteratively sort array A[low..high] using t450porary array
void mergesort(int A[], int temp[], int low, int high)
{
  // divide the array into blocks of size m
  // m = [1, 2, 4, 8, 16...]
  for (int m = 1; m <= high - low; m = 2*m)
  {
    // for m = 1, i = 0, 2, 4, 6, 8
    // for m = 2, i = 0, 4, 8
    // for m = 4, i = 0, 8
    // ...
    for (int i = low; i < high; i += 2*m)
    {
      int from = i;
      int mid = i + m - 1;
      int to = min(i + 2*m - 1, high);

      merge(A, temp, from, mid, to, high);
    }
  }
}

int main(int argc, char **argv){
  struct timespec st, et;
  double t;
  int size = atoi(argv[1]); // numero de elementos
  int *array = (int *) malloc(sizeof(int)*size);
  int *temp = (int *) malloc(sizeof(int)*size);
  int i,aux,l = 0, r = size-1;

  ifstream fin("input_10500000.txt");

  clock_gettime(CLOCK_MONOTONIC, &st);

  for(i=0;i<size;i++){
    fin>>aux;
    array[i] = aux;
  }
  
  //mergesort(array,temp,0,size-1);
  
  clock_gettime(CLOCK_MONOTONIC, &et);
  t = (et.tv_sec - st.tv_sec) + (et.tv_nsec - st.tv_nsec) / 1000000000.0;
    printf("%u;%lf;", size, t);

  return 0;
}