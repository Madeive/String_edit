#pragma once
#include "COMMAND_INTERFACE.h"
#include "TEXT_FOR_EDIT.h"
#include "BUFFER.h"
using namespace std;

class COPY : public COMMAND_INTERFACE
{
protected:

	TEXT_FOR_EDIT* text_for_edit;
	BUFFER* text_buffer;
	int from;
	int to;

public:

	COPY(TEXT_FOR_EDIT* text_for_edit,BUFFER* text_buffer, int from, int to) : 
		text_for_edit{ text_for_edit},
		text_buffer {text_buffer},
		from{ from },
		to{ to }{}

	void execute() override
	{
		text_buffer->set_buffer(text_for_edit->get_text().substr(from, to));
	}

};