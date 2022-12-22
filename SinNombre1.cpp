

#include <iostream>

using namespace std;

int main () {


int vector[5]={3, 7, -1, 6, 0}, valor_minimo, valor_maximo, pos_min, pos_max, suma_vectores, numero_vectores;

valor_minimo = 0;

pos_min = 0;

pos_max = 0;

valor_maximo = 0;

suma_vectores = 0;

numero_vectores=0; 


  for (int i=0; i<5; i++){
	
	    if (vector[i] < valor_minimo) {
		
		valor_minimo=vector[i];
		pos_min = i;
		
	   }
	   
  }
	   cout<< "El valor minimo del vector es: "<< valor_minimo << "y se encuentra en la posicion: " << pos_min << endl;
  

   for (int i=0; i<5; i++){
   	
   	     if (vector[i] > valor_maximo) {
   	     	
   	     	valor_maximo=vector[i];
   	     	pos_max = i; 
   	     	
			}
				
   }
		cout<< "El valor maximo del vector es: "<< valor_maximo << "y se encuentra en la posicion: " << pos_max << endl;
   
   
   for (int i=0; i<5; i++){
   	  
   	  suma_vectores= suma_vectores + vector[i];
   	  numero_vectores = i;
   	
   } 
    
    cout<< "La media de los vectores es: "<< suma_vectores/numero_vectores;
   
   
   return 0;
}


