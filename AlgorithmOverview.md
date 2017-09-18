# 算法信息

## 代码来源

| 名称           | 算法类型                              | 链接                                       | 测试ID |
| ------------ | --------------------------------- | ---------------------------------------- | ---- |
| CoinOR.lemon | Dijkstra                          | http://lemon.cs.elte.hu/trac/lemon       | A    |
| CoinOR.cgc   | Dijkstra                          | https://projects.coin-or.org/Cgc         | B    |
| CppUtilibs   | Dijkstra, A*, Bellman-Ford, Floyd | https://github.com/Zhouxing-Su/CppUtilibs/blob/master/algorithm/Graph.h | C    |
|              | A*                                |                                          |      |
|              | Bellman-Ford                      |                                          |      |
|              | Floyd                             |                                          |      |
|              | Dijkstra                          | https://github.com/andrewhayward/dijkstra/blob/master/graph.js | D    |
|              | Dijkstra                          | https://github.com/vterron/dijkstra/blob/master/dijkstra.py | E    |
|              | Dijkstra                          | https://github.com/graphhopper/graphhopper/blob/master/core/src/main/java/com/graphhopper/routing/Dijkstra.java | F    |
|              | A*                                | https://github.com/graphhopper/graphhopper/blob/master/core/src/main/java/com/graphhopper/routing/AStar.java | G    |
|              | Dijkstra                          | https://github.com/Professorq/dijkstra/blob/master/algorithm.go | H    |
|              | Dijkstra                          | https://github.com/ibaaj/dijkstra-cartography/blob/master/flights/main.cpp | I    |
|              | Dijkstra                          | https://github.com/mapa17/Dijkstra/blob/master/dijkstra.c | J    |
|              | Dijkstra                          | https://github.com/thinkphp/dijkstra/blob/master/dijkstra.c     https://github.com/thinkphp/dijkstra/blob/master/algorithm-dijkstra.cpp | K    |
|              | Dijkstra                          | https://github.com/fedelebron/Dijkstra/blob/master/dijkstra.c | L    |
|              |                                   |                                          |      |



## 可配置性

### 配置简称

| 配置                          | 描述ID  |
| --------------------------- | ----- |
| 朴素实现 (naive)                | D.N   |
| 二叉堆 (binary heap)           | D.BAH |
| 二项堆 (binomial heap)         | D.BOH |
| 斐波那契堆 (fibonacci heap)      | D.FH  |
| 配对堆 (pairing heap)          | D.PH  |
| 排名配对堆 (rank pairing heap)   | D.RPH |
| 桶队列 (bucket queue)          | D.BQ  |
| 双向搜索 (bidirectional search) | D.BS  |
| 打破平局 (breaking ties)        | A.BT  |
| 队列优化 (queue)                | B.Q   |
| 先扩展较近点 (small label first)  | B.SLF |
| 后扩展较远点 (large label last)   | B.LLL |

### Dijkstra

| 测试ID\配置 | D.N          | D.BAH        | D.BOH        | D.FH         | D.PH         | D.RPH | D.BQ | D.BS |
| ------- | ------------ | ------------ | ------------ | ------------ | ------------ | ----- | ---- | ---- |
| A       | $\checkmark$ |              |              |              |              |       |      |      |
| B       |              | $\checkmark$ |              |              |              |       |      |      |
| C       |              |              | $\checkmark$ |              |              |       |      |      |
| D       |              |              |              | $\checkmark$ |              |       |      |      |
| E       |              |              |              |              | $\checkmark$ |       |      |      |
| F       |              |              |              |              |              |       |      |      |
| H       |              |              |              |              |              |       |      |      |
| I       |              |              |              |              |              |       |      |      |
| J       |              |              |              |              |              |       |      |      |
| K       |              |              |              |              |              |       |      |      |
| L       |              |              |              |              |              |       |      |      |

### A*

| 测试ID\配置 | D.N          | D.BAH        | D.BOH        | D.FH | D.PH | D.RPH | D.BQ | D.BS | A.BT |
| ------- | ------------ | ------------ | ------------ | ---- | ---- | ----- | ---- | ---- | ---- |
| C       | $\checkmark$ |              |              |      |      |       |      |      |      |
| G       |              | $\checkmark$ |              |      |      |       |      |      |      |
|         |              |              | $\checkmark$ |      |      |       |      |      |      |

### Bellman-Ford

| 测试ID\配置 | B.Q          | B.SLF        | B.LLL        |
| ------- | ------------ | ------------ | ------------ |
|         | $\checkmark$ |              |              |
|         |              | $\checkmark$ |              |
|         |              |              | $\checkmark$ |

