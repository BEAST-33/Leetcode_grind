// there is a time array indicating the time at which that person comes to occupy the room. 
// there is a purpose array of the same length with 0 and 1. 0 means it is a candidate and 1 means it is a employee. 
// if the room had previously not been in use ,or employee was using it before, the employee in the queue gets more priority. 
// if a candidate has been using it before ,then now candidate gets more priority. each job takes one unit of time. 
// return the array consisting of peoples completion time in the same order as the time array
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // For std::sort

// A helper struct to hold combined information for each person.
struct Person {
    int arrival_time;
    int purpose; // 0 for candidate, 1 for employee
    int original_index;
};

// A standalone comparison function for sorting Person objects.
// It's passed to std::sort to define the sorting criteria.
bool comparePeople(const Person& a, const Person& b) {
    // Primary sort by arrival time.
    if (a.arrival_time != b.arrival_time) {
        return a.arrival_time < b.arrival_time;
    }
    // If times are equal, use original index as a tie-breaker for stable ordering.
    return a.original_index < b.original_index;
}

/**
 * @brief Calculates the completion time for each person based on room usage priority.
 *
 * @param time A vector of integers for arrival times.
 * @param purpose A vector of integers (0 for candidate, 1 for employee).
 * @return A vector of integers representing the completion time for each person.
 */
std::vector<int> get_completion_times(const std::vector<int>& time, const std::vector<int>& purpose) {
    int n = time.size();
    if (n == 0) {
        return {};
    }

    // 1. Combine inputs into a vector of Person objects.
    std::vector<Person> people;
    people.reserve(n);
    for (int i = 0; i < n; ++i) {
        people.push_back({time[i], purpose[i], i});
    }

    // 2. Sort people by passing the address of the comparison function.
    std::sort(people.begin(), people.end(), comparePeople);

    std::vector<int> completion_times(n);
    std::queue<int> employee_queue;
    std::queue<int> candidate_queue;

    long long current_time = 0;
    int last_user_type = -1; // -1: None, 0: Candidate, 1: Employee
    int arrival_index = 0;
    int completed_count = 0;

    // 3. Main simulation loop.
    while (completed_count < n) {
        // If idle, jump time to the next arrival.
        if (employee_queue.empty() && candidate_queue.empty() && arrival_index < n) {
            current_time = std::max(current_time, (long long)people[arrival_index].arrival_time);
        }

        // Add all people who have arrived to their respective queues.
        while (arrival_index < n && people[arrival_index].arrival_time <= current_time) {
            if (people[arrival_index].purpose == 1) {
                employee_queue.push(people[arrival_index].original_index);
            } else {
                candidate_queue.push(people[arrival_index].original_index);
            }
            arrival_index++;
        }

        // Determine who gets the room based on priority.
        int person_to_process = -1;
        if (last_user_type == 1 || last_user_type == -1) { // Employee priority
            if (!employee_queue.empty()) {
                person_to_process = employee_queue.front();
                employee_queue.pop();
                last_user_type = 1;
            } else if (!candidate_queue.empty()) {
                person_to_process = candidate_queue.front();
                candidate_queue.pop();
                last_user_type = 0;
            }
        } else { // Candidate priority (last_user_type == 0)
            if (!candidate_queue.empty()) {
                person_to_process = candidate_queue.front();
                candidate_queue.pop();
                last_user_type = 0;
            } else if (!employee_queue.empty()) {
                person_to_process = employee_queue.front();
                employee_queue.pop();
                last_user_type = 1;
            }
        }

        // Process the selected person's job.
        if (person_to_process != -1) {
            completion_times[person_to_process] = current_time + 1;
            current_time++;
            completed_count++;
        }
    }

    return completion_times;
}

// Example Usage
int main() {
    std::vector<int> time_arr = {0, 1, 1, 2, 4};
    std::vector<int> purpose_arr = {0, 1, 0, 1, 0};

    std::vector<int> completion_result = get_completion_times(time_arr, purpose_arr);

    std::cout << "Time Array:    ";
    for (int t : time_arr) std::cout << t << " ";
    std::cout << std::endl;

    std::cout << "Purpose Array: ";
    for (int p : purpose_arr) std::cout << p << " ";
    std::cout << std::endl;

    std::cout << "Completion Times: ";
    for (int ct : completion_result) std::cout << ct << " ";
    std::cout << std::endl; // Expected Output: 1 3 2 4 5

    return 0;
}