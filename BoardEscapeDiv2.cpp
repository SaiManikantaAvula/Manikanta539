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
#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;



class BoardEscapeDiv2 {
public:
	vector<string> str;
	int total;
	string findWinner(vector <string>, int);
	int calculate(int x,int y,int k);
	int dp[51][51][102];
};



string BoardEscapeDiv2::findWinner(vector <string> s, int k) {
	
	memset(dp,-1,sizeof(dp));
	total=k;
	str=s;
	int result;
	for(int i = 0 ; i < s.size() ; i++){
		for(int j = 0 ; j < s[0].size() ; j++){
			if(s[i][j]=='T'){
				result=calculate(i,j,k);
				break;
			}
		}
	}
	if(result==1)
	return "Alice";
	else 
	return "Bob";
}

int BoardEscapeDiv2::calculate(int x,int y,int k){
	if((k==0 && total%2==0) || ((str[x][y]=='E') && ((total%2!=0 && k%2!=0 )||(total%2==0 && k%2==0))))
	return 0;
	if((k==0 && total%2!=0) || ((str[x][y]=='E') && ((total%2==0 && k%2!=0 )||(total%2!=0 && k%2==0))))
	return 1;
	
	static int dx[]={-1,0,1,0};
	static int dy[]={0,1,0,-1};

	if(dp[x][y][k]!=-1)
	return dp[x][y][k];
	
	int res=0;
	if((total%2==0 && k%2!=0 )|| (total%2!=0 && k%2==0))
	res=1;
	
	bool flag=true;
	
	for(int i = 0 ; i <4 ; i++){
		
		if(x+dx[i] >=0 && x+dx[i]<str.size() && y+dy[i]>=0 && y+dy[i]<str[0].size() && str[x+dx[i]][y+dy[i]]!='#'){
			int temp = calculate(x+dx[i],y+dy[i],k-1);
			if((total%2!=0 && k%2!=0 )||(total%2==0 && k%2==0))
		    res = res || temp;
			if((total%2==0 && k%2!=0 )|| (total%2!=0 && k%2==0))
			res = res && temp;
			flag=false;
		}
	}
	if(flag){
		if((total%2==0 && k%2==0 )|| (total%2!=0 && k%2!=0))
		dp[x][y][k]=0;
		if((total%2==0 && k%2!=0 )|| (total%2!=0 && k%2==0))
		dp[x][y][k]=1;
		return dp[x][y][k];
	}
	dp[x][y][k]=res;
	return dp[x][y][k];
}

double test0() {
	string t0[] = {"T.#",
 "#.E"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 3;
	BoardEscapeDiv2 * obj = new BoardEscapeDiv2();
	clock_t start = clock();
	string my_answer = obj->findWinner(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Alice";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"E#E",
 "#T#",
 "E#E"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 99;
	BoardEscapeDiv2 * obj = new BoardEscapeDiv2();
	clock_t start = clock();
	string my_answer = obj->findWinner(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Bob";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"#E...",
 "#...E",
 "E.T#.",
 "..#.."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 13;
	BoardEscapeDiv2 * obj = new BoardEscapeDiv2();
	clock_t start = clock();
	string my_answer = obj->findWinner(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Alice";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"TE"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 50;
	BoardEscapeDiv2 * obj = new BoardEscapeDiv2();
	clock_t start = clock();
	string my_answer = obj->findWinner(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Alice";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {".T."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	BoardEscapeDiv2 * obj = new BoardEscapeDiv2();
	clock_t start = clock();
	string my_answer = obj->findWinner(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Alice";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string t0[] = {"..........................",
 "......EEE..EEE..E...E.....",
 ".....E.....E..E.EE.EE.....",
 "......EEE..EEE..E.E.E.....",
 ".........E.E.E..E...E.....",
 "......EEE..E..E.E...E.....",
 "..........................",
 "...E#E#E#E#E#E#E#E#E#E#...",
 "..........................",
 "......EEE..EEE...EEE......",
 ".....E........E.E.........",
 "......EEE.....E..EEE......",
 ".....E...E...E..E...E.....",
 "......EEE....E...EEE......",
 "..........................",
 "...#E#E#E#E#E#E#E#E#E#E...",
 "..........................",
 "....EE...E...E..E.EEE.E...",
 "...E.....E...E..E.E...E...",
 "...E.EE..E...EEEE.EE..E...",
 "...E..E..E...E..E.E.......",
 "....EE...EEE.E..E.E...E...",
 "T........................."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 100;
	BoardEscapeDiv2 * obj = new BoardEscapeDiv2();
	clock_t start = clock();
	string my_answer = obj->findWinner(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Bob";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
