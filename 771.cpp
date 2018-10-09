int numJewelsInStones(char* J, char* S) {
    int count=0;
    for(int i=0;J[i]!='\0';++i){
        for(int j=0;S[j]!='\0';++j){
            if(J[i]==S[j]){
                count++;
            }
        }
    }
    return count;
}
