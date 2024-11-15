#include<stdio.h>
int main()
{
int a[5]={4,2,6,5,8};
int n=5;
for(int i=0; i<n-1; i++)
{ int flag=0;
  for (int j=0 ; j<n-i-1 ; j++)
{
if(a[j]>a[j+1])
{
int temp = a[j];
a[j]=a[j+1];
a[j+1]=temp;
flag =1;
}

}
if(flag==0)
{
    break;
}
}
for(int k=0 ; k<5 ; k++)
{
    printf("%d", a[k]);
    
}


}
