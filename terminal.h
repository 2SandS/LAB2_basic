#pragma once
#ifndef TERMINAL_H
#define TERMINAL_H
#include <iostream>
#include <iomanip>
#include<string>

using namespace std;

namespace Class1 {

    class Terminal {
    private:
        bool isInput;
        int connectionCount;
        int signalState;

    public:
        Terminal(bool input, int connections, int state);
        Terminal(bool input);
        Terminal();

        bool getIsInput() const;
        int getConnectionCount() const;
        int getSignalState() const;

        void setIsInput(bool input);
        void setConnectionCount(int count);
        void setSignalState(int state);

        Terminal& operator++();
        Terminal& operator--();
        void operator>>(Terminal& inputTerminal);
        void disconnect(Terminal& inputTerminal);
        void print() const;

        friend ostream& operator<<(ostream& os, const Terminal& terminal);
        friend istream& operator>>(istream& is, Terminal& terminal);


        ~Terminal() {}
    };
}
#endif TERMINAL_H