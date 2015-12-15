/*======================================================
    > File Name: heapSort.c
    > Author: panlu
    > E-mail:  
    > Other :  
    > Created Time: 2015年12月15日 星期二 21时51分18秒
 =======================================================*/

#include<stdio.h>
#define Lchild(i)  (2*i+1)
#define Rchild(i)  (2*i+2)

void swap(int *i,int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

void heapLittle(int *array,int length,int current_node){             //只是进行小根堆的初始化,current_node是当前数字的下标
    int l_child = Lchild(current_node);
    int r_child = Rchild(current_node);
    int min = current_node;
    if(array[current_node] > array[l_child] && l_child < length){
       swap(array+current_node,array+l_child);
       min = l_child;
    }
    if(array[current_node] > array[r_child] && r_child < length){
        swap(array+current_node,array+r_child);
        min = r_child;
    }
    if(min!=current_node){　　　　　　　　　　　　　　　　　　
       // swap(array+current_node,array+min);
        heapLittle(array,length,l_child);　　　　　　　　　　//左孩子和右孩子都需要进行深度载建堆
        heapLittle(array,length,r_child);
    }
}

void initHeap(int *array,int length){                                 //将数组改造成堆
    int i = length/2-1;
    for(; i >= 0; i--){
        heapLittle(array,length,i);
    }
}

void heapSort(int *array,int length){               //堆排序的方法，取数组第一个元素再将最后一个补上去，然后再次进行堆的初始化
    int cur = length-1;
    array[0] = array[cur];
    initHeap(array,cur);
} 

int main(){
    int length;
    int i = 0;
    int array[20];
    printf("请输入数组的长度: ");
    scanf("%d",&length);
    printf("请输入数组的值: \n");
    for(; i < length; i++){
        scanf("%d",array+i);
    }
    initHeap(array,length);
    
    for(i =0 ; i< length; i++){
        printf("%d ",array[i]);
    }

    printf("\n-------aftersort-------");
    printf("\n");
    for(i = length; i > 0; i--){
        printf("%d ",array[0]);
        heapSort(array,i);
    }
}
