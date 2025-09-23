#ifndef __HAJIMINAMEILUDUO_ARRAYLIST__ // 非常奇怪的名字，越怪越好以防和别人重复
#define __HAJIMINAMEILUDUO_ARRAYLIST__ #include<iostream>

class ArrayList
{
private:
    int size = 0;
    double *data = nullptr;

public:
    ArrayList() {}; // 默认构造函数
    ArrayList(int _maxSize)
    {
        size = _maxSize;
        data = new double[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = 0.0;
        }
    };
    ArrayList(const ArrayList &other) // 拷贝构造函数
    {
        size = other.size;
        data = new double[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }
    ~ArrayList() // 析构函数，比free()更安全，更聪明、更体面的自杀
    {
        if (data != nullptr)
        {
            delete[] data;
        }
    }
    void insert(double _val, int _pos);
    void printList();
};
#else
// DO NOTHING
#endif