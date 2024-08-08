#include "Student.h"
#include "globalFile.h"
#include <fstream>
Student::Student() {

}
Student::Student(int id, std::string name, std::string pwd) {
	this->id = id;
	this->mName = name;
	this->mPwd = pwd;

	std::ifstream ifs;
	ifs.open(COMPUTER_ROOM_FILE, std::ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.max_Num)
	{
		this->vCom.push_back(com);
	}
	ifs.close();
}
Student::~Student() {

}

void Student::openMenu() {
	std::cout << "1����ԤԼ2�鿴ԤԼ3����ԤԼ4ȡ��ԤԼ5ע��" << std::endl;

}
void Student::applyOrder() {
	std::cout << "��һ������ѡ���죿" << std::endl;

	int date=0;
	int interval = 0;
	int room = 0;
	while (true)
	{
		std::cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		std::cout << "��������" << std::endl;
	}
	std::cout << "��������1��2��" << std::endl;

	while (true)
	{
		std::cin >> interval;
		if (interval==1 || interval==2)
		{
			break;
		}
		std::cout << "��������" << std::endl;
	}
	std::cout << "�ĸ�������1��2��3" << std::endl;
	for (auto n : this->vCom)
	{
		std::cout << n.m_ComId << "������ " << n.max_Num << std::endl;
	}
	while (true)
	{
		std::cin >> room; 
		if (room == 1 || room == 2 || room == 3)
		{
			break;
		}
		std::cout << "��������" << std::endl;
	}
	std::cout << "OK,�����" << std::endl;
	std::ofstream ofs;
	ofs.open(ORDER_FILE, std::ios::app);
	ofs << "date:" << date<<" ";
	ofs << "interval:" << interval << " ";
	ofs << "stuid:" << this->id << " ";
	ofs << "stuname:" << this->mName << " ";
	ofs << "roomid:" << room << " ";
	ofs << "status:" << 1 << std::endl;
	ofs.close();
	system("pause");
	system("cls");
}
void Student::showMyOrder() {

}
void Student::showAllOrder() {

}
void Student::cancelOrder() {

}