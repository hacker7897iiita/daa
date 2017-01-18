# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void hybridSort(int *,int);
void quicksort(int *,int ,int ,int );
int partition(int *,int ,int );

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
	fp=fopen("rajq.dat","w+");
	int a,b,c,d,e,f,k,end,begin,res[n],t;
	t=n;
	for(a=1;a<=100;a++){

	        begin = clock();     
		for(b=0;b<n;b++){
			arr[b]=t;
			t++;
			
		}
		d=0;
		e=n-1;
		quicksort(arr,d,e,a);
        	end = clock();
		c=end-begin;
		res[a-1]=c;
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

void quicksort(int arr[],int low,int high,int k)
{
	int pi,a,b,c,d;
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
  	        	pi = partition(arr,low,high);
			quicksort(arr,low,pi - 1,k);
    	        	quicksort(arr,pi + 1,high,k);
    		}
	}
}

int partition (int arr[],int low,int high)
{

	int pivot,j,i,a;
	pivot = arr[high];  
        i = (low - 1);
	for (j = low; j <= high- 1; j++)
        {
	        if (arr[j] <= pivot)
	        {
    	            	i++;
    	               	a=arr[i];
		 	arr[i]=arr[j];
			arr[j]=a;
       	        }
        }
	a=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=a;
	return (i + 1);

}
