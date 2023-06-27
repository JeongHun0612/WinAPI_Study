#pragma once

/*
1. ����
2. ���İ� ����
3. Ŭ���� (Clipping) - ����ȭ �߻�
4. ������ / �ִϸ��̼�
5. ���� / ������
*/

// GDI Image
class GImage 
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE = 0, LOAD_FILE,		// ���ҽ�, ����
		LOAD_EMPTY, LOAD_END				// �� ��Ʈ��, �ε� Done
	};

	typedef struct tagImage
	{
		DWORD		resID;
		HDC			hMemDC;
		HBITMAP		hBit;
		HBITMAP		hOBit;
		int			width;
		int			height;
		BYTE		loadType;

		tagImage()
		{
			resID = 0;
			hMemDC = NULL;
			hBit = NULL;
			hOBit = NULL;
			width = 0;
			height = 0;
			loadType = LOAD_RESOURCE;
		}
	}IMAGE_INFO, * LPIMAGE_INFO;

private:
	LPIMAGE_INFO	_imageInfo;
	char*			_fileName;
	bool			_isTrans;		// ���ٰ���?

	/*
	COLORREF

	- ��������� ������ ǥ���ϱ� ���� ��ȣ���� 32bit ������
	�� R, G, B ���� 1����Ʈ (8bit)�̸� 0 ~ 255������ ���� ǥ���ϴµ� ����ȭ �Ǿ� �ִ�.
	*/
	COLORREF		_transColor;	// ���� RGB �� (����Ÿ = RGB(255, 0, 255))

	BLENDFUNCTION _blendFunc;		// ���ĺ��� ���
	LPIMAGE_INFO _blendImage;		// ���ĺ��� �̹���

public:
	HRESULT init(int width, int height);

	// �̹��� ���ҽ��� �ʱ�ȭ
	HRESULT init(const DWORD resID, int width, int height, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));

	// �̹��� ���Ϸ� �ʱ�ȭ
	HRESULT init(const char* fileName, int width, int height, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));

	// ���� �̹��� �ʱ�ȭ
	HRESULT initForAlphaBlend(void);

	// ���� �÷�Ű ����
	void setTransColor(bool isTrans, COLORREF transColor);

	// ����
	void release(void);

	// ����
	void render(HDC hdc);
	void render(HDC hdc, int destX, int destY);

	//�̹��� Ŭ����
	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);
	void render(HDC hdc, int destX, int destY, int destWidt, int destHeight, int sourX, int sourY, int sourWidth, int sourHeight);

	// ���ķ���
	void alphaRender(HDC hdc, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);

	// = �ζ��� �Լ� = 
	inline HDC getMemDC(void) { return _imageInfo->hMemDC; }

	GImage();
	~GImage() {}
};

