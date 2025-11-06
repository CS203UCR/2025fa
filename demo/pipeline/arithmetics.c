#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "perfstats.h"
#include <stdint.h> 
int main(int argc, char **argv)
{
    uint64_t i,sum=0,*data,previous=0,size;
    register uint64_t multiplier=0;
    struct timeval time_start, time_end, program_start, program_end;

    if(argc > 1)
        size = (uint64_t)atoi(argv[1]);
    else
        size = 131072;
    data = (uint64_t *)malloc(sizeof(uint64_t)*size);
    
    for(i=0;i<size;i++)
        data[i]=rand()%8738;
    if(argc > 2)
        multiplier = (uint64_t)atoi(argv[1]);
    else
        multiplier = 13;
    gettimeofday(&time_start, NULL);
  perfstats_init();
  perfstats_enable();
#ifdef A
    for(i=0;i<size*1000;i++)
    {
        sum+=data[(i*multiplier) & 131071];
    }

#else

    for(i=0;i<size*1000;i++)
    {
        sum+=data[((i << 3) + (i << 2) + i) & 131071];
    }

#endif
//    sum+=data[((i << 3) + (i << 2) + i) & 131071];
//    sum+=data[(i*13) & 131071];
  perfstats_disable();
  perfstats_print();
  perfstats_deinit();
    gettimeofday(&time_end, NULL);
    printf(",%lu,%lf\n",sum,((time_end.tv_sec * 1000000 + time_end.tv_usec) - (time_start.tv_sec * 1000000 + time_start.tv_usec))/1000000.0);
//    printf("sum: %d %lf seconds\n",sum,((time_end.tv_sec * 1000000 + time_end.tv_usec) - (time_start.tv_sec * 1000000 + time_start.tv_usec))/1000000.0);
    return 0;
}
