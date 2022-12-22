#include <iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>

using namespace std;

struct Punto{
    double x;
    double y;
};

struct Circulo{
    Punto centro;
    double radio;
};

struct Rectangulo{
    Punto inf_izq;
    Punto sup_der;
};

double DistanciaPuntos(const Punto& p1, const Punto& p2){
    double dist;
    double p_1=abs(p1.x-p2.x);
    double p_2=abs(p1.y-p2.y);
    dist=sqrt((p_1*p_1) + (p_2*p_2));
    return dist;
}

Punto RectanguloPunto(const Rectangulo& rect){
    Punto aleatorio;

    double u=rand()/(RAND_MAX+1.0);
    aleatorio.x=u*(rect.sup_der.x - rect.inf_izq.x) + rect.inf_izq.x;

    double v=rand()/(RAND_MAX+1.0);
    aleatorio.y=v*(rect.sup_der.y - rect.inf_izq.y) + rect.inf_izq.y;

    return aleatorio;
}

double Minimo(const Punto& p1, const Punto& p2){
    double distancia1, distancia2;

    Punto p_der_inf;
    p_der_inf.x=p1.x;
    p_der_inf.y=p2.y;

    distancia1=DistanciaPuntos(p_der_inf, p1);
    distancia2=DistanciaPuntos(p_der_inf, p2);
    double minimo=distancia2;

    if(distancia1<distancia2)
        minimo=distancia1;

    return minimo;
}

Punto PuntoMedio(const Punto& p1, const Punto&p2){
    Punto pmedio;
    pmedio.x=(p1.x+p2.x)/2;
    pmedio.y=(p1.y+p2.y)/2;

    return pmedio;
}

Circulo RectanguloACirculo(const Rectangulo& rect){
    Circulo cir;
    double diametro=Minimo(rect.sup_der,rect.inf_izq);
    cir.radio=diametro/2;

    cir.centro=PuntoMedio(rect.sup_der,rect.inf_izq);
    return cir;
}

bool CirculoPunto (const Circulo& cir, const Punto& p){
    bool dentro=false;
    double distancia=DistanciaPuntos(cir.centro,p);
    if (distancia<=cir.radio)
        dentro=true;

    return dentro;
}

Rectangulo DePuntoACuadrado(const Punto& p, const double& tam){
    Rectangulo rect;

    rect.sup_der.x=p.x+tam/2;
    rect.sup_der.y=p.y+tam/2;

    rect.inf_izq.x=p.x-tam/2;
    rect.inf_izq.y=p.y-tam/2;

    return rect;
}

int main(){
    Punto pcentral;
    double tam;
    double datos;

    cout << "Introduzca el punto central y un tamano de lado: " << endl;
    cin >> pcentral.x >> pcentral.y >> tam ;
    cout << endl;

    cout << "Cuantos numeros desea lanzar: ";
    cin >> datos;
    while (datos<0){
        cout << "Cuantos numeros desea lanzar: ";
        cin >> datos;
    }
    cout << endl;

    Rectangulo cuadrado=DePuntoACuadrado(pcentral,tam);
    Circulo circ=RectanguloACirculo(cuadrado);

    srand(time(0));
    double suma=0;
    for(int i=0; i<datos; i++){
        Punto punto=RectanguloPunto(cuadrado);
        bool pcirculo=CirculoPunto(circ, punto);
        if(pcirculo==true){
            suma+=1;
        }
    }

    cout.precision(15);
    double pi=(4*suma)/datos;
    cout << "La estimacion de pi es: " << pi;


return 0;
}
