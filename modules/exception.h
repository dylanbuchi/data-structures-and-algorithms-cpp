#pragma once

#include "print.h"

class Exception {
private:
    std::string m_message;

public:
    Exception();
    Exception(std::string message) {
        m_message = message;

        if (m_message != "")
            PrintError();
    };

    void PrintError() {
        print(m_message);
    };
};
