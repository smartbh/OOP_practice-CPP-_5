#include <iostream>
using namespace std;

class Matrix {
	int element[4];			//���Ұ� �װ��� �迭�� �װ�
public:
	Matrix(int a = 0, int b = 0, int c = 0, int d = 0){		//�⺻ �����ڸ� ���� ����Ʈ, �Ű����� �ִ� ������ ���ÿ�
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

void Matrix::operator>> (int *x) {		//�ݺ������� �Ű������� ���� �迭�� �� ���� ���� ����ֱ�
	int i;
	for (i = 0; i < 4; i++)
	{
		x[i] = element[i];
	}
}

void Matrix::operator << (int *x) {		//�ݺ������� �Ű������� ���� �迭�� �� ���� ���� ����ֱ�
	int i;
	for (i = 0; i < 4; i++)
	{
		element[i] = x[i];
	}
}


int main() {
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,3,4 };	//2���� ����� 4���� ���Ұ�
	a >> x;	//a�� �� ���Ҹ� �迭 x�� ����. x[]�� {4,3,2,1}
	b << y;	// �迭 y�� ���Ұ��� b�� �� ���ҿ� ����.

	for (int i = 0; i < 4; i++)
		cout << x[i] << ' ';	//x[]���
	cout << endl;
	b.show();
}