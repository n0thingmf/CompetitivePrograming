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
	int n;
	cin>>n;
	vector<int> t(n);
	vector<int> t2(n);
	for(int i=0;i<n;i++){
        cin>>t[i];
	}
	int l=t[n-1],r=2e5;
	while(l<r){
        int m=(l+r)/2,past=0;
            //cout<<l<<" "<<r<<" "<<m<<"\n";
        bool ok=true;
        for(int i=0;i<n;i++){
            t2[i]=t[i]+2*past;
            if(t2[i]>m){
                if(i==n-1){
                   // cout<<i<<" case1\n";
                    ok=false;
                    break;
                }
                past=t2[i]-m;
                if(t2[i]<2*past){
                   //cout<<i<<" case2\n";
                    ok=false;
                    break;
                }
            }else past=0;
        }
        if(ok) r=m;
        else l=m+1;
	}
	cout<<l<<"\n";
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
