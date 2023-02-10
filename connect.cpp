#include "modules/connect.h"
#include "modules/clear.h"
#include "lib/curl.h"
void connect::DownloadFile(const char *link, const char *outfile)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;

    curl = curl_easy_init();

    if (curl)
    {
        fp = fopen(outfile, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, link);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl");
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
}

bool connect::CheckNet()
{
    CURL *curl;
    CURLcode result;

    static char errorBuffer[CURL_ERROR_SIZE];

    static std::string buffer;
    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, ClearWrite);
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");

        result = curl_easy_perform(curl);
        if (result == CURLE_OK)
            return true;
        else
            return false;
    }
    return false;
}