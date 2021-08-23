#include <iostream>
using namespace std;

class Statistics {
	int *p;
	int count;
public:
	Statistics() { p = new int[10]; count = 0; }	//�⺻ ������

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
	Statistics stat;	//�⺻ ������ �ʿ�
	if (!stat)
		cout << "���� ��� ����Ÿ�� �����ϴ�." << endl;

	int x[5];
	cout << "5���� ������ �Է��϶�>>";

	for (int i = 0; i < 5; i++)
		cin >> x[i];	//x[i] �� �����Է�

	for (int i = 0; i < 5; i++)
		stat << x[i];	//x[i] ���� ��� ��ü�� �����Ѵ�.

	stat << 100 << 200;		//100, 200�� ��� ��ü�� �����Ѵ�.

	~stat;	//��� ����Ÿ�� ��� ����Ѵ�.

	int avg;

	stat >> avg;	//��� ��ü�κ��� ����� �޴´�.

	cout << "avg = " << avg << endl;	//����� ����Ѵ�.
}





