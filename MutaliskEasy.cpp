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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>

using namespace std;

class MutaliskEasy {
public:
	int minimalAttacks(vector <int>);
};

int MutaliskEasy::minimalAttacks(vector <int> x) {
	
	if(x.size()==1)
	return (x[0]%9==0 ? x[0]/9 : x[0]/9 +1);
	if(x.size()==2){
		sort(x.begin(),x.end());
		int count=0;
		while(x[0]>0 || x[1]>0){
			if(x[0]>=x[1])
			sort(x.begin(),x.end());
			x[1]-=9;
			x[0]-=3;
			cout<<x[0]<<" "<<x[1]<<endl;
			count++;
		}
		return count;
	}
	
	queue<int> q;
	int dist[61][61][61];
	memset(dist,-1,sizeof(dist));
	dist[x[0]][x[1]][x[2]]=0;
	q.push(x[0]);
	q.push(x[1]);
	q.push(x[2]);
	while(!q.empty()){
		int x = q.front(); q.pop();
		int y = q.front(); q.pop();
		int z = q.front(); q.pop();
		if(x==0 && y==0 && z==0)
		return dist[x][y][z];
		int arr[3];
		arr[0]=x;
		arr[1]=y;
		arr[2]=z;
		for(int i = 0 ; i< 3 ; i++){
			for(int j = 0 ; j <3 ; j++){
				for(int k = 0 ; k < 3 ; k++){
					if(i==j || j==k || k==i )
					continue;
					int temp1 = (arr[i]>9 ? arr[i]-9 : 0);
					int temp2 = (arr[j]>3 ? arr[j]-3 : 0);
					int temp3 = (arr[k]>1 ? arr[k]-1 : 0);
					if(dist[temp1][temp2][temp3]==-1){
						dist[temp1][temp2][temp3]=dist[x][y][z]+1;
						q.push(temp1);
						q.push(temp2);
						q.push(temp3);
					}
				}
			}
		}
	}
	return 999;
}


double test0() {
	int t0[] = {12,10,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MutaliskEasy * obj = new MutaliskEasy();
	clock_t start = clock();
	int my_answer = obj->minimalAttacks(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
double test1() {
	int t0[] = {54,18,6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MutaliskEasy * obj = new MutaliskEasy();
	clock_t start = clock();
	int my_answer = obj->minimalAttacks(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
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
double test2() {
	int t0[] = {55,60,53};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MutaliskEasy * obj = new MutaliskEasy();
	clock_t start = clock();
	int my_answer = obj->minimalAttacks(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 13;
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
double test3() {
	int t0[] = {1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MutaliskEasy * obj = new MutaliskEasy();
	clock_t start = clock();
	int my_answer = obj->minimalAttacks(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
double test4() {
	int t0[] = {60, 40};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MutaliskEasy * obj = new MutaliskEasy();
	clock_t start = clock();
	int my_answer = obj->minimalAttacks(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 9;
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
double test5() {
	int t0[] = {60};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MutaliskEasy * obj = new MutaliskEasy();
	clock_t start = clock();
	int my_answer = obj->minimalAttacks(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 7;
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
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
