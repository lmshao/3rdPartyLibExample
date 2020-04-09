#include <iostream>
#include "sigslot.h"

// 信号发送类 必须声明信号类型
class Sender {
public:
    // 参数不同的信号使用不同的信号类型，新版也可以统一使用sigslot::signal<>
    sigslot::signal0<> Pass;
    sigslot::signal1<std::string > PassOne;
    sigslot::signal4<std::string , std::string , std::string , std::string > PassFour;
};

// 信号接收类 必须继承 sigslot::has_slots<>
class Receiver : public sigslot::has_slots<> {
public:
    explicit Receiver(std::string name): _name(name){}

    void Get(){
        printf("[%s] ",_name.c_str());
        printf("Receive\n");
    }
    void GetOne(std::string what) {
        printf("[%s] ",_name.c_str());
        printf("Receive One: %s\n", what.c_str());
    }

    void GetFour(std::string w1, std::string w2, std::string w3, std::string w4) {
        printf("[%s] ",_name.c_str());
        printf("Receive Four: %s %s %s %s\n", w1.c_str(), w2.c_str(), w3.c_str(), w4.c_str());
    }

private:
    std::string _name;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Sender s1;
    Receiver r1("r1"), r2("r2");

    s1.Pass.connect(&r1, &Receiver::Get);
    s1.Pass();

    // 一个信号可以发给多个函数
    s1.PassOne.connect(&r1, &Receiver::GetOne);
    s1.PassOne.connect(&r2, &Receiver::GetOne);
    s1.PassOne("Apple");

    // 四个参数的信号
    s1.PassFour.connect(&r1, &Receiver::GetFour);
    s1.PassFour("Apple", "Orange", "Banana", "Cherry");

    return 0;
}