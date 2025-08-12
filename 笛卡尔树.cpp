
int buildCartesianMin_stack(const vector<int>& a,
                            vector<int>& ls,
                            vector<int>& rs,
                            vector<int>& parent) {
    int n = (int)a.size();
    ls.assign(n, -1);
    rs.assign(n, -1);
    parent.assign(n, -1);

    stack<int> st;
    int root = -1;

    for (int i = 0; i < n; ++i) {
        int last = -1;
        while (!st.empty() && a[st.top()] > a[i]) {
            last = st.top();
            st.pop();
        }
        if (!st.empty()) {
            rs[st.top()] = i;
            parent[i] = st.top();
        } else {
            root = i;
        }
        if (last != -1) {
            ls[i] = last;
            parent[last] = i;
        }
        st.push(i);
    }
    return root;
}
