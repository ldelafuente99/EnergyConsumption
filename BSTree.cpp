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
}

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

int main(){
	
	node arbol = NULL;
	vector<int> array;
	int size,valor,i,aux;
	ifstream fin("input.txt");
	fin>>valor;
	fin>>size;
	for(i=0;i<size;i++){
		fin>>aux;
		array.push_back(aux);
	}

	/*int array[] = {35,15,80,10,20,18,17,50,100,70,40};
	int sizeArray = (sizeof(array)/sizeof(*array));
	
	for(int i=0 ; i < sizeArray; i++){
		insertar(array[i],arbol);
	}*/

	for(i=0;i<size;i++){
		insertar(array[i],arbol);
	}
	
	cout<<"			+-------------------------------+"<<endl;
	cout<<"			|   Arbol Binario de Busqueda   |"<<endl;
	cout<<"			+-------------------------------+"<<endl;

	cout<<endl<<"PREORDEN : "<<endl;
	preorden(arbol);
	cout<<endl<<"INORDEN : "<<endl;
	inorden(arbol);
	cout<<endl<<"POSTORDEN : "<<endl;
	postorden(arbol);

	cout<<endl;
	cout<< ( buscar(arbol,valor) ? "Valor encontrado  ": "Valor no encontrado " )<<endl;
	
	return 0;
	
}