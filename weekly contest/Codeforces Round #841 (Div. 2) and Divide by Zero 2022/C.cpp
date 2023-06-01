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

    const int maxn=2e5;
    /*vector<int> sq;
    void init(){
        sq.pb(0);
        int x=max_bit(maxn);
        //cout<<(1<<x)<<" "<<(1<<(x+1))<<"\n";
        for(int i=1;i*i<(1<<(x+1));i++){
            sq.pb(i*i);
        }
    }*/
    int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int t;
        cin>>t;
        //cout<<sq.size()<<"\n";
        while(t--){
            int n;
            cin>>n;
            vector<int> sq;
            int x=max_bit(n);

            for(int i=0;i*i<(1<<(x+1));i++){
                sq.pb(i*i);
            }

            vector<int> a(n);
            for(int i=0;i<n;i++) cin>>a[i];
            vector<int> p(n+1);
            p[0]=0;
            for(int i=0;i<n;i++) p[i+1]=p[i]^a[i];
            vector<int> f(2*n,0);
            f[p[0]]++;
            ll ans=0;
            /*for(int i=0;i<=n;i++) cout<<p[i]<<" ";
            cout<<"\n";*/
            for(int i=1;i<=n;i++){
                ll tot=i;
                for(int s:sq){
                    tot-=f[p[i]^s];
                }
                //cout<<i<<" "<<tot<<"\n";
                ans+=tot;
                f[p[i]]++;
            }
            cout<<ans<<"\n";
        }
        cout << setprecision(12) << fixed;
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
