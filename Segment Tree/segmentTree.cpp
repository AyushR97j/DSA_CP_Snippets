void buildSegmentTree(int i, int l, int r, vector<int> &segmentTree, int arr[]) {
    if (l == r)
    {
        segmentTree[i] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;
    buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
    buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);
    segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
}

// T.C : O(q*log(n))
// S.C : O(4*n)