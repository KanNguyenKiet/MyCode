#include <bits/stdc++.h>
using namespace std;                                           

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define foru(i, a, b) for(int i = (a); i <= (b); i++)
#define ford(i, a, b) for(int i = (a); i >= (b); i--)
#define endl "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
#define com(a, b) a ## b
#define scv(a, b, c) #a#b#c
#define db(x) cerr << "[" << #x << ": " << (x) << "] " << endl;
#define run cerr << "DONE" << endl; 
template<class T> void printvec(vector<T>& x, int a, int b) {foru (i, a, b) cout << x[i] << " "; cout << endl;}
mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef vector<pll> v2l;
typedef pair<char, int> pci;
typedef vector<pci> vci;

const ld PI = acos((ld) - 1);
const ld EPSILON = 1e-7;
const int N = 1e6 + 123;
const int NN = 1e3 + 1; 
const ll MOD = 1e9 + 7;
const ll oo = LLONG_MAX;
const int BASE = 10000;
const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, 1, 0, -1};
const char dr[4] = {'U', 'R', 'D', 'L'};    

// void make_z(string a, int n, vector<int> &F) {
//     int L = -1, R = -1;
//     F[0] = n;
//     for (int i = 1; i < n; i++) {
//         if (i > R) {
//             L = i;
//             R = i - 1;
//             while (R < n - 1 && a[R + 1] == a[R - L + 1]) R++;
//             F[i] = R - L + 1;
//         } else {
//             if (F[i - L] < R - i + 1)
//                 F[i] = F[i - L];
//             else {
//                 L = i;
//                 while (R < n - 1 && a[R + 1] == a[R - L + 1]) R++;
//                 F[i] = R - L + 1;
//             }
//         }
//     }
// }

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int minmove(string s) {
	int n = s.length();
	int x, y, i, j, u, v; // x is the smallest string before string y
	for (x = 0, y = 1; y < n; ++ y) {
		i = u = x;
		j = v = y;
		while (s[i] == s[j]) {
			++ u; ++ v;
			if (++ i == n) i = 0;
			if (++ j == n) j = 0;
			if (i == x) break; // All strings are equal
		}
		if (s[i] <= s[j]) y = v;
		else {
			x = y;
			if (u > y) y = u;
		}
	}
	return x;
}

void query() {
    int n;
    cin >> n;
    string _;
    getline(cin, _);
    string s;
    while (1) {
        string c;
        getline(cin, c);
        for (char x : c) {
            s.pb(x);
        }
        if (sz(s) >= n) {
            break;
        }
    }
    string c;
    for (int i = 0; i < sz(s); i++) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
            c += tolower(s[i]);
        }
    }
    s = c;
    string t;
    while (1) {
        // run
        string c;
        getline(cin, c);
        t += c;
        // cerr << t << endl;
        if (sz(t) >= n) {
            break;
        }
    }
    c.clear();
    for (int i = 0; i < sz(t); i++) {
        if ((t[i] >= 'A' && t[i] <= 'Z') || (t[i] >= 'a' && t[i] <= 'z')) {
            c += tolower(t[i]);
        }
    }
    t = c;
    string change;
    for (int i = 0; i < sz(s); i++){
        change += ((t[i] - 'a') - (s[i] - 'a') + 25) % 26 + 'a';
    }
    n = sz(change);
    // vector<int> Z(n + 1);
    // make_z(change, n, Z);
    vector<int> Z = z_function(change);
    // for (int i = 0; i < n; i++) {
    //     cout << Z[i] << " ";
    // }
    // cout << endl;
    int pos = 0;
    for (int i = 1; i < n; i++) {
        if (i + Z[i] == n) {
            pos = i;
            break;
        }
    }
    string res;
    if (!pos) {
        res = change;
    } else {
        for (int i = 0; i < pos; i++) {
            res += change[i];
        }
    }
    // cout << res << endl;
    // cout << sz(res) << endl;
    int tt = minmove(res);
    // cout << tt << endl;
    string ans;
    for (int i = tt; i < sz(res); i++) {
        ans += res[i]; 
    }
    for (int i = 0; i < tt; i++) {
        ans += res[i];
    }
    cout << ans << endl;
}

void solve() {
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        query();
    }
}

int main() {
    #ifdef DEBUG
        com(fre, open) (scv(solve, ., inp), "r", stdin);
        com(fre, open) (scv(solve, ., out), "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); 
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}