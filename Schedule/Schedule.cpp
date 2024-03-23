#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a person and their availability
struct Person {
    string name;
    vector<bool> morningAvailability; // true if available in the morning, false otherwise
    vector<bool> afternoonAvailability; // true if available in the afternoon, false otherwise
};

// Structure to represent a day's schedule
struct DaySchedule {
    vector<Person> morningPersons;
    vector<Person> afternoonPersons;
};

// Function prototype for setAvailability
void setMorningAvailability(vector<Person>& persons, int personIndex, int dayIndex, bool available);
void setAfternoonAvailability(vector<Person>& persons, int personIndex, int dayIndex, bool available);

// Function to add a person to the list
void addPerson(vector<Person>& persons, const string& name, int numDays) {
    Person newPerson;
    newPerson.name = name;
    newPerson.morningAvailability.resize(numDays, true); // Initially, assume person is available every morning
    newPerson.afternoonAvailability.resize(numDays, true); // Initially, assume person is available every afternoon
    persons.push_back(newPerson);
}

// Function to set availability for a person in the morning on a specific day
void setMorningAvailability(vector<Person>& persons, int personIndex, int dayIndex, bool available) {
    persons[personIndex].morningAvailability[dayIndex] = available;
}

// Function to set availability for a person in the afternoon on a specific day
void setAfternoonAvailability(vector<Person>& persons, int personIndex, int dayIndex, bool available) {
    persons[personIndex].afternoonAvailability[dayIndex] = available;
}

// Function to generate schedule for a day based on availability of persons
DaySchedule generateSchedule(const vector<Person>& persons, int dayIndex) {
    DaySchedule schedule;
    for (const Person& person : persons) {
        if (person.morningAvailability[dayIndex]) {
            schedule.morningPersons.push_back(person);
        }
        if (person.afternoonAvailability[dayIndex]) {
            schedule.afternoonPersons.push_back(person);
        }
    }
    return schedule;
}

int main() {
    // Define array of days of the week
    string daysOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

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
        for (int j = 0; j < numDays; ++j) {
            bool morningAvailable, afternoonAvailable;
            cout << "Enter availability for " << name << " for " << daysOfWeek[j] << ":\n";
            cout << "Morning (1 for available, 0 for unavailable): ";
            cin >> morningAvailable;
            setMorningAvailability(persons, i, j, morningAvailable);
            cout << "Afternoon (1 for available, 0 for unavailable): ";
            cin >> afternoonAvailable;
            setAfternoonAvailability(persons, i, j, afternoonAvailable);
        }
    }

    // Generate and display the full schedule
    cout << "Full Schedule:\n";
    for (int i = 0; i < numDays; ++i) {
        DaySchedule schedule = generateSchedule(persons, i);
        cout << "Schedule for " << daysOfWeek[i] << ":\n";
        cout << "Morning:\n";
        for (const Person& person : schedule.morningPersons) {
            cout << person.name << endl;
        }
        cout << "Afternoon:\n";
        for (const Person& person : schedule.afternoonPersons) {
            cout << person.name << endl;
        }
        cout << endl;
    }

    return 0;
}
