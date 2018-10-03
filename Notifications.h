// Name:  Kenneth Yue
// Seneca Student ID: 127932176
// Seneca email:  kyue3@myseneca.ca
// Date of completion: Oct 03, 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

#ifndef W4_NOTIFICATIONS_H
#define W4_NOTIFICATIONS_H

#include "Message.h"

namespace w4 {
    class Notifications {
        size_t max = 10;
        size_t size;
        
        Message* msgs[10];

        void nullAll();

        public:
            // default constructor
            Notifications();
            // destructor
            ~Notifications();
            // copy constructor
            Notifications(Notifications&);
            // copy assignment
            Notifications& operator=(Notifications&);
            // move constructor
            Notifications(Notifications&&);
            // move assignment
            Notifications& operator=(Notifications&&);
            // adds a message to the array
            void operator+=(const Message&);
            // displays the array of messages
            void display(std::ostream&) const;
    };

} // namespace w4


#endif // NOTIFICATIONS_H