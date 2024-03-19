#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a person and their availability
struct Person {
    string name;
    vector<bool> availability; // true if available, false otherwise
};

// Structure to represent a day's schedule
struct DaySchedule {
    vector<Person> availablePersons;
};

// Function prototype for setAvailability
void setAvailability(vector<Person>& persons, int personIndex, int dayIndex, bool available);

// Function to add a person to the list
void addPerson(vector<Person>& persons, const string& name, int numDays) {
    Person newPerson;
    newPerson.name = name;
    newPerson.availability.resize(numDays, true); // Initially, assume person is available every day
    persons.push_back(newPerson);
}

// Function to set availability for a person on all days
void setAvailabilityForAllDays(vector<Person>& persons, int personIndex, int numDays) {
    string daysOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    cout << "Enter availability for " << persons[personIndex].name << " for each day, 1 for available 0 for unavailable:\n";
    for (int i = 0; i < numDays; ++i) {
        bool available;
        cout << daysOfWeek[i] << ": "; // Print the corresponding day of the week
        cin >> available;
        setAvailability(persons, personIndex, i, available);
    }
}

// Function to set availability for a person on a specific day
void setAvailability(vector<Person>& persons, int personIndex, int dayIndex, bool available) {
    persons[personIndex].availability[dayIndex] = available;
}

// Function to generate schedule for a day based on availability of persons
DaySchedule generateSchedule(const vector<Person>& persons) {
    DaySchedule schedule;
    int numDays = persons[0].availability.size();
    for (int i = 0; i < numDays; ++i) {
        for (const Person& person : persons) {
            if (person.availability[i]) {
                schedule.availablePersons.push_back(person);
            }
        }
    }
    return schedule;
}

int main() {
    vector<Person> persons;
    int numDays;

    cout << "Enter the number of days in the schedule: ";
    cin >> numDays;

    int numPersons;
    cout << "Enter the number of persons: ";
    cin >> numPersons;

    for (int i = 0; i < numPersons; ++i) {
        string name;
        cout << "Enter the name of person " << i + 1 << ": ";
        cin >> name;
        addPerson(persons, name, numDays);
        setAvailabilityForAllDays(persons, i, numDays);
    }

    // Define array of days of the week
    string daysOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    // Generate and display the full schedule
    DaySchedule schedule = generateSchedule(persons);
    cout << "Full Schedule:\n";
    for (int i = 0; i < numDays; ++i) {
        cout << "Schedule for " << daysOfWeek[i] << ":" << endl;
        for (const Person& person : schedule.availablePersons) {
            if (person.availability[i]) {
                cout << person.name << endl;
            }
        }
        cout << endl;
    }

    return 0;
}
