#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,string> >st(101);
int visited[101];
int truth[101];
bool flag;
void explore(int s){
	int current=s;
	int next=st[s].first;

	while(1){
		if(visited[current]==true)
			break;
		//cout<<"current="<<current<<"next="<<next<<endl;
		int truth_value1=truth[current];
		int truth_value2=truth[next];
		//cout<<"currenttruth="<<truth_value1<<"nexttruth="<<truth_value2<<endl;
		string sta1=st[current].second;
		string sta2=st[next].second;
		if(truth_value1==1){
			if(sta1=="false"&&truth[next]!=1){
				truth[next]=0;
			}
			else if(sta1=="true"&&truth[next]!=0){
				truth[next]=1;
			}
			else{
				flag=true;
				visited[current]=true;
				break;
			}
		}
		else{
			if(sta1=="false"&&truth[next]!=0){
				truth[next]=1;
			}
			else if(sta1=="true"&&truth[next]!=1){
				truth[next]=0;
			}
			else{
				flag=true;
				visited[current]=true;
				break;
			}
		}
		visited[current]=true;
		current=next;
		next=st[next].first;
	}
}
void find(){
	explore(1);
	if(flag==true)
		return;
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			cout<<"i="<<i<<endl;
			truth[i]=1;
			explore(i);
			//cout<<"flag AFTER exploring"<<i<<"="<<flag<<endl;
			if(flag==true){
				flag=false;
				for(int j=0;j<=n;j++){
					truth[j]=-1;
					visited[j]=false;
				}
				truth[i]=0;
				explore(i);
			}
		}
		if(flag==true)
			return;
	}
}
int main(){
	while(1){
		st.clear();
		flag=false;
		cin>>n;
		if(n==0)
			exit(0);
		for(int i=1;i<=n;i++){
			int t;
			string s;
			cin>>t>>s;
			st[i]=make_pair(t,s);
			visited[i]=false;
			truth[i]=-1;
		}
		truth[1]=1;
		find();
		//cout<<"flag after first="<<flag<<endl;
		if(!flag){
			cout<<"NOT PARADOX"<<endl;
		}
		else{
			for(int i=0;i<=n;i++){
				truth[i]=-1;
				visited[i]=false;
			}
			flag=false;
			truth[1]=0;
			find();
			//cout<<"flag after second="<<flag<<endl;
			if(flag){
				cout<<"PARADOX"<<endl;
			}
			else{
				cout<<"NOT PARADOX"<<endl;
			}
		}
	}
}