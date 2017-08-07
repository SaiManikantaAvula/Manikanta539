#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <queue>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <map>
#include <cstdlib>
#include <ctime>
#include<cstring>

using namespace std;


class BearPlaysDiv2 {
public:
	string equalPiles(int, int, int);
};

struct node{
	int arr[3];
};

string BearPlaysDiv2::equalPiles(int A, int B, int C) {
	if((A+B+C)%3!=0)
	return "impossible";
	int target = (A+B+C)/3;
	bool visited[699][699];
	memset(visited,0,sizeof(visited));
	queue<node> q;
	node temp;
	temp.arr[0]=A;
	temp.arr[1]=B;
	temp.arr[2]=C;
	sort(temp.arr,temp.arr+3);
	visited[temp.arr[0]][temp.arr[1]]=true;
	q.push(temp);
	while(!q.empty()){
		node bar=q.front();
		q.pop();
		if(bar.arr[0]==target && bar.arr[1]==target)
		return "possible";
		
		for(int i = 0 ; i< 3 ; i++){
			for(int j = i+1 ; j<3 ; j++){
				node foo = bar;
				if(foo.arr[i] !=foo.arr[j]){
					foo.arr[j]=foo.arr[j]-foo.arr[i] ; foo.arr[i]*=2;
					sort(foo.arr,foo.arr+3);
					if(!visited[foo.arr[0]][foo.arr[1]]){
						q.push(foo);
						visited[foo.arr[0]][foo.arr[1]]=true;
					}
				}
			}
		}
	}
	return "impossible";
}


double test0() {
	int p0 = 10;
	int p1 = 15;
	int p2 = 35;
	BearPlaysDiv2 * obj = new BearPlaysDiv2();
	clock_t start = clock();
	string my_answer = obj->equalPiles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 1;
	int p1 = 1;
	int p2 = 2;
	BearPlaysDiv2 * obj = new BearPlaysDiv2();
	clock_t start = clock();
	string my_answer = obj->equalPiles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "impossible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 4;
	int p1 = 6;
	int p2 = 8;
	BearPlaysDiv2 * obj = new BearPlaysDiv2();
	clock_t start = clock();
	string my_answer = obj->equalPiles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "impossible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 18;
	int p1 = 18;
	int p2 = 18;
	BearPlaysDiv2 * obj = new BearPlaysDiv2();
	clock_t start = clock();
	string my_answer = obj->equalPiles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 225;
	int p1 = 500;
	int p2 = 475;
	BearPlaysDiv2 * obj = new BearPlaysDiv2();
	clock_t start = clock();
	string my_answer = obj->equalPiles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
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
