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

bool ask(int l,int r){
    cout<<"? "<<r-l+1;
    for(int i=l;i<=r;i++) cout<<" "<<i;
    cout<<"\n"<<endl;
    string s;
    cin>>s;
    return s=="YES";
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int n;
	string s;
	cin>>n;
	int l=1,r=n;
	while(l<r){
        bool ok1,ok2;
        int m=(l+r)>>1;
        ok1=ask(l,m);
        ok2=ask(l,m);
        if(ok1 || ok2){
            r=m;
        }else{
            l=m+1;
        }
	}
	cout<<"! "<<l<<"\n"<<endl;

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
