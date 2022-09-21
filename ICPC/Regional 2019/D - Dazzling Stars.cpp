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
#define x first
#define y second
using namespace std;

bool cw(pair<int,int> a, pair<int,int> b, pair<int,int> c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pair<int,int> a, pair<int,int> b, pair<int,int> c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

vector<pair<int,int>> convexHull(vector<pair<int,int>> &a){
    if (a.size() == 1) return vector<pair<int,int>>(1,a[0]);

    sort(all(a));

    pair<int,int> p1 = a[0], p2 = a.back();
    vector<pair<int,int>> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    vector<pair<int,int>> ans;
    for (int i = 0; i < (int)up.size(); i++)
        ans.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        ans.push_back(down[i]);

    return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<pair<int,int>> points(n);
	vector<pair<int,pair<int,int>>> psorted(n);
	for(int i=0;i<n;i++){
        int b,cx,cy;
        cin>>cx>>cy>>b;
        points[i]={cx,cy};
        psorted[i]={b,{cx,cy}};
	}
	vector<pair<int,int>> hull=convexHull(points);
	sort(all(psorted));

    int m=hull.size();
    bool solved=false;
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            ll vx=-(hull[j].y-hull[i].y),vy=hull[j].x-hull[i].x;
            bool ok1=true;
            ll last=INT_MIN;
            for(int k=0;k<n;){
                int b=psorted[k].first;
                ll minv=INT_MAX,maxv=INT_MIN;

                while(k<n && psorted[k].first==b){
                    ll val=vx*psorted[k].second.x+vy*psorted[k].second.y;
                    maxv=max(maxv,val);
                    minv=min(minv,val);
                    k++;
                }

                if(minv<last){
                    ok1=false;
                    break;
                }
                last=maxv;

            }
            bool ok2=true;
            last=INT_MAX;
            for(int k=0;k<n;){
                int b=psorted[k].first;
                ll minv=INT_MAX,maxv=INT_MIN;
                while(k<n && psorted[k].first==b){
                    ll val=vx*psorted[k].second.x+vy*psorted[k].second.y;
                    maxv=max(maxv,val);
                    minv=min(minv,val);
                    k++;
                }

                if(maxv>last){
                    ok2=false;
                    break;
                }
                last=minv;

            }
            if(ok1||ok2){
                solved=true;
                break;
            }
        }
    }
    if(solved) cout<<"Y\n";
    else cout<<"N\n";
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
