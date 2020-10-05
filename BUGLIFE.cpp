#include<bits/stdc++.h>
using namespace std;
int n,m;
bool visited[100001];
int color[100001];
#define ll long long int
#define MOD 1000000007
vector<ll>grp[100001];
ll coun,ans;
bool flag;
void explore(ll s){
	visited[s]=true;
	//cout<<"dfs="<<s<<endl;
	// first comment
	// second comment
	for(ll i=0;i<grp[s].size();i++){
		if(visited[grp[s][i]]&&color[s]==color[grp[s][i]]){
			flag=true;
			//cout<<s<<" "<<grp[s][i]<<endl;
			return;
		}
		if(!visited[grp[s][i]]){
			if(color[grp[s][i]]==color[s]){
				flag=true;
				//cout<<s<<" "<<grp[s][i]<<endl;
				return;
			}
			else{
				color[grp[s][i]]=(!color[s]);
				//cout<<grp[s][i]<<" "<<color[grp[s][i]]<<endl;
			}
			explore(grp[s][i]);
		}
	}
}
void dfs(ll source){
	color[source]=1;
	explore(source);
	for(ll i=1;i<=n;i++){
		if(!visited[i]){
			color[i]=1;
			explore(i);
		}
		
	}
}
int main(){
	ll t,c=0;
	cin>>t;
	while(t--){
		c++;
		flag=false;
		for(int i=0;i<100001;i++){
			grp[i].clear();
			color[i]=-1;
		}
		cin>>n>>m;
		for(ll i=0;i<=n;i++){
			visited[i]=false;
		}
		for(ll i=0;i<m;i++){
			ll u,v;
			cin>>u>>v;
			grp[u].push_back(v);
			grp[v].push_back(u);
		}
		ll source=1;
		dfs(source);
		cout<<"Scenario #"<<c<<":"<<endl;
		if(flag)
		{
			cout<<"Suspicious bugs found!"<<endl;
		}
		else{
			cout<<"No suspicious bugs found!"<<endl;
		}
	}
}
