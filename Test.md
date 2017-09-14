然后算例生成, 可以用张军琛那个, 也可以直接到TSPLIB这种公开的算例库里面下载, 自己只用稍微改下算例把起点终点加上就可以了

参考：https://github.com/miloyip/nativejson-benchmark



找算法：



http://lemon.cs.elte.hu/trac/lemon

https://projects.coin-or.org/Cgc

https://github.com/Zhouxing-Su/CppUtilibs/blob/master/algorithm/Graph.h

github, google查找算法



一个是功能也弄个表, 比如支不支持配置优先队列, 支不支持自定义停止条件之类的

一个是测试算例还可以覆盖下起点终点跳数不同的

前面那个停止条件就是我可以扩展完所有节点停止, 或者扩展到指定点(终点)停止, 或者扩展到某些特殊节点停止(比如双向搜索另一侧已扩展的节点), 或者扩展前k个节点就停止, 等等

后面那个跳数, 主要是bellman-ford这种只能算一个单源点最短路, 不能想a*或者dijkstra那样到达终点时提前退出, 可能在不同算例上性能波动会比较大