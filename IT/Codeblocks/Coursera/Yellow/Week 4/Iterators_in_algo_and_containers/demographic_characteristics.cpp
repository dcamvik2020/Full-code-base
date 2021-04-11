#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
enum class Gender {
  FEMALE,
  MALE
};

struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};




// Это пример функции, его не нужно отправлять вместе с функцией PrintStats
template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}
*/


/// !! we may use partition from <algorithm>
/// PAY ATTENTION : we may sort vector<Person> persons : there will be
/// different sections --> males     | females
///                       /   \           /  \
///            employed     unempl.    empl.   unempl.                  
///  ---> we may count needed iterators and count median ages
/// males_end
/// females_end
/// empl_males_end
/// empl_females_end
void PrintStats(vector<Person> persons) {
  /// general median age
  int gen_med_age = ComputeMedianAge(persons.begin(), persons.end());

  /// females general median age
  auto females = partition(persons.begin(), 
		           persons.end(), 
			   [](const Person & person) {
		             return person.gender == Gender::FEMALE; 
			   });
  int fem_med_age = ComputeMedianAge(persons.begin(), females);

  /// employed females general median age
  auto employed_females = partition(persons.begin(), persons.end(), [](const Person & person) {
		                                                       return person.gender == Gender::FEMALE &&
								              person.is_employed == true; 
							             });
  int emp_fem_med_age = ComputeMedianAge(persons.begin(), employed_females);

  /// unemployed females general median age
  auto unemployed_females = partition(persons.begin(), persons.end(), [](const Person & person) {
		                                                       return person.gender == Gender::FEMALE &&
								              person.is_employed == false; 
							             });
  int unemp_fem_med_age = ComputeMedianAge(persons.begin(), unemployed_females);



  /// males general median age
  auto males = partition(persons.begin(), persons.end(), [](const Person & person) {
		                                             return person.gender == Gender::MALE; 
							    });
  int male_med_age = ComputeMedianAge(persons.begin(), males);

  /// employed males general median age
  auto employed_males = partition(persons.begin(), persons.end(), [](const Person & person) {
		                                                       return person.gender == Gender::MALE &&
								              person.is_employed == true; 
							             });
  int emp_male_med_age = ComputeMedianAge(persons.begin(), employed_males);

  /// unemployed females general median age
  auto unemployed_males = partition(persons.begin(), persons.end(), [](const Person & person) {
		                                                       return person.gender == Gender::MALE &&
								              person.is_employed == false; 
							             });
  int unemp_male_med_age = ComputeMedianAge(persons.begin(), unemployed_males);

  
  cout << "Median age = " << gen_med_age << endl;
  cout << "Median age for females = " << fem_med_age << endl;
  cout << "Median age for males = " << male_med_age<< endl;
  cout << "Median age for employed females = " << emp_fem_med_age << endl;
  cout << "Median age for unemployed females = " << unemp_fem_med_age << endl;
  cout << "Median age for employed males = " << emp_male_med_age << endl;
  cout << "Median age for unemployed males = " << unemp_male_med_age << endl;
}



int main() {
  vector<Person> persons = {
      {31, Gender::MALE, false},
      {40, Gender::FEMALE, true},
      {24, Gender::MALE, true},
      {20, Gender::FEMALE, true},
      {80, Gender::FEMALE, false},
      {78, Gender::MALE, false},
      {10, Gender::FEMALE, false},
      {55, Gender::MALE, true},
  };
  PrintStats(persons);

/*
 * answer (example of format):
 *
 * Median age = 40
 * Median age for females = 40
 * Median age for males = 55
 * Median age for employed females = 40
 * Median age for unemployed females = 80
 * Median age for employed males = 55
 * Median age for unemployed males = 78
 */
  
  
  return 0;
}
