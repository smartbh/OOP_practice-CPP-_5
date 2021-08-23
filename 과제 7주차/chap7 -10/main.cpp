#include <iostream>
using namespace std;

class Statistics {
	int *p;				//�迭�� �ޱ����� ����
	int count;			//���� ���� ���� ī����
public:
	Statistics() { p = new int[10], count = 0; }	//�⺻ ������ ���� �ִ� 10�� ������ �迭 �����Ҵ�

	~Statistics() { free(p); cout << "��谡 �Ҹ�Ǿ����ϴ�." << endl; } //���� �Ҵ� ���� �Ҹ��� ����

	bool operator ! ();

	Statistics& operator << (int n);			//�ڵ� 56�� �迭�� ���Ҹ� ��� Ŭ������ ����ֱ�

	void operator ~ ();			//����Լ�

	void operator >>(int& avg);		//��� ���ϱ����� ���� �Ű����� �Լ�
};

bool Statistics::operator ! () {
		if (count == 0)
			return true;

		else
			return false;
}

Statistics& Statistics:: operator << (int n) {

	p[count] = n;
	count++;		//count�� �⺻������ ����Ʈ�� 0���� ����. 56�ٿ��� �ݺ������� 0~4���� ����

	return *this;		//���� ����
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
	Statistics stat;	//�⺻ ������ �ʿ�

	if (!stat)
		cout << "���� ��� ����Ÿ�� �����ϴ�." << endl;

	int x[5];

	cout << "5���� ������ �Է��϶�>>";

	for (int i = 0; i < 5; i++)
		cin >> x[i];	//x[i] �� �����Է�

	for (int i = 0; i < 5; i++)
		stat << x[i];	//x[i] ���� ��� ��ü�� ����

	stat << 100 << 200;		//100, 200�� ��� ��ü�� ����

	~stat;	//��� ����Ÿ�� ��� ���

	int avg;

	stat >> avg;	//��� ��ü�κ��� ����� �޴´�.

	cout << "avg = " << avg << endl;	//����� ���
}





