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
 const double pi=3.14159265358979,r2=sqrt(2);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(2) << fixed;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
        double s,r;
        cin>>s>>r;
        if(r<=s/2){
            cout<<pi*r*r<<"\n";
        } else if(r>=(s/2)*r2){
            cout<<s*s<<"\n";
        }else{
            double ang=acos(s/(2*r));
            double delta=r*r*(ang-sin(2*ang)/2);
            cout<<pi*r*r-4*delta<<"\n";
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
