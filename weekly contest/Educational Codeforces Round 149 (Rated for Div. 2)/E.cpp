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

ll f[1<<20];
ll fi[1<<20];
ll comb(ll a,ll b){
    return f[a]*fi[a-b]%mod;
}
ll fpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	//concreta mejor tus ideas, para que asi sea mas facil de programar.

	f[0]=1;
	for(ll i=1;i<(1<<20);i++) f[i]=f[i-1]*i%mod;
	fi[(1<<20)-1]=fpow(f[(1<<20)-1],mod-2);
	for(ll i=(1<<20)-2;i>=0;i--){
        fi[i]=fi[i+1]*(i+1)%mod;
	}

	int k;
	cin>>k;
	vector<int> tour(1<<k);
	for(int i=0;i<(1<<k);i++){
        cin>>tour[i];
        if(tour[i]!=-1){
            tour[i]-=1;
        }
	}
	vector<ll> toput(k),filled(k);
	for(int i=k-1;i>=0;i--){
        toput[i]=0;
        filled[i]=0;
        for(int j=0;j<(1<<i);j++){
            int cnt=0,ok=0;
            for(int u=0;u<(1<<k-i);u++){
                int id=j*(1<<k-i)+u;
                if(tour[id]!=-1){
                    if((1<<i)<=tour[id] && tour[id]<(1<<(i+1))) ok++;
                    if(tour[id]<(1<<i)) cnt++;
                }
            }
            if(ok>1){
                cout<<"0\n";
                return 0;
            }
            if(cnt>1    ){
                cout<<"0\n";
                return 0;
            }
            if(ok==0){
                toput[i]++;
                filled[i]+=cnt;
            }
        }
	}

	ll ans=1;
	for(int i=k-1;i>=0;i--){
        //cout<<i<<" "<<toput[i]<<" "<<filled[i]<<"\n";
        if(toput[i]<filled[i]) continue;
        ans=ans*comb(toput[i],filled[i])%mod;
        ll left=toput[i]-filled[i];
        while(left>0) ans=ans*left*2%mod,left--;
	}
	cout<<ans<<"\n";
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
