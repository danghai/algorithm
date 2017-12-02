#include <stdio.h>
#include <stdarg.h>
#include"debug_macro.h"//

#define MAX_LINK_LENGTH (100)
#define MAX_NUM_LINK (20)

#define N_DUMMY_LINKS (5)
#define N_DUMMY_RESULT_SITE (2)

const char* DUMMY_RESULT_LINKS[] =
{
    #include"link.txt"
};

const char* DUMMY_HAS_SOURCE_CODE_SITE[]=
{
    "www.stackoverflow.com",
    "www.kipalog.com"
};

void search_google(char* keyword, char result[MAX_NUM_LINK][MAX_LINK_LENGTH], int *nResults)
{
    int i = 0;

    log_debug("Search google : (keyword=%s) START \n", keyword);

    for (i = 0; i < N_DUMMY_LINKS; i++)
    {
        strcpy(result[i], DUMMY_RESULT_LINKS[i]);
    }
    *nResults = N_DUMMY_LINKS;

    log_debug("Search google : (nResults=%d) END \n", *nResults);
}

int runSource(char* link)
{
    int retVal = 1;

    //log_debug("Run source in (link=%s) START \n",link);
    if (strstr(link, "www.kipalog.com") != NULL)
    {
        log_debug("OK, It works!!!!\n");
        retVal = 1;
    }
    else
    {
        log_err("Hmm, Bad source (link=%s) \n",link);
        retVal = 0;
    }
    //log_debug("Run source in (link=%s) END \n",link);

    return retVal;
}

int hasSampleSource(char* link)
{
    int i = 0;
    int retVal = 0;

    //log_debug("Check source (link=%s) START \n",link);
    for (i = 0; i < N_DUMMY_RESULT_SITE; i++)
    {
        if (strstr(link, DUMMY_HAS_SOURCE_CODE_SITE[i]) != NULL)
        {
            retVal = 1;
            break;
        }
    }
    //log_debug("Check source (link=%s) END \n",link);

    return retVal;
}

int main(int argc, char* argv[])
{
    char *keyword;
    char results[MAX_NUM_LINK][MAX_LINK_LENGTH];
    int nResults;
    int i = 0;

    // Kiểm tra tham số
    if (2 != argc)
    {
        log_err("Invalid parameter, usage: %s <keyword>\n",argv[0]);
        return 0;
    }

    keyword = argv[1];

    search_google(&keyword[0], results, &nResults);
    if (nResults > 0)
    {

        for (i = 0; i < nResults; i++)
        {
            log_debug("Try (link=%s) \n",results[i]);
            if (hasSampleSource(results[i]))
                runSource(results[i]);
            else
                log_err("No source in link :%s\n", results[i]);          
        }
    }
    else{
        log_err("Keyword is so difficult (keyword=%s) \n", keyword);
    }
    printf ("Program End \n");
    return 0;
}
