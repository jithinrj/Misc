#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <cstring>
using std::tolower;

int main()
{
    char *strin;
    string inputstr;
    vector<string> svec;
    vector<int> cvec;
    char *pch;
    int unique_word_count=0;
    while(getline(cin,inputstr))
    {
        //token-ize the string
        //First string
        strin = &inputstr[0];
        pch = std::strtok(strin," ,-");
        bool unique_word_found = true;
        //subsequent words
        while (pch != NULL)
        {
            string word(pch);
            for(string::size_type i=0; i < word.size(); i++)
                word[i]=tolower(word[i]);
            //first word
            //just add to svec and no comparisons
            if(unique_word_count==0)
            {
                svec.push_back(word);
                cvec.push_back(1);
                cvec[unique_word_count++]=1; //init count of first word
                //next word
                pch = std::strtok(NULL, " ,-");
                unique_word_found = true; //reset flag
                continue;
            }

            //start comparing with other words currently in string vector
            //do not do this if only 1 word present
            vector<string>::iterator iter=svec.begin();
            while(iter < svec.end())
            {
                if(word == *iter)
                {
                    //match found
                    cvec[iter-svec.begin()]++; //increment count of that word
                    unique_word_found = false;
                }
                iter++;
            }
            if(unique_word_found)
            {
                //add to unique word list and increment count
                svec.push_back(word);
                cvec.push_back(1);
                cvec[unique_word_count++]=1;
            }

            //next word
            pch = std::strtok(NULL, " ,-");
            unique_word_found = true; //reset flag
        }
    }

    cout << "Word" << " ---> " << "Occurrences" << endl;
    for(vector<string>::size_type i=0; i < svec.size(); i++)
    {
        cout << svec[i] << "  --->  " << cvec[i] << endl;
    }
    return 0;
}
