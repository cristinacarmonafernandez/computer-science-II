#include <iostream>
#include <string>
#include<vector>

using namespace std;

void Minuscula(string&palabra)
{
    for(int i=0; i<palabra.size(); i++)
    {
        palabra[i]=tolower(palabra[i]);
    }
}

void OrdenarAscii(vector<string>&diccionario)
{
    for (int i=0; i < (int)diccionario.size()-1; i++)
    {
        int pmin= i;
        for ( int j=pmin+1; j< (int)diccionario.size(); j++)
            if ( diccionario[j]< diccionario[pmin])
                pmin= j;
        string aux= diccionario[i];
        diccionario[i]= diccionario[pmin];
        diccionario[pmin]= aux;
    }
}

bool LineaVacia(const string&p){
    bool vacia=true;
    for(int i=0; i<p.size()&& vacia==true; i++){
        if(!isspace(p[i])){
            vacia=false;
        }
    }

return vacia;
}
int Posicion(string&p, int&pos){
    while(isalpha(p[pos])==false && pos<p.size()){
        pos++;
    }
    return pos;
}

int TamPalabra(const string&p,int pos){
    bool espacio=false;
    int tam;
    for(int i=pos; i<p.size()-1&&espacio==false; i++){
        if(isspace(p[i])){
            espacio=true;
            tam=i-pos;
            pos=i;
        }
    }
    return tam;
}

vector<string> Vectorlinea(string p){
    vector<string> lineas(0);
    int cont=0,pos=0,tam;

   while(pos<(int)p.size()){
        string aux;
        pos=Posicion(p,pos);
        tam=TamPalabra(p,pos);
        lineas.push_back(aux);
        for(int i=pos; i<pos+tam; i++){
            lineas[cont].push_back(p[i]);
        }
        pos=pos+tam;
        cont++;
   }
    return lineas;
}
int Buscarpalabra(vector<string> diccionario, string palabra)
{
    bool encontrado=false;
    int izq=0, dcha=(int)diccionario.size()-1, mitad;

    while(izq<=dcha&&encontrado==false){
        mitad=(izq+dcha)/2;
        if (diccionario[mitad]>palabra){
            dcha=mitad-1;
        }
        else if (diccionario[mitad]<palabra){
            izq=mitad+1;
        }
        else if(diccionario[mitad]==palabra){
            encontrado=true;
        }

    }

    return encontrado ? mitad : -1;
}
bool Repetidos(vector<string> diccionario){
    bool Repetido=false;
    for(int i=0; i<diccionario.size()-1; i++){
        if(diccionario[i]==diccionario[i+1]){
            Repetido=true;
        }
    }
    return Repetido;
}
bool Palabra(string palabra){
    bool espalabra=true;
    for(int i=0; i<palabra.size(); i++)
        if(isalpha(palabra[i])==false&&espalabra==true){
            espalabra=false;
        }


    return espalabra;

}
bool LeerDiccionario(string&palabra, vector<string>&diccionario){
    bool apto=true, espalabra=true;
    int n;
    do{
        cout<<"Introduce el numero de palabras del diccionario ";
        cin>>n;
    }
    while(n<0);
    cout<<"Introduce las palabras del diccionario "<<endl;
    for(int i=0; i<n &&espalabra==true; i++){
        cin>>palabra;
        Minuscula(palabra);
        espalabra=Palabra(palabra);
        diccionario.push_back(palabra);

    }
    OrdenarAscii(diccionario);
    bool prepetida=Repetidos(diccionario);
    if(prepetida==true || espalabra==false)
    {
        apto=false;
    }
    return apto;
}

int ProcesarTexto(const vector<string>&diccionario,vector<int>&contador, int&ptexto)
{
    string p ;
    cout<<"Introduce el texto "<<endl;
    int lineastexto=0,posicion;
    do{
        getline(cin,p);
        Minuscula(p);
        bool vacia=LineaVacia(p);
       if(vacia==false){
            vector<string>lineas;
            lineas=Vectorlinea(p);
            ptexto=ptexto+lineas.size();
            for(int i=0; i<lineas.size(); i++){
                posicion=Buscarpalabra(diccionario,lineas[i]);
                if(posicion>-1){
                    contador[posicion]++;
                }

            }
        }
        lineastexto++;
    }
    while(p[0]!='#');
    return lineastexto;
}

void OrdenarFrecuencia(vector<string>&diccionario,vector<int>&contador)
{
    for (int i=0; i < (int)contador.size()-1; i++)
    {
        int pmin= i;
        for ( int j=pmin+1; j< (int)contador.size(); j++)
        {
            if ( contador[j]> contador[pmin])
            {
                pmin= j;
                double aux= contador[i];
                contador[i]= contador[pmin];
                contador[pmin]= aux;
                string aux1=diccionario[i];
                diccionario[i]=diccionario[pmin];
                diccionario[pmin]=aux1;
            }
        }
    }
}

void Escritura(vector<string>&diccionario,int ptexto,int ltexto,vector<int>contador )
{
    int d=0;
    for(int i=0; i<contador.size(); i++)
    {
        d=d+contador[i];

    }
    cout<<"Numero de palabras del diccionario: "<<diccionario.size()<<endl;
    cout<<"Numero de palabras del texto: "<<ptexto<<endl;
    cout<<"Numero de lineas del texto: "<<ltexto<<endl;
    cout<<"Numero de palabras del texto que estan en el diccionario: "<<d<<endl;
    for(int i=0; i<contador.size(); i++)
    {
        cout<<i+1<<"."<<diccionario[i]<<":"<<endl<<"Frecuencia con la que aparece en el texto: "<<contador[i]<<endl<<
            "Porcentaje con respecto al numero de palabras del texto que estan en el diccionario: "<<contador[i]/d<<endl<<
            "Porcentaje con respecto al numero total de palabras del texto: "<<contador[i]/ptexto<<endl;
    }
    cout<<"Palabras del diccionario ordenadas de la mas frecuente a la menos frecuente en el texto: "<<endl;

    OrdenarFrecuencia(diccionario,contador);
    for(int i=0; i<diccionario.size(); i++)
    {
        cout<<i+1<<"."<<diccionario[i]<<" con frecuencia: "<<contador[i]<<endl;
    }

}


int main()
{
    string palabra;
    vector<string> diccionario;

    bool apto=LeerDiccionario(palabra,diccionario);
    if(apto==true)
    {
        int ptexto=0;
        vector<int> contador(diccionario.size());
        int ltexto=ProcesarTexto(diccionario,contador,ptexto);
        Escritura(diccionario,ptexto,ltexto,contador);

    }

    else
    {
        cout<<"No es posible cargar el diccionario";
    }

}

