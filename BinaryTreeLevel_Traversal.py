#定義一個函式
def dfs(depth,root,result):
    #需要設定一個條件,來中止迴圈
    if root==None:
        return
    #印出  第幾層:數字(只是在寫程式時看有沒有寫對,測試用)
    #print(depth,":",root.val)

    #如果第幾層(depth)等於result的個數
    #result一開始設定為0,則新增一個空陣列(或是說list)
    if depth == len(result):
        result.append([])
    #把數字塞進:代表所在層數(depth)的陣列
    result[depth].append(root.val)
    #重複做左子樹及右子樹
    #先做左子樹,再做右子樹
    dfs(depth+1,root.left,result)
    dfs(depth+1,root.right,result)

class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        #一開始讓result為空陣列
        result=[]
        #使用上面的函式,把每一層的數字由左到右排出
        dfs(0,root,result)
        #由於上面是top-down(由上而下)的方式排列
        #所以用內建函式(reverse)來反轉成:由下而上(buttom-up)
        result.reverse()
        return result
        