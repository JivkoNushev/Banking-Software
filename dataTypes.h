class User
{
    string userName, password;
    int userId;
public:
    User(string userName, string password, int userId);

    void set_name(string name);
    void set_password(string new_password);
    void set_id(int new_id);

    string get_name();
    string get_password();
    int get_id();

    string add_user();

    static bool user_exists(string username, string password);

    static int user_id(string username);

    static bool username_exists(string username);

    static int generate_id(string username);

    bool withdraw();

    bool deposit();

    bool transfer();
};

class Bill
{
    string billNumber;
    int userId;
    float balance;
public:
    Bill(string billNumber, string userId, float balance);

    void set_billNumber(string bill_Number);
    void set_userId(string user_Id);
    void set_balance(float new_balance);

    string get_billNumber();
    int get_userId();
    float get_balance();

    static float find_balance(int userId);
    static void change_balance(int userId, float newBalance);        
    static bool bill_exists(string billNumber);
};
class Transactions
{
    string operationCode, billNumberFrom, billNumberTo;
    float transferAmount;
public:
    Transactions(string operationCode, string billNumberFrom, string billNumberTo, float transferAmount);

    void set_operationCode(string new_operationCode);
    void set_billNumberFrom(string new_billNumberFrom);
    void set_billNumberTo(string new_billNumberTo);
    void set_transferAmount(float new_transferAmount);

    string get_operationCode();
    string get_billNumberFrom();
    string get_billNumberTo();
    float get_transferAmount();
};