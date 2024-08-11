#include <iostream>
#include <fstream>
#include "Identity.h"
#include "globalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
//管理员子菜单
void managerMenu(Identity* &manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->openMenu();
		//将父类指针转为子类指针以调用子类的接口
		Manager* man = (Manager*)manager;
		int select = 0;
		std::cin >> select;
		switch (select)
		{
		case 1:
			man->addAccount();
			break;
		case 2:
			man->checkAccount();
			break;
		case 3:
			man->showComRoomInfo();
			break;
		case 4:
			man->deleteAccount();
			break;
		case 5:
			man->clearFile();
			break;
		default:
			delete manager;
			system("pause");
			system("cls");
			return;
			break;
		}
	}
}
void studenMenu(Identity*& student)
{
	while (true)
	{
		student->openMenu();
		Student* stu = (Student*)student;
		int select = 0;
		std::cin >> select;
		switch (select)
		{
		case 1:
			stu->applyOrder();
			break;
		case 2:
			stu->showMyOrder();
			break;
		case 3:
			stu->showAllOrder();
			break;
		case 4:
			stu->cancelOrder();
			break;
		default:
			delete student;
			system("pause");
			system("cls");
			return;
			break;
		}
		
	}
}
void teachermenu(Identity*& teacher)
{
	while (true)
	{
		teacher->openMenu();
		Teacher* stu = (Teacher*)teacher;
		int select = 0;
		std::cin >> select;
		switch (select)
		{
		case 1:
			stu->showAllOrder();
			break;
		case 2:
			stu->validOrder();
			break;

		default:
			delete teacher;
			system("pause");
			system("cls");
			return;
			break;
		}

	}
}
void loginIn(std::string filename, int type)
{
	Identity* person = NULL;

	std::ifstream ifs;
	ifs.open(filename, std::ios::in);
	if (!ifs.is_open())
	{
		std::cout << "文件不存在。" << std::endl;
		ifs.close();
		return;
	}
	//准备用户接受
	int id=0;
	std::string name;
	std::string pwd;
	if (type == 1)
	{
		std::cout << "输入学号" <<std::endl;
		std::cin >> id;
	}
	else if (type == 2)
	{
		std::cout << "输入职工号" << std::endl;
		std::cin >> id;
	}
	std::cout << "输入用户名" << std::endl;
	std::cin >> name;
	std::cout << "输入密码" << std::endl;
	std::cin >> pwd;

	//验证是否存在
	if (type == 1)
	{
		//验证学生
		int fId;
		std::string fName;
		std::string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//与用户输入对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				std::cout << "验证成功" << std::endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生子菜单'
				studenMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//验证教师
		int fId;
		std::string fName;
		std::string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//与用户输入对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				std::cout << "验证成功" << std::endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入老师子菜单'

				return;
			}
		}
	}
	else if (type == 3)
	{
		//验证管理

		std::string fName;
		std::string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			//与用户输入对比
			if (fName == name && fPwd == pwd)
			{
				std::cout << "验证成功" << std::endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员子菜单'
				managerMenu(person);
				return;
			}
		}
	}
	std::cout << "验证登录失败" << std::endl;
	system("pause");
	system("cls");
	return;
}
void test()
{
	int select = 0;
	while (true)
	{
		std::cout << "1、学生"
			<< "2、老师"
			<< "3、管理员"
			<< "0、退出"
			<< std::endl;
		std::cin >> select;
		switch (select)
		{
		case 1:
			loginIn(STUDENT_FILE, 1);
			break;
		case 2:
			loginIn(TEACHER_FILE, 2);
			break;
		case 3:
			loginIn(ADMIN_FILE, 3);
			break;
		case 0:
			std::cout << "欢迎下次使用！" << std :: endl;
			system("pause");
			return;
			break;
		default:
			std::cout << "重新选择" << std::endl;
			system("pause");
			system("cls");
			break;
		}

	}
}

int main()
{
	test();
	system("pause");
	return 0;
}