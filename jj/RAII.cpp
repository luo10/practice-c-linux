#include <iostream>
#include <string>
using namespace std;

// 假设这是一个会占用较大堆空间的类型
class Message
{
public:
  Message() : val{"这是一个非常长的字符串"}
  {
  }
  ~Message() {}
  void SendMessage()
  {
    cout << val << endl;
  }
  string val;
};

// 这个类型负责管理Message对象的释放工作
class MessageRAII
{
public:
  MessageRAII() : msgObj{new Message()} {};
  Message *get()
  {
    return msgObj;
  }
  ~MessageRAII()
  {
    delete msgObj;
  }
  Message *msgObj;
};

// 入口函数
int main()
{
  {
    MessageRAII msgRAIIobj;
    msgRAIIobj.get()->SendMessage();
  }
  auto c = getchar();
}
