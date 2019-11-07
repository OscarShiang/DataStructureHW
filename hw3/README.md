# Assignment 3 Description
### Queueing in Costco
在本次作業中，我使用vector陣列`friends`來記錄哪些是朋友，並實作一個以int陣列為資料的class：Queue來記錄隊伍的情況

#### Enqueue
在進行`enqueue`的時候，我會先搜尋這個剛輸入的char是否有朋友，若有朋友的話就將對應的friends vector與char一起傳進Queue的enqueue函式中，若沒有朋友的話就傳入空的vector<br>
接著比較朋友的位置比較小還是隊伍的長度 (length) 比較小，如果剛剛傳入的vector不是空的的話，就將該位置以後的所有字元向後推一格，並將剛剛輸入的字元放進該位置<br>
若剛剛傳入的vector是空的話就把輸入的字元放在隊伍的最後

#### Dequeue
當執行`dequeue`時，首先先確定隊伍的長度 > 0，若隊伍長度不大於0的話就直接跳出function；若隊伍長度大於0的話，將隊伍的第一個元素印出，並將後面所有元素向前位移一格