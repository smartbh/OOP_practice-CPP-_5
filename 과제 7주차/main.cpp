#include <iostream>
using namespace std;

class Matrix {
	int element[4];
public:
	Matrix(int a =0, int b =0, int c =0, int d =0)
	{
		element[0] = a;
		element[1] = b;
		element[2] = c;
		element[3] = d;
	}
	void show();
	Matrix operator+ (Matrix b);
	Matrix& operator += (Matrix b);
	/*friend Matrix operator+ (Matrix b);
	friend Matrix& operator+= (Matrix b);*/
	bool operator== (Matrix b);
};

Matrix Matrix::operator+ (Matrix b)
{
	Matrix tmp;
	int i;
	for (i = 0; i < 4; i++)
	{
		tmp.element[i] = this->element[i] + b.element[i];
	}

	return tmp;
}

Matrix& Matrix::operator+= (Matrix b) {
	int i;

	for (i = 0; i < 4; i++) 
	{
		this->element[i] = this->element[i] + b.element[i];
	}
	
	return *this;
}

// ¸â¹öÇÔ¼ö

/*Matrix operator+ (Matrix b)
{
	Matrix tmp;
	int i;
	for (i = 0; i < 4; i++)
	{
		tmp.element[i] = this->element[i] + b.element[i];
	}

	return tmp;
}

Matrix& operator+= (Matrix b) {
	int i;

	for (i = 0; i < 4; i++)
	{
		this->element[i] = this->element[i] + b.element[i];
	}

	return *this;
}
*/
//ÇÁ·»µå ÇÔ¼ö

bool Matrix::operator== (Matrix b)
{
	if (this->element[0] == b.element[0] &&
		this->element[1] == b.element[1] &&
		this->element[2] == b.element[2] &&
		this->element[3] == b.element[3])
	{
		return true;
	}

	else
		return false;
}

void Matrix::show() {
	cout << "Matrix = { " << element[0] << " " << element[1] << " " << element[2] << " " << element[3] << " }" << endl;
}

int main() 
{
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;

	a.show(); b.show(); c.show();

	if (a == c)
	{
		cout << "a and c are the same" << endl;
	}
}