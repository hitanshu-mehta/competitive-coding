vector<vector<int>> matmul(const vector<vector<int>> &a, const vector<vector<int>> &b, int mod = MOD) {
    int r = a.size(), c = b[0].size(), m = a[0].size();
    assert(m == (int) b.size());
    vector<vector<int>> res(r, vector<int>(c, 0LL));
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            for (int k = 0; k < m; ++k) {
                res[i][j] += (long long) a[i][k] * b[k][j] % MOD;
                if (res[i][j] >= MOD) res[i][j] -= MOD;
            }
    return res;
};
vector<int> vecmul(const vector<int> &a, const vector<vector<int>> &b, int mod = MOD) {
    // vector {.., .., ..} x {{..}, {..}, .., {..}}
    // return vector
    int m = a.size();
    assert(m == (int) b.size() && b.size() == b[0].size());
    vector<int> res(m, 0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            res[i] += (long long) a[j] * b[j][i] % MOD;
            if (res[i] >= MOD) res[i] -= MOD;
        }
    }
    return res;
};
vector<vector<int>> matpow(vector<vector<int>> base, long long ex) {
    assert(base[0].size() == base.size());
    int s = base.size();
    vector<vector<int>> res(s, vector<int>(s, 0));
    for (int i = 0; i < s; ++i) res[i][i] = 1;
    while (ex > 0) {
        if (ex & 1) res = matmul(base, res);
        base = matmul(base, base);
        ex >>= 1;
    }
    return res;
};

struct Matrix {
  static int const N = 2;
  using T = int;
  T x[N][N];
  int n, m;
  Matrix(int _n = N, int _m = N, T val = 0): n(_n), m(_m) {
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
      x[i][j] = val;
  }
  T* operator [] (int r) {
    return x[r];
  }
  const T* operator [] (int r) const {
    return x[r];
  }
  static Matrix unit(int n) {
    Matrix res(n, n);
    for (int i = 0; i < n; i++) res[i][i] = 1;
    return res;
  }
  static Matrix fib_base() {
    Matrix res(2, 2, 1); res[0][0] = 0;
    return res;
  }
  Matrix& operator += (const Matrix &rhs) {
    assert (n == rhs.n && m == rhs.m);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
      x[i][j] += rhs[i][j];
      if (x[i][j] >= MOD) x[i][j] -= MOD;
    }
    return *this;
  }
  Matrix operator + (const Matrix &rhs) const {
    Matrix lhs(*this);
    return lhs += rhs;
  }
  friend Matrix operator * (const Matrix &A, const Matrix &B) {
    assert (A.m == B.n);
    Matrix res(A.n, B.m);
    for (int i = 0; i < res.n; i++) for (int j = 0; j < res.m; j++) {
      long long sum = 0LL;
      for (int k = 0; k < A.m; k++) {
        sum += (long long) A[i][k] * B[k][j];
        if (sum >= SQMOD) sum -= SQMOD;
      }
      res[i][j] = (int) (sum % MOD);
    }
    return res;
  }
  friend Matrix operator ^ (Matrix base, long long ex) {
    assert (base.n == base.m);
    Matrix res = Matrix::unit(base.n);
    while (ex > 0) {
      if (ex & 1) res = res * base;
      base = base * base;
      ex >>= 1;
    }
    return res;
  }
  Matrix& operator *= (const Matrix &rhs) {
    return *this = *this * rhs;
  }
  Matrix& operator ^= (const long long &ex) {
    return *this = *this ^ ex;
  }
  friend ostream &operator << (ostream &os, const Matrix& A) {
    os << "(" << A.n << " x " << A.m << ")" << endl;
    os << string(A.m * 2, '-');
    for (int i = 0; i < A.n; ++i) {
      os << endl;
      for (int j = 0; j < A.m; ++j) os << A[i][j] << ' ';
    }
    return os << endl << string(A.m * 2, '-');
  }
};

// Calculate geometric series: A^0 + A^1 + ... + A^k
Matrix geometricseries(Matrix A, long long k) {
  assert (A.n == A.m);
  if (k == 0) return unit(A.n);
  if (k == 1) return A + unit(A.n);
  vector<int> bit;
  while (k > 0) {
    bit.push_back(k & 1);
    k >>= 1;
  }
  Matrix res = A, tmp = A;
  for (int i = (int) bit.size() - 2; i >= 0; i--) {
      res = res + (res * tmp);
      tmp = tmp * tmp;
      if (bit[i] & 1) {
          tmp = tmp * A;
          res = res + tmp;
      }
  }
  res = res + unit(A.n);
  return res;
}
