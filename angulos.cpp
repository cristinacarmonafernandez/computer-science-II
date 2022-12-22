#include <iostream>

using namespace std;

double RadianesAGrados(double& radian, double& grado){

    const double pi= 3.14159265358979323846;
    grado = (radian*180)/pi;
    return grado;

}

double GradosARadianes(double& grado, double& radian){

    const double pi= 3.14159265358979323846;
    radian = (grado*pi)/180;
    return radian;
}

double Normalizar (double& grado) {

    while (grado>180){
        grado=grado-360;}

    while (grado<-180){
        grado=grado+360;}

    return grado;
}

double SexagesimalADecimal(double& grados, double& minutos, double& segundos, double& angulo){

        angulo = grados + minutos/60 + segundos/3600;
        return angulo;
}

void DecimalASexagesimal (double& angulo){
    int grado=angulo;
    double minuto=(angulo-grado)*60;
    int mn=minuto;
    double segundos=(minuto-mn)*60;
    if (grado<0){
        grado=grado+180;
        cout << "El angulo es(opuesto): " << grado << " g, " << mn << " m, " << segundos << " s.";
    }
    else
    cout << "El angulo es: " << grado << " g, " << mn << " m, " << segundos << " s.";
}


int main()
{
    char opcion;

    cout << "Introduzca una opcion: "<< endl;
    cout << "(r) Radianes" << endl;
    cout << "(d) Grados decimales" << endl;
    cout << "(s) Grados sexagesimales" << endl;
    cin >> opcion;

    switch(opcion){

            case 'R':
            case 'r': {
                double grados, radianes;
                cout << "Introduzca un angulo en radianes: ";
                cin >> radianes;

                RadianesAGrados(radianes, grados);
                cout << "El angulo es: " << radianes << " radianes, en grados: " << grados << endl;
                Normalizar(grados);
                cout << "El angulo normalizado es: " << grados << " grados" << endl;
                DecimalASexagesimal(grados);
                break;
            }

            case 'D':
            case 'd': {
                double grados, radianes;
                cout << "Introduzca un angulo en grados: ";
                cin >> grados;
                    GradosARadianes(grados, radianes);
                    cout << "El angulo es: " << grados << " grados, en radianes: " << radianes << endl;
                    Normalizar(grados);
                    cout << "El angulo normalizado es: " << grados << " grados" << endl;
                    GradosARadianes(grados, radianes);
                    cout << "El angulo es: " << grados << " grados, en radianes: " << radianes << endl;
                    DecimalASexagesimal(grados);
                break;
            }

            case 'S':
            case 's':{
                double gr, minu, sg, angulo, radian;
                cout << "Introduzca los grados: ";
                cin >> gr;
                cout << "los minutos: ";
                cin >> minu;
                cout << "los segundos: " << endl;
                cin >> sg;

                SexagesimalADecimal(gr, minu, sg, angulo);
                cout << "El angulo en decimales es: " << angulo << endl;
                GradosARadianes(angulo, radian);
                cout << "El angulo es: " << angulo << " grados, en radianes: " << radian << endl;
                Normalizar(angulo);
                cout << "El angulo normalizado es: " << angulo << " grados" << endl;
                GradosARadianes(angulo, radian);
                cout << "El angulo es: " << angulo << " grados, en radianes: " << radian << endl;
                DecimalASexagesimal(angulo);
                break;

            }
    }
return 0;
}
