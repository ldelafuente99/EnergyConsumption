# Medición sistemática del consumo energético de algoritmos de ordenamiento y búsqueda

_Proyecto de memoría de título para optar al grado de Ingeniero Civil Informático de la Universidad de Concepción por parte de Leonardo De La Fuente. Profesor guía José Fuentes. Colaborador Zheng Li._

## Algoritmos

_Se realizaron análisis sobre algunos algoritmos de ordenamiento y búsqueda._

##Algoritmos de ordenamiento

  - Merge Sort Iterativo
  - Merge Sort Recursivo
  - Counting Sort
  - Heap Sort

##Algoritmos de búsquedas
  
  - Binary Search Iterativo
  - Binary Search Recursivo
  - Binary Search Tree

##Nombre del archivo utilizado para cada algoritmo
 - Merge Sort Iterativo -> MergeSortIterativo.cpp
 - Merge Sort Recursivo -> MergeSortRecursivo.cpp
 - Counting Sort -> CountingSort.cpp
 - Heap Sort -> HeapSort.cpp
 - Binary Search Iterativo -> BBIterativo.cpp
 - Binary Search Recursivo -> BBRecursivo.cpp
 - Binary Search Tree -> BSTree.cpp

##Observacion

_Para el algoritmo de Binary Search Tree se modifico el codigo para agregar una métrica adicional de tiempo, para lo cual se creó otra versión de la implementación con nombre_ BSTree_Exp2.cpp._ 

##Compilación

´´´
Para cada función Main se debe modificar el nombre del archivo de entrada, los cuales se encuentran en el siguiente enlace:_ https://cutt.ly/fnUyhgq
Compilar el algoritmo como:
  - g++ nombre_del_algoritmo.cpp -o nombre_ejecutable
Existen dos script en bash, uno para los algoritmos de ordenamiento (run_exps_ordenar.sh) y otro para los algoritmos de búsqueda (run_exps_búsqueda.sh), para los cuales se debe ingresar el nombre del ejecutable.
´´´

