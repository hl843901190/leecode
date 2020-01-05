/* 509. fibonacci ,带备忘录的递归*/
/* 时间复杂度= 子问题数 * 解决子问题需要的时间，O(N)*/

int dparray[1000] = {0};
int fib(int N){
    if (N < 1) {
        return 0;
    }

    if (N == 1 || N == 2) {
        return 1;
    } 

    if (dparray[N] != 0) {
        return dparray[N];
    } 
    
    dparray[N] = fib(N - 1) + fib(N - 2);
    return dparray[N];
}