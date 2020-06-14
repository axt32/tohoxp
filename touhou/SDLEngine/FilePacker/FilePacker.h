//FilePacker

// Pack File ����
// 0~3����Ʈ : Pack File�� ������ ���� (Big Endian)
// 4~7����Ʈ : Pack File�� ù��° ������ ��� ����Ʈ ��ġ (Big Endian)
// 8~11����Ʈ : Pack File�� ù��° ������ ����Ʈ �뷮 (Big Endian)
// 12~x����Ʈ : Pack File�� ù��° ������ �̸�
// x+1~y����Ʈ : Pack File�� ù��° ������ ������
// y+1~z����Ʈ : Pack FIle�� �ι�° ������ ��� ����Ʈ ��ġ (Big Endian)
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
	
	//���ο� �Լ����Դϴ�. ���������� �ǵ帮�� �ȵ˴ϴ�.
	int _GetFileCount();
	int _GetFilePos();
	int _GetFileSize();
	std::string _GetFileName(int IN_iFileDataPos);

	//GetFilePtr�� ���� ���Դϴ�. ���� ��ŷ������ ���� �ݴ� �Լ��Դϴ�.
	bool OpenFile(std::string IN_FileName);
	bool CloseFile();

public:
	FilePacker();
	~FilePacker();
	
	//Ư���� ������ �ִ� ��� ������ ��ŷ�մϴ�.
	void StoreFiles(std::string IN_FolderName, std::string IN_OutputPath);
	
	//��ŷ ���ϼ��� ��� ������ Ư���� ������ Ǳ�ϴ�.
	void ExtractFiles(std::string IN_FileName, std::string IN_OutputPath);

	//��ŷ ���ϼӿ��� ���ϴ� �ڷ��� �����Ϳ� ũ�⸦ ���մϴ�. �ڷᰡ ���� ��� OUT_Ptr�� OUT_Size�� NULL�� ��ȯ�մϴ�.
	bool GetFilePtr(std::string IN_FileName, std::string IN_DataName, char ** OUT_Ptr, int * OUT_Size);
	bool DeleteFilePtr();
};