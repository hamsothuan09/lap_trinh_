#include <stdio.h>

int main() {
    int n, sum = 0;

    scanf("%d", &n);

    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    if (sum == n && n > 0) {
        printf("SO HOAN HAO");
    } else {
        printf("KHONG PHAI SO HOAN HAO");
    }

    return 0;
}
//for (int i = 1; i <= n/2; i++) => Ước của n không bao giờ lớn hơn n/2 (trừ chính n)
//if (n % i == 0) =>  i là ước của n
//if (sum == n) => Tổng ước bằng chính nó → số hoàn hảo
//  sum += i; => sau mỗi vòng lặp thì sum sẽ cộng dồn cho các ước của n tới khi sum = n  
        