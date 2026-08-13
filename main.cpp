#include <iostream>
#include <iomanip>

 int main()
 {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n{};
    double x{};

    std::cin >> n >> x ;

    std::cout << std::fixed << std::setprecision(4)<< ( n * x ) << '\n';

 }