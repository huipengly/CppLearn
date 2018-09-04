#include "Message.h"

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(*this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(*this);
}

void Message::add_to_folder(const Message &m)
{
    for (auto f : m.folders)
    {
        f->addMsg(*this);
    }
}

void Message::remove_from_folders()
{
    for (auto f : folders)
    {
        f->remMsg(*this);
    }
    // 不需要添加这一句，需要用到的场景中，析构会自动清除set，拷贝时会复制
    // folders.clear();            // 删除和folder连接后，要清除set中记录的folder
}

void Message::move_folders(Message &m)
{
    folders = std::move(m.folders);
    for (auto f : folders)
    {
        f->remMsg(m);
        f->addMsg(*this);
    }
    m.folders.clear();
}

Message& Message::operator=(const Message& rhs)
{
    remove_from_folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_folder(rhs);
    return *this;
}

Message& Message::operator=(Message &&rhs)
{
    if (this != &rhs)
    {
        remove_from_folders();
        contents = std::move(contents);
        move_folders(rhs);
    }
    return *this;
}

Message::~Message()
{
    remove_from_folders();
}

void Message::addFolder(Folder *f)
{
    save(*f);
}

void Message::remFolder(Folder *f)
{
    remove(*f);
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    lhs.remove_from_folders();
    rhs.remove_from_folders();
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, lhs.folders);
    lhs.add_to_folder(lhs);
    rhs.add_to_folder(rhs);
}

void Folder::addMsg(Message &m)
{
    messages.insert(&m);
}

void Folder::remMsg(Message &m)
{
    messages.erase(&m);
}

Folder::~Folder()
{
    remove_from_message();
}

void Folder::add_to_messages(const Folder &f)
{
    for (auto m : f.messages)
    {
        m->addFolder(this);
    }
}

void Folder::remove_from_message()
{
    for (auto m : messages)
    {
        m->remove(*this);
    }
}

Folder& Folder::operator=(const Folder &rhs)
{
    remove_from_message();
    messages = rhs.messages;
    add_to_messages(rhs);
    return *this;
}



int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
