// Este programa va a pedirle al usuario un numero y una opcion, entre factorial, exponencial, logaritmo nepriano y salida

#include <iostream>
#include <cmath>
using namespace std;

int main () {
	
	double x, fact, i;
    char opcion;
    bool continuar_menu;

	
    cout << "Introduce un numero: " << endl;
    cin >> x;
    
    continuar_menu = true;
    
    while (continuar_menu) {
    	
    	cout << "Elige una opcion: " << endl;
    	cout << "Factorial (f): " <<endl;
    	cout << "Exponencial (e): " <<endl;
    	cout << "Logaritmo neperiano (l): " << endl;
    	cout << "Salida (s): " << endl;
    	cin >> opcion;
    	
    	switch (opcion) {
    		
    		case 'F':
    		case 'f': {
    			cout << "Elegida opcion factorial..."<< endl;
    			fact=1;
    			if (x<0){
    				fact=0;
    			}
    			else if(x==0){
    				fact=1;
				}
				else{
					for(i=1;i<=x; i++){
						fact=fact*i;
					}
				
			}
    			
    		cout<< "El factorial es: "<<  fact<<endl;	
				break;
			}
    	
    		
    		case 'E':
    		case 'e': {
    			 cout<< "Elegida opcion exponencial..." << endl;
    			 cout << "El resultado es: " << exp(x);
    			
				break;
			}
			
			
			case 'L':
			case 'l': {
				
				if (x>0) {
				
				cout << "Elegida la opcion logaritmo neperiano... " << endl;
				cout << "El restultado es" << log(x) << endl;
				
			}
			
				else
				cout << "OPCION NO VALIDA";
				
				break;
			}
			
			case 'S':
			case 's': {
				cout << "Elegida la opcion salida..." << endl;
				continuar_menu= false;
								
				break;
			}
			
			default: {
                cout << "OPCION NO VALIDA" << endl;
             
                break;
				
    	 	}
    	
   	}
	
	cout << endl << "Fin del programa" << endl;
}
	return 0;
}
