/**
* @file ParseFile.cpp
* @brief Parse a file with given delimeter
* @author Sohel Tarir
* @version 1.0
* @date 2014-10-06
*/

#include "ParseFile.h"

namespace STLibs{
	ParseFile::ParseFile(const char* szFile, char cDelim){
		std::cout << "[STLibs::ParseFile] : Constructor called..." << std::endl;
		std::cout << "[STLibs::ParseFile] : Parsing file " << szFile << " with delimeter \"" << cDelim <<"\" " << std::endl;
		m_nRows = 0;	
		if (!InitTokens(szFile, cDelim)){
			std::cout << "STLibs::ParseFile] : Failed to read file " << szFile << std::endl;
			this->~ParseFile();
		}
	}
	ParseFile::~ParseFile(){
		std::cout << "[STLibs::ParseFile] : Destructor Called!" << std::endl;
	}
	bool ParseFile::InitTokens(const char* szFile, char cDelim){
		std::ifstream pFile (szFile);
		if (pFile.is_open()){
			while (pFile){
				std::string strLine;
				if (!getline(pFile, strLine))	break;
				std::istringstream ssLine(strLine);
				int nCols = 0;
				while (ssLine){
					std::string strCol;
					if (!getline(ssLine, strCol, cDelim))	break;
					m_mapElements[m_nRows].push_back(strCol);
					nCols++;
				}
				m_mapColCount[m_nRows] = nCols;
				m_nRows++;	
			}
		}
		else
			return false;
		return true;
	}
	int ParseFile::RowCount(){
		return m_nRows;
	}
	
	std::string ParseFile::GetElement(int nRow, int nCol){
		std::string strToken = "";
		try{
			strToken = m_mapElements[nRow].at(nCol);
		}
		catch (const std::out_of_range& oor) {
			std::cerr << "Out of Range error: " << oor.what() << '\n';
		}
		return strToken;
	}
	
	int ParseFile::ColumnCount(int nRow){
		int nCols = 0;
		nCols = m_mapColCount[nRow] + 1;
		return nCols;
	}
}	
