class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //排序小孩及餅乾的vector
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        //小孩及餅乾的index
        int child=0;
        int cookie=0;

        while(child<g.size()&&cookie<s.size()){
            //如果小孩要的餅乾數負擔得起
            if(g[child]<=s[cookie]){
                //要到餅乾的小孩數加一
                child++;
            }
            //目前的餅乾數不適和,換下一個
            cookie++;
        }
        return child;
    }
};