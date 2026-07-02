#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_PARKING_UNIT 9000
#define LENGTH_OF_CAR 8
#define MAX_NUM_ROUND 10000
int road[MAX_PARKING_UNIT];
int main()
{
    srand((unsigned)time(NULL));
    for(int round=0;round<MAX_NUM_ROUND;round++)
    {
        int x=rand()%MAX_PARKING_UNIT;
        int found=0;
        for(int i=x;i<=MAX_PARKING_UNIT-LENGTH_OF_CAR;i++)
        {
            int ok=1;
            for(int j=i;j<i+LENGTH_OF_CAR;j++)
            {
                if(road[j])
                {
                    ok=0;
                    break;
                }
            }
            if(ok)
            {
                for(int j=i;j<i+LENGTH_OF_CAR;j++)
                {
                    road[j]=1;
                }

                found=1;
                break;
            }
        }
    }
    int occupied=0;
    for(int i=0;i<MAX_PARKING_UNIT;i++)
    {
        if(road[i])
        {
            occupied++;
        }
    }
    double rate=(double)occupied*100.0/MAX_PARKING_UNIT;
    printf("Occupied Units = %d\n",occupied);
    printf("Utilization Rate = %.2f%%\n",rate);
    return 0;
}