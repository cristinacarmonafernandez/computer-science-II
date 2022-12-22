#include <iostream>
#include<vector>
#include<cmath>

using namespace std;

void Intervalo(int& n){
    while (n<2 || n>20){
        cout << "El tamaño no se encuentra en el rango, introduzca uno nuevo: ";
        cin >> n;
    }
}


int main()
{
    int tam;
    cout << "Introduzca el tamano del vector: "<< endl;
    cin >> tam;
    Intervalo(tam);

    vector<double> v(tam);
    cout << "Introduzca los valores: " << endl;
    for (int i=0; i<tam; i++){
        cin >> v[i];
    }

    //Hallamos la media
    double suma=0;
    for (int i=0; i<tam; i++){
        suma+=v[i];
    }
    double media=suma/tam;
    cout << "La media es: " << media << endl;

    //Desviacion media
    double sumadm=0;
    for (int i=0; i<tam; i++){
        sumadm=sumadm+abs(v[i]-media);
    }
    double desvm=sumadm/tam;
    cout << "La desviacion media es: " << desvm << endl;

    //varianza
    double sumav=0;
    for (int i=0; i<tam; i++){
        sumav=sumav+(pow(v[i]-media,2));
    }
    double varianza=sumav/tam;
    cout << "La varianza es: " << varianza << endl;

    return 0;
}





/*   double lat, lon, alt;
   cout << "Introduzca posición geográfica: <latitud> <longitud> <altura> m: ";
   if (LeerGeograficas(lat, lon, alt)) {
      cout << "Posición introducida: ";
      EscribirGeograficas(lat, lon, alt);
      cout << endl;
   }
   else cout << "El ángulo no tiene el formato esperado" << endl;*\
