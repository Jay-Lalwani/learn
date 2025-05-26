#include <unistd.h>    // for fork(), write()
#include <stdio.h>     // for printf()
#include <fcntl.h>     // for open(), O_RDWR
#include <string.h>    // for strlen()

int main() {
    int fd = open("test.txt", O_RDWR);
    int rc = fork();

    if (rc < 0) {
        printf("Error");
        return -1;
    }

    if (rc == 0) {
        // child process
        lseek(fd, 0, SEEK_SET);
        char *data = "This\nis\nchild\n";
        write(fd, data, strlen(data));
    }
    else {
        lseek(fd, 0, SEEK_SET);
        char *data = "This\nis\nparent\n";
        write(fd, data, strlen(data));
    }
}