#include <iostream>
#include <string>


using namespace std;

void Minuscula(string& texto){
    for(int i=0; i<texto.size(); i++)
        texto[i]=tolower(texto[i]);
}

int Busqueda(const string& pequena, string& grande){
    int posicion;
    Minuscula(grande);
    bool coincide=false;
    for (int i=0; i<=grande.size()-pequena.size(); i++){
            if (grande[i]==pequena[0]){
                coincide=true;
                for (int j=0; j<pequena.size(); j++)
                    if (grande[i+j]!=pequena[j]){
                        coincide=false;
                    }
                    if (coincide==true){
                        posicion=i;
                    }
            }
    }
    if (coincide==false)
        posicion=-1;

    return posicion;
}

void Caracter (char car, int posicion, int numero){
    for (int i=0; i<posicion; i++)
        cout << " ";
    for (int j=0; j<numero; j++)
        cout << car;

}

int main()
{
    string palabra;
    string texto;
    char caracter='^';

    cout << "Introduzca la palabra a buscar: ";
    cin >> palabra;

    cout << "Introduzca el texto: ";
    getline (cin, texto);
    for (int i=0; texto[0]!=('#'); i++){
        getline (cin, texto);
        if (Busqueda(palabra,texto)!=-1){
            cout << i+1 << ":" << texto << endl;
            cout << i+1 << ":";
            Caracter(caracter, Busqueda(palabra,texto), palabra.size());
            cout << endl;
        }
    }
return 0;
}
