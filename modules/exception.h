#pragma once

#include "print.h"

class Exception {
private:
    std::string m_message;

public:
    const std::string kEmpty{"Empty"};

    const std::string kInvalidPosition{"Invalid position"};
    const std::string kInvalidIndex{"Invalid index"};
    const std::string kInvalidValue{"Invalid value"};

    const std::string kItemDoesNotExist{"Item does not exist"};

    Exception() {}
    Exception(std::string message) {
        m_message = message;

        if (m_message != "")
            PrintError();
    };

    void PrintError() {
        Print(m_message);
    };
};
