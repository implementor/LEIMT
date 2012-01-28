#include "dbobj.h"
#include <string>

/////////////////////////////////////////////////
///////// SIMPLE GETTERS ////////////////////////

/* User */
std::string *User::getName() const throw() { return name; }
std::string *User::getEmail() const throw() { return email; }
lrank_t User::getCapability() const throw() { return capability; }

/* Teacher */
id_t Teacher::getUserId() const throw() { return user; }
rank_t Teacher::getEvilness() const throw() { return evilness; }
rank_t Teacher::getExperience() const throw() { return experience; }
rank_t Teacher::getITSkill() const throw() { return itskill; }

/* Subject */
std::string *Subject::getLabel() const throw() { return label; }

/* Course */
id_t Course::getTeacherId() const throw() { return teacher; }
id_t Course::getSubjectId() const throw() { return subject; }
rank_t Course::getLevel() const throw() { return level; }

/* Timespan */
std::string *Timespan::getLabel() const throw() { return label; }
char Timespan::getDayOfWeek() const throw() { return dayOfWeek; }
double Timespan::getStartTime() const throw() { return startTime; }
double Timespan::getEndTime() const throw() { return endTime; }

/* Lesson */
id_t Lesson::getTimespanId() const throw() { return timespan; }
id_t Lesson::getCourseId() const throw() { return course; }
lrank_t Lesson::getRoom() const throw() { return room; }
rank_t Lesson::getWeek() const throw() { return week; }

/* Skill */
id_t Skill::getTeacherId() const throw() { return teacher; }
id_t Skill::getSubjectId() const throw() { return subject; }

/* MissingTeacher */
id_t MissingTeacher::getTeacherId() const throw() { return teacher; }
long MissingTeacher::getDate() const throw() { return date; }
std::string *MissingTeacher::getReason() const throw() { return reason; }

/* Substitution */
Nullable<id_t> Substitution::getOrigLessonId() const throw() { return origLesson; }
Nullable<id_t> Substitution::getSubTeacherId() const throw() { return subTeacher; }
id_t Substitution::getSubSubjectId() const throw() { return subSubject; }
lrank_t Substitution::getSubRoom() const { return subRoom; }
std::string *Substitution::getNote() const throw() { return note; }

/* Class */
std::string *Class::getLabel() const throw() { return label; }
rank_t Class::getLevel() const throw() { return level; }
id_t Class::getPrimClassTeacherId() const throw() { return primClassTeacher; }
id_t Class::getSecClassTeacherId() const throw() { return secClassTeacher; }

/* Student */
std::string *Student::getName() const throw() { return name; }
rank_t Student::getLevel() const throw() { return level; }
Nullable<id_t> Student::getClassId() const throw() { return classid; }

/* ClassLesson */
id_t ClassLesson::getClassId() const throw() { return classid; }
id_t ClassLesson::getCourseId() const throw() { return course; }

/* StudentLesson */
id_t StudentLesson::getStudentId() const throw() { return student; }
id_t StudentLesson::getCourseId() const throw() { return course; }