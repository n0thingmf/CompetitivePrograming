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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> l(n,-1);
        vector<int> r(n,-1);
        vector<int> a(n);
        map<int,vector<int>> id;
        for(int i=0;i<n;i++){
            cin>>a[i];
            id[m-a[i]].pb(i);
        }
        set<int> st;
        int dad;
        for(auto x:id){
            int val=m-x.first,j=n;

            for(int i:x.second){
                if(st.empty()){
                    dad=i;
                    st.insert(i);
                    continue;
                }
                auto it=st.lower_bound(i);
                if(it==st.end()){
                    it--;
                    r[*it]=i;
                }else if(it==st.begin()){
                    l[*it]=i;
                }else{
                    int v=*it;
                    it--;
                    int u=*it;
                    if(a[u]<a[v]){
                        r[u]=i;
                    }else{
                        l[v]=i;
                    }
                }
                st.insert(i);
            }

        }
        //cout<<"inicia\n";
        auto dfs = [&](int v, auto&& dfs) -> vector<ll> {
            vector<ll> lf,rg;
            if(l[v]!=-1) lf=dfs(l[v],dfs);
            if(r[v]!=-1) rg=dfs(r[v],dfs);
            if(l[v]==-1 && r[v]==-1) return vector<ll>(m,1);
            vector<ll> ans(m);
            if(l[v]==-1){
                ans[0]=rg[0];
                for(int i=1;i<m;i++){
                    ans[i]=ans[i-1]+rg[i];
                    ans[i]%=mod;
                }
                return ans;
            }
            if(r[v]==-1){
                ans[0]=0;
                for(int i=1;i<m;i++){
                    ans[i]=ans[i-1]+lf[i-1];
                    ans[i]%=mod;
                }
                return ans;
            }
            for(int i=1;i<m;i++){
                rg[i]+=rg[i-1];
                rg[i]%=mod;
            }
            ans[0]=0;
            for(int i=1;i<m;i++){
                ans[i]=ans[i-1]+lf[i-1];
                ans[i]%=mod;
            }
            for(int i=0;i<m;i++) ans[i]=(ans[i]*rg[i])%mod;
            return ans;
        };
        vector<ll> ans=dfs(dad,dfs);
        ll res=0;
        for(int i=0;i<m;i++) res=(res+ans[i])%mod;
        cout<<res<<"\n";
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
