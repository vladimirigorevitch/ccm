/*                                                                            *
*Abstraction level for modules which need to have access to source code.      *
*  Implementation should include  working with src located in memory          *
*  and for working with src located in file                                   */


#ifndef FILEINTERFACE_H__
#define FILEINTERFACE_H__

#include <string>
#include <inttypes.h>


#include "core_FilePointer.h"

#define MAX_MODULE_ACCESS 10

namespace core
{
namespace file_interface
{

	class FileInterface

	{
	private: /*Data*/
		std::string* fl;
		uint32_t* ID_Table;
		uint8_t free_cell;
		core::file_pointer::FilePointer file;
	public:
		FileInterface& createFS(std::string* _fl);
		FileInterface& createFS(const char * _file_name);
		char getChar(uint8_t ID);
		std::string getString(uint8_t ID); //Return str due to first '/n' symbol or EOF
		uint8_t getID();
		inline bool hasID(uint8_t ID) const { if(ID_Table[ID] == -1) return false; else return true;};
	private: /*Methods*/
		virtual ~FileInterface();
		FileInterface();
		FileInterface(const FileInterface&);
		FileInterface& operator=(const FileInterface&);
		void initNewFS();
		void initTable(uint32_t* ID_Table);
		void increaseChr();
		void increaseStr();

	};

	/*exceptions*/
	class FileErr
	{

	};
	class EoFile : FileErr
	{

	};
	class IDErr : FileErr
	{

	};

} /* namespace file_interface */
} /*namespace core */

#endif /* FILEINTERFACE_H__ */