#include <unistd.h>    // for fork(), write()
#include <stdio.h>     // for printf()
#include <fcntl.h>     // for open(), O_RDWR
#include <string.h>    // for strlen()
#include <iostream>

int main() {
    int rc = fork();

    if (rc == 0) {
        // child process
        std::cout << "hello\n";
    }
    else {
        // parent process
        wait(NULL);
        std::cout << "goodbye\n";
    }
}