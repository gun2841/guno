#ifndef BUS_H
#define BUS_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct S{
	string str; // ���� ������
	int time; // ����ð�
	int run; //����ð�
	int charge; // �ݾ�
};
class BUS{
protected:
	vector<S> s1;
public:
	void schedule(void); // ���� ����,�뼱
	void timetable (char menu); // ���� �ð�
	void print(void);
	void reserve(string str, int time, int run, int charge);
	bool reservemenu(void);
	// �ð�ǥ
	void gangnam();
	void dongseoul();
	void sangbong();
	void dongdaegu();
	void busan();
	void southbusan();
	void gwangju();
	void sunsan();
	//�ð�ǥ

	BUS(); // ����Ʈ ������
	BUS(S* s1);//�����ִ� ������
	BUS(const BUS& bus); // ���������
	~BUS(); // �Ҹ���
};

#endif