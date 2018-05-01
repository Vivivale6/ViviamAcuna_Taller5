#include <iostream>
#include <math.h>

using namespace std;

void inicializa(int b , double **matriz_V, double d, float h, double l, double L, double vo);
void inicializa_campo(int b, double **matriz_Ex, double **matriz_Ey);
void evoluciona(int b , double **matriz_V, double **matriz_Vviejo, double w);
void actualiza(int b , double **matriz_V, double **matriz_Vviejo);
void campo_electrico(double **matriz_Ex, double **matriz_Ey, double **matriz_V, int b, double h );
//void imprime(int b, float **valores);




int main(){

	double L = 5.0;

	double l = 2.0;

	double d = 1.0;

	double h = 5.0/512.0;

	double vo = 100.0;

	int b = L/h;

	int N = 2.0 * (b)*(b);

	double w = 1.1;

// Se hacen las matrices con los punteros 
	double **matriz_V;
	double **matriz_Vviejo;

	double **matriz_Ex;
	double **matriz_Ey;

	matriz_V = new double *[b];
	matriz_Vviejo = new double *[b];

	matriz_Ex = new double *[b-2];
	matriz_Ey = new double *[b-2];



	for (int i = 0; i < b; ++i){

		matriz_V[i]= new double[b];
		matriz_Vviejo[i]= new double[b];
	}	

	for (int i = 0; i < b-2.0 ; ++i){

		matriz_Ex[i]= new double[b-2];
		matriz_Ey[i]= new double[b-2];
		
	}

		


	


	// Se inicializa la matriz del potencial
	

	inicializa_campo(b,matriz_Ex, matriz_Ey);
	
	for (int i = 0; i < 100; ++i){

		inicializa(b , matriz_V , d, h, l, L, vo);
		evoluciona(b , matriz_V, matriz_Vviejo, w);	
		actualiza(b , matriz_V, matriz_Vviejo);

	}
	
	campo_electrico(matriz_Ex, matriz_Ey, matriz_V,b, h );

	

	

	return 0;

}	

void inicializa(int b , double **matriz_V , double d, float h, double l, double L, double vo){
// Se inicializan los valores con las condiciones inicales dadas
	double v= L-d;
	double w= L+d;
	double c= L-l;
	double n= c/(2*h);
	double q= (c+2*l)/2*h;
	int h1= v/(2*h); 
	int h2 = w /(2*h);

	for (int i = n ; i < q ; ++i){
		for (int j = h2 ; j < q; ++j){

			matriz_V[i][j]= vo/2.0;
		}
	}	
		
	for (int i = n ; i < q ; ++i){
		for (int j = h1 ; j < q; ++j){

			matriz_V[i][j]= -1.0*vo/2.0; 
		}
		
	}

}

void inicializa_campo(int b, double **matriz_Ex, double **matriz_Ey){
	for (int i = 0; i < b-2.0  ; ++i){
		for (int j = 0; j < b-2.0 ; ++j){
			matriz_Ex[i][j]=0;
			matriz_Ey[i][j]=0;
		}
	}
}

void evoluciona(int b , double **matriz_V, double **matriz_Vviejo, double w){
	for (int i = 1; i < b-1; ++i){
		for (int j = 1 ; j < b-1; ++j){
			
			double a;
			double ru;

			a = (matriz_Vviejo[i+1][j] + matriz_Vviejo[i][j+1] + matriz_V[i-1][j] + matriz_V[i][j-1])/4;
			ru = a- matriz_Vviejo[i][j];

			matriz_V[i][j]= matriz_Vviejo[i][j] + w*ru;
		}

		
	}

}	

void actualiza(int b , double **matriz_V, double **matriz_Vviejo){
	for (int i = 0; i < b; ++i){
		for (int j = 0; j < b; ++j){

			matriz_Vviejo[i][j]=matriz_V[i][j];
			
		}
		
	}

}

void campo_electrico(double **matriz_Ex, double **matriz_Ey, double **matriz_V, int b, double h ){

	double a = 2*h;
	for (int i = 1 ; i < b-2.0; ++i){
		for (int j = 0; j < b-2.0; ++j){

			matriz_Ex[i][j]= (matriz_V[i-1][j]-matriz_V[i+1][j])/a;
			matriz_Ey[i][j]= (matriz_V[i][j+1]-matriz_V[i][j-1])/a;

			cout << matriz_V[i][j]<< " " << matriz_Ey[i][j]<< " "<< matriz_Ex[i][j] << endl;
		}
	}

}












