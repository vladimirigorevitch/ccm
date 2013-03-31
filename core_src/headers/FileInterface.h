#ifndef FILEINTERFACE_H__
#define FILEINTERFACE_H__

#include <fstream>
#include <iostream>
#include <string>
#include <inttypes.h>

namespace core
{
namespace file_interface
{
	/* Abstraction level for modules which need to have access to source code.    *
	*  Implementation should include class for working with src located in memory *
	*  and class for working with src located in file                             */

	class FileInterface

	{
		public:
			FileInterface()
			{}
			virtual ~FileInterface()
			{}
			virtual char getChar() = 0;
			virtual std::string getString() = 0;
			virtual uint8_t getID() const = 0; //replace unsigned int with <uint_8>
			virtual inline bool hasID() const = 0;


	};

	/*Non multithread */
	class FilePtr : virtual public FileInterface
	{
	private: /*Data*/
		std::string& fl;
		uint8_t* ID_Table;
	public:
		FilePtr(std::string& _fl);
		virtual ~FilePtr();
		template <class Module> char getChar(Module* M) const;
		template <class Module> std::string getString(Module* M) const;
		template <class Module> uint8_t getID(Module* M) const;
		template <class Module> bool hasID(Module* M) const;
	private: /*Methods*/
		uint8_t hashStr(std::string Str) const;
		uint8_t searchID(std::string Str) const;
		void addNewID(std::string Str);
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

} /* nmaespace file_interface */
} /*namespace core */

#endif /* FILEINTERFACE_H__ */