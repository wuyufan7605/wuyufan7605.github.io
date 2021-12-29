class Solution {
public:
    int numDecodings(string s) {
        if(s.length()==0){
            return 0;
        }
        m_ways[""]=1;
        return ways(s);
    }
//private只有同一個class才能用
private:
    int ways(const string&s){
        if(m_ways.count(s)) return m_ways[s];
        if(s[0]=='0') return 0;
        if(s.length()==1) return 1;
        
        //s.substr(1)表示index由1到最後,代表的的數字
        //扣除第一個數字,有幾種解法
        int w=ways(s.substr(1));
        //stoi是把字串轉成數字,轉的範圍從index0,包括index0的兩個數字
        const int prefix=stoi(s.substr(0,2));
        //如果前兩個數字有可能一起解碼時
        //就把"前面兩個數字去掉的解碼方法數"加進去原來的解碼方法數
        if (prefix<=26){
            w+=ways(s.substr(2));
        }
        //最終解碼方法數為w
        m_ways[s]=w;
        //回傳方法數
        return w;
    }
    //unordered_map為c++ STL中map裡面的容器
    //基本上用法跟map依樣,都是key/value之間的映射
    //只是他們內部採用的資料結構不一樣
    //使用unordered_map的話,比較適合針對高效率查詢的情況
    //如果不希望消耗記憶體,或資料要排序的話,用map
    unordered_map<string, int> m_ways;
};