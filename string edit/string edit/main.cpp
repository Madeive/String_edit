#pragma once
#include "TEXT_FOR_EDIT.h"
#include "COMMAND_LIST.h"
#include "COPY.h"
#include "COMMAND_INTERFACE.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "PASTE.h"
#include "INSERT.h"
#include "DELETE.h"
using namespace std;



int main()
{
	TEXT_FOR_EDIT exemple; // ������������� ���������
	BUFFER buffer; // ������������� �������
	COPY copyrka(&exemple, &buffer,0,7); // ������������� ������� COPY
	PASTE vstavka(&exemple, &buffer, 12);// ������������� ������� PASTE
	INSERT ustanovka(&exemple, "VSTAVIT ETO ", 0); // ������������� ������� INSERT
	DELETE sterka(&exemple, 0, 8);

	COMMAND_LIST Comands; // ������������� ��������
	cout << exemple.get_text() << endl ;
	Comands.push_command(&copyrka);// ���������� ������� COPY � ���� ������
	Comands.push_command(&vstavka); // ��������� ������� PASTE � ���� ������
	Comands.push_command(&ustanovka); // ��������� ������� INSERT � ���� ������
	Comands.push_command(&sterka); // ��������� ������� DELETE � ���� ������

	Comands.execute_command();// ���������� ���� ������
	cout << exemple.get_text() << endl;


}
