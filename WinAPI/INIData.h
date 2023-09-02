#pragma once
#include "SingletonBase.h"

#pragma region ���� ����� (ini)
/*

�� INI (Initialization)

- ���� ���α׷��̳� ������ ��ü�� �ʱ� ������ �ʿ��� ������ ���Ե� �ؽ�Ʈ ����

- INI ������ ���� ���Ͽ� ���� ��ǻ� ǥ���̶�� ������ �� �ִ�.
�� ��ü�� �� �ִ� ������ �����ϰ� ���� ������ �����Ҷ� ���� �����ϱ� ����
�� ���� �ܼ� ������ �ؽ�Ʈ ���Ϸ� ������ �Ǿ� �ִٴ� Ư¡�� �ִ�.
�� �ؽ�Ʈ ������ ������ ������ �ֱ� ������ Ȯ���� ��ȯ�� ����� �Ѵ�. (��, txt�� ���ؼ�)

- INI ������ ����ũ�μ���Ʈ�� ���� OS�� ������� ������ ������ �ٸ� �ü�������� ����� �� �� �ִ�.

- �Ϲ������� ���α׷��� ����ɶ� �ش�Ǵ� INI ������ ���ؼ� ���α׷��� ���࿡ �ʿ��� �⺻ ������ �о� ���̸鼭 ������ �ȴ�.


�� ���ӿ����� ���� ����ؾ� �ϴ°�?

- �����ʿ����� �ɼ� � ���� ����� �ǰ� ��� ������ ��� ���� �������� ������ ���忡 ���ȴ�.

- �����ʿ��� INI ������ �ַ� ���� ���� �ٲ�� ��쿡 ����ϸ� ����.

�� INI �ϸ� ���ø� 3����

- ���ǰ� Ű, �׸��� ��

- �Ϲ����� ���� (Ŀ���� X)

[Section] - ���ȣ ������ ���� ini�������� ������ ����
Key = Value

- Ŀ���� ���� (��� ����)
[Section]
Path = Value (C:\.....)
LifeTime = key (1) /  = 1

*/
#pragma endregion

struct tagIniData
{
	char* section;
	char* key;
	char* value;
};

class INIData : public SingletonBase<INIData>
{
private:
	typedef vector<tagIniData> arrIniData;
	typedef vector<arrIniData> arrIniDatas;

private:
	arrIniDatas _vIniData;

public:
	HRESULT init(void);
	void release(void);


	// ������ �߰� -> 
	void addData(char* section, char* key, char* value);
	// ���̺�
	void iniSave(char* fileName);

	// ���ڰ�
	char* loadDataString(char* fileName, char* section, char* key);
	// ����
	int loadDataInteger(char* fileName, char* section, char* key);


	INIData() {}
	~INIData() {}
};

