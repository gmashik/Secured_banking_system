

class account
{
private:
    char account_number[30];
    char firstName[30];
    char lastName[30];
    float total_Balance;
    int tel;
public:
    void read_input();
    void show_info();
    void info_write();
    void record_read();
    void record_search();
    void record_mod();
    void rec_delete();
};


