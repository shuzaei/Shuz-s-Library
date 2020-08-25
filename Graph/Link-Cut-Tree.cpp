struct link_cut_tree {
    struct node {
        node *pp, *lp, *rp;
        ll idx, data;
        node(ll i = 0, ll val = 0) : pp(nullptr), lp(nullptr), rp(nullptr), idx(i), data(val) {}
        bool is_root() { return pp == nullptr or (pp->lp != this and pp->rp != this); }
        void rotr() {
            node *q = pp, *r = q->pp;
            if (q->lp = rp; rp != nullptr) rp->pp = q;
            rp = q, q->pp = this;
            if (pp = r; r != nullptr) {
                if (r->lp == q) r->lp = this;
                if (r->rp == q) r->rp = this;
            }
        }
        void rotl() {
            node *q = pp, *r = q->pp;
            if (q->rp = lp; lp != nullptr) lp->pp = q;
            lp = q, q->pp = this;
            if (pp = r; r != nullptr) {
                if (r->lp == q) r->lp = this;
                if (r->rp == q) r->rp = this;
            }
        }
        void splay() {
            while (not is_root()) {
                node *q = pp;
                if (q->is_root()) q->lp == this ? rotr() : rotl();
                else {
                    node *r = q->pp;
                    if (r->lp == q) {
                        q->lp == this ? q->rotr() : rotl(), rotr();
                    } else {
                        q->rp == this ? q->rotl() : rotr(), rotl();
                    }
                }
            }
        }
    };
    node *expose(node *x) {
        node *rp = nullptr;
        for (node *p = x; p != nullptr; p = p->pp) p->splay(), p->rp = rp, rp = p;
        x->splay();
        return rp;
    }
    void cut(node *c) {
        expose(c);
        node *p = c->lp;
        c->lp = p->pp = nullptr;
    }
    void cut(node *u, node *v) { expose(u), u->lp == v ? cut(u) : cut(v); }
    void link(node *c, node *p) { expose(c), expose(p), c->pp = p, p->rp = c; }
    node *get_root(node *x) {
        expose(x);
        while (x->lp != nullptr) x = x->lp;
        return x;
    }
    node *lca(node *u, node *v) {
        return get_root(u) == get_root(v) ? (expose(u), expose(v)) : nullptr;
    }
    node *make_node(ll idx = 0, ll val = 0) { return new node(idx, val); }
} lct;