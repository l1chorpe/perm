#include <cstring>
#include <iostream>
#include <set>
#include <string>

using std::cout;
using std::set;
using std::strcmp;
using std::string;

set<string> permutate(const string&);
void printHelpPage();


/**
 * @brief Handles the input according to the options.
 * 
 * @param argc The command line argument count
 * @param argv The command line arguments
 * @return int The exit code
 */
int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        {
            printHelpPage();
            return 0;
        }

        for(const string& perm : permutate(argv[1]))
            cout << perm + '\n';

        return 0;
    }
    else if(argc == 3)
    {
        if(strcmp(argv[1], "-c") != 0 && strcmp(argv[1], "--count") != 0)
        {
            printHelpPage();
            return 1;
        }

        cout << permutate(argv[2]).size() << '\n';
        return 0;
    }
    else
    {
        printHelpPage();
        return 1;
    }
    
}

/**
 * @brief Takes a string and for each substring permutations, inserts the first substring into the second at each index.
 * 
 * @param s The string to permutate
 * @return set<string> A set of all the permutations of the given string
 */
set<string> permutate(const string& s)
{
    if(s.length() == 1)
        return {s};
    
    set<string> result{};
    // Take half of the length
    const int limit = s.length() % 2 == 0 ? s.length() / 2 : s.length() / 2 + 1;
    for(int i = 1; i <= limit; ++i)
    {
        // Generate all permutations of both substrings
        const auto& perms1 = permutate(s.substr(0, i));
        const auto& perms2 = permutate(s.substr(i));

        // Insert the first substring perms into the second substring perms, for each index of the word
        for(const string& perm1 : perms1)
            for(const string& perm2 : perms2)
                for(int j = 0; j < perm2.size() + 1; ++j)
                    // Using the constructor because insert works with the original string
                    result.insert(string{perm2}.insert(j, perm1));
    }

    return result;
}

void printHelpPage()
{
    cout << "Usage: perm <text> OR perm <options>\n";
    cout << "Finds all the permutations of a given text and outputs them along with the permutation count.\n\n";

    cout << "OPTIONS\n";
    cout << "-h, --help: Displays this text.\n\n";
    cout << "-c <text>, --count <text>: Only outputs the permutation count.\n\n";
}