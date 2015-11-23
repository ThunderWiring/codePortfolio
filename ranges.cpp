/*
Given an array of "array range", return an optimized array by deleting subarrays. 
NOTE: Array range (2,6) represents (2,3,4,5,6) 
INPUT: [(2,6),(3,5),(7,21),(20,21)] 
OUTPUT: [(2,6),(7,21)] 
Reason: (3,5) is a subarray of (2,6) and (20,21) is a subarray of (7,21)
*/
#include <stdlib.h> 
#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<int, int> Range;
/************************************************************/
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
/************************************************************/
//auxilary function.
//return true if r2 is contained in r1
bool isContained(Range r1, Range r2) {
    return (r1.first <= r2.first) && (r1.second >= r2.second);
}
/************************************************************/
void getMaxRange(Range& max, const vector<Range> ranges) {
  max = ranges[0];
  for(size_t i = 0; i < ranges.size(); ++i) {
    max = (isContained(ranges[i] ,max)) ? ranges[i] : max;
  }  
}
/************************************************************/
void printOptimalRanges(vector<Range>& ranges) {
  if(ranges.empty()) {
    return;
  }  
  sort(ranges.begin(), ranges.end());  
  Range current, previous, max;
  getMaxRange(max, ranges);
  for(size_t i = 1; i < ranges.size(); ++i) {
    current = ranges[i];
    previous = ranges[i-1];
    if(isContained(max, current) && isContained(max, previous)) {
      continue;
    } else if(!isContained(previous, current)) {
      cout  << current.first << " " << current.second << endl;
    }
  }
  cout << max.first << " " << max.second << endl;
}
/************************************************************/
int main() {
  vector<Range> ranges;
  Range r = make_pair(2,6);
  ranges.push_back(r);
  r = make_pair(1,21);
  ranges.push_back(r);
  r = make_pair(3,5);
  ranges.push_back(r);
  r = make_pair(20,21);
  ranges.push_back(r);
  r = make_pair(1,40);
  ranges.push_back(r);
  printOptimalRanges(ranges);
  return 0;
}
