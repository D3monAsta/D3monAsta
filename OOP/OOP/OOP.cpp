#include <iostream>

using namespace std;

class Sstring {
    char* data;
    char* data_tail;
    long size;
    public:
        Sstring(){
            size = 0;
            data = new char[0]; data[0] = '\0';
            data_tail = data;
        }

        Sstring(const char* d) {
            size = 0;
            const char* t = d;
            while (*d++) size++;
            data_tail = new char[size+1];
            data = data_tail;
            while (*data_tail++ = *t++);
            data_tail--;
        }

        Sstring(const Sstring& d) {
            size = d.size;
            data = d.data;
            data_tail = d.data_tail;
        }

        Sstring& operator=(const Sstring& d) {
            size = d.size;
            data = d.data;
            data_tail = d.data_tail;
        }

        Sstring operator+(const char* d) const{
            Sstring res;
            const char* t = d;
            while (*d++) res.size++;
            res.size += size;
            res.data_tail = new char[size + 1];
            res.data = res.data_tail;
            const char* dd = data;
            while (*dd)
                *res.data_tail++ = *dd++;
            while (*res.data_tail++ = *t++);
            *res.data_tail = '\0';
            res.data_tail--;
            return res;
        }

        bool operator==(const Sstring& d) {
            Sstring res = d;
            res.data_tail = res.data;
            data_tail = data;
            if (size == d.size) {
                while (*res.data++)
                    if (*res.data_tail++ != *data_tail++)
                        return false;
            }
            else
                return false;
            return true;
        }

        bool operator!=(const Sstring& d) {
            Sstring res = d;
            res.data_tail = res.data;
            data_tail = data;
            if (size == d.size) {
                while (*res.data++)
                    if (*res.data_tail++ == *data_tail++)
                        return false;
            }
            else
                return true;
        }

        bool operator>(const Sstring& d) {
            const char* l = data;
            const char* r = d.data;
            while (*l && *r) {
                if (*l != *r) 
                    return *l > * r;
                ++l;
                ++r;
            }
            return *l == '\0';
        }

        bool operator>=(const Sstring& d) {
            const char* l = data;
            const char* r = d.data;
            while (*l && *r) {
                if (*l != *r)
                    return *l >= * r;
                ++l;
                ++r;
            }
            return *l == '\0';
        }

        bool operator<(const Sstring& d) {
            const char* l = data;
            const char* r = d.data;
            while (*l && *r)
            {
                if (*l != *r)
                    return *l <= *r;
                ++l;
                ++r;
            }
            return *l == '\0';
        }

        bool operator<=(const Sstring& d) {
            const char* l = data;
            const char* r = d.data;
            while (*l && *r)
            {
                if (*l != *r)
                    return *l < *r;
                ++l;
                ++r;
            }
            return *l == '\0';
        }

        Sstring operator+(const Sstring& d) const{
            Sstring res;
            const Sstring& t = d;
            res.size = size + d.size;
            res.data_tail = new char[size + 1];
            res.data = res.data_tail;
            const char* dd = data;
            const char* td = t.data;
            while (*dd)
                *res.data_tail++ = *dd++;
            while (*res.data_tail++ = *td++);
            *res.data_tail = '\0';
            res.data_tail--;
            return res;
        }

        Sstring& operator=(const char* d) {
            size = 0;
            while (*d++) size++;
            data_tail = new char[size + 1];
            data = data_tail;
            while (*data_tail++ = *d++);
            data_tail--;
        }

        char operator[](const int ind) {
            if (0 <= ind < size) {
                Sstring res;
                res.size = size;
                res.data_tail = data;
                res.data = res.data_tail;
                int i = 0;
                while (i++ != ind)
                    *res.data_tail++;
                return *res.data_tail;
            }
            return '\0';
        }
        /*int index(const Sstring a) {
    if (size < a.size)
        return -1;
    Sstring res = a;
    res.data_tail = res.data;
    data_tail = data;
    int ind = -1;
    while (*data_tail++){
        while (*res.data_tail++) {
            if (*data_tail != *res.data_tail) {
                res.data_tail = res.data;
                break;
            }
            ind = data_tail-res.data;
        }
    }
    return ind;
}*/
        int index(const Sstring& a) {
            if (size < a.size)
                return -1;
            char* iterator = a.data;
            data_tail = data;
            int ind = -1;
            while (*data_tail) {
                if (a.size == ind)
                    break;
                if (*data_tail != *iterator) {
                    ind = 0;
                    iterator = a.data;
                    
                }
                else 
                    *iterator++;
                ind++;
                *data_tail++;
            }
            return ind;
        }

        friend ostream& operator<<(ostream& os, const Sstring& str);
        friend istream& operator>>(istream& os, Sstring& d);
};

class Snumber : Sstring {
    friend Sstring sum(const Sstring& a, const Sstring& b) {
        Sstring result;
        
    }
};

istream& operator>>(istream& os, Sstring& str) {
    str.data_tail = new char[str.size + 1];
    str.data = str.data_tail;
    int i = 0;
    while (i < str.size) {
        os >> *str.data_tail++;
        ++i;
    }
    str.data_tail--;
    return os;
};

ostream& operator<<(ostream& os, const Sstring& str)
{
    const char* st = str.data;
    const char* end = str.data_tail;
    for (st; st <= end; st++)
        std::cout << *st;
    std::cout << endl;
    return os;
};

int main()
{
    Sstring a("abc");
    Sstring b("ababc");
    std::cout << a << endl << b << endl;
    std::cout << b.index(a);
    
}