int wordcmp(const void *a, const void * b) {
    return (strlen(*(const char**)b) - strlen(*(const char**)a));
}

int minimumLengthEncoding(char ** words, int wordsSize){
    char *pS_str = NULL;
    int *pA_int = NULL;
    char *endstr = "#";
    int i = 0, j = 0, k = 0, loop = 0;
    int ret = 0;
	int totallen = 0;
	int result = 0;
    int findsame = 0;
    int templen = 0;
    int tobecmplen = 0;
    int baselen = 0;
    char *test = 0;
    
    if ( words == NULL || wordsSize == 0) {
        return 0;
    }
    
    qsort(words, wordsSize, sizeof(char *), wordcmp);
    
    for (i = 0; i < wordsSize; i++) {
        totallen += strlen(words[i]);
	}

	totallen += (wordsSize + 1);
	pS_str = (char *)malloc(totallen);
    if (pS_str == NULL) {
        return -1;
    }
	
	memset(pS_str, 0, totallen);
    for (i = 0; i < wordsSize; i++) {
        tobecmplen = strlen(words[i]);
        findsame = 0;
        for (j = 0; j < wordsSize; j++) {
            baselen = strlen(words[j]);
            if(i == j || tobecmplen > baselen) {
                continue;
            }
            
            templen = baselen - tobecmplen;
            for (loop = templen, k = 0; loop < baselen; loop++, k++) {

                if (words[i][k] == words[j][loop]) {
                    continue;
                } else {
                    break;
                }
            }

            if (k == tobecmplen && loop == baselen) {
                findsame = 1;
                break;
            } else {
                continue;
            }
        }
        if (findsame != 1){
            strcat(pS_str, words[i]);
            strcat(pS_str, endstr);
        } else {
            test = strstr(pS_str, words[i]);
            if (test == NULL) {
                strcat(pS_str, words[i]);
                strcat(pS_str, endstr);
            } 
        }
    }

    printf("%u\n", strlen(pS_str));
	result = strlen(pS_str);

	if (pS_str) {
        free(pS_str);
    }
    
    return result;
    
}