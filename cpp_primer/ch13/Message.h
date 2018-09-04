/**
 * @brief 练习13.34-13.37
 * 
 * @file Message.h
 * @author huipengly
 * @date 2018-09-03
 * @note 没有测试过
 */
#ifndef _MESSAGE_H_
#define _MESSAGE_H_
#include <string>
#include <set>

class Folder;

class Message
{
    friend class Folder;
    friend void swap(Message&, Message&);
public:
    explicit Message(const std::string s = "") : contents(s) {}
    Message(const Message& msg) : contents(msg.contents), folders(msg.folders) 
        { add_to_folder(msg); }
    Message(Message &&msg) : contents(std::move(msg.contents))  // 移动构造，所以这里参数不能是const
        { move_folders(msg); }
    Message& operator=(const Message&);
    Message& operator=(Message&&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
    void addFolder(Folder*);
    void remFolder(Folder*);
private:
    std::string contents;                   //!< message的内容
    std::set<Folder*> folders;              //!< message所在的folder
    void add_to_folder(const Message&);
    void remove_from_folders();
    void move_folders(Message&);
};

class Folder
{
    friend void swap(Folder&, Folder&);
public:
    Folder() = default;
    Folder(const Folder& f) : messages(f.messages) 
        { add_to_messages(f); }
    Folder& operator=(const Folder&);
    void addMsg(Message&);
    void remMsg(Message&);
    ~Folder();

private:
    std::set<Message*> messages;
    void add_to_messages(const Folder&);
    void remove_from_message();
};


#endif