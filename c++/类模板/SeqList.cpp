#include <iostream>

using namespace std;

template <typename T, int size>

class SeqList
{
public:
  SeqList();
  void addData(const T &data)
  {
    if (index >= size)
    {
      cout << "The SeqList is full" << endl;
      return;
    }
    buf[index] = data;
    index++;
  }
  void show(void) const
  {
    for (int i = 0; i < index; i++)
    {
      cout << buf[i] << endl;
    }
  }

  ~SeqList()
  {
    if (buf)
    {
      delete[] buf;
    }
  }

private:
  T *buf;
  // int size;
  int index;
};

template <typename T, int size>
SeqList<T, size>::SeqList()
{
  if (size <= 0)
  {
    cout << "Invalid argument:" << size << endl;
    return;
  }

  buf = new T[size];
  this->index = 0;
}

int main(int argc, const char *argv[])
{
  SeqList<string, 3> list;
  list.addData("hello");
  list.addData("world");
  list.addData("123");
  list.addData("xyz");
  list.show();
  return 0;
}