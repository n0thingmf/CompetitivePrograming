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
	ll n,m,C;
	cin>>n>>C;
	map<ll,ll> xc;
	for(int i=0;i<n;i++){
        ll c,d,h;
        cin>>c>>d>>h;
        if(xc.count(c)){
            xc[c]=max(xc[c],d*h);
        }else{
            xc[c]=d*h;
        }
	}
	vector<ll> maxpowa(C+1,0);
	for(auto uwu:xc){
        for(ll i=uwu.first,j=uwu.second;i<=C;i+=uwu.first,j+=uwu.second){
            maxpowa[i]=max(maxpowa[i],j);
        }
	}
	for(ll i=1;i<=C;i++){
        maxpowa[i]=max(maxpowa[i-1],maxpowa[i]);
	}
	cin>>m;
	for(int i=0;i<m;i++){
        ll D,H,P;
        cin>>D>>H;
        P=D*H;
        ll l=0,r=C;
        while(l<r){
            ll mid=(l+r)/2;
            if(maxpowa[mid]>P) r=mid;
            else l=mid+1;
        }
        if(maxpowa[l]>P) cout<<l<<" ";
        else cout<<"-1 ";
	}
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
