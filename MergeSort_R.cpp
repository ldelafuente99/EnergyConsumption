#include <bits/stdc++.h>

using namespace std;

void Merge(int *array, int l, int mitad, int r){
	int i,j,k;
	int n1 = mitad - l + 1, n2 = r - mitad;

	//int temp1[n1], temp2[n2]; // modificar
	int *temp1 =(int *)malloc(sizeof(int)*n1);
	int *temp2 =(int *)malloc(sizeof(int)*n2);

	for(i=0;i<n1;i++){
		temp1[i] = array[l+i];
	}
	for(i=0;i<n2;i++){
		temp2[i] = array[mitad+1+i];
	}
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2){
		if(temp1[i] <= temp2[j]){
			array[k] = temp1[i];
			i++;
		}else{
			array[k] = temp2[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		array[k] = temp1[i];
		i++;
		k++;
	}
	while(j<n2){
		array[k] = temp2[j];
		j++;
		k++;
	}

	free(temp1);
	free(temp2);
}

void MergeSort(int *array, int l, int r){
	if(l<r){
		int mitad = (l+r)/2;
		MergeSort(array,l,mitad);
		MergeSort(array,mitad+1,r);

		Merge(array,l,mitad,r);	
	}
}

int main(int argc, char **argv){
	struct timespec st, et;
	double t;
	int size = atoi(argv[1]); // numero de elementos
	int *array = (int *) malloc(sizeof(int)*size);
	int i,aux,l = 0, r = size-1;

	ifstream fin("input_10500000.txt");

	clock_gettime(CLOCK_MONOTONIC, &st);
	
	for(i=0;i<size;i++){
		fin>>aux;
		array[i] = aux;
	}
	
	//MergeSort(array,l,r);
	
	clock_gettime(CLOCK_MONOTONIC, &et);
	t = (et.tv_sec - st.tv_sec) + (et.tv_nsec - st.tv_nsec) / 1000000000.0;
  	printf("%u;%lf;", size, t);

	return 0;
}