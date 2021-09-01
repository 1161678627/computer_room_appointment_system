#pragma once
#include<iostream>
#include<string>
#include "Identity.h"
#include "computerRoom.h"
#include<vector>
#include<fstream>
#include "globalFile.h"
#include "Order.h"
using namespace std;

class Student : public Identity
{
public:
	// Ĭ�Ϲ���
	Student();
	// �вι���
	Student(int id, string name, string pwd);
	// �˵�����
	virtual void operMenu();
	// ����ԤԼ
	void applyOrder();
	// �鿴�ҵ�ԤԼ
	void showMyOrder();
	// �鿴����ԤԼ
	void showAllOrder();
	// ȡ��ԤԼ
	void cancleOrder();

	// ѧ��id����������û�У��Լ�����
	int m_id;
	
	// ��Ϊѧ��ԤԼ����ʱ����Ҫ֪����ǰ������Ϣ��������Ҫ��һ����������������
	vector<computerRoom> comps;
private:

};