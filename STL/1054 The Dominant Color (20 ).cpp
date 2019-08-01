//
// Created by Administrator on 2019/7/29.
//

/**
 *
Behind the scenes in the computer's memory, color is always talked about as a series of 24 bits of information for each pixel. In an image, the color with the largest proportional area is called the dominant color. A strictly dominant color takes more than half of the total area. Now given an image of resolution M by N (for example, 800×600), you are supposed to point out the strictly dominant color.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive numbers: M (≤800) and N (≤600) which are the resolutions of the image. Then N lines follow, each contains M digital colors in the range [0,2
​24
​​ ). It is guaranteed that the strictly dominant color exists for each input image. All the numbers in a line are separated by a space.

Output Specification:
For each test case, simply print the dominant color in a line.

Sample Input:
5 3
0 0 255 16777215 24
24 24 0 0 24
24 0 24 24 24
Sample Output:
24
**/

//2019.8.1 15:53 reading
//2019.8.1 15:57 read

#include <stdio.h>
#include <map>
using namespace std;

int main(){

    int m, n;
    scanf("%d%d", &m, &n);

    map<int,int> image;

    for(int i=0; i<n; i++){
        for (int j = 0; j < m; ++j) {
            int x;
            scanf("%d", &x);
            image[x]++;
        }
    }

    int k=0,max = 0;
    for(auto it = image.begin(); it!=image.end(); it++){
        if(it->second > max){
            k = it->first;
            max = it->second;
        }
    }

    printf("%d\n", k);
    return 0;
}

//16:05 NC PAT AC