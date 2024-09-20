#include <iostream>
#include <string>
using namespace std;
/*Cuenta la cantidad de caracteres que componen la cadena s.*/
int length (string s)
{
    int i = 0;
    while(s[i]!='\0')
    {
        i++;
    }
    return i;
}

/*Cuenta la cantidad de veces que aparece el carácter c dentro de s.*/
int charCount(string s,char c)
{
    int i = 0;
    for(char letra : s){
        if(letra == c){
            i++;
        }
    }
   return i;
}

/*Retorna la subcadena de s comprendida entre las posiciones d (inclu-
sive) y h (no inclusive).*/
string subString(string s,int d,int h)
{
   {
   string subs = "";
   for (int i = d; i < h; i++)
   {
      subs = subs + s[i];
   }
   return subs;
}
}

/*Retorna la subcadena de s comprendida entre la posición d y el final de
la cadena.*/
string subString(string s,int d)
{
    string result = "";

    for (int i = d; s[i] != '\0'; ++i) {
        result += s[i];
    }

    return result;
}


/*Retorna la posición que ocupa la primera ocurrencia del carácter c
dentro de la cadena s.*/
int indexOf(string s,char c)
{
    int i = 0;
     while (s[i] != '\0') {
        if (s[i] == c) {
            return i; // Retornamos la posición de la primera ocurrencia
        }
        ++i;
    }
    return -1; // Retornamos -1 si el carácter no se encuentra en la cadena
}


/*Retorna la posición que ocupa la primera ocurrencia de un carácter c 
dentro de la cadena s, descartando los primeros offeset caracteres (desplazamiento inicial).*/
int indexOf(string s,char c,int offset)
{
 for (int i = offset; s[i] != '\0'; i++) {
        if (s[i] == c) {
            return i;
        }
 }
 return -1;
}

/*Retorna la posición que ocupa la primera ocurrencia de toSearch dentro
de la cadena s.*/
int indexOf(string s,string toSearch)
{
    int i = 0;
    int j = 0;

    
    while (s[i] != '\0') {

        if (s[i] == toSearch[j]) {
            ++i;
            ++j;
          
            if (toSearch[j] == '\0') {
                return i - j; 
            }
        } else {
            
            i = i - j + 1; 
            j = 0; 
        }
    }
    return -1;
}


/*Retorna la posición que ocupa la primera ocurrencia de toSearch
dentro de la cadena s, descartando los primeros offeset caracteres (desplazamiento inicial).*/
int indexOf(string s,string toSearch,int offset)
{
     int i = offset;
    int j = 0;

    
    while (s[i] != '\0') {

        if (s[i] == toSearch[j]) {
            ++i;
            ++j;
          
            if (toSearch[j] == '\0') {
                return i - j; 
            }
        } else {
            
            i = i - j + 1; 
            j = 0; 
        }
    }
    return -1;
}


/*Retorna la posición de la última ocurrencia del carácter c dentro de s.*/
int lastIndexOf(string s,char c)
{ 
    int j = 0;
     for (int i = 0; s[i] != '\0'; i++) 
     {
     if (s[i] == c) 
     {
        j = i;
        
     }
 }
 return j;
}


/*Retorna la posición de la n-ésima ocurrencia de c dentro de s. Si n es 0
(cero) retorna -1; si n es mayor que la cantidad de ocurrencias de c retorna la longitud
de la cadena s.*/
int indexOfN(string s,char c,int n)
{
   int pos = -1;
   if (n == 0)
   {
      return pos;
   }
   int ocurrences = 0;
   for (int i = 0; i < length(s); i++) // Recorro el string s
   {
      if (s[i] == c) // Encuentro coincidencias con el caracter c
      {
         pos = i;
         ocurrences++;
         if (ocurrences == n)
         {
            return pos;
         }
      }
      if (ocurrences < n)
      {
         pos = length(s);
      }
   }
   return pos;
}


/*Retorna el valor numérico que representa el carácter c.*/
int charToInt(char c)
{
    if(c >='0' && c<='9'){
    c= c - '0';
    return c;
    }
     else 
     c = c - '7';
     return c;
}


/*Retorna el carácter que representa al valor de i, que debe estar com-
prendido entre 0 y 9, o en entre 65 y 90. Es la función inversa de charToInt.*/
char intToChar(int i){
     if(i >0 && i<9){
        i = i + '0';
    return i;
    }
     else 
     i = i + '7';
     return i;
}


/*Retorna el i-ésimo dígito del valor de n.*/
int getDigit(int n,int i){
    while (i > 0 && n != 0) {
        n /= 10;
        i--;
    }
    return n % 10;
}


/*Retorna la cantidad de dígitos que contiene el valor de n.*/
int digitCount(int n){
    int i = 0;
    while(n!=0)
    {
        n= n/10;
        i++;
    }
    return i;
}


/*Retorna una cadena de caracteres representando el valor i.*/
string intToString(int i){
#include <string>
    if (i == 0) {
        return "0"; // Caso especial para el número 0
    }

    string result = "";
    bool isNegative = false;

    // Manejar números negativos
    if (i < 0) {
        isNegative = true;
        i = -i; // Convertir número negativo a positivo
    }

    // Convertir cada dígito del número a un carácter
    while (i > 0) {
        char digitChar = '0' + (i % 10); // Convertir dígito a carácter
        result = digitChar + result; // Agregar el carácter al inicio de la cadena
        i /= 10; // Eliminar el último dígito del número
    }

    // Agregar signo negativo si el número era negativo
    if (isNegative) {
        result = '-' + result;
    }

    return result;
}


/*Retorna el valoro numérico representado en la cadena s, conside-
rando que dicho valor está expresado en la base numérica b.*/
int stringToInt(string s,int b){
       int result = 0;
    int sign = 1;
    int startIndex = 0;

    // Manejar el signo si es necesario
    if (s[0] == '-') {
        sign = -1;
        startIndex = 1;
    }

    // Convertir cada dígito de la cadena al valor numérico correspondiente en la base b
    for (int i = startIndex; i < s.length(); ++i) {
        char c = s[i];
        int digitValue = 0;
        
        // Convertir el carácter a su valor numérico según la base b
        if (c >= '0' && c <= '9') {
            digitValue = c - '0';
        } else if (c >= 'A' && c <= 'Z') {
            digitValue = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'z') {
            digitValue = c - 'a' + 10;
        } else {
            // Carácter no válido
            return 0;
        }
        
        // Verificar que el dígito esté en la base especificada
        if (digitValue >= b) {
            return 0;
        }
        
        result = result * b + digitValue;
    }

    return result * sign;
}


/*Retorna el valor numérico de la cadena s, que sólo debe contener dí-
gitos numéricos en base 10. Esta función es la función inversa de intToString.*/
int stringToInt(string s){
     int result = 0;
    int sign = 1;
    int startIndex = 0;

    // Manejar el signo si es necesario
    if (s[0] == '-') {
        sign = -1;
        startIndex = 1;
    }

    // Convertir cada dígito de la cadena al valor numérico correspondiente
    for (int i = startIndex; i < s.length(); ++i) {
        char c = s[i];
        if (c < '0' || c > '9') {
            // Si el carácter no es un dígito válido, retornar 0
            return 0;
        }
        result = result * 10 + (c - '0');
    }

    return result * sign;
}


/*Retorna una cadena cuyo único carácter es c.*/
string charToString(char c){
 return string (1,c);
}


/*Retorna el único carácter que contiene la cadena s. Esta es la función
inversa de charToString.*/
char stringToChar(string s){
    return s[0];
}


/*Retorna la misma cadena que recibe. Se trata de una función trivial que
usaremos más adelante, dentro de este mismo capítulo.*/
string stringToString(string s){
    string d = s;
    return d;
}


/*Retorna una cadena representando el valor contenido en d.*/
string doubleToString(double d){
    string c = to_string(d);
    return c;
}


/*Retorna el valor numérico representado en la cadena s.*/
double stringToDouble(string s){
    return stod(s);
}


/*Retorna true o false según s sea o no la cadena vacía.*/
bool isEmpty(string s){
    if(s==""){
    return true;
    } else {
    return false;
    }
}


/*Determina si x es prefijo de s.*/
bool startsWith(string s,string x){
    int l = 0;
    int i = 0;
    while(l<=length(x)){
        if(s[i]==x[i]){
            i++;
        }
        l++;
    } 
    if(i==length(x)){
        return true;
    } else { 
        return false;
    }
}


/*Determina si x es sufijo de s.*/
bool endsWith(string s,string x){
    int l = 0;
    int i = 0;
    while(l<=s.length())
    {
        if(s[i]==x[i]){
            i++;
        }
        l++;
    } 
    if(i=x.length()){
        return true;
    } else { 
        return false;
    }
}


/*Determinar si la cadena s contiene al carácter c.*/
bool contains(string s,char c){
     int i = 0;
    while (i < length(s)) {
        if (s[i] == c) {
            return true;
        }
        i++;
    }
    return false;
}


/*Reemplaza en s todas las ocurrencias de oldChar por newChar.*/
string replace(string s,char oldChar,char newChar){
    for (char&c : s) {
        if (c == oldChar) {
            c = newChar;
        }
    }
    return s;
}


/*Insertar el carácter c en la posición pos de la cadena s.*/
string insertAt(string s,int pos,char c){ 
    s.insert(pos, 1, c);
    return s;
}


/*Remover de s el carácter ubicado en la posición pos.*/
string removeAt(std::string s, int pos) {
    if (pos >= 0 && pos < s.length()) {
        s.erase(pos, 1); // Elimina 1 carácter en la posición especificada
    }
    return s;
}


/*Recorta los espacios en blanco que se encuentren a la izquierda de s.*/
string ltrim(string s){ 
    string result;
    bool foundNonSpace = false;

    for (char c : s) {
        if (!foundNonSpace && c == ' ') {
            continue; // Saltar espacios en blanco al principio
        }
        foundNonSpace = true;
        result += c;
    }

    return result;
}


/*Recortar los espacios en blanco a la derecha de s.*/
string rtrim(string s){
        string result;

    // Recorremos la cadena en reversa para encontrar el primer carácter que no sea un espacio en blanco
    int end = length(s) - 1;
    while (end >= 0 && s[end] == ' ') {
        end--;
    }

    // Construimos la cadena resultante utilizando los caracteres antes del primer espacio en blanco
    for (int i = 0; i <= end; i++) {
        result += s[i];
    }

    return result;
}


/*Recortar los espacios en blanco ubicados a izquierda y derecha de s.*/
string trim(string s){
        string result;

    // Eliminamos los espacios en blanco al principio de la cadena
    int start = 0;
    while (start < s.size() && s[start] == ' ') {
        start++;
    }

    // Eliminamos los espacios en blanco al final de la cadena
    int end = s.size() - 1;
    while (end >= 0 && s[end] == ' ') {
        end--;
    }

    // Construimos la cadena resultante utilizando los caracteres entre start y end
    for (int i = start; i <= end; i++) {
        result += s[i];
    }

    return result;
}


/*Generar una cadena de caracteres compuesta por n caracteres c.*/
string replicate(char c,int n){
    string result = "";
    int i = 0;
    while(i<n){
        result += c;
        i++;
    }
    return result;
}


/*Genera una cadena de caracteres compuesta por n caracteres ' '.*/
string spaces(int n){
    int i = 0;
    string s = "";
    while(i<n){
        s+=" ";
        i++;
    }
    return s;
}


/*Retorna una cadena idéntica a s, con longitud n completando, si fuese
necesario, con caracteres c a la izquierda hasta llegar a la longitud requerida.*/
string lpad(string s,int n,char c){
  int lon = n - length(s);
  string rep = replicate(c,lon);
  string result = rep + s;
  return result;
}


/*Idem lpad pero, de ser necesario, agrega caracteres c a la derecha.*/
string rpad(string s,int n,char c){
    int lon = n - length(s);
  string rep = replicate(c,lon);
  string result = s+rep;
  return result;
}


/*Idem rpad pero distribuye los caracteres c a izquierda y derecha.*/
string cpad(string s,int n,char c){
    int l = n - length(s);
    int lon = l/2;
    string rep = replicate(c,lon);
    string r = rep + s;
    string result = r + rep;
    return result;
}


/*Determinar si el valor de c corresponde o no a un dígito numérico.*/
bool isDigit(char c){
    bool result = false;
    if('0'<=c && c<='9'){
        result = true;
    } else {
        result = false;
    }
    return result;
}


/*Determina si el valor de c corresponde o no a una letra.*/
bool isLetter(char c){
    bool result = false;
    if('A'<=c && c<='Z'&& 'a'<=c && 'z'<=c){
        result = true;
    } else {
        result = false;
    }
    return result;
}


/*Determinar si el valor de c corresponde a una letra mayúscula.*/
bool isUpperCase(char c){
    bool result = false;
    if('A'<=c && c<='Z'){
        result = true;
    } else {
        result = false;
    }
    return result;
}


/*Determina si el valor de c corresponde a una letra minúscula.*/
bool isLowerCase(char c){
     bool result = false;
    if('a'<=c && c<='z'){
        result = true;
    } else {
        result = false;
    }
    return result;
}


/*Convertir el valor de c a mayúscula.*/
char toUpperCase(char c){
    char r = c;
    if('a'<=c && c<='z')
    {
    char result = ' ';
    result = c -32 ;
    return result;
    }
    return r; 
}


/*Convierte el valor de c a minúscula.*/
char toLowerCase(char c){
   char r = c;
    if('A'<=c && c<='Z')
    {
    char result = ' ';
    result = c + 32 ;
    return result;
    }
    return r;  
}


/*Retorna una cadena idéntica a s pero completamente en mayúsculas.*/
string toUpperCase(string s){
     for (char&c : s) {
        if (c == toLowerCase(c)) {
            c = toUpperCase(c);
        }
    }
    return s;
}


/*Retorna una cadena idéntica a s pero completamente en minúsculas.*/
string toLowerCase(string s){
    for (char&c : s) {
        if (c == toUpperCase(c)) {
            c = toLowerCase(c);
        }
    }
    return s;
}


/*Compara alfabéticamente dos cadenas.*/
int cmpString(string a,string b){
      if (a < b) {
        return -1; // a es menor que b
    } else if (a > b) {
        return 1;  // a es mayor que b
    } else {
        return 0;  // a es igual a b
    }
}


/*Compara dos valores.*/
int cmpDouble(double a,double b){
    if (a < b) {
        return -1; // a es menor que b
    } else if (a > b) {
        return 1;  // a es mayor que b
    } else {
        return 0;  // a es igual a b
    }
}