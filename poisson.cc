// Sheet 3, Exercise 1

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

double poisson(double mu, int k) {
  double p = 0.0;
  if (k > 1) {
    p = pow(mu, k) * exp(-1.0 * mu) / tgamma(k - 1.0);
  } else {
    p = pow(mu, k) * exp(-1.0 * mu); 
  }
  return p;
}

int main() {
// 1 a)
  using namespace std;
  ifstream fin("datensumme.txt");
  int n_i;
  vector<int> zaehler(11);
  for(int i = 0 ; i < 234 ; ++i) {
    fin >> n_i;
    zaehler[n_i] += 1;
  }
  fin.close();
  for (unsigned int k = 0 ; k < zaehler.size() ; ++k) {
    // cout << k << ": " << zaehler[k] << endl;
  }

// 1 b)
  ofstream fout1("hist.txt");
  for (unsigned int k = 0 ; k < zaehler.size() ; ++k) {
    fout1 << k << " " << zaehler[k] << endl;
  }
  fout1.close();

// 1 c)
  double mu = 3.11538;  
  double p, sum_p = 0.0;
  cout << "mu = " << mu << endl; 
  ofstream fout2("histpoi.txt");
  for (unsigned int k = 0 ; k < zaehler.size() ; ++k) {
    p = 234 * poisson(mu, k);
    sum_p += p;
    fout2 << k << " " << zaehler[k] << " " << p <<  endl;
    cout <<  k << "\t" << zaehler[k] << "\t" << p <<  endl;
  }
  fout2.close();
  cout << "sum_p = " << sum_p << endl; 
}
