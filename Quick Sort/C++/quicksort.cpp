#include <iostream>

int split(int a[],int start_index,int end_index){
int x=a[end_index];
int i=start_index-1;
for(int j=start_index;j<end_index;j++){
    if(a[j]<=x){
        i++;
      int temp=a[i];
      a[i]=a[j];
      a[j]=temp;//swap(a[i],a[j])
    }
}
int temp=a[i+1];
a[i+1]=a[end_index];
a[end_index]=temp;//swap(a[i+1],a[end_index])

return i+1;
}

void quicksort(int a[],int start_index,int end_index){
if(start_index<end_index){
    int mid_index=split(a,start_index,end_index);
                quicksort(a,start_index,mid_index-1);
                quicksort(a,mid_index+1,end_index);
}
}

int main()
{
  int arr[8]={2,8,7,1,3,5,6,4};
    quicksort(arr,0,7);
    for(int i=0;i<8;i++){
        std::cout<<arr[i]<<" ";
    }
    return 0;
}
