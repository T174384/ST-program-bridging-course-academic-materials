int valid_Sudoku(int arr[][9]){
    int i,j,k,l;
    // 错误：原来没初始化，里面是随机值
    int st1[10][10]={0};
    int st2[10][10]={0};
    // 检查行和列
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            st1[i][arr[i][j]]++;
            st2[i][arr[j][i]]++;
        }
        for(j=1;j<=9;j++){
            if(st1[i][j]!=1 || st2[i][j]!=1)
                return 0;
        }
    }
    // 检查3×3宫格
    for(i=0;i<=6;i+=3){
        // 错误：
        // 你写的是 j++
        // 会把(0,1)、(0,2)也当成宫格左上角
        // 应该每次跳3格
        for(j=0;j<=6;j+=3){
            // 错误：原来没初始化
            int st[10]={0};
            for(k=i;k<=i+2;k++){
                for(l=j;l<=j+2;l++){
                    // 错误：
                    // 你写的是
                    // st[arr[i][j]]++;
                    // 用成了宫格左上角元素
                    // 应该统计当前遍历到的位置
                    st[arr[k][l]]++;
                }
            }
            for(k=1;k<=9;k++){
                if(st[k]!=1)
                    return 0;
            }
        }
    }
    return 1;
}