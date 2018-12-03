#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "time_measurement.h"

int main()
{
    Time_measurement test;
    
    start_time_measurement(&test);
    printf("test time mesurement");
    end_time_measurement(&test);

    printf_time_measurement(&test);

    return 0;
}
