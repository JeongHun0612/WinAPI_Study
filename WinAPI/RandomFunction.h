#pragma once
#include "SingletonBase.h"

class RandomFunction : public SingletonBase <RandomFunction>
{
public:
	RandomFunction()
	{
		// GetTickCount() : API ���� �Լ�
		// �� API �Լ��� OS�� ���õ� ���� ��� �ð��� üũ�� �ش�.
		// �� �и����� ������ üũ�� �����ϸ� �и����� ������ �ð� ���� ��ȯ�ϱ� ������ �Ը� ũ�� ���� ������ �����ϴ�.
		srand(GetTickCount());
	}
	~RandomFunction() {}

	inline int getInt(int num)
	{
		return rand() % num;
	}

	// 0�� ��������.
	inline int getFromIntTo(int fromNum, int toNum)
	{
		// fromNum �� toNum�� ������ ���� ����ó���� �ؾ� ������ ���ǽ��� ���� inlineȭ�� ���� ���� ���ɼ����ִ�.
		// �� ���� ���α׷��Ӱ� �Լ��� ����ϱ� ������ ���ܰ� �Ǵ� �Ű������� �ѱ��� �������̴�.
		return rand() % (toNum - fromNum + 1) + fromNum;
	}

	float getFloat(void)
	{
		return (float)rand() / (float)RAND_MAX;
	}

	float getFloat(float num)
	{
		return (float)rand() / (float)RAND_MAX * num;
	}

	float getFromFloatTo(float fromNum, float toNum)
	{
		float rnd = (float)rand() / (float)RAND_MAX;

		return (rnd * (toNum - fromNum) + fromNum);
	}
};