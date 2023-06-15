#pragma once
class Report_06_GameNode
{
private:

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(HDC hdc);

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

	Report_06_GameNode() {}
	virtual ~Report_06_GameNode() {}
};

