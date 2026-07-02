//A
bool can_merge(Range a,Range b){
    if(b.a<=a.b&&b.b>=a.a) return 1;
    return 0;
}

//B
Range merge(Range a, Range b){
    Range c;
    c.a=a.a<b.a?a.a:b.a;
    c.b=a.b>b.b?a.b:b.b;
    return c;
}

//C
typedef struct{
    int left;
    int right;
}Range;

void add(Range r, Range s[], int n){
    int i = 0;
    /* 找到第一个可能与 r 相交的位置 */
    while(i < n && s[i].right < r.left) i++;
    int start = i;
    /* 合并所有相交区间 */
    while(i < n && can_merge(s[i], r)){
        r = merge(r, s[i]);
        i++;
    }
    /* start~i-1 这些区间都被 r 吃掉了 */
    s[start] = r;
    /* 后面的区间整体前移 */
    int j = start + 1;
    while(i < n){
        s[j++] = s[i++];
    }
    print(s);      // 新长度
}