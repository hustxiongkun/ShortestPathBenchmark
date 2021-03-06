# 测试算例

## 算例特征

| 算例覆盖类型                  | 描述                                       | 典型算例 |
| :---------------------- | :--------------------------------------- | :--- |
| 节点数                     | 100, 500, 1000, 5000, 10000, 50000       |      |
| 边密度 ($|E|/|V|^2$)       | 0.01, 0.05, 0.1, 0.5, 1                  |      |
| 最大边权重                   | 10, 100, 1000, 10000                     |      |
| 拓扑结构                    | 网格 (grid), 聚团 (cluster), 总线 (bus), 随机 (random), 无环 (acyclic) |      |
| 起点终点距离 ($hop/\sqrt{V}$) | 0.1, 0.5, 1, 5                           |      |
| 终点相同重复次数                | 1, 100, 10000                            |      |
| 总重复次数                   | 1000000                                  |      |
| 路径需求                    | 点对点 (point to point), 单源点 (single source), 任意点间 (all pair) |      |

## 算例来源

| 算法类型   | 描述                                       |
| ------ | ---------------------------------------- |
| TSPLIB | http://www.iwr.uni-heidelberg.de/groups/comopt/software/TSPLIB95/ |
| DIMACS | http://dimacs.rutgers.edu/Challenges/    |
| 自行生成   |                                          |

# 测试算法

## 算法框架

| 算法类型         | 描述   |
| :----------- | :--- |
| Dijkstra     |      |
| A*           |      |
| Bellman-Ford |      |
| Floyd        |      |

## 代码来源

| 名称           | 算法类型                              | 链接                                       |
| ------------ | --------------------------------- | ---------------------------------------- |
| CoinOR.lemon | Dijkstra                          | http://lemon.cs.elte.hu/trac/lemon       |
| CoinOR.cgc   | Dijkstra                          | https://projects.coin-or.org/Cgc         |
| CppUtilibs   | Dijkstra, A*, Bellman-Ford, Floyd | https://github.com/Zhouxing-Su/CppUtilibs/blob/master/algorithm/Graph.h |
|              | A*                                |                                          |
|              | Bellman-Ford                      |                                          |
|              | Floyd                             |                                          |

# 评估标准

## 可配置性

### Dijkstra

| 配置                          | 描述           |
| :-------------------------- | :----------- |
| 朴素实现 (naive)                | $\checkmark$ |
| 二叉堆 (binary heap)           | $\surd$      |
| 二项堆 (binomial heap)         |              |
| 斐波那契堆 (fibonacci heap)      |              |
| 配对堆 (pairing heap)          |              |
| 排名配对堆 (rank pairing heap)   |              |
| 桶队列 (bucket queue)          |              |
| 双向搜索 (bidirectional search) |              |

### A*

| 配置                   | 描述   |
| -------------------- | ---- |
| Dijkstra 的所有配置       |      |
| 打破平局 (breaking ties) |      |

### Bellman-Ford

| 配置                         | 描述   |
| -------------------------- | ---- |
| 队列优化 (queue)               |      |
| 先扩展较近点 (small label first) |      |
| 后扩展较远点 (large label last)  |      |

## 性能

| 测量标准 | 描述   |
| :--- | :--- |
| 时间   |      |
| 内存消耗 |      |

# 参考文献

1. http://theory.stanford.edu/~amitp/GameProgramming/