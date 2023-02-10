#include "modules/algorithms.h"
#include <iostream>
#include "modules/generate.h"
#include "modules/connect.h"
#include <bits/stdc++.h>
#include "lib/termcolor.hpp"

void algorithms::GrabPhotoStandart(std::string format, std::string site, std::string path, std::string token)
{
    generatealg ga;
    connect c;

    resultGen = token;
    outFile = path + resultGen + format;
    link = "https://" + site + "/" + resultGen + format;

    const char *linkConverted = link.c_str();
    const char *outFileConverted = outFile.c_str();
    c.DownloadFile(linkConverted, outFileConverted);
}
