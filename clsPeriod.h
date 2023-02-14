#pragma once
#include "clsDate.h"

class clsPeriod
{
public:

    clsDate StartDate;
    clsDate EndDate;

    clsPeriod(clsDate StartDate, clsDate EndDate)
    {
        this->StartDate = StartDate;
        this->EndDate = EndDate;

    }

    void Print()
    {
        cout << "Period Start: ";
        StartDate.Print();


        cout << "Period End: ";
        EndDate.Print();


    }


    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {

        if (
            clsDate::CompareDates(Period2.EndDate, Period1.StartDate) == clsDate::enDateCompare::Before
            ||
            clsDate::CompareDates(Period2.StartDate, Period1.EndDate) == clsDate::enDateCompare::After
            )
            return false;
        else
            return true;

    }
    bool IsOverlapPeriods(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }

  
    static int PeriodLengthIndDays(clsDate StartDate, clsDate EndDate, bool IncludeEndDay = false)
    {
        return clsDate::GetDifferenceInDays(StartDate, EndDate, IncludeEndDay);
    }
    int PeriodLengthIndDays(bool IncludeEndDay = false)
    {
        return PeriodLengthIndDays(this->StartDate, this->EndDate, IncludeEndDay);
    }

    static bool IsDateWithInPeriod(clsDate Date, clsPeriod Period)
    {
        return (clsDate::IsDate1AfterDate2(Date, Period.StartDate) && clsDate::IsDate1BeforeDate2(Date, Period.EndDate));
    }
    bool IsDateWithInPeriod(clsDate Date)
    {
        return IsDateWithInPeriod(Date, *this);
    }

    static int CountOverlapDays(clsPeriod Period1 ,clsPeriod Period2)
    {
        int Days = 0;
        if (!IsOverlapPeriods(Period1, Period2))
            return 0;

        if (IsDateWithInPeriod(Period1.StartDate, Period2))
        {
            while (clsDate::IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate) && clsDate::IsDate1BeforeDate2(Period1.StartDate, Period2.EndDate))
            {
                Days++;
                Period1.StartDate = clsDate::AddOneDay(Period1.StartDate);
            }
        }
        else
        {
            while (clsDate::IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate) && clsDate::IsDate1BeforeDate2(Period2.StartDate, Period1.EndDate))
            {
                Days++;
                Period2.StartDate = clsDate::AddOneDay(Period2.StartDate);
            }
        }

        return ++Days;
    }


};
