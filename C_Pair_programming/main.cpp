/** @file main.cpp
 *  @brief Pair programming
 *
 *  The company employs n developers, where n is an even number.
 *  The manager decided to split all the developers into teams
 *  of two people.
 *
 *  To do this, he compiled a list of all developers and assigned
 *  each of them a number on the list (from 1 to n) and the
 *  value a — the skill level of the i-th in the developer's list.
 *
 *  He makes the next command as follows:
 *  1. the first developer in the team is the one who goes first
 *  in the list;
 *  2. a pair is selected for him such that the difference between
 *  their levels is minimal (that is, the minimum value of |ai−aj|,
 *  where |x| is the modulus of the number x); if there are several
 *  such candidates, then the one who is earlier in the list is
 *  selected from them;
 *  3. These two developers form a team and are removed from
 *  the list.
 *
 *  The task is to simulate the process of splitting into teams.
 *
 *  @author Demidov Ignatii
 *  @bug No known bugs.
 */

#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int t; // count of input data sets
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n; // count of developers (even number)
        std::cin >> n;
        std::vector<std::pair<int, int>> dev;

        for (int num = 1; num <= n; num++) {
            int skill; // level of skill
            std::cin >> skill;
            dev.push_back({num, skill});
        }

        while (!dev.empty()) {
            int minIndex = 1;
            int minValue = abs(dev[0].second - dev[1].second);
            for (int num = 2; num < dev.size(); num++) {
                if (abs(dev[0].second - dev[num].second) < minValue) {
                    minIndex = num;
                    minValue = abs(dev[0].second - dev[num].second);
                }
            }
            std::cout << dev[0].first << ' ' << dev[minIndex].first << std::endl;
            dev.erase(dev.begin() + minIndex);
            dev.erase(dev.begin());
        }
        std::cout << std::endl;
    }
}