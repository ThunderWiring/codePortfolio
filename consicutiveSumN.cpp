/*
Given an array of positive integers (excluding zero) and a target number. 
Detect whether there is a set of consecutive elements in the array that add up to the target. 

Example: a = {1, 3, 5, 7, 9} 
target = 8 

output = true ({3, 5}) 

or target = 15 
output = true : {3, 5, 8} 

but if target = 6, output would be false. since 1 and 5 are not next to each other.
*/
#include <stdlib.h> 
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <iostream>
using namespace std;
/************************************************************/
void setBounds (const vector<int>& ele, const int N, int& start, int& end) {
  start = (end == 0) ? 0 : end + 1;
  for(size_t i = start; i < ele.size(); ++i) {
    end = i;
    if(ele[i] >= N) {
      end = i - 1;
      return;
    }
  }  
}
/************************************************************/  
void getConsecutive(const vector<int>& elements, const int N) {
  if((elements.empty() ) || (N <= 0) ||
    (!all_of(elements.begin(), elements.end(), [](int i) {return i >0;})) ) {
    return;
  }  
  int start(0), end(0), sum(0), tmpEnd(0);
  while(start <= end) {
    setBounds(elements, N, start, end);
    tmpEnd = end;    
    for(int i = end; i >= start; --i) {
      sum += elements[i];
      if(sum == N) {
        for (int j = i ; j <= tmpEnd; ++j) {
          cout << elements[j] << " ";
        }
        return;        
      } else if(sum > N) {
        sum -= elements[tmpEnd];
        --tmpEnd;
      }
    }
  }
  cout << "No mach found!";
}
/************************************************************/
int main() {
  int arr[] = {1,3,7,9};  
  vector<int> elements(arr, arr + sizeof(arr) / sizeof(int));
  getConsecutive(elements, 8);
  return 0;
}
