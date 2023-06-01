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
#define pt pair<int,int>
#define x first
#define y second

using namespace std;

int cross(pt a,pt b,pt c){
    pt u={a.x-b.x,a.y-b.y};
    pt v={c.x-b.x,c.y-b.y};
    return u.x*v.y-u.y*v.x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<pt> p(n);
	for(int i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
	}
	int ans=0;
	for(int i=0;i<n;i++){
        int j=(i+1)%n,k=(i+2)%n;
        //cout<<cross(p[i],p[j],p[k])<<"\n";
        if(cross(p[i],p[j],p[k])<0 && p[i].y>p[j].y && p[k].y>p[j].y){

            ans++;
        }
	}
	int last,cnt=0,i=0;
	for(i=0;i<n;i++){
        int j=(i+1)%n;
        if(p[i].y!=p[j].y){
            last=p[j].y-p[i].y;
            break;
        }
	}
	int j,k;
	for(j=(i+1)%n;j!=i;j=(j+1)%n){
        k=(j+1)%n;
        if(p[j].y==p[k].y && p[j].x<p[k].x){
            cnt++;
        }
        if(p[j].y!=p[k].y){
            if(cnt){
                if(last<0 && p[k].y-p[j].y>0){
                    ans++;

                }
            }
            last=p[k].y-p[j].y;
            cnt=0;
        }
	}
	k=(j+1)%n;
	if(p[j].y!=p[k].y){
        if(cnt){
            if(last<0 && p[k].y-p[j].y>0){
                ans++;

            }
        }
        last=p[k].y-p[j].y;
        cnt=0;
    }
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
