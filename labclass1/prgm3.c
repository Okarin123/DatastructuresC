#include<stdio.h> 

void insort(int a[10], int n)
	{
	int last, to_be_sorted, pos, i, j, k; 

	for (int i=0; i<n-1; i++)
		{
		last=i; 
		to_be_sorted=a[i+1];

		for (j=i+1; j<n-1; j++)
			a[j]=a[j+1];
		
		for (j=0; j<=last; j++)
			if (to_be_sorted<=a[j])
				break; 

		pos=j; 

		for (k=n-2; k>=pos; k--)
			a[k+1]=a[k];

		a[pos]=to_be_sorted;
		}
	}

void shellsort(int arr[10], int num)
	{
	int gap, j, k, tmp;

	for (gap= num/2; gap>0; gap/=2)
        	for (j = gap; j< num; j++)
        		for(k = j-gap; k >= 0; k-=gap)
            			{
                		if (arr[k+gap] >= arr[k])
                    			break;
                
				else
               				{
                    			tmp = arr[k];
                    			arr[k] = arr[k+gap];
                    			arr[k+gap] = tmp;
                			}
            			}
        
    	}

void main()
	{
	int a[10], n, i, ch; 

	printf("\nEnter the size: ");
	scanf("%d", &n); 

	for (i=0; i<n; i++)
		{
		printf("\nEnter element: ");		
		scanf("%d", &a[i]);	
		}

	printf("\nEnter choice: 1. Shell sort   2. Insertion sort- ");
	scanf("%d", &ch); 

	switch (ch)
		{	
		case 1:
			shellsort(a,n);
			break;

		case 2:
			insort(a,n);
			break;

		default:
			printf("\nEnter valid choice!");
		}

	printf("\nArray after sorting: \n");
	
	for (i=0; i<n; i++)
		printf("%d\n", a[i]);
	}
