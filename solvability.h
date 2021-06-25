int inv_count(int **puzzle , int N){

    int arr[N*N]; int p=0;

    for(int i=0;i<N;i++){

        for(int j=0;j<N;j++)
        arr[p++]=puzzle[i][j];
    }

    int count=0;

    for(int i=0;i<p-1;i++){

        for(int j=i+1;j<p;j++){

            if(arr[i]>0 && arr[j]>0 && arr[i]>arr[j])
            count++;
        }
    }

    return count;
}

int get_pos(int **puzzle, int N){

    for(int i=0;i<N;i++){

        for(int j=0;j<N;j++){

            if(puzzle[i][j]==0)
            return N-i;
        }
    }
}

bool isSolvable(int **puzzle, int N){

    if(N%2){

        if(inv_count(puzzle,N)%2==0)
        return true;

        return false;
    }
    else{

        int count=inv_count(puzzle,N);
        int pos=get_pos(puzzle,N);

        if(count%2 != pos%2)
        return true;

        return false;
    }
}