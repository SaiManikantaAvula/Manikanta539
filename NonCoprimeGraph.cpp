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


class NonCoprimeGraph {
public:
	int distance(int n, int s, int t) {
		if(s==t)
		return 0;
		if(gcd(s,t)>1)
		return 1;
		if(s==1 || t==1)
		return -1;
		long a = minDivisor(s);
		long b = minDivisor(t);
		if(a*b <=n)
		return 2;
		if((2 * max(a,b)) > n)
		return -1;
		return 3;
	}
	
	int minDivisor(int s){
		for(int i = 2 ; i*i<=s ; i++){
			if(s%i==0)
			return i;
		}
		return s;
	}
	
	int gcd(int a,int b){
		if(b==0)
		return a;
		else
		return gcd(b,a%b);
	}
};

