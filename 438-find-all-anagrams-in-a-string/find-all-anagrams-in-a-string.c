/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char* s, char* p, int* returnSize) {
    int* result = malloc(strlen(s) * sizeof(int));
    *returnSize = 0;
    
    int pLen = strlen(p), sLen = strlen(s);
    if(pLen > sLen) return result;
    
    int pCount[26] = {0}, sCount[26] = {0};
    
    // Initial window
    for(int i = 0; i < pLen; i++) {
        pCount[p[i]-'a']++;
        sCount[s[i]-'a']++;
    }
    
    // Check first window
    int match = 1;
    for(int i = 0; i < 26; i++) {
        if(pCount[i] != sCount[i]) { match = 0; break; }
    }
    if(match) result[(*returnSize)++] = 0;
    
    // Slide window
    for(int i = pLen; i < sLen; i++) {
        sCount[s[i-pLen]-'a']--;
        sCount[s[i]-'a']++;
        
        match = 1;
        for(int j = 0; j < 26; j++) {
            if(pCount[j] != sCount[j]) { match = 0; break; }
        }
        if(match) result[(*returnSize)++] = i - pLen + 1;
    }
    
    return result;   
}