# Assignment 2 Description

### Solitaire
我將這個程式分為兩個部分，分別為`牌組生成`與`抽出牌組`

##### 1. 牌組生成
在生成牌組的方法上，我使用一個bool陣列`exist`來記錄這個數字是不是已經有抽過了，如果已經有抽過這個數字的話，就執行`do-while`迴圈重複抽牌的動作直到抽出尚未被抽出的牌

##### 2. 抽出牌組
在依序抽出排的方法上，我利用`remain`函數來記錄現在還未被抽出的牌數。當牌組的第一張牌不是當次應該抽出的牌時，將該牌紀錄起來，把剩餘的牌向前位移一格，並將剛剛記錄下來的牌放在牌組的最後；若是該回合要抽出的牌的話，則直接將後方牌組向前位移一格，並將`remain`減1，直到remain == 0的時候就跳出迴圈結束程式