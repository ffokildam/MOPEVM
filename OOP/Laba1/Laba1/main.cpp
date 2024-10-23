#include <iostream>
#include <vector>
#include <string>

class Telephone
{
public:
    Telephone(long long _number, std::vector<long long> _contacts, int _minutePrice) {
        number = _number;
        contacts = _contacts;
        callCount = 0;
        minutePrice = _minutePrice;
    }

    long long makeCall(long long callNumber, int callLength, std::vector<Telephone>& allPhones) {
        if (std::to_string(callNumber).length() != 11) {
            throw std::invalid_argument("Вызываемый номер должен иметь 11 знаков.");
        }

        if (!std::count(contacts.begin(), contacts.end(), callNumber)) {
            contacts.push_back(callNumber);
            std::cout << "Номер был добавлен в контакты\n";
        }

        callCount++;

        for (auto& phone : allPhones) {
            if (phone.getNumber() == callNumber) {
                if (phone.answerCall(number) == 0)
                    return callLength * minutePrice;
                else
                    return -1;
            }
        }

        throw std::exception("Вызываемый абонент не найден");

    }
    int answerCall(long long callNumber) {
        std::cout << "Входящий вызов от номера " << callNumber << ". Ответить? (y/n): ";
        char response;
        std::cin >> response;

        if (response == 'y' || response == 'Y') {
            if (!std::count(contacts.begin(), contacts.end(), callNumber)) {
                contacts.push_back(callNumber);
            }
            callCount++;
            std::cout << "Вызов принят." << std::endl;
            return 0; 
        }
        else {
            std::cout << "Вызов отклонен." << std::endl;
            return -1; 
        }
    }
    long long getNumber() const { return number; }

private:
    long long number;
    std::vector<long long> contacts;
    int callCount;
    int minutePrice;
};

int main() {
    setlocale(LC_ALL, "Russian");

    std::vector<long long> contacts1;
    Telephone t1(89889431886, contacts1, 5);
    Telephone t2(89889431887, contacts1, 5);
    std::vector<Telephone> allPhones;
    allPhones.push_back(t1);
    allPhones.push_back(t2);
    for (int i = 0; i < 2; i++)
    {
        try {
            short int res = t1.makeCall(89889431887, 5, allPhones);
            if (res != -1) {
                std::cout << "Стоимость вызова: " << res << " рублей.\n";
            }
        }
        catch (std::invalid_argument& e) {
            std::cerr << "Error: " << e.what();
        }
        catch (std::exception& e) {
            std::cerr << "Error: " << e.what();
        }
    }
}