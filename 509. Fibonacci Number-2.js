//A,B都是矩陣
//這個函式表示兩個矩陣相乘的結果
function multiply(A,B){
    let c00= A[0][0] * B[0][0] +A[0][1] *B[1][0];
    let c01= A[0][0] * B[0][1] +A[0][1] *B[1][1];
    let c10= A[1][0] * B[0][0] +A[1][1] *B[1][0];
    let c11= A[1][0] * B[0][1] +A[1][1] *B[1][1];
    let c=[
        [c00,c01],
        [c10,c11]
    ]
    return c
}
//A為矩陣: 1  1
//        1  0
let A=[
        [1,1],
        [1,0],
    ]
//算A矩陣^(n/2)
//再平方即為所求
function pow_of_A(n){
    //如果n=1,就直接回傳
    if (n==1){return A}
    //從n=2開始算
    //如果n=2k(偶數)
    if(n%2==0){
        let Ak=pow_of_A(n/2)
        return multiply(Ak,Ak)
    }
    //如果n是奇數
    //2*k+1=n
    //所以k=(n-1)/2
    let Ak=pow_of_A((n-1)/2)
    return multiply(multiply(A, Ak), Ak)
}
//求費式數列
//求矩陣的左上角的值
function fib(n) {
    if(n<=1){return n}
    return pow_of_A(n-1)[0][0]
};