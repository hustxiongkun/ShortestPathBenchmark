# 算法信息

## 代码来源

| 名称           | 算法类型                              | 链接                                       | 测试ID |
| ------------ | --------------------------------- | ---------------------------------------- | ---- |
| CoinOR.lemon | Dijkstra,Bellman-Ford             | http://lemon.cs.elte.hu/trac/lemon       | A    |
| CoinOR.cgc   | Dijkstra                          | https://projects.coin-or.org/Cgc         | B    |
| CppUtilibs   | Dijkstra, A*, Bellman-Ford, Floyd | https://github.com/Zhouxing-Su/CppUtilibs/blob/master/algorithm/Graph.h | C    |
|              | A*                                | https://github.com/denisov-v/ShortestPath/blob/master/ShortestPath/astar.h | D    |
|              | A*                                | https://github.com/ActiveState/code/blob/master/recipes/C++/577457_Astar_Shortest_Path_Algorithm/recipe-577457.cpp | E    |
|              | Bellman-Ford                      | https://github.com/DLily0129/Data-Structure/blob/master/ShortestPathBellmanFord/ShortestPathBellmanFord/ShortestPathBellmanFord.h | F    |
|              | Bellman-Ford                      | https://github.com/heyitstanyado/BellmanFord/blob/master/BellmanFord.c | G    |
|              | Bellman-Ford                      | http://theoryofprogramming.com/bellman-ford-algorithm-using-cpp-stl/ | H    |
|              | Floyd                             | https://github.com/sysilion/ShortestPath/blob/master/src/main.c | I    |
|              | Dijkstra                          | https://github.com/ibaaj/dijkstra-cartography/blob/master/flights/main.cpp | J    |
|              | Dijkstra                          | https://github.com/dragonslayerx/Competitive-Programming-Repository/blob/master/src/dijkstra_using_priority_queue.cpp | K    |
|              | Dijkstra                          | https://www.quora.com/What-is-the-most-simple-efficient-C++-code-for-Dijkstras-shortest-path-algorithm | L    |
|              | Dijkstra                          | https://github.com/fedelebron/Dijkstra/blob/master/dijkstra.c | M    |



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

| 测试ID\配置 | D.N          | D.BAH | D.BOH | D.FH | D.PH | D.RPH | D.BQ | D.BS |
| ------- | ------------ | ----- | ----- | ---- | ---- | ----- | ---- | ---- |
| A       | $\checkmark$ |       |       |      |      |       |      |      |
|         |              |       |       |      |      |       |      |      |
|         |              |       |       |      |      |       |      |      |
|         |              |       |       |      |      |       |      |      |
|         |              |       |       |      |      |       |      |      |
|         |              |       |       |      |      |       |      |      |
|         |              |       |       |      |      |       |      |      |
|         |              |       |       |      |      |       |      |      |
|         |              |       |       |      |      |       |      |      |
|         |              |       |       |      |      |       |      |      |
|         |              |       |       |      |      |       |      |      |

### A*

| 测试ID\配置 | D.N  | D.BAH | D.BOH | D.FH | D.PH | D.RPH | D.BQ | D.BS | A.BT |
| ------- | ---- | ----- | ----- | ---- | ---- | ----- | ---- | ---- | ---- |
|         |      |       |       |      |      |       |      |      |      |
|         |      |       |       |      |      |       |      |      |      |
|         |      |       |       |      |      |       |      |      |      |

### Bellman-Ford

| 测试ID\配置 | B.Q  | B.SLF | B.LLL |
| ------- | ---- | ----- | ----- |
| A       |      |       |       |
|         |      |       |       |
|         |      |       |       |

