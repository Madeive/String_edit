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
	TEXT_FOR_EDIT exemple; // Инициализация рессивера
	BUFFER buffer; // инициализация буффера
	COPY copyrka(&exemple, &buffer,0,7); // инициализация команды COPY
	PASTE vstavka(&exemple, &buffer, 12);// инициализация команды PASTE
	INSERT ustanovka(&exemple, "VSTAVIT ETO ", 0); // инициализация команды INSERT
	DELETE sterka(&exemple, 0, 8);

	COMMAND_LIST Comands; // инициализация инвокера
	cout << exemple.get_text() << endl ;
	Comands.push_command(&copyrka);// помещегние команды COPY в пулл команд
	Comands.push_command(&vstavka); // Помещение команды PASTE в пулл команд
	Comands.push_command(&ustanovka); // помещение команды INSERT в пулл команд
	Comands.push_command(&sterka); // помещение команды DELETE в пулл команд

	Comands.execute_command();// выполнение пула команд
	cout << exemple.get_text() << endl;


}
