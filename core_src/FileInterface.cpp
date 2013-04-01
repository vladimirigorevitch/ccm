#include "headers/FileInterface.h"

namespace core
{
namespace file_interface
{
	FilePtr::FilePtr(std::string* _fl) : fl(_fl), free_cell(0)
	{
		uint8_t *ID_Table = new uint8_t[MAX_MODULE_ACCESS];

	}
	FilePtr::FilePtr(const char * _file_name) : fl(0), free_cell(0),  file(_file_name)
	{
		uint8_t *ID_Table = new uint8_t[MAX_MODULE_ACCESS];
		initTable(ID_Table);
	}
	FilePtr::~FilePtr()
	{
		delete[] ID_Table;
	}

	void FilePtr::initTable(uint8_t* ID_Table)
	{
		for(int i = 0; i < MAX_MODULE_ACCESS; i++) ID_Table[i] = -1;
	}

	uint8_t FilePtr::getID()
	{
		if(free_cell == MAX_MODULE_ACCESS) throw IDErr();
		uint8_t return_id = free_cell;
		ID_Table[free_cell++] = 1;
		return return_id;
	}
	char FilePtr::getChar(uint8_t ID)
	{
		char returnChar;
		if(!hasID(ID)) throw IDErr();
		if(!fl)
		{
			try
			{
				returnChar = file.getChar(ID_Table[ID]);
			}
			catch(file_pointer::EoFErr)
			{
				throw EoFile();
			}
		}
		else
		{
			if(ID_Table[ID] < (*fl).length()) 
			{
				returnChar = (*fl)[ID_Table[ID]];
			}
			else throw EoFile();
		}
		ID_Table[ID]++;
		return returnChar;
	}



}
}