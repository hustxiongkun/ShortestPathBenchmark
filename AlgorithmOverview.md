# 算法信息

## 代码来源

| 名称           | 算法类型                              | 链接                                       | 测试ID |
| ------------ | --------------------------------- | ---------------------------------------- | ---- |
| CoinOR.lemon | Dijkstra                          | http://lemon.cs.elte.hu/trac/lemon       | 01   |
| CoinOR.cgc   | Dijkstra                          | https://projects.coin-or.org/Cgc         | 02   |
| CppUtilibs   | Dijkstra, A*, Bellman-Ford, Floyd | https://github.com/Zhouxing-Su/CppUtilibs/blob/master/algorithm/Graph.h | 03   |
|              | A*                                |                                          |      |
|              | Bellman-Ford                      |                                          |      |
|              | Floyd                             |                                          |      |
|              |                                   |                                          |      |
|              |                                   |                                          |      |
|              |                                   |                                          |      |
|              |                                   |                                          |      |
|              |                                   |                                          |      |
|              |                                   |                                          |      |
|              |                                   |                                          |      |
|              |                                   |                                          |      |
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

| 测试ID\配置 | D1           | D2           | D3           | D4           | D5           | D6   | D7   | D8   |
| ------- | ------------ | ------------ | ------------ | ------------ | ------------ | ---- | ---- | ---- |
| 01      | $\checkmark$ |              |              |              |              |      |      |      |
| 02      |              | $\checkmark$ |              |              |              |      |      |      |
| 03      |              |              | $\checkmark$ |              |              |      |      |      |
| 04      |              |              |              | $\checkmark$ |              |      |      |      |
| 05      |              |              |              |              | $\checkmark$ |      |      |      |

### A*

| 测试ID\配置 | D1           | D2           | D3           | D4   | D5   | D6   | D7   | D8   | A9   |
| ------- | ------------ | ------------ | ------------ | ---- | ---- | ---- | ---- | ---- | ---- |
| 03      | $\checkmark$ |              |              |      |      |      |      |      |      |
| 04      |              | $\checkmark$ |              |      |      |      |      |      |      |
| 05      |              |              | $\checkmark$ |      |      |      |      |      |      |

### Bellman-Ford

| 测试ID\配置 | B1           | B2           | D3           |
| ------- | ------------ | ------------ | ------------ |
| 03      | $\checkmark$ |              |              |
| 04      |              | $\checkmark$ |              |
| 05      |              |              | $\checkmark$ |

