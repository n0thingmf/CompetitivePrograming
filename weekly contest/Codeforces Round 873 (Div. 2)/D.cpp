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

const int maxn=5001;
int ft[5001];
void add(int pos){
    for(++pos;pos<maxn;pos+=pos&-pos){
        ft[pos]++;
    }
}
int sum(int pos){
    int ans=0;
    for(++pos;pos>0;pos&=pos-1){
        ans+=ft[pos];
    }
    return ans;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vector<int> s=a;
        sort(all(s));
        unordered_map<int,int> pos;
        for(int i=0;i<n;i++) pos[s[i]]=i;
        ll ans=0;
        for(int i=0;i<n;i++){
            vector<pair<int,int>> rg;
            memset(ft,0,sizeof(ft));
            add(pos[a[i]]);
            ll res=0;
            for(int j=1;i+j<n;j++){
                int mypos=sum(pos[a[i+j]]);
                if(mypos!=j){
                    while(rg.size()>0 && mypos<=rg.back().first){
                        res-=rg.back().second-rg.back().first;
                        rg.pop_back();
                    }
                    if(rg.size()>0 && rg.back().first<mypos && mypos<=rg.back().second){
                        pair<int,int> newr={rg.back().first,j};
                        res-=rg.back().second-rg.back().first;
                        rg.pop_back();
                        rg.pb(newr);
                        res+=rg.back().second-rg.back().first;
                    }else{
                        res+=j-mypos;
                        rg.pb({mypos,j});
                    }
                }
                ans+=res;
                add(pos[a[i+j]]);
            }
        }
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
