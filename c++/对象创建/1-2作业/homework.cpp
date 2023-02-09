// 用时间类在栈区、静态区、堆区创建对象
#include <iostream>

using namespace std;

class Timer
{
private:
  int hour;
  int minutes;
  int seconds;

public:
  void setHour(int _hour)
  {
    hour = _hour;
  }

  void setMinutes(int _minutes)
  {
    minutes = _minutes;
  }

  void setSeconds(int _seconds)
  {
    seconds = _seconds;
  }

  void print()
  {
    cout << hour << ":" << minutes << ":" << seconds << endl;
  }
};

Timer static_time; // 静态区域

int main(int argc, const char *argv[])
{
  Timer stack_time; // 栈区域
  stack_time.setHour(11);
  stack_time.setMinutes(11);
  stack_time.setSeconds(11);
  stack_time.print();

  Timer *heap_time;
  heap_time = new Timer;

  heap_time->setHour(11);
  heap_time->setMinutes(11);
  heap_time->setSeconds(11);
  heap_time->print();
}
