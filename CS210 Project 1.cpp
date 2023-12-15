#include <iostream>
#include <ctime>
#include <iomanip>

class Clock {
private:
    int hours, minutes, seconds;

public:
    Clock() {
        // Get current time
        time_t now = time(0);
        tm* localTime = localtime(&now);

        // Set initial values for the clock
        hours = localTime->tm_hour;
        minutes = localTime->tm_min;
        seconds = localTime->tm_sec;
    }

    void display12Hour() const {
        std::cout << std::setfill('0') << std::setw(2) << (hours % 12 == 0 ? 12 : hours % 12) << ":"
                  << std::setw(2) << minutes << ":" << std::setw(2) << seconds
                  << (hours >= 12 ? " PM" : " AM");
    }

    void display24Hour() const {
        std::cout << std::setfill('0') << std::setw(2) << hours << ":"
                  << std::setw(2) << minutes << ":" << std::setw(2) << seconds;
    }

    void addOneHour() {
        hours = (hours + 1) % 24;
    }

    void addOneMinute() {
        minutes = (minutes + 1) % 60;
        if (minutes == 0) {
            addOneHour();
        }
    }

    void addOneSecond() {
        seconds = (seconds + 1) % 60;
        if (seconds == 0) {
            addOneMinute();
        }
    }
};

class ClockManager {
private:
    Clock clock;

public:
    void displayClocks() const {
        std::cout << "*****************************    *****************************\n";
        std::cout << "*        12-Hour Clock      *    *        24-Hour Clock      *\n";
        std::cout << "*         ";
        clock.display12Hour();
        std::cout << "       *    *         ";
        clock.display24Hour();
        std::cout << "          *\n";
        std::cout << "*****************************    *****************************\n";
    }


    void performAction(int choice) {
        switch (choice) {
            case 1:
                clock.addOneHour();
                break;
            case 2:
                clock.addOneMinute();
                break;
            case 3:
                clock.addOneSecond();
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
};

int main() {
    ClockManager clockManager;

    int choice;
    do {
        clockManager.displayClocks();

        // Display menu
        std::cout << "\n***********************\n";
        std::cout << "* 1. Add One Hour     *\n";
        std::cout << "* 2. Add One Minute   *\n";
        std::cout << "* 3. Add One Second   *\n";
        std::cout << "* 4. Exit Program     *\n";
        std::cout << "***********************\n";
        std::cin >> choice;

        if (choice >= 1 && choice <= 3) {
            clockManager.performAction(choice);
        } else if (choice != 4) {
            std::cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    std::cout << "Exiting program. Goodbye!\n";

    return 0;
}
