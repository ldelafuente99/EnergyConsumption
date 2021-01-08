
#include <bits/stdc++.h>
 
using namespace std; 

// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int *arr, int n, int i) 
{ 
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	// If largest is not root 
	if (largest != i) { 
		swap(arr[i], arr[largest]); 

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest); 
	} 
} 

// main function to do heap sort 
void heapSort(int *arr, int n) 
{ 
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i); 

	// One by one extract an element from heap 
	for (int i = n - 1; i >= 0; i--) { 
		// Move current root to end 
		swap(arr[0], arr[i]); 

		// call max heapify on the reduced heap 
		heapify(arr, i, 0); 
	} 
} 

int main(int argc, char **argv){
	struct timespec st, et;
	double t;
	int size = atoi(argv[1]); // numero de elementos
	int *array = (int *) malloc(sizeof(int)*size);
	int i,aux,l = 0, r = size-1;

	ifstream fin("input_150000.txt");

	clock_gettime(CLOCK_MONOTONIC, &st);

	for(i=0;i<size;i++){
		fin>>aux;
		array[i] = aux;
	}
	
	heapSort(array,size);
	
	clock_gettime(CLOCK_MONOTONIC, &et);
	t = (et.tv_sec - st.tv_sec) + (et.tv_nsec - st.tv_nsec) / 1000000000.0;
  	printf("%u;%lf;", size, t);

	return 0;
}