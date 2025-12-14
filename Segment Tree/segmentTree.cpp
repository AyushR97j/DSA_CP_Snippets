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
