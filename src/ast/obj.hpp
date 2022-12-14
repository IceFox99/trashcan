#ifndef OBJ_H
#define OBJ_H

#include <string>
#include <memory>
#define BasePtr std::shared_ptr<Base>
#define IntPtr std::shared_ptr<Int>
#define makeInt(i) std::make_shared<Int>(i)
#define StringPtr std::shared_ptr<String>
#define makeStr(i) std::make_shared<String>(i)
#define BoolPtr std::shared_ptr<Bool>
#define makeBool(i) std::make_shared<Bool>(i)

class Base {
public:
    virtual std::string getType() const = 0;
    virtual std::string toString() const = 0;
    virtual ~Base();
};

class Int : public Base {
public:
    Int(int i);
    int getInt() const;
    std::string getType() const override;
    std::string toString() const override;
private:
    int i;
};

class String : public Base {
public:
    String(std::string str);
    std::string getStr() const;
    std::string getType() const override;
    std::string toString() const override;
private:
    std::string str;
};

class Bool : public Base {
public:
    Bool(bool b);
    bool getBool() const;
    std::string getType() const override;
    std::string toString() const override;
private:
    bool b;
};

#endif
