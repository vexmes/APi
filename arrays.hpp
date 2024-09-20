#include <iostream>
#include <string>
using namespace std; 


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