#pragma once
#include<iostream>
#include<string>
using namespace std;

// �����ֻ࣬��ͷ�ļ����ɣ�����Ҫʵ�ִ��룬������ʵ�֣�����ϵͳ�е�������ݳ��������
class Identity
{
public:
	// ���麯��
	virtual void operMenu() = 0;
	string m_Name;
	string m_Pwd;

private:

};