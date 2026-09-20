#include <bits/stdc++.h>
using namespace std;


//  this question is to find the position of a substring in a string.
//  how to do it:-
//  1. take the string and the substring as input.
//  2. use the std::string::find function to get the first occurrence of the substring in the string. If the substring is not found, it will return std::string::npos.  
//  3. print the index of the first occurrence of the substring in the string.
//  4. if the substring is not found, it will return std::string::npos, which is a constant representing the maximum value of size_t. In this case, we will print -1 to indicate that the substring was not found.
//  5. finally, print the result index.
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