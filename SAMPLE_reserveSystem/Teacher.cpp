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
	std::cout << "1查看预约2审核预约3注销" << std::endl;
}
void Teacher::showAllOrder() {
	OrderFile of;
	if (of.m_size == 0)
	{
		std::cout << "无预约记录" << std::endl;
		system("pause");
		system("cls");
		return;

	}
	for (int i = 0;i < of.m_size;i++)

	{
		std::cout << i + 1 << std::endl;
		if (this->id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			std::cout << "预约日期： 周" << of.m_orderData[i]["date"];
			std::cout << "时间段： " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			std::cout << "姓名" << of.m_orderData[i]["stuName"];
			std::cout << "学号; " << of.m_orderData[i]["stuId"];
			std::cout << "机房号" << of.m_orderData[i]["roomId"];
			std::string status;
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "审核成功";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "预约失败";
			}
			else
			{
				status += "预约取消";
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
		std::cout << "无预约记录" << std::endl;
		system("pause");
		system("cls");
		return;

	}
	std::cout << "待审核记录如下" << std::endl;
	std::vector<int>v;
	int index = 0;
	for (int i = 0;i < of.m_size;i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			std::cout << ++index << "、";
			std::cout << "预约日期： 周" << of.m_orderData[i]["date"];
			std::cout << "时间段： " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			std::cout << "姓名" << of.m_orderData[i]["stuName"];
			std::cout << "学号; " << of.m_orderData[i]["stuId"];
			std::cout << "机房号" << of.m_orderData[i]["roomId"];
			std::string status;
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			std::cout << status << std::endl;

		}
	}
	std::cout << "输入记录，0返回" << std::endl;
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
				std::cout << "输入审核结果：1通过其他不行 " << std::endl;
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
				std::cout << "已审核" << std::endl;
				system("pause");
				system("cls");
			}
		}
	}

}
