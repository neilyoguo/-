#include <iostream>
#include <string>
#include <map>

std::map<std::string, int> m_car{
    {"Benz", 1},
    {"Bmw", 2}
};

class Car
{
public:
    virtual void show() = 0;
};

class Benz:public Car
{
public:
    virtual void show() override
    {
        std::cout << "create benz" << std::endl;
    }
};
class Bmw:public Car
{
public:
    virtual void show() override
    {
        std::cout << "create Bmw" << std::endl;
    }
};


class Factory
{
public:
    static Car* creat_car(std::string name)
    {
        auto iter = m_car.find(name);
        if(iter != m_car.end())
        {
            switch(iter->second)
            {
                case 1:
                    return new Benz();
                case 2:
                    return new Bmw();
                default:
                    return nullptr; 
            }
        }
        else
        {
            return nullptr;
        } 
    }
};
int main()
{
    std::string car_name = "Bmw";
    Car* car = Factory::creat_car(car_name);
    car->show();
    delete car;
}