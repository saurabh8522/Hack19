#include<bits/stdc++.h>
using namespace std;
int n,m;
bool visited[1000];
vector<int>grp[1000];
void explore(int s){
	visited[s]=true;
	cout<<s<<endl;
	for(int i=0;i<grp[s].size();i++){
		if(!visited[grp[s][i]]){
			explore(grp[s][i]);
		}
	}
}
void dfs(int source){
	explore(source);
	for(int i=1;i<=n;i++){
		if(!visited[i])
			explore(i);
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		visited[i]=false;
	}
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		grp[u].push_back(v);
	}
	int source=1;
	dfs(source);
}