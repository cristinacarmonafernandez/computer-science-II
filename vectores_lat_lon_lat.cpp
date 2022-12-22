#include <iostream>
#include <vector>

using namespace std;

void Leer(int tam, vector<double>& lat, vector<double>& lon, vector<double>& alt){

    cout << "Introduzca los elementos de la latitud: " << endl;
    for (int i=0; i<tam; i++){
        cin >> lat[i];
    }

    cout << "Introduzca los elementos de la longitud: " << endl;
    for (int i=0; i<tam; i++){
        cin >> lon[i];
    }

    cout << "Introduzca los elementos de la altura: " << endl;
    for (int i=0; i<tam; i++){
        cin >> alt[i];
    }
}

bool OrdenadoMenorMayor (int tam,const vector<double>& v){
    bool ordenado=true;
    for (int i=0; i<tam; i++)
        if (v[i]>v[i+1])
            return false ;
    return ordenado;
}

bool OrdenadoMayorMenor(int tam, const vector<double>& v){
    bool ordenado=true;
    for (int i=tam-1; i>=0; i--)
        if (v[i+1]<v[i])
            return false;
    return ordenado;
}

int BuscarMinimo (int tam, const vector <double>& v, int posinicial) {
   int posmin=posinicial;
   for (int i=posinicial+1; i<tam; i++)
      if (v.at (i)<v.at(posmin))
         posmin=i;
      return posmin;
}

void Intercambiar (double &v1, double &v2) {
   double aux=v1;
   v1=v2;
   v2=aux;
}


void OrdenarSeleccion (int tam, vector <double>& v) {
   if (OrdenadoMayorMenor(tam,v)==false && OrdenadoMenorMayor(tam,v)==false) {
      for (int i=0; i<tam; i++) {
         int posmin=BuscarMinimo (tam,v,i);
         Intercambiar (v.at(i),v.at(posmin));
      }
   }
}

void Mediana(int tam, vector<double> v){
    OrdenarSeleccion(tam, v);
    double mitad=tam/2;
    char car='?';
    double mediana;
    if(tam%2==0){
        while (car!='i' && car!='d' && car!='m') {
         cout << "Escribe si quiere hallar la mediana haciendo la media(m), por la izquierda (i) o por la derecha (d): " ;
         cin >> car;
     }
    }
      if (car=='m')
         mediana=(v[mitad]+v[mitad-1])/2;

      if (car=='d')
         mediana=v[mitad];

      if (car=='i')
         mediana=v[mitad-1];


   if (tam%2!=0) {
      mitad=((tam-1)/2);
      mediana=v[mitad];
    }

   cout << "La mediana es: " << mediana << endl;

}

int main()
{
    int n;
    cout << "Introduzca el numero de posiciones: " << endl;
    cin >> n;

    vector<double> latitud(n);
    vector<double> longitud(n);
    vector<double> altura(n);

    Leer(n,latitud,longitud,altura);
    Mediana(n,latitud);
    Mediana(n,longitud);
    Mediana(n,altura);

    return 0;
}
