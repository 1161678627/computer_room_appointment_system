#include "Teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(int id, string name, string pwd)
{
	this->m_id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

void Teacher::operMenu()
{
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� ";

}

void Teacher::showAllOrder()
{
	Order od;
	if (od.order_size == 0)
	{
		cout << "��ǰû��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < od.order_size; i++)
	{
		Order of = od;
		cout << "ԤԼ���ڣ� ��" << of.m_order_data[i]["oday"];
		cout << " ʱ�Σ�" << (of.m_order_data[i]["otime"] == "1" ? "����" : "����");
		cout << " ѧ�ţ�" << of.m_order_data[i]["stuid"];
		cout << " ������" << of.m_order_data[i]["stuname"];
		cout << " ������" << of.m_order_data[i]["roomid"];
		string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
		if (of.m_order_data[i]["state"] == "1")
		{
			status += "�����";
		}
		else if (of.m_order_data[i]["state"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_order_data[i]["state"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

void Teacher::validOrder()
{
	Order of;
	if (of.order_size == 0)
	{
		cout << "��ǰû��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	// ���ڱ�ǲ�����¼���ļ�index
	vector<int> vindex;
	for (int i = 0; i < of.order_size; i++)
	{
		if (of.m_order_data[i]["state"] == "1")
		{
			vindex.push_back(i);	// ���������кŷŽ�ȥ
			cout << vindex.size() << "��";
			cout << "ԤԼ���ڣ� ��" << of.m_order_data[i]["oday"];
			cout << " ѧ�ţ�" << of.m_order_data[i]["stuid"];
			cout << " ������" << of.m_order_data[i]["stuname"];
			cout << " ʱ�Σ�" << (of.m_order_data[i]["otime"] == "1" ? "����" : "����");
			cout << " ������" << of.m_order_data[i]["roomid"];
			string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
			if (of.m_order_data[i]["state"] == "1")
			{
				status += "�����";
			}
			else if (of.m_order_data[i]["state"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_order_data[i]["state"] == "-1")
			{
				status += "���δͨ����ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}
	cout << "������Ҫ�����ļ�¼�ţ�����0ȡ������";
	int choose;
	cin >> choose;
	if (choose == 0)
	{
		cout << "����ȡ����" << endl;
		system("pause");
		system("cls");
		return;
	}
	if (choose >= 0 && choose <= vindex.size())
	{
		cout << "��������˽����1.ͨ���������ܾ�����";
		int choose_2;
		cin >> choose_2;
		if (choose_2 == 1)
		{
			// �޸Ķ�Ӧ��¼
			of.m_order_data[vindex[choose - 1]]["state"] = "2";
			of.updateOrder();
		}
		else
		{
			// �޸Ķ�Ӧ��¼
			of.m_order_data[vindex[choose - 1]]["state"] = "-1";
			of.updateOrder();
		}
		cout << "�����ϣ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "�������������²�����" << endl;
		system("pause");
		system("cls");
	}
}