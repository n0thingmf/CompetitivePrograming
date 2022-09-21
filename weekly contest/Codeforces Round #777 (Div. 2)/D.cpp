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
	int t;
	cin>>t;
	while(t--){
        ll x,d,cnt=0;
        cin>>x>>d;
        bool dprime=true;
        for(ll i=2;i*i<=d;i++){
            if(d%i==0){
                dprime=false;
                break;
            }
        }
        while(x%d==0){
            x/=d;
            cnt++;
        }
        if(cnt==1){
            cout<<"NO\n";
            continue;
        }
        bool ok=false;
        for(ll i=2;i*i<=x;i++){
            if(x%i==0){
                ok=true;
                break;
            }
        }
        if(ok) cout<<"YES\n";
        else if(cnt>2){
            if(dprime) cout<<"NO\n";
            else{
                if(cnt==3){
                for(ll i=2;i*i<=x*d;i++){
                    if((x*d)%i==0){
                        if(i%d!=0 && ((x*d)/i)%d!=0) ok=true;
                    }
                }
                if(ok) cout<<"YES\n";
                else cout<<"NO\n";
                }
                else cout<<"YES\n";
            }
        }else cout<<"NO\n";
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
