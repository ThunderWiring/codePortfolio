/*
On a given array with X numbers,
find subset of size N (exactly N elements) that equal to SUM.
*/
#include <vector>
#include <iostream>
using namespace std;
bool equalTo_N(vector<int>& numbers, const int& N, const int& SUM) {
  if(numbers.empty()) {
    return ((SUM == 0) && (N == 0));
  }
  vector<int> aggregate(numbers.size());
  for(size_t i = 0; i < numbers.size(); ++i) {
    if(!i) {
      aggregate[i] = numbers[i];
    }
    aggregate[i] = aggregate[i-1] + numbers[i];
  }
  for(int i = N - 1; i < (int)aggregate.size(); ++i) {
    if(i == N - 1 && aggregate[i] == SUM) {
      return true;
    } else if(aggregate[i] - aggregate[i - N] == SUM) {
      return true;
    }
  }
  return false;
}
/************************************************************/
int main() {  
  int arr[] = {1,5,10,12,2,100,2,4,5};
  vector<int> numbs (arr, arr + sizeof(arr)/sizeof(int));
  cout << equalTo_N(numbs, 4, 28);
  return 0;
}
