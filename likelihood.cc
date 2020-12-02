// // Sheet 3, Exercise 2

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

double poisson(double mu, int k) {
  double p = 0.0;
  p = pow(mu, k) * exp(-1.0 * mu) / tgamma(k + 1.0);
  return p;
}
double prob(std::vector<int> daten, double mu) {
  double p = 1.0;
  for (unsigned int i = 0; i < daten.size(); ++i) {
    p = p * poisson(mu, daten[i]);
  }
  return p;
}
int main() {
    int n_i;
    double mu = 3.11538;
    std::vector<int> daten;
    ifstream fin("datensumme.txt");
    while (fin >> n_i) {
      daten.push_back(n_i);
    }
    fin.close();

    // exercise 2a
    cout << "Likelihood of " << daten.size() <<
      " data = " << prob(daten, mu) << endl;

    // exercise 2b
    double p;
    ofstream ofil("likelihood.txt");
    for(int j = 0; j <= 60; j++){
      mu = j / 10.0;
      p = prob(daten, mu);
      ofil << mu << " " << p << endl;
    }
    ofil.close();

}