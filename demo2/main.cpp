#include <iostream>
#include <string>
class Key
{
public:
    virtual Key * clone() = 0;
    virtual void show() = 0; 
};

class CarKey:public Key
{
public:
    CarKey(std::string name):car_name(name){}
    CarKey(const CarKey& other)
    {
        this->car_name = other.car_name;
    }
public:
    Key *clone() override
    {
        return new CarKey(*this);
    }
    void show() override
    {
        std::cout << car_name << std::endl;
    }
private:
    std::string car_name;
};

int main()
{
    Key * bmw_key = new CarKey("bmw");
    //复制3把bmw 钥匙
    Key *bmw = bmw_key->clone();;
    bmw->show();
    Key *bmw2 = bmw_key->clone();;
    bmw2->show();
    Key *bmw3 = bmw_key->clone();;
    bmw3->show();


    Key * benz_key = new CarKey("benz");
    //复制1把benz钥匙
    Key *benz = benz_key->clone();
    benz->show();
    delete bmw;
    delete bmw2;
    delete bmw3;
    delete benz;
    delete bmw_key;
    delete benz_key;

}