#include "User.h"



User * createUser(string name,string lastname,string username,string email,string password){
    User * user = new User();
    setName(user,name);
    setLastname(user,lastname);
    setUsername(user,username);
    setEmail(user,email);
    setPassword(user,password);
    return user;
}


void setName(User * user,string name){
    user->name = name;
}
void setLastname(User *user,string lastname){
    user->lastname  = lastname;
}
void setUsername(User *user,string username){
      user->username  = username;
}
void setEmail(User *user,string email){
      user->email  = email;
}
void setPassword(User *user,string password){
      user->password  = password;
}

string getName(User * user){
    return user->name;
}
string getLastname(User *user){
      return user->lastname;
}
string getUsername(User *user){
      return user->username;
}
string getEmail(User *user){
      return user->email;
}
string getPassword(User * user){
      return user->password;
}



void printUser(User *user){
    cout << "Nombre: " << user->name << endl;
    cout << "Apellido: " << user->lastname << endl;
//    cout << "Usuario: " << user->username << endl;
//    cout << "Correo: " << user->email << endl;
//    cout << "Contrasenia: " << user->password << endl;
}

void printUserVoid(void *user){
    cout << "Nombre: " << ((User*) user)->name<< endl;
    cout << "Apellido: " << ((User*) user)->lastname << endl;
    cout << "Usuario: " << ((User*) user)->username << endl;
    cout << "Correo: " << ((User*) user)->email << endl;
    cout << "Contrasenia: " << ((User*) user)->password << endl;
}


