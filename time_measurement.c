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
      startClock = clock();               // ���ϻ����cpu���ּ���
    }

void end_time_mesurment(Time_measurement* const p_this){
      p_this -> end
      gettimeofday(&endTime, NULL);       // ���ϻ������
      endClock = clock();                 // ���ϻ����cpu���ּ�
    }

void printf_time_measurement(Time_measurement* const p_this){

      time_t diffsec = difftime(p_this -> endTime.tv_sec, p_this -> startTime.tv_sec);    // �ÿ��κ�ʬ��׻�
      suseconds_t diffsub = p_this->endTime.tv_usec - p_this -> startTime.tv_usec;      // �ޥ���������ʬ�κ�ʬ��׻�
      //�ʲ��ν���������(15/10/28)
      //if (diffsub < 0) {                                              // �ޥ������ä���ˤʤä��Ȥ�
      //    diffsec -= 1;                                               // ����ʬ�򷫤겼��
      //    diffsub = 1000000 + diffsub;                                // 1�äȤκ�
      //}
      double realsec = diffsec+diffsub*1e-6;                          // �»��֤�׻�
      double cpusec = (p_this -> endClock - p_this -> startClock)/(double)CLOCKS_PER_SEC; // cpu���֤�׻�
    
      double percent = 100.0*cpusec/realsec;                          // ����Ψ��100ʬΨ�Ƿ׻�
      printf("CPU utilization: %f %%\n", percent);                      // ɽ��
    }
