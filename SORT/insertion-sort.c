#include <stdio.h>

int main (void)
{
    int arr[10] = {0};
    for(int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for(int i = 1; i < 10; i++)
    {
        int key = arr[i];//要插入的元素
        int j = i-1;
        while(j >= 0 && arr[j]>key)//左边的大于右边的
        {
            arr[j+1] = arr[j];//右移
            j--;//调整指针位置
        }
        arr[j+1] = key;//把原来的key放到左边（这里j--后又+1的位置就是要放的，原来的arr[j]）
    }
    for(int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0;
}