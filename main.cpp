#include <iostream>
#include <direct.h>
using namespace std;
void printSystemInfo()
{
    cout<<__FILE__<<endl;
    cout<<__LINE__<<endl;
    cout<<__FUNCTION__<<endl;
}
int main() {
//    char buf[1024];
//    _getcwd(buf, sizeof(buf));
//    printf("%s\n",buf);
//    perror("error in:%s\n");
    printSystemInfo();
    return 0;
}
