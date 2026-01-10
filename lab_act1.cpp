#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main (int argc, char *arg[]) {
    pid_t pid = fork();
     if (pid < 0)
        {
            cerr << "fork failed" << endl;
            return 1;
        }
     else if (pid == 0)
        {
            execlp("whoami", "whoami", (char *)NULL);
            cerr << "execlp failed" << endl;
            return 1;
        }
     else
        {
            cout << "Process ID is: " << getpid() << endl;
            wait (NULL);
            return 0;
        }
}
