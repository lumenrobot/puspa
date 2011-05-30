#include <iostream>
#include <string>
#include "Brain.h"
#include "Errors.h"
#include "ServerSocket.h"

using namespace std;

int main(int argc, char *const argv[])
{
    ServerSocket *socket;
    Brain *brain;

    cerr << "Loading myself...\n";
    try {
        cerr << "Loading my socket...\n";
        socket = new ServerSocket();
        cerr << "My socket is ready.\n";

        cerr << "Loading my brain...\n";
        brain = new Brain();
        cerr << "My brain is ready.\n";
    }
    catch (Error& error) {
        cerr << "Exception caught: " << error.message << ".\n";
    }
    catch (GetAddressInfoError& getAddressInfoError) {
        cerr << "Exception caught: " << getAddressInfoError.message << ".\n";
    }
    cerr << "I am ready.\n";
   
    string input, output;
    while (true) {
        cerr << "I'm waiting for someone to connect..\n";
        try {
            socket->listen();
            socket->accept();
            
            while (true) {
                socket->receive(input);
                cerr << "Received \"" << input << "\"\n";
                if (!brain->process(input))
                    continue;
                
                output = brain->getResponse();
                socket->send(output.c_str());
                cerr << "Sent \"" << output << "\"\n";
            }
        }
        catch (Error& error) {
            cerr << "Exception caught: " << error.message << ".\n";
        }
    }
    
    cerr << endl;
    
    delete brain;
    delete socket;
    
    return 0;
}
