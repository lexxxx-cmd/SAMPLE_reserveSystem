#pragma once
#include "Identity.h"
class Teacher :
    public Identity
{
public:
    int empId;

    Teacher();
    Teacher(int empId, std::string name, std::string pwd);
    ~Teacher();

    virtual void openMenu();
    void showAllOrder();
    void validOrder();

};

