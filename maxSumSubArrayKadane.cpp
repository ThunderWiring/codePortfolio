/* print max sum of a contiguious sub array*/
#include <vector>
#include <iostream>
using namespace std;
/************************************************************/
void maxSubArray(const vector<int>& array) {
  if(array.empty()) {
    return;
  }
  int globalMax(0), currentMax(0);
  for(size_t i = 0; i < array.size(); ++i) {
    currentMax += array[i];
    currentMax = (currentMax <= 0) ? 0 : currentMax;
    globalMax = (currentMax >= globalMax) ? currentMax : globalMax;
  }
  cout << "max sum of sub-array = " << globalMax << endl;
}
/************************************************************/
int main() {
  int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
  vector<int> vec = {arr, arr + sizeof(arr) / sizeof(int)};
  maxSubArray(vec);
  return 0;
}