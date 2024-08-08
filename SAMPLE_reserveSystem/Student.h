#pragma once
#include "Identity.h"
#include "ComputerRoom.h"
#include <vector>
class Student :
    public Identity
{
public:
    int id;
    std::vector<ComputerRoom> vCom;

    Student();
    Student(int id,std::string name,std::string pwd);
    ~Student();

    virtual void openMenu();
    void applyOrder();
    void showMyOrder();
    void showAllOrder();
    void cancelOrder();

};

