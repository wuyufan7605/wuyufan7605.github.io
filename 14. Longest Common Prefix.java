class Solution {
    public String longestCommonPrefix(String[] strs) {
        //如果字串為空,回傳""
        if(strs==null||strs.length==0) return"";
        String res=strs[0];
        //兩兩相比,把全部字串都比過
        for(int i=1;i<strs.length;i++){
            //表示在strs1中,找看看
            //看有沒有strs0
            //若沒有就把strs0減少最後一個字母
            //反覆直到str0與str1有一樣的為止
            while(strs[i].indexOf(res) != 0){
                res=res.substring(0,res.length()-1);
            }
        }
        return res;
    }
}