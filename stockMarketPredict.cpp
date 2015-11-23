/*
Given predicted stock prices for next n days for a stock
e.g : 10, 30, 42, 15, 20, 50, 10, 25 
find the maximum profit that can be made with a single buy-sell transaction. 
If no profit can be made return 0. 
In the example buying at 15 and selling at 50 gives maximum profit.
Note that the two prices are neither minimum nor maximum in the array.

Link:http://www.careercup.com/question?id=5180595304923136 

In this solution, time = space = O(n)
*/
#include <stdlib.h> 
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <iostream>
using namespace std;
/************************************************************/
void getMinMax(const vector<int>& stocks, vector<int>& minShare, vector<int>& maxShare) {
  minShare[0] = maxShare[0] = stocks[0];  
  int min(0), max(0);
  for(size_t i = 1; i < stocks.size(); ++i) {
    min = minShare[i - 1] < stocks[i] ? minShare[i - 1] : stocks[i];
    max = maxShare[i - 1] > stocks[i] ? maxShare[i - 1] : stocks[i];
    maxShare[i] = max;
    minShare[i] = min;
  }
}
/************************************************************/
void stockPredict(const vector<int>& stocks) {
  if(stocks.empty()) {
    return;
  }      
  vector<int> maxShare (stocks.size());
  vector<int> minShare (stocks.size());
  vector<int> profitShare (stocks.size() - 1);
  getMinMax(stocks, minShare, maxShare);
  int buy(minShare[0]), sell(maxShare[0]), profit(0);  
  for(size_t i = 1; i < maxShare.size(); ++i) {
    buy = minShare[i - 1];
    sell = maxShare[i] > maxShare[maxShare.size() - 1] ? 
                maxShare[i] : maxShare[maxShare.size() - 1];
    profit = sell - buy;
    profitShare[i] = profit;
  }
  profit = profitShare[0];
  buy = 0;
  sell = maxShare[1] > maxShare[maxShare.size() - 1] ? 
                maxShare[1] : maxShare[maxShare.size() - 1];
  for(size_t i = 0; i < profitShare.size(); ++i) { 
    if(profit < profitShare[i]) {
      buy = minShare[i];      
      sell = maxShare[i + 1] > maxShare[maxShare.size() - 1] ? 
                maxShare[i] : maxShare[maxShare.size() - 1];
      profit = profitShare[i];
    }
  }
  cout << "buy = " << buy << ", sell = " << sell << endl;
}
/************************************************************/
int main() {
  int stocks[]  = {14,9, 10,50,150,45};
  vector<int> predict (stocks, stocks + sizeof(stocks) / sizeof(int));
  stockPredict(predict);
  return 0;
}
