[算法基础模板整理（基础图论篇）](https://www.cnblogs.com/MarisaMagic/p/17318016.html "发布于 2023-04-14 13:23")
=============================================================================================

# 拓扑排序
====

C++
```
bool topo(){
    queue<int> q;
    for(int u = 1; u <= n; u ++ )
        if(!ind\[u\]) q.push(u);
    
    int cnt = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cnt ++ ;
        ans.push_back(u);
        for(int i = h\[u\]; i != -1; i = ne\[i\]){
            int v = e\[i\];
            if(!(--ind\[v\])) q.push(v);
        }
    }
    
    return cnt == n;
}

```

  

# 最短路
===

## 朴素Dijkstra
----------

C++
```
int dijkstra(){
    memset(dist, 0x3f, sizeof(dist));  dist\[1\] = 0;
    //循环n次 将n个点都加入最短路径网络（树）
    for(int i = 0; i < n; i ++ ){
        int t = -1;   //找到网络外距离源点最近的点
        for(int v = 1; v <= n; v ++ )
            if(!st\[v\] && (t == -1 || dist\[v\] < dist\[t\]))
                t = v;
        st\[t\] = true;   //加入最短路径网络 作为扩展点
        for(int j = h\[t\]; j != -1; j = ne\[j\]){
            int to = e\[j\], c = w\[j\];   
            if(!st\[to\]) dist\[to\] = min(dist\[to\], dist\[t\] + c);
        }
    }
    return dist\[n\] == inf ? -1 : dist\[n\];
}
```
## 堆优化Dijkstra
-----------

C++
```
int dijkstra(){
    memset(dist, 0x3f, sizeof(dist));   dist\[1\] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> q;  q.push({0, 1});    
    while(!q.empty()){
        auto \[d, t\] = q.top();
        q.pop();
        if(st\[t\]) continue;   //有的点可能被重复加入
        st\[t\] = true;
        for(int i = h\[t\]; i != -1; i = ne\[i\]){
            int v = e\[i\], c = w\[i\];
            if(dist\[v\] > d + c){
                dist\[v\] = d + c;
                q.push({dist\[v\], v});
            }
        }
    }
    return dist\[n\] == inf ? -1 : dist\[n\];
}
```
* * *

  

## SPFA
----

C++


```
int spfa(){
    memset(dist, 0x3f, sizeof(dist));
    queue<int> q; q.push(1);
    dist\[1\] = 0, st\[1\] = true;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        st\[t\] = false;  //重新标记为false 之后有可能再次入队
        for(int i = h\[t\]; i != -1; i = ne\[i\]){
            int v = e\[i\], c = w\[i\];
            if(dist\[v\] > dist\[t\] + c){
                dist\[v\] = dist\[t\] + c;
                if(!st\[v\]) q.push(v), st\[v\] = true;
            }
        }
    }
    return dist\[n\];
}
```


## SPFA判断负环
--------

C++


```
int spfa(){
    queue<int> q;
    for(int i = 1; i <= n; i ++ ) q.push(i), st\[i\] = true;//所有点放入点集
    //只遍历已经更新过距离的点，避免Bellman_Ford中每次遍历所有边的情况
    while(!q.empty()){
        int t = q.front();
        q.pop();
        st\[t\] = false;    //重新标记为false 之后有可能再次入队
        for(int i = h\[t\]; i != -1; i = ne\[i\]){
            int v = e\[i\], c = w\[i\];
            if(dist\[v\] > dist\[t\] + c){
                dist\[v\] = dist\[t\] + c;
                cnt\[v\] = cnt\[t\] + 1;          //记录cnt
                if(cnt\[v\] >= n) return true;  //存在负环
                if(!st\[v\]) q.push(v), st\[v\] = true;
            }
        }
    }
    return false;
}
```


## SPFA SLF优化
----------

C++


```
void spfa(){
    memset(dist, 0x3f, sizeof(dist));
    deque<int> q; q.push_back(src);
    st\[src\] = true, dist\[src\] = 0;
    while(!q.empty()){
        ...
        //SLF优化
        for(int i = h\[t\]; i != -1; i = ne\[i\])
            ...
                    if(!q.empty() && dist\[v\] < dist\[q.front()\]) 
q.push_front(v);
                    else q.push_back(v);
                    st\[v\] = true;
            ...
        }
    }
}
```


## Floyd
-----

C++

```

void init(){
    for(int i = 1; i <= n; i ++ )
        for(int j = 1; j <= n; j ++ )
            if(i == j) continue;
            else dist\[i\]\[j\] = inf;
}
void floyd(){
    for(int k = 1; k <= n; k ++ )
        for(int i = 1; i <= n; i ++ )
            for(int j = 1; j <= n; j ++ )
                dist\[i\]\[j\] = min(dist\[i\]\[j\], dist\[i\]\[k\] + dist\[k\]\[j\]);
} 
```


* * *

  

# 最小生成树
=====

## Prim
----

C++


```
int prim(){
    memset(dist, 0x3f, sizeof(dist));
    int ans = 0;
    for(int i = 0; i < n; i ++ ){
        int t = -1;    //集合外最近的点作为扩展点
        for(int v = 1; v <= n; v ++ )
            if(!st\[v\] && (t == -1 || dist\[v\] < dist\[t\]))
                t = v;
        if(i && dist\[t\] == inf) return inf;  //不存在最小生成树
        if(i) ans += dist\[t\];
        st\[t\] = true;
        for(int v = 1; v <= n; v ++ )
            dist\[v\] = min(dist\[v\], g\[t\]\[v\]);
    }
    return ans;
}
```


## Kruskal
-------

C++


```
struct edge{
    int u, v, w;
}e\[M\];
int fa\[N\], n, m, cnt, ans;
int find(int x){
    return fa\[x\] == x ? x : (fa\[x\] = find(fa\[x\]));
}
int kruskal(){
    for(int i = 1; i <= n; i ++ ) fa\[i\] = i;
    sort(e + 1, e + m + 1, \[\](struct edge &a, struct edge &b){
        return a.w < b.w;
    });
    for(int i = 1; i <= m; i ++ ){
        int fu = find(e\[i\].u), fv = find(e\[i\].v);
        if(fu == fv) continue;    //在同一个集合中 会形成环
        fa\[fv\] = fu;
        ans += e\[i\].w;
        cnt ++ ;
    }
    if (cnt < n - 1) return inf;
    return ans;
}
```


* * *

  

# Tarjan
======

## Tarjan求LCA
----------

C++


```
void tarjan(int u){
    st\[u\] = 1;
    for(int i = h\[u\]; i != -1; i = ne\[i\]){
        int v = e\[i\];
        if(!st\[v\]){
            tarjan(v);
            fa\[v\] = u;
        }
    }
    for(auto \[v, id\] : query\[u\]){
        if(st\[v\]){
            int anc = find(v);    //最近公共祖先  find和并查集一样
            if(anc == u) res\[id\] = 1;   
            else if(anc == v) res\[id\] = 2;
            else res\[id\] = 0;
        }
    }
}
```


## Tarjan求树上两点最近距离
---------------

C++


```
//深搜求出节点到根节点的距离
void dfs(int u, int fa){
    for(int i = h\[u\]; i != -1; i = ne\[i\]){
        int v = e\[i\];
        if(fa == v) continue;
        dist\[v\] = dist\[u\] + w\[i\];   
        dfs(v, u);
    }
}
void tarjan(int u){
    st\[u\] = true;
...
    for(auto \[v, id\] : query\[u\]){
        if(st\[v\]){
            int anc = find(v);  //如果被访问过 那么LCA为find(v)
            res\[id\] = dist\[u\] + dist\[v\] - 2 * dist\[anc\];  
            //两点距离为两点到根节点的距离和减去两倍的LCA根节点的距离
        }
    }
}
```


## Tarjan判断割边
----------

C++


```
void tarjan(int u, int in_edge){
    dfn\[u\] = low\[u\] = ++ num;
    st\[ ++ top\] = u;
    for(int i = h\[u\]; i != -1; i = ne\[i\]){
        int v = e\[i\];
        if(!dfn\[v\]){
            tarjan(v, i);                  //自底向上
            low\[u\] = min(low\[u\], low\[v\]);  //更新当前节点的最小时间戳
            if(low\[v\] > dfn\[u\])         //无法回退到u
                bridge\[i\] = bridge\[i ^ 1\] = true;  //割边
        }else if(i != (in_edge ^ 1))
            low\[u\] = min(low\[u\], dfn\[v\]);   //处理回退边
    }
    
    if(dfn\[u\] == low\[u\]){  //双连通分量起点u
        dcc_cnt ++ ; int v;
        do{ v = st\[top -- \];   id\[v\] = dcc_cnt;   //割边
        }while(v != u);
    }
}
int ans(){
for(int i = 0; i < idx; i ++ ) if(bridge\[i\]) d\[id\[e\[i\]\]\] ++ ;   
//边i为割边 那么两边度数 + 1
for(int i = 1; i <= dcc_cnt; i ++ ) if(d\[i\] == 1) cnt ++ ;  
return (cnt + 1) / 2;
}
```


## Tarjan判断割点
----------

C++


```
void tarjan(int u, int in_edge){
    dfn\[u\] = low\[u\] = ++ num;
    int flag = 0;
    for(int i = h\[u\]; i != -1; i = ne\[i\]){
        int v = e\[i\];
        if(!dfn\[v\]){
            tarjan(v, i);                  //自底向上
            low\[u\] = min(low\[u\], low\[v\]);  //更新当前节点的最小时间戳
            if(low\[v\] >= dfn\[u\]){        
                flag ++ ;
                if(u != root || flag > 1) cut\[u\] = true;
            }
        }else low\[u\] = min(low\[u\], dfn\[v\]);
    }
}
```


* * *

  

# 二分图
===

## 染色法判定二分图
--------

C++


```
bool dfs(int u, int c){
    color\[u\] = c;
    for(int i = h\[u\]; i != -1; i = ne\[i\]){
        int v = e\[i\];
        if(!color\[v\]){  //如果没有被染过色
            if(!dfs(v, 3 - c)) return false;  //自底向上 深度染色关联节点
        }else if(color\[v\] == c) return false; //已经染色 但是相邻颜色相同
    }
    return true;
}
bool isBigraph(){
    bool flag = true;
    for(int i = 1; i <= n; i ++ )
        if(!color\[i\])
            if(!dfs(i, 1)){
                flag = false;
                break;
            }
    return flag;
}
```


## 匈牙利算法 二分图的最大匹配
--------------

C++


```
bool find(int u){
    for(int i = h\[u\]; i != -1; i = ne\[i\]){ //询问所有与u相关联的男生
        int v = e\[i\];
        if(!st\[v\]){        //男生还没被预定
            st\[v\] = true;
            if(match\[v\] == 0 || find(match\[v\])){
                //如果男生还没有女朋友 或者 男生更换原配换成现在的女孩
                match\[v\] = u;   //v的女朋友是u
                return true;
            }
        }
    }
    return false;
}
int max_match(){
    for(int i = 1; i <= n1; i ++ ){
        memset(st, 0, sizeof(st));
        if(find(i)) res ++ ;
    }
    return res;   
}
```


*   [拓扑排序](#拓扑排序)
*   [最短路](#最短路)
*   [    朴素Dijkstra](#朴素dijkstra)
*   [    堆优化Dijkstra](#堆优化dijkstra)
*   [    SPFA](#spfa)
*   [    SPFA判断负环](#spfa判断负环)
*   [    SPFA SLF优化](#spfa-slf优化)
*   [    Floyd](#floyd)
*   [最小生成树](#最小生成树)
*   [    Prim](#prim)
*   [    Kruskal](#kruskal)
*   [Tarjan](#tarjan)
*   [    Tarjan求LCA](#tarjan求lca)
*   [    Tarjan求树上两点最近距离](#tarjan求树上两点最近距离)
*   [    Tarjan判断割边](#tarjan判断割边)
*   [    Tarjan判断割点](#tarjan判断割点)
*   [二分图](#二分图)
*   [    染色法判定二分图](#染色法判定二分图)
*   [    匈牙利算法 二分图的最大匹配](#匈牙利算法-二分图的最大匹配)

  

\_\_EOF\_\_

[![](https://pic.cnblogs.com/avatar/3039354/20230831022235.png)](https://pic.cnblogs.com/avatar/3039354/20230831022235.png)

*   **本文作者：** [MarisaMagic](https://www.cnblogs.com/MarisaMagic)
*   **本文链接：** [https://www.cnblogs.com/MarisaMagic/p/17318016.html](https://www.cnblogs.com/MarisaMagic/p/17318016.html)
*   **关于博主：** 评论和私信会在第一时间回复。或者[直接私信](https://msg.cnblogs.com/msg/send/MarisaMagic)我。
*   **版权声明：** 本博客所有文章除特别声明外，均采用 [BY-NC-SA](https://creativecommons.org/licenses/by-nc-sa/4.0/ "BY-NC-SA") 许可协议。转载请注明出处！
*   **声援博主：** 如果您觉得文章对您有帮助，可以点击文章右下角**【[推荐](javascript:void(0);)】**一下。

一切都是命运石之门的选择，本文章来源于博客园，作者：[MarisaMagic](https://www.cnblogs.com/MarisaMagic/)，出处：[https://www.cnblogs.com/MarisaMagic/p/17318016.html](https://www.cnblogs.com/MarisaMagic/p/17318016.html)，未经允许严禁转载

分类: [算法](https://www.cnblogs.com/MarisaMagic/category/2405348.html)

标签: [Acwing](https://www.cnblogs.com/MarisaMagic/tag/Acwing/) , [C++](https://www.cnblogs.com/MarisaMagic/tag/C%2B%2B/) , [基础算法模板](https://www.cnblogs.com/MarisaMagic/tag/%E5%9F%BA%E7%A1%80%E7%AE%97%E6%B3%95%E6%A8%A1%E6%9D%BF/)

[好文要顶](javascript:void(0);)推荐该文

[关注我](javascript:void(0);)关注博主关注博主 [收藏该文](javascript:void(0);)收藏本文 [微信分享](javascript:void(0);)分享微信

[![](https://pic.cnblogs.com/face/3039354/20230831022235.png)](https://home.cnblogs.com/u/MarisaMagic/)

[MarisaMagic](https://home.cnblogs.com/u/MarisaMagic/)  
[粉丝 \- 87](https://home.cnblogs.com/u/MarisaMagic/followers/) [关注 \- 7](https://home.cnblogs.com/u/MarisaMagic/followees/)  

[+加关注](javascript:void(0);)

0

0

[«](https://www.cnblogs.com/MarisaMagic/p/17317078.html) 上一篇： [算法基础模板整理（基础搜索篇）](https://www.cnblogs.com/MarisaMagic/p/17317078.html "发布于 2023-04-14 01:05")  
[»](https://www.cnblogs.com/MarisaMagic/p/17318023.html) 下一篇： [算法基础模板整理（高阶数据结构篇）](https://www.cnblogs.com/MarisaMagic/p/17318023.html "发布于 2023-04-14 13:27")

posted @ 2023-04-14 13:23  [MarisaMagic](https://www.cnblogs.com/MarisaMagic)  阅读(16)  评论(0)  [编辑](https://i.cnblogs.com/EditPosts.aspx?postid=17318016)  [收藏](javascript:void(0))  [举报](javascript:void(0))

var cb\_entryId = 17318016, cb\_entryCreatedDate = '2023-04-14 13:23', cb\_postType = 1, cb\_postTitle = '算法基础模板整理（基础图论篇）'; var allowComments = true, cb\_blogId = 776044, cb\_blogApp = 'MarisaMagic', cb\_blogUserGuid = '54f617e2-2e28-4b39-02a0-08daa8657cf1'; mermaidRender.render() markdown\_highlight() zoomManager.apply("#cnblogs\_post\_body img:not(.code\_img\_closed):not(.code\_img\_opened)");

[会员力量，点亮园子希望](https://cnblogs.vip/)

[刷新页面](#)[返回顶部](#top)

登录后才能查看或发表评论，立即 [登录](javascript:void(0);) 或者 [逛逛](https://www.cnblogs.com/) 博客园首页

[【推荐】轻量又高性能的 SSH 工具 IShell：AI 加持，快人一步](http://ishell.cc/)  
[【推荐】100%开源！大型工业跨平台软件C++源码提供，建模，组态！](http://www.uccpsoft.com/index.htm)  
[【推荐】「废话少说，放码过来」：博客园2024夏季短袖T恤上架啦](https://www.cnblogs.com/cmt/p/18219378)  
[【推荐】会员力量，点亮园子希望，期待您升级成为博客园VIP会员](https://cnblogs.vip/buy)  

 [![](https://img2024.cnblogs.com/blog/35695/202403/35695-20240328092537879-1189167464.jpg)](https://cnblogs.vip/) 

**编辑推荐：**  
· [从 C++ 看 C# 托管内存与非托管内存](https://www.cnblogs.com/ggtc/p/18333486)  
· [SpringBoot2.7还是任性的，就是不支持Logback1.3](https://www.cnblogs.com/youzhibing/p/18327929)  
· [.NET 高性能缓冲队列实现 BufferQueue](https://www.cnblogs.com/eventhorizon/p/18331018)  
· [C#中使用 record 的好处](https://www.cnblogs.com/vipwan/p/18325508)  
· [如何让 SQL Server 像 MySQL 一样拥有慢查询日志](https://www.cnblogs.com/lyhabc/p/18322758)  

**阅读排行：**  
· [救园行动——赞助商计划](https://www.cnblogs.com/cmt/p/18333440)  
· [自从用了这些监控工具，我连续几天没睡好觉！](https://www.cnblogs.com/yupi/p/18336341)  
· [C#/.NET/.NET Core优秀项目和框架2024年7月简报](https://www.cnblogs.com/Can-daydayup/p/18335855)  
· [园子的困境：技术社区的自我革新之路](https://www.cnblogs.com/qqloving/p/18338478)  
· [EF Core性能优化技巧](https://www.cnblogs.com/baibaomen-org/p/18338447)  

var commentManager = new blogCommentManager(); commentManager.renderComments(0); fixPostBody(); window.footnoteTipManager.generateFootnoteTips(); setTimeout(function() { countViews(cb\_blogId, cb\_entryId); }, 50); deliverT2(); deliverC1C2(); loadNewsAndKb(); LoadPostCategoriesTags(cb\_blogId, cb\_entryId); LoadPostInfoBlock(cb\_blogId, cb\_entryId, cb\_blogApp, cb\_blogUserGuid); GetPrevNextPost(cb\_entryId, cb\_blogId, cb\_entryCreatedDate, cb\_postType); loadOptUnderPost(); GetHistoryToday(cb\_blogId, cb\_blogApp, cb_entryCreatedDate);