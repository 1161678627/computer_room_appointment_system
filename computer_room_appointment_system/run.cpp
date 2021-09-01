#include<iostream>
#include<string>
#include<fstream>
#include "Identity.h"
#include "globalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
using namespace std;

void login(string file_name, int type);
void managerMenu(Identity*& manager);
void studentMenu(Identity*& student);
void teacherMenu(Identity*& teacher);

void show_menu()
{
	cout << "======================  ��ӭ��������ԤԼϵͳ  ====================="
		<< endl;
	cout << endl << "�������������" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.ѧ������           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.��    ʦ           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.�� �� Ա           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.��    ��           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "��������ѡ��: ";
}

// �û�ѡ��
void select_user()
{
	int choose;
	cin >> choose;
	switch (choose)
	{
	case 1:
		login(STUDENT_FILE, 1);
		break;
	case 2:
		login(TEACHER_FILE, 2);
		break;
	case 3:
		login(MANAGER_FILE, 3);
		break;
	case 0:
	{
		cout << "�����˳�ϵͳ��" << endl;
		system("pause");
		system("cls");
		exit(0); 
	}
		break;
	default:
		cout << "��������������ѡ��" << endl;
		break;
	}

}

// ִ�е�¼
void login(string file_name, int type)
{
	// ʵ��������ָ�룬ָ���¼�ɹ���Ĳ�ͬ�������
	Identity* person = NULL;
	// ����filename�鿴��Ӧ�˺������ļ��Ƿ����
	ifstream ifs;
	ifs.open(file_name, ios::in);
	if (!ifs.is_open())
	{
		cout << file_name << "�ļ�������!" << endl;
		ifs.close();
		return;
	}
	int id;
	string name;
	string pwd;
	// ��ȡ�û��ļ��е��˺�����
	int fid;
	string fname;
	string fpwd;
	int flag = 0;
	switch (type)
	{
	case 1:
	{
		cout << "������ѧ��id��";
		cin >> id;
		cout << "�������˺ţ�";
		cin >> name;
		cout << "���������룺";
		cin >> pwd;
		// �жϵ�½�Ƿ�ɹ�
		// ��ifs�ж����ݣ�ѭ��һ�ζ�һ�У��ո��־һ�����ݽ���
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if ((fid == id) && (fname == name) && (fpwd == pwd))
			{
				cout << "ѧ�� " << name << " ��½�ɹ���" << endl;
				flag = 1;
				system("pause");
				system("cls");
				// ����ǰ��¼���󿪱ٵ������������ص�ָ�봫�������person����
				person = new Student(id, name, pwd);
				// ����ѧ���û��������棬�Ե�ǰѧ����ݽ��в���
				studentMenu(person);
				// ��ѧ���û��˳���¼�����ص����˵�����
				delete person;
				return;
			}
		}
		if (flag == 0)
		{
			cout << "�˺�����������������룡" << endl;
		}
	}
	break;
	case 2:
	{
		cout << "�������ʦ��ţ�";
		cin >> id;
		cout << "�������˺ţ�";
		cin >> name;
		cout << "���������룺";
		cin >> pwd;
		// �жϵ�½�Ƿ�ɹ�
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if ((fid == id) && (fname == name) && (fpwd == pwd))
			{
				cout << "��ʦ " << name << " ��½�ɹ���" << endl;
				system("pause");
				system("cls");
				// ����ǰ��¼���󿪱ٵ������������ص�ָ�봫�������person����
				person = new Teacher(id, name, pwd);
				// �����ʦ�û��������棬�Ե�ǰ��ʦ��ݽ��в���
				teacherMenu(person);
				// ����ʦ�û��˳���¼�����ص����˵�����
				delete person;
				return;
			}
		}
		if (flag == 0)
		{
			cout << "�˺�����������������룡" << endl;
		}
	}
	break;
	case 3:
	{
		cout << "���������Ա�˺ţ�";
		cin >> name;
		cout << "���������Ա���룺";
		cin >> pwd;
		// �жϵ�½�Ƿ�ɹ�
		while (ifs >> fname && ifs >> fpwd)
		{
			if ((fname == name) && (fpwd == pwd))
			{
				cout << "����Ա " << name << " ��½�ɹ���" << endl;
				system("pause");
				system("cls");
				// ����ǰ��¼���󿪱ٵ������������ص�ָ�봫�������person����
				person = new Manager(name, pwd);
				// �������Ա�û��������棬�Ե�ǰ����Ա��ݽ��в���
				managerMenu(person);
				// ������Ա�û��˳���¼�����ص����˵�����
				// �ֶ��ͷŶ�������
				delete person;
				return;
			}
			else
			{
				cout << "�˺�����������������룡" << endl;
			}
		}
		if (flag == 0)
		{
			cout << "�˺�����������������룡" << endl;
		}
	}
	break;
	default:
		break;
	}
}

// ��ӹ���Ա��¼�ɹ�����������ȫ�ֺ���
// ����һ�������ָ������
void managerMenu(Identity*& manager)
{
	while (true)
	{
		// չʾmanager�˵�
		manager->operMenu();
		int choose;
		cin >> choose;
		// ǿת����ָ��ָ����������Ϊ����ָ�룬�����ָ��ֻ�ܵ��ø��෽����ǿת��ɵ���������з���
		Manager* mag = (Manager*)manager;
		switch (choose)
		{
		case 1:
			mag->addUser();
			break;
		case 2:
			mag->showUser();
			break;
		case 3:
			mag->showComputer();
			break;
		case 4:
			mag->clearFile();
			break;
		case 0:
			cout << "�����˳���¼��" << endl;
			return;
		default:
			break;
		}
	}
}


void studentMenu(Identity*& student)
{
	while (true)
	{
		student->operMenu();
		int choose;
		cin >> choose;
		Student* stu = (Student*)student;
		switch (choose)
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
			stu->cancleOrder();
			break;
		case 0:
			cout << "�����˳���¼��" << endl;
			return;
		default:
			break;
		}
	}
}

void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();
		int choose;
		cin >> choose;
		Teacher* tea = (Teacher*)teacher;
		switch (choose)
		{
		case 1:
			tea->showAllOrder();
			break;
		case 2:
			tea->validOrder();
			break;
		case 0:
			cout << "�����˳���¼��" << endl;
			return;
		default:
			break;
		}
	}
}


int main() {
	while (true)
	{
		show_menu();
		select_user();
		system("pause");
		system("cls");
	}
	return 0;
}