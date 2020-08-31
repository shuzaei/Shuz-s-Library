struct link_cut_tree {
    struct node {
        node *pp, *lp, *rp;
        ll idx, data, val, sum, cnt;
        bool rev;
        node(ll i = 0, ll d = 0, ll v = 0) :
            pp(nullptr), lp(nullptr), rp(nullptr), idx(i), data(d), val(v), sum(d), cnt(1), rev(0) {
        }
        bool is_root() { return pp == nullptr or (pp->lp != this and pp->rp != this); }
    };
    void rotr(node *x) {
        node *q = x->pp, *r = q->pp;
        if (q->lp = x->rp; x->rp != nullptr) x->rp->pp = q;
        x->rp = q, q->pp = x;
        update(q), update(x);
        if (x->pp = r; r != nullptr) {
            if (r->lp == q) r->lp = x;
            if (r->rp == q) r->rp = x;
            update(r);
        }
    }
    void rotl(node *x) {
        node *q = x->pp, *r = q->pp;
        if (q->rp = x->lp; x->lp != nullptr) x->lp->pp = q;
        x->lp = q, q->pp = x;
        update(q), update(x);
        if (x->pp = r; r != nullptr) {
            if (r->lp == q) r->lp = x;
            if (r->rp == q) r->rp = x;
            update(r);
        }
    }
    void splay(node *x) {
        push(x);
        while (not x->is_root()) {
            node *q = x->pp;
            if (q->is_root()) {
                push(q), push(x);
                q->lp == x ? rotr(x) : rotl(x);
            } else {
                node *r = q->pp;
                push(r), push(q), push(x);
                if (r->lp == q) {
                    q->lp == x ? rotr(q) : rotl(x), rotr(x);
                } else {
                    q->rp == x ? rotl(q) : rotr(x), rotl(x);
                }
            }
        }
    }
    ll count(node *x) { return x == nullptr ? 0 : x->cnt; }
    ll sum(node *x) { return x == nullptr ? 0 : x->sum; }
    node *update(node *x) {
        x->cnt = count(x->lp) + count(x->rp) + 1;
        x->sum = sum(x->lp) + sum(x->rp) + x->val;
        return x;
    }
    void push(node *x) {
        if (x->rev) {
            swap(x->lp, x->rp);
            if (x->lp != nullptr) x->lp->rev = !x->lp->rev;
            if (x->rp != nullptr) x->rp->rev = !x->rp->rev;
            x->rev = false;
        }
    }
    void toggle(node *x) { x->rev = !x->rev, push(x); }
    node *expose(node *x) {
        node *rp = nullptr;
        for (node *p = x; p != nullptr; p = p->pp) splay(p), p->rp = rp, rp = p, update(p);
        splay(x);
        return rp;
    }
    void cut(node *c) {
        expose(c);
        node *p = c->lp;
        c->lp = p->pp = nullptr;
    }
    void cutb(node *u, node *v) { evert(u), cut(v); }
    void link(node *c, node *p) { expose(c), expose(p), c->pp = p, p->rp = c; }
    void linkb(node *u, node *v) { evert(u), evert(v), link(u, v); }
    void evert(node *x) { expose(x), toggle(x), push(x); }
    node *get_root(node *x) {
        expose(x);
        while (x->lp != nullptr) push(x), x = x->lp;
        splay(x);
        return x;
    }
    node *lca(node *u, node *v) {
        return get_root(u) == get_root(v) ? (expose(u), expose(v)) : nullptr;
    }
    ll path_sum(node *u, node *v) {
        evert(u), expose(v);
        return v->val + sum(v->lp);
    }
    node *update_val(node *x, ll val) {
        expose(x), x->val = val, splay(x);
        return x;
    }
    node *make_node(ll idx = 0, ll dat = 0, ll val = 0) { return new node(idx, dat, val); }
} lct;