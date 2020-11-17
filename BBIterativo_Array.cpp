#include <bits/stdc++.h>

using namespace std;

void BBIterativo(int *array, int valor, int size){
	int mitad, l = 0, r = size - 1;
	while(l<=r){
		mitad = (l+r)/2;
		if(array[mitad] == valor){
			return ;
		}else if(valor > array[mitad]){
			l = mitad + 1;
		}else{
			r = mitad - 1;
		}
	}
	return ;
}

int main(int argc, char **argv){
	struct timespec st, et;
	double t;

	int size = atoi(argv[1]); // numero de elementos
	int num_ops = atoi(argv[2]); // numero de búsquedas

	int *array = (int *) malloc(sizeof(int)*size);
	int i,aux,temp;

	ifstream fin("input_450000.txt");

	for(i=0;i<size;i++){
		fin>>aux;
		array[i] = aux;
	}
	clock_gettime(CLOCK_MONOTONIC, &st);

	for(i=0;i<num_ops;i++){
		temp = rand() % size + 1;
		BBIterativo(array,temp,size);
	}
	
	clock_gettime(CLOCK_MONOTONIC, &et);
	t = (et.tv_sec - st.tv_sec) + (et.tv_nsec - st.tv_nsec) / 1000000000.0;
  	printf("%u;%u;%lf;", size, num_ops, t);
	return 0;
}