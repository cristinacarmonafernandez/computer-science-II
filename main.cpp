#include <iostream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

struct Anagrama{
   string clave;
   vector<string> secuencia;
};

//Función que vamos a usar para pasar palabras mayúsculas con y sin tilde a minúscula
void Minus(string& cadena){
   string LETESP="ÁÉÍÓÚÜÑ";
   string espminus="áéíóúüñ";
   for(int i=0; i<(int)cadena.size(); i++){
      bool contilde=false; //Creamos un booleano para que si recorre la palabra y la letra tiene tilde no entre en el tolower
      for(int j=0; j<(int)LETESP.size(); j++){
         if(cadena[i]==LETESP[j]){
            contilde=true;
            cadena[i]=espminus[j];
         }
      }
      if(contilde==false)
         cadena[i]=tolower(cadena[i]);
    }
}


//Función para comprobar si es letra
bool EsLetra(const char& let){
   bool letra=false;
   string LET_ESP= "áéíóúüñÁÉÍÓÚÜÑ";
   if(('a'<=let && let<='z') || ('A'<=let && let<='Z'))
      letra=true;
   else{ //Si no está en el abecedario, comprobamos si tiene tilde
      for(int j=0; j<(int)LET_ESP.size(); j++)
         if(let==LET_ESP[j])
            letra=true;
   }
   return letra;
}

//Función para quitar tildes
void QuitarTildes(string& palabra){
   string LET_ESP="áéíóú";
   string sintilde= "aeiou";

   for(int i=0; i<(int)palabra.size(); i++){
      if(palabra[i]=='ü')
         palabra[i]='u';
      else{
         for(int j=0; j<(int)LET_ESP.size(); j++){
            if(palabra[i]==LET_ESP[j])
            palabra[i]=sintilde[j];
         }
      }
   }
}

//Funciones que vamos a usar para crear las claves
int BuscarMinimo(const string& cadena, int pos){
   int minimo=pos;
   for(int i=pos+1; i<(int)cadena.size(); i++)
      if(cadena.at(i)<cadena.at(minimo))
         minimo=i;
   return minimo;
}

void Intercambiar(char& c1, char& c2){
   char auxiliar=c1;
   c1=c2;
   c2=auxiliar;
}

void OrdenarCadena(string& cadena){
   for(int i=0; i<(int)cadena.size(); i++){
      int minimo=BuscarMinimo(cadena, i);
      Intercambiar(cadena.at(i), cadena.at(minimo));
   }
}

//Función que vamos a usar para buscar la posición correcta de la palabra en el vector secuencias
int BusquedaBinariaPalabra(const vector<string>& secuencia, const string& palabra){
   int izq=0, dcha=(int)secuencia.size()-1, centro;
   bool encontrado=false;

   while(izq<=dcha && encontrado==false){
      centro=(izq+dcha)/2;
      if(secuencia.at(centro)>palabra)
         dcha=centro-1;
      else if(secuencia.at(centro)<palabra)
         izq=centro+1;
      else
         encontrado=true;
    }
   if(encontrado==false)
      centro=-1;

   return centro;
}

//Función que vamos a usar para buscar la posición correcta de la clave
int BusquedaBinariaClave(const vector<Anagrama>& vect, const string& clave){
   int izq=0, dcha=(int)vect.size()-1, centro;
   bool encontrado=false;

   while(izq<=dcha && encontrado==false){
      centro=(izq+dcha)/2;
      if(vect.at(centro).clave>clave)
         dcha=centro-1;
      else if(vect.at(centro).clave<clave)
         izq=centro+1;
      else
         encontrado=true;
    }
    if(encontrado==false)
        centro=-1;

   return centro;
}

//Función que ordena el vector anagrama alfabeticamente
void DesplazarHaciaAtrasClaves(vector<Anagrama>& v, int pos){
   Anagrama aux=v[pos];
   int i;
   for(i=pos; i>0 && aux.clave<v.at(i-1).clave; i--){
      v[i].secuencia=v[i-1].secuencia;
      v[i].clave=v[i-1].clave;
   }
   v[i].clave=aux.clave;
   v[i].secuencia=aux.secuencia;

}

//Función que ordena el vector secuencias alfabeticamente
void DesplazarHaciaAtrasSec(vector<string>& secuencia, int pos){
   string aux=secuencia[pos];
   int i;
   for(i=pos; i>0 && aux<secuencia.at(i-1); i--)
      secuencia.at(i)=secuencia.at(i-1);
   secuencia.at(i)=aux;
}

//Función que verifica la entrada de una palabra
bool LeerPalabra(char& c, string&palabra){
   bool pal=true;
   palabra.clear(); //Vaciamos la cadena para evitar valores basura
   cin.get(c);
   while(EsLetra(c)==true){
      palabra.push_back(c); // Creamos la palabra letra a letra
      cin.get(c);
   }
   if((int)palabra.size()==0)
      pal=false;

   return pal;
}

//Funcion para insertar las claves y las palabras en su correspondiente posición
void InsertarPalabra (vector<Anagrama>& texto, string palabra, const bool& existe) {
   if(existe==true){
      Minus(palabra);
      string palordenada=palabra;
      QuitarTildes(palordenada);
      OrdenarCadena(palordenada);
      int posclave=BusquedaBinariaClave(texto, palordenada);
      if(posclave!=-1){ //Cuando la clave ya existe
         int pospalabra=BusquedaBinariaPalabra(texto[posclave].secuencia, palabra);
         if(pospalabra==-1){ //Cuando la palabra no existe en la secuencia
            texto[posclave].secuencia.push_back(palabra);
            DesplazarHaciaAtrasSec(texto[posclave].secuencia, (int)texto[posclave].secuencia.size()-1);
         }
      }
      else{ //Cuando la clave no existe, creamos un nuevo anagrama
         Anagrama nuevo;
         nuevo.clave=palordenada;
         nuevo.secuencia.push_back(palabra);
         texto.push_back(nuevo);
         DesplazarHaciaAtrasClaves(texto, (int)texto.size()-1);
      }
   }
}

//Función para la salida de los anagramas
void EscribirAnagramas(const vector<Anagrama>& texto){
   cout << "LOS ANAGRAMAS SON: " << endl;
   for(int i=0; i<(int)texto.size(); i++){
      if((int)texto[i].secuencia.size()>1){ //Solo aparezca por pantalla los que tengan más de una palabra
         cout << "-Clave: " << texto[i].clave << endl;
         cout << " Palabras: ";
         for(int j=0; j<(int)texto[i].secuencia.size(); j++){
            if(j==(int)texto[i].secuencia.size()-1)
               cout << texto[i].secuencia[j] << ".";
            else
               cout << texto[i].secuencia[j] << ", ";
         }
         cout << endl;
      }
   }
}

int main()
{
    system ("chcp 1252");
   vector<Anagrama> texto;

   cout << "Introduzca el texto: ";
   char c;
   while(!cin.eof()) {
      string palabra;
      bool existe=LeerPalabra(c, palabra);
      InsertarPalabra(texto, palabra, existe);
   }

   cout << endl;

   EscribirAnagramas(texto);

   return 0;
}
