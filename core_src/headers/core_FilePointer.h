#ifndef CORE_FILEPOINTER_H__
#define CORE_FILEPOINTER_H__


#include <fstream>
#include <string>
#include <inttypes.h>

namespace core
{
namespace file_pointer
{
	class FilePointer
	{
		private: /* Data */
			uint32_t file_size;
			std::FILE *fl;
 		public:
 			FilePointer();
			FilePointer(const char * _fl_name);
			~FilePointer();
			char getChar(uint8_t offset) const;
		private:
			uint32_t getFileSize();			
	};

	/*exceptions*/
	class EoFErr
	{

	};

} /* namespace core */
} /* namespace file_pointer */

#endif /* CORE_FILEPOINTER_H__ */