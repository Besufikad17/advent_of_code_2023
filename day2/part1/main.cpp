#include <cstddef>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {

  map<string, int> max_cubes;
  
  // storing the number of cubes for red, blue and green 
  max_cubes["red"] = 12;
  max_cubes["blue"] = 14;
  max_cubes["green"] = 13;

  // loading the input file 
  ifstream inputFile("input.txt");
  string line;
  int sum = 0;

  // reading the input file line by line 
  while(getline(inputFile, line)) {

    // getting the id of each game 
    string prefix = line.substr(0, line.find(':'));
    int id = stoi(prefix.substr(5, prefix.size()));
    
    vector<vector<string>> game;

    string s;
    stringstream ss(line.substr(line.find(':') + 1, line.size()));
    int count = 0, total_count = 0;

    // iterating through each set 
    while (getline(ss, s, ';')) {
      s = s.substr(1, s.size());
      stringstream ss2(s);
      string s2;
      vector<string> sets;

      // iterating and storing each given for specific set 
      while(getline(ss2, s2, ',')) {
        if(s2.at(0) == ' ') {
          s2 = s2.substr(1, s2.size());
        }
        sets.push_back(s2); 
      }

      // storing the total number of givens for specific game 
      total_count += sets.size();
      game.push_back(sets);
    }

    // iterating through each given 
    for(int i = 0; i < game.size(); i++) {
      for(int j = 0; j < game.at(i).size(); j++) {
        string set = game.at(i).at(j);
       
        // extracting the number of cubes and the color for each given
        int n = stoi(set.substr(0, set.find(' ')));
        string color = set.substr(set.find(' ') + 1, set.size());
       
        // checking if the the number of given cubes for each color satisfies the rule
        if(max_cubes[color] >= n) {
          count++;
        }
      }
    }

    // checking if all given cubes satisfy the rule
    if(count == total_count) {
      sum += id;
    }

    count = 0;
    total_count = 0;
  }
  cout<<sum<<endl;
  inputFile.close();
}
