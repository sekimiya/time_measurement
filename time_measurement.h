#include <stdio.h>
#include <time.h>
#include <sys/time.h>

typedef struct time_measurement{
    struct timeval startTime, endTime;
    clock_t startClock, endClock;       
}Time_measurement;


void start_time_measurement(Time_measurement* const p_this){
      struct timeval startTimenow; 
      gettimeofday(&startTimenow, NULL);
      //計測開始時刻取得
      p_this -> startTime = startTimenow;
      //CPU使用時間取得
      p_this -> startClock = clock();
}

void end_time_measurement(Time_measurement* const p_this){
    struct timeval endTimenow;
    gettimeofday(&endTimenow, NULL);
    p_this -> endTime = endTimenow;
    p_this -> endClock = clock();
}

void printf_time_measurement(Time_measurement* const p_this){

        // 秒数の差分を計算
        time_t diffsec = difftime(p_this -> endTime.tv_sec, p_this -> startTime.tv_sec);
        // ms秒部分差分計算 
        suseconds_t diffsub = p_this->endTime.tv_usec - p_this -> startTime.tv_usec;
        // 実時間計算
        double realsec = diffsec+diffsub*1e-6;                          
        //cpu時間を計算
        double cpusec = (p_this -> endClock - p_this -> startClock)/(double)CLOCKS_PER_SEC;
        
        double percent = 100.0*cpusec/realsec;                                printf("CPU utilization: %f %%\n", percent);    
        printf("real time : %f sec", realsec);
}
