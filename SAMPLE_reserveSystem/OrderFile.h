#pragma once
#include <iostream>
#include <fstream>
#include "globalFile.h"
#include <map>
class OrderFile
{
public:
	OrderFile();
	void updateOrder();
	int m_size;
	std::map<int, std::map<std::string, std::string>>m_orderData;
};

