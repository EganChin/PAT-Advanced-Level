/*
1067 Sort with Swap(0, i) （25 分）
Given any permutation of the numbers {0, 1, 2,..., N−1}, it is easy to sort them in increasing order.

But what if Swap(0, *) is the ONLY operation that is allowed to use?

For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:

Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}

Now you are asked to find the minimum number of swaps

need to sort the given permutation of the first N nonnegative integers.

Input Specification:
Each input file contains one test case, which gives a positive N (≤10^5​​ )

followed by a permutation sequence of {0, 1, ..., N−1}. All the numbers in a line are separated by a space.

Output Specification:
For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

Sample Input:
10
3 5 7 2 6 4 9 0 8 1
Sample Output:
9
*/

// 2018.9.25
//20:40 reading
//20:47 read

#include<cstdio>

const int maxn = 100010;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int n, pos[maxn], stime = 0;   //存储各数的位置
    scanf("%d", &n);
    int unorder = n-1;  //除0外其他不在正确位置的数的个数
    for(int i=0; i<n; i++){
        int temp;
        scanf("%d", &temp);
        pos[temp] = i;
        if(temp && temp == pos[temp]){
            unorder--;
        }
    }

    int i=1;
    while(unorder){
        //如果零在本位，将其与一个无序数交换
        if(!pos[0]){
            while(i<n){
                if(pos[i] != i){
                    swap(pos[0], pos[i]);
                    stime++;
                    break;
                }
                i++;
            }
        }while(pos[0]){
            //否则将0所在位置的数的当前位置和0的当前位置交换
            swap(pos[0], pos[pos[0]]);
            stime++;
            unorder--;
        }

    }
    printf("%d\n", stime);
    return 0;
}

// 21:06 AC
