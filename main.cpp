#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#include "modules/algorithms.h"
#include "lib/termcolor.hpp"
#include <filesystem>
#include <thread>
#include "modules/generate.h"
#include "modules/connect.h"

// OldTeam | by lomaster

using namespace termcolor;
namespace fs = std::filesystem;
fs::create_directories("out"); // Create folder
algorithms alg;
files f;
generatealg ga;
connect c;

std::string what;
std::string temp;
std::string what1;
std::string what2;
std::string what3;
int what4;
int temp_gen;
int gen_count;

void HelpMenu()
{
    system("clear");
    std::cout << "\n  PhotoHostKiller - by lomaster | OldTeam\n\n";
    std::cout << "    usage:\n";
    std::cout << "      ./parser [options]     run parser\n\n";
    std::cout << "    options:\n";
    std::cout << "      -D, --domain           set domain\n";
    std::cout << "      -F, --format           set format\n";
    std::cout << "      -P, --path             set path\n";
    std::cout << "      -G, --generate         set method\n";
    std::cout << "      -GC, --generatecount   set generate lenght\n\n";
    std::cout << "      -C, --count            set count\n\n";
    std::cout << "    optional arguments:\n";
    std::cout << "      -h, --help            show this help message\n\n";
}

int a2i(const char *s)
{
    int sign = 1;
    if (*s == '-')
    {
        sign = -1;
        s++;
    }
    int num = 0;
    while (*s)
    {
        num = ((*s) - '0') + num * 10;
        s++;
    }
    return num * sign;
}

void Check()
{
    std::cout << "\n";
    std::cout << "  PhotoHostKiller C++ " << f.VersionCheck();
    std::cout << "";
    std::cout << "\n  ---------------------------------------------";
    if (c.CheckNet() == true)
    {
        std::cout << "\n  | Connect...." << green << "true\n"
                  << reset;
    }
    else
    {
        std::cout << "\n  | Connect.... " << red << "false\n"
                  << reset;
        exit(1);
    }
    std::cout << "  | Folder...." << green << "true\n"
              << reset;
    std::cout << "  ---------------------------------------------\n";
    std::cout << "  | Domain...." << green << what1 << reset << std::endl;
    if (std::filesystem::exists(what3))
    {
        std::cout << "  | Path...." << green << what3 << reset << std::endl;
        std::cout << "  | Format...." << green << what2 << reset << std::endl;
        std::cout << "  | Gen.Mode...." << green << temp_gen << reset << std::endl;
        std::cout << "  | Gen.Lenght...." << green << gen_count << reset << std::endl;
        std::cout << "  | Count...." << green << what4 << reset << std::endl;
        std::cout << "  ---------------------------------------------\n";
    }
    else
    {
        std::cout << "  ---------------------------------------------\n";
        std::cout << red << "  ERROR: path not found\n"
                  << reset;
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        if (argv[0])
            HelpMenu();
        exit(1);
    }
    while (true)
    {
        if (std::string(argv[1]) == "-D" || std::string(argv[1]) == "--domain")
        {
            what1 = argv[2];
        }
        if (std::string(argv[3]) == "-F" || std::string(argv[3]) == "--format")
        {
            what2 = argv[4];
        }
        if (std::string(argv[5]) == "-P" || std::string(argv[5]) == "--path")
        {
            what3 = argv[6];
        }
        if (std::string(argv[7]) == "-G" || std::string(argv[7]) == "--generate")
        {
            temp_gen = a2i(argv[8]);
        }
        if (std::string(argv[9]) == "-GC" || std::string(argv[7]) == "--generatecount")
        {
            gen_count = a2i(argv[10]);
        }
        if (std::string(argv[11]) == "-C" || std::string(argv[9]) == "--count")
        {
            what4 = a2i(argv[12]);
            break;
        }
        if (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help")
        {
            HelpMenu();
            exit(1);
        }
        else
        {
            std::cout << "  Usage: ./parser --help\n";
            exit(1);
        }
    }
    system("clear");
    Check();
    std::cout << "  | run (y,n): ";
    std::cin >> what;
    if (what == "y" || what == "Y")
    {
#define RUN
    }
    else
    {
        system("clear");
        exit(1);
    }

#ifdef RUN
    std::cout << "  ---------------------------------------------\n";
    if (temp_gen == 1)
    {
        for (int i = 1; i <= what4; i++)
        {
            auto begin = std::chrono::steady_clock::now();
            alg.GrabPhotoStandart(what2, what1, what3, ga.GenerateMode(gen_count));
            auto end = std::chrono::steady_clock::now();
            auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

            if (f.CheckSize(alg.outFile) == true)
            {
                std::cout << bold << green << "  [+] " << reset << alg.outFile << blue << " << " << reset << alg.link << blue << " | " << reset << elapsed_ms.count() << " ms" << blue << " | " << reset << temp << yellow << " [" << i << "]" << reset << std::endl;
            }
            else
            {
                std::cout << bold << red << "  [-] " << reset << alg.outFile << blue << " << " << reset << alg.link << blue << " | " << reset << elapsed_ms.count() << " ms" << blue << " | " << reset << temp << yellow << " [" << i << "]" << reset << std::endl;
            }
        }
    }
    else if (temp_gen == 2)
    {
        for (int i = 1; i <= what4; i++)
        {
            auto begin = std::chrono::steady_clock::now();
            alg.GrabPhotoStandart(what2, what1, what3, ga.Generate(gen_count));
            auto end = std::chrono::steady_clock::now();
            auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

            if (f.CheckSize(alg.outFile) == true)
            {
                std::cout << bold << green << "  [+] " << reset << alg.outFile << blue << " << " << reset << alg.link << blue << " | " << reset << elapsed_ms.count() << " ms" << blue << " | " << reset << temp << yellow << " [" << i << "]" << reset << std::endl;
            }
            else
            {
                std::cout << bold << red << "  [-] " << reset << alg.outFile << blue << " << " << reset << alg.link << blue << " | " << reset << elapsed_ms.count() << " ms" << blue << " | " << reset << temp << yellow << " [" << i << "]" << reset << std::endl;
            }
        }
    }
    else if (temp_gen == 3)
    {
        for (int i = 1; i <= what4; i++)
        {
            auto begin = std::chrono::steady_clock::now();
            alg.GrabPhotoStandart(what2, what1, what3, ga.GenerateMode1(gen_count));
            auto end = std::chrono::steady_clock::now();
            auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

            if (f.CheckSize(alg.outFile) == true)
            {
                std::cout << bold << green << "  [+] " << reset << alg.outFile << blue << " << " << reset << alg.link << blue << " | " << reset << elapsed_ms.count() << " ms" << blue << " | " << reset << temp << yellow << " [" << i << "]" << reset << std::endl;
            }
            else
            {
                std::cout << bold << red << "  [-] " << reset << alg.outFile << blue << " << " << reset << alg.link << blue << " | " << reset << elapsed_ms.count() << " ms" << blue << " | " << reset << temp << yellow << " [" << i << "]" << reset << std::endl;
            }
        }
    }
    else
    {
        std::cout << red << "  ERROR: generate mode (1-3)\n"
                  << reset;
        exit(1);
    }
#endif
    return 0;
}
