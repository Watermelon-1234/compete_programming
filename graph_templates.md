 

[DFS](https://so.csdn.net/so/search?q=DFS&spm=1001.2101.3001.7020)
------------------------------------------------------------------

> DFS的结果就是一颗`搜索树`，只不过每次只记录眼前的分支,然后通过栈回溯到上一个节点再往下朝另一个方向搜索，绘出所有轨迹就是一棵搜索树。

#### 排列数字问题

    #include<iostream>
    using namespace std;
    const int N=8;
    int n,path[N];
    bool st[N];
    void dfs(int u){
        if(u==n){
            for(int i=0;i<n;i++) cout<<path[i]<<' ';
            cout<<endl;
            return ;
        }
        for(int i=1;i<=n;i++){
            if(!st[i]){
                path[u]=i;
                st[i]=true;
                dfs(u+1);
                st[i]=false;
            }
        }
    }
    int main()
    {
        cin>>n;
        dfs(0);
        return 0;
    }
    

#### 经典N皇后问题

    #include<iostream>
    #include<vector>
    #include<cstring>
    using namespace std;
    const int N=15;
    int n;
    vector<vector<char>> g(N,vector<char>(N,'.'));
    bool row[N],col[N],bias_l[N],bias_r[N];
    void dfs(int layer){
        if(layer==0){
            for(int x=n;x>0;x--){
                for(int y=1;y<=n;y++){
                    cout<<g[x][y];
                }
                cout<<endl;
            }
            cout<<endl;
            return;
        }
        for(int y=1;y<=n;y++){
            if(!row[layer]&&!col[y]&&!bias_r[layer+y]&&!bias_l[y-layer+n]){
                g[layer][y]='Q';
                row[layer]=col[y]=bias_r[layer+y]=bias_l[y-layer+n]=true;
                dfs(layer-1);
                g[layer][y]='.';
                row[layer]=col[y]=bias_r[layer+y]=bias_l[y-layer+n]=false;
            }
        }
    }
    int main()
    {
        cin>>n;
        dfs(n);
        return 0;
    }
    

不难发现，这两道题目完全不一样，但题解的结构几乎是一致的。

*   DFS
    *   递归出口
    *   修改状态
    *   向下递归
    *   回溯状态

而`剪枝`是算法效率高低的核心所在，也是难点所在。

[BFS](https://so.csdn.net/so/search?q=BFS&spm=1001.2101.3001.7020)
------------------------------------------------------------------

> BFS的搜索过程就是一个雷达扫描图，一层一层向外搜索，基于这个特点，如果边权相同可以用来解最短路问题。

#### 经典迷宫问题，求走出迷宫最少步数

    #include<iostream>
    #include<vector>
    using namespace std;
    const int N=110;
    typedef pair<int,int> PII;
    vector<vector<int> > d(N,vector<int>(N,-1));//和g[N][N]一样大的二维数组，存储当前节点到原点的距离，-1表示未被访问
    int n,m,hh,tt;//队列头尾指针
    PII q[N*N];//模拟队列（因为是模拟所以出队后头指针会向后走，因此队列长度不能小于可能入队元素个数）
    int g[N][N];//矩阵信息
    int bfs(){
        q[0]={0,0};//将左上角节点入队
        d[0][0]=0;//左上角到自己的距离为0
        int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};//枚举四个方向本质还是坐标的偏移
        while(hh<=tt){
            auto t=q[hh++];//要擅用auto
            for(int i=0;i<4;i++){//枚举四个方向
                int x=t.first+dx[i],y=t.second+dy[i];
                if(x>=0&&x<n&&y>=0&&y<m&&d[x][y]==-1&&g[x][y]==0){//d[N][N]既存储距离又充当判断是否走过
                    q[++tt]={x,y};
                    d[x][y]=d[t.first][t.second]+1;
                }
            }
        }
        return d[n-1][m-1];
    }
    int main()
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>g[i][j];
        cout<<bfs();
        return 0;
    }
    

DFS一般没有固定的思路，但BFS往往有一套组合拳。

*   BFS
    *   记录初始状态
    *   while循环，判断队列不空
    *   取出队首元素
    *   处理逻辑
    *   符合要求数据入队

#### 基于刚才的走迷宫问题总结：

*   通过`int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};`可以使用一个for循环相当简洁的遍历4邻域，8邻域同理。本是上是构建了一个向量。
    
*   以后会在图论中大量见到`d[N][N]`这个数组，`妙用无穷`，例如在本题，既可以表示某个坐标`是否走过`，还可以知道`距离起点多远`。甚至还可以记录当前点是从哪一个父节点转移过来的，这样可以从终点`回溯出一条路径`。
    

##### 八数码问题其实也提供了一个很好的思路，当我们碰到一个一维的字符串，问你多少次变换后能变成另外一个字符串。我们可以尝试在逻辑上将其转化为一个二维的表，然后利用`int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};`来进行一个遍历，使用个map来存储这个串是否出现过（也就是某个点是否走过，key=string,value=distance）。基于这个题目是尝试先走，也就是在遍历每个方向后都需要回溯状态，方便本次循环中下一次尝试。

树、图的存储与遍历
---------

> `树是有向无环图`，在存储时`无向图`又是在`有向图`的基础上添加一条逆向的边罢了。因此我们在存储时只需要会存有向图即可。

##### 常见的有两种存储方式——邻接矩阵和邻接表

*   邻接矩阵
    *   `g[N][N]`，`g[a][b]`表示有一条从`a->b`的边。适合稠密图
*   邻接表
    *   将所有顶点存到`h[N]`中，然后每个`h[a]`采用链表的方式，b遍历`h[a]`这个链表能找到`b`，说明有一条从`a->b`的边。适合稀疏图，这个用得较多。
    *       // 对于每个点k，开一个单链表，存储k所有可以走到的点。h[k]存储这个单链表的头结点
            int h[N], e[N], ne[N], idx;
            
            // 添加一条边a->b
            void add(int a, int b)
            {
               e[idx] = b, ne[idx] = h[a], h[a] = idx++ ;
            }
            
            // 初始化
            idx = 0;
            memset(h, -1, sizeof h);
            
            注意：e存的是边数，往往与N也就是节点的个数不一致。
            
        

#### 树和图的`深度优先搜索`和`广度优先搜索`

> 一般来收，深搜都会涉及到递归，利用系统的栈，具体代码因题而异。而宽搜一般少不了队列。并且一般都少不了一个`st[N]`标记某个点是否被访问过了或者`d[N][N]`表示某个点到起点的距离，深搜常手写邻接表，但广搜常直接用STL的`queue`。基于这个思路代码会好些不少。

##### 深搜

    int dfs(int u)
    {
        st[u] = true; // st[u] 表示点u已经被遍历过
    
        for (int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (!st[j]) dfs(j);
        }
    }
    

##### 广搜

    queue<int> q;
    st[1] = true; // 表示1号点已经被遍历过
    q.push(1);
    
    while (q.size())
    {
        int t = q.front();
        q.pop();
    
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (!st[j])
            {
                st[j] = true; // 表示点j已经被遍历过
                q.push(j);
                //这里可以加上距离
            }
        }
    }
    

#### 广搜经典应用：求图的拓扑序

> 只针对有向图，无向图是没有拓扑序的。简而言之，将图的所有顶点按某个序列排好，这个序列中任意两个有边的顶点都是从前指向后的。而没有从后指向前的点是不是就可以推出这是一个无环图~也就是说拓扑序可以判断图中是否存在环。

##### 关于拓扑序列，非常重要的一个概念就是`入度`、`出度`。入度为0意味着没有其他边指向它，从它开始处理邻接点就不会存在存在某条边从后指向前的问题了，所以我们选取入度为0的点作为起点。

一般步骤：

*   选取所有入度为0的点，放入队列
*   宽搜模板
    *   找到所有当前节点出度指向的子节点，去除指向的边，并且子节点入度-1
    *   如果子节点入度为0，放入队列
        *   如果存在环的话，一定会有子节点度永远不为0，即永不入队。我们可以通过判断队列的大小来判断是否存在拓扑序。

##### 重边并不会影响拓扑序，存了多少到时候减少的也是多少。但是自环不一样，自环已经破环了拓扑序的先决条件了，最终一定会出现度不为零的节点，也就是无法将所有节点入队。

    #include<iostream>
    #include<vector>
    using namespace std;
    int n,m;
    const int N=1e5+10;
    vector<int> h(N,-1);//邻接表的静态部分(这个数组范围也是1~n)
    int idx,e[N],ne[N];//邻接表的链表部分
    int hh=0,tt=-1,q[N];//数组模拟队列，tt设为-1是因为待会要循环先执行入队操作，保持编号与下标一致
    int d[N];//记录每个点的入度
    bool topsort(){
        for(int i=1;i<=n;i++){
            if(!d[i]) q[++tt]=i;
        }
        while(hh<=tt){
            int t=q[hh++];
            for(int i=h[t];i!=-1;i=ne[i]){
                int j=e[i];
                d[j]--;
                if(!d[j]) q[++tt]=j;
            }
        }
        if(tt==n-1) return true;
        else return false;
    }
    void add(int a,int b){
        e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    }
    int main()
    {
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            add(a,b);
            d[b]++;
        }
        if(topsort()){
            for(int i=0;i<n;i++) cout<<q[i]<<' ';
        }else cout<<-1;
        return 0;
    }
    

朴素Dijkstra算法
------------

> 时间复杂度O(n^2)，与源点个数n有关，与边的数目m无关，适合稠密图。

#### 稠密图使用邻接矩阵存储：

    const int N=510,INF=0x3f3f3f3f;
    vector<vector<int>> g(N,vector<int>(N, INF));//邻接矩阵
    vector<int> dist(N,INF);//到起点的最短距离
    bool st[N];//节点是否纳入最短点集
    

#### C++代码

    #include<iostream>
    #include<algorithm>
    #include<vector>
    using namespace std;
    const int N=510,INF=0x3f3f3f3f;
    vector<vector<int>> g(N,vector<int>(N, INF));
    vector<int> dist(N,INF);
    bool st[N];
    int n,m;
    int dijkstra(){
        dist[1]=0;
        for(int i=0;i<n;i++){//处理n次，每次选取一个点纳入最短点集，n次后所有点都纳入最短点集合了，因此任意一个点到起点的距离都是最短的
            int t=-1;
            for(int j=1;j<=n;j++){
                if(!st[j] && (t==-1 || dist[t]>dist[j])){
                    t=j;
                }
            }
            st[t]=true;//这里意味着每次循环都有一个点纳入最短点集，但距离的更新就不好说了，没有边可能还是无穷
            for(int j=1;j<=n;j++){
                dist[j]=min(dist[j],dist[t]+g[t][j]);
            }
        }
        if(dist[n]==INF) return -1;
        else return dist[n];
    }
    int main()
    {
        cin>>n>>m;
        while(m--){
            int x,y,z;
            cin>>x>>y>>z;
            g[x][y]=min(g[x][y],z);
        }
        cout<<dijkstra();
        return 0;
    }
    

##### 虽然每次学完都会忘记，但一次次的温习渐渐觉得这个算法好像变简单了。

（假设求第1个点到第n个点的最短路）

*   初始化
    *       1.所有点到起点的距离都是无穷，此时最短点集为空。
            2.起点到自己的距离为0，是所有距离起点最近的点。注意：此时还未将起点纳入最短点集，只是为其赋予了关键的初始值
            
        
*   核心算法
    *       1.在所有还未纳入最短点集的点中找一个距离起点最近的点，2.将这个点纳入最短点集
            3.然后利用这个点更新其他点的距离。
            
        
    *   最外层为一个n次的循环，因为每一次循环都会将一个点纳入最短点集，也就是说确定了一个点的最短路，当我遍历完n个点，也就获得了n个点的最短路。

堆优化Dijkstra算法
-------------

![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/3542f0d16d2785be50c50eb2b0e0fdab.png)

> 将上面朴素Dijkstra算法的步骤表达出来，发现`时间复杂度最高的就是在不属于最短点集的点中找出dist最小的`，最坏形况下遍历n个点，时间复杂度O(n^2)。如果我们把所有的dist插入小根堆中，那么每次找到的时间就是近乎O(1)，而第三步用t更新其他点的距离本质上是在遍历`边m`，也就是n次更新一共遍历了`m`条边，每次维护队中的n个节点堆插入操作的时间复杂的就是logn，`最大的时间复杂的就为m*logn`。也就是说适合稀疏图m,n一个数量级的。但是STL中的堆是不支持指定删除节点的，也就是说我们更新后的更短的dist只能直接插入，但是由于更新后值更小，所以并不会受到这个点之前未删除的值的影响，形成空间换时间。并且由于冗余的存在，可能会出现某个点已经被纳入最短点集了，但是某一次堆中pop出的是那个被纳入最短点集的点上一次的较小值，但这个较小值可能比堆中其他所有点的dist都要小，所以我们每次`st[t]=true`的时候都要判断一下是否纳入了最小点集。

#### C++代码

    typedef pair<int, int> PII;
    
    int n;      // 点的数量
    int h[N], w[N], e[N], ne[N], idx;       // 邻接表存储所有边
    int dist[N];        // 存储所有点到1号点的距离
    bool st[N];     // 存储每个点的最短距离是否已确定
    
    // 求1号点到n号点的最短距离，如果不存在，则返回-1
    int dijkstra()
    {
        memset(dist, 0x3f, sizeof dist);
        dist[1] = 0;
        priority_queue<PII, vector<PII>, greater<PII>> heap;
        heap.push({0, 1});      // first存储距离，second存储节点编号
    
        while (heap.size())
        {
            auto t = heap.top();
            heap.pop();
    
            int ver = t.second, distance = t.first;
    
            if (st[ver]) continue;
            st[ver] = true;
    
            for (int i = h[ver]; i != -1; i = ne[i])
            {
                int j = e[i];
                if (dist[j] > distance + w[i])
                {
                    dist[j] = distance + w[i];
                    heap.push({dist[j], j});
                }
            }
        }
    
        if (dist[n] == 0x3f3f3f3f) return -1;
        return dist[n];
    }
    

##### y总的写法是简洁优雅的，初始化数组的值我第一时间想到的就是使用类似`vector a(N,-1)`，但是效率相比于`cstring`中的`memset(a,-1,sizeof a)`直接处理一个字节一个字节的内存还是太慢了。

##### 如果我们添加一个`path[N]`数组，`path[i]`含义为：存储最短路径上，`i`的前驱节点.直白点，就是在最短路径上`i`这个节点是由哪个节点转移来的。

##### 再次回顾一下，此时我们指的一直都是`单源最短路`，其实求出来的是一个节点到其他所有节点的最短路，基于上面额path数组我们就可以回溯一条从任意终点到起点的最短路径了。

Bellman_Ford算法
--------------

> 思路非常简单，核心为松弛操作。按边的长度来松弛，易知如果存在`n`个点，`1~n`号点之间至多存在`n-1`条边。也就是说如果我按边的长度来松弛至多只需要处理`n-1`次，求得的值就是该点的最短路（假设存在）。内层循环就是遍历所有的边进行松弛操作就行`(dist[b]>min(dist[b],dist[a]+weight))`。因此时间复杂度为O(nm)

#### 但显然以上思路虽然简单，却有一些明显需要考虑的问题：

*   存储：
    
    *   由于最核心的操作是内层循环对所有便进行遍历然后松弛，因此我们只要保证能将每条边的数据遍历到就行。使用边集数组即可。
    
        struct Edge{
            int a,b,w;
        }edges[N];
        
    
*   如何限制更新k条边：
    *   在每次内存循环开始的时候都将`dist[N]`备份成`backup[N]`，松弛操作`(dist[b]>min(dist[b],dist[a]+weight))`修改为`dist[b]>min(dist[b],backup[a]+weight)`。请诸位思考，一开始所有点到起点之间的距离都是正无穷，dist\[1\]=0;此时起点自己到自己的距离为0。这时我利用边去更新dist即到起点的距离，是不是与起点相连的边都会被更新，并且由于backup数组的存在，本次更新的值并不会影响我后面值的更新，从而引发串联。如果将本次更新视为在当前层，那么我的`backup`永远是用的上一层结果，从而保证这个算法一定是按距离起点边长为1，距离起点边长为2，… ，距离起点边长为n去更新的最短路。当然因为存在负权边，所以某些无穷大可能也会被更新为较小的无穷大，可以无视，因为这表示还是没有通路到起点。
*   重边：
    *   由于我们求的是最短路，因此就算有重边，最终结果也只会保留最短的那条的更新结果。
*   自环：
    *   如果自环为正，路径变成长，因此不会被更新，不用考虑。
    *   如果自环为负，即构成负环，这个点到起点的距离会无数次被更新，每次都会减小负环的值，但是我们最外层存在变数限制，也就是它更新的次数会被限制住。
*   负环：
    *   起点到终点的最短路经过负环，通过限制边的松弛长度可以求出某个限制条件下的最短路。
    *   起点到终点的最短路`不`经过负环，对结果没有影响，可以当其不存在。

#### 初始化

> 建议使用memset和memcpy，属于cstring头文件的，对单个字节内存进行操作，效率高。

    int n, m;       // n表示点数，m表示边数
    int dist[N];        // dist[x]存储1到x的最短路距离
    int backup[N];
    struct Edge     // 边，a表示出点，b表示入点，w表示边的权重
    {
        int a, b, w;
    }edges[M];
    

    int bellman_ford(){
        memset(dist,0x3f,sizeof dist);//这是每次调用这个算法都需要的初始化
        dist[1]=0;//起点到自己的距离为0
        for(int i=0;i<k;i++){//至多n-1次可以求出1~n路径上所有节点的最短路，至于多循环一次两次并没有什么影响，当然这个值也可能取决于题目。
            memcpy(backup,dist,sizeof dist);
            for(int j=0;j<m;j++){
                int a=edges[j].a,b=edges[j].b,w=edges[j].w;
                dist[b]=min(dist[b],backup[a]+w);//min在algorithm头文件中
            }
        }
        if(dist[n]>0x3f3f3f3f/2) return -2e9;
        else return dist[n];
    }
    

    //只需要记录n条边就行
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        edges[i]={x,y,z};
    }    
    

SPFA算法
------

> SPFA算法是对Bellman\_Ford算法的优化，而Bellman\_Ford算法时间复杂度最高的就是第二层循环中对所有边进行遍历更新`o(nm)`。但事实上处理`a->b`边中`dist[b]`是否更新取决它前面的`a`节点也就是`dist[a]`是否被更新，而`dist[a]`又取决于它前一条更新它的边。`简而言之，如果某一条边或者说某个节点被更新了，那么与这个节点相连的边是极有可能需要被更新的。`这样平均下来SPFA的算法时间复杂为o(m)。最坏情况下存在负环也要o(nm)

##### 在上述的优化操作优化的关键点在于`如果某一条边或者说某个节点被更新了，那么与这个节点相连的边是极有可能需要被更新的。`也就是实现上倾向于使用`邻接表`，能把性能发挥到极致。

##### 而这些本次被更新的点，可以放到任意数据结构里去，习惯上我们使用`队列queue`存储。一旦被更新了就存起来，后面再拿出来通过边权更新其他相连的节点，直到队列为空，就求出了所有节点的最短路了。

##### 实现上需要注意的细节：某个节点可能在队列中，等待更新其他节点，但此时也可能仍被其他节点更新，此时不需要重复放入队列，只需要更新`dist`即可。因为队列中放的毕竟是节点编号，遍历处理的也是节点编号。

    #include<iostream>
    #include<vector>
    #include<queue>
    using namespace std;
    const int N=1e5+10,M=1e5+10,INF=0x3f3f3f3f;
    int n,m,idx;
    vector<int> dist(N,INF);
    vector<int> h(N,-1);
    int e[M],w[M],ne[M];
    bool st[N];
    void add(int a,int b,int c){
        e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
    }
    int spfa(){
        //dist=vector(N,INF);再次初始化
        queue<int> q;
        dist[1]=0;
        q.push(1);
        st[1]=true;
        while(q.size()){
            auto t=q.front();
            q.pop();
            st[t]=false;
            for(int i=h[t];i!=-1;i=ne[i]){
                int j=e[i];
                if(dist[j]>dist[t]+w[i]){
                    dist[j]=dist[t]+w[i];
                    if(!st[j]) q.push(j),st[j]=true;
                }
            }
        }
        return dist[n]==INF?-INF:dist[n];
    }
    int main()
    {
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            add(a,b,c);
        }
        int t=spfa();
        if(t==-INF) cout<<"impossible";
        else cout<<t;
        return 0;
    }
    

##### 做算法题这样写没什么，一次过了就不会再用了，但如果第二次调用`spfa()`就会发现`dist`没有被重新初始化。导致我在工程化项目中经常出现这种疏忽。。

* * *

##### `注意：以上我都是在说最短路的问题，并不涉及到负环。显然如果存在负环，那么负环路径上的点就会一直被更新，队列一直不空因此整个算法会陷入死循环。所以SPFA算法效率高、好写、还可以处理负权边，因此用的非常多。但缺点是无法和它老爹bellman_ford一样通过对边数的约束处理负环问题`

##### 但是别急，我们通过`抽屉原理`，加上一个`cnt[N]`数组就可以解决负环问题。本质上和bellman_ford的思路是一样的。

> `Bellman_Ford：n个节点至多存在n-1条边。`

> `SPFA：cnt[n]记录一下1~n之间的边数，如果负环的话cnt[j] = cnt[t] + 1;会不停更新，直到存在某个cnt[j]>=n，说明存在n条边，那就有n+1个节点，由抽屉原理可知一定有两个节点是相同的，也就是构成了环。`

    #include<iostream>
    #include<vector>
    #include<queue>
    using namespace std;
    const int N=2010,M=10010,INF=0x3f3f3f3f;
    int n,m,idx;
    vector<int> dist(N,INF);
    vector<int> h(N,-1);
    int cnt[N];
    int e[M],w[M],ne[M];
    bool st[N];
    void add(int a,int b,int c){
        e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
    }
    bool spfa(){
        dist=vector(N,INF);
        queue<int> q;
        for (int i = 1; i <= n; i ++ ) {
            q.push(i);
            st[i]=true;
        }
        while(q.size()){
            auto t=q.front();
            q.pop();
            st[t]=false;
            for(int i=h[t];i!=-1;i=ne[i]){
                int j=e[i];
                if(dist[j]>dist[t]+w[i]){
                    dist[j]=dist[t]+w[i];
                    cnt[j]=cnt[t]+1;
                    if(cnt[j]>n-1)  return true;
                    if(!st[j]) q.push(j),st[j]=true;
                }
            }
        }
        return false;
    }
    int main()
    {
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            add(a,b,c);
        }
        if(spfa()) cout<<"Yes";
        else cout<<"No";
        return 0;
    }
    

##### 之所以在spfa()中预先把所有点放入队列中，最主要是为了防止某一些完全独立的点内部构成负环。如果确保所有点都是联通的，那么从任意一个点开始使用spfa()都能实现对负环的判断。并且，dist数组也可以不初始化，因为我们目的就是判负环，只有遇到负环才会疯狂更新cnt\[\]，直到cnt\[j\]>=n判出负环。

Floyd算法
-------

> 弗洛伊德算法（Floyd-Warshall Algorithm）是一种用于解决图中节点之间最短路径问题的算法，它适用于有向图或者无向图，可以处理带有负权边但不包含负权回路的图。  
> 弗洛伊德算法的核心思想是动态规划。它通过遍历所有节点对之间的可能路径，逐步更新从一个节点到另一个节点的最短距离，直到获得所有节点之间的最短路径为止。具体来说，算法维护一个二维数组D，其中D\[i\]\[j\]表示从节点i到节点j的最短距离。然后通过以下递推关系来更新这些距离： `D[i][j] = min(D[i][j], D[i][k] + D[k][j])`

> 其中k表示所有可能的中间节点，如果从i到j经过k节点的路径比直接从i到j的路径更短，就更新D\[i\]\[j\]的值。

> 弗洛伊德算法的时间复杂度为O(n^3)，其中n为节点数，因此它适用于中等规模的图。该算法的优点是能够同时计算任意两点之间的最短路径，因此非常适合于需要多对多最短路径的场景。然而，对于大规模图来说，其时间复杂度可能会使其效率较低。

##### floyd算法相当好记，直接k,i,j三重循环嵌套，更新`D[i][j] = min(D[i][j], D[i][k] + D[k][j])`即可。（k为中心节点、i,j为节点编号）

##### 问题一：为什么一定是k,i,j三重嵌套，我i,k,j 或者 i,j,k不行吗？

`不行！如果弄懂了这个问题，理论推导出公式我不敢说，但使用起来你将没有任何疑惑。`

##### `如果我们先遍历起点和终点，然后再遍历中间节点，就会出现某两个节点之间存在可能的最短路径，但由于中心节点尚未更新，这个最短路径可能被忽略。这样就会导致无法找到所有节点对之间的最短路径。`

##### `而当我们先遍历中间节点时，我们可以确保在考虑任意一对节点(i, j)时，中间节点已经被遍历过，从而能够考虑到经过这些中间节点的所有可能最短路径。通过遍历所有中间节点，我们最终能够找到所有节点对之间的最短路径，因此确保了算法的完备性。`

#### 一句话总结，先遍历中心节点，再遍历起点和终点，就能找到这个经过这个中心节点的所有最短路，遍历所有中心节点就得到了所有节点间的最短路。

##### 不论是基于遍历所有节点的算法原理，还是`D[i][j] = min(D[i][j], D[i][k] + D[k][j])`表达式，着眼的都是`节点`。显然用`邻接矩阵`比较好，方便遍历所有节点以及获得任意两节点之间的关系。

    const int INF=0x3f3f3f3f;
    初始化：
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                if (i == j) d[i][j] = 0;
                else d[i][j] = INF;
    
    // 算法结束后，d[a][b]表示a到b的最短距离
    void floyd()
    {
        for (int k = 1; k <= n; k ++ )
            for (int i = 1; i <= n; i ++ )
                for (int j = 1; j <= n; j ++ )
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
    

最后判断是否d\[a\]\[b\]间存在最短路，会出现和Bellman_Ford算法一样的问题，因为二者归根结底还是遍历了所有边，甚至Floyd暴力程度连不存在的边也会处理一下，导致`如果存在负权边，某些距离无穷大的节点会被更新成较小的无穷大`，这是需要看下数据的范围全为负值叠一起加个正无穷看下有多大。一般经验，d\[a\]\[b\]>INF/2就可以认为是不存在最短路了。

* * *

最小生成树
-----

> 最小生成树是指`在一个加权连通图中找到一个包含所有顶点的树，并且使得树的边的权值之和最小`。换句话说，给定一个带权的无向连通图，最小生成树是指一个边的子集，它是一棵树，包含图中的所有顶点，使得这棵树的所有边的权值之和达到最小。最小生成树常常用于解决诸如网络设计、电路设计、城市规划等领域的问题，以确保连接所有节点的同时，尽可能减少总成本或总距离。经典的算法包括Prim算法和Kruskal算法，它们可以有效地找到给定图的最小生成树。

朴素Prim算法
--------

![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/7c9bf270420a3ef2a3ebb26e5f85347e.png)

> 和`Dijkstra求最短路`的思路算法非常相似，最大的区别在于`Dijkstra`使用`dist[N]数组存储节点到起点的距离`。而`Prim算法`使用`dist[N]存储节点到最小生成树集合的距离`。因为最小生成树着眼的是连通图的权值和最小，最小生成树内部本就是联通的、权值和最小的。此时我们想纳入新的节点到最小生成树中，就是要寻找与最小生成树相连的、边权最小的那个节点。然后每纳入一个节点都需要利用这个节点更新一下相连的边到最小生成树集合的位置了，因为有新的节点纳入最小生成树了，与这个节点相连的节点到最小生成树集合的距离可能需要修改遍历一遍就行，更小就修改一下，修改后的值就是这两点的边权。

    int n;      // n表示点数
    int g[N][N];        // 邻接矩阵，存储所有边
    int dist[N];        // 存储其他点到当前最小生成树的距离
    bool st[N];     // 存储每个点是否已经在生成树中
    
    
    // 如果图不连通，则返回INF(值是0x3f3f3f3f), 否则返回最小生成树的树边权重之和
    int prim()
    {
        memset(dist, 0x3f, sizeof dist);
    
        int res = 0;
        for (int i = 0; i < n; i ++ )
        {
            int t = -1;
            for (int j = 1; j <= n; j ++ )
                if (!st[j] && (t == -1 || dist[t] > dist[j]))
                    t = j;
    
            if (i && dist[t] == INF) return INF;
    
            if (i) res += dist[t];
            st[t] = true;
    
            for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]);
        }
    
        return res;
    }
    

##### 标记一下我学的时候略有疑惑的点：

    if (i && dist[t] == INF) return INF;
    
    if (i) res += dist[t];
    

##### 这里之所以要加上一个`i`的判断，是因为`memset(dist, 0x3f, sizeof dist);`一开始我们将所有的`dist[N]`都初始化为正无穷，并没有将任何一个点纳入最小生成树集合，因此会出现第一次循环时任何一个点到最小生成树集合的距离都为正无穷。需要进行对`i=0`也就是第一次循环进行特判，允许第一次循环碰到`dist[t]==INF`，如果后面再碰到`最小生成树集合存在元素`且当前`dist[t]==INF`那就说明这个点是孤立的，无法构成最小生成树。

*   粘一下自己仅凭随手搜的最小生成树的概念,实现的求最小生成树的代码，比上面的模板要慢个七八倍叭。。

    #include<iostream>
    #include<cstring>
    #include<algorithm>
    #include<queue>
    using namespace std;
    const int N=510,M=1e5+10,INF=0x3f3f3f3f;
    int h[N],e[2*M],w[2*M],ne[2*M],idx;
    int n,m;
    bool st[N];
    typedef pair<int,int> PII;
    void add(int a,int b,int c){
        e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
    }
    int Prim(){
        int cnt=0,res=0;
        priority_queue<PII,vector<PII>,greater<PII>> q;
        q.push({0,1});
        while(q.size()){
            auto t=q.top();
            q.pop();
            int weight=t.first,ver=t.second;
            if(st[ver]) continue;
            st[ver]=true;
            res+=weight;
            cnt++;
            for(int i=h[ver];i!=-1;i=ne[i]){
                int j=e[i];
                if(st[j]) continue;
                q.push({w[i],j});
            }
        }
        if(cnt==n) return res;
        else return -INF;
    }
    int main()
    {
        // ios::sync_with_stdio(false),cin.tie(0);
        memset(h,-1,sizeof h);
        cin>>n>>m;
        while(m--){
            int u,v,w;
            cin>>u>>v>>w;
            add(u,v,w);
            add(v,u,w);
        }
        int t=Prim();
        if(t==-INF) cout<<"impossible";
        else cout<<t;
        return 0;
    }
    

Kruskal算法
---------

##### 初始化：

*   所有点之间都是不连通的，对于任意两个点我们都要能迅速判断是否连通。

##### 核心步骤：

*   将`所有边`进行`降序`排序 `O(mlogm)`
*   依次处理每条边
    *   判断这条边的两个端点是否在同一个集合中
        *   如果不连通，则将这条边最为最小生成树的一条边。
        *   如果连通，则舍弃。

##### 1\. 所有点不连通，如果某些点连通要能迅速判断连通状态。`并查集`

    int p[N];//记录所有节点的父节点
    for(int i=1;i<=n;i++) p[i]=i;
    //每一个节点的父节点都是自己，即一开始所有节点都是孤立
    

    //路径压缩的并查集，返回某个节点的祖宗节点。近乎O(1)
    int find(int x){
        if(p[x]!=x) p[x]=find(p[x]);
        return p[x];
    }
    

##### 2\. 所有边降序排序。`STL sort()`，但要实现`com比较函数`

    struct Edge{
        int a,b,w;
        bool operator <(const Edge &edge){
            return w<edge.w;
        }
    }edges[N];
    //C++兼容了C的结构体，将其看作一个类即可，重载了一下 <运算符
    

##### 3.判断两个端点是否在同一个集合中，并统计权值，以及最终是否构成了一颗生成树。

    int res=0;cnt=0;
    for(int i=1;i<=n;i++){
        int a=edges[i].a,b=edges[i].b,w=edge[i].w;//此时a,b为该边的左右端点
        a=find(a),b=find(b);//此时a,b被更新为a,b这两个端点所属集合的祖宗节点编号。
        if(a!=b){
            res+=w;//记录最小生成树权值
            cnt++;//记录最小生成树中的边数
            p[a]=b;//将a的父节点设置为b节点编号(相当于将a这个集合插入到了b这个集合中)
        }
    }
    if(cnt<n-1) 无法构成最小生成树
    

染色法判二分图
-------

> 二分图（Bipartite Graph）是一种特殊的图论结构，其中所有的顶点可以被分成两个互不相交的集合，使得每一个边的两个端点都分别来自这两个不同的集合。也就是说，图中的任意一条边都连接着两个集合中的两个顶点。二分图不含奇数环，否则会出现同一个点染上两种颜色（即同一个点分别位于两个集合）

##### 具体的步骤：

1.  选择一个起始顶点，将其染色。
    
2.  对于每一个与已经染过色的顶点相邻的未染色顶点，将其染成与相邻顶点不同的颜色。
    
3.  如果在染色过程中遇到一个已经染过色的顶点，需要检查其颜色是否与我们打算给它的颜色相同。如果不同，那么说明这个图不能被有效地染成两种颜色，因此它不是一个二分图。
    

##### BFS写法

    #include<iostream>
    #include<vector>
    using namespace std;
    const int N=1e5+10,M=2*N;
    int n,m;
    int color[N];
    vector<int> h(N,-1);
    int idx,e[M],ne[M];
    void add(int a,int b){
        e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    }
    bool bfs(int ver){
        int q[N],hh=0,tt=-1;
        color[ver]=1;
        q[++tt]=ver;
        while(hh<=tt){
            auto t=q[hh++];
            for(int i=h[t];i!=-1;i=ne[i]){
                int j=e[i];
                if(!color[j]){
                    color[j]=3-color[t];
                    q[++tt]=j;
                }else if(color[j]==color[t]) return false;
            }
        }
        return true;
    }
    int main()
    {
        cin>>n>>m;
        while(m--){
            int a,b;
            cin>>a>>b;
            add(a,b),add(b,a);
        }
        bool flag=true;
        for(int i=1;i<=n;i++){
            if(!color[i]){
                if(!bfs(i)){//bfs()的含义就是进行二分染色，成功就返回true,否则false
                    flag=false;
                    break;
                }
            }
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        return 0;
    }
    

###### DFS写法

    int n;      // n表示点数
    int h[N], e[M], ne[M], idx;     // 邻接表存储图
    int color[N];       // 表示每个点的颜色，-1表示未染色，0表示白色，1表示黑色
    
    // 参数：u表示当前节点，c表示当前点的颜色
    bool dfs(int u, int c)
    {
        color[u] = c;
        for (int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (color[j] == -1)
            {
                if (!dfs(j, !c)) return false;
            }
            else if (color[j] == c) return false;
        }
    
        return true;
    }
    
    bool check()
    {
        memset(color, -1, sizeof color);
        bool flag = true;
        for (int i = 1; i <= n; i ++ )
            if (color[i] == -1)
                if (!dfs(i, 0))
                {
                    flag = false;
                    break;
                }
        return flag;
    }
    

##### BFS好理解，DFS简洁。基于染色原理，邻接表存储好一点，无向图存两边，M为两倍N。

* * *

匈牙利算法
-----

> 匈牙利算法，又称为Kuhn-Munkres算法或者KM算法，是一种用于解决分配问题的优化算法。

##### 目前本文的应用仅限于`求二分图最大匹配数`

*   一个匹配是一个图的边集合，满足集合中的任意两条边都不与同一个顶点相邻。也就是说，每个顶点只与集合中的一条边相邻。最大匹配，就是所有匹配中，包含边数最多的匹配。
    *   可以理解为男女关系，不存在一男多女或者一女多男的关系。即集合中任意两条边都不存在一个相同的顶点。

##### y总“死缠烂打大法”，时间复杂度o(nm)。

*   将其中一个集合的所有元素遍历一遍，每次遍历过程中，遍历该节点所有出边，为其匹配另外一个集合中的节点。
    *   如果另外一个集合的节点——未匹配，直接匹配即可。
    *   如果另外一个集合的节点——已匹配，让这个已匹配点的对应点，往后寻找看看能不能换一个节点匹配，把这个当前已匹配的节点让出来，让别人匹配。如果不能改点就无法匹配。

##### 通俗一点讲，A男和C女早就匹配，现在B男尝试和C女匹配。B男开启死缠烂打模式，让和C女匹配的A男换一个匹配对象，把C女让给B男。A男同意了，就尝试通过出边去寻找后面的能匹配的女的。如果找到了就把C女让给B男，三人皆大欢喜。如果没找到，A男就不让了，B男这个点就依据自己得出边看看有没有下一个，重复以上操作，没有就寄了，这B没有匹配的边。

    #include<iostream>
    #include<cstring>
    #include<algorithm>
    using namespace std;
    const int N=510,M=1e5+10;
    //采取什么方式建图更多的是取决于时间复杂度和我们到底在算法处理过程中需要什么样的数据
    //实际应用中二分图大多是无向图，但这里不需要存u->v和v->u的边，假设我们从u开始遍历这个集合求二分图最大匹配
    //那么我们每次组要处理的是u中点的出边，整个算法流程中并不涉及从v->u的边，因此只要存储u->u的边即可。
    int h[N],e[M],ne[M],idx;
    int n1,n2,m;
    int match[N];//存储v集合中被匹配的点，对应点是u集合中的哪个
    bool st[N];//当u对应点放弃当前匹配去尝试寻找下一个，最重要的作用就是避免在第一个点的时候无限递归下去
    void add(int a,int b){
        e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    }
    //如果x节点能找到一个匹配就返回true
    bool find(int x){
        for(int i=h[x];i!=-1;i=ne[i]){
            int j=e[i];
            if(!st[j]){
                st[j]=true;
                if(match[j]==0||find(match[j])){
                    match[j]=x;//最核心的一步，找到了合适的别忘了修改
                    return true;
                }
            }
        }
        return false;
    }
    int main()
    {
        memset(h,-1,sizeof h);
        cin>>n1>>n2>>m;
        while(m--){
            int u,v;
            cin>>u>>v;
            add(u,v);
        }
        int res=0;
        for(int i=1;i<=n1;i++){
            memset(st,0,sizeof st);
            if(find(i)){
                res++;
            }
        }
        cout<<res;
        return 0;
    }
    

##### 我个人认为细思递归是一件比较愚蠢的事情，人脑压栈几层就报废了。。如果想更好的理解原理当然可以，但使用或者编写的时候，我觉得抓住这个递归的定义和返回值就行，然后只管用就是，别想太多~