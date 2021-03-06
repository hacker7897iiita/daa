# include <stdio.h>
# include <stdlib.h>
# include <time.h>



void hybridSort(int *,int);

int main()
{
  int *arr,n;
  srand((unsigned int)time(NULL));
  scanf("%d",&n);
  arr = (int *)malloc(n*sizeof(int));
  hybridSort(arr,n);
  return 0;
}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    int j;
    for ( j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void bubbleSort(int arr[], int s,int e)
{
   int i, j,k;
   k=0;
   for (i = s; i < e-1; i++)      
 
       // Last i elements are already in place   
       for (j = 0; j < e-k-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
	k++;
}
 
void quickSort(int arr[],int k, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
	if(high-low >=k){
        int pi = partition(arr, low, high);
	quickSort(arr,k, low, pi - 1);
	quickSort(arr,k, pi + 1, high);
	}
	else{
//bubblesort																																																																																																																																																																
	bubbleSort(arr,low, high);
	return;
	}
    }
	
}	
void sort(int *arr, int k,int n)
{
	 int i,step,temp;
	 quickSort(arr, k,0, n-1);
}	
void hybridSort(int *arr, int n)
{
	int i;
	int k=5;	
	clock_t begin,end;	
	for(i=0;i<n;i++)
		arr[i] = rand()%1000;
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	begin = clock();
	sort(arr, k, n);
	end = clock();
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("%d,%Lf",k,(long double)end-begin);
}
  /* write your program here.....
     use the following block of code to find out the time of running a particular routine
     clock_t begin,end;



     begin = clock();
     
     perform your computation here

     end = clock();

     time required will be end-begin


     For random input use the following code

     arr[i] = rand();


     output should be printed in the following way for each k.

     printf("%d,%d",k,end-begin);

  */
     



