#include "headers/core_FilePointer.h"

namespace core
{
namespace file_pointer
{
	FilePointer::FilePointer(const char * _fl_name)
	{
		std::FILE *fl = std::fopen(_fl_name, "r");
		file_size = getFileSize();
	};
	FilePointer::~FilePointer()
	{
		std::fclose(fl);

	}

}
}