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

using namespace std;

class ProblemSetsEasy {
public:
	int maxSets(int, int, int, int, int);
	int func(int E,int EM,int M,int MH,int H,int mid);
};

int ProblemSetsEasy::maxSets(int E, int EM, int M, int MH, int H) {
	int total = min(E,min(M,H));
	int E1=E-total;
	int M1=M-total;
	int H1=H-total;
	int low = 0, high = MH+H1+1;
	while(low<=high){
		int mid = low + (high-low)/2;
		if(func(E1,EM,M1,MH,H1,mid))
		low=mid+1;
		else
		high=mid-1;
	}
	if(low-1==-1)
	return total;
	else
	return total+low-1;
}

int ProblemSetsEasy::func(int E,int EM,int M,int MH,int H,int mid){
	if(mid > EM+E || mid > H+MH || mid > M+MH+EM)
	return 0;
	int x = mid > E ? mid-E : 0;
	int y = mid > H ? mid-H : 0;
	int M1 = M+(EM-x)+(MH-y);
	if(M1 >=mid)
	return 1;
	else
	return 0;
}

double test0() {
	int p0 = 2;
	int p1 = 2;
	int p2 = 1;
	int p3 = 2;
	int p4 = 2;
	ProblemSetsEasy * obj = new ProblemSetsEasy();
	clock_t start = clock();
	int my_answer = obj->maxSets(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 100;
	int p1 = 100;
	int p2 = 100;
	int p3 = 0;
	int p4 = 0;
	ProblemSetsEasy * obj = new ProblemSetsEasy();
	clock_t start = clock();
	int my_answer = obj->maxSets(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 657;
	int p1 = 657;
	int p2 = 657;
	int p3 = 657;
	int p4 = 657;
	ProblemSetsEasy * obj = new ProblemSetsEasy();
	clock_t start = clock();
	int my_answer = obj->maxSets(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 1095;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 1;
	int p1 = 2;
	int p2 = 3;
	int p3 = 4;
	int p4 = 5;
	ProblemSetsEasy * obj = new ProblemSetsEasy();
	clock_t start = clock();
	int my_answer = obj->maxSets(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 100000;
	int p1 = 100000;
	int p2 = 100000;
	int p3 = 100000;
	int p4 = 100000;
	ProblemSetsEasy * obj = new ProblemSetsEasy();
	clock_t start = clock();
	int my_answer = obj->maxSets(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 166666;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
