
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Minus (string& cadena) {

   for (int i=0; i<(int)cadena.size(); i++)
      cadena[i]=tolower(cadena[i]);
}

bool EsLetra (const string& cadena) {

   bool letra=true;

   for (int i=0; i<(int)cadena.size(); i++) {
      if (isalpha(cadena[i])==false) {
         letra=false;
      }
   }

return letra;
}

vector<string> OrdenarAscii (vector<string>& cadena) {

   for (int i=0; (int)i<cadena.size()-1; i++) {
      for (int j=i+1; (int)j<cadena.size(); j++) {
         if (cadena[i]>cadena[j]) {
            string auxiliar=cadena[i];
            cadena[i]=cadena[j];
            cadena [j]=auxiliar;
         }
      }
   }

return cadena;
}

bool Repetidos (const vector<string>& diccionario) {

   bool repetidos=false;

   for (int i=0; (int)i<diccionario.size() && repetidos==false; i++) {
      if (diccionario[i]==diccionario[i+1]) {
         repetidos=true;
      }
   }

return repetidos;
}

bool LecturaDiccionario (vector<string>& diccionario) {

   int entero;
   cout << "Introduzca un entero: ";
   cin >> entero;

   if (entero<0)
      cout << "No ha sido posible cargar el diccionario." << endl;

   cout << "Introduzca diccionario: " << endl;
   string palabra;

   bool verdadero=true;

   for (int i=0; i<entero && verdadero==true; i++) {
         cin >> palabra;
         if (EsLetra(palabra)==false) {
               verdadero=false;
         } else {
            diccionario.push_back(palabra);
            Minus (palabra);
         }
   }

return verdadero;
}

void SalidaDiccionario (const vector<string>& cadena) {
   cout << "El diccionario de " << (int)cadena.size() << " ha sido cargado con exito: " << endl;
   for (int i=0; (int)i<cadena.size(); i++)
      cout << i+1 << ".- " << cadena [i] << endl;
}

int main()
{
   vector<string> palabras;

   if (LecturaDiccionario(palabras)==true) {
      if (Repetidos(OrdenarAscii(palabras))==false) {
         SalidaDiccionario (palabras);
      } else cout << "Hay valores repetidos." << endl;
   } else cout << "No ha sido posible cargar el diccionario.";

   return 0;
}

