#include <iostream>
#include<random>
using namespace std;

int main() {
	// ���� ����
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(1, 99);

	int number = distrib(gen);

	while (1)
	{
		int guess;
		cout << "���� ���ڸ� ���纸����! 1~99" << endl;
		cin >> guess;


		if (guess == number) {

			cout << "�����Դϴ�!" << endl;
			cout << "���� : " << number << endl;
			break;
		}
		else if (guess > number) {
			cout << "������ ���ں��� �۽��ϴ�." << endl;
		}

		else if (guess <  number) {
			cout << "������ ���ں��� Ů�ϴ�." << endl;
		}
	}

}