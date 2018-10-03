// Name:  Kenneth Yue
// Seneca Student ID: 127932176
// Seneca email:  kyue3@myseneca.ca
// Date of completion: Oct 03, 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

#ifndef W4_MESSAGE_H
#define W4_MESSAGE_H

#include <iostream>
#include <fstream>
#include <string>

namespace w4 {

    class Message {
        std::string user;
        std::string reply;
        std::string tweet;

        public:
            // default constructor
            Message(std::ifstream&, char);
            // returns if message is empty
            bool empty() const;
            // displays message
            void display(std::ostream&) const;   
    };

} // namespace w4

#endif // MESSAGE_H