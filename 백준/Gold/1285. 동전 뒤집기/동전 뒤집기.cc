#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int coin[22][22];
char tmp;
int main() {
    int n,j,cnt,ans=2147483647;
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++) {
        j = 1;
        while (1) {
            tmp = getchar();
            if (tmp == '\n')break;
            if (tmp == 'T') {//T가 위면 1 (뒷면) 인 값이 최소->ans가 최소
                coin[i][j] = 1;
            }
            else {
                coin[i][j] = 0;
            }
            j++;
        }
    }
    for (int i = 0; i < (1<<n); i++) {
        int tmparr[22][22] = { 0, };
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                tmparr[j][k] = coin[j][k];
            }
        }
        for (int j = 0; j < n; j++) {//몇번째줄 바꿀지?
            int p = pow(2, j);
            if ((p & i) != 0) {
                for (int k = 1; k <= n; k++) {
                    if (tmparr[j][k] == 0) {
                        tmparr[j][k] = 1;
                    }
                    else {
                        tmparr[j][k] = 0;
                    }
                }
            }
        }
        //for (int j = 1; j <= n; j++) {
        //    for (int k = 1; k <= n; k++) {
        //        printf("%d", tmparr[j][k]);
        //    }printf("\n");
        //}
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            int c_tmp1=0,c_tmp2=0;
            for (int k = 1; k <= n; k++) {
                if (tmparr[k][j] == 0) {
                    c_tmp1++;
                }
                else {
                    c_tmp2++;
                }
            }
    //        printf("c1 %d ][ c2 %d\n", c_tmp1, c_tmp2);
            cnt += min(c_tmp1, c_tmp2);
        }
  //      printf("ans %d ][ cnt %d\n", ans, cnt);
        ans = min(ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}//비트마스킹으로 구현 처음해보는듯..?
//구글링으로 참고많이함