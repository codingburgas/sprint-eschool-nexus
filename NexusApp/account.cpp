// account.cpp
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
    while (file >> user >> testName >> score) {
        accounts[user][testName] = score;
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

Account::Account(const std::string& username) : username(username) {
    if (accounts.empty()) loadAccounts();
    if (accounts.find(username) == accounts.end()) {
        accounts[username] = {};
    }
}

void Account::updateScore(int newScore, const std::string& testName) {
    if (accounts[username].find(testName) == accounts[username].end() || newScore > accounts[username][testName]) {
        accounts[username][testName] = newScore;
        saveAccounts();
    }
}

int Account::getScore(const std::string& testName) const {
    if (accounts.find(username) != accounts.end() && accounts[username].find(testName) != accounts[username].end()) {
        return accounts[username][testName];
    }
    return 0;
}

bool Account::accountExists(const std::string& username) {
    if (accounts.empty()) loadAccounts();
    return accounts.find(username) != accounts.end();
}

void Account::createAccount(const std::string& username) {
    if (!accountExists(username)) {
        accounts[username] = {};
        saveAccounts();
    }
}

std::vector<std::pair<std::string, std::map<std::string, int>>> Account::getDetailedScoreList() {
    std::vector<std::pair<std::string, std::map<std::string, int>>> scoreList;
    for (const auto& userPair : accounts) {
        scoreList.emplace_back(userPair.first, userPair.second);
    }
    return scoreList;
}