/*
Given an array A = [3, 7, 2,5,6,4] for a number N, 
print the pairs from that array A that sums up to N. 
You should print each pair once.
*/
#include <stdlib.h> 
#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

void printAllPairsSumToN(int arr[], size_t len, int N) {
  if(arr == NULL) {
    return;
  }
  map<int, int> hash;
  for(size_t i = 0; i < len; ++i) {
    hash[arr[i]]++;
  }
  for(size_t i = 0; i < len; ++i) {
    if((arr[i] == N/2) && (hash[N/2] < 2)) {
      continue;
    }
    if(hash[N - arr[i]] > 0) {
      cout << arr[i] << " " << N - arr[i] << endl;
      hash[N - arr[i]]--;
      hash[arr[i]]--;
    }
  }
}
/***********************************************************/
int main() {
  int arr[] = {0,1,2,3,4,5,6};
  printAllPairsSumToN(arr,7, 6);
	return 0;
}