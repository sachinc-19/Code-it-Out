int build(int *tree , int *a , int s , int e , int tidx)
{
    if(s==e)
      return a[s];
    int mid = (s+e)/2;
    tree[2*tidx] = build(tree , a , s , mid , 2*tidx);
    tree[2*tidx+1] = build(tree , a , mid+1 , e , 2*tidx+1);
    return tree[tidx] = tree[2*tidx] + tree[2*tidx+1];
}
int sum_query(int *tree , int s , int e , int l , int r , int idx)
{
    if(e < l || s > r) return 0;
    else if(s >= l && e <= r) return tree[idx];
    int mid = (s+e)/2;
    int left = sum_query(tree , s , mid , l , r , 2*idx);
    int right = sum_query(tree , mid+1 , e , l , r , 2*idx+1);
    return left+right;
}
void update(int *tree , int *a , int s , int e , int i , int v , int idx)
{
    if(s==e && i == s) {
      a[i] = v;
      tree[idx] = v;
      return ;
     }
    int mid = (s+e)/2;
    if(i > mid){
      update(tree , a , mid+1 , e , i , v , 2*idx+1);
     }
    else
    {
      update(tree , a , s , mid , i , v , 2*idx);
    }
    tree[idx] = tree[2*idx]+tree[2*idx+1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // range sum query
    int n , q , l , r , type ;
    cin >> n >> q;
    int *arr = new int[n];
    fon(i , n) cin >> arr[i];
    int *segtree = new int[4*n];
    build(segtree , arr , 0 , n-1 , 1);
    while(q--)
    {
       if(type == 1)
       {
          cin >> type >> l >> r;
          cout << sum_query(segtree , 0 , n-1 , l-1 , r-1 , 1) << endl;
       }
       else
       {
          update(segtree , arr , 0 , n-1 , l-1 , r , 1);
       }
    }
    delete[] arr;
    delete[] segtree;
}
console.log('');
