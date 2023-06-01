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
        int n,k;
        cin>>n>>k;
        vector<ll> a(n),b(n);
        vector<pair<ll,ll>> pr;
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i];
            if(i!=0) pr.pb({a[i]+b[i],b[i]});
        }
        if(k<=a[0]) cout<<"Yes\n";
        else if(k>a[0]+b[0]) cout<<"No\n";
        else{
            k-=b[0];
            sort(all(pr));
            bool ok=false;
            priority_queue<pair<int,int>> q;
            for(int i=n-2,j=n-2;i>=0;i--){
                while(j>=0 && k<=pr[j].first){
                    q.push({pr[j].second,pr[j].first-pr[j].second});
                    j--;
                }
                if(q.empty()) break;
                auto p=q.top();
                q.pop();
                if(k<=p.second){
                    ok=true;
                    break;
                }
                k-=p.first;
            }
            if(ok) cout<<"Yes\n";
            else cout<<"No\n";
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
