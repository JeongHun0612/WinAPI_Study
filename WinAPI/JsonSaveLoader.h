//#pragma once
//#include "SingletonBase.h"
//
//#pragma region ���̽� (JSON)
///*
//�� JSON (JavaScript Object Notation)
//
//- ���̽��� ��ü�� ������ �Ӽ��� �ؽ�Ʈ �������� �����ϱ� ���� ��ȵ� �����̸� ������ ��ȯ�� ǥ�� 
//	�� �⺻������ �ڹ� ��ũ��Ʈ ��� ǥ�� ǥ��������� �پ��� �� �����ϱ� ������ Ȯ�强 ��
//	�� �ַ� ���ͳݿ��� �����͸� �ְ� ���� �� �� �ڷḦ ǥ���ϴ� ������� ���� Ȱ���� �ȴ�.
//	�� �ؽ�Ʈ �����̱� ������ ������Ե� ���� ���� ����
//		�� ���ڿ� ����̱� ������ ������� ����
//
//- ���̽��� �ڷ��� ���ῡ ū ������ ������ Ư�� ��ǻ�� ���α׷��� �������� ǥ���ϴµ� ����
//
//- ���� ��ü�� �ڹ� ��ũ��Ʈ�� ���� ������ �������� ���α׷��� �� "�÷���"�� ����������
//C / C++, C#, Java,  JavaScript, ��, Python ���.. ���� ���� �̿��� �� �ִ�.
//
//- CSV, XML, HTML -> JSON�� "�Ϲ�����" ��Ȳ������ �� ������.
//�� �������� ���İ� ������ ����ϸ� JSON�� �⺻������ XML�̶�� ��ũ�� ���� �׻� ����� �ϰ� �Ѵ�.
//
//- ���̽� ���Ŀ��� ����ϴ� ��ȣ
//
//{}		: ��ü
//Ű / �� : ��ü�� ������ �Ӽ�
//""		: ���ڿ� ������
//[]		: �迭
//
//
//- C++ -> JSON -> ( JsonCPP / Rapid Json )
//�� �ӵ��鿡���� Rapid Json�� ����
//�� JsonCPP�� �޸� ��뷮�� ����.
//
//*/
//#pragma endregion
//
//class JsonSaveLoader : public SingletonBase<JsonSaveLoader>
//{
//private:
//	void saveString(char* fileName, string data);
//	void saveStringWithFileStream(char* fileName, string data);
//
//	string loadString(char* fileName);
//	string loadStringWithFileStream(char* fileName);
//
//public:
//	HRESULT init(void);
//	void release(void);
//	void saveJsonFile(char* fileName, Json::Value root);
//
//	Json::Value loadJsonFile(char* fileName);
//
//	JsonSaveLoader() {}
//	~JsonSaveLoader() {}
//};