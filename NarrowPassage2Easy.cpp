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
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;


class NarrowPassage2Easy {
public:
	int totalsum;
	int counter;
	vector<int> size;
	int count(vector <int> size, int maxSizeSum) {
		this->size=size;
		totalsum=maxSizeSum;
		counter=0;
		vector<int> permute;
		for(int i = 0 ; i< size.size() ;i++){
			permute.push_back(i);
		}
		do{
			if(check(permute))
			counter++;
		}
		while(std::next_permutation(permute.begin(),permute.end()));
		return counter;
	}
	
	bool check(vector<int> permute){
		for(int i = 0 ; i<permute.size() ; i++){
			for(int j=i+1 ; j<permute.size() ; j++){
				if(permute[i]>permute[j] && size[permute[i]]+size[permute[j]]>totalsum)
				return false;
			}
		}
		return true;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	NarrowPassage2Easy *obj;
	int answer;
	obj = new NarrowPassage2Easy();
	clock_t startTime = clock();
	answer = obj->count(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	
	vector <int> p0;
	int p1;
	int p2;
	
	{
	// ----- test 4 -----
	int t0[] = {2,4,6,1,3,5};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 8;
	p2 = 60;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
