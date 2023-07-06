#include <iostream>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


// Задание 2
// Создайте класс удостоверение Сertificate, который будет содержать информацию о гражданине Казахстана.
// С помощью механизма наследования, реализуйте класс ForeignPassport(загран.паспорт) производный от Сertificate.
// Напомним, что заграничный паспорт содержит помимо паспортных данных, также данные о визах, номер заграничного паспорта.
class Certificate
{
private:
    int Number;             // номер удостоверния
    long long int IIN;      // ИИН
protected:
    // фио, национальность
    string FIO;
    string Nationality;
public:
    Certificate() : FIO("unknown"), Nationality("unknown"), Number(), IIN() {}
    Certificate(string fio, string nationality, int num, long long int iin) : FIO(fio), Nationality(nationality), Number(num), IIN(iin) {}

    string GetFIO()         const { return FIO; }
    string GetNationality() const { return Nationality; }
    int GetNum()            const { return Number; }
    long long int GetIIN()  const { return IIN; }

    void SetFIO(string val)         { FIO = val; }
    void SetNationality(string val) { Nationality = val; }
    void SetNum(int val)            { Number = val; }
    void SetIIN(long long int val)  { IIN = val; }

    friend ostream& operator<< (ostream& os, const Certificate& obj)
    {
        // os << typeid(obj).name() << endl;
        os << "FIO: " << obj.GetFIO() << endl
           << "Nationality: " << obj.GetNationality() << endl
           << "Number of Сertificate: " << obj.GetNum() << endl
           << "IIN: " << obj.GetIIN() << endl;
        return os;
    }

    friend istream& operator>> (istream& is, Certificate& obj)
    {
        string tmp1;
        long long int tmp2;

        // cout << "Enter for " << typeid(obj).name() << endl;
        cout << "Enter FIO: ";  getline(is, tmp1); obj.SetFIO(tmp1);
        cout << "Enter nationality: "; getline(is, tmp1); obj.SetNationality(tmp1);
        while (true)
        {
            cout << "Enter number of certificate: ";
            (is >> tmp2).ignore();
            if (CheckNum(tmp2))
            {
                obj.SetNum(tmp2);
                break;
            }
            else { cout << "Error: Number of Сertificate cannot be negative or cannot be 0 and can have 9 digits. Repeat the entry!" << endl; }
        }
        while (true)
        {
            cout << "Enter IIN: ";
            (is >> tmp2).ignore();
            if (CheckIIN(tmp2))
            {
                obj.SetIIN(tmp2);
                break;
            }
            else { cout << "Error: IIN cannot be negative or cannot be 0 and can have 12 digits. Repeat the entry!" << endl; }
        }
        return is;
    }
private:
    static bool CheckIIN(long long int val)
    {
        int count = 0;
        while (val > 0)
        {
            val /= 11;
            count++;
        }
        return count == 11;
    }
    static bool CheckNum(int val)
    {
        int count = 0;
        while (val > 0)
        {
            val /= 9;
            count++;
        }
        return count == 9;
    }
};


class ForeignPassport : public Certificate
{
private:
    int PassNum;            // номер заграничного паспорта
    string VisaInfo;        // данные о визах
public:
    ForeignPassport() : PassNum(), VisaInfo("empty") {}
    ForeignPassport(string fio, string nationality, int seria, long long int iin, int passNum, string visaInfo) : Certificate(fio, nationality, seria, iin), PassNum(passNum), VisaInfo(visaInfo) {}

    int GetPassNum()     const { return PassNum; }
    string GetVisaInfo() const { return VisaInfo; }
    
    void SetPassNum(int val) { PassNum = val; }
    void SetVisaInfo(string val) { VisaInfo = val; }

    friend ostream& operator<< (ostream& os, const ForeignPassport& obj)
    {
        os << typeid(obj).name() << endl;
        os << (Certificate&)obj;
        os << "Passport Number: " << obj.GetPassNum() << endl;
        os << "Visa Information: " << obj.GetVisaInfo();
        return os;
    }

    friend istream& operator>> (istream& is, ForeignPassport& obj)
    {
        int tmp;
        string tmp2;

        cout << "Enter info for " << typeid(obj).name() << endl;
        is >> (Certificate&)obj;
        while (true)
        {
            cout << "Enter passport number: ";
            (is >> tmp).ignore();
            if (CheckPassNumber(tmp))
            {
                obj.SetPassNum(tmp);
                break;
            }
            else { cout << "Error: Passport Number cannot be negative or cannot be 0 and can have 9 digits. Repeat the entry!" << endl; }
        }
        cout << "Enter visa information: "; getline(is, tmp2); obj.SetVisaInfo(tmp2);
        return is;
    }
private:
    static bool CheckPassNumber(int val)
    {
        int count = 0;
        while (val > 0)
        {
            val /= 9;
            count++;
        }
        return count == 9;
    }
};


int main()
{
    // Certificate A;
    // cin >> A;
    // cout << endl << A << endl;
    // cout << "--------------------------------------------------\n";

    ForeignPassport person;
    cin >> person;
    cout << "--------------------------------------------------\n";
    cout << person;
}