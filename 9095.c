#include<stdio.h>

int main()
{
    int T, num;
    int arr[12];
    scanf("%d",&T);
    
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    while(T--){
        scanf("%d",&num);
        if(num<=3) {
            printf("%d\n",arr[num]);
            continue;
        }
        else{
            for(int i=4;i<=num;i++){
                arr[i] = arr[i-2]+arr[i-1]+arr[i-3];
            }
            printf("%d\n",arr[num]);
        }
    }
    return 0;
}
