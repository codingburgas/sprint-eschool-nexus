
#ifndef ACCOUNT_H 
#define ACCOUNT_H

#include <string> 
#include <unordered_map> 
#include <map> 
#include <vector> 

// Account class declaration
class Account {
private:
    std::string username; // Stores the username of the account
    static std::unordered_map<std::string, std::map<std::string, int>> accounts; // Static map to store all accounts data
    static void loadAccounts(); 
    static void saveAccounts(); 

public:
    Account(const std::string& username); // Constructor to create an Account object
    void updateScore(int newScore, const std::string& testName); 
    int getScore(const std::string& testName) const; 
    static bool accountExists(const std::string& username); 
    static void createAccount(const std::string& username); 
    static std::vector<std::pair<std::string, std::map<std::string, int>>> ScoreList(); 
};

#endif 