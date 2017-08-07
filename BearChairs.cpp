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

class BearChairs {
public:
	vector <int> findPositions(vector <int>, int);
};

vector <int> BearChairs::findPositions(vector <int> atLeast, int d) {
	vector<int> solutions;
	vector<int> temp;
	int i=0;
	
	solutions.push_back(atLeast[i]);
	temp.push_back(atLeast[i++]);
	if(atLeast.size()==1)
	return solutions;
	for(; i <atLeast.size() ;i++){
		int current = atLeast[i];
		int x = temp[0],y=-1;
		if(x-d >=1 && x-d>=current){
			solutions.push_back(current);
			temp.push_back(current);
			sort(temp.begin(),temp.end());
			continue;
		}
		else{
			for(int j = 0 ; j<temp.size() ; j++,y=-1){
				x=temp[j];
				if(j+1<temp.size())
				y=temp[j+1];
				if(y==-1){
					current = max(x+d,current);
					solutions.push_back(current);
					temp.push_back(current);
					break;
				}
				if(x+d<=y-d && y-d>=current){
					current = max(current,x+d);
					solutions.push_back(current);
					temp.push_back(current);
					sort(temp.begin(),temp.end());
					break;
				}
			}
		}
	}
	return solutions;
}


double test0() {
	int t0[] = {1,21,11,7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 10;
	BearChairs * obj = new BearChairs();
	clock_t start = clock();
	vector <int> my_answer = obj->findPositions(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {1, 21, 11, 31 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {1,21,11,7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 11;
	BearChairs * obj = new BearChairs();
	clock_t start = clock();
	vector <int> my_answer = obj->findPositions(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {1, 21, 32, 43 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {1000000,1000000,1000000,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1000000;
	BearChairs * obj = new BearChairs();
	clock_t start = clock();
	vector <int> my_answer = obj->findPositions(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {1000000, 2000000, 3000000, 4000000 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {104, 120, 213, 132, 177, 255, 216, 155, 99, 146, 108, 94, 214, 200, 210, 221, 229, 224, 191, 215, 129, 101, 121, 146, 163, 198, 115, 89, 98, 206, 172, 212, 146, 113, 263, 242, 97, 109, 217, 206, 173, 243, 219, 115, 172, 249, 156, 221, 202, 265, 256, 151, 187, 197, 215, 170};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 11;
	BearChairs * obj = new BearChairs();
	clock_t start = clock();
	vector <int> my_answer = obj->findPositions(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {104, 120, 213, 132, 177, 255, 224, 155, 143, 166, 188, 199, 235, 266, 277, 288, 299, 310, 321, 332, 343, 354, 365, 376, 387, 398, 409, 89, 420, 431, 442, 453, 464, 475, 486, 497, 508, 519, 530, 541, 552, 563, 574, 585, 596, 607, 618, 629, 640, 651, 662, 673, 684, 695, 706, 717};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
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
	
	time = test3();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
