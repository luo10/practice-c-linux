// 编写一个类描述时间对象，可以设置小时、分钟、秒，也可以输出设置的时间
#include <iostream>

using namespace std;

class timer
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

int main(int argc, const char *argv[])
{
  timer time;
  time.setHour(11);
  time.setMinutes(11);
  time.setSeconds(11);
  time.print();
}
