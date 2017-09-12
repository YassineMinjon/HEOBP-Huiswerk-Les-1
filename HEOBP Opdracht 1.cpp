// HEOBP Opdracht 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Lesson //The lesson class is the base to every different subject.
{
	private:
		int month;
		int week;
		int day;
		int classRoom;
		string time;
		string name;
		string teacher;
		string discription;

	static int numberOfLessons;
	
	public:
		int getMonth(){ return month; }
		int getWeek() { return week; }
		int getDay() { return day; }
		int getClassroom() { return classRoom; }
		string getTime() { return time; }
		string getName() { return name; }
		string getTeacher() { return teacher; }
		string getDiscription() { return discription; }

		void setDate(int monthVal, int weekVal, int dayVal) { month = monthVal; week = weekVal; day = dayVal; }
		void setTime(float timeVal) { time = timeVal; }
		void setName(string lessonName) { name = lessonName; }
		void setTeacher(string teacherName) { teacher = teacher; }
		void setDiscription(string newDiscription) { discription = newDiscription; }

		Lesson();
		Lesson(int monthVal, int weekVal, int dayVal, int classRoomVal, string timeVal, string nameVal, string teacherVal, string newDiscription);
		~Lesson();
};

int Lesson::numberOfLessons = 0;

Lesson::Lesson(void) { numberOfLessons++; }

Lesson::Lesson(int monthVal, int weekVal, int dayVal, int classRoomVal, string timeVal, string nameVal, string teacherVal, string newDiscription)
{
	this->month = monthVal;
	this->week = weekVal;
	this->day = dayVal;
	this->classRoom = classRoomVal;
	this->time = timeVal;
	this->name = nameVal;
	this->teacher = teacherVal;
	this->discription = newDiscription;
	numberOfLessons++;
}

Lesson::~Lesson() { numberOfLessons--; }


class KernModule : public Lesson
{
	private:
		string study;

	public:
		string getStudy() { return study; }

		void setStudy(string studyVal) { study = studyVal; }

		KernModule(int monthVal, int weekVal, int dayVal, int classRoomVal, string timeVal, string nameVal, string teacherVal, string newDiscription, string studyVal);
		KernModule() : Lesson() {};
};

KernModule::KernModule(int monthVal, int weekVal, int dayVal, int classRoomVal, string timeVal, string nameVal, string teacherVal, string newDiscription, string studyVal) 
: Lesson(monthVal ,weekVal ,dayVal ,classRoomVal ,timeVal ,nameVal ,teacherVal ,newDiscription)
{
	this->study = studyVal;
}


class KeuzeVak : public Lesson
{
	private:
		list<string> students;
		list<string>::iterator it;

	public:
		list<string> getStudents(){ return students; }

		void setStudents(string studentName) { students.insert(it, studentName); }

		KeuzeVak(int monthVal, int weekVal, int dayVal, int classRoomVal, string timeVal, string nameVal, string teacherVal, string newDiscription, list<string> students);
		KeuzeVak() : Lesson() {};

};

KeuzeVak::KeuzeVak(int monthVal, int weekVal, int dayVal, int classRoomVal, string timeVal, string nameVal, string teacherVal, string newDiscription, list<string> students)
: Lesson(monthVal, weekVal, dayVal, classRoomVal, timeVal, nameVal, teacherVal, newDiscription)
{

}




int main()
{
    return 0;
}

