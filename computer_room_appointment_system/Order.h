#pragma once
#include<string>
#include<iostream>
#include<map>
#include<string>
#include "globalFile.h"
#include<fstream>
using namespace std;

class Order
{
public:
	Order();

	// ��¼ԤԼ������,map�е�һ��Ԫ�ر�ʾһ��ԤԼ��¼
	map<int, map<string, string>> m_order_data;
	int order_size = 0;

	// ��ʦ���ܻ��޸ĳ�ʼ����order�����е����ݣ�������״̬��������Ҫ���޸ĺ������������д��
	// order.txt�ļ��У����Լ�¼
	void updateOrder();
private:

};