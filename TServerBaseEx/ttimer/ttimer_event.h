/******************************************
 * Copyright 2016/05 - 2021/07 
 * file	  :
 * author : tianyiheng
 * date   : $time$
 * brief  :
 *******************************************/

#ifndef __TYH_SERVER_BASE_TTIMER_TIMER_EVENT_H__
#define __TYH_SERVER_BASE_TTIMER_TIMER_EVENT_H__

#include <ctime>

namespace tyh {

class TTimerEvent {
public:
  TTimerEvent();
  ~TTimerEvent();

protected:
  time_t event_time_;
  int run_times_;
};


}  // namespace tyh


#endif  // __TYH_SERVER_BASE_TTIMER_TIMER_EVENT_H__
