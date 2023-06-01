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
        int n;
        cin>>n;
        multiset<ll> s;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            s.insert(x);
        }
        if(n==1){
            if((*s.begin())<=1) cout<<"1\n";
            else cout<<"0\n";
            continue;
        }
        int k;
        for(k=1;;k++){
            multiset<int> st(all(s));
            bool ok=true;
            for(int i=k;i>=1;i--){
                if(st.empty()){
                    ok=false;
                    break;
                }
                auto it=st.upper_bound(i);
                if(it==st.begin()){
                    ok=false;
                    break;
                }
                else it--;
                st.erase(it);
                if(st.empty()){
                    ok=false;
                    break;
                }
                auto it2=st.begin();
                st.insert((*it2)+i);
                st.erase(it2);
            }
            if(!ok) break;
        }
        cout<<k-1<<"\n";
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
