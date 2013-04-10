#include "Parser.h"

namespace sintax
{
	types::Token Parser::takeToken ()
	{
		//add to the id table
	}

	void Parser::parse ()
	{
		while ( tokensStillRemain() )
		{
			types::Token new_token = takeToken();
			switch (new_token.getTokenType())              //TODO: Thinking to break into private functions
			{
			case types::VARIABLE :
				{
				
					if ( false == new_token.isLvalue() )
					{
						//TODO: error
						break;
					}
					tokens.push_back(new_token);
					new_token = takeToken();

					if ( ASSIGNMENT == new_token.getTokenName())
					{
						//build function for adding arithmetics w/ RPN 
						//addOperation(new_token , tokens.pop_back() ,  )
						/*while ( semicolon != (new_token = taketoken()).gettokenname() )
						{
							
						}*/
					}
					else if ( INCREMENT == new_token.getTokenName() )
					{
						//create constant token "1" add operation
					}
					else if ( DECREMENT == new_token.getTokenName() )
					{
						//create constant token "1" add operation
					}

					
				}
			case types::KEY_WORD :
				{
					//TODO: for/while/do_while/if
				}
			case types::FUNCTION :
				{
					//TODO: func add body
				}
			default:
				{
					//TODO: error
					break;
				}
			}
			//tokens.push_back();
		}
	}
}