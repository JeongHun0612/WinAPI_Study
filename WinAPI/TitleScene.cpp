#include "Stdafx.h"
#include "TitleScene.h"

HRESULT TitleScene::init(void)
{
	Button sceneBtn;

	SOUNDMANAGER->play("타이틀", 1.0f);

	// 과제 씬 버튼 등록 ===============================================================================================================
	sceneBtn.init("짝 맞추기", REPORT_START_X + (WIDTH + INTERVAL_X) * 0, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	//sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("짝 맞추기"); });

	sceneBtn.setOnClick(bind(testFunc, "짝 맞추기"));

	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("두더지 게임", REPORT_START_X + (WIDTH + INTERVAL_X) * 1, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("두더지 게임"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("클레이 사격", REPORT_START_X + (WIDTH + INTERVAL_X) * 2, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("클레이 사격"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("똥 피하기", REPORT_START_X + (WIDTH + INTERVAL_X) * 3, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("똥 피하기"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("총알 발사", REPORT_START_X + (WIDTH + INTERVAL_X) * 4, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("총알 발사"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("악어 이빨 게임", REPORT_START_X + (WIDTH + INTERVAL_X) * 5, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("악어 이빨 게임"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("종스크롤 슈팅", REPORT_START_X + (WIDTH + INTERVAL_X) * 0, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("종스크롤 슈팅"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("횡스크롤 슈팅", REPORT_START_X + (WIDTH + INTERVAL_X) * 1, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("횡스크롤 슈팅"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("두더지 게임(이미지)", REPORT_START_X + (WIDTH + INTERVAL_X) * 2, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("두더지 게임(이미지)"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("아날로그 시계", REPORT_START_X + (WIDTH + INTERVAL_X) * 3, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("아날로그 시계"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("포탄 발사", REPORT_START_X + (WIDTH + INTERVAL_X) * 4, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("포탄 발사"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("총알 중력", REPORT_START_X + (WIDTH + INTERVAL_X) * 5, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("총알 중력"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("이미지 슬라이스", REPORT_START_X + (WIDTH + INTERVAL_X) * 0, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 2, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("이미지 슬라이스"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("미니맵", REPORT_START_X + (WIDTH + INTERVAL_X) * 1, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 2, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("미니맵"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("지렁이 게임", REPORT_START_X + (WIDTH + INTERVAL_X) * 2, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 2, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("지렁이 게임"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("공격 콤보 모션", REPORT_START_X + (WIDTH + INTERVAL_X) * 3, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 2, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("공격 콤보 모션"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("벽 잡기", REPORT_START_X + (WIDTH + INTERVAL_X) * 4, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 2, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("벽 잡기"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("레이싱 게임", REPORT_START_X + (WIDTH + INTERVAL_X) * 5, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 2, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("레이싱 게임"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("블랙홀", REPORT_START_X + (WIDTH + INTERVAL_X) * 0, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 3, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("블랙홀"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("공격 및 방어", REPORT_START_X + (WIDTH + INTERVAL_X) * 1, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 3, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("공격 및 방어"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("3D Matrix", REPORT_START_X + (WIDTH + INTERVAL_X) * 2, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 3, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("3D Matrix"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("타일맵", REPORT_START_X + (WIDTH + INTERVAL_X) * 3, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 3, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("타일맵"); });
	_vSceneBtn.push_back(sceneBtn);


	// 수업 예제 씬 버튼 등록 ===============================================================================================================

	sceneBtn.init("두더지 예제", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 0, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("두더지 예제"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("총알 발사", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 1, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("총알 발사"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("삼각 함수", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 2, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("삼각 함수"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("이미지 출력", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 3, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("이미지 출력"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("클리핑 이미지", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 4, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("클리핑 이미지"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("프레임 이미지", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 5, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("프레임 이미지"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("루프 이미지", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 0, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("루프 이미지"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("사운드 재생", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 1, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("사운드 재생"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("슈팅 게임", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 2, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("슈팅 게임"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("텐가이", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 3, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("텐가이"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("애니메이션", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 4, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("애니메이션"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("INI 데이터", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 5, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("INI 데이터"); });
	_vSceneBtn.push_back(sceneBtn);

	return S_OK;
}

void TitleScene::release(void)
{
}

void TitleScene::update(void)
{
	for (_viSceneBtn = _vSceneBtn.begin(); _viSceneBtn != _vSceneBtn.end(); ++_viSceneBtn)
	{
		_viSceneBtn->update();
	}
}

void TitleScene::render(void)
{
	TextOut(getMemDC(), 20, 20, "과제 파일", strlen("과제 파일"));
	LineMake(getMemDC(), 0, 50, WINSIZE_X, 50);

	TextOut(getMemDC(), 20, WINSIZE_Y / 2 + 70, "수업 파일", strlen("수업 파일"));
	LineMake(getMemDC(), 0, WINSIZE_Y / 2 + 100, WINSIZE_X, WINSIZE_Y / 2 + 100);

	for (_viSceneBtn = _vSceneBtn.begin(); _viSceneBtn != _vSceneBtn.end(); ++_viSceneBtn)
	{
		_viSceneBtn->render();
	}
}

void TitleScene::testFunc(string sceneName)
{
	SCENEMANAGER->changeScene(sceneName);
}
