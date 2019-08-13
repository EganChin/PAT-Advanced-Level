//
// Created by Administrator on 2019/8/12.
//

//2019.8.12 16:33 reading
//2019.8.12 16:38 read

/**
 *
Sample Input 1:
169 5 2
Sample Output 1:
169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2
Sample Input 2:
169 167 3
Sample Output 2:
Impossible
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n, k, p, maxFac = -1;
//fac方便高速计算
vector<int> fac, temp, ans;

void initFac() {
    for (int i = 1, f = 0; f <= n; i++) {
        fac.push_back(f);
        f = (int) pow(i, p);
    }

}

void dfs(int index, int nowK, int sum, int sumFac) {
    if (nowK == k && sum == n) {
        if (sumFac > maxFac) {
            ans = temp;
            maxFac = sumFac;
        }
        return;
    }
    if (nowK > k || sum > n) return;
    if (index - 1 >= 0) {
        temp.push_back(index);
        //选中当前因子
        dfs(index, nowK+1, sum + fac[index], sumFac + index);
        //将当前因子从临时分支移除
        temp.pop_back();
        //不选当前因子，尝试下一个因子
        dfs(index - 1, nowK, sum, sumFac);
    }
}

int main() {

    scanf("%d%d%d", &n, &k, &p);
    initFac();
    dfs(fac.size()-1, 0, 0, 0);
    if(maxFac == -1) printf("Impossible\n");
    else{
        printf("%d = %d^%d", n, ans[0], p);
        for(int i=1; i<ans.size(); i++)
            printf(" + %d^%d", ans[i], p);
    }
}