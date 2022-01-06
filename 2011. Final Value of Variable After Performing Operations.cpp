class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        //x一開始為0
        int x=0;
        for(int i=0;i<operations.size();i++){
            //如果是X++或++X,x就加一
            if(operations[i]=="X++" || operations[i]=="++X"){
                x++;
            }
            //反之則減一
            if(operations[i]=="X--" || operations[i]=="--X"){
                x--;
            }
        }
        //回傳x
        return x;
    }
};