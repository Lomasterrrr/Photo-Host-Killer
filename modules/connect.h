#include <iostream>
#include "files.h"

class connect
{
private:
public:
    files f;
    void DownloadFile(const char *link, const char *outfile);
    bool CheckNet();

};



