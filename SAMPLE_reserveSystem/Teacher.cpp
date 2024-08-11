#include "Teacher.h"
#include "OrderFile.h"
#include <vector>
Teacher::Teacher() {

}
Teacher::Teacher(int empId, std::string name, std::string pwd) {
	this->empId = empId;
	this->mName = name;
	this->mPwd = pwd;

}
Teacher::~Teacher() {

}

void Teacher::openMenu() {
	std::cout << "1�鿴ԤԼ2���ԤԼ3ע��" << std::endl;
}
void Teacher::showAllOrder() {
	OrderFile of;
	if (of.m_size == 0)
	{
		std::cout << "��ԤԼ��¼" << std::endl;
		system("pause");
		system("cls");
		return;

	}
	for (int i = 0;i < of.m_size;i++)

	{
		std::cout << i + 1 << std::endl;
		if (this->id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			std::cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
			std::cout << "ʱ��Σ� " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			std::cout << "����" << of.m_orderData[i]["stuName"];
			std::cout << "ѧ��; " << of.m_orderData[i]["stuId"];
			std::cout << "������" << of.m_orderData[i]["roomId"];
			std::string status;
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "��˳ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ��";
			}
			else
			{
				status += "ԤԼȡ��";
			}
			std::cout << status << std::endl;
		}
		system("pause");
		system("cls");
	}
}
void Teacher::validOrder() {
	OrderFile of;
	if (of.m_size == 0)
	{
		std::cout << "��ԤԼ��¼" << std::endl;
		system("pause");
		system("cls");
		return;

	}
	std::cout << "����˼�¼����" << std::endl;
	std::vector<int>v;
	int index = 0;
	for (int i = 0;i < of.m_size;i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			std::cout << ++index << "��";
			std::cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
			std::cout << "ʱ��Σ� " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			std::cout << "����" << of.m_orderData[i]["stuName"];
			std::cout << "ѧ��; " << of.m_orderData[i]["stuId"];
			std::cout << "������" << of.m_orderData[i]["roomId"];
			std::string status;
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			std::cout << status << std::endl;

		}
	}
	std::cout << "�����¼��0����" << std::endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		std::cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				std::cout << "������˽����1ͨ���������� " << std::endl;
				std::cin >> ret;
				if (ret == 1)
				{
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				
				of.updateOrder();
				std::cout << "�����" << std::endl;
				system("pause");
				system("cls");
			}
		}
	}

}
