#pragma once
#include "COMMAND_INTERFACE.h"
#include "TEXT_FOR_EDIT.h"
#include "BUFFER.h"
#include "COPY.h"
#include "PASTE.h"
#include "INSERT.h"
#include "DELETE.h"


class UNDO : public COMMAND_INTERFACE
{
	TEXT_FOR_EDIT* text_for_edit;
	BUFFER* text_buffer;
};