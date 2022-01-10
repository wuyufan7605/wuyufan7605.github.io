class Solution {
public:
    int countPoints(string rings) {
        //n為rings長度的一半
        //因為字母跟數字各占一半
        int n=rings.size()/2;
        //建三個vector 分三個顏色
        //長度為10 表示0~9的竿子
        vector<bool> Red(10,false);
        vector<bool> Green(10,false);
        vector<bool> Blue(10,false);
        //count代表有幾個竿子:三個顏色的環都有
        //預設為0
        int count=0;
        //代表竿子的號數(0~9)
        int RingRoll;
        
        for(int i=0;i<2*n;i++){
            //把rings中的數字由字串轉為整數
            RingRoll=rings[i+1]-'0';
            //如果出現紅色的環
            //把Red vector 中對應的index 設為true
            if(rings[i]=='R'){
                Red[RingRoll]=true;
            }
            //如果出現綠色的環
            //把Green vector 中對應的index 設為true
            if(rings[i]=='G'){
                Green[RingRoll]=true;
            }
            //如果出現藍色的環
            //把Blue vector 中對應的index 設為true
            if(rings[i]=='B'){
                Blue[RingRoll]=true;
            }
        }
        //看0~9的竿子 誰三個顏色都有
        for(int i=0;i<10;i++){
            if(Red[i]&&Green[i]&&Blue[i]){
                count++;
            }
        }
        //回傳有幾個竿子符合條件
        return count;
    }
};