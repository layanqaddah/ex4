//
// Created by Layan & Omar on 6/13/2022.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H


//Error messages are initialized in Mtmchkin.cpp

class DeckFileException : public std::runtime_error
{
public:
    DeckFileException(const std::string& what): std::runtime_error(what){};
protected:
    static const std::string BASE_MESSAGE;
};


class DeckFileNotFound : public DeckFileException
{
public:
    DeckFileNotFound():
                     DeckFileException(BASE_MESSAGE + FILE_NOT_FOUND_ERROR){};
private:
    static const std::string FILE_NOT_FOUND_ERROR;
};


class DeckFileFormatError : public DeckFileException
{
public:
    DeckFileFormatError(const std::string& lineNumber):
                        DeckFileException(BASE_MESSAGE+FILE_FORMAT_ERROR+lineNumber){};
private:
    static const std::string FILE_FORMAT_ERROR;
};


class DeckFileInvalidSize : public DeckFileException
{
public:
    DeckFileInvalidSize():
                        DeckFileException(BASE_MESSAGE+INVALID_SIZE_ERROR){};
private:
    static const std::string INVALID_SIZE_ERROR;
};



#endif //EX4_EXCEPTION_H