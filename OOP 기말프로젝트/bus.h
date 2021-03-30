#ifndef BUS_H
#define BUS_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct S{
	string str; // 운행 목적지
	int time; // 예약시간
	int run; //운행시간
	int charge; // 금액
};
class BUS{
protected:
	vector<S> s1;
public:
	void schedule(void); // 버스 운행,노선
	void timetable (char menu); // 운행 시간
	void print(void);
	void reserve(string str, int time, int run, int charge);
	bool reservemenu(void);
	// 시간표
	void gangnam();
	void dongseoul();
	void sangbong();
	void dongdaegu();
	void busan();
	void southbusan();
	void gwangju();
	void sunsan();
	//시간표

	BUS(); // 디폴트 생성자
	BUS(S* s1);//인자있는 생성자
	BUS(const BUS& bus); // 복사생성자
	~BUS(); // 소멸자
};

#endif