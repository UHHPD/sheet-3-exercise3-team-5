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
}  // end poisson

double prob(std::vector<int> daten, double mu) {
  double p = 1.0;
  for (unsigned int i = 0; i < daten.size(); ++i) {
    p = p * poisson(mu, daten[i]);
  }
  return p;
}  // end prob

double high_prob (std::vector<int> daten) {
  double hp = 1.0;
  for (unsigned int i = 0; i < daten.size(); ++i) {
    hp = hp * poisson(daten[i], daten[i]);
  }
  return hp;
}  // end high_prob

int main() {
    int n_i;
    double a_sum = 0.0, a2_sum = 0.0;
    double mu = 3.11538;
    std::vector<int> daten;
    ifstream fin("datensumme.txt");
    while (fin >> n_i) {
      daten.push_back(n_i);
      a_sum += n_i;
      a2_sum += n_i * n_i;
    }
    fin.close();
    double mean, sigma;
    mean = a_sum / daten.size();
    sigma = sqrt((a2_sum - a_sum * a_sum /  daten.size()) /  daten.size());

    // exercise 2a
    double min_mu = prob(daten, mu);
    cout << "Likelihood of " << daten.size() <<
      " data = " << min_mu << endl;

    // exercise 2b
    double p;
    ofstream ofi1("likelihood.txt");
    for(int j = 0; j <= 60; j++){
      mu = 0.0 + j / 10.0;
      p = prob(daten, mu);
      ofi1 << mu << " " << p << endl;
    }
    ofi1.close();
    // gnuplot: plot "likelihood.txt" using 1:2 with lines

    // exercise 2c
    double log_prob;
    ofstream ofi2("nll.txt");
    for(int j = 0; j <= 60; j++){
      mu = 0.0 + j / 10.0;
      log_prob = -2.0  * log(prob(daten, mu));
      ofi2 << mu << " " << log_prob << endl;
    }
    ofi2.close();
    // gnuplot: plot "nll.txt" using 1:2 with lines 

    // exercise 2d
    ofstream ofi3("deltanll.txt");
    double log_min_mu = -2.0 * log(min_mu);
    for(int j = 0; j <= 100; j++){
      mu = 2.9 + j / 100.0;
      log_prob = -2.0  * log(prob(daten, mu));
      ofi3 << mu << " " << log_prob - log_min_mu << endl;
    }
    ofi3.close();
    // gnuplot: plot [2.95:3.3][] "deltanll.txt" using 1:2 with lines, 1.0
    cout << "mean = " << mean << " sigma = " << sigma << endl;
    
    // exercise 2e
    // Our job for Wednesday result should be 233.942
    double ratio, z;
    int ndof = 233;
    ratio = prob(daten, mu) / high_prob (daten);
    cout << "Ratio = " << ratio << 
      ", log ratio = " << -2.0* log(ratio) << endl;
    z = (-2.0 * log(ratio) - ndof) / sqrt(2.0 * ndof);
    cout << "relative deviation = " << z << endl;
}  // end main
/*
// Sheet 2, Exercise 2a
  while (fin >> a) {
    n += 1;
    a_sum += a;
    a2_sum += a * a;

    if (n % sample_size == 0) { 
      mean = a_sum / sample_size;
      variance = (a2_sum - a_sum * a_sum / sample_size) / sample_size;
      //write into the files after every 9 elements
      fmean << mean <<std::endl;
      fvar << variance <<std::endl;
      sample_count += 1;
      mean_sum += mean;
      var_sum += variance;

      //reset the sums to 0
      a_sum = 0;
      a2_sum = 0;
    }
  };
*/
