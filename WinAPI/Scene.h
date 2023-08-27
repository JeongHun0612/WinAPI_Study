#pragma once

//class SceneManager;

class Scene
{
	// ���������� �㹫�� Ű����
	// ����ϱ��� ���� friend Ű���带 ��߸� �ߴ��� Ȯ���� Ȯ���� �ʿ�
	// ������ Ŭ������ �ֻ��� Ŭ������ �����ؼ� �����͸� �ٲ��� �� �߰��� �ִ� Ŭ�����鿡�� ��� ���� �߻����� ��
	// friend�� �ܹ����� �⺻
	// private�� ������ ������

	/*
	friend : �� �״�� ģ��
	�� ������ ��� �������� �Ǵ� ȿ������ ������ ������ �� ���� ����Ѵ�.
	*/

	//friend SceneManager;

private:
	// �������̽� Ŭ�������� ���ؿ� �ö󰡴� �Լ��� �����ϴ� �̷��� ������ �����ϴ�. (����)
	void init(int a);

	virtual void init() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void exit() = 0;

protected:

public:

	Scene();
	virtual ~Scene();
};