#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
using namespace std;

int main(){
  const int bits = 12; //12 bit input
  vector<bitset<bits>> diagnostics;
  ifstream fin("text.txt");
  string line;
  while(fin >> line) {
	diagnostics.push_back(bitset<bits>(line));
  }

  bitset<bits> gamma_rate, epsilon_rate;
  for(int i = bits-1; i >= 0; i--){
	int counts[2] {0,0};
	for(auto diagnostic : diagnostics){
		counts[diagnostic[i]]++;
	}
	gamma_rate[i] = counts[0] > counts[1] ? 0 : 1;
  }
  epsilon_rate = bitset<bits>(gamma_rate).flip(); //bitset flip zeros to ones and ones to zeros
	
  cout << "Gamma : " << gamma_rate.to_ulong() << endl; //member function to unsigned long
  cout << "Epsilon : " << epsilon_rate.to_ulong() << endl;
  cout << "Power Consumption : " << gamma_rate.to_ulong()*epsilon_rate.to_ulong() << endl;
}