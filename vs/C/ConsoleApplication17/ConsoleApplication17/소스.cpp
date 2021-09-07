#include <iostream>

int main()
{
	using namespace std;

	double kilo, gasoline;

	double sum, mile, gallon;

	kilo = 0;
	gasoline = 0;

	cout << "주행한 거리: ";
	cin >> kilo;

	cout << "소비한 휘발유 (리터단위로 입력): ";
	cin >> gasoline;

	sum = double(gasoline) / double(kilo) * 100;

	cout << "100킬로미터당 리터 수: " << sum  <<  "L \n";

	mile = kilo * 0.6214;

	gallon = gasoline * 3.875;

	cout << "100킬로미터당 리터 수를 미국 식으로 표현하면: " << mile / gallon << "mpg" << '\n';



	return 0;

}