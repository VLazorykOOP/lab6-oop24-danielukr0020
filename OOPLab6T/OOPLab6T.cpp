#include <iostream>

class Base {
public:
    int base_data;
    Base() : base_data(0) {}
    Base(int data) : base_data(data) {}
};

class D1 : public Base {
public:
    int d1_data;
    D1() : d1_data(1) {}
    D1(int data) : d1_data(data) {}
};

class D2 : public Base {
public:
    int d2_data;
    D2() : d2_data(2) {}
    D2(int data) : d2_data(data) {}
};

class D3 : public D1, public Base {
public:
    int d3_data;
    D3() : d3_data(3) {}
    D3(int data) : d3_data(data) {}
};

class D4 : public D2, public Base {
public:
    int d4_data;
    D4() : d4_data(4) {}
    D4(int data) : d4_data(data) {}
};

class D5 : public D3, public D4 {
public:
    int d5_data;
    D5() : d5_data(5) {}
    D5(int data) : d5_data(data) {}
};


//
//
//




class D1V : virtual public Base {
public:
    int d1_data;
    D1V() : d1_data(1) {}
    D1V(int data) : d1_data(data) {}
};

class D2V : virtual public Base {
public:
    int d2_data;
    D2V() : d2_data(2) {}
    D2V(int data) : d2_data(data) {}
};

class D3V : public D1V, virtual public Base {
public:
    int d3_data;
    D3V() : d3_data(3) {}
    D3V(int data) : d3_data(data) {}
};

class D4V : public D2V, virtual public Base {
public:
    int d4_data;
    D4V() : d4_data(4) {}
    D4V(int data) : d4_data(data) {}
};

class D5V : public D3V, public D4V {
public:
    int d5_data;
    D5V() : d5_data(5) {}
    D5V(int data) : d5_data(data) {}
};


int main() {
    Base base;
    D1 d1;
    D2 d2;
    D3 d3;
    D4 d4;
    D5 d5;
    D1V d1v;
    D2V d2v;
    D3V d3v;
    D4V d4v;
    D5V d5v;
    std::cout << "Size of Base: " << sizeof(base) << std::endl;
    std::cout << "Size of D1: " << sizeof(d1) << std::endl;
    std::cout << "Size of D2: " << sizeof(d2) << std::endl;
    std::cout << "Size of D3: " << sizeof(d3) << std::endl;
    std::cout << "Size of D4: " << sizeof(d4) << std::endl;
    std::cout << "Size of D5: " << sizeof(d5) << std::endl;
    std::cout << "Size of D1V: " << sizeof(d1v) << std::endl;
    std::cout << "Size of D2V: " << sizeof(d2v) << std::endl;
    std::cout << "Size of D3V: " << sizeof(d3v) << std::endl;
    std::cout << "Size of D4V: " << sizeof(d4v) << std::endl;
    std::cout << "Size of D5V: " << sizeof(d5v) << std::endl;
    return 0;
}


#include <iostream>
using namespace std;

class Function
{
protected:
    double x;
public:
    Function() : x(0) {}
    Function(double _x) : x(_x) {}
    virtual double Funk() = 0;
};
class Line : public Function
{
    double a;
    double b;
public:
    Line(double _x, double _a, double _b) : Function(_x), a(_a), b(_b) {}
    virtual double Funk() override {
        return a * x + b;
    }
};

class Ellipse : public Function {
    double a, b;

public:
    Ellipse(double a, double b) : a(a), b(b) {}

    virtual double Funk() override {
        return std::sqrt(1 - (x * x) / (a * a)) * b;
    }
};

class Hyperbola : public Function {
    double a, b;

public:
    Hyperbola(double a, double b) : a(a), b(b) {}

    virtual double Funk() override {
        return std::sqrt(1 + (x * x) / (a * a)) * b;
    }
};

int main()
{
    double x = 2.0;

    Line line(2, 3, 4);
    Ellipse ellipse(5, 4);
    Hyperbola hyperbola(3, 2);

    cout << "Value of line at x = " << x << ": " << line.Funk() << endl;
    cout << "Value of ellipse at x = " << x << ": " << ellipse.Funk() << endl;
    cout << "Value of hyperbola at x = " << x << ": " << hyperbola.Funk() << endl;

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(const string& _name, int _age) : name(_name), age(_age) {}
    virtual ~Person() {}

    virtual void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    friend istream& operator>>(istream& in, Person& person) {
        in >> person.name;
        in >> person.age;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Person& person) {
        out << "Name: " << person.name << ", Age: " << person.age;
        return out;
    }
};

class Employee : public Person {
protected:
    string position;
    double salary;

public:
    Employee(const string& _name, int _age, const string& _position, double _salary)
        : Person(_name, _age), position(_position), salary(_salary) {}

    void display() const override {
        Person::display();
        cout << "Position: " << position << ", Salary: " << salary << endl;
    }

    friend istream& operator>>(istream& in, Employee& employee) {
        in >> employee.name;
        in >> employee.age;
        in >> employee.position;
        in >> employee.salary;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Employee& employee) {
        out << static_cast<const Person&>(employee) << ", Position: " << employee.position << ", Salary: " << employee.salary;
        return out;
    }
};

class Family {
protected:
    string familyRole;

public:
    Family(const string& _role) : familyRole(_role) {}
    virtual ~Family() {}

    virtual void display() const {
        cout << "Family Role: " << familyRole << endl;
    }

    friend istream& operator>>(istream& in, Family& family) {
        in >> family.familyRole;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Family& family) {
        out << "Family Role: " << family.familyRole;
        return out;
    }
};

class EmployeeFamily : public Employee, public Family, public Person {
public:
    EmployeeFamily(const string& _name, int _age, const string& _position, double _salary, const string& _role)
        : Person(_name, _age), Employee(_name, _age, _position, _salary), Family(_role) {}

    void display() const override {
        Employee::display();
        Family::display();
    }
};

int main() {
    EmployeeFamily empFam("John Doe", 35, "Manager", 5000, "Father");
    empFam.display();
    return 0;
}