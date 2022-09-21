#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	vi num;

    string s; cin >> s;
    int n = s.size();

    for(int i = 0; i < (int) s.size(); i++)
        num.pb(s[i]-'0');

    int cnt[10];
    for(int i = 1; i <= 9; i++)
        cin >> cnt[i];

    vi nxt(n), prev(n);

    for(int i = 0; i < n; i++) {
        nxt[i] = i+1;
        prev[i] = i-1;
    }

    for(int i = 1; i <= 9; i++) {
        bool ok;
        do{
        ok=false;
        for(int j = 0; j < n; j++) {
            if(num[j] == i and nxt[j] < n and num[nxt[j]] > num[j] and cnt[i]) {
                ok=true;
                num[j] = -1;
                if(prev[j] >= 0) nxt[prev[j]] = nxt[j];
                if(nxt[j] < n) prev[nxt[j]] = prev[j];
                cnt[i]--;
            }
        }

        }while(ok);

        for(int j = n-1; j >= 0; j--) {
            if(num[j] == i and cnt[i]) {
                num[j] = -1;
                cnt[i]--;
                nxt[prev[j]] = nxt[j];
                prev[nxt[j]] = prev[j];
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(num[i] != -1) cout << num[i];
    }

	return 0;
}
