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

vector<ll> a;

bool ispos(int len,int s){
    if(len==0) return true;
    int n=a.size();
    multiset<ll> ss;
    for(int i=1;i<len+1;i++){
        ss.insert(a[i]);
    }
    for(int i=0;i+len<n;i++){
        if(ss.lower_bound(a[i]-s)==ss.begin()) return true;
        if(i+len+1<n){
            ss.erase(ss.find(a[i+1]));
            ss.insert(a[i+len+1]);
        }
    }
    //cout<<len<<" falsee"<<"\n";
    return false;
}
void check(int len,int s,int &al,int &ar){
    int n=a.size();
    multiset<ll> ss;
    for(int i=1;i<len+1;i++){
        ss.insert(a[i]);
    }
    for(int i=0;i+len<n;i++){
        if(ss.lower_bound(a[i]-s)==ss.begin()){
            al=i+1,ar=i+len;
            return;
        }
        if(i+len+1<n){
            ss.erase(ss.find(a[i+1]));
            ss.insert(a[i+len+1]);
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n,s;
        cin>>n>>s;
        a.resize(n+1);
        a[0]=0;
        for(int i=1;i<=n;i++){
            int val;
            cin>>val;
            a[i]=a[i-1]+val;
        }
        int l=0,r=n;
        while(l<r){
            int m=(r+l+1)/2;
            if(ispos(m,s)) l=m;
            else r=m-1;
        }
        if(l!=0){
            int al,ar;
            check(l,s,al,ar);
            cout<<al<<" "<<ar<<"\n";
        }else{
            cout<<"-1\n";
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
