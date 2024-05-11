#include"Time.h"

int main() {
    // Creating a Time object with initial values
    Time a{ 20, 59, 50 };

    // Incrementing the minute by 1
    a.incMin();

    // Printing the time in twenty-four hour format
    cout << "Time after incrementing minute by 1: ";
    a.printTwentyFourHourFormat(); // Output should be 21:00:50

    // Incrementing the hour by 1
    a.incHour();

    // Printing the time in twenty-four hour format
    cout << "\nTime after incrementing hour by 1: ";
    a.printTwentyFourHourFormat(); // Output should be 22:00:50

    // Decrementing the hour by 1
    a.decHour();

    // Printing the time in twenty-four hour format
    cout << "\nTime after decrementing hour by 1: ";
    a.printTwentyFourHourFormat(); // Output should be 21:00:50

    // Decrementing the minute by 1
    a.decMin();

    // Printing the time in twenty-four hour format
    cout << "\nTime after decrementing minute by 1: ";
    a.printTwentyFourHourFormat(); // Output should be 20:59:50

    cout << endl;
    return 0;
}


//int main()
//{
//	BoundedInteger bi(5, 12, 7); 
//	bi.decrement(4); 
//	cout << bi.getValue() << '\n';
//	//display 11 
//	bi.increment(10); 
//	cout<<bi.getValue()<<'\n';
//	//display 5
//	return 0;
//}
