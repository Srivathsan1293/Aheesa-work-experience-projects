#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>

int main() {
  std :: unordered_map<int, bool> primes ; 
  int i = 3;
  int number;
  std::string text;
  std::ifstream prime_numbers("numbers.txt");
  while (getline(prime_numbers, text)){
    number = stoi(text);
    primes[number] = true;
  }
  prime_numbers.close();
  std::cout << "Enter the number you want to search for, enter a negative to quit\n";
  std::cin >> number;
  while (number > 0){
    if (primes.find(number) != primes.end() && primes[number]) {
      std::cout << number << " is a prime number." << std::endl;
    } else {
        if ((number % 2) == 0){
          std::cout << number << " is not a prime number." << std::endl;
        }else{
          while (1){
            if ((number % i) == 0){
              std::cout << number << " is not a prime number." << std::endl;
              break;
            }else if ((i * i) > number){
              std::cout << number << " is prime number found from algorithm." << std::endl;
              primes[number] = true;
              break;
            }
            i += 2;
          }
        }
      
    }
    std::cout << "Enter the number you want to search for, enter a negative to quit\n";
    std::cin >> number;
  }
  std::ofstream store("numbers.txt");

  for (const auto& pair : primes) {
    if (pair.second) { // Check if the value is true
        store << pair.first << "\n"; // Write each prime number on a new line
    }
  }
  store.close();
  
}
