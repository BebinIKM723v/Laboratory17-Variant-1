#include <iostream>
#include <cstring>

class Student {
protected:
    char* name;
    int course;
    int id;

public:
    Student() : name(nullptr), course(0), id(0) {}

    Student(const char* studentName, int studentCourse, int studentId) {
        name = new char[strlen(studentName) + 1];
        strcpy_s(name, strlen(studentName) + 1, studentName);
        course = studentCourse;
        id = studentId;
    }

    virtual ~Student() {
        delete[] name;
    }

    virtual void print() const {
        std::cout << "Iм'я: " << (name ? name : "Немає даних") << ", Курс: " << course << ", ID: " << id << std::endl;
    }

    void setId(int newId) {
        id = newId;
    }
};

class GraduateStudent : public Student {
private:
    char* diplomaTopic;

public:
    GraduateStudent() : Student(), diplomaTopic(nullptr) {}

    GraduateStudent(const char* studentName, int studentCourse, int studentId, const char* topic)
        : Student(studentName, studentCourse, studentId) {
        diplomaTopic = new char[strlen(topic) + 1];
        strcpy_s(diplomaTopic, strlen(topic) + 1, topic);
    }

    ~GraduateStudent() override {
        delete[] diplomaTopic;
    }

    void print() const override {
        Student::print();
        std::cout << "Тема диплома: " << (diplomaTopic ? diplomaTopic : "Немає даних") << std::endl;
    }

    void setDiplomaTopic(const char* newTopic) {
        delete[] diplomaTopic;
        diplomaTopic = new char[strlen(newTopic) + 1];
        strcpy_s(diplomaTopic, strlen(newTopic) + 1, newTopic);
    }
};

int main() {
    setlocale(LC_ALL, "Ukrainian");
    Student student("Iван Iванов", 3, 12345);
    student.print();

    GraduateStudent gradStudent("Марiя Петрiвна", 5, 54321, "Дослiдження алгоритмiв");
    gradStudent.print();

    gradStudent.setDiplomaTopic("Нова тема диплома");
    gradStudent.setId(98765);
    gradStudent.print();

    return 0;
}
