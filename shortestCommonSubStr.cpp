/*
Given a random string S and another string T with unique elements, 
find the minimum consecutive sub-string of S such that it contains all the elements in T. 
example: 
S='adobecodebanc' 
T='abc' 
answer='banc'
*/
#include <stdlib.h> 
#include <stdio.h>
#include <algorithm>
#include <map>
#include <list>
#include <iostream>
#include <vector>
using namespace std;
typedef map<char, vector<int> >::iterator mapIterator;
/************************************************************/
int getDistanceLevel(map<char, vector<int>> dic, int level, 
								int& start, int& end, string str) {
  int dist(0);
  vector<int> pivots;
  for(size_t i = 0; i < str.size(); ++i) {
    pivots.push_back((dic[str[i]])[level]);
  }
  sort(pivots.begin(), pivots.end());
  start =  pivots[0];
  end = pivots[pivots.size() - 1];
  dist = end - start;
  return dist;
}
/************************************************************/
void printShortestComonSubString(string src, string target) {
  if(src.empty() || target.empty()) {
    return;
  }
  map<char, vector<int>> dictionary;
  for(size_t i = 0; i < src.size(); ++i) {
    dictionary[src[i]].push_back(i);
  }
  size_t min(src.size());
  for(size_t i = 0; i < target.size(); ++i) { 
    min = dictionary[target[i]].size() < min ? dictionary[target[i]].size() : min;
  }
  if (min == 0) {
    return;
  }
  int minDistance((int)src.size()), start(0), end(0), tmpDist(0);
  for(int i = 0; i < (int)min; ++i) {
    tmpDist = getDistanceLevel(dictionary, i, start, end, target);    
    minDistance = minDistance < tmpDist ?  minDistance : tmpDist;
  }
  //print the substring:
  for(int i = start; i <= end; ++i) {
    cout  << src[i];    
  }
}
/************************************************************/
int main() {
  printShortestComonSubString("adobecodebanc", "abc");
  return 0;
}
