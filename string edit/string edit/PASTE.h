#pragma once
#include "BUFFER.h"
#include "COMMAND_INTERFACE.h"
#include "TEXT_FOR_EDIT.h"


class PASTE : public COMMAND_INTERFACE
{
private:
	TEXT_FOR_EDIT* text_for_edit;
	BUFFER* saved_buffer;
	int ind_to_paste;

public:

	PASTE(TEXT_FOR_EDIT* text_for_edit,BUFFER* saved_buffer,int ind_to_paste):
		text_for_edit {text_for_edit},
		saved_buffer{saved_buffer},
		ind_to_paste{ind_to_paste}
	{}
	void execute() override
	{
		string tmp = text_for_edit->get_text();
		tmp.insert(ind_to_paste, saved_buffer->get_buffer());
		text_for_edit->set_text(tmp);
	}
};