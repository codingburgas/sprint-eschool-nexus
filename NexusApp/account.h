// account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <unordered_map>
#include <map>
#include <vector>

class Account {
private:
    std::string username;
    static std::unordered_map<std::string, std::map<std::string, int>> accounts;
    static void loadAccounts();
    static void saveAccounts();
public:
    Account(const std::string& username);
    void updateScore(int newScore, const std::string& testName);
    int getScore(const std::string& testName) const;
    static bool accountExists(const std::string& username);
    static void createAccount(const std::string& username);
    static std::vector<std::pair<std::string, std::map<std::string, int>>> getDetailedScoreList(); // Ensure this line exists
};

#endif // ACCOUNT_H