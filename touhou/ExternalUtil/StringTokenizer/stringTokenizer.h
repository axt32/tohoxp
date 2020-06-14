#ifndef _UtilSet_StringTokenizer
#define  _UtilSet_StringTokenizer

#include <string>
#include <vector>

// Split StringData with Token.

namespace _UtilSet
{
	class StringTokenizer
	{
	public:
		//using token for split?
		static const int Opt_Split = 0;
		//using token for erase?
		static const int Opt_Erase= 1;
	public:
		//Create StringTokenizerClass with default value
		StringTokenizer();
		//Create StringTokenizerClass with Split Process
		StringTokenizer(std::string _OriginalString,std::string _TokenString,int _Option = Opt_Split);
		//Destructor
		~StringTokenizer();
	private:
		//OriginalString For Split with Token.
		std::string OriginalString;
		//Token String.
		std::string TokenString;

		unsigned int ResultCount;
		bool SplitComplete;

		//Result Strings
		std::vector<std::string> ResultString;
	public:
		//How many strings in result?
		unsigned int GetResultCount() {return ResultCount;}
		void SetOriginalString(std::string _OriginalString) {OriginalString = _OriginalString;}
		void SetTokenString(std::string _TokenString) {TokenString = _TokenString;}

		//Split with OriginalString and TokenString.
		bool Split();
		bool Split(std::string _OriginalString,std::string _TokenString);

		//Erase TokenString In OriginalString. Result Data is ResultString[0].
		bool Erase();
		bool Erase(std::string _OriginalString,std::string _TokenString);

		//Get ResultString with PositionNumber. if wrong number, return Null.
		std::string GetResultString(unsigned int _SplitPosition);

		void Reset();
	};
}
#endif