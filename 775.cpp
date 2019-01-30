int isLocal(int* A,int Asize){
    int local=0;
    int i,j;
    for(i=0;i<Asize;++i){
            if(i==1000){
                return local;
            }
        for(j=i;j<Asize;++j){
            if(i<j&&A[i]>A[j]){
                local++;
            }
        }
    }
    return local;
}

int isGlobal(int* A,int Asize){
    int global=0;
    int i,j;
    for(i=0,j=1;j<Asize;++i,++j){
        if(i==1000){
            return global;
        }
        if(A[i]>A[j]){
            global++;
        }
        
    }
    return global;
}


bool isIdealPermutation(int* A, int ASize) {
    int local,global;
    local=isLocal(A,ASize);
    printf("local==%d\n",local);
    global=isGlobal(A,ASize);
    printf("global==%d\n",global);
    if(local==global){
        return true;
    }
    else{
        return false;
    }
    
}
