#include <iostream>

int main()
{
    int basedamage{};
    double multiplier{};
    [[maybe_unused]] int durability{100};

    std::cout << " Final damage: ";
    std::cin >> basedamage >> multiplier;
    basedamage = 5;

    std::cout << " Final damage: " << basedamage * multiplier << ".\n";
    
    return 0;
}