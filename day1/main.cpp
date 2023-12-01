#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  // loading the input file
  ifstream inputFile("input.txt");

  string line;
  int sum = 0;

  // reading input file line by line
  while(getline(inputFile, line)) {
    int calibration_val = 0;
    vector<int> numbs;

    // iterating through each character for every line in the input file 
    for(int i = 0; i < line.length(); i++) {
      
      // checking if the character at the current index is digit or not
      if(isdigit(line[i])) {

        // storing the digits 
        numbs.push_back(line[i] - '0'); 
      }
    }

    // calculating calibration by getting the first and the last digit
    calibration_val = (numbs.at(0) * 10) + (numbs.at(numbs.size() - 1));

    // adding the current calibration to the others 
    sum += calibration_val; 
  }
  inputFile.close();
  cout<<sum<<endl;
}
