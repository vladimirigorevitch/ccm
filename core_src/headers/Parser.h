#pragma once
#include "Types.h"
#include <vector>

namespace sintax
{

	const char* INCREMENT = "++";
	const char* DECREMENT = "--";
	const char* ASSIGNMENT = "=";
	const char* SEMICOLON = ";";

	class Parser 
	{
		public :
			Parser ();
			~Parser();

			void parse ();
			bool tokensStillRemain () const;


		private :
			types::Tree tree;
			std::vector< types::Token > tokens; 

			types::Token takeToken ();
			void addOperation ( types::Token operation , types::Token operand_fst , types::Token operand_scnd );


	};


}