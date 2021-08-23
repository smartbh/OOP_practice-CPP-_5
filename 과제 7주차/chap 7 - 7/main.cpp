#include <iostream>
using namespace std;

class Matrix {
	int element[4];			//원소가 네개니 배열도 네개
public:
	Matrix(int a = 0, int b = 0, int c = 0, int d = 0){		//기본 생성자를 위한 디폴트, 매개변수 있는 생성자 동시에
		element[0] = a;
		element[1] = b;
		element[2] = c;
		element[3] = d;
	}
	void show();
	void operator>> (int *x);
	void operator<< (int *x);
};

void Matrix::show() {
	cout << "Matrix = { " << element[0] << " " << element[1] << " " << element[2] << " " << element[3] << " }" << endl;
}

void Matrix::operator>> (int *x) {		//반복문으로 매개변수로 받은 배열에 각 대응 원소 집어넣기
	int i;
	for (i = 0; i < 4; i++)
	{
		x[i] = element[i];
	}
}

void Matrix::operator << (int *x) {		//반복문으로 매개변수로 받은 배열에 각 대응 원소 집어넣기
	int i;
	for (i = 0; i < 4; i++)
	{
		element[i] = x[i];
	}
}


int main() {
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,3,4 };	//2차원 행렬의 4개의 원소값
	a >> x;	//a의 각 원소를 배열 x에 복사. x[]는 {4,3,2,1}
	b << y;	// 배열 y의 원소값을 b의 각 원소에 설정.

	for (int i = 0; i < 4; i++)
		cout << x[i] << ' ';	//x[]출력
	cout << endl;
	b.show();
}