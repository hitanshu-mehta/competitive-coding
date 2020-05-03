#include <bits/stdc++.h>
using namespace std;
#define SZ(v) int((v).size())
#define ALL(vec) begin(vec), end(vec)
typedef long long i64;
template<typename T> inline bool uax(T &x, T y) {return (y > x) ? x = y, true : false;}
template<typename T> inline bool uin(T &x, T y) {return (y < x) ? x = y, true : false;}
#ifdef Rahul
# define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
  stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#else
# define error(...) 42;
#endif
string to_string(char c) { return "'" + string(1, c) + "'";}
string to_string(string s) { return '"' + s + '"';}
string to_string(const char* s) { return to_string((string) s);}
template<typename A> string to_string(A);
template<typename A, typename B> string to_string(pair<A, B> p){
  return "(" + to_string(p.first) + ": " + to_string(p.second) + ")";}
template<typename A> string to_string(A v) {bool f = false; string r = "{"; 
  for (auto x: v) {if (f) r += ", "; r += to_string(x); f = true;} return r += "}";}
template<typename A> string to_string(vector<vector<A>> v) {string r; 
  for (auto x: v) r += "\n" + to_string(x); return r;}
int Nerr;
template<typename A> string to_string(A *p) {return to_string(vector<A>(p, p + Nerr));}
void err(istream_iterator<string>) { cerr << endl; }
template<typename T,typename... Args> void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " =: " << to_string(a) << "; "; err(++it, args...); }
template<typename T> void kek(T ans) {cout << ans << endl; exit(0);}
#define Lu(...) [&] (auto &&u) { return __VA_ARGS__; }
#define Luv(...) [&] (auto &&u, auto &&v) { return __VA_ARGS__; }
int const MOD = 1e9 + 7;
i64 const INF = 1e18 + 42;
/***********************************************************************/
void solve_case();
void run();
int32_t main() {
  cin.tie(nullptr) -> sync_with_stdio(false);
  
  run();
  int tt; cin >> tt;
  for (int t = 1; t <= tt; ++t) {
    cout << "Case #" << t << ": ";
    solve_case();
  }
}

void run() {
}
void solve_case() {
  int r, s; cin >> r >> s;
  int n = r * s;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = i % r;
  }
  vector<pair<int,int>> ans;
  while (1) {
    error(a);
    if (is_sorted(ALL(a))) break;
    int b = a.back(), p = 0;
    while (1) {
      int ok = 1;
      p = 0;
      for (int j = 0; j < s; ++j) {
        ok &= a[SZ(a) - j - 1] == b;
        if (ok) p = j + 1;
      }
      if (!ok) break;
      a.resize(SZ(a) - s);
      b = a.back();
    }
    int q = p;
    q = SZ(a) - q - 1;
    while (SZ(a) - p - 1 >= 0 && a[SZ(a) - p - 1] != b) ++p;
    p = SZ(a) - p - 1;
    error(p, q);
    ans.emplace_back(p + 1, q - p);
    vector<int> c = a;
    int x = p + 1, y = q - p;
    for (int i = 0; i < y; ++i) {
      a[i] = c[x + i];
    }
    for (int i = y; i < x + y; ++i) {
      a[i] = c[i - y];
    }
  }
  error(ans);
  cout << SZ(ans) << '\n';
  for (auto &pr : ans) {
    cout << pr.first << ' ' << pr.second << '\n'; 
  }
}
