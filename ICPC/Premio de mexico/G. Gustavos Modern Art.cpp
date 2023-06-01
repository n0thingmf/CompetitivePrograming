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
	int n,q;
	cin>>n>>q;
	ll dx=n+1,dy=n+1;
    ll a=1,b=0,c=0,d=1;
	while(q--){
        string s;
        cin>>s;
        if(s=="q"){
            ll x,y;
            cin>>x>>y;
            x=x*2-dx,y=y*2-dy;
            ll tx,ty;
            //cout<<x<<" "<<y<<"\n";
            tx=a*x+b*y;
            ty=c*x+d*y;
            //cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
           //cout<<tx<<" "<<ty<<"\n";
            tx=(tx+dx)/2;
            ty=(ty+dy)/2;
            cout<<(tx-1)*n+ty<<"\n";
        }else{
            string t;
            cin>>t;
            if(t=="a"){
                swap(a,b);
                swap(c,d);
            }else if(t=="b"){
                b*=-1;
                d*=-1;
            }else if(t=="c"){
                swap(a,b);
                swap(c,d);
                a*=-1;
                b*=-1;
                c*=-1;
                d*=-1;
            }else{
                a*=-1;
                c*=-1;
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
