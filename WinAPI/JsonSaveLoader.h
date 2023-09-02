//#pragma once
//#include "SingletonBase.h"
//
//#pragma region 제이슨 (JSON)
///*
//▶ JSON (JavaScript Object Notation)
//
//- 제이슨은 객체의 구조와 속성을 텍스트 형식으로 전달하기 위해 고안된 형식이며 데이터 교환의 표준 
//	ㄴ 기본적으로 자바 스크립트 기반 표준 표기법이지만 다양한 언어를 지원하기 때문에 확장성 ↑
//	ㄴ 주로 인터넷에서 데이터를 주고 받을 때 그 자료를 표현하는 방법으로 많이 활용이 된다.
//	ㄴ 텍스트 형식이기 때문에 사람에게도 아주 좋은 포맷
//		ㄴ 문자열 기반이기 때문에 오버헤드 적용
//
//- 제이슨은 자료의 종료에 큰 제한은 없으며 특히 컴퓨터 프로그램의 변수값을 표현하는데 적합
//
//- 형식 자체가 자바 스크립트의 구문 형식을 따르지만 프로그래밍 언어나 "플랫폼"에 독립적으로
//C / C++, C#, Java,  JavaScript, 펄, Python 등등.. 많은 언어에서 이용할 수 있다.
//
//- CSV, XML, HTML -> JSON이 "일반적인" 상황에서는 더 빠르다.
//ㄴ 데이터의 형식과 성능을 고려하면 JSON은 기본적으로 XML이라는 마크업 언어와 항상 고민을 하게 한다.
//
//- 제이슨 형식에서 사용하는 기호
//
//{}		: 객체
//키 / 값 : 객체가 가지는 속성
//""		: 문자열 데이터
//[]		: 배열
//
//
//- C++ -> JSON -> ( JsonCPP / Rapid Json )
//ㄴ 속도면에서는 Rapid Json이 유리
//ㄴ JsonCPP이 메모리 사용량이 적다.
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