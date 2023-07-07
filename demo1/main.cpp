#include <iostream>
#include <string>
#include <thread>
#include <mutex>
class Singleton
{
public:

    Singleton(Singleton &other) = delete;
    void operator=(const Singleton &) = delete;

    static Singleton * getInstance(const std::string& value)
    {
        m_mutex.lock();
        if(singleton == nullptr)
        {
            singleton = new Singleton(value);
        }
        m_mutex.unlock();
        return singleton;
    }
    void getValue()
    {
        std::cout << m_val << std::endl;
    }
private:
    Singleton(const std:: string & value)
    {
        m_val = value;
    }
    static Singleton * singleton;
    static std::mutex m_mutex;
    std::string m_val;
};

Singleton *Singleton::singleton = nullptr;
std::mutex Singleton::m_mutex;

void fun1()
{
    for(int t = 0; t < 10; t ++)
    {
        Singleton *singleton = Singleton::getInstance("banana");
        singleton->getValue();
    }

}
void fun2()
{
    for(int t = 0; t < 10; t ++)
    {
        Singleton *singleton = Singleton::getInstance("orange");
        singleton->getValue();
    }
}
void fun3()
{
    for(int t = 0; t < 10; t ++)
    {
        Singleton *singleton = Singleton::getInstance("apple");
        singleton->getValue();
    }
}
int main()
{
    std::thread t1(fun1);
    std::thread t2(fun2);
    std::thread t3(fun3);
    t1.join();
    t2.join();
    t3.join();
}