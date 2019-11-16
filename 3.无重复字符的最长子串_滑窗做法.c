int lengthOfLongestSubstring(char * s){
    char tmp = 0;
    int array[256] = {0};
    int i = 0;
    int len = 0;
    int startidx = 0;
    int totallen = 0;
    int maxlen = 0;
    
    if (s == NULL) {
        return 0;
    }
    
    memset(array, -1, sizeof(array));
    totallen = strlen(s);
    printf("s=%s, totalen=%u\n", s, totallen);
    while ((tmp = s[i]) != '\0') {
        printf("s[%u]=%c, array[%u]=%d, startidx=%u\n", i, s[i], s[i], array[s[i]], startidx);
        if (array[tmp] >= startidx) { // 在当前正在比较的字符串内找到了相同的字符,右移并刷新开始index
            len = i - startidx;
            maxlen = (maxlen > len) ? maxlen : len;
            startidx = array[tmp] + 1; 
            printf("startidx=%u, s[%u]=%c, maxlen=%u, len=%u\n", startidx, i, s[i], maxlen, len);
        }            
        array[s[i]] = i;
        i++;
    }
    
    
    len = i - startidx;
    maxlen = (maxlen > len) ? maxlen : len;
    printf("finall:startidx=%u, i=%u, maxlen=%u, len=%u\n", startidx, i, maxlen, len);
    
    return maxlen;

}