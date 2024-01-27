#include "terminal.h"
namespace Class1 {
    
    Terminal::Terminal() : isInput(true), connectionCount(0), signalState(-1) {
    }

    Terminal::Terminal(bool input, int connections, int state) : isInput(input), connectionCount(connections), signalState(state) {

        if (isInput && connectionCount > 1) {
            cout << "Error: Input terminal cannot have more than 1 connection." << endl;
            connectionCount = 1;
        }

        if (!isInput && connectionCount > 3) {
            cout << "Error: Output terminal cannot have more than 3 connections." << endl;
            connectionCount = 3;
        }

        if (isInput && connectionCount == 0) {
            signalState = -1; // "X" 
        }

        if (connectionCount < 0) {
            cout << "Error: Negative digit";
        }
    }

    Terminal::Terminal(bool input) : isInput(input), connectionCount(0), signalState(-1) {
    }

    bool Terminal::getIsInput() const {
        return isInput;
    }

    int Terminal::getConnectionCount() const {
        return connectionCount;
    }

    int Terminal::getSignalState() const {
        return signalState;
    }

    void Terminal::setIsInput(bool input) {
        isInput = input;
    }

    void Terminal::setConnectionCount(int count) {
        
        // Проверки на допустимые значения
        if (isInput && count > 1) {
            cout << "Error: Input terminal cannot have more than 1 connection." << endl;
            connectionCount = 1;
        }

        else if (!isInput && count > 3) {
            cout << "Error: Output terminal cannot have more than 3 connections." << endl;
            connectionCount = 3;
        }

        else if (count < 0) {
            cout << "Error: negative digit";
        }

        else connectionCount = count;

    }

    void Terminal::setSignalState(int state) {
        if (state == 1 || state == 0 || state == -1) {
            signalState = state;
        }
        else {
            cout << "Error: Invalid value for signal state. Valid values are 1, 0, or -1." << endl;
        }
    }

    Terminal& Terminal::operator++() {
        if (connectionCount < (isInput ? 1 : 3)) {
            connectionCount++;
        }
        else {
            cout << "Error: Cannot increase connection count too many." << endl;
        }
        return *this;
    }

    Terminal& Terminal::operator--() {
        if (connectionCount > 0) {
            connectionCount--;
        }
        else {
            cout << "Error: Connection count must be >= 0." << endl;
        }
        return *this;
    }

    void Terminal::operator>>(Terminal& inputTerminal) {
        if (!isInput && inputTerminal.isInput && connectionCount < 3 && inputTerminal.connectionCount == 0) { // Соединяются именно выходная и входная
            inputTerminal.signalState = signalState;
            connectionCount++;
            inputTerminal.connectionCount++;
        }
        else {
            cout << "Error: Invalid connection between terminals." << endl;
        }
    }

    void Terminal::disconnect(Terminal& inputTerminal) { // Предполагается что клеммы были соединены (из условия)
        if (!isInput && inputTerminal.isInput || isInput && !inputTerminal.isInput) {
            // Сбрасываем сигнала в виде установки значения в "X" = -1
            inputTerminal.signalState = -1;
            signalState = -1;
            connectionCount--;
            inputTerminal.connectionCount--;
        }
        else {
            cout << "Error: Invalid disconnection between terminals." << endl;
        }
    }

    void Terminal::print() const {
        cout << "Connection:" << this->connectionCount << endl;
        cout << "Signal:" << this->signalState << endl;
        cout << "Type:" << this->isInput << endl;
    }

    ostream& operator<<(ostream& os, const Terminal& terminal) {
        os << "Connection: " << terminal.connectionCount << endl;
        os << "Signal: " << terminal.signalState << endl;
        os << "Type: " << (terminal.isInput ? "Input" : "Output") << endl;
        return os;
    }

    istream& operator>>(istream& is, Terminal& terminal) {
        string type;
        Terminal tmp;

        //while (true) {
            //cout << "Enter terminal type (Input/Output): ";
            is >> type;

            if (type == "Input") {
                tmp.isInput = true;
                //break;  
            }
            else if (type == "Output") {
                tmp.isInput = false;
                //break;  
            }
            else {
                is.setstate(std::ios_base::failbit);
                return is;
                //cout << "Error: Invalid terminal type. Please enter either 'Input' or 'Output'." << endl;
                
            }
        //}

        //while (true) {
            //cout << "Enter connection count: ";
            is >> tmp.connectionCount;

            if ((tmp.isInput && tmp.connectionCount == 1 || tmp.isInput && tmp.connectionCount == 0) || (!tmp.isInput && tmp.connectionCount <= 3 && tmp.connectionCount >= 0)) {
                //break;
            }
            else {
                is.setstate(std::ios_base::failbit);
                return is;
               // cout << "Error: Invalid connection count. Please enter a valid value." << endl;
            }
        //}

        //while (true) {
            //cout << "Enter signal state: ";
            is >> tmp.signalState;

            if (tmp.signalState == 0 || tmp.signalState == 1 || tmp.signalState == -1) {
                //break;  
            }
            else {
                //cout << "Error: Invalid signal state. Please enter 0, 1, or -1." << endl;
                is.setstate(std::ios_base::failbit);
                return is;
            }
            terminal = tmp;
            return is;
        //}

        //return is;
    }

}