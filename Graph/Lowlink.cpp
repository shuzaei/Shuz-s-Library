struct Lowlink {
    vector<int> lowlink;
    graph g;
    Lowlink(int n) : lowlink(n), g(n) {}
}