struct student
{
        int s_n;
        char name[20];
        float score;
};

struct nodestudent
{
        char name[20];
        float score;
        struct nodestudent *next;
};
