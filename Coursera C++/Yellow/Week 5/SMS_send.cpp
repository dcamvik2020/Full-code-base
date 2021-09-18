#include <iostream>
#include <string>

using namespace std;

void SendSms(const string& number, const string& message) {
  cout << "Send '" << message << "' to number " << number << endl;
}

void SendEmail(const string& email, const string& message) {
  cout << "Send '" << message << "' to e-mail "  << email << endl;
}

///____________________________________________________________
/*
 Реализуйте здесь классы INotifier, SmsNotifier, EmailNotifier
 */
class INotifier {
public:
  virtual void Notify (const string & message) const = 0;
};

class SmsNotifier : public INotifier {
private:
//public:
  const string & number_;
public:
  SmsNotifier (const string & number) : number_(number) {
      //cout << "Constructor : number_ = " << number_ << endl;
  }
  virtual void Notify (const string & message) const override{
    SendSms (number_, message);
  }
};

class EmailNotifier : public INotifier {
private:
//public:
  const string & mail_;
public:
  EmailNotifier (const string & mail) : mail_(mail) {}

  virtual void Notify (const string & message) const override {
    SendEmail (mail_, message);
  }
};
///____________________________________________________________

void Notify(INotifier& notifier, const string& message) {
  notifier.Notify(message);
}

int main() {
  SmsNotifier sms{"+7-495-777-77-77"};
//cout << "sms  --> " << sms.number_ << endl;
  EmailNotifier email{"na-derevnyu@dedushke.ru"};

//cout << "sms  --> " << sms.number_ << endl;
//cout << "mail --> " << email.mail_ << endl << endl;

  Notify(sms, "I have White belt in C++");
  Notify(email, "And want a Yellow one");

  /// Output :
  ///  Send 'I have White belt in C++' to number +7-495-777-77-77
  ///  Send 'And want a Yellow one' to e-mail na-derevnyu@dedushke.ru
  
  return 0;
}


