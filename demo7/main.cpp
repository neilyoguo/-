#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Student
{
public:
    virtual void update(std::string action) = 0;
};
class Teacher
{
public:
    virtual void AddObserver(Student *st) = 0;
    virtual void DelObserver(Student *st) = 0;
    virtual void Notitf(std::string action) = 0;
};

class St1 : public Student
{
private:
    std::string m_name;
public:
    St1(std::string name):m_name(name){}
    virtual void update(std::string action ) override
    {
        std::cout<< m_name << "收到消息:" << action << std::endl;
        if(action == "校长来了")
            std::cout<< m_name << "假装学习" << std::endl;
        if(action == "校长走了")
            std::cout<< m_name << "开始睡觉" <<std::endl;
    }
};

class St2 : public Student
{
private:
    std::string m_name;
public:
    St2(std::string name):m_name(name){}
    virtual void update(std::string action ) override
    {
        std::cout<< m_name << "收到消息:" << action << std::endl;
        if(action == "校长来了")
            std::cout<< m_name << "假装学习" << std::endl;
        if(action == "校长走了")
            std::cout<< m_name << "开始听歌" <<std::endl;
    }
};
class Schoolmaster : public Teacher
{
public:
    void AddObserver(Student *st)
    {
        vec.push_back(st);
    }
    void DelObserver(Student *st)
    {
        auto it = std::find(vec.begin(), vec.end(), st);
        if (it != vec.end()) 
        {
            vec.erase(it);
        }
    }
    void Notitf(std::string action)
    {
        for(auto v : vec)
        {
            v->update(action);
        }
    }
    void SetAction(std::string action)
    {
        this->action = action;
        Notitf(action);
    }
private:
    std::string action;
    std::vector<Student *> vec;
};

int main()
{
    St1 st1("小明");
    St2 st2("小红");
    Schoolmaster t;
    t.AddObserver(&st1);
    t.AddObserver(&st2);
    t.SetAction("校长来了");
    t.SetAction("校长走了");
    t.DelObserver(&st1);
    t.SetAction("校长来了");
}