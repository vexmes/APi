#include <iostream>
#include <string>
using namespace std; 

int cmpInt(int a,int b){return a-b;}

//Agrega el elemento e al final del arr incrementando su longitud len.
template <typename T>
int add(T arr[],int& len,T e){
    arr[len++] = e;
    return len;
}

//Inserta el elemento e en la posición p del array arr. Desplaza los elementos ubicados a partir de p+1 e incrementa la longitud len.
template <typename T>
   void insert(T arr[], int &len, T e, int p)
{
   if (len == 0)
   {
      add<T>(arr, len, e);
   }
   else
   {
      for (int i = len; i > p; i--)
      {
         arr[i] = arr[i - 1];
      }
      arr[p] = e;
      len++;
   }
}

//Remueve el elemento ubicado en la posición p del array arr. Desplaza ubicados a partir de p y decrementa la longitud len.
template <typename T>
T remove(T arr[],int& len,int p)
{
    T x = arr[p];

    {
        for (int i = p; i<len; i++)
        arr[i] = arr[i+1];

    }

    len--;
    return x;
}

//Retorna la posición de la primera ocurrencia de k dentro de arr o un valor negativo si arr no contiene a k.
template <typename T, typename K>
int find(T arr[], int len, K k, int (*cmpTK)(T, K)) {
    for (int i = 0; i < len; i++) {
        if (cmpTK(arr[i], k)) {
            return i; // Retorna el índice si encuentra el elemento
        }
    }
    return -1; // Retorna -1 si no lo encuentra
}

//Inserta e dentro de arr según el criterio de precedencia que establece cmpTT, y retorna la posición donde dicho elemento quedó insertado. El array arr debe estar ordenado o vacío.
template <typename T>
int orderedInsert(T arr[],int& len,T e,int cmpTT(T,T)){
   int retorno = 0;
   bool inserted = false;

   for (int i = 0; i < len && inserted == false ; i++) {

        if (cmpTT(e, arr[i]) < 0 ) 

        {
         insert<T>(arr, len, e, i);
            retorno = i;
            inserted = true;
        }
}
return retorno;
}

//Ordena arr según el criterio de precedencia que establece cmpTT.
template <typename T>
void sort(T arr[],int len,int cmpTT(T,T)){
   T arrb[len];
   for(int i = 0; i<len; i++){
      orderedInsert(arrb,len, arr[i], cmpTT);
   }
    for(int i = 0; i<len; i++){
      arr[i] = arrb[i];
}
}