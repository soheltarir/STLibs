/**
 * @file TimeConvertor.cpp
 * @brief  All relevant functions to convert time from Epoch format to other formats, and vice-versa 
 * @author Sohel Tarir
 * @version 1.0
 * @date 2014-10-07
 */

#include "TimeConvertor.h"

namespace STLibs{
    const char* epoch2hhmmss (long int nEpochTime){
        time_t now, m_time;
        struct tm* current;
        now = time(0);
        current = localtime(&now);
        struct tm t = {0};
        t.tm_year = current->tm_year; t.tm_mon = current->tm_mon; t.tm_mday = current->tm_mday; t.tm_hour = 0; t.tm_min = 0; t.tm_sec = 0;
        m_time = mktime(&t);
        long int intOutTime = nEpochTime - (long int)m_time;
        int Output, Hrs, Mins, Secs;
        Hrs = (int)(intOutTime/3600); Mins = (int)((intOutTime - Hrs*3600)/60); Secs = (int)(intOutTime - Hrs*3600 - Mins*60);
        Output = Hrs*10000 + Mins*100 + Secs;
        char strOutput[16] = "";
        sprintf(strOutput, "%02d:%02d:%02d", Hrs, Mins, Secs);
        return strOutput;
    }

    const char* epoch2hhmm (long int nEpochTime){
        time_t now, m_time;
        struct tm* current;
        now = time(0);
        current = localtime(&now);
        struct tm t = {0};
        t.tm_year = current->tm_year; t.tm_mon = current->tm_mon; t.tm_mday = current->tm_mday; t.tm_hour = 0; t.tm_min = 0; t.tm_sec = 0;
        m_time = mktime(&t);
        long int intOutTime = nEpochTime - (long int)m_time;
        int Output, Hrs, Mins, Secs;
        Hrs = (int)(intOutTime/3600); Mins = (int)((intOutTime - Hrs*3600)/60); Secs = (int)(intOutTime - Hrs*3600 - Mins*60);
        Output = Hrs*10000 + Mins*100 + Secs;
        char strOutput[16] = "";
        sprintf(strOutput, "%02d:%02d", Hrs, Mins);
        return strOutput;

    }

    const char* epoch2date(long int nEpochTime, const char* szFormat){
        time_t epoch = (time_t)nEpochTime;
        struct tm *m_tm = localtime(&epoch);
        char strOutput[16] = "";
        strftime(strOutput, 16, szFormat, m_tm);
        return strOutput;
    }

    long int datetime2epoch (const char* szTimeDate, const char* szFormat){
        struct tm tm; time_t epoch;
        if (strptime (szTimeDate, szFormat, &tm) != NULL){
            epoch = mktime(&tm);
            return (long int)epoch;
        }
        else{
            return -1;
        }
    }

    long int time2epoch(const char* szTime, const char* szFormat){
        time_t now;
        struct tm* current;
        now = time(0);
        const char* szCurrDate = epoch2date((long int)now, "%Y%m%d");
        char szNewFormat[32] = "", szTimeDate[32] = "";
        sprintf(szNewFormat, "%%Y%%m%%d-%s", szFormat);
        sprintf(szTimeDate, "%s-%s", szCurrDate, szTime);
        long int nOutput = datetime2epoch(szTimeDate, szNewFormat);
        return nOutput;
    }

    long int date2epoch(const char* szDate, const char* szFormat){
        char szTimeDate[32] = "", szNewFormat[32] = "";
        sprintf(szNewFormat, "%s-%%H:%%M:%%S", szFormat);
        sprintf(szTimeDate, "%s-%02d%02d%02d", szDate, 0, 0, 0);
        long int nOutput = datetime2epoch(szTimeDate, szNewFormat);
        return nOutput;
    }
}
