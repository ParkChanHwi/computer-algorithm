#include <iostream>
#include<random>
using namespace std;

int main() {
	// 난수 생성
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(1, 99);

	int number = distrib(gen);

	while (1)
	{
		int guess;
		cout << "랜덤 숫자를 맞춰보세요! 1~99" << endl;
		cin >> guess;


		if (guess == number) {

			cout << "정답입니다!" << endl;
			cout << "정답 : " << number << endl;
			break;
		}
		else if (guess > number) {
			cout << "추측한 숫자보다 작습니다." << endl;
		}

		else if (guess <  number) {
			cout << "추측한 숫자보다 큽니다." << endl;
		}
	}

}