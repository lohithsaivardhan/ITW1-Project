#include<stdio.h>
int main()
{

int a[5]={5,4,2,3,1};
int i , j, k, l;
for (i=0 ; i< 5 ; i++)
{
k=i;
for(j=i+1; j<5;j++ )
{
if(a[j]<a[k])
{
    k=j;
}

}
int temp =a[k];
a[k]=a[i];
a[i]=temp;
}
for( l=0 ; l< 5; l++)
{
    printf("%d", a[l]);
}

}
