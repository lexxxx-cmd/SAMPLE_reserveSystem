#include "OrderFile.h"
OrderFile::OrderFile()
{
	std::ifstream ifs;
	ifs.open(ORDER_FILE, std::ios::in);
	std::string date;
	std::string interval;
	std::string stuId;
	std::string stuname;
	std::string roomId;
	std::string status;

	this->m_size = 0;
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuname && ifs >> roomId && ifs >> status)
	{
		std::string key;
		std::string value;
		std::map<std::string, std::string>m;

		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(std::make_pair(key, value));
		}
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(std::make_pair(key, value));
		}
		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(std::make_pair(key, value));
		}
		pos = stuname.find(":");
		if (pos != -1)
		{
			key = stuname.substr(0, pos);
			value = stuname.substr(pos + 1, stuname.size() - pos - 1);
			m.insert(std::make_pair(key, value));
		}
		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(std::make_pair(key, value));
		}
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(std::make_pair(key, value));
		}
		this->m_orderData.insert(std::make_pair(this->m_size, m));
		this->m_size++;
		
	}
	ifs.close();
}
void OrderFile::updateOrder() {
	if (this->m_size == 0)
	{
		return;
	}
	std::ofstream ofs(ORDER_FILE, std::ios::out | std::ios::trunc);
	for (int i = 0;i < this->m_size;i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << std::endl;
	}
	ofs.close();
}

