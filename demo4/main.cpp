#include <iostream>
#include <string>

//抽象类汽车
class Car
{
public:
    virtual void show() = 0;
};
//具体类奔驰
class Benz:public Car
{
public:
    virtual void show() override
    {
        std::cout << "create benz" << std::endl;
    }
};
//具体类宝马
class Bmw:public Car
{
public:
    virtual void show() override
    {
        std::cout << "create Bmw" << std::endl;
    }
};

//抽象类工厂
class Factory 
{
public:
    virtual Car* createCar() = 0;
};

class FactoryBenz:public Factory
{
public:
    virtual Car* createCar() override
    {
        return new Benz();
    }  
};

class FactoryBmw:public Factory
{
public:
    virtual Car* createCar() override
    {
        return new Bmw();
    }  
};

int main()
{
    Factory * fac_benz = new FactoryBenz();
    Car * car_benz = fac_benz->createCar();
    car_benz->show();
    Factory * fac_bmw = new FactoryBmw();
    Car * car_bmw = fac_bmw->createCar();
    car_bmw->show();
    delete fac_benz;
    delete fac_bmw;
    delete car_benz;
    delete car_bmw;
}