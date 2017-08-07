#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

class LuckyCycle {
public:
	vector <int> getEdge(vector <int>, vector <int>, vector <int>);
};

vector <int> LuckyCycle::getEdge(vector <int> edge1, vector <int> edge2, vector <int> weight) {
	int n = edge1.size()+1;
	vector < pair<int,int> > vec[edge1.size()+1];
	for(int i = 0 ; i <n-1 ; i++){
		vec[edge1[i]-1].push_back(make_pair(edge2[i]-1,weight[i]));
		vec[edge2[i]-1].push_back(make_pair(edge1[i]-1,weight[i]));
	}
	for(int i = 0 ; i < n ; i++){
		vector<int> count7(n,-1),count4(n,-1);
		count7[i]=count4[i]=0;
		queue<int> q;
		q.push(i);
		while(!q.empty()){
			int x = q.front();
			q.pop();
			if(x!=i){
				if((count7[x]+1==count4[x] || count4[x]+1==count7[x]) && count4[x]+count7[x]>1){
					vector<int> zec;
					if(count4[x]>count7[x]){
						zec.push_back(i+1);
						zec.push_back(x+1);
						zec.push_back(7);
						return zec;
					}
					else{
						zec.push_back(i+1);
						zec.push_back(x+1);
						zec.push_back(4);	
						return zec;					
					}
				}
			}
			
			for(int j = 0 ; j<vec[x].size(); j++){
				int y = vec[x][j].first;
				int weight=vec[x][j].second;
				if(count7[y]==-1){
					if(weight==7){
						count7[y]=count7[x]+1;
						count4[y]=count4[x];
						q.push(y);
					}else{
						count7[y]=count7[x];
						count4[y]=count4[x]+1;
						q.push(y);						
					}	
				}
			}
		}
	}
	vector<int> zec;
	return zec;
}

