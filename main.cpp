#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

// Define the monster names
std::vector<std::string> Mons = {"Floraburn", "Shockfin", "Frostmoth", "Shadowmind", "Voltbrawler", "Terrafey", "Ironcladore", "Spectrake", "Toxiwarrior", "Metatuff"};

// Function to pick monsters for a team
std::vector<int> picker(std::vector<int> otherTeam)
{
    // Shuffle the monster indices
    std::vector<int> indices(Mons.size());
    std::iota(indices.begin(), indices.end(), 0);
    std::shuffle(indices.begin(), indices.end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));

    // Pick the first three unique monsters that are not in the other team
    std::vector<int> team;
    for (int i = 0; i < indices.size() && team.size() < 3; i++) {
        if (std::find(otherTeam.begin(), otherTeam.end(), indices[i]) == otherTeam.end()) {
            team.push_back(indices[i]);
        }
    }

    return team;
}

int main()
{
    // Pick monsters for each team
    std::vector<int> team1 = picker({});
    std::vector<int> team2 = picker(team1);

    // Print the selected monsters for each team
    std::cout << "Team 1:\n";
    for (int i = 0; i < 3; i++) {
        std::cout << Mons[team1[i]] << "\n";
    }
    std::cout << "Team 2:\n";
    for (int i = 0; i < 3; i++) {
        std::cout << Mons[team2[i]] << "\n";
    }

    return 0;
}

/* Fixed with the assistance of GitHub CoPilot

According to GitHub CoPilot:
GitHub Copilot: The reason why the first script didn't work properly is that it didn't include 
the `std` namespace for the `string` type. In C++, the `string` type is defined in the `std` namespace, 
so you need to either use the fully qualified name `std::string` or include the `using namespace std;` 
directive to bring the `std` namespace into scope.

In the second script, the `using namespace std;` directive is included, so the `string` type can be used 
without the `std::` prefix. Additionally, the `string` type is used to define the `Mons` array, 
which is more convenient than using a C-style array of `char*` pointers.

Another difference between the two scripts is that the second script uses a C-style array of `int` pointers
to represent the picked monsters, while the first script uses a `std::vector<int>` to represent the 
picked monsters. The `std::vector` class provides more convenient and safer memory management than 
C-style arrays, and allows you to easily resize the array if needed.
*/

