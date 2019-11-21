### 3月25-29 回溯法

---
## 注意！

> 注意啊，写任何迭代的代码，
> 
> 第一步，想明白要迭代的函数的作用/功能；
> 
> 第二步，想清楚要迭代的函数的返回值；
> 
> 第三步，**用这个返回值当已知条件写好一次迭代**逻辑就全OK了；


#### 一. 思路：
> (1)描述解的形式，定义一个解空间，它包含问题的所有解，这一步主要明确问题的解空间树。
> 
> (2)构造状态空间树。
> 
> (3)构造约束函数（用于杀死节点）。
> 
> 然后就要通过DFS思想完成回溯，具体流程如下：
> 
> (1)设置初始化的方案（给变量赋初值，读入已知数据等）。
> 
> (2)变换方式去试探，若全部试完则转(7)。
> 
> (3)判断此法是否成功（通过约束函数），不成功则转(2)。
> 
> (4)试探成功则前进一步再试探。
> 
> (5)正确方案还未找到则转(2)。
> 
> (6)已找到一种方案则记录并打印。
> 
> (7)退回一步（回溯），若未退到头则转(2)。
> 
> (8)已退到头则结束或打印无解。

#### 二. 算法步骤：
***1*.在动手写算法之前要想明白的事：**
- *树的子节点的空间范围*
- *由此而来的状态变量和层数变量是哪些*

***2*. 开始写算法，所需的函数内部结构如下：**

```
self.ans #解空间
def go_next():      #约束函数
 
def add_ans():      #可以添加临时解至self.ans的条件
 
def go(result,i,j):           #迭代函数，参数为状态变量与层数变量
                     #状态变量一般是可能解目前的状态，和一些辅助信息，帮助约束函数判断。前者用result表示
                     #层数变量一般是位置信息
    if add_ans():
        self.ans.append(copy.deepcopy(result))
    else:
        for i in range(len(子节点空间)) #遍历子节点可能的值
            if go_next():               #如果子节点符合条件，不会被剪枝
                更新状态变量与层数变量
                其中，状态变量需要自更新，层数变量不要自更新
                即，状态变量如result，需要写result.append()这样的，直接去更新变量本身；
                而，层数变量，如记录坐标或者index的i,j等变量，需要写i1 = i+1之类的，然后传给下一个go()，不更新自身
                go(result,i1,j1)
    #然后这里需要细想你for遍历结束时状态变量的改变，是否需要回退，ans.append之后状态变量是否需要回退，之类的问题。如果都需要回退，就在这写，不然就写到if else里面，
    if len(result):
        result.pop()
go([],0,0)
return self.ans
```

---

下面是几个leetcode回溯法典型题与我写的解法(没有优化过，比较烂，但是结构还算清晰)，都是困难难度的：

#### 题目1：
> 给出一个不重复大于0数字的数组和一个目标，求数组中数的组合的和得到该目标（数字不同组合顺序当做一个解）。

###### 解法：
```
#coding:gbk
import copy

class Solution(object):
    def __init__(self):
        self.ans = []               #定义解空间
    def he(self, nums, target):
        """
        :type board: List[int], targer: int
        :rtype: List[List[int]]
        """
        def go_next(now, node):     #构造约束函数
            if sum(now)+node <= target:
                return True
            else:
                return False
        def go(nums1, list1):
            if sum(list1) == target:                    #成功条件
                self.ans.append(copy.deepcopy(list1))
            else:
                for i in range(len(nums1)):
                    if go_next(list1, nums1[i]):
                        list1.append(nums1[i])
                        go(nums1[i+1:],list1)
            if len(list1):
                list1.pop()
        go(nums,[])
        return self.ans

def main():
    a = Solution()
    print(a.he([2,3,7,6,4,5],9))

if __name__ == "__main__":
    main()
```

#### 题目2：
> n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。即不能同行，不能同列，不能互成45度角的斜线。
> 
> 示例:
> 
> 输入: 4
> 输出: [
>  [".Q..",  // 解法 1
>   "...Q",
>   "Q...",
>   "..Q."],
> 
>  ["..Q.",  // 解法 2
>   "Q...",
>   "...Q",
>   ".Q.."]
> ]
> 解释: 4 皇后问题存在两个不同的解法。

###### 解法：
```
#coding:gbk
import copy

class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        self.ans = []                                                                                           #构造解空间
        def go_next1(row, col, next_node):                                                                      #约束函数
            for i in range(len(row)):
                if abs(row[i] - next_node[0]) == abs(col[i] - next_node[1]):
                    return True
            return False
        def go_next(row, col, next_node):
            if (next_node[0] in row) or (next_node[1] in col) or (go_next1(row,col,next_node)):                 #约束函数
                return False
            else:
                return True
        def go(row, col, result, i):                                                                            #go递归函数
            if len(result)==n:                                                                                  #写入ans条件
                self.ans.append(copy.deepcopy(result))
                if len(result):                                                                                     #写入ans了怎么办：回退至上一步状态
                    result.pop()
                    row.pop()
                    col.pop()
            else:                                                                                               #还不足以写入ans时：
                for j in range(n):                                                                                  #遍历解空间树子节点，寻找可能的子节点
                    if go_next(row,col,[i,j]):                                                                          #判断该子节点是否被剪枝
                        row.append(i)                                                                                       #处理状态变量: row col result的改变
                        col.append(j)
                        foo = ""
                        for k in range(n):
                            if k == j:
                                foo += "Q"
                            else:
                                foo += "."
                        result.append(foo)
                        go(row, col, result, i+1)                                                                           #开始遍历树的下一层，传递状态变量row col result，与层数变量i
                if len(result):                                                                                     #遍历该层子节点结束，回退至上一步状态
                    result.pop()                                                                                    #这里为什么不回退i的状态呢？因为i的状态根本就没有被改变！我们没有写i += 1然后传进去
                    row.pop()                                                                                       #而是直接把i+1传到了下一次的go里面去，所以无需回退i的状态
                    col.pop()                                                                                       #所以我觉得这种写法是不规范的，就应该写i += 1，然后回退的时候回退它

        go([],[],[],0)                                                                                          #初始状态，
        return self.ans                                                                                        #返回ans

def main():
    a = Solution()
    print(a.solveNQueens(4))

if __name__ == "__main__":
    main()
```

#### 题目3：
> 解9*9数独，编写一个程序，通过已填充的空格来解决数独问题。
> 
> 一个数独的解法需遵循如下规则：
> 
>     数字 1-9 在每一行只能出现一次。
>     数字 1-9 在每一列只能出现一次。
>     数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
> 
> 空白格用 '.' 表示。
>
> Note:
> 
>     给定的数独序列只包含数字 1-9 和字符 '.' 。
>     你可以假设给定的数独只有唯一解。
>     给定数独永远是 9x9 形式的。
> 

###### 解法：

```
#coding:gbk
import copy

class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        self.ans = []                                                           #解空间

        def go_next(hmp, next_node):                                            #约束函数
            if ('r'+ str(next_node[1][0]+1)) in hmp[next_node[0]] or ('c'+ str(next_node[1][1]+1)) in hmp[next_node[0]] or ('s'+ str(next_node[1][2]+1)) in hmp[next_node[0]]:
                return False
            else:
                return True

        def go(hmp, result, j, k, l, t):                                        #迭代函数，参数为状态变量hmp,result，层数变量为j,k,l,
            if j == 9 :                                                         #最外层处理ans的判断
                self.ans.append(copy.deepcopy(result))                              #加ans
                return self.ans                                                     #返回ans
            else:                                                               #还不能添加ans时
                if board[j][k] != ".":                                              #若是给定的数值，则跳至子节点，维护层数变量，其他不予处理
                    if k == 8:
                        j1 = j + 1
                        k1 = 0
                    else:
                        j1 = j
                        k1 = k + 1
                    l1 = j1 / 3 * 3 + k1 / 3
                    go(hmp, result, j1, k1, l1, board[j][k])
                else:                                                               #若是可以尝试的层，则从1-9这些子节点挨个尝试
                    for i in xrange(1,10):                                              #遍历子节点
                        if go_next(hmp, [i,[j,k,l]]):                                       #约束函数剪枝判断
                            hmp[i].append('r' + str(j+1))                                       #维护状态变量hmp,result，层数变量j,k,l
                            hmp[i].append('c' + str(k+1))
                            hmp[i].append('s' + str(l+1))
                            result[j][k] = str(i)
                            if k == 8:
                                j1 = j+1
                                k1 = 0
                            else:
                                j1 = j
                                k1 = k+1
                            l1 = j1 / 3 * 3 + k1 / 3                                            #这里迭代至下一层时要记得，千万不要直接改状态变量，然后直接传。在这里要j1=j+1，然后传j1，不然会出问题
                            go(hmp,result,j1,k1,l1,i)                                           #维护结束，迭代至下一层
                if k:                                                               #从子节点退回，说明需要回退状态，所以在此维护状态变量hmp,result和层数变量j,k,l
                    k -= 1
                else:
                    j -= 1
                    k = 8
                l = j / 3 * 3 + k / 3
                if board[j][k] == "." and len(hmp[t]):
                    hmp[t].pop()
                    hmp[t].pop()
                    hmp[t].pop()
                    result[j][k] = "."


        def hmp_handle(input):                                                      #预处理
            hmp1 = {1:[],2:[],3:[],4:[],5:[],6:[],7:[],8:[],9:[]}
            for i in xrange(9):
                for j in xrange(9):
                    if input[i][j] != ".":
                        hmp1[int(input[i][j])].append('r' + str(i+1))
                        hmp1[int(input[i][j])].append('c' + str(j+1))
                        hmp1[int(input[i][j])].append('s' + str(i/3*3 + j/3 + 1))
            return hmp1
        result_list = copy.deepcopy(board)
        go(hmp_handle(board),result_list,0,0,0,1)                                   #开始迭代
        return self.ans                                                             #返回ans

def main():
    a = Solution()
    print(a.solveSudoku([["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]))

if __name__ == "__main__":
    main()
```
#### 题目4：
> 在二维网格 grid 上，有 4 种类型的方格：
> 
>     1 表示起始方格。且只有一个起始方格。
>     2 表示结束方格，且只有一个结束方格。
>     0 表示我们可以走过的空方格。
>     -1 表示我们无法跨越的障碍。
> 
> 返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目，每一个无障碍方格都要通过一次。
> 示例 1：
> 
> 输入：[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
> 输出：2
> 解释：我们有以下两条路径：
> 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
> 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
> 
> 示例 2：
> 
> 输入：[[1,0,0,0],[0,0,0,0],[0,0,0,2]]
> 输出：4
> 解释：我们有以下四条路径： 
> 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
> 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
> 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
> 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

###### 解法：

```
#coding:gbk
import copy


class Solution(object):
    def uniquePathsIII(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        self.ans = 0
        self.a = len(grid)
        self.b = len(grid[0])
        self.ab = self.a * self.b
        def go_next(result, i ,j):
            if ([i,j] in result) or (not 0<=i<=self.a-1) or (not 0<=j<=self.b-1) or ([i,j] == self.e and len(result) != (self.ab -1 -self.c)):
                return False
            try:
                if grid[i][j] == -1:
                    return False
            except:
                pass
            return True

        def add_ans(result, i, j):
            if (0 <= i <= self.a) and (0 <= j <= self.b):
                try:
                    if grid[i][j] == 2 and len(result) == (self.ab - self.c -1):
                        return True
                except IndexError:
                    pass
            return False
        def go(result, i, j):
            if add_ans(result,i,j):
                self.ans +=1
            else:
                for k in range(4):
                    if go_next(result,i,j):
                        result.append([i,j])
                        if k%2:
                            i1 = i
                            j1 = 2-k+j
                        else:
                            i1 = k-1+i
                            j1 = j
                        go(result,i1,j1)
            if len(result):
                result.pop()

        def preprocess(grid):
            j = 0
            a = []
            b = []
            for i in range(len(grid)):
                if -1 in grid[i]:
                    j += grid[i].count(-1)
                if 1 in grid[i]:
                    a.append(i)
                    a.append(grid[i].index(1))
                if 2 in grid[i]:
                    b.append(i)
                    b.append(grid[i].index(2))
            return (j,a,b)
        (self.c, self.d, self.e) = preprocess(grid)
        go([],self.d[0],self.d[1])
        return self.ans



def main():
    a = Solution()
    print(a.uniquePathsIII([[1,0,0,0],[0,0,0,0],[0,0,2,-1]]))

if __name__ == "__main__":
    main()
```
> 其实这些代码还都能优化，但我需要快点熟悉套路，没心思再搞优化了