#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void printPredicate(char c) { 
	cout << c;
}
/************************************************************/
//wrapper method for the recursion
void aux_printVariations(vector<int>& group, int i) {
  static vector<char> buffer;
  if(i >= (int)group.size()) {
    for_each(buffer.begin(), buffer.end(), printPredicate);
    cout << endl;
    return;
  }
  buffer.push_back('0'+group[i]);
  buffer.push_back(',');
  aux_printVariations(group, (i + 1));
  buffer.pop_back();
  buffer.pop_back();
  buffer.push_back('0'+ group[i]);
  aux_printVariations(group, (i + 1));
  buffer.pop_back();
}
void printVariations(vector<int>& group) {
  if(group.empty()) {
    return;
  }
  aux_printVariations(group, 0);
}
/************************************************************/
int main() {
  int arr[] = {1,2,3,4};
  vector<int> vec = {arr, arr + sizeof(arr) / sizeof(int)};
  printVariations(vec);
  return 0;
}
