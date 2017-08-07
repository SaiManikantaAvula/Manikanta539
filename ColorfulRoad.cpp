#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#define red 'R'
#define green 'G'
#define blue 'B'
using namespace std;


class ColorfulRoad {
public:
	int getMin(string road) {
		int length = road.size();
		int dp[length];
		dp[length-1]=0;
		for(int i=length-2 ; i>=0 ;i--){
			int dist = 100000;
			if(road[i]==red){
				for(int j = i+1 ; j<length ;j++){
					if(road[j]==green){
						int temp = (j-i)*(j-i)+dp[j];
						if(temp < dist)
						dist=temp;
					}
				}
			}
			else if(road[i]==green){
				for(int j = i+1 ; j<length ;j++){
					if(road[j]==blue){
						int temp = (j-i)*(j-i)+dp[j];
						if(temp < dist)
						dist=temp;
					}
				}
			}
			else{
				for(int j = i+1 ; j<length ;j++){
					if(road[j]==red){
						int temp = (j-i)*(j-i)+dp[j];
						if(temp < dist)
						dist=temp;
					}
				}
			}
			dp[i]=dist;
		}
		if(dp[0]>=100000)
		return -1;
		else
		return dp[0];
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	ColorfulRoad *obj;
	int answer;
	obj = new ColorfulRoad();
	clock_t startTime = clock();
	answer = obj->getMin(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	string p0;
	int p1;
	
	{
	// ----- test 0 -----
	p0 = "RGGGB";
	p1 = 8;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "RGBRGBRGB";
	p1 = 8;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "RBBGGGRR";
	p1 = -1;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "RBRRBGGGBBBBR";
	p1 = 50;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "RG";
	p1 = 1;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "RBRGBGBGGBGRGGG";
	p1 = 52;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
