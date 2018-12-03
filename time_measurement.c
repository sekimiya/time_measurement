#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "time_measurement.h"

static void time_measurement_clear(Time_measurement* const p_this);

void Time_measurement(Time_measurement* const p_this)
{
    time_measurement_clear(p_this);
}

void start_time_mesurement(Time_measurement* const p_this){
      struct timeval startTimenow;
      p_this -> startTime = gettimeofday(&startTimenow, Null);
      startClock = clock();               // 開始時刻のcpu時間取得
    }

void end_time_mesurment(Time_measurement* const p_this){
      p_this -> end
      gettimeofday(&endTime, NULL);       // 開始時刻取得
      endClock = clock();                 // 開始時刻のcpu時間取
    }

void printf_time_measurement(Time_measurement* const p_this){

      time_t diffsec = difftime(p_this -> endTime.tv_sec, p_this -> startTime.tv_sec);    // 秒数の差分を計算
      suseconds_t diffsub = p_this->endTime.tv_usec - p_this -> startTime.tv_usec;      // マイクロ秒部分の差分を計算
      //以下の処理は不要(15/10/28)
      //if (diffsub < 0) {                                              // マイクロ秒が負になったとき
      //    diffsec -= 1;                                               // 秒部分を繰り下げ
      //    diffsub = 1000000 + diffsub;                                // 1秒との差
      //}
      double realsec = diffsec+diffsub*1e-6;                          // 実時間を計算
      double cpusec = (p_this -> endClock - p_this -> startClock)/(double)CLOCKS_PER_SEC; // cpu時間を計算
    
      double percent = 100.0*cpusec/realsec;                          // 使用率を100分率で計算
      printf("CPU utilization: %f %%\n", percent);                      // 表示
    }
