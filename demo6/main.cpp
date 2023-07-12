#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Student
{
public:
    Student(std::string name):m_name(name){}
    void update(std::string action)
    {
        std::cout<< m_name << "收到消息:" << action << std::endl;
        if(action == "老师来了")
            std::cout<< m_name << "假装学习" << std::endl;
        if(action == "老师走了")
            std::cout<< m_name << "开始睡觉" <<std::endl;
    }
private:
    std::string m_name;
};

class Teacher
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
    Student st1("小明");
    Student st2("小红");
    Teacher t;
    t.AddObserver(&st1);
    t.AddObserver(&st2);
    t.SetAction("老师来了");
    t.SetAction("老师走了");
    t.DelObserver(&st1);
    t.SetAction("老师来了");
}