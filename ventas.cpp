#include <iostream>
#include <vector>

using namespace std;

int main(){

    //Introducimos datos
    double datos;
    cin >> datos;

    vector<vector<int> > v;

    while (datos!=-2){
        vector<int> vendedor;
        while (datos>=0){
            vendedor.push_back(datos);
            cin >> datos;
        }
        v.push_back(vendedor);
        cin >> datos;
    }

    for (int j=0; j<v.size(); j++){
        for (int i=0; i<v[j].size(); i++){
            cout << v[j][i]<< " ";
        }
        cout << endl;
    }

    //Hacemos la suma
    vector<int> suma(v.size());

    cout << "Listado de ventas: " << endl;
    for (int j=0; j<suma.size(); j++){
        cout << j+1 << ".-  ";
        suma[j]=0;
        for (int i=0; i<v[j].size(); i++){
            suma[j]=suma[j]+v[j][i];
        }
        cout << suma[j] << " total (" ;
        for (int i=0; i<v[j].size(); i++){
            cout << v[j][i] ;
            if (i<v[j].size()-1)
                cout << "+";
        }
        cout << ")" << endl;
    }

    //Ordenamos el vector según la suma
    vector<int> ordenar(suma.size());

    for (int i=0; i<ordenar.size(); i++)
        ordenar[i]=i;

    for (int i=0; i<ordenar.size()-1; i++){
        int pmin=i;
        for (int j=pmin+1; j<ordenar.size(); j++){
            if (suma[ordenar[j]]>suma[ordenar[pmin]]){
                pmin=j;
                int aux=ordenar[i];
                ordenar[i]=ordenar[pmin];
                ordenar[pmin]=aux;
                j=j-1;
            }
        }
    }

    cout << "Listado ordenado: " << endl;
    for(int i=0; i<ordenar.size(); i++){
        cout << ordenar[i]+1 << ".- " << suma[ordenar[i]] << " total (" ;
        for (int j=0; j<v[ordenar[i]].size(); j++){
            cout << v[ordenar[i]][j];
            if (j<v[ordenar[i]][j]-1)
                cout << "+";
        }
        cout << ")" << endl;
    }


return 0;
}
