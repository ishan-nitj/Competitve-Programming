void pre(){
    ll i,j;
    C[0][0]=1;
    C[1][0]=1;C[1][1]=1;
    for(i=2;i<51;i++)
        for(j=0;j<51;j++){
            if(j==0)
                C[i][j]=1;
            if(i<j)continue;
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }  

}
