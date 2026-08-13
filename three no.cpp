#include <iostream>
#include <iomanip>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << "Enter three numbers: ";

    int x{};
    int y{};
    int z{};

    std::cin >> x >> y >> z;

    std::cout << "You entered " << x << ", " << y << ", and " << z << ".\n";

    return 0;
}