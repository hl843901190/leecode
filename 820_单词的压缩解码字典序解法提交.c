int wordcmp(const void *a, const void * b) {
    //return (strlen(*(const char**)b) - strlen(*(const char**)a));
    return strcmp(*(const char**)a, *(const char**)b);
}

void wordswap(char *word){
    int i = 0;
    char temp = 0;
    int len = strlen(word);
    
    for(i = 0; i < (len+1)/2; i++) {
        temp = word[i];
        word[i] = word[len - i -1];
        word[len - i -1] = temp;
    }
    return;
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
    
    /* first swap */
    for (i = 0; i < wordsSize; i++) {
        
        wordswap(words[i]);
        totallen += strlen(words[i]);
	}

	totallen += wordsSize ;
    //printf("totallen = %u\n", totallen);
    
    /* sort to dictionary */
    qsort(words, wordsSize, sizeof(char *), wordcmp);

    /* whether left in right*/
    for (i = 0; i < wordsSize - 1; i++) {
        if (strncmp(words[i], words[i+1], strlen(words[i])) == 0) {
            totallen -= (strlen(words[i]) + 1);u
        }

    }

    //printf("final:%u", totallen);


    return totallen;
    
}