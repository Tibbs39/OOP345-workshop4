// Name:  Kenneth Yue
// Seneca Student ID: 127932176
// Seneca email:  kyue3@myseneca.ca
// Date of completion: Oct 03, 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

#include <iostream>
#include <fstream>
#include <string>
#include "Message.h"

using namespace w4;

// constructor
Message::Message(std::ifstream& fin, char delim) {
    // getline up to delim and store in temp string
    int pos = 0;
    std::string temp;
    getline(fin, temp, delim);

    // parse the string
    pos = temp.find_first_of(' ');
    if (pos != -1) {
        user.assign(temp.substr(0,pos));
        temp.erase(0,pos+1);

        // check if there's an '@'
        if (temp.find('@') == 0) {
            pos = temp.find_first_of(' ');
            reply.assign(temp.substr(1,pos-1));
            temp.erase(0,pos+1);
        }

        // the remaining content should be the tweet
        tweet.assign(temp);
    }
}

// returns if tweet is empty
bool Message::empty() const {
    return tweet.empty();
}

void Message::display(std::ostream& os) const {
    if (!empty()) {
        os << "Message" << std::endl
        << " User  : " << user << std::endl;
        if (!reply.empty())
            os << " Reply : " << reply << std::endl;
        os << " Tweet : " << tweet << std::endl;
    }
}