/*
We have an array of objects A and an array of indexes B. 
Reorder objects in array A with given indexes in array B. 
Do not change array A's length. 
http://www.careercup.com/question?id=5756151524229120
example:
var A = [C, D, E, F, G];
var B = [3, 0, 4, 1, 2];
sort(A, B);
A is now [D, F, G, C, E];
*/
#include <stdlib.h> 
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <iostream>
using namespace std;
 
void swap(vector<char>& values, const int i, const int j) {
  char tmp = values[i];
  values[i] = values[j];
  values[j] = tmp;
}
/************************************************************/
void reorder(vector<char> values,  vector<int> order) {
  if(values.empty() || order.empty()) {
    return;
  }
  for(size_t i = 0; i < order.size(); ++i) {
    if (order[i] != (int)i) {
      swap(values, i, order[i]);      
      int tmp = order[i];
      order[i] = i;
      order[tmp] = tmp;
    } 
  }
  cout <<"values: " <<endl;
  for(size_t i = 0; i < values.size(); ++i) {
    cout << values[i] << " ";    
  }
  for(size_t i = 0; i < values.size(); ++i) {
    cout << order[i] << " ";    
  }
}
/************************************************************/
int main() {   // 0    1    2    3    4   5   6   7
  char arr[] =  {'c', 'd', 'e', 'f', 'g','x','y','z'};
  int order[] = { 1,   6,   4,   3,   7,  0  ,2,  5 };
  vector<char> values (arr, arr + sizeof(arr) / sizeof(char));
  vector<int> ordr (order, order + sizeof(order) / sizeof(int));
  reorder(values, ordr);
  
  return 0;
}
