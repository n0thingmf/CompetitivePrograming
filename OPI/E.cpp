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
	int q;
	cin>>q;
	map<ll,int> comprat,ventat;
	while(q--){
        int type;
        cin>>type;
        if(type==1){//venta
            int d,p;
            cin>>d>>p;
            ventat[p]+=d;
        }else{//compra
            int d,p;
            cin>>d>>p;
            comprat[p]+=d;
        }
        map<ll,int> compra=comprat,venta=ventat;
        //for(auto x:compra) cout<<x.first<<" "<<x.second<<" e\n";
        //for(auto x:venta) cout<<x.first<<" "<<x.second<<" e2\n";
        ll ans=0;
        auto it1=compra.rbegin();
        for(;it1!=compra.rend();it1++){
        auto it2=venta.begin();
            for(;it2!=venta.end();it2++){
                if((it1->first)>(it2->first)){
                    ll cnt=min(it1->second,it2->second);
                    ans+=cnt*((it1->first)-(it2->first));
                    (it1->second)-=cnt;
                    (it2->second)-=cnt;
                }
            }
        }
        /*for(;it1!=compra.end() && it2!=venta.rend();){
            if((it1->first)>(it2->first)){
                ll cnt=min(it1->second,it2->second);
                ans+=cnt*((it1->first)-(it2->first));
                (it1->second)-=cnt;
                (it2->second)-=cnt;
                if((it1->second)==0) it1++;
                if((it2->second)==0) it2++;
            }else{
                it2++;
            }
        }*/
        cout<<ans<<"\n";
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
