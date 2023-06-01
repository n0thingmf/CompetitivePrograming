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

ll const xd=2e6;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        ll a,b;
        cin>>a>>b;
        if(a>b){
            cout<<a-b<<"\n";
        }else if(b%a==0){
            cout<<"0\n";
        }else{
            ll k=b/a;
            if(k<=a){
                //cout<<"case 1:\n";
                ll ans=a*(k+1)-b;
                for(ll i=k;i>=1;i--){
                    ll d=b-a*i;
                    ll y=(i-(d%i))%i;
                    ll x=(y+d)/i;
                    ans=min(ans,x+y);
                }
                cout<<ans<<"\n";
            }else{
                //cout<<"case 2:\n";
                ll ans=a*(k+1)-b;
                for(ll i=k;i>=1 && i>=k-xd;i--){
                    ll d=b-a*i;
                    ll y=(i-d%i)%i;
                    ll x=(y+d)/i;
                    ans=min(ans,x+y);
                }
                cout<<ans<<"\n";
            }
        }
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
