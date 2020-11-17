#include <bits/stdc++.h>

using namespace std;

int recursivo(int *array, int valor, int l, int r){
	int mitad = (l+r)/2;
	if(array[mitad] != valor && l==r){
		return -1;
	}
	if(array[mitad] == valor){
		return 0;
	}else if(valor > array[mitad]){
		return recursivo(array,valor,mitad+1,r);
	}else{
		return recursivo(array,valor,l,mitad-1);
	}
}

int main(int argc, char **argv){
	struct timespec st, et;
	double t;

	int size = atoi(argv[1]); // numero de elementos
	int num_ops = atoi(argv[2]); // numero de búsquedas

	int *array = (int *) malloc(sizeof(int)*size);
	int i,aux,temp,l=0,r=size-1;

	ifstream fin("input_450000.txt");

	for(i=0;i<size;i++){
		fin>>aux;
		array[i] = aux;
	}
	clock_gettime(CLOCK_MONOTONIC, &st);

	for(i=0;i<num_ops;i++){
		temp = rand() % size + 1;
		recursivo(array,temp,l,r);
	}
	
	clock_gettime(CLOCK_MONOTONIC, &et);
	t = (et.tv_sec - st.tv_sec) + (et.tv_nsec - st.tv_nsec) / 1000000000.0;
  	printf("%u;%u;%lf;", size, num_ops, t);
	return 0;
}