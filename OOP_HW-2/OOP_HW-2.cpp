// OOP_HW-2.cpp
//

#include <iostream>

using namespace std;

class Person {
private:
    string name;
    int age;
    string gender;
    float weight;
public:
    Person(string n = "", int a = 0, string g = "", float w = 0.0) : name(n), age(a), gender(g), weight(w) {

    }
    void setName(string n) {
        name = n;
    }
    void setAge(int a) {
        age = a;
    }
    void setWeight(float w) {
        weight = w;
    }
    string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
    string getGender() const {
        return gender;
    }
    float getWeight() const {
        return weight;
    }
};

class Student : public Person {
private:
    int StudyYear;
    static int studentCounter;
public:
    Student(string n = "", int a = 0, string g = "", float w = 0.0, int sy = 0) : StudyYear(sy), Person(n, a, g, w) {
         studentCounter++;
    }
    void setStudyYear(int sy) {
        StudyYear = sy;
    }
    void increaseStudyYear() {
        StudyYear++;
    }
    int getStudyYear() const {
        return StudyYear;
    }
    int countStudents() const {
        return studentCounter;
    }
    void print() const {
        cout << " Name: " << getName() << " Age: " << getAge() << " Gender: " << getGender() << " Weight: " << getWeight() << " StudyYear: " << getStudyYear() << " Students total: " << countStudents() << endl;
    }
    ~Student() {
        studentCounter--;
    }
};

int Student::studentCounter = 0;

class Fruit {
private:
    string name;
    string color;
public:
    Fruit(string n = "", string c = "") : name(n), color(c) {

    }
    string getName() const {
        return name;
    }
    string getColor() const {
        return color;
    }
};

class Apple : public Fruit {
public:
    Apple(string c = "", string n = "") : Fruit(n + "apple", c) {
    
    }
};

class Banana : public Fruit {
public:
    Banana() : Fruit("banana", "yellow") {

    }
};

class GrannySmith : public Apple {
public:
    GrannySmith() : Apple("green", "Granny Smith ") {

    }
};

int main()
{
    Student Anton("Anton", 30, "male", 70.0, 1);
    Student Vasya("Vasya", 31, "male", 76.0, 2);
    Student Katya("Katya", 29, "female", 46.0, 1);
    Anton.increaseStudyYear();
    Anton.print();
    Vasya.print();
    Katya.print();

    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}
