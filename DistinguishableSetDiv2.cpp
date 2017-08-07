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

class DistinguishableSetDiv2 {
public:
	int count(vector <string>);
	
};

int DistinguishableSetDiv2::count(vector <string> answer) {
	int M = answer[0].size();
	int N = answer.size();
	int limit = (1<<(M))-1;
	int count=1;
	for(int i = 1 ; i<=limit ; i++){
		vector<int> indices;
		cout<<i<<"    ";
		for(int j = 0 ; j<M ; j++){
			
			if((i &(1<<j))!=0)
			{
				indices.push_back(M-j-1);
			}
		}
		cout<<endl;
		for(int j = 0 ; j < N ; j++){
			for(int k = j+1 ; k< N ; k++){
				int counta=0;
				for(int o = 0 ; o<indices.size() ; o++){
					if(answer[j][indices[o]]==answer[k][indices[o]])
					counta++;
				}
				if(counta==indices.size())
				{
					count++;
					goto label;
				}
			}
		}
		label:
		;
	}
	return (pow(2,M)-count);
}


double test0() {
	string t0[] = {"AA","AB","CC"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	DistinguishableSetDiv2 * obj = new DistinguishableSetDiv2();
	clock_t start = clock();
	int my_answer = obj->count(p0);
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
	string t0[] = {"XYZ","XYZ","XYZ"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	DistinguishableSetDiv2 * obj = new DistinguishableSetDiv2();
	clock_t start = clock();
	int my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
	string t0[] = {"AAAA","BACA","CDCE"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	DistinguishableSetDiv2 * obj = new DistinguishableSetDiv2();
	clock_t start = clock();
	int my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 11;
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
	string t0[] = {"HGHHGUHUHI","BQHJWOSZMM","NDKSKCNXND","QOEOEIWIDS","IIQIWUNNZM"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	DistinguishableSetDiv2 * obj = new DistinguishableSetDiv2();
	clock_t start = clock();
	int my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1017;
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
	string t0[] = {"XYZ","XAB","YAC"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	DistinguishableSetDiv2 * obj = new DistinguishableSetDiv2();
	clock_t start = clock();
	int my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
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
	
	
	time = test2();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
