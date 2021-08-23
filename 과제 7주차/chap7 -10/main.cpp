#include <iostream>
using namespace std;

class Statistics {
	int *p;				//배열을 받기위한 변수
	int count;			//숫자 세기 위한 카운터
public:
	Statistics() { p = new int[10], count = 0; }	//기본 생성자 대충 최대 10개 정수형 배열 동적할당

	~Statistics() { free(p); cout << "통계가 소멸되었습니다." << endl; } //동적 할당 받은 소멸자 실행

	bool operator ! ();

	Statistics& operator << (int n);			//코드 56줄 배열의 원소를 통계 클래스에 집어넣기

	void operator ~ ();			//출력함수

	void operator >>(int& avg);		//평균 구하기위한 참조 매개변수 함수
};

bool Statistics::operator ! () {
		if (count == 0)
			return true;

		else
			return false;
}

Statistics& Statistics:: operator << (int n) {

	p[count] = n;
	count++;		//count는 기본생성자 디폴트로 0에서 시작. 56줄에서 반복문으로 0~4까지 증가

	return *this;		//참조 리턴
}

void Statistics ::operator ~ () {

	for (int i = 0; i< count; i++)
		cout << p[i] << ' '; 
	
	cout << endl;
}

void Statistics::operator >>(int& avg) {

	int sum = 0;

	for (int i = 0; i< count; i++)
		sum += p[i];

	avg = sum / count;
}



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
		stat << x[i];	//x[i] 값을 통계 객체에 삽입

	stat << 100 << 200;		//100, 200을 통계 객체에 삽입

	~stat;	//통계 데이타를 모두 출력

	int avg;

	stat >> avg;	//통계 객체로부터 평균을 받는다.

	cout << "avg = " << avg << endl;	//평균을 출력
}





