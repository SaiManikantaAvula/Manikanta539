#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class OrderOfOperationsDiv2 {
public:
	int minTime(vector <string>);
	int dp[1048600];
	int calculate(int bitmasks);
	vector<string> str;
	int total,m,n;
};

int OrderOfOperationsDiv2::minTime(vector <string> s) {
	str=s;
	m=s[0].size();
	n=s.size();
	total = (1<<s[0].size())-1;
	memset(dp,-1,sizeof(dp));
	int result = calculate(0);
	return result;
}

int OrderOfOperationsDiv2::calculate(int bitmasks){
	if(bitmasks==total)
	return 0;
	if(dp[bitmasks]!=-1)
	return dp[bitmasks];
	int minimum = 9999;
	for(int i = 0 ; i <n ;i++){
		int tempmasks=bitmasks;
		int counter = 0;
		for(int j = 0 ; j < m ; j++){
			if((tempmasks & (1<<j))==0 && str[i][m-j-1]=='1')
			{
				tempmasks=(tempmasks|(1<<j));
				counter++;
			}
		}
		if(tempmasks!=bitmasks)
		minimum=min(minimum,(int)pow(counter,2)+calculate(tempmasks));
	}
	if(minimum==9999)
	return dp[bitmasks]=0;
	else
	return dp[bitmasks]=minimum;
}


double test0() {
	string t0[] = {
"01000100000000001101", "00000000000000010001", "00000000000000000010", "01100000010000000000", "00000010000100110000", "00010101000001000000", "00000010010000010000", "00010010000001000000", "10000000000000000000", "00001011001001010001", "00000000000111000000", "00101001000000000010", "01000000000001100000", "00101001000100000000", "01100101100010000000", "00000100000101011110", "00010001000001001011", "00100000100000010100", "00000100000010000010", "00000000010010000000"
};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	OrderOfOperationsDiv2 * obj = new OrderOfOperationsDiv2();
	clock_t start = clock();
	int my_answer = obj->minTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();

	
}

//Powered by [KawigiEdit] 2.0!
