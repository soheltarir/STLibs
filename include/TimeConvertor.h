/**
 * @file TimeConvertor.h
 * @brief All relevant functions to convert time from Epoch format to other formats, and vice-versa 
 * @author Sohel Tarir
 * @version 1.0
 * @date 2014-10-07
 */
#ifndef _TIMECONVERTOR_H_
#define _TIMECONVERTOR_H_

#include <iostream>
#include <time.h>
#include <stdio.h>

namespace STLibs{
    /**
     * @brief Converts time from Epoch format to HH:MM:SS (H = Hours; M = Minutes; S = Seconds)
     *
     * @param nEpochTime: Time in seconds since 1st January 1970
     *
     * @return 
     */
    const char* epoch2hhmmss (long int nEpochTime);

    /**
     * @brief Converts time from Epoch format to HH:MM (H = Hours; M = Minutes)
     *
     * @param nEpochTime: Time in seconds since 1st January 1970

     *
     * @return 
     */
    const char* epoch2hhmm (long int nEpochTime);

    /**
     * @brief Converts time from Epoch format to the corresponding date format as specified by the user
     *
     * @param nEpochTime: Time in seconds since 1st January 1970
     * @param szFormat: For Example if the date format required is YYYY/MM/DD (Y = Year; M = Month; D = Date), the input should be then "%Y/%m/%d" 
     *
     * @return 
     */
    const char* epoch2date (long int nEpochTime, const char* szFormat);

    /**
     * @brief Converts time from the Time format of the current day given to Epoch format
     *
     * @param szTime : The Time that needs to be converted   
     * @param szFormat : The format of the time input. For eg, if the time is 19:40:06 the format should be given as "HH:MM:SS"
     *
     * @return : -1 if fails to convert
     */
    long int time2epoch (const char* szTime, const char* szFormat);

    /**
     * @brief Converts the time and date of the given format to epoch format
     *
     * @param szTimeDate : The time-date input
     * @param szFormat : The format of the time-date input. For eg, if the input is 2014/10/07-09:10:55, the format should "%Y/%m/%d-%H:%M:%S"
     *
     * @return : -1 if fails to convert
     */
    long int datetime2epoch (const char* szTimeDate, const char* szFormat);
 
    /**
     * @brief Converts the date of the given format to epoch format
     *
     * @param szTimeDate : The date input
     * @param szFormat : The format of the date input. For eg, if the input is 2014/10/07, the format should "%Y/%m/%d"
     *
     * @return : -1 if fails to convert
     */
    long int date2epoch (const char* szDate, const char* szFormat);
}

#endif
