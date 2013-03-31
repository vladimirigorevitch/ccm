#include <Map>
#include <string>

namespace types 
{

	class Token 
	{
	private :
		std::string type;
		std::string name;
		int table_pointer;

	public:
		Token(std::string type , std::string name , int pointer);
		Token(std::string type , std::string name);
		Token(const Token &another);
		~Token();

		std::string getTokenType() const;
		std::string getTokenName() const;
		int getTablePointer() const; 

		void Token::setPointer (int pointer);


	};


	class Tree
	{
	};



}

