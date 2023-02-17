#include <iostream>
#include <random>
#include <string>
using namespace std;
// 消息父类。用于描述所有消息都具备的共同特征
class Message
{
public:
  Message() : MessageId{createMessageId()} {}
  const int MessageId;
  virtual void SendMessage() {}

private:
  int createMessageId()
  { // 生成消息ID
    random_device dev;
    return dev();
  }
};

// 文本消息子类
class TextMessage : public Message
{
public:
  TextMessage() : Message() {}
  void SendMessage() override
  {                                                               // 重写父类消息
    cout << "发送文本消息：" << MessageId << ":" << Text << endl; // MessageId来自父类
  }
  string Text;
};

// 文件消息子类
class FileMessage : public Message
{
public:
  FileMessage() : Message() {}
  void SendMessage() override
  {                                                                   // 重写父类消息
    cout << "发送文件消息：" << MessageId << ":" << FilePath << endl; // MessageId来自父类
  }
  string FilePath;
};

// 通用消息处理方法
void Send(Message &msg)
{
  msg.SendMessage();
}

// 入口函数
int main()
{
  {
    TextMessage txtMsg;
    txtMsg.Text = "明天下午又个会";
    Send(txtMsg); // 传递引用 输出：发送文本消息：1286241589:明天下午又个会
  }
  {
    FileMessage fileMsg;
    fileMsg.FilePath = "c://hello.png";
    Send(fileMsg); // 传递引用 输出：发送文件消息：860319378:c://hello.png
  }
  auto c = getchar();
}