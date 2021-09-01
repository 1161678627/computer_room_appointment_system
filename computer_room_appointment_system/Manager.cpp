#include "Manager.h"
#include<fstream>
#include "globalFile.h"
#include<algorithm>

void printStus(Student& stu);
void printTchs(Teacher& tch);

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();
}

void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� ";
}

void Manager::addUser()
{
	cout << "��������Ҫ����˺ŵ����ͣ�1.ѧ����2.��ʦ����";
	int temp_choose = 0;
	cin >> temp_choose;
	if (temp_choose == 1)
	{
		int id;
		string name;
		string pwd;
		while (true)
		{
			cout << "������ѧ��id��";
			cin >> id;
			if (!checkRepeat(id, temp_choose))
			{
				break;
			}
			cout << "ѧ��id�ظ������������룡" << endl;
		}
		cout << "������ѧ���˺ţ�";
		cin >> name;
		cout << "������ѧ�����룺";
		cin >> pwd;
		// ׷��д�뵽��ʦ�ļ���
		ofstream ofs;
		// ָ��׷��д�뷽ʽ
		ofs.open(STUDENT_FILE, ios::out | ios::app);
		ofs << id << ' ' << name << ' ' << pwd << endl;
		cout << "ѧ�� " << name << " ��ӳɹ���" << endl;
		ofs.close();
		system("pause");
		system("cls");
	}
	else if (temp_choose == 2)
	{
		int id;
		string name;
		string pwd;
		while (true)
		{
			cout << "�������ʦ��ţ�";
			cin >> id;
			if (!checkRepeat(id, temp_choose))
			{
				break;
			}
			cout << "��ʦ����ظ������������룡" << endl;
		}
		cout << "�������ʦ�˺ţ�";
		cin >> name;
		cout << "�������ʦ���룺";
		cin >> pwd;
		ofstream ofs;
		// ָ��׷��д�뷽ʽ
		ofs.open(TEACHER_FILE, ios::out | ios::app);
		ofs << id << ' ' << name << ' ' << pwd << endl;
		cout << "��ʦ " << name << " ��ӳɹ���" << endl;
		ofs.close();
		system("pause");
		system("cls");
	}
	else
	{
		cout << "�����������������룡" << endl;
		system("pause");
		system("cls");
	}
	// ÿ��������û��󣬸�������
	this->initVector();
}

void Manager::showUser()
{
	cout << "��ѡ��Ҫչʾ�Ķ���1.ѧ����2.��ʦ����";
	int choose;
	cin >> choose;
	if (choose == 1)
	{
		cout << "��ǰ��ѧ�������ǣ�" << stus.size() << endl;
		for_each(stus.begin(), stus.end(), printStus);
	}
	else
	{
		cout << "��ǰ����ʦ�����ǣ�" << tchs.size() << endl;
		for_each(tchs.begin(), tchs.end(), printTchs);
	}
	system("pause");
	system("cls");
}

void Manager::showComputer()
{
	cout << "����������Ϊ��" << comps.size() << endl;
	for (int i = 0; i < comps.size(); i++)
	{
		cout << "�������Ϊ��" << comps[i].m_id << "\t����������Ϊ��" << comps[i].m_maxNum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::clearFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "ԤԼ��¼��ճɹ���" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	// ��ȡ��ʦ�ļ�
	ifstream ifs;
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << TEACHER_FILE << "�ļ�������" << endl;
		return;
	}
	// ÿ�ζ�ȡǰ���������������
	tchs.clear();
	Teacher tch;
	while ((ifs >> tch.m_id) && (ifs >> tch.m_Name) && (ifs >> tch.m_Pwd))
	{
		// push_backʱ���� Teacher�Ŀ������죬����ȥ����һ��ȫ�µı���
		tchs.push_back(tch);
	}
	ifs.close();

	// ��ȡѧ���ļ�
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << STUDENT_FILE << "�ļ�������" << endl;
		return;
	}
	// ÿ�ζ�ȡǰ���������������
	stus.clear();
	Student stu;
	while ((ifs >> stu.m_id) && (ifs >> stu.m_Name) && (ifs >> stu.m_Pwd))
	{
		// push_backʱ���� Teacher�Ŀ������죬����ȥ����һ��ȫ�µı���
		stus.push_back(stu);
	}
	ifs.close();

	// ��ȡ������Ϣ
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << COMPUTER_FILE << "�ļ�������" << endl;
		return;
	}
	comps.clear();
	computerRoom comp;
	while ((ifs >> comp.m_id) && (ifs >> comp.m_maxNum))
	{
		comps.push_back(comp);
	}
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	// ��ʦ
	if (type == 2)
	{
		for (vector<Teacher>::iterator it = this->tchs.begin(); it != this->tchs.end(); it++)
		{
			if (it->m_id == id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Student>::iterator it = this->stus.begin(); it != this->stus.end(); it++)
		{
			if (it->m_id == id)
			{
				return true;
			}
		}
	}
	return false;
}

void printStus(Student& stu)
{
	cout << "ѧ����id�ǣ�" << stu.m_id << "\t�˺��ǣ�" << stu.m_Name << "\t�����ǣ�" << stu.m_Pwd << endl;
}

void printTchs(Teacher& tch)
{
	cout << "��ʦ�ı���ǣ�" << tch.m_id << "\t�˺��ǣ�" << tch.m_Name << "\t�����ǣ�" << tch.m_Pwd << endl;
}