#define ll long long
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int cmp(const void* a, const void* b) {
    return *(const ll*) b > *(const ll*) a;    
}

void dfs(struct TreeNode* root, ll* sum, int idx, int* d) {
    if (!root) return;
    sum[idx] += root->val;
    dfs(root->left, sum, idx+1, d);
    dfs(root->right, sum, idx+1, d);
    (*d) = MAX((*d), idx);
}

long long kthLargestLevelSum(struct TreeNode* root, int k) {
    int d = 0;
    ll* sum = (ll*) calloc(100000, sizeof(ll));
    dfs(root, sum, 0, &d);
    qsort(sum, d+1, sizeof(ll), cmp);
    ll ans = (k-1 < d+1) ? sum[k-1] : -1;
    free(sum);
    return ans;
}
