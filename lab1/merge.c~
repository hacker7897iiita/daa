# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void hybridSort(int *,int);
void mergesort(int *,int ,int ,int );
void merge(int *,int ,int ,int );

int main()
{
  int *arr,n;
  srand((unsigned int)time(NULL));
  scanf("%d",&n);
  arr = (int *)malloc(n*sizeof(int));
  hybridSort(arr,n);
  return 0;
}


void hybridSort(int *arr, int n)
{
	FILE *fp;
	fp=fopen("d.dat","w+");
	int a,b,c,d,e,f,k,end,begin,res[n],t,i;
	t=0;
	for(a=1;a<=100;a++){
	        begin = clock();   
		if(0){  
		for(b=0;b<n;b++){
			arr[b]=rand();
		}
		}
		if(1){
		for(i=0;i<n/2;i++)
		{
			arr[i]=rand();
		} 
		for(b=i;b<n;b++){
			arr[b]=t;
			t++;
			
		}
		}
		if(0){
			t=n;
			for(b=0;b<n;b++){
			arr[b]=t;
			t--;
			}	
		}
		if(0){
			for(b=0;b<n;b++){
			arr[b]=t;
			t++;
			
		}
		}
		d=0;
		e=n-1;
		mergesort(arr,d,e,a);
        	end = clock();
		c=end-begin;
		res[a-1]=c;
		printf("%d %d\n",a,end-begin);
		fprintf(fp,"%d %d\n",a,end-begin);

	}
        a=res[0];
	c=0;
	for(b=1;b<100;b++){

		if(res[b]<a){

			c=b;
			a=res[b];

		}

	}
	printf("\nvalue of k for which time is min. is %d\n",c+1);  

}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int high, int low,int k)
{
	int a,b,c,d,e,f,m;
    if (low < high)
    {

	a=high-low+1;
	if(a<=k){
	for(b=low;b<high-1;b++)
		for(c=low;c<high-1;c++){
			if(arr[c]>arr[c+1]){
				d=arr[c+1];
				arr[c+1]=arr[c];
				arr[c]=d;
			}
		}
	}
	else{
		int m = low+(high-low)/2;
       		mergesort(arr, low, m,k);
        	mergesort(arr, m+1, high,k);
     		merge(arr, low, m, high);
	}        
    }
}


