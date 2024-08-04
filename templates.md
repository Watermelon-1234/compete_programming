### 線性篩
```cpp=
bitset<MAXN> prime_bool;
vector<ll> prime;

//線性篩
void find_prime(){
    prime_bool.set();
    for(int i=2;i<MAXN;i++){
        if(prime_bool[i]){
            prime.push_back(i);
        }
        for(auto j:prime){
            if(j*i>=MAXN)
                break;
            prime_bool[j*i]=0;
            if(i%j==0)
                break;
        }
    }
}
```

### 拓展歐基里德
```cpp=
int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    int gcd=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return gcd;
}
```

### BIT
```cpp=
int n;
vll BIT;

void update_add(int idx,int val){
    while(idx<=n){
        BIT[idx]+=ll(val);
        idx+=(idx&-idx);
    }
}

ll query(int idx){
    ll res=0;
    while(idx>0){
        res+=BIT[idx];
        idx-=(idx&-idx);
    }
    return res;
}
```

### pbds平板電視
```cpp=
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

ordered_set.order_of_key(n)//找有幾個數小於n
ordered_set.find_by_order(n)//找第n小的數
```
### 快速冪
```cpp=
int qpow(int a,int b){
    int res=1;
    while(b){
        if(b&1)
            res*=a;
        b>>=1;
        a*=a;
    }
    return res;
}
```

### 線段樹
```cpp=
const int N=5e5+5;
int n;
ll seg[N<<2],tag[N<<2];
//線段樹與懶惰標記

void merge(int idx){
    seg[idx]=seg[idx<<1]+seg[idx<<1|1];
    //區間最大要把return x+y改成max(x,y)
}

void build(int idx=1,int l=1,int r=n){//創建線段樹
    if(l==r){
        cin>>seg[idx];
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    merge(idx);
}

void push_tag(int idx,int l,int r){
    if(tag[idx]){
        int mid=(l+r)>>1;
        seg[idx<<1]+=(mid-l+1)*tag[idx];
        seg[idx<<1|1]+=(r-mid)*tag[idx];
        tag[idx<<1]+=tag[idx];
        tag[idx<<1|1]+=tag[idx];
        tag[idx]=0;
    }
}

void update_range(int ql,int qr,ll val,int idx=1,int l=1,int r=n){//區間加值
    if(l!=r)
        push_tag(idx,l,r);
    if(ql<=l&&r<=qr){
        seg[idx]+=(r-l+1)*val;
        tag[idx]+=val;
        return;
    }
    int mid=(l+r)>>1;
    if(qr<=mid)
        update_range(ql,qr,val,idx<<1,l,mid);
    else if(ql>mid)
        update_range(ql,qr,val,idx<<1|1,mid+1,r);
    else{
        update_range(ql,qr,val,idx<<1,l,mid);
        update_range(ql,qr,val,idx<<1|1,mid+1,r);
    }
    merge(idx);
}

ll query(int ql,int qr,int idx=1,int l=1,int r=n){//區間查詢
    if(l!=r)
        push_tag(idx,l,r);
    //ql~qr為欲查詢的範圍
    if(ql<=l&&r<=qr)
        return seg[idx];
    int mid=(l+r)>>1;
    if(mid>=qr)
        return query(ql,qr,idx<<1,l,mid);
    else if(ql>mid)
        return query(ql,qr,idx<<1|1,mid+1,r);
    else
        return query(ql,qr,idx<<1,l,mid)+query(ql,qr,idx<<1|1,mid+1,r);
        //區間最大要把return x+y改成max(x,y)
}

void update(int pos,ll val,int idx=1,int l=1,int r=n){//單點更新
    if(l==r){
        seg[idx]+=val;
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid)
        update(pos,val,idx<<1,l,mid);
    else
        update(pos,val,idx<<1|1,mid+1,r);
    merge(idx);
}
```

### 01背包問題
```cpp=
for(int i=1;i<=n;i++){
    for(int j=x;j>=w[i];j--){
        dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    }
}
```

### 無限背包問題
```cpp=
for(int i=1;i<=W;i++){ // 從小到大遍歷重量
    for(int j=1;j<=n;j++){ // 遍歷每個物品
        if(i>=w[j]) dp[i]=max(dp[i],dp[i-w[j]]+v[j]);
    }
}
```

### LIS 最長遞增子序列(DP為求得LIS實際子序列)
```cpp=
for(int i=0;i<num.size();i++){
    if(lis.empty()||lis.back()<num[i]){
        lis.push_back(num[i]);
        dp[i]=lis.size();
    }
    else{
        auto iter=lower_bound(all(lis),num[i]);
        dp[i]=iter-lis.begin()+1;
        *iter=num[i];
    }
}
int length=lis.size();
for(int i=num.size()-1;i>=0;i--){
    if(dp[i]==length){
        ans.push_back(num[i]);
        length--;
    }
}
```

### 拓樸排序
```cpp=
void Topological_sorting(){
    queue<int> que;
    for(int i=1;i<=n;i++){
        if(!in[i]){
            que.push(i);
        }
    }
    while(!que.empty()){
        int cur=que.front();
        que.pop();
        ans.push_back(cur);
        for(const auto &i:out[cur]){
            in[i]--;
            if(!in[i])
                que.push(i);
        }
    }
}
```

### 樹直徑
```cpp=
void DFS(int cur,int last,int dis=0){
    if(dis>mx)
        mx=dis,r=cur;
    for(const auto &i:routs[cur]){
        if(i==last)
            continue;
        DFS(i,cur,dis+1);
    }
}
```

### 一般並查集
```cpp=
int f(int cur){
    return num[cur]==cur?cur:num[cur]=f(num[cur]);
}

void merge(int a,int b){
    a=f(a),b=f(b);
    if(a!=b){
        cnt--;
        num[b]=a;
    }
}
for(int i=0;i<n;i++)//初始化
    num[i]=i;
```

### 並查集(連通塊與最大連接數)
```cpp=
int f(int cur){
    return num[cur]<0?cur:num[cur]=f(num[cur]);
}

void connect(int a,int b){
    a=f(a),b=f(b);
    if(a!=b){
        num[a]+=num[b];
        mx=max(mx,-num[a]);
        num[b]=a;
        heap--;
    }
}
```

### 最小生成樹 MST
```cpp=
sort(all(cost),cmp);//a.cost<b.cost
for(const auto &i:cost){
    int a=f(i.a),b=f(i.b);//使用一般並查集
    if(a!=b){
        num[b]=a;
        counter--;
        ans+=i.cost;
    }
}
```

### Dijkstra
```cpp=
void Dijkstra(){
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,1}),ans[1]=0;
    while(!pq.empty()){
        pll cur=pq.top();
        pq.pop();
        if(cur.first>ans[cur.second])
            continue;
        for(const auto &i:routs[cur.second]){
            if(ans[i.second]>cur.first+i.first){
                ans[i.second]=cur.first+i.first;
                pq.push({ans[i.second],i.second});
            }
        }
    }
}
```

### Floyd warshall(DP)
```cpp=
void Floyd_warshall(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
            }
        }
    }
}
```

### 找cycle
```cpp=
void DFS(int cur,int last=0){
    if(cur==last||found)
        return;
    visited[cur]=1;
    for(const auto &i:routs[cur]){
        if(visited[i]==0){
            pre[i]=cur;
            DFS(i,cur);
        }
        else if(visited[i]==1){
            print_cycle(i,cur);
            found=1;
            return;
        }
    }
    visited[cur]=2;
}
```

### 單調隊列(求最大最小)
```cpp=
deque<int> mx,mn;
for(int i=0;i<n;i++){
    if(!mx.empty()&&i-mx.front()>=window)
        mx.pop_front();
    if(!mn.empty()&&i-mn.front()>=window)
        mn.pop_front();
    while(!mx.empty()&&num[mx.back()]<num[i])
        mx.pop_back();
    while(!mn.empty()&&num[mn.back()]>num[i])
        mn.pop_back();
    mx.push_back(i),mn.push_back(i);
    if(i>=window-1){
        ans_max.push_back(num[mx.front()]);
        ans_min.push_back(num[mn.front()]);
    }
}
```

### 字串編輯距離(DP)
```cpp=
for(int i=1;i<=a;i++){
    for(int j=1;j<=b;j++){
        if(s1[i-1]==s2[j-1])
            dp[i][j]=dp[i-1][j-1];
        else
            dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
    }
}
```

### LCS 最長公共子序列(DP)
```cpp=
for(int i=1;i<=s1.size();i++){
    for(int j=1;j<=s2.size();j++){
        if(s1[i-1]==s2[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
}
```

### 二元樹(以preorder和inorder建成)
```cpp=
class Node{
public:
    char data;
    Node* left;
    Node* right;
    Node(char value){
        data=value;
        right=nullptr;
        right=nullptr;
    }
};

class Tree{
public:
    Node* root;
    Tree(){
        root=nullptr;
    }

    Node* build_tree(vector<char>& preorder,vector<char>& inorder){
        if(preorder.empty()||inorder.empty()){
            return nullptr;
        }
        Node* point=new Node(preorder[0]);
        auto findit=find(all(inorder),preorder[0]);
        int length=findit-inorder.begin();
        vector<char> inorder_left(inorder.begin(),findit);
        vector<char> inorder_right(findit+1,inorder.end());
        vector<char> preorder_left(preorder.begin()+1,preorder.begin()+1+length);
        vector<char> preorder_right(preorder.begin()+1+length,preorder.end());
        point->left=build_tree(preorder_left,inorder_left);
        point->right=build_tree(preorder_right,inorder_right);
        return point;
    }

    void Postorder(Node* x){
        if(x){
            Postorder(x->left);
            Postorder(x->right);
            cout<<x->data;
        }
    }

    void del_tree(Node* x){
        if(x==nullptr)
            return;
        del_tree(x->left);
        del_tree(x->right);
        delete x;
    }
};
```

### 線段樹上二分搜
```cpp=
void st_bsearch(int pos,int idx=1,int l=1,int r=n){
    if(l==r&&seg[idx]>=pos){
        seg[idx]-=pos;
        ans=l;
        return;
    }
    int mid=(l+r)>>1;
    if(seg[idx<<1]>=pos)
        check_in(pos,idx<<1,l,mid);
    else if(seg[idx<<1|1]>=pos)
        check_in(pos,idx<<1|1,mid+1,r);
    merge(idx);
}
```

### KMP演算法
```cpp=
string a; // 文本串
string b; // 模板串(将被匹配的子串)
int kmp_next[N]; // next数组

void getNext(int m=b.size()){//初始化
	int j = 0;
	kmp_next[0] = 0;
	for(int i=1; i<m; ++i){
		while(j>0 && b[i]!=b[j]) j=kmp_next[j-1];
		if(b[i]==b[j]) ++j;
		kmp_next[i] = j;
	}
}

int kmp(int n=a.size(),int m=b.size()){//使用KMP寻找匹配位置
	int i, j = 0;
	int p = -1;
	getNext(m);
	for(i=0; i<n; ++i){
		while(j>0 && b[j]!=a[i]) j=kmp_next[j-1];
		if(b[j]==a[i]) ++j;
		if(j==m){
			p = i - m + 1;
			break;
		}
	}
	return p;
}

int kmp(int n=a.size(),int m=b.size()){//使用KMP计算匹配次数
	int i, j = 0, res = 0;
	getNext(m);
	for(i=0; i<n; ++i){
		while(j>0 && b[j]!=a[i]) j=kmp_next[j-1];
		if(b[j]==a[i]) ++j;
		if(j==m) ++res;
	}
	return res;
}
```

### 動態開點+懶惰標記線段樹
```cpp=
class Node {
public:
    Node* left;
    Node* right;
    int l;
    int r;
    int mid;
    int v;
    int add;
    Node(int l, int r) {
        this->l = l;
        this->r = r;
        this->mid = (l + r) >> 1;
        this->left = this->right = nullptr;
        v = add = 0;
    }
};
class SegmentTree {
private:
    Node* root;
 
public:
    SegmentTree() {
        root = new Node(1, 1e9);
    }
 
    void modify(int l, int r, int v) {
        modify(l, r, v, root);
    }
 
    void modify(int l, int r,int v, Node* node) {
        if(node->l>r||node->r<l) return;
 
        if (node->l >= l && node->r <= r)
        {
            node->v += (node->r - node->l + 1) * v;
            node->add += v;
            return;
        }
        pushdown(node);
        modify(l, r, v, node->left);
        modify(l, r, v, node->right);
        merge(node);
    }
 
    int query(int l, int r) {
        return query(l, r, root);
    }
 
    int query(int l, int r, Node* node) {
        if(node->l>r||node->r<l) return 0;
        if (node->l >= l && node-> r <= r) return node->v;
        pushdown(node);

        return query(l, r, node->left)+query(l, r, node->right);
    }
 
    void merge(Node* node) {
        node->v = node->left->v+node->right->v;
    }
 
    void pushdown(Node* node) {
        if (!node->left) node->left = new Node(node->l, node->mid);
        if (!node->right) node->right = new Node(node->mid + 1, node->r);
        if (node->add)
        {
            Node* left = node->left;
            Node* right = node->right;
            left->v += node->add;
            left->add += node->add;
 
            right->v += node->add;
            right->add += node->add;
            node->add = 0;
        }
    }
};
```

### SPFA(用於判斷負權環)
```cpp=
vector<pii> routs[N];
int dis[N],n,cnt[N];

bool SPFA(const int &start){
    fill(dis,dis+n,1e9);
    memset(cnt,0,sizeof(cnt));
    dis[start]=0;
    queue<int> que;
    bitset<N> in_que;
    que.push(start);
    while(!que.empty()){
        int cur=que.front();
        que.pop();
        cnt[cur]++;
        if(cnt[cur]>n){
            return 1;
        }
        in_que[cur]=0;
        for(const auto &i:routs[cur]){
            if(dis[i.second]>dis[cur]+i.first){
                dis[i.second]=dis[cur]+i.first;
                if(!in_que[i.second]){
                    que.push(i.second);
                    in_que[i.second]=1;
                }
            }
        }
    }
    return 0;
}
```

### 稀疏表
```cpp=
constexpr int N=500;
int dp[N+5][32];
int a[N]={1,2,3,4,5};

void build(){
    for(int i=1;i<=N;i++)
        dp[i][0]=a[i-1];
    for(int k=1;k<32;k++){
        for(int i=1;i+(1<<(k-1))<=N;i++){
            dp[i][k]=max(dp[i][k-1],dp[i+(1<<(k-1))][k-1]);
        }
    }
}

int query(int l,int r){
    int idx=__lg(r-l+1);
    return max(dp[l][idx],dp[r-(1<<idx)+1][idx]);
}
```

### Z-Function
```cpp=
string s="123456789";
const int n=s.size();
vi z(n);
for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (z[i - l] < r - i + 1)
        z[i] = z[i - l];
    else {
        z[i] = max(r - i + 1, 0);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        l = i, r = i + z[i] - 1;
    }
}
```

### Trie
```cpp=
struct TrieNode {
    int nxt[26]; //遇到a~z時的節點編號(idx)
    int cnt; //以此結尾的字串個數
} node[1000005];
int idx = 2; //root = 1

void insert(string s){
     int cur = 1; //從root開始
     for(auto i:s) {
          if(node[cur].nxt[i-'a'] == 0){
               node[cur].nxt[i-'a'] = idx; //開一個新的node
               cur = idx;
               idx++;
           }
           else {
                cur = node[cur].nxt[i-'a'];
           }
     }
     node[cur].cnt++;
}

int query(string s){
     int cur = 1;
     for(auto i:s) {
          if(node[cur].nxt[i-'a'] == 0){
               return 0;
           }
           else {
                cur = node[cur].nxt[i-'a'];
           }
     }
     return node[cur].cnt;
}
```