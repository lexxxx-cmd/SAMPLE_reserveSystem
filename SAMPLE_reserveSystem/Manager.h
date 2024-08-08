#pragma once
#include "Identity.h"
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include "ComputerRoom.h"
class Manager :
    public Identity
{
public:
    Manager();
    Manager(std::string name,std::string pwd);
    ~Manager();

    virtual void openMenu();
    void addAccount();
    void checkAccount();
    void deleteAccount();
    void showComRoomInfo();
    void clearFile();

    void initVector();
    std::vector<Student>vStu;
    std::vector<Teacher>vTea;
    bool checkRepeat(int id,int type);

    std::vector<ComputerRoom>vCom;

};

