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

using namespace std;


class LCMSetEasy {
public:
	string include(vector <int> S, int x) {
		vector<bool> flag(S.size(),false);
		vector<int> factors1;
		vector<int> factors;
		long X=x;
		
		for(int i = 0 ; i < S.size() ;i++){
			if(X%S[i]==0){
				flag[i]=true;
			}
		}
		
		for(int i = 0 ; i<S.size() ;i++)
		if(flag[i])
		factors1.push_back(S[i]);
		
		sort(factors1.begin(),factors1.end());
		
		for(int i = 0 ; i < factors1.size() ; i++){
			int j;
			for(j = i+1 ; j<factors1.size() ;j++)
			if(factors1[j]%factors1[i]==0)
			break;
			if(j==factors1.size()){
			factors.push_back(factors1[i]);
			}
		}
		int limit = (1<<factors.size())-1;
		for(int i = 1 ; i<=limit ; i++){
			vector<long> numbers;
			for(int j = 0 ; j < factors.size() ;j++){
				if((i&(1<<j))!=0){
					numbers.push_back(factors[factors.size()-j-1]);
				}
			}
			
			if(numbers.size()==1)
			if(numbers[0]==X)
			return "Possible";
			
			if(numbers.size()>=2){
				if(findlcm(numbers)==(long long)X)
				return "Possible";
			}
		}
		return "Impossible";
	}
long gcd(long a, long b)
{
    if (b==0)
        return a;
    return gcd(b, a%b);
}
 
// Returns LCM of array elements
long long  findlcm(vector<long> numbers)
{
    // Initialize result
    long long ans = numbers[0];
 
    // ans contains LCM of arr[0],..arr[i]
    // after i'th iteration,
    for (int i=1; i<numbers.size(); i++)
        ans = ( ((numbers[i]*ans)) /
                (gcd(numbers[i], ans)) );
 
    return ans;
}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	LCMSetEasy *obj;
	string answer;
	obj = new LCMSetEasy();
	clock_t startTime = clock();
	answer = obj->include(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	string p2;
	
	{
	// ----- test 6 -----
	int t0[] = {862, 6048, 478, 156, 78, 2321, 23, 113, 697, 5, 7232, 10, 6, 1, 9, 2427, 104, 460, 196, 6599, 4, 3, 129, 9129, 6840, 992, 32, 474, 13, 8642, 8, 6082, 517, 3130, 3416, 368, 5583, 401, 555, 2, 540, 577, 674, 91, 5673};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 779399712;
	p2 = "Possible";
	all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
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
