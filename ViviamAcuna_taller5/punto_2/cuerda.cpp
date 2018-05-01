#include <iostream>
#include <math.h>

using namespace std;

void inicializa(double *u_viejo, double *u_masviejo, int nx, double x, double l, double delta_x);
void evolucion(double *u_nuevo, double *u_viejo,double *u_masviejo, double k, double nx);
void imprime (double *u_nuevo, double *u_viejo, double *u_masviejo,int nx, double delta_x, double x, int nume);



int main (){
	//Se muestran los valores de las constantes 
	
	double t = 40.0;
	double rho = 10;
	double l = 100.0;
	double c = pow(t/rho,0.5);
	double delta_x = 0.01;
	double delta_t = 0.0001;
	int nume= 200.0/delta_t;
	double min = 0;
	double max = 1;
	double k = c*c*delta_t*delta_t/(delta_x*delta_x);
	int nx = ((max-min)/delta_x)+1;
	double x = 0;
	

	double *u_nuevo;
	double *u_viejo;
	double *u_masviejo;
	

	u_nuevo = new double[nx];
  	u_viejo = new double[nx];
  	u_masviejo = new double[nx];

	inicializa(u_viejo, u_masviejo, nx, x,l, delta_x);

	int numer= 8.0/10.0;
	int h=1;
	for (int j = 0 ; j < nx ; j++){

		while (u_masviejo[numer]>j){

			u_masviejo[0]=0;
			u_viejo[0]=0;
			u_masviejo[nx-1]=0;
			u_viejo[nx-1]=0;
			evolucion(u_nuevo, u_viejo, u_masviejo, k, nx);

			for (int i = 0; i < nx; ++i){
				u_masviejo[i]=u_viejo[i];
				u_viejo[i]=u_nuevo[i];
			}


		}

		imprime(u_nuevo, u_viejo, u_masviejo, nx, delta_x,x,nume);
		
	}

	return 0;
}
void inicializa(double *u_viejo, double *u_masviejo, int nx, double x, double l, double delta_x){
//Se inicializan los valores de u vijo y mas viejo
	for (int i = 0; i < nx ; ++i){

		if ( x <= 0.8*l){
			u_masviejo[i]= 1.25*x/l;
			u_viejo[i]= 1.25*x/l;

		}
		else {
			u_masviejo[i]= 5.0-5.0*x/l;
			u_viejo[i]= 5.0-5.0*x/l;
		}

		cout << x << " " << u_viejo[i]<<endl;
		x += delta_x;
		
	}

}

void evolucion(double *u_nuevo, double *u_viejo,double *u_masviejo, double k, double nx){
	//Se muestra la evolucion de u viejo
	
	for (int i = 0; i < nx-1; ++i){

		u_nuevo[i]= k*(u_viejo[i+1]+u_viejo[i-1]-2.0*u_viejo[i]) + 2.0* u_viejo[i];


	}

		
	
}

void imprime (double *u_nuevo, double *u_viejo, double *u_masviejo,int nx, double delta_x, double x, int nume){
	
	// Se imprimen los valores
	
	for (int i = 0; i < nx; ++i){
			x = delta_x;
			for (int i = 0; i < 501; ++i){
					cout << x <<" "<< u_nuevo[i]<< endl;
					
			}

			
			
	}
	
}
