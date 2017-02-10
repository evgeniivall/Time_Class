#include "time_class.h"
#include <cmath>

Time& Time::operator=(const Time& time)
{
    hours_ = time.hours_;
    minuts_ = time.minuts_;
    seconds_ = time.seconds_;
    return *this;
}

Time::Time(const Time& time)
{
    hours_ = time.hours_;
    minuts_ = time.minuts_;
    seconds_ = time.seconds_;
}

bool Time::isTimeCorrect()
{
    if(hours_ > HOUR_MAX)
        return 0;
    if(minuts_ > MINUTE_MAX)
        return 0;
    if(seconds_ > SECOND_MAX)
        return 0;
    return 1;
}

Time& Time::Add(us hours, us minuts, us seconds)
{
    seconds_ = seconds_ + seconds;
    minuts_ = minuts_   + seconds_/60;
    seconds_ %= SECOND_MAX;

    minuts_ = minuts_ + minuts;
    hours_ = hours_ + minuts_/60;
    minuts_ %= MINUTE_MAX;

    hours_ = hours_ + hours;
    hours_ %= HOUR_MAX;

   return *this;
}

Time& Time::Sub(us hours, us minuts, us seconds)
{
    minuts = minuts + (seconds/SECOND_MAX);
    seconds = seconds%SECOND_MAX;
    if(seconds_ < seconds)
    {
        minuts_--;
        seconds_ = seconds_ + SECOND_MAX;
    }
    seconds_ = seconds_ - seconds;


    hours = hours +(minuts/MINUTE_MAX);
    minuts = minuts&MINUTE_MAX;
    if(minuts_ < minuts)
    {
        hours_--;
        minuts_ = minuts_ + MINUTE_MAX;
    }
    minuts_ = minuts_ - minuts;

    hours %= HOUR_MAX;
    hours_ = hours_ - hours;

    return *this;
}

Time Time::operator-(const Time& time)
{
    Time temp(*this);
    temp.Sub(time.hours_, time.minuts_, time.seconds_);
    return temp;
}

Time& Time::operator ++()
{
    seconds_++;
    if(seconds_ > SECOND_MAX)
    {
        seconds_ = 0;
        minuts_++;
        if(minuts_ > MINUTE_MAX)
        {
            minuts_ = 0;
            hours_++;
            if(hours_ > HOUR_MAX)
            {
                hours_ = 0;
            }
        }
    }
    return *this;
}

Time& Time::operator --()
{
    seconds_--;
    if(seconds_ < 0)
    {
        seconds_ = SECOND_MAX;
        minuts_--;
        if(minuts_ < 0)
        {
            minuts_ = MINUTE_MAX;
            hours_--;
            if(hours_ < 0)
            {
                hours_ = HOUR_MAX;
            }
        }
    }
    return *this;
}

Time Time::operator+(const Time& time)
{
    Time temp(*this);
    this -> Add(time.hours_, time.minuts_, time.seconds_);
    return temp;
}

bool Time::operator < (const Time& time)const
{
    if(hours_ > time.hours_)
        return 0;
    if(minuts_ > time.minuts_)
        return 0;
    if(seconds_ > time.seconds_)
        return 0;
    return 1;
}
bool Time::operator > (const Time& time)const
{
    return (time < (*this));
}
bool Time::operator == (const Time& time)const
{
    return (hours_ == time.hours_)&&(minuts_ == time.minuts_)&&(seconds_ == time.seconds_);
}
bool Time::operator != (const Time& time)const
{
    return (!(*this == time));
}
bool Time::operator <= (const Time& time)const
{
    return (!(*this > time));
}
bool Time::operator >= (const Time& time)const
{
    return (!(*this < time));
}
