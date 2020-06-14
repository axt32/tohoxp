#include "stringTokenizer.h"
using namespace _UtilSet;

StringTokenizer :: StringTokenizer()
{
	SplitComplete = false;
}
StringTokenizer :: StringTokenizer(std::string _OriginalString,std::string _TokenString,int _Option)
{
	Reset();
	OriginalString = _OriginalString;
	TokenString = _TokenString;
	switch(_Option)
	{
	case Opt_Split:
		Split(); break;
	case Opt_Erase:
		Erase(); break;
	}	
}
StringTokenizer :: ~StringTokenizer()
{
	ResultString.clear();
}

bool StringTokenizer :: Split()
{
	unsigned int FindResult;
	std::string TemporaryString;
	std::string SubString;

	ResultString.clear();
	if(OriginalString.size() <= TokenString.size() ){ SplitComplete = false; return false; }
	
	if(TokenString.size() == 0)
		ResultString.push_back(OriginalString);
	else
	{
			TemporaryString = OriginalString;
			while(1)
			{
				FindResult = TemporaryString.find(TokenString);
				if(FindResult == std::string::npos)
				{
					if(TemporaryString.size() != 0)
					{
						ResultString.push_back(TemporaryString);
					}
					else
					{
						ResultString.push_back("");		//공란일 경우 공백 값을 넣습니다.
					}
					break;
				}

				SubString = TemporaryString.substr(0,FindResult);
				TemporaryString = TemporaryString.substr(FindResult+1);

				if(SubString.size() != 0)
				{
					ResultString.push_back(SubString);
				}
				else
				{
					ResultString.push_back("");		//공란일 경우 공백 값을 넣습니다.
				}
			}
	}
	ResultCount = ResultString.size();
	SplitComplete = true;
	return SplitComplete;
}
bool StringTokenizer :: Split(std::string _OriginalString,std::string _TokenString)
{
	Reset();
	OriginalString = _OriginalString;
	TokenString = _TokenString;
	return Split();
}

bool StringTokenizer :: Erase()
{
	unsigned int FindResult;
	std::string TemporaryString;

	ResultString.clear();
	if(OriginalString.size() <= TokenString.size() ){ SplitComplete = false; return false; }

	if(TokenString.size() == 0)
		ResultString.push_back(OriginalString);
	else
	{
		TemporaryString = OriginalString;
		while(1)
		{
			FindResult = TemporaryString.find(TokenString);
			if(FindResult == std::string::npos)
			{
				if(TemporaryString.size() != 0)
					ResultString.push_back(TemporaryString);
				break;
			}
			TemporaryString.erase( FindResult,TokenString.size() );
		}
	}
	ResultCount = ResultString.size();
	SplitComplete = true;
	return SplitComplete;
}

bool StringTokenizer :: Erase(std::string _OriginalString,std::string _TokenString)
{
	Reset();
	OriginalString = _OriginalString;
	TokenString = _TokenString;
	return Erase();
}

std::string StringTokenizer ::GetResultString(unsigned int _SplitPosition)
{
	if(_SplitPosition >= ResultCount)
	{
		return NULL;
	}

	return ResultString[_SplitPosition];
}

void StringTokenizer :: Reset()
{
	OriginalString.clear();
	TokenString.clear();
	ResultString.clear();
	ResultCount = 0;
	SplitComplete = false;
}