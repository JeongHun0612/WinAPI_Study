#include "Stdafx.h"
#include "Example_Animation.h"

/*
과제 1. SVN or Git 점검

- SVN or Git 사용법을 터득해서 X자 모양이 되도록 팀원끼리 대화를 나눈다.

- 작업 이력 캡처해서 같이 제출

과제 2. 애니메이션 클래스에 속한 함수 완성

- 미완성 함수 완성 시키기

ㄴ setPlayFrame()
ㄴ setPlayFrame()
ㄴ setFPS()

과제 3. 세미 포트폴리오 선행 작업 (코드 X -> 이미지)
*/

HRESULT Example_Animation::init(void)
{
    _image = IMAGEMANAGER->addImage("코끼리", "Resources/Images/Object/Elephant.bmp", 660, 268, true, RGB(255, 0, 255));

    _animationA = new Animation;
    _animationA->init(_image->getWidth(), _image->getHeight(), 110, 67);
    _animationA->setDefPlayFrame(false, true);
    _animationA->setFPS(0.2);

    return S_OK;
}

void Example_Animation::release(void)
{
    _animationA->release();
    SAFE_DELETE(_animationA);
}

void Example_Animation::update(void)
{
    if (KEYMANAGER->isOnceKeyDown('B'))
    {
        _animationA->AniStart();
    }

    _animationA->frameUpdate(TIMEMANAGER->getElapsedTime() * 1);
}

void Example_Animation::render(void)
{
    _image->aniRender(getMemDC(), WINSIZE_X_HALF - 50, WINSIZE_Y_HALF, _animationA);
}
