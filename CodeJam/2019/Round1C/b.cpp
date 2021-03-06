#include <bits/stdc++.h>
//~ #include <ext/pb_ds/assoc_container.hpp>
//~ #include <ext/pb_ds/tree_policy.hpp>
//~ template<typename T, typename V = __gnu_pbds::null_type>
//~ using ordered_set = __gnu_pbds::tree<T, V, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; // find_by_order(), order_of_key()

#define SZ(v) (int((v).size()))
#define ALL(vec) (vec).begin(),(vec).end()
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
using namespace std;
 
using i64 = long long int;
template <typename T> inline bool uax(T &x, T y) {return (y > x) ? x = y, true : false;}
template <typename T> inline bool uin(T &x, T y) {return (y < x) ? x = y, true : false;}
 
void err(__attribute__((unused)) istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " =: " << a << endl;
  err(++it, args...);
}
template <typename T1, typename T2>
inline ostream& operator << (ostream& os, const pair<T1, T2>& buf) {
  return os << "(" << buf.first << ": " << buf.second << ")";
}
template<typename T>
inline ostream &operator << (ostream & os,const vector<T>& v) {
  bool first = true;
  os << "[";
  for (const auto &e: v) {
    if(!first) os << ", ";
    os << e;
    first = false;
  }
  return os << "]";
}
template<typename T>
inline ostream &operator << (ostream & os, multiset<T>& v) {
  bool first = true;
  os << "{";
  for (auto ii = v.begin(); ii != v.end(); ++ii) {
    if(!first) os << ", ";
    os << *ii;
    first = false;
  }
  return os << "}";
}
template<typename T>
inline ostream &operator << (ostream & os,const unordered_set<T>& v) {
  bool first = true;
  os << "{";
  for (const auto &x : v) {
    if(!first) os << ", ";
    os << x;
    first = false;
  }
  return os << "}";
}
template<typename T1, typename T2>
inline ostream &operator << (ostream & os,const map<T1, T2>& v) {
  bool first = true;
  os << "{";
  for (const auto &e : v) {
    if(!first) os << ", ";
    os << e;
    first = false;
  }
  return os << "}";
}
template<typename T>
ostream &operator << (ostream & os,const vector<vector<T>>& v) {
  for (auto &u: v) os << '\n' << u;
  return os;
}
template<typename T>
void finish(T ans) {cout << ans << '\n'; exit(0);}
int const MOD = 1e9 + 7;
long long const INF = 1e18;
#define PI 3.14159265358979323846
/***********************************************************************/
char ask(int x) {
  cout << x + 1 << endl;
  char c; cin >> c;
  if (c == 'N') exit(0);
  return c;
}
void test_case() {

  string ans;
  vector<int> ind(119);
  iota(ALL(ind), 0);
  int p = 0;
  vector<bool> done(5, false);
  for (int j: {23, 5, 1, 0}) {
    vector<vector<int>> a(5);
    for (int &i: ind) {
      a[ask(i * 5 + p) - 'A'].push_back(i);
    }
    ++p;
    for (int i = 0; i < 5; ++i) if (!done[i]) {
      if (SZ(a[i]) == j) {
        ind = a[i];
        ans += (char) ('A' + i);
        done[i] = true;
      }
    }
  }
  for (int i = 0; i < 5; ++i) if (!done[i]) ans += (char) ('A' + i);
  cout << ans << endl;
  char ver; cin >> ver;
  if (ver == 'N') exit(0);
  
  return;
}

signed main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt, f;
  cin >> tt >> f;
  for (int t = 1; t <= tt; ++t) {
    //~ cout << "Case #" << t << ": ";
    test_case();
  }
  
  return 0;
}
