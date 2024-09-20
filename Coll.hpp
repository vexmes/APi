#include <iostream>
#include <string>
using namespace std;
#include "\Users\Victor\OneDrive\Escritorio\UTN\LyED\tokens.hpp"
template<typename T>

struct Coll{
    string tokens;
    char sep;
    int count;
};

template <typename T>
Coll<T> coll(char sep)
{
    return {"", sep};
}

template <typename T>
Coll<T> coll()
{
    return {"", '|'};
}

template <typename T>
int collSize(Coll<T> c){
    int i = tokenCount(c.tokens, c.sep);
    return i;
}

template <typename T>
void collRemoveAll(Coll<T>& c){
    c.tokens = "";
}

template <typename T>
void collRemoveAt(Coll<T>& c,int p){
    removeTokenAt(c.tokens , c.sep, p);
}

template <typename T>
int collAdd(Coll<T>& c,T t,string tToString(T)){
    addToken(c.tokens, c.sep , tToString(t));
    return 0;
}

template <typename T>
void collSetAt(Coll<T>& c,T t,int p,string tToString(T)){
    setTokenAt(c.tokens, c.sep, tToString(t), p);
}

template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string)){
    T result = tFromString( getTokenAt(c.tokens, c.sep, p));
    return result;
}

template <typename T, typename K>
int collFind(Coll<T> c , K k , int cmpTK(T,K), T tFromString(string)){
 {
   int p = -1;
   for (int i = 0; i < tokenCount(c.tokens, c.sep); i++)
   {
      string currentToken = getTokenAt(c.tokens, c.sep, i);
      if (cmpTK(currentToken, k) == 0)
      {
         p = i;
      }
   }
   return p;
}
}

template <typename T>
bool collHasNext(Coll<T> c){
    bool result = false;
    if(c.count<collSize(c)){
        result = true;
    }
    return result;
}

template <typename T>
T collNext(Coll<T>& c,T tFromString(string)){
   T t;
   if (collHasNext(c))
   {
      t = tFromString(getTokenAt(c.tokens, c.sep, c.cI));
      c.count++;
   }

   return t;
}

template <typename T>
T collNext(Coll<T>& c,bool& eoc,T tFromString(string)){
    T t;
    eoc = false;
   if (collHasNext(c))
   {
      t = tFromString(getTokenAt(c.tokens, c.sep, c.cI));
      c.count++;
      if(c.count>=collsize(c)){
        eoc = true;
      }
   }

   return t;
}

template <typename T>
void collReset(Coll<T>& c){
    c.count = 0;
}