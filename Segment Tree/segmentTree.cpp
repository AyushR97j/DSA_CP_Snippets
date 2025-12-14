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
