#include <iostream>
#include <fstream>
#include <string>


int main()
{
    std::string fish;
    std::string current_fish;
    int count_of_fishes = 0;
    std::cout << "What kind a fish you wont to catch?" << std::endl;
    std::cin >> fish;

    std::ofstream basket("C:\\tutorial-data\\basket.txt", std::ios::app);
    if (!basket.is_open()) {
        std::cerr << "Fail to open file or mistake in a path to it" << std::endl;
        return 1;
    }

    std::ifstream fishing;
    fishing.open("C:\\tutorial-data\\river.txt");
    if (!fishing.is_open()) {
        std::cerr << "Fail to open file or mistake in a path to it" << std::endl;
        return 1;
    }

    while (std::getline(fishing, current_fish)) {
        if (current_fish == fish) {
            basket << fish << "\n";
            count_of_fishes++;
        }
    }

    if (count_of_fishes == 0) {
        std::cout << "It's a bad day for fishing. You didn't catch anything" << std::endl;
    }
    else {
        std::cout << "Good day for your cat! You catch: " << count_of_fishes << " fish/es!" << std::endl;
    }


    basket.close();
    fishing.close();

    return  0;
}