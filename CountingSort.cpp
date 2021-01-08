// C++ Program for counting sort 
#include <bits/stdc++.h> 
#include <string.h> 
using namespace std; 


// The main function that sort 
// the given string arr[] in 
// alphabatical order 
void countSort(int arr[], int size) 
{ 
	// The output character array 
	// that will have sorted arr 
	int RANGE=0;
	for(int j=0;j<size;j++){ //Determina el elemento de mayor valor
		if(arr[j] > RANGE){
			RANGE = arr[j];
		}
	}
	int *output = (int *) malloc(sizeof(int)*size);

	// Create a count array to store count of inidividul 
	// characters and initialize count array as 0 
	int *count = (int *) malloc(sizeof(int)*RANGE+1);
	int i; 
	memset(count, 0, sizeof(count)); //Crea un arreglo de puros ceros

	// Store count of each character 
	for (i = 0; arr[i]; ++i) 
		++count[arr[i]]; 

	// Change count[i] so that count[i] now contains actual 
	// position of this character in output array 
	for (i = 1; i <= RANGE; ++i) 
		count[i] += count[i - 1]; 

	// Build the output character array 
	for (i = 0; arr[i]; ++i) { 
		output[count[arr[i]] - 1] = arr[i]; 
		--count[arr[i]]; 
	} 

	/* 
	For Stable algorithm 
	for (i = sizeof(arr)-1; i>=0; --i) 
	{ 
		output[count[arr[i]]-1] = arr[i]; 
		--count[arr[i]]; 
	} 
	
	For Logic : See implementation 
	*/

	// Copy the output array to arr, so that arr now 
	// contains sorted characters 
	for (i = 0; arr[i]; ++i) {
		arr[i] = output[i]; 
	}

	/*for(int j=0;j<size;j++){
		cout<<arr[j]<<" ";
	}*/
	free(output);
	free(count);
} 

// Driver code 
int main(int argc, char **argv){ 
	struct timespec st, et;
    double t;
    int size = atoi(argv[1]); // numero de elementos
    int *array = (int *) malloc(sizeof(int)*size);
    int i,aux,l = 0, r = size-1;

    ifstream fin("input_10500000_v1.txt");

    clock_gettime(CLOCK_MONOTONIC, &st);

    for(i=0;i<size;i++){
        fin>>aux;
        array[i] = aux;
    }
    
    countSort(array,size);
    
    clock_gettime(CLOCK_MONOTONIC, &et);
    t = (et.tv_sec - st.tv_sec) + (et.tv_nsec - st.tv_nsec) / 1000000000.0;
    printf("%u;%lf;", size, t);

    
    return 0;
} 

// This code is contributed by rathbhupendra 
