#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>grp[1000];
queue<int>q;
bool visited[1000];
void explore(int s){
	q.push(s);
	visited[s]=true;
	while(!q.empty()){
		int p=q.front();
		q.pop();
		cout<<p<<endl;
		for(int i=0;i<grp[p].size();i++){
			if(!visited[grp[p][i]]){
				q.push(grp[p][i]);
				visited[grp[p][i]]=true;
				//cout<<"pushing"<<grp[p][i]<<endl;
			}
		}
	}
}
void bfs(int s){
	explore(s);
	for(int i=1;i<=n;i++){
		if(!visited[i])
			explore(i);
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		grp[u].push_back(v);
	}
	int source =1;
	bfs(source);
}