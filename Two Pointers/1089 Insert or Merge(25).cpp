/*
1089 Insert or Merge （25 分）
According to Wikipedia:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.

Merge sort works as follows: Divide the unsorted list into N sublists, each containing 1 element (a list of 1 element is considered sorted). Then repeatedly merge two adjacent sublists to produce new sorted sublists until there is only 1 sublist remaining.

Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in the first line either "Insertion Sort" or "Merge Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resuling sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0
Sample Input 2:
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
Sample Output 2:
Merge Sort
1 2 3 8 4 5 7 9 0 6
*/

//20190224 10:13 reading
//20190224 10:22 read

//思路：先尝试使用插入排序，每一趟都比较是否与目标序列相同，如果不存在相同序列，则一定是归并排序

#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define max 110
int target[max], n;

bool same(int a[]){
    for(int i=0; i<n; i++)
        if(target[i] != a[i])
            return false;
    return true;
}

void print(int a[]){
    for(int i=0; i<n; i++){
        printf("%d", a[i]);
        if(i<n-1)
            printf(" ");
    }
    printf("\n");
}

//非递归的归并排序方法
void mergeSort(int a[]){
    int flag = 0;
    for(int step = 2; step/2<=n; step*=2){
        if(step != 2 && same(a))
            flag = 1;
        for(int i=0; i<n; i+=step)
            sort(a+i, a+min(i+step, n));
        //print(a);
        if(flag == 1)
            return;

    }
}

bool isInsertSort(int a[]){
    int flag = 0;
    for(int i=1; i<n; i++){
        if(i!=1 && same(a))
            flag = 1;
        int temp = a[i], j = i;
        while(j>0 && temp<a[j-1]){
            a[j] = a[j-1];
            j--;
        }

        a[j] = temp;
        //print(a);
        if(flag == 1)
            return true;

   }
   return false;
}

int main()
{
    scanf("%d", &n);
    int insert[n], merge[n];
    for(int i=0; i<n; i++){
        scanf("%d", &insert[i]);
        merge[i] = insert[i];
    }
    for(int i=0; i<n; i++)
        scanf("%d", &target[i]);

    if(isInsertSort(insert)){
        printf("Insertion Sort\n");
        print(insert);
    }else{
        mergeSort(merge);
        printf("Merge Sort\n");
        print(merge);
    }

    return 0;
}

/*
end 11:52
*/

/*
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
*/
