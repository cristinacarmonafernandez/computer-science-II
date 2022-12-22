#include <iostream>
#include<vector>
#include<cmath>

using namespace std;

void Intervalo(int& n, vector<double>& vector){

    while (n<2 || n>20){
        cout << "El tamaño no se encuentra en el rango, introduzca uno nuevo: ";
        cin >> n;
    }
    cout << "Introduzca los valores: " << endl;
    for (int i=0; i<n; i++){
        cin >> vector[i];
    }
}

double Media(int n,vector<double> vector){
    double suma=0;
    for (int i=0; i<n; i++){
        suma=suma+vector[i];
    }
    double media=suma/n;
    return media;
}

double DesviacionMedia(const double& media, const int& n, vector<double> vector){
    double sumadm=0;
    for (int i=0; i<n; i++){
        sumadm=sumadm+abs(vector[i]-media);
    }
    double desvm=sumadm/n;
    return desvm;

}

double Varianza(const double& media, int&n, vector<double> vector){
    double sumav=0;
    for (int i=0; i<n; i++){
        sumav=sumav+(pow(vector[i]-media,2));
    }
    double varianza=sumav/n;
    return varianza;
}

int main()
{
    int tam=2345678;
    vector<double> v(tam);
    cout << "Introduzca el tamano del vector: "<< endl;
    cin >> tam;

    Intervalo(tam, v);
    double media=Media(tam, v);
    cout << "La media es: " << media << endl;
    double desviacionm=DesviacionMedia(media, tam, v);
    cout << "La desviacion media es: " << desviacionm << endl;
    double varianza=Varianza(media, tam, v);
    cout << "La varianza es: " << varianza << endl;

    return 0;
}
