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

const double pi=acos(-1),eps=1e-12;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(12) << fixed;
	double a,b;
	cin>>a>>b;
	double l=0,r=pi/6;
	while(r-l>eps){
        double m1=(2*l+r)/3,m2=(l+2*r)/3;
        double f1=min(a/cos(m1),b/cos(pi/6-m1)),f2=min(a/cos(m2),b/cos(pi/6-m2));
        if(f1<f2){
            l=m1;
        }else{
            r=m2;
        }
	}
	cout<<min(a/cos(l),b/cos(pi/6-l))<<"\n";
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
