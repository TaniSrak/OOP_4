#include <iostream>
#include <string>
#include <fstream>

//операторы и специаьные окнструкторы копирования в классах
class Integer 
{
public:
	Integer():data_(0){}
	Integer(int num):data_(num){}

	//перегрузка оператора в виде дружественного члена клаасса
	friend Integer operator + (Integer A, Integer B)
	{
		Integer result;
		result.data_ = A.data_ + B.data_; //посчитали
		return result;
		//или
		// return Integer(this->data_ + obj.data_);
	}
	//дружественная для +
	friend std::ostream& operator << (
		std::ostream& out,
		const Integer& obj) //obj - объект класса
	{
		return out << obj.data_;
	}
	int GetNum()
	{
		return data_;
	}
	//перегрузка оператора как метода класса
	Integer& operator= (const Integer& other)
	{
		this->data_ = other.data_;
		return *this;
	}

private:
	int data_;
	//реализации для математически достоверного числа, чтобы прям сильно точно было
	/*bool sign_; где bool - либо да либо нет, ноль либо единица
	unsigned long long units_;*/


};

//внешняя перегрузка оператора для - ,как независимая функция
Integer operator-(Integer a, Integer b)
{
	return a.GetNum() - b.GetNum();
}
//внешняя перегрузка для * ,как независимая функция
Integer operator*(Integer a, Integer b)
{
	return a.GetNum() * b.GetNum();
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n{ 5 };
	int a{ 10 };

	//std::cout << 'q' << 3 << "qwerty" << 5 + 9;

	std::cout << a + n << std::endl;
	std::cout << a - n << std::endl;
	std::cout << a * n << std::endl;
//========================
	std::cout << a + 5 << std::endl;
	std::cout << a - 5 << std::endl;
	std::cout << a * 5 << std::endl;
//=========================
	std::cout << 4 + n << std::endl; //это дружественная функция
	std::cout << a - 2 << std::endl;
	std::cout << 7 * n << std::endl;

	Integer c;



	return 0;
}