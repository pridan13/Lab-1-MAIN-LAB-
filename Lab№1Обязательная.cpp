#include <iostream>
#include <string>
using namespace std;
class Harbinger
{
private:
	std::string h_name;
	int h_age;
	string CatchPhrase;
public:

	Harbinger(string name = "", int age = 0, string phrase = "")
	{
		h_name = name;
		h_age = age;
		CatchPhrase = phrase;

	}

	std::string getName() const { return h_name; }
	int getAge() const { return h_age; }
	void setName(string name) {
		h_name = name;
	}
	void setAge(int age) {
		h_age = age;
	}
	string getCatchPhrase() const {
		return CatchPhrase;
	}
	void setCatchPhrase(string CatchPhrase) {
		this->CatchPhrase = CatchPhrase;

	}

};

class Prophet : public Harbinger {

private:
	string ph_name, ph_call, strN;
	int ph_age;
	string MagnumOpus[3];
public:
	Prophet(string name = "", int age = 0, string call = "") {
		ph_name = name;
		ph_age = age;
		ph_call = call;
	}

	void setNAme(string name) {
		if (name.length() > 24) {
			cout << "Ошибка";
			cin >> strN;
			setNAme(strN);
		}
		else if (name.length() > ph_call.length()) {
			ph_name = ph_call;
			ph_call = name;
		}
		else ph_name = name; 

	}
	string getNAme() const { return ph_name; }
	void setAGe(int age) {
		ph_age = age;
	}
	int getAGe() const { return ph_age; }

	string getCAll() const { return ph_call; }

	void setMagmum(int n, string str) {
		if (str.length() > 24) {
			cout << "Ошибка" << endl;
		}
		else { MagnumOpus[n] = str; }

		if (str.length() > ph_call.length()) {
			ph_call = str;
		}
		else { ph_name = str; }

	}
	string getMagnum(int i) {
		return MagnumOpus[i];
	}
	void sort () {
		string a ="";
		for (int i = 0; i < 2; i++) {
			if (MagnumOpus[i] > MagnumOpus[i+1]) {
				a = MagnumOpus[i];
				MagnumOpus[i] = MagnumOpus[i+1];
				MagnumOpus[i+1] = a;
			}
		}
	}
};

class DeusEx : public Prophet {
private: 
	string gd_name;
	int gd_year;
public: 
	DeusEx(string name = "Иисус", int year=(rand()%10000)) {
		gd_name = name;
		gd_year = year;
	
	}
	void forecast() {
		sort ();
    
		cout << getName() << " в возрасте " << getAge() << " говорил, что " << getCatchPhrase() << endl;
		cout << "Первое пророчество : " << getMagnum(0) << endl;
		cout << "Второе пророчество: " << getMagnum(1) << endl;
		cout << "Главное пророчество: " << getMagnum(2) << endl;
		cout << "Так говорил " << getName() << " в возрасте " << getAGe() << endl;
		cout << "В год " << gd_year << " пришёл " << gd_name << ", которого предрекали " << getName();
	}
	string getGd_name() const { return gd_name; }
	int getGd_year() const { return gd_year; }
  void bonus () {cout << getName () << endl;}
};

class Believer : private DeusEx {
private: 
	string bv_name;
	int bv_age;
public: 
	Believer(string name, int age) {
		bv_name = name;
		bv_age = age;
    
	}
	
	void setBv_name(string name) {
		bv_name = name;
	}
	void setBv_age(int age) {
		bv_age = age;
	}
	string getBv_name() const { return bv_name; }
	int getBv_age() const { return bv_age; }
	 
	void output() {
     cout << " и " << bv_name << endl;
		cout << "Верующий " << bv_name << " молится " << getGd_name()<<   " именем " ;
	
	}
  void output2 () {	cout << "С " << getGd_year() << " и по сей день";}
/* Для вызова gd_name и gd_year создаём геттеры в родительском классе.*/

};

int main() {
  setlocale(LC_ALL, "Russian");

  DeusEx first = DeusEx();
  first.setName("John");
  first.setAge(32);
  first.setCatchPhrase("You know!");
  first.setMagmum(0, "All people will know!");/* Заполнение массива */
  first.setMagmum(1, "We will become better!");
  first.setMagmum(2, "The world will change");
  first.setAGe(28);/* Добавляет возраст в переменную ph_age */
  first.forecast();
  Believer F = Believer("Anna", 22);
  F.output();
  first.bonus();
  F.output2 ();
  return 0;

}

