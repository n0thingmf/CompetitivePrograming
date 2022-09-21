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
        int n,z=0;
        cin>>n;
        map<int,int> a;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[x]++;
        }
        map<int,int> b;
        while(true){
            if(a.size()==1 && a.begin()->second==1) break;
            for(auto it:a){
                if(it.second>1){
                    b[0]+=it.second-1;
                }
            }
            for(auto it=a.begin(),it2=++(a.begin());it2!=a.end();it++,it2++){
                int x=it->first,y=it2->first;
                b[y-x]++;
            }
            a=b;
            b.clear();
        }
        cout<<a.begin()->first<<"\n";
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
