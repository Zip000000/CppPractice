#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("%d*%d=%d",i,i,i*i);
        for(int j=i+1;j<=n;j++)
        {
            printf("	%d*%d=%d",i,j,i*j);
        }
        printf("\n");
    }

    return 0;
}