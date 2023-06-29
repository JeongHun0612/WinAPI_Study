#include "Stdafx.h"
#include "Report_17_2_MainGame.h"

/*
���� 2. ������ �̹��� ó��

- ���� �� + ���� ��

- ���Ӿ������� �Ʒ��� �̹����� GUIȭ ���Ѽ� ��� ��Ų��. (��ư)
�� ������ ����)

- �ʼ� �̹���
�� ���, ���, �̵� (�� + ��), ��� (�� + ��), �밢�� ���,
	���� ��� (�� + ��), �� ������, �¸� ���� (�� ������), ��ų Ŭ���̸��� ����, �й�
*/

HRESULT Report_17_2_MainGame::init(void)
{
	GameNode::init();

	for (int i = 0; i < MAX_MOTION; i++)
	{
		_motionBtn[i].idx = i;
		_motionBtn[i].rc = RectMake(50 + (i / 5) * 980, 50 + (i % 5) * 155, 200, 80);

		_motionImage[i].motion = new GImage;
	}

	_skillScene = new GImage;
	_skillScene->init("Resources/Images/Motion/Skill_Scene.bmp", 0.0f, 0.0f, WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

	_motionImage[0].motion->init("Resources/Images/Motion/Idle.bmp", WINSIZE_X / 2, WINSIZE_Y / 2, 3357, 393, 9, 1, true, RGB(255, 0, 255));
	_motionImage[1].motion->init("Resources/Images/Motion/Move.bmp", WINSIZE_X / 2, WINSIZE_Y / 2, 3114, 778, 9, 2, true, RGB(255, 0, 255));
	_motionImage[2].motion->init("Resources/Images/Motion/Sting.bmp", WINSIZE_X / 2, WINSIZE_Y / 2, 5872, 698, 8, 2, true, RGB(255, 0, 255));
	_motionImage[3].motion->init("Resources/Images/Motion/Diagonal_Sting.bmp", WINSIZE_X / 2, WINSIZE_Y / 2, 3150, 1000, 7, 2, true, RGB(255, 0, 255));
	_motionImage[4].motion->init("Resources/Images/Motion/Double_Sting.bmp", WINSIZE_X / 2, WINSIZE_Y / 2, 7568, 638, 11, 2, true, RGB(255, 0, 255));
	_motionImage[5].motion->init("Resources/Images/Motion/Turn_Circle.bmp", WINSIZE_X / 2, WINSIZE_Y / 2, 5490, 800, 9, 1, true, RGB(255, 0, 255));
	_motionImage[6].motion->init("Resources/Images/Motion/Victory.bmp", WINSIZE_X / 2, WINSIZE_Y / 2, 16401, 430, 21, 1, true, RGB(255, 0, 255));
	_motionImage[7].motion->init("Resources/Images/Motion/Lose.bmp", WINSIZE_X / 2, WINSIZE_Y / 2, 3402, 728, 9, 2, true, RGB(255, 0, 255));
	_motionImage[8].motion->init("Resources/Images/Motion/Skill.bmp", WINSIZE_X / 2, WINSIZE_Y / 2, 10500, 600, 14, 1, true, RGB(255, 0, 255));

	wsprintf(_motionBtn[0].name, "���");
	wsprintf(_motionBtn[1].name, "�̵�");
	wsprintf(_motionBtn[2].name, "���");
	wsprintf(_motionBtn[3].name, "�밢�� ���");
	wsprintf(_motionBtn[4].name, "���� ���");
	wsprintf(_motionBtn[5].name, "�� ������");
	wsprintf(_motionBtn[6].name, "�¸� ����");
	wsprintf(_motionBtn[7].name, "�й� ����");
	wsprintf(_motionBtn[8].name, "��ų ����");
	wsprintf(_motionBtn[9].name, "");

	_motionType = EMOTION_TYPE::MOVE;

	_count = _index = 0;
	_alpha = 0;
	_currentIdx = (int)_motionType;

	_isLeft = true;

	return S_OK;
}

void Report_17_2_MainGame::release(void)
{
	GameNode::release();
}

void Report_17_2_MainGame::update(void)
{
	GameNode::update();

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && _motionImage[_currentIdx].motion->getMaxFrameY() == 1)
	{
		_isLeft = true;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && _motionImage[_currentIdx].motion->getMaxFrameY() == 1)
	{
		_isLeft = false;
	}

	// ��ư Ŭ��
	for (int i = 0; i < MAX_MOTION - 1; i++)
	{
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON) && PtInRect(&_motionBtn[i].rc, _ptMouse))
		{
			_currentIdx = _motionBtn[i].idx;
			_skillScene->setX((float)WINSIZE_X);
			_count = 0;
			_alpha = 0;
		}
	}

	// ��ų ����
	if (_currentIdx == (int)EMOTION_TYPE::SKILL)
	{
		_skillScene->setX(_skillScene->getX() - 8.0f);

		_alpha += 2;

		if (_alpha > 255)
		{
			_alpha = 255;
		}

		if (_skillScene->getX() <= 0)
		{
			_alpha = 0;
			_skillScene->setX((float)WINSIZE_X);
		}
	}

	// �̹��� ������ ����
	if (_isLeft)
	{
		_count++;

		_motionImage[_currentIdx].motion->setFrameY(0);

		if (_count % 5 == 0)
		{
			_index++;

			if (_index > _motionImage[_currentIdx].motion->getMaxFrameX())
			{
				_index = 0;
			}

			_motionImage[_currentIdx].motion->setFrameX(_index);
		}
	}
	else
	{
		_count++;

		_motionImage[_currentIdx].motion->setFrameY(1);

		if (_count % 5 == 0)
		{
			_index--;

			if (_index < 0)
			{
				_index = _motionImage[_currentIdx].motion->getMaxFrameX();
			}

			_motionImage[_currentIdx].motion->setFrameX(_index);
		}
	}

}

void Report_17_2_MainGame::render(HDC hdc)
{
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// ==========================================================

	for (int i = 0; i < MAX_MOTION; i++)
	{
		DrawRectMake(memDC, _motionBtn[i].rc);
		SetTextAlign(memDC, TA_CENTER);
		TextOut(memDC, _motionBtn[i].rc.left + 100, _motionBtn[i].rc.top + 35, _motionBtn[i].name, strlen(_motionBtn[i].name));
	}

	_motionImage[_currentIdx].motion->frameRender(memDC,
		_motionImage[_currentIdx].motion->getX() - _motionImage[_currentIdx].motion->getFrameWidth() / 2,
		_motionImage[_currentIdx].motion->getY() - _motionImage[_currentIdx].motion->getFrameHeight() / 2);

	if (_currentIdx == (int)EMOTION_TYPE::SKILL)
	{
		_skillScene->alphaRender(memDC, _skillScene->getX(), _skillScene->getY(), _alpha);
	}


	// ==========================================================
	this->getDoubleBuffer()->render(hdc, 0, 0);
}
