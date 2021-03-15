
/*In this code, I wrote different kind of Searching and Sorting Algorithms. 
  Also here, I used "User Define Function" for good understanding about 
  this source code. And everyone can easily understand this code and also 
  clear there most of the Algorithm's doubt.
  
  Marzan Islam
  7th Semester
  Computer Science & Engineering
  Dhaka International University
*/

#include<stdio.h>
int main()
{
    printf("\n\t\tWelcome to Algorithm's World.\n\n");
    printf("\t      --------------------------------\n\n");
    printf(" Press 1 for Searching Algorithm.\n");
    printf(" Press 2 for Sorting Algorithm.\n\n");
    int choice;

    printf(" Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        int searching, length, item, i;
        printf("\n Press 1 for Linear Search.\n");
        printf(" Press 2 for Binary Search.\n");

        printf("\n Enter your choice: ");
        scanf("%d", &searching);

        printf("\n How many numbers do you want: ");
        scanf("%d", &length);
        int array[length];
        printf(" Enter %d your numbers: \n", length);

        for (i = 0; i < length; i++)
        {
            printf(" Index[%d", i);
            printf("] = ");
            scanf("%d", &array[i]);
        }

        printf("\n Enter the number you want to search: ");
        scanf("%d", &item);

        switch(searching)
        {
        case 1:
            linearSearch(array, length, item);
            break;

        case 2:
            binarySearch(array, length, item);
            break;

        default:
            printf(" Please press the correct input.\n");
        }
    }

    else if(choice == 2)
    {
        int sorting, length, i, max = 0;
        printf("\n Press 1 for Bubble Sort.");
        printf("\n Press 2 for Insertion Sort.");
        printf("\n Press 3 for Selection Sort.");
        printf("\n Press 4 for Radix Sort.");
        printf("\n Press 5 for Quick Sort.");
        printf("\n Press 6 for Counting Sort.");

        printf("\n\n Enter your choice: ");
        scanf("%d", &sorting);

        printf("\n How many numbers do you want: ");
        scanf("%d", &length);
        int array[length];
        printf(" Enter %d your numbers: \n", length);

        for (i = 0; i < length; i++)
        {
            printf(" Index[%d", i);
            printf("] = ");
            scanf("%d", &array[i]);
            if(array[i] > max)
                max = array[i];
        }

        switch (sorting)
        {
        case 1:
            bubbleSort(array, length);
            break;

        case 2:
            insertionSort(array, length);
            break;

        case 3:
            selectionSort(array, length);
            break;

        case 4:
            radixSort(array, length);
            printf ("ascending order: ");
            for (i = 0; i < length; i++)
                printf ("%d ", array[i]);
            printf ("\n");
            break;

        case 5:
            quicksort(array, 0, length - 1);
            printf("ascending order: ");
            for(i = 0; i < length; i++)
                printf("%d ", array[i]);
            printf("\n");
            break;

        case 6:
            countingSort(array, length, max);
            break;

        default:
            printf(" Please choose the correct option.\n");
        }
    }
    else
    {
        printf(" Please choose the correct option");
    }

    printf("\n Are you want to go home page?\n");
    printf(" 1. Yes\n");
    printf(" 2. No\n");
    printf(" Please enter your choice: ");
    scanf("%d", & choice);

    if(choice==1)
    {
        system("cls");
        main();
    }
    return 0;
}


void linearSearch(int array[], int length, int searchItem)
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (array[i] == searchItem)
        {
            printf(" %d is found at index %d.\n", searchItem, i);
            break;
        }
    }
    if (i == length)
        printf(" %d isn't found \n", searchItem);
}


void binarySearch(int array[], int length, int searchItem)
{
    int low = 0, high = length - 1;
    int mid = low + (high - low) / 2;
    while (low <= high)
    {
        if (array[mid] < searchItem)
            low = mid + 1;
        else if (array[mid] == searchItem)
        {
            printf(" %d is found at index %d.\n", searchItem, mid);
            break;
        }
        else
            high = mid - 1;
        mid = (low + high) / 2;
    }
    if(low > high)
        printf(" %d isn't found\n", searchItem);
}


void bubbleSort(int array[], int length)
{
    int i, j, swap;
    for (i = 0; i < length - 1; i++)
    {
        for (j = 0; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap;
            }
        }
    }
    printf("ascending order: ");
    for (i = 0; i < length; i++)
        printf(" %d ", array[i]);
    printf("\n");
}


void insertionSort(int array[], int length)
{
    int i, j, temp;
    for (i = 1; i < length; i++)
    {
        temp = array[i];
        j = i - 1;
        while ((temp < array[j]) && (j >= 0))
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = temp;
    }
    printf(" ascending order: ");
    for(i = 0; i < length; i++)
        printf(" %d ",array[i]);
    printf("\n");
}


void selectionSort(int array[], int length)
{
    int i, j, temp;
    for (i = 0; i < length; i++)
    {
        for (j = i + 1; j < length; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printf(" ascending order: ");
    for(i = 0; i < length; i++)
        printf(" %d ",array[i]);
    printf("\n");
}


void quicksort(int array[],int first, int last)
{
    int i, j, pivot, temp;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(array[i]<=array[pivot]&&i<last)
                i++;
            while(array[j]>array[pivot])
                j--;
            if(i<j)
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
        temp=array[pivot];
        array[pivot]=array[j];
        array[j]=temp;
        quicksort(array,first,j-1);
        quicksort(array,j+1,last);
    }
}


void countingSort(int a[],int n,int max)
{
    int count[50]= {0},i,j;
    for(i=0; i<n; ++i)
        count[a[i]]=count[a[i]]+1;
    printf(" ascending order: ");
    for(i=0; i<=max; ++i)
        for(j=1; j<=count[i]; ++j)
            printf(" %d ",i);
    printf("\n");
}


void radixSort (int a[], int n)
{
    int bucket[10][10], bucket_cnt[10];
    int i, j, k, r, NOP = 0, divisor = 1, lar, pass, max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    lar = max;
    while (lar > 0)
    {
        NOP++;
        lar /= 10;
    }
    for (pass = 0; pass < NOP; pass++)
    {
        for (i = 0; i < 10; i++)
        {
            bucket_cnt[i] = 0;
        }
        for (i = 0; i < n; i++)
        {
            r = (a[i] / divisor) % 10;
            bucket[r][bucket_cnt[r]] = a[i];
            bucket_cnt[r] += 1;
        }
        i = 0;
        for (k = 0; k < 10; k++)
        {
            for (j = 0; j < bucket_cnt[k]; j++)
            {
                a[i] = bucket[k][j];
                i++;
            }
        }
        divisor *= 10;
    }
}


