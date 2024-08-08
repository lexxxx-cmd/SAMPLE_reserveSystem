#include "Manager.h"
#include "globalFile.h"
#include<fstream>
#include <algorithm>
Manager::Manager()
{

}
Manager::Manager(std::string name, std::string pwd) {
	this->mName = name;
	this->mPwd = pwd;

	this->initVector();

	std::ifstream ifs;
	ifs.open(COMPUTER_ROOM_FILE, std::ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.max_Num)
	{
		vCom.push_back(com);
	}
	ifs.close();
	std::cout << " 机房数量： " << vCom.size() << std::endl;
}
Manager::~Manager() {

}

void Manager::openMenu() {
	std::cout << "1添加账号2产看账号3查看机房4删除账号5清空预约其他注销登录" << std::endl;
}
void Manager::addAccount() {
	std::cout << "输入添加账号类型1学生2老师" << std::endl;
	std::string fileName;
	std::string tid;
	std::string errorTip;

	std::ofstream ofs;
	int select = 0;
	std::cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tid = "请输入学号";
		errorTip = "学号重复，重新输入";
	}
	else
	{
		fileName = TEACHER_FILE;
		tid = "请输入职工号";
		errorTip = "职工号重复，重新输入";
	}
	ofs.open(fileName, std::ios::out | std::ios::app);
	int id;
	std::string name;
	std::string pwd;

	std::cout << tid << std::endl;
	while (true)
	{
		
		std::cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			std::cout << errorTip << std::endl;
		}
		else
		{
			break;
		}
	}
	std::cout << "输入姓名" << std::endl;
	std::cin >> name;
	std::cout << "输入密码" << std::endl;
	std::cin >> pwd;

	ofs << id << " " << name << " " << pwd << std::endl;
	std::cout << "添加成功" << std::endl;
	system("pause");
	system("cls");
	ofs.close();

	this->initVector();

}
void printStudent(Student& s)
{
	std::cout << s.id << " " << s.mName << std::endl;
}
void printTeacher(Teacher& s)
{
	std::cout << s.empId << " " << s.mName << std::endl;
}
void Manager::checkAccount() {
	std::cout << "选择查看内容1学生2老师" << std::endl;

	int select = 0;
	std::cin >> select;
	if (select == 1)
	{
		for (auto n : this->vStu)
		{
			printStudent(n);
		}
	}
	else
	{
		for (auto n : this->vTea)
		{
			printTeacher(n);
		}
	}
	system("pause");
	system("cls");
}
void Manager::deleteAccount() {

}
void Manager::showComRoomInfo() {
	std::cout << "机房信息" << std::endl;
	for (auto n : vCom)
	{
		std::cout << n.m_ComId << " " << n.max_Num << std::endl;
	}
	system("pause");
	system("cls");
}
void Manager::clearFile() {
	std::ofstream ofs;
	ofs.open(ORDER_FILE, std::ios::trunc);
	ofs.close();
	system("pause");
	system("cls");
}
void Manager::initVector()
{
	vStu.clear();
	vTea.clear();
	std::ifstream ifs;
	ifs.open(STUDENT_FILE, std::ios::in);
	if (!ifs.is_open())
	{
		std::cout << "文件打开失败"<<std::endl;
		ifs.close();
		return;
	}
	Student s;
	while (ifs >> s.id && ifs >> s.mName && ifs >> s.mPwd)
	{
		vStu.push_back(s);
	}
	std::cout << "当前学生数量为： " << vStu.size() << std::endl;
	ifs.close();
	ifs.open(TEACHER_FILE, std::ios::in);
	if (!ifs.is_open())
	{
		std::cout << "文件打开失败" << std::endl;
		ifs.close();
		return;
	}
	Teacher t;
	while (ifs >> t.empId && ifs >> t.mName && ifs >> t.mPwd)
	{
		vTea.push_back(t);
	}
	std::cout << "当前老师数量为： " << vTea.size() << std::endl;
	ifs.close();
}
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (std::vector<Student>::iterator it = vStu.begin();it != vStu.end();it++)
		{
			if (id == it->id)
			{
				return true;
			}
		}
	}
	else
	{
		for (std::vector<Teacher>::iterator it = vTea.begin();it != vTea.end();it++)
		{
			if (id == it->empId)
			{
				return true;
			}
		}
	}
	return false;
}
