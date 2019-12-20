# Assignment 8 Description

### Single Source Shortest Paths
我使用`Bellman-Ford Algorithm`來實作本題，</br>
以BFS掃描所有相連節點的距離並重新更新為新的節點權重，並將該`BFS Tree`的每個節點的父節點記錄起來，方便在掃描完後追蹤最短路徑

### All Pair Shortest Paths
第二題我使用的方法與前一題類似，但加入判斷使程式能夠產生所以配對組合，並進行`BFS Tree`生成，最後將結果印出。