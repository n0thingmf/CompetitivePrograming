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
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(a[0]!=n && a[n-1]!=n) cout<<"-1\n";
        else{
            deque<int> p;
            int i=0,j=n-1;
            while(i<=j){
                if(a[i]<a[j]){
                    p.push_front(a[i]);
                    i++;
                }else{
                    p.push_back(a[j]);
                    j--;
                }
            }
            while(!p.empty()){
                cout<<p.front()<<" ";
                p.pop_front();
            }
            cout<<"\n";
        }
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
