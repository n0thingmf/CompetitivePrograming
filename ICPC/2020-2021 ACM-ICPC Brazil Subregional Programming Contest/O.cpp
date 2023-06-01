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

double pi=acos(-1);
double e=1e-5;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> x(n),y(n);
	for(int i=0;i<n;i++) cin>>x[i]>>y[i];
	vector<long double> rad(n),dist(n);
	for(int i=0;i<n;i++){
        int j=(i+1)%n;
        rad[i]=atan2(y[j]-y[i],x[j]-x[i]);
        dist[i]=sqrtl((y[j]-y[i])*(y[j]-y[i])+(x[j]-x[i])*(x[j]-x[i]));
	}
	/*double ans=10000000;
	for(double ang=pi;ang<2*pi;ang+=pi/360){
        double res=0;
        double a=ang;
        for(int i=0;i<n;i++){
            int j=(i+1)%n;
            if(a<0) a+=2*pi;
            if(a>=2*pi) a-=2*pi;
            if(a<=pi/2 || a>3*pi/2) res+=cos(a)*dist[i];
            a+=rad[j]-rad[i];
        }
        //cout<<a-2*pi<<"\n";
        if(res<ans) cout<<"yeeeeeeeeeess\n";
        else cout<<"nooooooo\n";
        ans=min(res,ans);
	}*/
	auto cycle=[&](double ang) -> double{
        long double res=0;
        long double a=ang;
        for(int i=0;i<n;i++){
            int j=(i+1)%n;
            if(a<0) a+=2*pi;
            if(a>=2*pi) a-=2*pi;
            res+=max((long double)0.0,cos(a)*dist[i]);
            a=ang+rad[j]-rad[0];
        }
        return res;
	};
	long double l=0,r=2*pi;
	int iter=70;
	while(iter--){
        long double m1=(l*2+r)/3,m2=(l+r*2)/3;
        if(cycle(m1)<cycle(m2)){
            r=m2;
        }else l=m1;
	}

	cout << setprecision(2) << fixed;
	cout<<cycle(l)<<"\n";
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
