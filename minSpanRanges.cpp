/*
Given a set of ranges: 
(e.g. S = {(1, 4), (30, 40), (20, 91) ,(8, 10), (6, 7), (3, 9), (9, 12), (11, 14)}. 
And given a target range R (e.g. R = (3, 13) - meaning the range going from 3 to 13).
Write an algorithm to find the smallest set of ranges that covers your target range.

All of the ranges in the set must overlap in order to be considered as spanning the entire target range. 
(In this example, the answer would be {(3, 9), (9, 12), (11, 14)}.

NOTE: in this solution, i returned the min set of ranges that covers MOST of the target range.
in case you want to cover ALL of the target reange,
change the halting condition in the recursion method 'getFitRange' into:
if((start->first > target.first) || !(start != end)) {return;}
*/
#include <stdlib.h> 
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <iostream>
using namespace std;
typedef pair<int, int> Range;
typedef vector<Range>::const_iterator RangeIterator;
/************************************************************/
void getFitRange(Range target, vector<Range>& span,  
                 RangeIterator start, RangeIterator end) {
  if((start->first > target.second) || !(start != end)) {
    return;
  }
  Range fit = *start++;  
  int minDelta(fit.first), delta(0);
  for(; start != end; ++start) {
    delta = target.first - start->first;
    if(delta < 0) {      
      break;
    } else if(delta < minDelta) {
      minDelta = delta;
      fit = *start;
    }
  }
  span.push_back(fit);  
  target.first = fit.second;  
  getFitRange(target, span, start, end);
}
/************************************************************/
vector<Range> getMinSpan(vector<Range>& ranges, Range target) {
  if(ranges.empty()) {
    return ranges;
  }
  sort(ranges.begin(), ranges.end());
  vector<Range> span;
  getFitRange(target, span,  ranges.begin(), ranges.end()); 
  
  cout << "spanning ranges are: " << endl;
  for(RangeIterator it = span.begin(); it != span.end(); ++it) {
    cout << it->first << ", " << it->second << endl;
  }
  return span;
}
/************************************************************/
int main() {
  Range r;
  vector<Range> ranges;
  r = make_pair(1,4);
  ranges.push_back(r);  
  r = make_pair(30,40);
  ranges.push_back(r);  
  r = make_pair(20,91);
  ranges.push_back(r); 
  r = make_pair(8,10);
  ranges.push_back(r);  
  r = make_pair(6,7);
  ranges.push_back(r);  
  r = make_pair(3,9);
  ranges.push_back(r);  
  r = make_pair(9,12);
  ranges.push_back(r);  
  r = make_pair(11,14);
  ranges.push_back(r);  
  r = make_pair(3,13);
  getMinSpan(ranges, r);
  return 0;
}
