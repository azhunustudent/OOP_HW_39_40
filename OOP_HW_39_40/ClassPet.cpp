#include <iostream>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


// Задание 1.
// Создать базовый класс «Домашнее животное» и производные классы «Собака», «Кошка», «Попугай».
// С помощью конструктора установить имя каждого животного и его характеристики.
class Pet
{
private:
	string Breed;
protected:
	string Name;
	int Age;
public:
    Pet() = delete;
    Pet(string name) : Name(name), Age() {}

    string GetBreed() const { return Breed; }
    string GetName()  const { return Name;  }
    int GetAge()      const { return Age;   }
    
    void SetBreed(string val) { Breed = val; }
    void SetName(string val)  { Name = val;  }
    void SetAge(int val) { Age = val; }

    friend ostream& operator<< (ostream& os, const Pet& obj)
    {
        os << "Name: " << obj.GetName() << endl
           << "Age: " << obj.GetAge() << endl
           << "Breed: " << obj.GetBreed() << endl;
        return os;
    }

    friend istream& operator>> (istream& is, Pet& obj)
    {
        string tmp1;
        int tmp2;

        cout << "Enter name: ";  getline(is, tmp1); obj.SetName(tmp1);
        while (true)
        {
            cout << "Enter age: ";
            (is >> tmp2).ignore();
            if (tmp2 >= 0)
            {
                obj.SetAge(tmp2);
                break;
            }
            else { cout << "Error: Age cannot be negative. Repeat the entry!" << endl; }
        }
        cout << "Enter breed: "; getline(is, tmp1); obj.SetBreed(tmp1);
        return is;
    }
};


class Dog : public Pet
{
private:
	string Toy;			// любимая игрушка собаки
public:
    Dog() : Pet("Dog") {}
    Dog(string toy) : Pet("Dog"), Toy(toy) {}

    string GetToy() const   { return Toy; }
    void SetToy(string val) { Toy = val; }

    friend ostream& operator<< (ostream& os, const Dog& obj)
    {
        os << typeid(obj).name() << endl;
        os << (Pet&)obj;
        os << "Toy: " << obj.GetToy();
        return os;
    }

    friend istream& operator>> (istream& is, Dog& obj)
    {
        string tmp;

        cout << "Enter info for " << typeid(obj).name() << endl;
        is >> (Pet&)obj;
        cout << "Enter favorite toy: "; getline(is, tmp); obj.SetToy(tmp);
        return is;
    }
};


class Cat : public Pet
{
private:
	int LifeCount;
public:
    Cat() : Pet("Cat"), LifeCount() {}
    Cat(int count) : Pet("Cat"), LifeCount(count) {}

    int GetLifeCount() const   { return LifeCount; }
    void SetLifeCount(int val) { LifeCount = val; }

    friend ostream& operator<< (ostream& os, const Cat& obj)
    {
        os << typeid(obj).name() << endl;
        os << (Pet&)obj;
        os << "LifeCount: " << obj.GetLifeCount();
        return os;
    }

    friend istream& operator>> (istream& is, Cat& obj)
    {
        int tmp;

        cout << "Enter info for " << typeid(obj).name() << endl;
        is >> (Pet&)obj;
        while (true)
        {
            cout << "Enter life count: ";
            (is >> tmp).ignore();
            if (tmp >= 0 && tmp <= 9)
            {
                obj.SetLifeCount(tmp);
                break;
            }
            else { cout << "Error: Life count cannot be negative and cannot be greater than 9. Repeat the entry!" << endl; }
        }
        return is;
    }
};


class Parrot : public Pet
{
private:
	string Word;		// любимое или повторяемое слово попугая(?)
public:
    Parrot() : Pet("Parrot") {}
    Parrot(string word) : Pet("Parrot"), Word(word) {}

    string GetWord() const   { return Word; }
    void SetWord(string val) { Word = val; }

    friend ostream& operator<< (ostream& os, const Parrot& obj)
    {
        os << typeid(obj).name() << endl;
        os << (Pet&)obj;
        os << "Favorite word: " << obj.GetWord();
        return os;
    }

    friend istream& operator>> (istream& is, Parrot& obj)
    {
        string tmp;

        cout << "Enter info for " << typeid(obj).name() << endl;
        is >> (Pet&)obj;
        cout << "Enter favorite word: "; getline(is, tmp); obj.SetWord(tmp);
        return is;
    }
};


int main()
{
    Dog dog;
    cin >> dog;
    cout << "--------------------------------------------------\n";
    cout << dog << endl;
    cout << "--------------------------------------------------\n";

    Cat cat;
    cin >> cat;
    cout << "--------------------------------------------------\n";
    cout << cat << endl;
    cout << "--------------------------------------------------\n";

    Parrot parrot;
    cin >> parrot;
    cout << "--------------------------------------------------\n";
    cout << parrot;
}