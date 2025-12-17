#include<stdio.h>
// ham kiem tra so hoan hao
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
int main (){
	in
}