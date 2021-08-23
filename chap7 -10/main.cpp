#include <iostream>
using namespace std;

class Statistics {
	int *p;
	int count;
public:
	Statistics() { p = new int[10]; count = 0; }	//기본 생성자

	bool operator ! () {

		if (count == 0) return true; else return false; 

	}

	Statistics& operator << (int n) {

		p[count] = n; count++; 
		
		return *this; 
	};

	void operator ~ () {

		for (int i = 0; i< count; i++) 
			cout << p[i] << ' '; cout << endl; 
	}

	void operator >>(int& avg) { 

		int sum = 0; 

		for (int i = 0; i< count; i++) 
			sum += p[i]; avg = sum / count; 
	}
};

int main()
{
	Statistics stat;	//기본 생성자 필요
	if (!stat)
		cout << "현재 통계 데이타가 없습니다." << endl;

	int x[5];
	cout << "5개의 정수를 입력하라>>";

	for (int i = 0; i < 5; i++)
		cin >> x[i];	//x[i] 에 정수입력

	for (int i = 0; i < 5; i++)
		stat << x[i];	//x[i] 값을 통계 객체에 삽입한다.

	stat << 100 << 200;		//100, 200을 통계 객체에 삽입한다.

	~stat;	//통계 데이타를 모두 출력한다.

	int avg;

	stat >> avg;	//통계 객체로부터 평균을 받는다.

	cout << "avg = " << avg << endl;	//평균을 출력한다.
}





