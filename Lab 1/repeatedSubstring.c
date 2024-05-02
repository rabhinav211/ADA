char* substring(char *s, int start, int end) {
    char *res = (char*)malloc((end - start + 1) * sizeof(char));
    int j = 0;

    for (int i = start; i < end; i++)
        res[j++] = s[i];
    res[j] = '\0';
    return res;
}

bool repeatedSubstringPattern(char* s) {
    int len = strlen(s);

    for (int i = 1; i < len; i++) {
        if (len % i == 0) {
            int fac = 0;
            char *s1 = substring(s, 0, i);
            char *s2;
            printf("i:%d\tlen:%d\n",i,len);
            int flag;
            do {
                s2 = substring(s, fac, fac + i);
                fac += i;
                flag=strcmp(s1, s2);
            } while ( flag==0 && fac + i <= len);
            free(s1); 
            free(s2);
            if (fac == len && flag==0)
                return true;
        }
    }

    return false;
}
