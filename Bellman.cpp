#include<bits/stdc++.h>
using namespace std;
struct edge{
	int a,b,w;
};
int main(){
	int n,m;
	cin>>n>>m;
	vector<struct edge>ed(m);
	int dist[n+1];
	for(int i=1;i<=n;i++)
		dist[i]=INT_MAX;
	for(int i=0;i<m;i++){
		cin>>ed[i].a>>ed[i].b>>ed[i].w;
	}
	dist[1]=0;
	for(int i=0;i<n-1;i++){
		//cout<<i<<endl;
		for(int j=0;j<m;j++){
			if(dist[ed[j].a]+ed[j].w<dist[ed[j].b]&&dist[ed[j].a]!=INT_MAX){
				dist[ed[j].b]=dist[ed[j].a]+ed[j].w;
				//cout<<ed[j].a<<ed[j].b<<ed[j].w<<endl;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<dist[i]<<endl;
	}
}