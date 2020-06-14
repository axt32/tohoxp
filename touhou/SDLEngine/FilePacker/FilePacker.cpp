#include "FilePacker.h"
#include <windows.h>
#include <regex>
#include "../../ExternalUtil/INIManager/INIManager.h"

FilePacker :: FilePacker()
{
	m_pData = NULL;
	m_iFileCount = 0;
	m_iCurrentMarker = 0;
}

FilePacker :: ~FilePacker()
{

}

//정수형(4바이트) 숫자를 빅 엔디안 방식 1바이트 네개로 쪼갭니다.
void FilePacker::WriteInt (int a)
{
	//big endian
	char str[4];
	str[0] = static_cast<char> ( ( a & 0xff000000 ) >> 24 );		//256 ^ 0
	str[1] = static_cast<char> ( ( a & 0x00ff0000 ) >> 16 );		//256 ^ 1
	str[2] = static_cast<char> ( ( a & 0x0000ff00 ) >> 8 );			//256 ^ 2
	str[3] = static_cast<char> ( ( a & 0x000000ff ) >> 0 );			//256 ^ 3
	m_Out.write(str, 4);
}

int FilePacker::ReadInt (std::ifstream * IN_IFStream, int start)
{
	IN_IFStream->seekg(start, std::ifstream::beg);
	char str[4];
	IN_IFStream->read(str, 4);

	UCHAR ustr[4];
	for (int i = 0; i < 4; i++)
	{
		ustr[i] = str[i];
	}

	int i0 = static_cast<int> ( ( ustr[0]  ) << 24 );		//256 ^ 3
	int i1 = static_cast<int> ( ( ustr[1]  ) << 16 );		//256 ^ 2
	int i2 = static_cast<int> ( ( ustr[2]  ) << 8 );			//256 ^ 1
	int i3 = static_cast<int> ( ( ustr[3]  ) << 0 );			//256 ^ 0

	int iResult = i0 + i1 + i2 + i3;
	return iResult;
}

void FilePacker::StoreFiles(std::string IN_FolderName, std::string IN_OutputPath)
{
	printf ("Packing ...\n");
	//헤더에 파일목록들을 저장한다.
	m_iFileCount = 0;
	m_iCurrentMarker = 4;
	m_Out.open(IN_OutputPath, std::ofstream::binary);
	m_Out.seekp(4, std::ofstream::beg);
	_StoreFiles(IN_FolderName + "\\*.*", "");
	m_Out.seekp(0, std::ofstream::beg);
	WriteInt(m_iFileCount);

	//본체에 파일의 데이터들을 저장한다.

	m_Out.close();
	printf ("Packing Completed!\n");
}

void FilePacker::_StoreFiles(std::string IN_FolderName, std::string IN_SubFolderName)
{
	BOOL bResult = TRUE;
	WIN32_FIND_DATAA ffResult;

	HANDLE hFind = FindFirstFileA (IN_FolderName.c_str(), &ffResult);

	while ( hFind != INVALID_HANDLE_VALUE && bResult != FALSE)
	{
		std::string sFileName = ffResult.cFileName;

		std::basic_string <CHAR>::size_type iIndex1 = IN_FolderName.find_last_of("\\");
		std::string sPathDirectory = IN_FolderName.substr(0, iIndex1 + 1).c_str();
		std::string sFilePath = sPathDirectory + sFileName;

		if ((ffResult.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM ) == 0
			&& (ffResult.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN) == 0)
		{
			if ( (ffResult.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0 )		//비디렉토리
			{
				//여기서 패킹
				std::ifstream in(sFilePath, std::ifstream::binary);

				in.seekg(0, std::ifstream::end);
				int iFileSize = in.tellg();

				//시작위치 ( 지금까지의 위치 + 시작위치 정보담는곳(4) + 파일크기(4) + 파일이름(X) )
				std::string sPackName = IN_SubFolderName + sFileName;
				int iFileNameLen = sPackName.size();
				int iFileStartPos =  m_iCurrentMarker + 4 + 4 + iFileNameLen;
				WriteInt(m_iCurrentMarker + 4 + 4 + iFileNameLen);

				//파일크기
				WriteInt(iFileSize);

				//파일이름
				m_Out.write (sPackName.c_str(), iFileNameLen);

				printf ("%d	%d	%s	", iFileStartPos, iFileSize, sPackName.c_str());
				
				//데이터 내용 (1KBytes씩 보냄)	
				int iCurrentFileSrcPos = 0;
				while ( true )
				{
					if (iCurrentFileSrcPos + FILEPACKER_CLUSTER_SIZE > iFileSize)
					{
						in.seekg(iCurrentFileSrcPos, std::ifstream::beg);
						int iTailSize = iFileSize % FILEPACKER_CLUSTER_SIZE;
						char * data = new char[iTailSize];
						in.read(data, iTailSize);
						m_Out.write(data, iTailSize);
						delete[] data;
						break;
					}
					else
					{
						in.seekg(iCurrentFileSrcPos, std::ifstream::beg);
						char data[FILEPACKER_CLUSTER_SIZE];
						in.read(data, FILEPACKER_CLUSTER_SIZE);
						m_Out.write(data, FILEPACKER_CLUSTER_SIZE);
						iCurrentFileSrcPos += FILEPACKER_CLUSTER_SIZE;

						//만약 파일 크기가 1kb로 딱 나누어 떨어지면, 종료시킨다.
 						if (iCurrentFileSrcPos == iFileSize)
 						{
 							break;
 						}
					}
				}

				in.close();

				printf ("OK\n");

				//마커 갱신
				m_iCurrentMarker += (4 + 4 + iFileNameLen + iFileSize);

				m_iFileCount++;
			}
			else		//디렉토리
			{
				if ( !(std::strcmp( sFileName.c_str(), ".") == 0 
					|| std::strcmp ( sFileName.c_str(), "..") == 0) )
				{
					_StoreFiles(sFilePath + "\\*.*", IN_SubFolderName + sFileName + "/");
				}
			}
		}

		bResult = FindNextFileA(hFind, &ffResult);
	}
}

int FilePacker :: _GetFileCount()
{
	int iOutputFileCount = ReadInt(&m_In, m_iCurrentMarker);
	m_iCurrentMarker += 4;

	return iOutputFileCount;
}

int FilePacker :: _GetFilePos()
{
	int iFileDataPos = ReadInt(&m_In, m_iCurrentMarker);
	m_iCurrentMarker += 4;

	return iFileDataPos;
}

int FilePacker :: _GetFileSize()
{
	int iOutputFileSize = ReadInt(&m_In, m_iCurrentMarker);
	m_iCurrentMarker += 4;

	return iOutputFileSize;
}

std::string FilePacker :: _GetFileName(int IN_iFileDataPos)
{
	m_In.seekg(m_iCurrentMarker, std::ifstream::beg);
	int iOutputFileNameLen = IN_iFileDataPos - m_iCurrentMarker;
	char * sGetFileName = new char[iOutputFileNameLen + 1];
	sGetFileName[iOutputFileNameLen] = 0;
	m_In.read(sGetFileName, iOutputFileNameLen);
	m_iCurrentMarker += iOutputFileNameLen;
	std::string sResult = sGetFileName;
	delete[] sGetFileName;
	return sResult;
}

void FilePacker::ExtractFiles(std::string IN_FileName, std::string IN_OutputPath)
{
	printf ("Unpacking ...\n");

	OpenFile(IN_FileName);
	
	std::regex rx ("/");

	//1. 파일갯수
	int iOutputFileCount = _GetFileCount();
	for (int i = 0; i < iOutputFileCount; i++)
	{
		//2. 데이터 존재위치
		int iFileDataPos = _GetFilePos();
		
		//3. 파일크기
		int iOutputFileSize = _GetFileSize();

		//4. 파일이름
		std::string sDestFileName = _GetFileName(iFileDataPos);

		printf ("%d	%d	%s	", iFileDataPos, iOutputFileSize, sDestFileName.c_str());
	
		//파일 복사
		sDestFileName = std::regex_replace(sDestFileName, rx, std::string("\\"), std::regex_constants::format_default);
		
		//디렉토리부터 만들음.
		std::string sDestPath = IN_OutputPath + "\\" + sDestFileName;
		int iIndexLast = sDestPath.find_last_of("\\");
		int iIndexMarker = sDestPath.find("\\", 0);
		while ( true )
		{
			if (iIndexMarker == -1)
			{
				break;
			}
			std::string sDestFolderName = sDestPath.substr(0, iIndexMarker);
			CreateDirectoryA(sDestFolderName.c_str(), NULL);
			
			iIndexMarker = sDestPath.find("\\", iIndexMarker + 1);
		}

		std::ofstream unpack_out(sDestPath, std::ifstream::binary);

		int iNextFileInfoStart = iFileDataPos + iOutputFileSize;
		while ( true )
		{
			if (m_iCurrentMarker + FILEPACKER_CLUSTER_SIZE > iNextFileInfoStart)
			{
				m_In.seekg(m_iCurrentMarker, std::ifstream::beg);
				int iTailSize = iOutputFileSize % FILEPACKER_CLUSTER_SIZE;
				char * data = new char[iTailSize];
				m_In.read(data, iTailSize);
				unpack_out.write(data, iTailSize);
				delete[] data;
				m_iCurrentMarker += iTailSize;
				break;
			}
			else
			{
				m_In.seekg(m_iCurrentMarker, std::ifstream::beg);
				char data[FILEPACKER_CLUSTER_SIZE];
				m_In.read(data, FILEPACKER_CLUSTER_SIZE);
				unpack_out.write(data, FILEPACKER_CLUSTER_SIZE);
				m_iCurrentMarker += FILEPACKER_CLUSTER_SIZE;

				//만약 파일 크기가 1kb로 딱 나누어 떨어지면, 종료시킨다.
 				if (m_iCurrentMarker == iNextFileInfoStart)
 				{
					break;
 				}
			}
		}

		unpack_out.close();
		printf ("OK\n");

	}

	CloseFile();

	printf ("Unpacking Completed!\n");
}

//GetFilePtr을 위해 쓰입니다. 각각 패킹파일을 열고 닫는 함수입니다.
bool FilePacker :: OpenFile(std::string IN_FileName)
{
	if (m_In.is_open() == false)
	{
		m_In.open(IN_FileName, std::ifstream::binary);
		m_iCurrentMarker = 0;
		return true;
	}

	return false;
}

bool FilePacker :: CloseFile()
{
	if (m_In.is_open() == true)
	{
		m_In.close();
	}

	return false;
}

//패킹 파일속에서 원하는 자료의 포인터와 크기를 구합니다. 자료가 없을 경우 OUT_Ptr과 OUT_Size는 NULL을 반환합니다.
bool FilePacker :: GetFilePtr(std::string IN_FileName, std::string IN_DataName, char ** OUT_Ptr, int * OUT_Size)
{
	OpenFile(IN_FileName);

	if (m_pData != NULL)
	{
		return false;
	}

	//1. 파일갯수
	int iOutputFileCount = _GetFileCount();
	for (int i = 0; i < iOutputFileCount; i++)
	{
		//2. 데이터 존재위치
		int iFileDataPos = _GetFilePos();

		//3. 파일크기
		int iOutputFileSize = _GetFileSize();

		//4. 파일이름
		std::string sDestFileName = _GetFileName(iFileDataPos);
		if ( std::strcmp(sDestFileName.c_str(), IN_DataName.c_str()) == 0)
		{
			//이렇게 할 경우 매우 큰 용량은 new에 실패할수도 있으나, 일단 이렇게 한다.
			m_pData = new char[iOutputFileSize];
			m_In.read(m_pData, iOutputFileSize);

			*OUT_Ptr = m_pData;
			*OUT_Size = iOutputFileSize;
			
			CloseFile();
			return true;
		}

		m_iCurrentMarker += iOutputFileSize;

	}

	CloseFile();
	return false;
}

bool FilePacker :: DeleteFilePtr()
{
	if (m_pData != NULL)
	{
		delete[] m_pData;
		m_pData = NULL;

		return true;
	}

	return false;
}