#include "Types.h"

namespace types
{
	/*                                      Token                                             */
	/*      This is the Token class which can accept the name of the token and it's type      */



	Token::Token(std::string _type , std::string _name , int pointer) : table_pointer(pointer) ,
																		type(_type) , name(_name)
	{
	}

	Token::Token(std::string _type , std::string _name) :	type(_type) , name(_name)
	{
	}

	Token::Token(const Token &another) : table_pointer(another.table_pointer) , 
										 type(another.type) , name(another.name)
	{
	}

	Token::~Token()
	{
	}

	std::string Token::getTokenName () const 
	{
		return name;
	}

	std::string Token::getTokenType () const 
	{
		return type;
	}

	int Token::getTablePointer () const 
	{
		return table_pointer;
	}

	void Token::setPointer (int pointer)
	{
		table_pointer = pointer;
	}

	/*                                      Token ends                                        */
	/******************************************************************************************/

}