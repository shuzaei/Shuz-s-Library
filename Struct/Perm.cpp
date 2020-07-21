using Perm = vector<ll>;

Perm e(ll n) {
    Perm a(n);
    rep(i, n) a[i] = i;
    return a;
}
Perm rev(Perm a) {
    Perm b(len(a));
    rep(i, len(a)) b[a[i]] = i;
    return b;
}
Perm mul(Perm a, Perm b) {
    Perm c(len(a));
    rep(i, len(a)) c[i] = b[a[i]];
    return c;
}
Perm pow(Perm a, ll n) {
    if (!n) return e;
    Perm b = pow(a, n >> 1);
    b = mul(b, b);
    if (n & 1) b = mul(b, a);
    return b;
}