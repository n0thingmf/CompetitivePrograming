#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define popb pop_back
#define all(A) A.begin(),A.end()
#define rall(A) A.rbegin(),A.rend()
#define dic unordered_map
#define bpc __builtin_popcountll//numero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll
#define max_bit(A) 31-__builtin_clz(A)

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,l;
	ll k;
	cin>>n>>k;
	vector<string> att(n);
	vector<ll> score(n);
	vector<vector<ll>> event(n);
	for(int i=0;i<n;i++){
        cin>>att[i]>>score[i];
	}
	map<string,int> ind;
	for(int i=0;i<n;i++) ind[att[i]]=i;
	cin>>l;
	for(int i=0;i<l;i++){
        ll tresh;
        string s;
        cin>>s>>tresh;
        int id=ind[s];
        event[id].pb(tresh);
	}
	ll need=0,ans=0;
	priority_queue<pair<ll,int>> q;
	vector<ll> delta(n,0);
	for(int i=0;i<n;i++){
        if(event[i].size()){
            sort(all(event[i]));
            ll maxv=event[i].back();
            ll sum=event[i].size();
            for(int j=event[i].size()-1;j>=0 && event[i][j]==maxv;j--){
                sum+=maxv;
                delta[i]+=maxv;
            }
            q.push({sum,i});
            if(score[i]<maxv){
                need+=maxv-score[i];
                score[i]=maxv;
            }
            for(int j=0;j<event[i].size();j++){
                if(event[i][j]!=score[i]) ans+=score[i];
            }
        }
	}
	cout<<need<<" "<<k<<"\n";
	if(need<=k){
        k-=need;
        while(k){
            auto now=q.top();
            int id=now.second;
            ans+=now.first;
            k--;
            if(delta[id]>0){
                q.pop();
                now.first-=delta[id];
                delta[id]=0;
                q.push({now});
            }else break;
        }
        if(k>0){
            auto now=q.top();
            ans+=now.first*k;
        }
        cout<<ans<<"\n";
	}else cout<<"0\n";

	return 0;
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* bitwise and boolean operations
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
