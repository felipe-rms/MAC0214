#include <bits/stdc++.h>
using namespace std;

int meio(int a, int b){
    return (a+b)/2;
}

long long buildseg(vector<long long> &x, vector<long long> &seg, int node, int a, int b){
    if(a == b){
        seg[node] = x[a];
        return seg[node];
    }
    int mid = meio(a, b);
    seg[node] = buildseg(x, seg, 2*node+1, a, mid) + buildseg(x, seg, 2*node+2, mid+1, b);
//    printf("sum[%d, %d] = %lld\n", a, b, seg[node]);
    return seg[node];
}

long long query(vector<long long> &seg, int node, int a, int b, int qa, int qb){
    if(qa <= a && b <= qb) return seg[node];
    if(b < qa || qb < a) return 0;
    int mid = meio(a, b);
    return query(seg, node*2+1, a, mid, qa, qb) + query(seg, node*2+2, mid+1, b, qa, qb);
}
void updateseg(vector<long long> &seg, long long diff, int k, int node, int a, int b){
    if(k < a || b < k) return;
    seg[node] += diff;
    if(a < b){
        int mid = meio(a, b);
        if(k <= mid)
            updateseg(seg, diff, k, 2*node+1, a, mid);
        else
            updateseg(seg, diff, k, 2*node+2, mid+1, b);
    }
//    printf("sum[%d, %d] = %lld\n", a, b, seg[node]);
}

int main(){
    int n, q;
    cin >> n >> q;
    vector<long long> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    vector<long long> seg(2*n+1, -1);
    buildseg(x, seg, 0, 0, n-1);
    for(int i = 0; i < q; i++){
        int op; cin >> op;
        if(op == 1){
            int k;
            long long u;
            cin >> k >> u;
            long long diff = u - x[k-1];
            x[k-1] = u;
            updateseg(seg, diff, k-1, 0, 0, n-1);
        }
        else if(op == 2){
            int a, b; cin >> a >> b;
            cout << query(seg, 0, 0, n-1, a-1, b-1) << "\n";
        }
    }
}
