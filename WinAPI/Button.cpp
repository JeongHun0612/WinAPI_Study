#include "Stdafx.h"
#include "Button.h"
#include "Animation.h"

HRESULT Button::init(string text, float x, float y, int width, int height, BUTTON_STATE state, ButtonCallBack onClick, ButtonCallBack onHover)
{
	_state = state;
	_text = text;
	_x = x;
	_y = y;
	_rc = RectMakeCenter(_x, _y, width, height);

	return S_OK;
}

HRESULT Button::init(string imageName, float x, float y, BUTTON_STATE state, ButtonCallBack onClick, ButtonCallBack onHover)
{
	_state = state;
	_image = IMAGEMANAGER->findImage(imageName);

	_onClick = onClick;
	_onHover = onHover;

	_x = x;
	_y = y;
	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

	return S_OK;
}

HRESULT Button::init(string imageName, Animation* anim, float x, float y, BUTTON_STATE state, ButtonCallBack onClick, ButtonCallBack onHover)
{
	_state = state;
	_image = IMAGEMANAGER->findImage(imageName);

	_anim = anim;
	_anim->AniStart();

	_onClick = onClick;
	_onHover = onHover;

	_x = x;
	_y = y;
	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

	return S_OK;
}

void Button::release(void)
{
	if (_anim != nullptr)
	{
		SAFE_DELETE(_anim);
	}
}

void Button::update(void)
{
	if (_state != BUTTON_STATE::DISABLE)
	{
		// 애니메이션이 있을 시
		if (_anim != nullptr) _anim->frameUpdate(TIMEMANAGER->getElapsedTime() * 1);

		if (PtInRect(&_rc, _ptMouse))
		{
			if (_state == BUTTON_STATE::NORMAL)
			{
				_state = BUTTON_STATE::HOVER;

				if (_onHover)
				{
					callBackFunc(_onHover);
				}
				else
				{
					//if (_anim != nullptr) _anim->setPlayFrame(7, 12, false, true);

					_frameX = (int)BUTTON_STATE::HOVER;
				}
			}

			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				if (_onClick) callBackFunc(_onClick);
			}
		}
		else
		{
			if (_state != BUTTON_STATE::NORMAL)
			{
				_state = BUTTON_STATE::NORMAL;
				_frameX = (int)BUTTON_STATE::NORMAL;
			}
		}
	}
}

void Button::render(void)
{
	// 이미지가 없을 시
	if (!_image)
	{
		DrawRectMake(getMemDC(), _rc);

		TextOut(getMemDC(), _x - (_text.length() / 2 * 9), _y - 8, _text.c_str(), _text.length());
	}

	// 이미지가 있을 시
	else
	{
		// 애니메이션이 있을 시
		if (_anim != nullptr)
		{
			_image->aniRender(getMemDC(), _rc.left, _rc.top, _anim);
		}
		else
		{
			_image->frameRender(getMemDC(), _rc.left, _rc.top, _frameX, _frameY);
		}
	}
}

void CALLBACK Button::callBackFunc(ButtonCallBack callbackFunc)
{
	callbackFunc();
}