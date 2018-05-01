
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std; 


//Se declaran las funciones usadas
double deriva_q1(double p1);

double deriva_p1(double q1);

double deriva_q2(double p2);

double deriva_p2(double q1, double q2);



int main(){

//Se declaran las variables

	double a = 1/(2*pow(2,1/2));

	double q1_n = a;

	double q2_n = -a;

	double p1_n = 0;

	double p2_n = 0;

	double e = pow(10,-3);

	double h = 0.006;

	double t = 3000.0/h;

//Se usa el metodo Runge-Kutta para hallar la solucion a las ecuaciones diferenciales

	for (int i = 0; i < t; ++i){
		
		double k1q1, k2q1, k3q1, k4q1;

		double k1p1, k2p1, k3p1, k4p1;
		
		double k1q2, k2q2, k3q2, k4q2;
		
		double k1p2, k2p2, k3p2, k4p2;

	//Se halla la constante k1

		k1q1=deriva_q1(p1_n);

		k1p1=deriva_p1(q1_n);
		
		k1q2=deriva_q2(p2_n);
		
		k1p2=deriva_p2(q1_n,q2_n);

	//Se halla la constante k2
		k2q1=deriva_q1(p1_n + h/2.0 * k1q1);

		k2p1=deriva_p1(q1_n + h/2.0 * k1p1);

		k2q2=deriva_q2(p2_n + h/2.0 * k1q2);

		k2p2=deriva_p2(q1_n + h/2.0 * k1p1, q2_n + h/2.0 * k1p1);

	//Se halla la constante k3	
		k3q1= deriva_q1(p1_n + h/2.0 * k2q1);

		k3p1=deriva_p1(q1_n + h/2.0 * k2p1);

		k3q2=deriva_q2(p2_n + h/2.0 * k2q2);

		k3p2=deriva_p2(q1_n + h/2.0 * k2p1, q2_n + h/2.0 * k2p1);

	//Se halla la constante k4	
		k4q1= deriva_q1(p1_n  + k3q1* h);

		k4p1=deriva_p1(q1_n + k3p1 * h);

		k4q2=deriva_q2(p2_n + k3q2* h);

		k4p2=deriva_p2(q1_n + k3p1 * h, q2_n + k3p1 * h);

	//Solucion de las ecuaciones
		q1_n += q1_n + (h/6.0 )* (k1q1 + 2.0 * k2q1 + 2.0 * k3q1 + k4q1);

		p1_n += p1_n + (h/6.0) * (k1p1 + 2.0 * k2p1 + 2.0 * k3p1 + k4p1);

		q2_n += q2_n + (h/6.0 )* (k1q2 + 2.0 * k2q2 + 2.0 * k3q2 + k4q2);

		p2_n += p2_n + (h/6.0) * (k1p2 + 2.0 * k2p2 + 2.0 * k3p2 + k4p2);


	// Se imprimen los valores de q2 y p2
		cout << q2_n << " " << p2_n << endl;
	}	
	

	return 0; 


}


double deriva_q1(double p1){

	return p1;
}

double deriva_p1(double q1){

	double e = pow(10.0,-3);

	return - 2.0*q1/(pow(4*q1*q1+e*e,3.0/2.0));

}

double deriva_q2(double p2){

	return p2;
}

double deriva_p2(double q1, double q2){

	double e = pow(10.0,-3);

	double a;

	double b;

	double c;

	double d;

	a = q1 - q2;

	b = q1 + q2;

	c= a/(pow((a*a)+e*e/4.0,3.0/2.0));
	
	d= b/(pow((b*b)+e*e/4.0,3.0/2.0));

	return c - d;

}