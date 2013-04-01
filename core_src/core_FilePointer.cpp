#include "headers/core_FilePointer.h"

namespace core
{
namespace file_pointer
{
	FilePointer::FilePointer(const char * _fl_name) : fl(_fl_name)
	{
		file_size = getFileSize();
	};
	FilePointer::~FilePointer()
	{
		fl.close();

	}
	uint32_t FilePointer::getFileSize()
	{
		long end, begin;
		begin = fl.tellg();
		fl.seekg(0, std::ios::end);
		end = fl.tellg();
		return (end-begin);
	}

	char FilePointer::getChar(uint8_t offset)
	{
		char retChar;
		fl.seekg(static_cast<std::streampos>(offset));
		retChar = fl.get();
		if(fl.good()) return retChar;
		else throw EoFErr();
	}
}
}