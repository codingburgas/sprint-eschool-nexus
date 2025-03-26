
#include "account.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>


std::unordered_map<std::string, std::map<std::string, int>> Account::accounts;


void Account::loadAccounts() {
    std::ifstream file("accounts.txt");
    if (!file.is_open()) return; 

    std::string user;
    std::string testName;
    int score;

    // Read user, test name, and score from the file.
    while (file >> user >> testName >> score) {
        accounts[user][testName] = score; // Store the score in the 'accounts' map.
    }
    file.close();
}

void Account::saveAccounts() {
    std::ofstream file("accounts.txt");

  
    for (const auto& userPair : accounts) {
        for (const auto& scorePair : userPair.second) {
            file << userPair.first << " " << scorePair.first << " " << scorePair.second << "\n";
        }
    }
    file.close();
}

// Constructor for the Account class.
Account::Account(const std::string& username) : username(username) {
    // If 'accounts' is empty, load data from file.
    if (accounts.empty()) loadAccounts();

    // If the user doesn't exist, create an empty entry for them.
    if (accounts.find(username) == accounts.end()) {
        accounts[username] = {};
    }
}

// Updates a user's score for a specific test.
void Account::updateScore(int newScore, const std::string& testName) {
    // If the test score doesn't exist or the new score is higher, update it
    if (accounts[username].find(testName) == accounts[username].end() || newScore > accounts[username][testName]) {
        accounts[username][testName] = newScore;
        saveAccounts(); // Save the updated data.
    }
}

// Retrieves a user's score for a specific test.
int Account::getScore(const std::string& testName) const {
    // If the user and test exist, return the score.
    if (accounts.find(username) != accounts.end() && accounts[username].find(testName) != accounts[username].end()) {
        return accounts[username][testName];
    }
    return 0; 
}

// Checks if an account with the given username exists.
bool Account::accountExists(const std::string& username) {
    // If 'accounts' is empty, load data from file.
    if (accounts.empty()) loadAccounts();

    return accounts.find(username) != accounts.end();
}

// Creates a new account with the given username.
void Account::createAccount(const std::string& username) {
    // If the account doesn't exist, create it and save the data
    if (!accountExists(username)) {
        accounts[username] = {};
        saveAccounts();
    }
}

// Returns a vector of all accounts and their scores.
std::vector<std::pair<std::string, std::map<std::string, int>>> Account::ScoreList() {
    std::vector<std::pair<std::string, std::map<std::string, int>>> scoreList;

    
    for (const auto& userPair : accounts) {
        scoreList.emplace_back(userPair.first, userPair.second);
    }
    return scoreList;
}