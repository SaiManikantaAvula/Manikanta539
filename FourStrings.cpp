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

class FourStrings {
public:
	int shortestLength(string, string, string, string);
};

int FourStrings::shortestLength(string a, string b, string c, string d) {
	int max=60;
	string str[]={a,b,c,d};
	
	for(int i = 0 ; i< 4 ; i++){
		for(int j = 0 ; j < 4 ; j++){
			if(j==i)
			continue;
			for(int k =0  ; k< 4 ; k++){
				if((i==k || j==k))
				continue;
				for(int l = 0 ; l< 4 ; l++){
					if((l==i || l==j || l==k))
					continue;
					
					string temp = str[i];	
					
					std::size_t found = temp.find(str[j]);
  					if (found==std::string::npos){
  						bool flag=true;
  						for(int z = str[j].size()-2 ; z >=0  ; z--){
  							string temporary = str[j].substr(0,z+1);
  							if(temp.size()<temporary.size())
  							continue;
  							int y,x;
  							for(y=temp.size()-temporary.size(),x=0; y<temp.size() && x<temporary.size() ; y++,x++ ){
  								if(temp[y]!=temporary[x])
  								break;
							  }
  							if(y==temp.size())
  							{
  								flag = false;
  								temp=temp+(str[j].substr(z+1,str[j].size()-z-1));
  								break;
							  }
						  }
						  if(flag)
						  temp=temp+str[j];
					  }
					  
					found = temp.find(str[k]);
  					if (found==std::string::npos){
  						bool flag=true;
  						for(int z = str[k].size()-2 ; z >=0  ; z--){
  							string temporary = str[k].substr(0,z+1);
  							if(temp.size()<temporary.size())
  							continue;
  							int y,x;
  							for(y=temp.size()-temporary.size(),x=0; y<temp.size() && x<temporary.size() ; y++,x++ ){
  								if(temp[y]!=temporary[x])
  								break;
							  }
  							if(y==temp.size())
  							{
  								flag = false;
  								temp=temp+(str[k].substr(z+1,str[k].size()-z-1));
  								break;
							  }
						  }
						  if(flag)
						  temp=temp+str[k];
					  }
					  
					  
					found = temp.find(str[l]);
  					if (found==std::string::npos){
  						bool flag=true;
  						for(int z = str[l].size()-2 ; z >=0  ; z--){
  							string temporary = str[l].substr(0,z+1);
  							if(temp.size()<temporary.size())
  							continue;
  							int y,x;
  							for(y=temp.size()-temporary.size(),x=0; y<temp.size() && x<temporary.size() ; y++,x++ ){
  								if(temp[y]!=temporary[x])
  								break;
							  }
  							if(y==temp.size())
  							{
  								flag = false;
  								temp=temp+(str[l].substr(z+1,str[l].size()-z-1));
  								break;
							  }
						  }
						  if(flag)
						  temp=temp+str[l];
					  }		

					  
					  if(temp.size() < max)
					  max=temp.size();			  
				}
			}
		}
	}
	return max;
}


double test0() {
	string p0 = "abc";
	string p1 = "ab";
	string p2 = "bc";
	string p3 = "b";
	FourStrings * obj = new FourStrings();
	clock_t start = clock();
	int my_answer = obj->shortestLength(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "a";
	string p1 = "bc";
	string p2 = "def";
	string p3 = "ghij";
	FourStrings * obj = new FourStrings();
	clock_t start = clock();
	int my_answer = obj->shortestLength(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 10;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "top";
	string p1 = "coder";
	string p2 = "opco";
	string p3 = "pcode";
	FourStrings * obj = new FourStrings();
	clock_t start = clock();
	int my_answer = obj->shortestLength(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 8;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = "aaabab";
	string p1 = "ba";
	string p2 = "bbabab";
	string p3 = "bbbbab";
	FourStrings * obj = new FourStrings();
	clock_t start = clock();
	int my_answer = obj->shortestLength(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 19;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string p0 = "aba";
	string p1 = "b";
	string p2 = "b";
	string p3 = "b";
	FourStrings * obj = new FourStrings();
	clock_t start = clock();
	int my_answer = obj->shortestLength(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string p0 = "x";
	string p1 = "x";
	string p2 = "x";
	string p3 = "x";
	FourStrings * obj = new FourStrings();
	clock_t start = clock();
	int my_answer = obj->shortestLength(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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
