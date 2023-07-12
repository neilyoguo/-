#include <iostream>
#include <string>

//抽象类cpu
class Cpu
{
public:
    virtual void show() = 0;
};

class Amd:public Cpu
{
public:
    virtual void show() override
    {
        std::cout << "create amd cpu" << std::endl;
    }
};

class Intel:public Cpu
{
public:
    virtual void show() override
    {
        std::cout << "create intel cpu" << std::endl;
    }
};
//抽象类显示器
class Monitor
{
public:
    virtual void show() = 0;    
};
class Samsung:public Monitor
{
public:
    virtual void show() override
    {
        std::cout << "create samsung" << std::endl;
    }
};

class Aoc:public Monitor
{
public:
    virtual void show() override
    {
        std::cout << "create Aoc" << std::endl;
    }
};
//抽象类工厂
class Factory 
{
public:
    virtual Monitor* createMonitor() = 0;
    virtual Cpu* createCpu() = 0;
};

class Factory1:public Factory
{
public:
    virtual Monitor* createMonitor() override
    {
        return new Samsung();
    }  
    virtual Cpu* createCpu() override
    {
        return new Amd();
    }  
};

class Factory2:public Factory
{
public:
    virtual Monitor* createMonitor() override
    {
        return new Aoc();
    }  
    virtual Cpu* createCpu() override
    {
        return new Intel();
    }  
};

int main()
{
    Factory * factory1 = new Factory1();
    Monitor * mor = factory1->createMonitor();
    Cpu * cpu = factory1->createCpu();
    mor->show();
    cpu->show();
    delete factory1;
    delete mor;
    delete cpu;
}