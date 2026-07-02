int secondMostNumOfCourses(int enrol[][MAX_STUDENTS], int numClasses, int numStudents)
{
    int a[numStudents];
    int i,j;
    int max=-1;
    int second_max=-2;
    for(i=0;i<numStudents;i++)
    {
        a[i]=0;
        for(j=0;j<numClasses;j++)
        {
            a[i]+=enrol[j][i];
        }
        if(a[i]>max)
        {
            second_max=max;
            max=a[i];
        }
        else if(a[i]<max && a[i]>second_max)
        {
            second_max=a[i];
        }
    }
    return second_max;
}

void mostPopularNumOfCourses(int enrol[][MAX_STUDENTS], int numClasses, int numStudents)
{
    int a[numStudents];
    int b[numClasses+1];
    int i,j;
    int max=-1;
    for(i=0;i<=numClasses;i++)
    {
        b[i]=0;
    }
    for(i=0;i<numStudents;i++)
    {
        a[i]=0;
        for(j=0;j<numClasses;j++)
        {
            a[i]+=enrol[j][i];
        }
        b[a[i]]++;
    }
    for(i=0;i<=numClasses;i++)
    {
        if(b[i]>max)
        {
            max=b[i];
        }
    }
    for(i=0;i<=numClasses;i++)
    {
        if(b[i]==max)
        {
            printf("%d ",i);
        }
    }
}