#include <iostream>

int main()
{
	using namespace std;

	double kilo, gasoline;

	double sum, mile, gallon;

	kilo = 0;
	gasoline = 0;

	cout << "������ �Ÿ�: ";
	cin >> kilo;

	cout << "�Һ��� �ֹ��� (���ʹ����� �Է�): ";
	cin >> gasoline;

	sum = double(gasoline) / double(kilo) * 100;

	cout << "100ų�ι��ʹ� ���� ��: " << sum  <<  "L \n";

	mile = kilo * 0.6214;

	gallon = gasoline * 3.875;

	cout << "100ų�ι��ʹ� ���� ���� �̱� ������ ǥ���ϸ�: " << mile / gallon << "mpg" << '\n';



	return 0;

}