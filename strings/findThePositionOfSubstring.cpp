#include <bits/stdc++.h>
using namespace std;

// program entry point
int main() {
  // define the text
  string text = "takeuforward";
  // define the pattern
  string pattern = "forward";
  // use std::string::find to get first occurrence (or npos)
  size_t foundIdx = text.find(pattern);
  // print the result index
  cout << "The substring starts from the index: " << foundIdx << endl;
  // exit
  return 0;
}