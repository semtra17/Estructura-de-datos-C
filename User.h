#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;
struct User{
    std::string name;
    std::string  lastname;
    std::string  username;
    std::string  email;
    std::string  password;
};



User * createUser(string,string,string,string,string);
void printUser(User *);
void printUserVoid(void *user);
void setName(User *,string);
void setLastname(User *,string);
void setUsername(User *,string);
void setEmail(User *,string);
void setPassword(User *,string);

string getName(User *);
string getLastname(User *);
string getUsername(User *);
string getEmail(User *);
string getPassword(User *);

#endif // USER_H_INCLUDED
