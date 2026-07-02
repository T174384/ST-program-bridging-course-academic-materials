void read_records(student_t stu[]){
    FILE * indata;
    int i,j;
    indata=fopen("roster.txt","r");
    if(indata==NULL){
        printf("can't open");
        exit(1);
    }
    for(i=0;i<10;i++){
        fscanf(indata,"%s%d",stu[i].matric,&stu[i].num_mods);
        for(j=0;j<stu[i].num_mods;j++){
            fscanf(indata,"%d%s",&stu.credit[j],stu.grade[j]);
        }
    }
    fclose(indata);//不要忘了我求你了
}
double get_grade_point(char grade[]){
    int i;
    char grades[11][3]={"A+","A","A-","B+","B","B-","C+","C","D+","D","F"};
    double points[11]={5.0,5.0,4.5,4.0,3.5,3.0,2.5,2.0,1.5,1.0,0};
    for(i=0;i<11;i++){
        if(!strcmp(grade,grades[i])) return points[i];
    }
}
double cal_cap(student_t stu){
    double deno=0,nomi=0;
    int i;
    for(i=0;i<stu.num_mods;i++){
        nomi+=stu.credit[i]*get_grade_point(stu.grade[i]);
        deno+=stu.credit[i];
    }
    return nomi/deno;
}
double get_highest_cap(student_t stu[]){
    double maxx=0,i;
    for(i=0;i<10;i++){
        if(cal_cap(stu[i])>maxx) maxx=cal_cap(stu[i]);
    }
    return maxx;
}
void print_top_student(student_t stu[],double max_cap){
    int i;
    for(i=0;i<10;i++){
        if(cal_cap(stu[i])==max_cap){
            printf("%.2f %s\n",max_cap,stu[i].matric);
        }
    }
}