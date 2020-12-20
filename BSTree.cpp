#include <bits/stdc++.h>

using namespace std;

struct Node{
	int valor;
	struct Node *left;
	struct Node *right;
};

typedef struct Node *node;

void insertar(int valor,node &root){
	if(root == NULL){
		node nuevo = new (struct Node);
		nuevo->valor = valor;
		nuevo->left = NULL;
		nuevo->right = NULL;
		root = nuevo;
	}else{
		if(valor > root->valor){
			insertar(valor,root->right);
		}else if(valor < root->valor){
			insertar(valor,root->left);
		}else{
			// Numero repetido
		}
	}
}


// ------- RECORRIDOS ----------
//	Preorden 		(R) I D
//	Inorden  		I (R) D *
//	Postorden		I D (R)	
/*
void preorden(node root){
	if(root != NULL){
		cout<<root->valor<<", ";
		preorden(root->left);
		preorden(root->right);
	}
}

void inorden(node root){
	if(root != NULL){
		inorden(root->left);
		cout<<root->valor<<", ";
		inorden(root->right);
	}
}

void postorden(node root){
	if(root != NULL){
		postorden(root->left);
		postorden(root->right);
		cout<<root->valor<<", ";
	}
}*/

bool buscar(node root,int numero){
	if(root != NULL){
		if(root->valor == numero){
			return true;
		}else if(numero > root->valor){
			return buscar(root->right,numero);
		}else if(numero < root->valor){
			return buscar(root->left,numero);
		}else{
			return false;
		}
	}
	return false;
}


int main(int argc, char **argv){
	struct timespec st, et;
	double t;

	int size = atoi(argv[1]); // numero de elementos
	int num_ops = atoi(argv[2]); // numero de búsquedas

	node arbol = NULL;

	int *array = (int *) malloc(sizeof(int)*size);
	int i,aux,temp;

	ifstream fin("input_10500000.txt");

	for(i=0;i<size;i++){
		fin>>aux;
		array[i] = aux;
	}

	clock_gettime(CLOCK_MONOTONIC, &st);

	for(i=0;i<size;i++){
		insertar(array[i],arbol);
	}	

	/*for(i=0;i<num_ops;i++){
		temp = rand() % size + 1;
		buscar(arbol,temp);
	}*/
	
	clock_gettime(CLOCK_MONOTONIC, &et);
	t = (et.tv_sec - st.tv_sec) + (et.tv_nsec - st.tv_nsec) / 1000000000.0;
  	printf("%u;%u;%lf;", size, num_ops, t);
  	free(array);
	return 0;
}