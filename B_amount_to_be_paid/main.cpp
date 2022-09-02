/** @file main.cpp
 *  @brief Amount to be paid
 *
 *  There is an action in the store: "buy three identical
 *  products and pay only for two." Each purchased product can
 *  participate in only one promotion. The promotion can be
 *  used multiple times.
 *
 *  For example, if 7 products of one type are purchased at
 *  a price of 2 per piece and 5 products of another type at
 *  a price of 3 per piece, then instead of 7⋅2+5⋅3, you will
 *  have to pay 5⋅2+4⋅3=22.
 *
 *  Only the same products have the same prices.
 *
 *  @return Amount to be paid
 *
 *  @author Demidov Ignatii
 *  @bug No known bugs.
 */

#include <iostream>
#include <unordered_map>

int main() {
    int t; // number of input data sets
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n; // number of purchased products
        std::cin >> n;
        std::unordered_map<int, int> products;

        for (int j = 0; j < n; j++) {
            int now; // price of current product
            std::cin >> now;
            auto search = products.find(now);
            if (search == products.end()) products[now] = 1;
            else search->second++;
        }

        int sum = 0; // amount to be paid
        for (auto product: products) {
            sum += product.first * (product.second - product.second / 3);
        }
        std::cout << sum << std::endl;
    }
}