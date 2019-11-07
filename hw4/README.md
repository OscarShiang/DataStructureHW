# Assignment 4 Description

在本次作業中，我使用了`struct`來建立Linked list的單一節點
利用`class`來來包裝並維護整個`linked list`的資料
在資料的利用上，我使用`private`變數`head`與`tail`來記錄`linked list`的起點與終點
最後使用`class destructor`將剩餘的`node`刪除

### Solitaire
在這個作業的實作上，我還是使用`bool`陣列來記錄哪些牌已經被發出，並利用`do-while`迴圈避免重複的牌被發出
接著運用`remain`變數將 K ~ A 依序抽出牌組<br/>
如果牌組的第一張就是我們要抽出的牌，就將儲存該張牌的node從list中`pop`出來，將其刪除<br/>
如果第一張牌不是我們要抽出的牌，一樣將該其pop出來，並再push回list的最後<br/>
並印出每次執行的牌組狀態，直到所有牌都被抽出

### Queueing in Costco 
我首先使用char陣列記錄哪些人是同一組的朋友，並在每個一組朋友輸入完畢後在陣列的最後加上一個`'\0'`字元，作為陣列的結束

當程式執行到`ENQUEUE`指令的時候，我會先搜尋這個輸入是否有朋友，如果有朋友的話，就將這個朋友的陣列與輸入一同傳進enqueue函式中，<br/>
若朋友在隊伍中的話，就將該輸入`insert`到朋友的前方<br/>
如果沒有朋友在隊伍中的話，就將該輸出`push`到隊伍的最後

當程式執行到`DEQUEUE`的時候，就將list最前面的node執行`pop`將節點取出，印出它的值並將他刪除

### 與 Assignment 3 的差異
在Assignment 3中我是使用int陣列來實作牌組的序列與排隊的狀況<br/>
所以在執行不論是抽出牌組`dequeue`或`enqueue`的動作的時候都需要將整個陣列剩餘的元素向前向後進行推移，以達到維護與更新資料的目的

而在使用linked list來實作同樣的題目時，只需要透過對linked list的`head`與`tail`進行操作或是將節點直接插入到序列之中就可以達到同樣的效果，而不用改動整個序列，並節省空間上的浪費