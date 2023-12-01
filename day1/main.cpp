#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream inputFile("input.txt");

  string line;
  int sum = 0;
  while(getline(inputFile, line)) {
    int calibration_val = 0;
    vector<int> numbs;
    for(int i = 0; i < line.length(); i++) {
      if(isdigit(line[i])) {
        numbs.push_back(line[i] - '0'); 
      }
    }
    calibration_val = (numbs.at(0) * 10) + (numbs.at(numbs.size() - 1));
    sum += calibration_val; 
  }
  inputFile.close();
  cout<<sum<<endl;
}
