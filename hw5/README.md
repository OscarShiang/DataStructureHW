# Assignment 5 Description

### Monk And Champions League
在本題中，我使用`array`來進行`Max-heap`的實作。</br>
因為`Max-heap`的最大值會位在`array`的第一個位置，所以我透過將最大值累加並將其減一後，重新生成`Max-heap`以保持最大值維持在`array`的第一個位置。
最後將結果印出。

### Height Union
如果使用`height union rule`來實作`collapsing find`的話，`node traversed`的次數會增加。</br>
但如果是使用`weight union rule`來實作函式的話，能讓大部分的情況下的`node traversed`個數減少，而最壞的狀況也不會大於`height union`的次數。
