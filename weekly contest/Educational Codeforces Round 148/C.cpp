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

int sggn(int x){
    if(x==0) return 0;
    if(x>0) return 1;
    else return -1;
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
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> b;
        b.pb(a[0]);
        for(int i=1;i<n;i++){
            if(a[i]!=b.back()) b.pb(a[i]);
        }
        int m=b.size();
        if(m==1){
            cout<<"1\n";
            continue;
        }
        vector<int> delta(m-1);
        for(int i=0;i<m-1;i++){
            delta[i]=b[i+1]-b[i];
        }
        vector<int> c;
        int last=delta[0];
        c.pb(b[0]);
        for(int i=1;i<m-1;i++){
            if(sggn(delta[i])!=sggn(last)){
                c.pb(b[i]);
                last=delta[i];
            }
        }
        c.pb(b[m-1]);
        cout<<c.size()<<"\n";
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
