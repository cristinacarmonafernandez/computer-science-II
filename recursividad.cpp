#include <iostream>

using namespace std;

void Funcion(int numero, int exponente){
    for(int i=0; i<exponente/2; i++){
        numero=numero*numero;
    }

    Funcion(numero, exponente);

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
