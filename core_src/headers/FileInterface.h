/*                                                                            *
*Abstraction level for modules which need to have access to source code.      *
*  Implementation should include class for working with src located in memory *
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
		public:
			FileInterface()
			{}
			virtual ~FileInterface()
			{}
			virtual char getChar(uint8_t ID) = 0 ;
			virtual std::string getString(uint8_t ID) = 0;
			virtual uint8_t getID() = 0;
			virtual inline bool hasID(uint8_t ID) const = 0;


	};

	/*Non multithread */
	class FilePtr : virtual public FileInterface
	{
	private: /*Data*/
		std::string* fl;
		uint32_t* ID_Table;
		uint8_t free_cell;
		core::file_pointer::FilePointer file;
	public:
		FilePtr(std::string* _fl);
		FilePtr(const char * _file_name);
		virtual ~FilePtr();
		char getChar(uint8_t ID);
		std::string getString(uint8_t ID); //Return str due to first '/n' symbol or EOF
		uint8_t getID();
		inline bool hasID(uint8_t ID) const { if(ID_Table[ID] == -1) return false; else return true;};
	private: /*Methods*/
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