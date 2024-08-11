#include <iostream>
#include <fstream>
#include "Identity.h"
#include "globalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
//����Ա�Ӳ˵�
void managerMenu(Identity* &manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->openMenu();
		//������ָ��תΪ����ָ���Ե�������Ľӿ�
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
		std::cout << "�ļ������ڡ�" << std::endl;
		ifs.close();
		return;
	}
	//׼���û�����
	int id=0;
	std::string name;
	std::string pwd;
	if (type == 1)
	{
		std::cout << "����ѧ��" <<std::endl;
		std::cin >> id;
	}
	else if (type == 2)
	{
		std::cout << "����ְ����" << std::endl;
		std::cin >> id;
	}
	std::cout << "�����û���" << std::endl;
	std::cin >> name;
	std::cout << "��������" << std::endl;
	std::cin >> pwd;

	//��֤�Ƿ����
	if (type == 1)
	{
		//��֤ѧ��
		int fId;
		std::string fName;
		std::string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���û�����Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				std::cout << "��֤�ɹ�" << std::endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ���Ӳ˵�'
				studenMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��֤��ʦ
		int fId;
		std::string fName;
		std::string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���û�����Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				std::cout << "��֤�ɹ�" << std::endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//������ʦ�Ӳ˵�'

				return;
			}
		}
	}
	else if (type == 3)
	{
		//��֤����

		std::string fName;
		std::string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			//���û�����Ա�
			if (fName == name && fPwd == pwd)
			{
				std::cout << "��֤�ɹ�" << std::endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա�Ӳ˵�'
				managerMenu(person);
				return;
			}
		}
	}
	std::cout << "��֤��¼ʧ��" << std::endl;
	system("pause");
	system("cls");
	return;
}
void test()
{
	int select = 0;
	while (true)
	{
		std::cout << "1��ѧ��"
			<< "2����ʦ"
			<< "3������Ա"
			<< "0���˳�"
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
			std::cout << "��ӭ�´�ʹ�ã�" << std :: endl;
			system("pause");
			return;
			break;
		default:
			std::cout << "����ѡ��" << std::endl;
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