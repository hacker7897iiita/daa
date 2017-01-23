// k-ary Max-Heap
# include <stdio.h>
# include <stdlib.h>

void build_MAX_heap(int *,int, int);
void swap(int *,int *);
void max_heapify(int *,int ,int ,int );
void display(int *,int );
int check_MAX_heap(int *,int,int);
void insert(int *,int,int,int);
int extract_MAX(int *,int, int);
void change(int *,int,int,int,int);

int main()
{
  char ch=' ';
  int *arr,n,k,i,new;
  scanf("%d",&k);
  scanf("%d",&n); /* To have anything non-trivial, n should be >2*n*k*/
  arr = (int *)malloc(2*n*sizeof(int));
  for(i=0;i<n;i++)
    {
      scanf("%d",&arr[i]);
    }
	 if(!check_MAX_heap(arr,n,k)){
		printf("\nbuilding max_heapify\n");	    
		build_MAX_heap(arr,n,k);
		display(arr,n);
	}
	do
    {
      while(getchar()!='\n'); /* To clear the buffer of any leftover characters*/
      ch=getchar();
      switch(ch)
	{
	case 'i':
	  scanf("%d",&new);
	  insert(arr,n,k,new);
	  n++;
	  display(arr,n);
	  break;
	case 'd':
	  printf("%d",extract_MAX(arr,n,k));
	  n--;
	  display(arr,n);
	  break;
	case 'c':
	  scanf("%d",&i);
	  scanf("%d",&new);
	  change(arr,n,k,i,new);
	  display(arr,n);
	  break;
	}
    }while(ch!='q');
  return 0;
}
void swap(int *a,int *b){
	int k;
	k=*a;
	*a=*b;
	*b=k;	
}
void display(int arr[],int n){
	printf("\n");
	int i;
	for(i=0;i<n;i++){
		printf(" %d",arr[i]);
	}
}
void max_heapify(int arr[],int n,int i,int k){
	int j,largest,c[k+1],m;	
	largest = i;
	for(j=1;j<=k;j++){
			if(k*i+j>=n)
				break;
			else				
				c[j] = k*i+j;
		}
	m=1;
	while(m<j){
		if(arr[largest] < arr[c[m]])
			largest = c[m];
		m++;
	}		
	if(largest!=i){
		swap(&arr[largest],&arr[i]);
		max_heapify(arr,n,largest,k);
	}	
} 
void build_MAX_heap(int arr[],int n,int k)
{
  /* This function shuffle the elements of arr till it is a k-ary MAX-heap*/
	int i;	
	for(i=n/k-1;i>=0;i--){
		max_heapify(arr,n,i,k);
	}	
}
int extract_MAX(int arr[],int n,int k)
{
  /* This function extracts the maximum element of a k-ary MAX-heap and returns it*/
	int dum;
	dum = arr[n-1];
	arr[0]=arr[n-1];
	max_heapify(arr,n,0,k);
	return dum;
}
void insert(int arr[],int n,int k,int new){
	arr[n]=new;
	build_MAX_heap(arr,n+1,k);
}
void change(int arr[],int n,int k,int i,int new)
{
  /* This function changes the value of arr[i]= new and makes arr a k-ary max-heap*/
	arr[i]=new;
	build_MAX_heap(arr,n,k);
}
int check_MAX_heap(int arr[],int n,int k)
{
  /* The function returns 0 if arr is NOT a k-ary MAX-heap.*/
	int i,c,m,largest,j;	
	c=1;
	for(i=n/k-1;i>=0;i--)
	{
		largest = i;
		for(j=1;j<=k;j++){
			m=k*i+j;
			if(m>=n){
				break;
			}
			if(arr[largest]<arr[m]){
				c=0;
				break;	
			}
		}
		if(c==0)
			break;
	}
	return c;
}


