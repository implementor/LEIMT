#ifndef _dbobj_h_
#define _dbobj_h_
#include <string>

/*  LEIMT Datebase Bindings  */

typedef unsigned id_t;
typedef unsigned char rank_t;
typedef unsigned short lrank_t;

class DBObject {
private:
    bool massUpdate;
protected:
    bool IsUpdating() { return massUpdate; }
    id_t const id;
public:
    id_t getId() const throw() { return id; }
    void StartUpdate() { if (IsUpdating()) EndUpdate(); massUpdate = true; }
    virtual void EndUpdate() { massUpdate = false; }
};

template <typename T>
class Nullable {
private:
    bool hasValue;
    T value;
public:
    Nullable() : value(T()), hasValue(false) {}
    Nullable(T const val) : value(val), hasValue(true) {}
    T getValue() const { return value; }
    bool HasValue() const { return hasValue; }
    operator T() const { return value; }
    bool operator ==(void *ptr) const
    {
        return (ptr==NULL) && (!hasValue);
    }
    bool operator !=(void *ptr) const
    {
        return !(this==ptr);
    }
};

#define ucSuperUser         0xFFFF
#define ucEditConfig        0x0001
#define ucAddStudents       0x0002
#define ucEditStudents      0x0004
#define ucEditSubstitutions 0x0008
#define ucEditCourses       0x0010

class User : public virtual DBObject {
private:
    std::string *name;
    std::string *email;
    lrank_t capability;
public:
    std::string *getName() const throw();
    std::string *getEmail() const throw();
    lrank_t getCapability() const throw();
    void setName(std::string const &val);
    void setEmail(std::string const &val);
    void setCapability(unsigned short val);
    void EndUpdate();
};

class Teacher : public virtual DBObject {
private:
    id_t user;
    rank_t evilness, experience, itskill; 
public:
    id_t getUserId() const throw();
    User *getUser() const;
    rank_t getEvilness() const throw();
    rank_t getExperience() const throw();
    rank_t getITSkill() const throw();
    void setUserId(id_t val);
    void setUser(User const &val);
    void setEvilness(rank_t val);
    void setExperience(rank_t val);
    void setITSkill(rank_t val);
    void EndUpdate();
};

class Subject : public virtual DBObject {
private:
    std::string *label;
public:
    std::string *getLabel() const throw();
    void setLabel(std::string const &val);
    void EndUpdate();
};

class Course : public virtual DBObject {
private:
    id_t teacher, subject;
    rank_t level;
public:
    id_t getTeacherId() const throw();
    Teacher *getTeacher() const;
    id_t getSubjectId() const throw();
    Subject *getSubject() const;
    rank_t getLevel() const throw();
    void setTeacherId(id_t val);
    void setTeacher(Teacher const &val);
    void setSubjectId(id_t val);
    void setSubject(Subject const &val);
    void setLevel(rank_t val);
    void EndUpdate();
};

#define dowSunday           0x00
#define dowMonday           0x01
#define dowTuesday          0x02
#define dowWednesday        0x03
#define dowThursday         0x04
#define dowFriday           0x05
#define dowSaturday         0x06

class Timespan : public virtual DBObject {
private:
    std::string *label;
    char dayOfWeek;
    double startTime, endTime;
public:
    std::string *getLabel() const throw();
    char getDayOfWeek() const throw();
    double getStartTime() const throw();
    double getEndTime() const throw();
    void setLabel(std::string const &val);
    void setDayOfWeek(char val);
    void setStartTime(double val);
    void setEndTime(double val);
    void EndUpdate();
};

#define wkEveryWeek         0x00
#define wkEvenWeek          0x10
#define wkOddWeek           0x11
#define wkFirstWeek         0x01
#define wkSecondWeek        0x02
#define wkThirdWeek         0x03
#define wkFourthWeek        0x04

class Lesson : public virtual DBObject {
private:
    id_t timespan, course;
    lrank_t room;
    rank_t week;
public:
    id_t getTimespanId() const throw();
    id_t getCourseId() const throw();
    Timespan *getTimespan() const;
    Course *getCourse() const;
    lrank_t getRoom() const throw();
    rank_t getWeek() const throw();
    void setTimespanId(id_t val);
    void setTimespan(Timespan const &val);
    void setCourseId(id_t val);
    void setCourse(Course const &val);
    void setRoom(lrank_t val);
    void setWeek(rank_t val);
    void EndUpdate();
};

class Skill : public virtual DBObject {
private:
    id_t teacher, subject;
public:
    id_t getTeacherId() const throw();
    Teacher *getTeacher() const;
    id_t getSubjectId() const throw();
    Subject *getSubject() const;
    void setTeacherId(id_t val);
    void setTeacher(Teacher const &val);
    void setSubjectId(id_t val);
    void setSubject(Subject const &val);
    void EndUpdate();
};

class MissingTeacher : public virtual DBObject {
private:
    id_t teacher;
    std::string *reason;
    long date;
public:
    id_t getTeacherId() const throw();
    Teacher *getTeacher() const;
    std::string *getReason() const throw();
    long getDate() const throw();
    void setTeacherId(id_t val);
    void setTeacher(Teacher const &val);
    void setReason(std::string const &val);
    void setDate(long val);
    void EndUpdate();
};

class Substitution : public virtual DBObject {
private:
    Nullable<id_t> origLesson, subTeacher;
    id_t subSubject;
    lrank_t subRoom;
    std::string *note;
public:
    Nullable<id_t> getOrigLessonId() const throw();
    Lesson *getOrigLesson() const;
    Nullable<id_t> getSubTeacherId() const throw();
    Teacher *getSubTeacher() const;
    id_t getSubSubjectId() const throw();
    Subject *getSubSubject() const;
    lrank_t getSubRoom() const;
    std::string *getNote() const throw();
    void setOrigLessonId(Nullable<id_t> val);
    void setOrigLesson(Lesson const &val);
    void setSubTeacherId(Nullable<id_t> val);
    void setSubTeacher(Teacher const &val);
    void setSubSubjectId(id_t val);
    void setSubSubject(Subject const &val);
    void setSubRoom(lrank_t val);
    void setNote(std::string const &val);
    void EndUpdate();
};

class Class : public virtual DBObject {
private:
    std::string *label;
    rank_t level;
    id_t primClassTeacher, secClassTeacher;
public:
    std::string *getLabel() const throw();
    rank_t getLevel() const throw();
    id_t getPrimClassTeacherId() const throw();
    id_t getSecClassTeacherId() const throw();
    Teacher *getPrimClassTeacher() const;
    Teacher *getSecClassTeacher() const;
    void setLabel(std::string const &val);
    void setLevel(rank_t val);
    void setPrimClassTeacherId(id_t val);
    void setSecClassTeacherId(id_t val);
    void setPrimClassTeacher(Teacher const &val);
    void setSecClassTeacher(Teacher const &val);
    void EndUpdate();
};

class Student : public virtual DBObject {
private:
    std::string *name;
    rank_t level;
    Nullable<id_t> classid;
public:
    std::string *getName() const throw();
    rank_t getLevel() const throw();
    Nullable<id_t> getClassId() const throw();
    Class *getClass() const;
    void setName(std::string const &val);
    void setLevel(rank_t val);
    void setClassId(id_t val);
    void setClass(Class const &val);
    void EndUpdate();
};

class ClassLesson : public virtual DBObject {
private:
    id_t course, classid;
public:
    id_t getCourseId() const throw();
    id_t getClassId() const throw();
    Course *getCourse() const;
    Class *getClass() const;
    void EndUpdate();
};

class StudentLesson : public virtual DBObject {
private:
    id_t course, student;
public:
    id_t getCourseId() const throw();
    id_t getStudentId() const throw();
    Course *getCourse() const;
    Student *getStudent() const;
    void EndUpdate();
};

#endif