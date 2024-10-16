#include <stdio.h>
void largest(int array[],int s)
{
   int large=0,i;
   for(i=0;i<s;i++)
   {
   if(array[i]>large)
   {
       large=array[i];
   }
   }
   printf("Largest element in the array is: %d\n",large);
}
void smallest(int array[],int s)
{
      int small=0,i;
   for(i=0;i<s;i++)
   {
   if(array[i]<small)
   {
       small=array[i];
   }
   }
   printf("smallest element in the array is: %d\n",small);  
}
void insert(int array[],int n) 
{
    int pos,num,i;
    printf("Which position do you want to insert:");
    scanf("%d",&pos);
     printf("Enter element do you want to insert:");
    scanf("%d",&num);
    for(i=n-1;i>=pos-1;i--)
    {
      array[i+1]=array[i];
    }
    array[i+1]=num;
    printf("Modified Array is\n");
    for(int i=0;i<=n;i++)
    {
        printf("%d\t",array[i]);
    }
}
void delete(int array[],int n)
    {
      int i,pos;
      printf("\nWhich position do you want to delete:");
    scanf("%d",&pos);
    for(i=pos-1;i<n-1;i++)
    {
        array[i]=array[i+1];
    }
    printf("Modified Array is\n");
    for(int i=0;i<n-1 ;i++)
    {
        printf("%d\t",array[i]);
    }
    }
int main()
{
    int n;
  int array[20],i;
  printf("Enter numbers of elements in array:");
  scanf("%d",&n);
  printf("Enter elements of array:");
  for(i=0;i<n;i++)
  {
  scanf("%d",&array[i]);
  }
  while(i)
  {
    int a;
    printf("\nEnter 1 for find largest element\n");
    printf("Enter 2 for find smallest element\n");
    printf("Enter 3 for insert element into array\n");
    printf("Enter 4 for delete element from array\n");
    scanf("%d",&a);
    switch(a)
    {
        case 1:
  {
  largest(array,n);
  break;
  }
   case 2:
   {
  smallest(array,n);
  break;
   }
   case 3:
   {
  insert(array,n);
  break;
   }
   case 4:
   {
  delete(array,n);
  break;
    }
  }
}
}