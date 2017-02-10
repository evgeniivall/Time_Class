#ifndef TIME_H
#define TIME_H

#include <time.h>

#include <iostream>
#define SECOND_MAX 60
#define MINUTE_MAX 60
#define HOUR_MAX 24

typedef int us;

class Time
{
private:
    us hours_;
    us minuts_;
    us seconds_;
    bool isTimeCorrect();

public:
    Time(us hours = 0, us minuts = 0, us seconds = 0): hours_(hours), minuts_(minuts), seconds_(seconds)
    {
        if(!(this->isTimeCorrect()))
        {
            hours_ = 0;
            minuts_ = 0;
            seconds_ = 0;
        }
    }
    Time(const Time& time);
    void SetCurrentTime()
    {
        time_t t = time(NULL);
        tm* aTm = localtime(&t);
        hours_ = aTm->tm_hour;
        minuts_ = aTm->tm_min;
        seconds_ = aTm->tm_sec;
    }

    Time& Add(us hours = 0, us minuts = 0, us seconds = 0);
    Time& Sub(us hours = 0, us minuts = 0, us seconds = 0);

    Time& operator =(const Time&);
    Time& operator ++();
    Time& operator --();

    Time operator +(const Time&);
    Time operator -(const Time&);

    bool operator < (const Time&)const;
    bool operator > (const Time&)const;
    bool operator ==(const Time&)const;
    bool operator !=(const Time&)const;
    bool operator <=(const Time&)const;
    bool operator >=(const Time&)const;

    friend std::ostream& operator <<(std::ostream &os, const Time& time)
    {
        if(time.hours_ < 10)
            os << 0 << time.hours_ << ':' ;
        else
            os << time.hours_<< ':' ;;
        if(time.minuts_ < 10)
            os << 0 << time.minuts_<< ':' ;
        else
            os << time.minuts_<< ':' ;;
        if(time.seconds_ < 10)
            os << 0 << time.seconds_ ;
        else
            os << time.seconds_;

        return os;
    }

    friend std::istream& operator >>(std::istream &is, Time& time);
};

#endif // TIME_H
