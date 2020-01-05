/* 509.斐波那契正向非递归 */
int fib(int N){
    int sum = 0;
    int prev = 0;
    int cur = 1;
    int i = 0;

    if (N < 1) {
        return 0;
    }

    if (N == 1 || N == 2) {
        return 1;
    }

    
    for (i =0; i < N - 1; i++) {
        sum = prev + cur;
        prev = cur;
        cur = sum;
    }
    return cur;
}