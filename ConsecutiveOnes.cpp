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
#include <climits>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class ConsecutiveOnes {
public:
	long long get(long long n, int k) {
		int count=0;
		int digits=ceil(log2(n));
		for(int i = 0 ; i<digits ; i++){
			if((n & (1ll<<i)) !=0)
			count++;
			if(count==k)
			return n;
			if( (n & (1ll<<i)) ==0)
			count=0;
		}
		if(digits<=k)
		{
			return (1ll<<k)-1;
		}
		else{
			long long  ans = LLONG_MAX;
			for(int i = 0 ; i<=digits-k ; i++){
				
				long long temp = n;
				temp &=((1ll<<(digits-i))-1)<<i;
				long long temp3 = (1ll<<(i+k))-1;
				long long temp4 = (1ll<<i)-1;
				temp3 =temp3-temp4;
				temp = (temp | temp3); 
				
				if(temp<ans && temp>=n)
				ans=temp;
				
			}
			return ans;
		}
	}
};


