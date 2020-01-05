/* 509. fibonacci ,简单递归暴力解法*/
/* 时间复杂度= 子问题数 * 解决子问题需要的时间，O(2^N)*/
int fib(int N){
    if (N < 1) {
        return 0;
    }

    if (N == 0) {
        return 0;
    } else if (N == 1) {
        return 1;
    } else {
        return fib(N - 1) + fib(N -2);
    }

}