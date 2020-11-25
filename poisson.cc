// Sheer 3 Exercise 1

#include <iostream>
#include <fstream>
#include <vector>

double poisson(double mu, int k) {
    return 0;
}

int main() {
    using namespace std;
    int n_i;
    vector<int> zaehler(11);

    // 1 a)
    ifstream fin("datensumme.txt");
    for(int i = 0 ; i < 234 ; ++i) {
      fin >> n_i;
      zaehler[n_i] += 1;
    }
    fin.close();
    for (unsigned int k = 0 ; k < zaehler.size() ; ++k) {
      cout << k << ":" << zaehler [ k ] << endl ;
    }

    // 1 b)
    ofstream fout1("hist.txt");
    for (unsigned int k = 0 ; k < zaehler.size() ; ++k) {
      fout1 << k << " " << zaehler[k] << endl;
    }
    fout1.close();
}