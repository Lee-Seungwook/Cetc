
#include"iostream"
using namespace std;

class person
{
	//private: //ĸ�� ���ο����� ������ ���������� �ܺο����� ������ �� �� ����.
	//public: //ĸ��ȭ�� �ӽ÷� Ǯ���ֱ� ���Ͽ�
private:
	char name[30] = { '\0' };
	int age = 0;

public: // talk�� see�� �ܺο��� ���� �����ϴ�.
	person() // ������ �Լ�
	{
		strcpy_s(name, strlen("\0") + 1, "\0");
		cout << "�� person �⺻������" << endl;
	}

	person(int page, const char pname[30])
	{
		cout << "�� ���� ���� person ������" << endl;
		age = page;
		strcpy_s(name, strlen(pname) + 1, pname);
	} /* �Ķ���� (��ȣ�ȿ� ������)�� �ִ� �Լ��� ������� �⺻ �Լ��� �ʼ��� �ʿ��ϴ�.
	  (��, perso(int page, const char pname [30]�� ��������, person()�� �ʿ��ϴ�.)*/

	char* getname()
	{
		return (char*)name;
	}

	void setname(const/*���ȭ ��Ű�ڴ�.*/ char pname[30])
	{
		strcpy_s(name, strlen(pname) + 1, pname);
	}

	void Setage(int page)
		//���ο� �Լ�(Setage)�� �����Ͽ�, private���� ������ age�� ���� �����ϰ� ����Ҽ� �ִ�.
	{
		age = page;
		cout << "age=" << age << endl;
	}

	void setage()
	{
		age = 45;
		cout << "age= " << age << endl;
	}

	int getage() //  ����Լ��� ȣ���Ͽ�, private���� ������ age�� �ܺο��� ȣ���ϰ� ����� �� �ְ� ���ش�.
	{
		return age;
	}

	void talk() // method (����Լ�)
	{
		age = 7;
		cout << "person�� ���Ѵ�." << endl;
	}
	void see() // method
	{
		talk();
		cout << "person�� ����." << endl;
	}

};



int main()
{
	//person  hodong;/*hodong �̶�� ��ü�� ����, ȣ��=��ü��������, �ν��Ͻ�����*/
	//Ŭ������ �ϳ��� Ÿ���̵ȴ�.(persond�� ������Ÿ��)
	//hodong.setage = 7;
	int num[3] = { 0, 1, 2 };
	int val[3] = { 0, 1, 2 };
	person hodong;
	//hodong.name = "��ȣ��"; // <-  ū ����ǥ�� ���� ���� �����Ϸ����� ���ڿ� ��������ͷ� ����Ѵ�.
	person hodong = person()/*<- person() ������ �Լ��� �Ѵ�.*/;
	person wonbin = person{ 41, "����" };
	person wonbin{ 41, "����" }; // ���� wonbin�� ���� ����� ���´�.
	cout << "wonbin.name=" << wonbin.getname() << "wonbin.age=" << wonbin.getage() << endl;
	hodong.setname("��ȣ��");
	cout << "hodong.name=" << hodong.getname() << endl;
	//strcpy_s(hodong.name, strlen("��ȣ��") +1 /*+1�� �ι��ڰ� �� �ڸ��� Ȯ���ϱ� �����̴�.*/, "��ȣ��");
	hodong.Setage(45);
	hodong.setage();
	cout << "hodong.age=" << hodong.getage() << endl;
	hodong.talk();/*public:������ talk�Լ� ���� ����*/

}