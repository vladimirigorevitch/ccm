#pragma once
#include "Types.h"
#include <vector>

namespace sintax
{
	const char* LVALUE = "lvalue";
	const char* RVALUE = "rvalue";

	class Parser 
	{
		public :
			Parser ();
			~Parser();

		private :
			types::Tree tree;
			std::vector< types::Token > tokens; 

			types::Token takeToken ();
			void addOperation ();
			


	};


}