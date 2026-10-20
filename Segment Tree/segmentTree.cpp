void buildSegmentTree(int i, int l, int r, vector<int> &segmentTree, int arr[]) {
    if (l == r)
    {
        segmentTree[i] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;
    buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
    buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);
    segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2]; //using 0-indexed array tree → children of i are 2*i+1 and 2*i+2.
                                                                      //if using 1-indexed array tree → children of i are 2*i and 2*i+1.
}

int querySegmentTree(int start, int end, int i, int l, int r, vector<int>& segmentTree) {
        if(l > end || r < start) {
            return 0;
        }
        
        if(l >= start && r <= end) {
            return segmentTree[i];
        }
        
        int mid = l + (r-l)/2;
        return querySegmentTree(start, end, 2*i+1, l,    mid, segmentTree) + 
               querySegmentTree(start, end, 2*i+2, mid+1, r, segmentTree);
    }
// T.C : O(q*log(n))
// S.C : O(4*n)


//Complete code for Range Sum & Range Min & Point Update
/*
#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long sum;
    int mn;
};

vector<Node> seg;
vector<int> arr;

Node merge(Node a, Node b) {
    return {a.sum + b.sum, min(a.mn, b.mn)};
}

void build(int i, int l, int r) {
    if (l == r) {
        seg[i] = {arr[l], arr[l]};
        return;
    }
    int mid = (l + r) / 2;
    build(2*i+1, l, mid);
    build(2*i+2, mid+1, r);
    seg[i] = merge(seg[2*i+1], seg[2*i+2]);
}

void pointUpdate(int i, int l, int r, int idx, int val) {
    if (l == r) {
        seg[i] = {val, val};
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid)
        pointUpdate(2*i+1, l, mid, idx, val);
    else
        pointUpdate(2*i+2, mid+1, r, idx, val);
    seg[i] = merge(seg[2*i+1], seg[2*i+2]);
}

Node query(int i, int l, int r, int ql, int qr) {
    if (qr < l || r < ql)
        return {0, INT_MAX};
    if (ql <= l && r <= qr)
        return seg[i];
    int mid = (l + r) / 2;
    return merge(
        query(2*i+1, l, mid, ql, qr),
        query(2*i+2, mid+1, r, ql, qr)
    );
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    seg.resize(4*n);
    build(0, 0, n-1);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int idx, val;
            cin >> idx >> val;
            pointUpdate(0, 0, n-1, idx, val);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << query(0, 0, n-1, l, r).mn << '\n';
        } else if (type == 3) {
            int l, r;
            cin >> l >> r;
            cout << query(0, 0, n-1, l, r).sum << '\n';
        }
    }
}

*/


//Complete code for Range Sum & Point Update & Range Update (Lazy Propagation)
//Range Update : add val to every element in [l, r]
/*
#include <bits/stdc++.h>
using namespace std;

vector<long long> seg, lazy; // lazy[i] = pending add for every element in node i's range
vector<long long> arr;

void build(int i, int l, int r) {
    if (l == r) {
        seg[i] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2*i+1, l, mid);
    build(2*i+2, mid+1, r);
    seg[i] = seg[2*i+1] + seg[2*i+2];
}

// apply pending lazy value of node i to itself and pass it to its children
void push(int i, int l, int r) {
    if (lazy[i] != 0) {
        seg[i] += (r - l + 1) * lazy[i];
        if (l != r) {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
}

// add val to every element in [ql, qr]
void rangeUpdate(int i, int l, int r, int ql, int qr, long long val) {
    push(i, l, r);
    if (qr < l || r < ql)
        return;
    if (ql <= l && r <= qr) {
        lazy[i] += val;
        push(i, l, r);
        return;
    }
    int mid = (l + r) / 2;
    rangeUpdate(2*i+1, l, mid, ql, qr, val);
    rangeUpdate(2*i+2, mid+1, r, ql, qr, val);
    seg[i] = seg[2*i+1] + seg[2*i+2];
}

// set arr[idx] = val
void pointUpdate(int i, int l, int r, int idx, long long val) {
    push(i, l, r);
    if (l == r) {
        seg[i] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid)
        pointUpdate(2*i+1, l, mid, idx, val);
    else
        pointUpdate(2*i+2, mid+1, r, idx, val);
    push(2*i+1, l, mid);
    push(2*i+2, mid+1, r);
    seg[i] = seg[2*i+1] + seg[2*i+2];
}

// sum of [ql, qr]
long long query(int i, int l, int r, int ql, int qr) {
    push(i, l, r);
    if (qr < l || r < ql)
        return 0;
    if (ql <= l && r <= qr)
        return seg[i];
    int mid = (l + r) / 2;
    return query(2*i+1, l, mid, ql, qr) + query(2*i+2, mid+1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    seg.assign(4*n, 0);
    lazy.assign(4*n, 0);
    build(0, 0, n-1);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {            // 1 idx val    -> arr[idx] = val
            int idx;
            long long val;
            cin >> idx >> val;
            pointUpdate(0, 0, n-1, idx, val);
        } else if (type == 2) {     // 2 l r val    -> add val to arr[l..r]
            int l, r;
            long long val;
            cin >> l >> r >> val;
            rangeUpdate(0, 0, n-1, l, r, val);
        } else if (type == 3) {     // 3 l r        -> print sum of arr[l..r]
            int l, r;
            cin >> l >> r;
            cout << query(0, 0, n-1, l, r) << '\n';
        }
    }
    return 0;
}
// T.C : O(log(n)) per query/update
// S.C : O(4*n)
*/
