#include <iostream>
#include <string>
#include <algorithm>

class Pet {
protected:
    std::string name;

public:
    Pet(const std::string& name) : name(name) {}
    virtual ~Pet() {}
};

class Dog : public Pet {
public:
    Dog(const std::string& name) : Pet(name) {}
};

class Cat : public Pet {
public:
    Cat(const std::string& name) : Pet(name) {}
};

class Parrot : public Pet {
public:
    Parrot(const std::string& name) : Pet(name) {}
};

class String {
protected:
    std::string content;

public:
    String(const std::string& content = "") : content(content) {}

    void clear() {
        content.clear();
    }

    String operator+(const String& other) const {
        return String(content + other.content);
    }

    String& operator+=(const String& other) {
        content += other.content;
        return *this;
    }

    bool operator==(const String& other) const {
        return content == other.content;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    const std::string& get_content() const {
        return content;
    }
};

class BitString : public String {
public:
    BitString(const std::string& content = "") : String() {
        if (std::all_of(content.begin(), content.end(), [](char c) { return c == '0' || c == '1'; })) {
            this->content = content;
        }
    }

    void change_sign() {
        std::transform(content.begin(), content.end(), content.begin(), [](char c) {
            return c == '0' ? '1' : '0';
        });
    }

    BitString operator+(const BitString& other) const {
        return BitString(String::operator+(other).get_content());
    }

    BitString& operator+=(const BitString& other) {
        String::operator+=(other);
        return *this;
    }
};

int main() {
    Dog dog("buddy");
    Cat cat("whiskers");
    Parrot parrot("polly");

    String s1("hello"), s2("world");
    BitString b1("1010"), b2("0101");

    b1.change_sign();
    BitString b3 = b1 + b2;

    std::cout << "bitstring b3: " << b3.get_content() << std::endl;
    return 0;
}
