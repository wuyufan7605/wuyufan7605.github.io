class Solution:
    def simplifyPath(self, path: str) -> str:
        res=[]
        #把最後的/去掉,並以/為區隔,區分每一個字
        for x in path.rstrip('/').split('/'):
            #如果遇到.或空格,就繼續
            if x=="." or x=="":
                continue
            #如果遇到.. ,就看res的長度
            #res長度>0表示前面有東西
            #把前面的東西pop(拿出來)掉
            elif x=="..":
                if len(res)>0:
                    res.pop()
            #把要的append(推進去)
            else:
                res.append(x)
        #'/'.join(res)表示在回傳的字中,以/區隔
        #然後最前面要一個/
        return '/'+'/'.join(res)