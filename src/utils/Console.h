#pragma once
#ifndef CRYFS_CONSOLE_H
#define CRYFS_CONSOLE_H

#include <string>
#include <vector>
#include <iostream>
#include <boost/optional.hpp>

class Console {
public:
    virtual unsigned int ask(const std::string &question, const std::vector<std::string> &options) = 0;
    virtual bool askYesNo(const std::string &question) = 0;
    virtual void print(const std::string &output) = 0;
};

class IOStreamConsole: public Console {
public:
    IOStreamConsole();
    IOStreamConsole(std::ostream &output, std::istream &input);
    unsigned int ask(const std::string &question, const std::vector<std::string> &options) override;
    bool askYesNo(const std::string &question) override;
    void print(const std::string &output) override;
private:
    template<typename Return>
    Return _askForChoice(const std::string &question, std::function<boost::optional<Return> (const std::string&)> parse);

    std::ostream &_output;
    std::istream &_input;
};


#endif
