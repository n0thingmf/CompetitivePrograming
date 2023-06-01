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
	cout << setprecision(12) << fixed;
	int n,a,b;
	cin>>n>>a>>b;
	double prob=1,prob_0=1;
	prob/=b-a+1;
	prob_0/=(b-a+1);
	//prob_0*=b-a+1;
	vector<double> p(n,0);
	vector<double> sp(n+1,0);
	if(a==0){
        p[0]=(b-a+1);
        p[0]/=b-a;
	}else{
        p[0]=1;
	}
	sp[0]=0,sp[1]=p[0];
	for(int i=1;i<n;i++){
        p[i]=(sp[max(i-max(a,1)+1,0)]-sp[max(i-b,0)])*prob;
        /*for(int j=max(a,1);j<=b;j++){
            if(i-j>=0) p[i]+=p[i-j]*prob;
        }*/
        if(a==0) p[i]*=b-a+1,p[i]/=b-a;
        sp[i+1]=sp[i]+p[i];
	}
	double ans=0;
	for(int i=0;i<n;i++) ans+=p[i];

	cout<<ans<<"\n";
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
