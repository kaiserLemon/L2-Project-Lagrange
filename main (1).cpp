/**

L2 X22I050
Algorithmique Numérique

Travaux pratiques 3
Polynômes d'interpolation de Lagrange

TORRES Andy 486M
FISHER Daniel 486M

**/



#include <iostream>
#include<cmath>
using namespace std;



// La fonction suivante permet de créer un tableau de n+1 points équidistants entre a et b

//Préconditions : a < b et n > 0

double* equidistant(double a, double b, int n) {
  double* tabxk = new double[n+1];
  for(int i = 0; i <= n; i++){
    tabxk[i] = i * (b-a)/n;
  }
  return tabxk;
}



// La fonction f() permet de calculer l'image de x, passé en paramètre, par la fonction f choisie

// Préconditions : x > 0 (cela dépend de la fonction choisie)

double f(double x) {
  return x/sqrt(x);
}

/*
void afficherTab(double* tab, int n){
	for(int i = 0; i < n; i++){
		cout << i+1 << ": " << tab[i]<< endl;
		}
}
*/


// La fonction baseLagrange() construit les polynômes de base de Lagrange en calculant ℓi(x) à partir d'un indice i, un réel x que l'on prend pour réaliser le calcul, le tableau des xk généré par la fonction equidistant() et l'indice n correspondant à l'ordre du polynôme d'interpolation

// Préconditions : i >= 0 et n >= i

double baseLagrange(int i, double x, double* tabxk, int n){
  double resultat;
  resultat = 1;
  for(int j = 0; j <= n; j++){
      if(j != i){
        resultat = resultat * (x-tabxk[j])/(tabxk[i] - tabxk[j]);
      }
  }
  return resultat;
}



// La fonction lagrange() permet de calculer le polynôme interpolateur p(x) à partir d'un entier n, d'un réel x sur lequel on veut réaliser le calcul et du tableau généré par la fonction equidistant()

// Préconditions : n > 1

double lagrange(int n, double x,double* tabxk) {
  double resultat = 0;
  for (int i = 1; i <= n; i++) {
    resultat = resultat + f(tabxk[i]) * baseLagrange(i,x,tabxk,n);
  }
  return resultat;
}



// Test des fonctions précédemment définies dans une fonction applicative

int main() {
  double a, b, x, resultLagrange, resultFunction;
  a = 0;
  b = 1;
  int n = 30;
  x = 0.55;
  double* tabxk = equidistant(a,b,n);
  resultLagrange = lagrange(n,x,tabxk);
  resultFunction = f(x);
  cout.precision(16);
  cout << abs(resultFunction - resultLagrange) << endl;
cout << (abs(resultLagrange - resultFunction)) / abs(resultFunction) * 100 << endl;
}

