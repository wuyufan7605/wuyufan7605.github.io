#include<stdio.h>

int p[10];
//初始化 十個節點都指向自己,每個點都自己一團
void initialize(){
    for(int x=0;x<10;x++){
        p[x]=x;
    }
}
//找樹根
int find(int x){
    //當x不是樹根,就在往上找,直到找到樹根
    while(x!=p[x]){
        x=p[x];
    }
    return x;
}
void union(int x,int y){
    x=find(x); //找到x的parent
    p[x]=y;    //令x的parent指向y
}
