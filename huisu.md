### 3��25-29 ���ݷ�

---
## ע�⣡

> ע�Ⱑ��д�κε����Ĵ��룬
> 
> ��һ����������Ҫ�����ĺ���������/���ܣ�
> 
> �ڶ����������Ҫ�����ĺ����ķ���ֵ��
> 
> ��������**���������ֵ����֪����д��һ�ε���**�߼���ȫOK�ˣ�


#### һ. ˼·��
> (1)���������ʽ������һ����ռ䣬��������������н⣬��һ����Ҫ��ȷ����Ľ�ռ�����
> 
> (2)����״̬�ռ�����
> 
> (3)����Լ������������ɱ���ڵ㣩��
> 
> Ȼ���Ҫͨ��DFS˼����ɻ��ݣ������������£�
> 
> (1)���ó�ʼ���ķ���������������ֵ��������֪���ݵȣ���
> 
> (2)�任��ʽȥ��̽����ȫ��������ת(7)��
> 
> (3)�жϴ˷��Ƿ�ɹ���ͨ��Լ�������������ɹ���ת(2)��
> 
> (4)��̽�ɹ���ǰ��һ������̽��
> 
> (5)��ȷ������δ�ҵ���ת(2)��
> 
> (6)���ҵ�һ�ַ������¼����ӡ��
> 
> (7)�˻�һ�������ݣ�����δ�˵�ͷ��ת(2)��
> 
> (8)���˵�ͷ��������ӡ�޽⡣

#### ��. �㷨���裺
***1*.�ڶ���д�㷨֮ǰҪ�����׵��£�**
- *�����ӽڵ�Ŀռ䷶Χ*
- *�ɴ˶�����״̬�����Ͳ�����������Щ*

***2*. ��ʼд�㷨������ĺ����ڲ��ṹ���£�**

```
self.ans #��ռ�
def go_next():      #Լ������
 
def add_ans():      #���������ʱ����self.ans������
 
def go(result,i,j):           #��������������Ϊ״̬�������������
                     #״̬����һ���ǿ��ܽ�Ŀǰ��״̬����һЩ������Ϣ������Լ�������жϡ�ǰ����result��ʾ
                     #��������һ����λ����Ϣ
    if add_ans():
        self.ans.append(copy.deepcopy(result))
    else:
        for i in range(len(�ӽڵ�ռ�)) #�����ӽڵ���ܵ�ֵ
            if go_next():               #����ӽڵ�������������ᱻ��֦
                ����״̬�������������
                ���У�״̬������Ҫ�Ը��£�����������Ҫ�Ը���
                ����״̬������result����Ҫдresult.append()�����ģ�ֱ��ȥ���±�������
                �����������������¼�������index��i,j�ȱ�������Ҫдi1 = i+1֮��ģ�Ȼ�󴫸���һ��go()������������
                go(result,i1,j1)
    #Ȼ��������Ҫϸ����for��������ʱ״̬�����ĸı䣬�Ƿ���Ҫ���ˣ�ans.append֮��״̬�����Ƿ���Ҫ���ˣ�֮������⡣�������Ҫ���ˣ�������д����Ȼ��д��if else���棬
    if len(result):
        result.pop()
go([],0,0)
return self.ans
```

---

�����Ǽ���leetcode���ݷ�����������д�Ľⷨ(û���Ż������Ƚ��ã����ǽṹ��������)�����������Ѷȵģ�

#### ��Ŀ1��
> ����һ�����ظ�����0���ֵ������һ��Ŀ�꣬��������������ϵĺ͵õ���Ŀ�꣨���ֲ�ͬ���˳����һ���⣩��

###### �ⷨ��
```
#coding:gbk
import copy

class Solution(object):
    def __init__(self):
        self.ans = []               #�����ռ�
    def he(self, nums, target):
        """
        :type board: List[int], targer: int
        :rtype: List[List[int]]
        """
        def go_next(now, node):     #����Լ������
            if sum(now)+node <= target:
                return True
            else:
                return False
        def go(nums1, list1):
            if sum(list1) == target:                    #�ɹ�����
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

#### ��Ŀ2��
> n �ʺ������о�������ν� n ���ʺ������ n��n �������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������������ͬ�У�����ͬ�У����ܻ���45�Ƚǵ�б�ߡ�
> 
> ʾ��:
> 
> ����: 4
> ���: [
>  [".Q..",  // �ⷨ 1
>   "...Q",
>   "Q...",
>   "..Q."],
> 
>  ["..Q.",  // �ⷨ 2
>   "Q...",
>   "...Q",
>   ".Q.."]
> ]
> ����: 4 �ʺ��������������ͬ�Ľⷨ��

###### �ⷨ��
```
#coding:gbk
import copy

class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        self.ans = []                                                                                           #�����ռ�
        def go_next1(row, col, next_node):                                                                      #Լ������
            for i in range(len(row)):
                if abs(row[i] - next_node[0]) == abs(col[i] - next_node[1]):
                    return True
            return False
        def go_next(row, col, next_node):
            if (next_node[0] in row) or (next_node[1] in col) or (go_next1(row,col,next_node)):                 #Լ������
                return False
            else:
                return True
        def go(row, col, result, i):                                                                            #go�ݹ麯��
            if len(result)==n:                                                                                  #д��ans����
                self.ans.append(copy.deepcopy(result))
                if len(result):                                                                                     #д��ans����ô�죺��������һ��״̬
                    result.pop()
                    row.pop()
                    col.pop()
            else:                                                                                               #��������д��ansʱ��
                for j in range(n):                                                                                  #������ռ����ӽڵ㣬Ѱ�ҿ��ܵ��ӽڵ�
                    if go_next(row,col,[i,j]):                                                                          #�жϸ��ӽڵ��Ƿ񱻼�֦
                        row.append(i)                                                                                       #����״̬����: row col result�ĸı�
                        col.append(j)
                        foo = ""
                        for k in range(n):
                            if k == j:
                                foo += "Q"
                            else:
                                foo += "."
                        result.append(foo)
                        go(row, col, result, i+1)                                                                           #��ʼ����������һ�㣬����״̬����row col result�����������i
                if len(result):                                                                                     #�����ò��ӽڵ��������������һ��״̬
                    result.pop()                                                                                    #����Ϊʲô������i��״̬�أ���Ϊi��״̬������û�б��ı䣡����û��дi += 1Ȼ�󴫽�ȥ
                    row.pop()                                                                                       #����ֱ�Ӱ�i+1��������һ�ε�go����ȥ�������������i��״̬
                    col.pop()                                                                                       #�����Ҿ�������д���ǲ��淶�ģ���Ӧ��дi += 1��Ȼ����˵�ʱ�������

        go([],[],[],0)                                                                                          #��ʼ״̬��
        return self.ans                                                                                        #����ans

def main():
    a = Solution()
    print(a.solveNQueens(4))

if __name__ == "__main__":
    main()
```

#### ��Ŀ3��
> ��9*9��������дһ������ͨ�������Ŀո�������������⡣
> 
> һ�������Ľⷨ����ѭ���¹���
> 
>     ���� 1-9 ��ÿһ��ֻ�ܳ���һ�Ρ�
>     ���� 1-9 ��ÿһ��ֻ�ܳ���һ�Ρ�
>     ���� 1-9 ��ÿһ���Դ�ʵ�߷ָ��� 3x3 ����ֻ�ܳ���һ�Ρ�
> 
> �հ׸��� '.' ��ʾ��
>
> Note:
> 
>     ��������������ֻ�������� 1-9 ���ַ� '.' ��
>     ����Լ������������ֻ��Ψһ�⡣
>     ����������Զ�� 9x9 ��ʽ�ġ�
> 

###### �ⷨ��

```
#coding:gbk
import copy

class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        self.ans = []                                                           #��ռ�

        def go_next(hmp, next_node):                                            #Լ������
            if ('r'+ str(next_node[1][0]+1)) in hmp[next_node[0]] or ('c'+ str(next_node[1][1]+1)) in hmp[next_node[0]] or ('s'+ str(next_node[1][2]+1)) in hmp[next_node[0]]:
                return False
            else:
                return True

        def go(hmp, result, j, k, l, t):                                        #��������������Ϊ״̬����hmp,result����������Ϊj,k,l,
            if j == 9 :                                                         #����㴦��ans���ж�
                self.ans.append(copy.deepcopy(result))                              #��ans
                return self.ans                                                     #����ans
            else:                                                               #���������ansʱ
                if board[j][k] != ".":                                              #���Ǹ�������ֵ���������ӽڵ㣬ά�������������������账��
                    if k == 8:
                        j1 = j + 1
                        k1 = 0
                    else:
                        j1 = j
                        k1 = k + 1
                    l1 = j1 / 3 * 3 + k1 / 3
                    go(hmp, result, j1, k1, l1, board[j][k])
                else:                                                               #���ǿ��Գ��ԵĲ㣬���1-9��Щ�ӽڵ㰤������
                    for i in xrange(1,10):                                              #�����ӽڵ�
                        if go_next(hmp, [i,[j,k,l]]):                                       #Լ��������֦�ж�
                            hmp[i].append('r' + str(j+1))                                       #ά��״̬����hmp,result����������j,k,l
                            hmp[i].append('c' + str(k+1))
                            hmp[i].append('s' + str(l+1))
                            result[j][k] = str(i)
                            if k == 8:
                                j1 = j+1
                                k1 = 0
                            else:
                                j1 = j
                                k1 = k+1
                            l1 = j1 / 3 * 3 + k1 / 3                                            #�����������һ��ʱҪ�ǵã�ǧ��Ҫֱ�Ӹ�״̬������Ȼ��ֱ�Ӵ���������Ҫj1=j+1��Ȼ��j1����Ȼ�������
                            go(hmp,result,j1,k1,l1,i)                                           #ά����������������һ��
                if k:                                                               #���ӽڵ��˻أ�˵����Ҫ����״̬�������ڴ�ά��״̬����hmp,result�Ͳ�������j,k,l
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


        def hmp_handle(input):                                                      #Ԥ����
            hmp1 = {1:[],2:[],3:[],4:[],5:[],6:[],7:[],8:[],9:[]}
            for i in xrange(9):
                for j in xrange(9):
                    if input[i][j] != ".":
                        hmp1[int(input[i][j])].append('r' + str(i+1))
                        hmp1[int(input[i][j])].append('c' + str(j+1))
                        hmp1[int(input[i][j])].append('s' + str(i/3*3 + j/3 + 1))
            return hmp1
        result_list = copy.deepcopy(board)
        go(hmp_handle(board),result_list,0,0,0,1)                                   #��ʼ����
        return self.ans                                                             #����ans

def main():
    a = Solution()
    print(a.solveSudoku([["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]))

if __name__ == "__main__":
    main()
```
#### ��Ŀ4��
> �ڶ�ά���� grid �ϣ��� 4 �����͵ķ���
> 
>     1 ��ʾ��ʼ������ֻ��һ����ʼ����
>     2 ��ʾ����������ֻ��һ����������
>     0 ��ʾ���ǿ����߹��Ŀշ���
>     -1 ��ʾ�����޷���Խ���ϰ���
> 
> �������ĸ������ϡ��¡����ң�������ʱ������ʼ���񵽽�������Ĳ�ͬ·������Ŀ��ÿһ�����ϰ�����Ҫͨ��һ�Ρ�
> ʾ�� 1��
> 
> ���룺[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
> �����2
> ���ͣ���������������·����
> 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
> 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
> 
> ʾ�� 2��
> 
> ���룺[[1,0,0,0],[0,0,0,0],[0,0,0,2]]
> �����4
> ���ͣ���������������·���� 
> 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
> 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
> 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
> 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

###### �ⷨ��

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
> ��ʵ��Щ���뻹�����Ż���������Ҫ�����Ϥ��·��û��˼�ٸ��Ż���