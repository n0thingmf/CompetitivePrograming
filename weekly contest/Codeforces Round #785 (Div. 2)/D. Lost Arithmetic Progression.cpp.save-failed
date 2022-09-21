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

const ll mod=1e9+7;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        ll b,q,y,c,r,z;
        cin>>b>>q>>y>>c>>r>>z;
        if(r%q!=0){
            cout<<"0\n";
        }else{
            if(abs(c-b)%q!=0){
                cout<<"0\n";
            }else{
                ll t0=(c-b)/q,tf=(1ll*r*(z-1)+c-b)/q;
                //cout<<t0<<" "<<tf<<" aeaaa\n";
                if(t0>=0 && tf<y){
                    bool inf=false;
                    ll ans=0;

                    for(ll g=1;g*g<=q;g++){
                        if(q%g==0){
                            ll p=(r/q)*g;
                            if(gcd(p,q)==g){
                                if(t0<r/q || y-1-tf<r/q) inf=true;
                                ans+=1ll*(r/p)*(r/p);
                                ans%=mod;
                            }
                            if(q/g!=g){
                                p=(r/q)*(q/g);
                                if(gcd(p,q)==q/g){
                                    if(t0<r/q || y-1-tf<r/q) inf=true;
                                    ans+=1ll*(r/p)*(r/p);
                                    ans%=mod;
                                }

                            }
                        }


                    }
                    if(inf) cout<<"-1\n";
                    else cout<<ans<<"\n";
                }else{
                    cout<<"0\n";
                }
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
