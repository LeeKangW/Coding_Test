#include<iostream>
#include<string>

class Human
{
protected:
	std::string name;
	int age;
public:
	explicit Human(std::string p_name, int p_age) :name{ p_name }, age{ p_age }{}
	virtual ~Human() {}

	virtual void show() const { std::cout << "부모" << std::endl; }
};

class Student : public Human
{
private:
	std::string class_name;
public:
	explicit Student(std::string p_name, int p_age, std::string p_class_name) :Human(p_name, p_age), class_name{ p_class_name }{}
	virtual ~Student(){}
	void show() const override {
		// printf("학생\n이름 : %s , 나이 : %d , 클래스명 : %s \n", __super::name, __super::age, class_name); 
		std::cout << "학생 \n 이름 : " << __super::name << ", 나이 : " << __super::age << ", 클래스명 : " << class_name << std::endl;
	}
};

class Teacher : public Human
{
	private:
		std::string class_name;
public:
	explicit Teacher(std::string p_name, int p_age, std::string p_class_name) :Human(p_name, p_age), class_name{ p_class_name }{}
	virtual ~Teacher() {}
	void show() const override { 
		//printf("교수\n이름 : %s , 나이 : %d , 클래스명 : %s \n", __super::name, __super::age, class_name); 
		std::cout << "교수 \n 이름 : " << __super::name << ", 나이 : " << __super::age << ", 클래스명 : " << class_name << std::endl;
	}
};

void Show(const Human& rhs)
{
	rhs.show();
}
int main()
{
	Student s[2] = { Student{"Lee",25,"Computer"},Student{"Kim",25,"Electrode"} };
	Teacher t("Park", 45, "Computer");

	Show(s[0]);
	Show(s[1]);
	Show(t);
}