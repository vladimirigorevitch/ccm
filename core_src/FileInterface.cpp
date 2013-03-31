#include "headers/FileInterface.h"

namespace core
{
namespace file_interface
{
	FilePtr::FilePtr(std::string* _fl) : fl(_fl)
	{
		uint8_t *ID_Table = new uint8_t[10];

	}
	FilePtr::FilePtr(const char * _file_name) : file(_file_name)
	{
		uint8_t *ID_Table = new uint8_t[10];
		fl = 0;
	}
	FilePtr::~FilePtr()
	{
		delete[] ID_Table;
	}
	template <class Module> 
	uint8_t FilePtr::getID(Module* M) const
	{
		char buffer[100];
		std::string tmpString;
		snprintf(buffer, 100, "%p", M);
		tmpString = buffer;
		if(tmpString.length() > 0) return hashStr(tmpString);
		else throw EoFile();
	}
	uint8_t hashStr(std::string Str)
	{

	};



}
}