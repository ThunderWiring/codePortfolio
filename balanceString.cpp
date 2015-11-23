/*
Balance Parantheses:
"ab(d)c"
"askfjasf"
"ab(cd)ef)g"
   ^  ^  ?
-> "ab(cd)efg" OR "ab(cdef)g"
Remove minimal number of parantheses, so the string is balanced
"()()( ) ((( ( )"
       ^
*/
#include <iostream>
using namespace std;
/**********************************************************************/
int getBalanceCount(const string& str) {
	int count(0);
	for(size_t i = 0; i < str.size(); ++i) {
        if(str[i] == '(' ) {
            count++;
        } else if(str[i] == ')') {
            count--;
        }
    }
	return count;
}
/**********************************************************************/
int setPivot(const string& str, bool parenthess) {
	int pivot(0), count(0);
	char wanted = parenthess ? '(' : ')';
	char unWanted = parenthess ? ')' : '(';
	for(size_t i = 0; i < str.size(); ++i) {
	   if(str[i] == wanted ) {
		   count++;
	   } else if(str[i] == unWanted) {
		   count--;
		   pivot = (count == 0) ? i : pivot;
	   }
   }
   return pivot;
}
/**********************************************************************/
string balanceString(string str) {
    if(str.empty()) {
        return str;
    }
    int count(0), pivot(0);
	count = getBalanceCount(str);
    int tmpCount = count;
    if(count == 0) {
        return str;
    } else {
		pivot = setPivot(str, (count > 0) );
	}
 // balance str:
     size_t strSize = str.size();
    for(int i = pivot; i < (int)strSize ; ++i) {
        if(tmpCount == 0) {
                break;
        } else if(tmpCount < 0) {
            if(str[i] == ')' ) {
                str[i] = '\0';
                tmpCount++;
            }
        } else if(tmpCount > 0) {
            if(str[i] == ')') {
                str[i] = '\0';
                tmpCount--;
            }
        }
    }
    //print balanced str:
    string result = "";
    for(size_t i = 0; i < strSize ; ++i) {
        if(str[i]  != '\0') {
            result += str[i];
        }
    }
    return result;
}
/**********************************************************************/
int main(){
	cout << balanceString("123()())");
    return 0;
}