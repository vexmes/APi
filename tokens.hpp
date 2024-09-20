#include <iostream>
#include <string>
using namespace std;
#include "/Users/Victor/OneDrive/Escritorio/UTN/LyED/strings.hpp"

/*Cuenta la cantidad tokens que el separador sep genera en s*/
int tokenCount(string s,char sep){
    int i = charCount(s,sep);
    return i+1;
}

/*Agrega el token t al final de la cadena s.*/
void addToken(string& s,char sep,string t){
    if(s==""){
        s+=t;
    } else{
        s+=sep;
        s+=t;
    }
}

/*Retorna el i-ésimo token de la cadena tokenizada s.*/
string getTokenAt(string s,char sep,int i){
    string result;
    if(i==0){
        result = subString(s,0, indexOf(s,sep));
    } else {
        int start = indexOfN(s, sep, i)+1;
        int end = indexOfN(s,sep,i+1);
        result = subString(s, start, end);
        }
        return result;
    }


/*Remueve de s el token ubicado en la posición i.*/
void removeTokenAt(string &s, char sep, int i)
{
    if (i==0){
        s = subString(s, indexOf(s, sep)+1);
    } else {
        string start = subString(s,0,indexOfN(s,sep, i)+1);
        string end = subString(s,indexOfN(s,sep, i+1));
        s = start + end;
    }
}


/*Reemplaza por t el token de s ubicado en la posición i.*/
void setTokenAt(string& s,char sep,string t,int i){
    if(i==0){
        t+=sep;
        s = t + s;
    } else{
        string start = subString(s,0,indexOfN(s,sep, i)+1);
        string end = subString(s,indexOfN(s,sep, i+1));
        s = start + t + end;
    }
}

/*Determinar la posición que el token t ocupa dentro de la cadena s.*/
int findToken(string s, char sep, string t)
{
   int pos = -1;
   for (int i = 0; i < tokenCount(s, sep); i++)
   {
      if (getTokenAt(s, sep, i) == t)
      {
         pos = i;
      }
   }

   return pos;
}