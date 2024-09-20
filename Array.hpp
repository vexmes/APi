#include <iostream>
#include <string>
using namespace std; 
#include <arrays.hpp>

template <typename T, typename K>
int cmpTK(T, K){
    if(T=K){
        return 0;
    } 
    return -1
}

template <typename T, typename K>
int cmpTT(T, K){
    if (T<K){
        return 
    }
}


template<typename T>
struct Array
{
    Array<T> arr[];
    int len = 0;

};

//Inicializa un array cuya capacidad inicial será establecida por defecto. La longitud del array será 0, y se incrementará a medida que se agreguen o inserten nuevos elementos.
template <typename T>
Array<T> array(){
    Array<T> arr;
    return arr;
} 

/*Agrega t al final de a incrementando, de ser necesario, su capacidad.
Retorna la posición del arr donde quedó ubicado el elemento t.*/
template<typename T>
int arrayAdd(Array<T>& a,T t){
    add(a, a.len, t);
    return a.len;
};

//Retorna la dirección del elemento de a ubicado en la posición p.
template <typename T>
T* arrayGet(Array<T> a,int p){
    return a[p];
}

//Asigna el elemento t en la posición p del array a.
template <typename T>
void arraySet(Array<T>& a,int p,T t){
    remove(a, a.len,p );
    insert(a, a.len, t, p);
}


//Inserta t en la posición p del array a.
template <typename T>
void arrayInsert(Array<T>& a,T t,int p){
    insert(a,a.len, t, p);
}


//Retorna la longitud actual del array.
template <typename T>
int arraySize(Array<T> a){
    return a.len;
}

//Remove el elemento de a ubicado en la posición p.
template <typename T>
T arrayRemove(Array<T>& a,int p){
    remove(a, a.len, p);
}

//Remueve todos los elemento de a dejándolo vacío, con longitud 0.
template <typename T>
void arrayRemoveAll(Array<T>& a){
    for(int i = a.len, i==0, i-- ){
        remove(a,a.len,i)
    }
}

/*Retorna la posición que k ocupa dentro de a, según la función de compa-
ración cmpTK, o un valor negativo si a no contiene a k.*/
template <typename T, typename K>
int arrayFind(Array<T> a,K k,int cmpTK(T,K)){
    for(int i = 0; i<a.len; i++){
        if(cmpTK(a[i], k)==0){
            return i;
        }
    }
    return i;
}

//Inserta t en a según el criterio de precedencia que establece cmpTT.
template <typename T>
int arrayOrderedInsert(Array<T>& a,T t,int cmpTT(T,T)){

}