#include "Student.h"

Student::Student()
{

}


Student::Student(int id, string name, string pwd)
{
	this->m_id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
	// ��ѧ�����캯���г�ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	computerRoom comp;
	while ((ifs >> comp.m_id) && (ifs >> comp.m_maxNum))
	{
		this->comps.push_back(comp);
	}	
}

void Student::operMenu()
{
	cout << "��ӭѧ����" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� ";
}

void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	int oday = 0;
	while (true)
	{
		cout << "����������ԤԼ�����ڣ�";
		cin >> oday;
		if ((oday >= 1) && (oday <= 5))
		{
			break;
		}
		cout << "ԤԼ�����������������룡" << endl;
	}
	cout << "1������" << endl;
	cout << "2������" << endl;
	int otime;
	while (true)
	{
		cout << "����������ԤԼ��ʱ�䣺";
		cin >> otime;
		if ((otime == 1) || (otime == 2))
		{
			break;
		}
		cout << "ԤԼʱ���������������룡" << endl;
	}
	cout << "1�Ż���������" << comps[0].m_maxNum << endl;
	cout << "2�Ż���������" << comps[1].m_maxNum << endl;
	cout << "3�Ż���������" << comps[2].m_maxNum << endl;
	int oroom;
	while (true)
	{
		cout << "����������ԤԼ�Ļ�����";
		cin >> oroom;
		if ((otime == 1) || (otime == 2) || (otime == 3))
		{
			break;
		}
		cout << "ԤԼ�����������������룡" << endl;
	}
	cout << "ԤԼ�ɹ����ȴ���ʦ����У�" << endl;
	// ��ԤԼ��Ϣд��order�ļ���
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "data:" << oday << ' ';
	ofs << "interval:" << otime << ' ';
	ofs << "stuid:" << this->m_id << ' ';
	ofs << "name:" << this->m_Name << ' ';
	ofs << "roomid:" << oroom << ' ';
	ofs << "state:" << 1 << ' ' << endl;
	ofs.close();
	system("pause");
	system("cls");
}

void Student::showMyOrder()
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
		// ���ַ���ǿתΪ����
		if (atoi(od.m_order_data[i]["stuid"].c_str()) == this->m_id)
		{
			Order of = od;
			cout << "ԤԼ���ڣ� ��" << of.m_order_data[i]["oday"];
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
	system("pause");
	system("cls");
}

void Student::showAllOrder()
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

void Student::cancleOrder()
{
	Order of;
	if (of.order_size == 0)
	{
		cout << "��ǰû�пɹ�ȡ���ļ�¼��" << endl;
	}
	// ���ڱ�ǲ�����¼���ļ�index
	vector<int> vindex;
	for (int i = 0; i < of.order_size; i++)
	{
		// ɸѡ�����Լ��ļ�¼
		if (atoi(of.m_order_data[i]["stuid"].c_str()) == this->m_id)
		{
			if (of.m_order_data[i]["state"] == "1" || of.m_order_data[i]["state"] == "2")
			{
				vindex.push_back(i);	// ���������кŷŽ�ȥ
				cout << vindex.size() << "��";
				cout << "ԤԼ���ڣ� ��" << of.m_order_data[i]["oday"];
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
		// �޸Ķ�Ӧ��¼
		of.m_order_data[vindex[choose - 1]]["state"] = "0";
		of.updateOrder();
		cout << "�ѳɹ�ȡ��ԤԼ��" << endl;
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