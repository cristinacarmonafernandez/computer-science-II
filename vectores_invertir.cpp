#include <iostream>
#include<vector>

using namespace std;

void Invertir (vector<double>& datos){
    for (int i=0; i<datos.size()/2; i++){
        double aux=datos[i];
        datos[i]=datos[datos.size()-1-i];
        datos[datos.size()-1-i]=aux;
    }
}

bool Ordenado (const vector<double>& v){
    for (int i=0; i<v.size()-1; i++)
        if (v[i]>v[i+1])
            return false;
    return true;
}

void EscribirDatos (vector<double>& datos){
    cout << "Los datos invertidos son: ";
    for (int i=0; i<datos.size(); ++i)
        cout << datos[i] << " ";
    cout << endl;

}

bool Contenido(const vector<double>& datos){
    int m;
    cout << "introduzca el tamano del segundo vector: ";
    cin >> m;

    vector<double> datos2(m);

    cout << "Introduzca datos: ";
    for (int i=0; i<datos2.size(); i++)
        cin >> datos2[i];

    bool contenido=false;

   while(contenido==false){
        for (int j=0; j<datos.size(); j++){
            for (int i=0; i<datos2.size(); i++){
                if(datos[j]==datos2[i] && datos[j+1]==datos[i+1])
                    contenido=true;
            }
        }
   }

return contenido;
}

int main(){
    int n;

    cout << "Introduzca el tamano del vector: ";
    cin >> n;

    vector<double> datos(n);

    cout << "Introduzca datos: ";
    for (int i=0; i<datos.size(); i++)
        cin >> datos[i];

    if (Ordenado(datos)==true)
        cout << "Está ordenado" << endl;
    else cout << "no" << endl;

    Invertir(datos);
    EscribirDatos(datos);

    if (Ordenado(datos)==true)
        cout << "Está ordenado" << endl;
    else cout << "no" << endl;

    if (Contenido(datos)==true)
        cout << "Está contenido" << endl;
    else cout << "no" << endl;

    return 0;
}
