#include <iostream>
#include <string>
#include <set>

using namespace std;

class Message;

class Folder
{
public:
    void addMsg(Message*);
    void remMsg(Message*);
private:
    set<Message*> messages;
};

void Folder::addMsg(Message *m)
{
    messages.insert(m);
}

void Folder::remMsg(Message *m)
{
    messages.erase(m);
}