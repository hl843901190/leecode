3/无重复字符的最长自串
1)bbbbbbbb
2)aab
int findChar(char *basestr, char *needlechr) {
    int i = 0;
    int totallen = 0;
    
    if (basestr[0] == '\0' || needlechr == NULL) {
        return 0;
    }
    totallen = strlen(basestr);
    for (i = 0; i < totallen; i++) {
        if (basestr[i] == needlechr) {
            return 1;
        }
    }
    
    return 0;
}
int lengthOfLongestSubstring(char * s){
    int i = 0;
    int pos = 0;
    int lastlen = 0, temlen = 0;
    int totallen = 0;
    char *temstr = NULL;
    
    if (s == NULL) {
        return 0;
    }
    
    totallen = strlen(s);
    //printf("s=%s, len=%u \n", s, totallen);
    temstr = (char *)malloc(totallen);
    memset(temstr, 0, totallen);
    
    for(pos = 0; pos < totallen; pos++) {
        temlen = 0;
        memset(temstr, 0, totallen);
        for (i = pos; i < totallen; i++) {
            //printf("temstr=%s,s[%u]=%c, temlen=%u, pos=%u \n", temstr, i, s[i], temlen, pos);
            if (findChar(temstr, s[i]) != 0) { // find
                //printf("find \n");
                break;
            } else {
                temstr[temlen] = s[i];        
                temlen++;
                //printf("not find \n");
            }
        }
        
        //printf("pos=%u, i=%u, lastlen=%u, temlen=%u, temstr=%s \n", pos, i, lastlen, temlen, temstr);
        lastlen = (lastlen > temlen) ? lastlen : temlen;
        //pos += i;
        //printf("i=%u, pos = %u \n", i, pos);
    }
    
    //printf("final:lastlen=%u, temstr=%s \n", lastlen, temstr);
    return lastlen;
    
}