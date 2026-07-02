//A 
int pins_felled(long game){
    int sum=0;
    while(game){
        sum+=game%10;
        game/=10;
    }
    return sum;
}

//B
int consec_strikes(long game){
    int maxx=0,j=0;
    while(game){
        int s=game%10;
        if(s==9) j++;
        else j=0;
        if(j>maxx) maxx=j;
        game/=10;
    }
    return maxx;
}

//C
int score(long game){
    int pv=0,sum=0;
    while(game){
        int s=game%10;
        game/=10;
        if(s==9) sum+=pv;
        sum+=s;
        pv=s;
    }
    return sum;
}