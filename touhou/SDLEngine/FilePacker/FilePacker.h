//FilePacker

// Pack File 구조
// 0~3바이트 : Pack File속 파일의 갯수 (Big Endian)
// 4~7바이트 : Pack File의 첫번째 파일이 담긴 바이트 위치 (Big Endian)
// 8~11바이트 : Pack File의 첫번째 파일의 바이트 용량 (Big Endian)
// 12~x바이트 : Pack File의 첫번째 파일의 이름
// x+1~y바이트 : Pack File의 첫번째 파일의 데이터
// y+1~z바이트 : Pack FIle의 두번째 파일이 담긴 바이트 위치 (Big Endian)
// .....

#pragma once

#include <fstream>
#include <ostream>
#include <string>

#define FILEPACKER_CLUSTER_SIZE 1024

class FilePacker
{
private:
	std::ifstream m_In;
	char * m_pData;

	void WriteInt (int a);
	int ReadInt (std::ifstream * i, int start);

	void _StoreFiles(std::string IN_FolderName, std::string IN_SubFolderName);

	std::ofstream m_Out;
	int m_iFileCount;
	int m_iCurrentMarker;
	
	//내부용 함수들입니다. 엔드유저는 건드리면 안됩니다.
	int _GetFileCount();
	int _GetFilePos();
	int _GetFileSize();
	std::string _GetFileName(int IN_iFileDataPos);

	//GetFilePtr을 위해 쓰입니다. 각각 패킹파일을 열고 닫는 함수입니다.
	bool OpenFile(std::string IN_FileName);
	bool CloseFile();

public:
	FilePacker();
	~FilePacker();
	
	//특정한 폴더에 있는 모든 파일을 패킹합니다.
	void StoreFiles(std::string IN_FolderName, std::string IN_OutputPath);
	
	//패킹 파일속의 모든 파일을 특정한 폴더로 풉니다.
	void ExtractFiles(std::string IN_FileName, std::string IN_OutputPath);

	//패킹 파일속에서 원하는 자료의 포인터와 크기를 구합니다. 자료가 없을 경우 OUT_Ptr과 OUT_Size는 NULL을 반환합니다.
	bool GetFilePtr(std::string IN_FileName, std::string IN_DataName, char ** OUT_Ptr, int * OUT_Size);
	bool DeleteFilePtr();
};