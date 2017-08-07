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

class PublicTransit {
public:
	int minimumLongestDistance(int, int);
};

int PublicTransit::minimumLongestDistance(int R, int C) {
	
	int minmaxdist=9999;
	for(int a = 0 ; a < R*C ; a++){
		for(int b = 0 ; b< R*C ; b++){
			int tx1 = (a/C) ; int ty1 = (a%C);
			int tx2 = (b/C) ; int ty2 = (b%C);
			
			int maxdist = 0;
			for(int  i = 0 ; i < R*C ; i++){
				for(int j = 0; j < R*C ; j++){
					int px1 = (i/C) ; int py1=(i%C);
					int px2 = (j/C) ; int py2=(j%C);
					
					int dist1 = abs(px1 - px2)+abs(py1 - py2);
					int dist2 = abs(px1 - tx1)+abs(py1-ty1) + abs(tx2 - px2) + abs(ty2 - py2);
					int dist3 = abs(px1 - tx2)+abs(py1-ty2) + abs(tx1 - px2) + abs(ty1 - py2);
					
					maxdist = max(maxdist,min(dist1,min(dist2,dist3)));
				}
			}
			minmaxdist = min(minmaxdist,maxdist);
		}
	}
	return minmaxdist;
}


double test0() {
	int p0 = 4;
	int p1 = 1;
	PublicTransit * obj = new PublicTransit();
	clock_t start = clock();
	int my_answer = obj->minimumLongestDistance(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 2;
	int p1 = 2;
	PublicTransit * obj = new PublicTransit();
	clock_t start = clock();
	int my_answer = obj->minimumLongestDistance(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 5;
	int p1 = 3;
	PublicTransit * obj = new PublicTransit();
	clock_t start = clock();
	int my_answer = obj->minimumLongestDistance(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 8;
	int p1 = 2;
	PublicTransit * obj = new PublicTransit();
	clock_t start = clock();
	int my_answer = obj->minimumLongestDistance(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
