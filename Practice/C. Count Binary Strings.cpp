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

const ll mod=998244353;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;

	vector<int> a(n);
	for(int i=0;i<n;i++) a[i]=i;
	vector<int> two(n,-1);
	for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int x;
            cin>>x;
            if(x==1){
                for(int k=i;k<=j;k++){
                    a[k]=a[i];
                }
            }else if(x==2){
                if(two[i]==-1) two[i]=j;
            }
        }
	}
	vector<int> m(n,-1);
	int y=0;
	for(int i=0;i<n;i++){
        if(m[a[i]]==-1) m[a[i]]=y++,a[i]=m[a[i]];
        else a[i]=m[a[i]];
	}
	/*for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<"\n";*/
	int nm=y;
	vector<pair<int,int>> interv;
	for(int i=0;i<n;i++){
        int j=two[i];
        if(j==-1) continue;
        if(a[i]==a[j]){
            cout<<"0\n";
            return 0;
        }
        interv.pb({a[i],a[j]});
	}
	sort(all(interv));
	interv.erase(unique(all(interv)),interv.end());
	vector<int> l(nm,-1);
	for(int i=0;i<interv.size();i++){
        bool ok=true;
        for(int j=0;j<interv.size() && ok;j++){
            if(i==j) continue;
            if(interv[i].first<=interv[j].first && interv[j].second<=interv[i].second) ok=false;
        }
        if(ok){
            l[interv[i].second]=interv[i].first;
        }
	}
	/*cout<<nm<<"\n";
	for(int i=0;i<nm;i++) cout<<l[i]<<" ";
	cout<<"\n";*/
	vector<ll> dp(nm,0);
	dp[0]=1;
	for(int i=1;i<nm;i++){
        if(l[i]==-1){
            dp[i]=(2*dp[i-1])%mod;
        }else{
            for(int j=l[i];j<i;j++){
                dp[i]+=dp[j];
                dp[i]%=mod;
            }
        }
	}
	/*for(int i=0;i<nm;i++) cout<<dp[i]<<" ";
	cout<<"\n";*/
	cout<<(2*dp[nm-1])%mod<<"\n";
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
