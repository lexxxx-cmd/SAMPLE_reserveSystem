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
	std::cout << " ���������� " << vCom.size() << std::endl;
}
Manager::~Manager() {

}

void Manager::openMenu() {
	std::cout << "1����˺�2�����˺�3�鿴����4ɾ���˺�5���ԤԼ����ע����¼" << std::endl;
}
void Manager::addAccount() {
	std::cout << "��������˺�����1ѧ��2��ʦ" << std::endl;
	std::string fileName;
	std::string tid;
	std::string errorTip;

	std::ofstream ofs;
	int select = 0;
	std::cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tid = "������ѧ��";
		errorTip = "ѧ���ظ�����������";
	}
	else
	{
		fileName = TEACHER_FILE;
		tid = "������ְ����";
		errorTip = "ְ�����ظ�����������";
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
	std::cout << "��������" << std::endl;
	std::cin >> name;
	std::cout << "��������" << std::endl;
	std::cin >> pwd;

	ofs << id << " " << name << " " << pwd << std::endl;
	std::cout << "��ӳɹ�" << std::endl;
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
	std::cout << "ѡ��鿴����1ѧ��2��ʦ" << std::endl;

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
	std::cout << "������Ϣ" << std::endl;
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
		std::cout << "�ļ���ʧ��"<<std::endl;
		ifs.close();
		return;
	}
	Student s;
	while (ifs >> s.id && ifs >> s.mName && ifs >> s.mPwd)
	{
		vStu.push_back(s);
	}
	std::cout << "��ǰѧ������Ϊ�� " << vStu.size() << std::endl;
	ifs.close();
	ifs.open(TEACHER_FILE, std::ios::in);
	if (!ifs.is_open())
	{
		std::cout << "�ļ���ʧ��" << std::endl;
		ifs.close();
		return;
	}
	Teacher t;
	while (ifs >> t.empId && ifs >> t.mName && ifs >> t.mPwd)
	{
		vTea.push_back(t);
	}
	std::cout << "��ǰ��ʦ����Ϊ�� " << vTea.size() << std::endl;
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
