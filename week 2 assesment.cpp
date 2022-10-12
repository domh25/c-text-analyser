#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
using namespace std;

int main()
{
    int numberOfWords = 0;
    int numberOfSentances = 0;
    string line;
    string full;
    string word;
    std::map<string, int> wordList;
    int count = 1;
    

    string filename = "input.txt";
    ifstream myFile(filename); 
    if (myFile.is_open())
    {
        while (getline(myFile, line))
        {
            full += line;
            numberOfSentances += 1;
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] == ' ') 
                {
                    numberOfWords++;
                }
            }
        }       
        myFile.close();
        cout << "sentances is: " << numberOfSentances << "\n";
        cout << "words is: " << numberOfWords + numberOfSentances;
       
        for (int i = 0; i < full.size(); i++)
        {
            if (full[i] == ',')
            {
                full[i] = ' ';
            }
            if (full[i] == '.')
            {
                full[i] = ' ';
            }
        }
        

        istringstream wordStream(full);
        while (wordStream >> word)
        {
            pair<map<string, int>::iterator, bool> returnValue;

            returnValue = wordList.insert(pair<string, int>(word, count));

            if (returnValue.second == false)
            {
                ++returnValue.first->second;
            }
        }
        map<string, int>::iterator itr;
        for (itr = wordList.begin(); itr != wordList.end(); ++itr)
        {
            cout << '\t' << itr->second << '\n';
            cout << '\t' << itr->first;
            
        }
    }
    return 0;
}

