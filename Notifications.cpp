// Name:  Kenneth Yue
// Seneca Student ID: 127932176
// Seneca email:  kyue3@myseneca.ca
// Date of completion: Oct 03, 2018
//
// I confirm that the content of this file is created by me,
// with exception of the parts provided to me by my professor

#include <iostream>
#include "Notifications.h"

using namespace w4;

// set all pointers to null
void Notifications::nullAll() {
    for (size_t i = 0; i < max; ++i) {
        msgs[i] = nullptr;
    }
}

// default constructor
Notifications::Notifications() {
    nullAll();
}

// destructor
Notifications::~Notifications() {
    for (size_t i = 0; i < max; ++i) {
        delete msgs[i];
    }
}

// copy constructor
Notifications::Notifications(Notifications& other) {
    nullAll();
    *this = other;
}

// copy assignment
Notifications& Notifications::operator=(Notifications& other) {
    // check for self assignment
    if (this != &other) {
        size = other.size;
        // iterate through the array
        for (size_t i = 0; i < max; ++i) {
            // delete old message;
            delete msgs[i];

            // check for nullptr;
            if (!other.msgs[i]) {
                msgs[i] = nullptr;
            } else {
                msgs[i] = new Message(*other.msgs[i]);    
            }
        }
    }
    
    return *this;
}

// move constructor
Notifications::Notifications(Notifications&& other) {
    nullAll();
    *this = std::move(other);
}

// move assignment
Notifications& Notifications::operator=(Notifications&& other) {
    if (this != &other) {
        size = other.size;
        // iterate through the array
        for (size_t i = 0; i < size; ++i) {
            // delete old message;
            delete msgs[i];
            // check for nullptr;
            if (!other.msgs[i]) {
                msgs[i] = nullptr;
            } else {
                // transfer ownership
                msgs[i] = other.msgs[i];   
                other.msgs[i] = nullptr; 
            }
        }
    }

    return *this;
}

void Notifications::operator+=(const Message& other) {
    if (size < max) {
        // add new message to arrays
        msgs[size] = new Message(other);
        ++size; 
    } else {
        std::cout << "Notification List is full!!" << std::endl;
    }
}

void Notifications::display(std::ostream& os) const {
    for (size_t i = 0; i < size; ++i) {
        if (msgs[i]) {
            msgs[i]->display(os);        
            os << std::endl;
        }
    }
}