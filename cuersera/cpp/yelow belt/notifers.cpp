#include <string>

using namespace std;

class INotifier
{
public:
    virtual void Notify(const string &message) const = 0;
};

class SmsNotifier : public INotifier
{
public:
    SmsNotifier(const string &number) : Number(number)
    {
    }
    virtual void Notify(const string &message) const override
    {
        SendSms(Number, message);
    }

private:
    const string Number;
};

class EmailNotifier : public INotifier
{
public:
    EmailNotifier(const string &email) : Email(email)
    {
    }
    virtual void Notify(const string &message) const override
    {
        SendEmail(Email, message);
    }

private:
    const string Email;
};
