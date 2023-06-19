#include "Stdafx.h"
#include "Report_MainGame.h"

#include "Report_CardMatch.h"
#include "Report_Mole.h"
#include "Report_ClayShooting.h"
#include "Report_Avoid.h"
#include "Report_BulletShooting.h"
#include "Report_Crocodile.h"

HRESULT Report_MainGame::init(void)
{
    GameNode::init();

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int idx = i * 2 + j;
            _gameTypeBtn[idx] = RectMakeCenter(200 + j * 300, 100 + i * 100, 150, 50);
        }
    }

    _EGameType = GAMETYPENULL;

    _gameName[0] = "짝 맞추기";
    _gameName[1] = "두더지 게임";
    _gameName[2] = "클레이 사격";
    _gameName[3] = "똥 피하기";
    _gameName[4] = "총알 발사";
    _gameName[5] = "악어 이빨 게임";

    _bIsInGame = false;

    return S_OK;
}

void Report_MainGame::release(void)
{
    GameNode::release();

    _mg->release();

    SAFE_DELETE(_mg);
}

void Report_MainGame::update(void)
{
    GameNode::update();

    if (_bIsInGame)
    {
        _mg->update();

        if (KEYMANAGER->isOnceKeyDown(VK_F1))
        {
            _bIsInGame = false;
        }
    }
    else
    {
        if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
        {
            for (int i = 0; i < MAX_GAMETYPE; i++)
            {
                if (PtInRect(&_gameTypeBtn[i], _ptMouse))
                {
                    _bIsInGame = true;
                    _EGameType = (GAMETYPE)i;

                    switch (_EGameType)
                    {
                    case CARDMATCHGAME:
                        _mg = new Report_CardMatch;
                        break;
                    case MOLEGAME:
                        _mg = new Report_Mole;
                        break;
                    case CLAYSHOOTING:
                        _mg = new Report_ClayShooting;
                        break;
                    case AVOIDGAME:
                        _mg = new Report_Avoid;
                        break;
                    case BULLETSHOOTING:
                        _mg = new Report_BulletShooting;
                        break;
                    case CROCODILETEETH:
                        _mg = new Report_Crocodile;
                        break;
                    default:
                        return;
                    }

                    _mg->init();
                }
            }
        }
    }
}

void Report_MainGame::render(HDC hdc)
{
    if (_bIsInGame)
    {
        _mg->render(hdc);
    }
    else
    {
        for (int i = 0; i < MAX_GAMETYPE; i++)
        {
            DrawRectMake(hdc, _gameTypeBtn[i]);

            //SetTextAlign(hdc, TA_CENTER);
            TextOut(hdc, 10 + _gameTypeBtn[i].left, 15 + _gameTypeBtn[i].top, _gameName[i], strlen(_gameName[i]));
        }
    }
}
