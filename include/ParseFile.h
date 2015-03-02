/**
 * @file ParseFile.h
 * @brief Parse a file with given delimeter
 * @author Sohel Tarir
 * @version 1.0
 * @date 2014-04-28
 */
#ifndef _PARSEFILE_H_
#define _PARSEFILE_H_
#include <stdio.h>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <iostream>
#include <vector>
#include <stdexcept>

namespace STLibs{
	class ParseFile
	{
		public:
			/**
			 * @brief Constructor for the class ParseFile
			 *
			 * @param szFile	The entire file path
			 * @param cDelim	Single charactor Delimimter
			 */
			ParseFile(const char* szFile, char cDelim);
			~ParseFile ();
			/**
			 * @brief Retrieves the specific token
			 *
			 * @param nRow The Row number of the token (0...n-1)
			 * @param nCol The Column number of the token (0...n-1)
			 *
			 * @return 
			 */
			std::string GetElement(int nRow, int nCol);
			/**
			 * @brief Gets the total number of columns present for specifc row
			 *
			 * @param nRow The Row number
			 *
			 * @return 
			 */
			int ColumnCount(int nRow);
			/**
			 * @brief Returns the Total number of rows in the file
			 *
			 * @return 
			 */
			int RowCount();
		private:
			bool InitTokens(const char* szFile, char cDelim);	
			int m_nRows;
			std::map <int, std::vector<std::string> > m_mapElements;
			std::map <int, int> m_mapColCount;
	};
}
#endif
