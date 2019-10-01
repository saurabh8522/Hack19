#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct edge{
	int u,v,w;
};
vector<int>link(10005);
vector<struct edge>grp;
bool sortbyweight(const struct edge &e,const struct edge &f){
	return e.w<f.w;
}
int find(int a){
	while(a!=link[a]){
		a=link[a];
	}
	return a;
}
void unite(int a,int b){
	a=find(a);
	b=find(b);
	link[a]=b;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,p;
		grp.clear();
		cin>>p>>n>>m;
		for(int i=0;i<m;i++){
			struct edge e;
			cin>>e.u>>e.v>>e.w;
			grp.push_back(e);
		}
		for(int i=1;i<=n;i++){
			link[i]=i;
		}
		ll sum=0;
		sort(grp.begin(),grp.end(),sortbyweight);
		for(int i=0;i<m;i++){
			int a=grp[i].u;
			int b=grp[i].v;
			//cout<<a<<" "<<b<<endl;
			if(find(a)==find(b)){
				continue;
			}
			else{
				unite(a,b);
				sum+=grp[i].w;
			}
		}
		cout<<sum*p<<endl;
	}
}