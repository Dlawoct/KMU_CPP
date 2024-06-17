    #include <iostream>
    #include <exception>

    using namespace std;

    class IncompatibleException : public exception {
    public:
        virtual const char* what() const throw() {
            return "b1+b2= In + operation, the operands are not compatible.";
        }
    };

    class Kvector {
    protected:
        int* m;
        int len;
    public:
        Kvector(int sz = 0, int value = 0) : len(sz) {
            m = new int[len];
            for(int i = 0; i < len; ++i)
                m[i] = value;
        }
        ~Kvector() { delete[] m; }
        Kvector(const Kvector& v) : len(v.len) {
            m = new int[len];
            for(int i = 0; i < len; ++i)
                m[i] = v.m[i];
        }
        Kvector& operator=(const Kvector& v) {
            if (this != &v) {
                delete[] m;
                len = v.len;
                m = new int[len];
                for(int i = 0; i < len; ++i)
                    m[i] = v.m[i];
            }
            return *this;
        }
        friend std::ostream& operator<<(std::ostream& os, const Kvector& v) {
            for(int i = 0; i < v.len; ++i)
                os << v.m[i] << " ";
            return os;
        }
    };

    class Bvector : public Kvector {
    protected:
        unsigned int* u_m;
        const int NBITS;
    public:
        Bvector(int nbits = 32);
        Bvector(const Bvector& e);
        ~Bvector();
        bool bit(int pos) const;
        void set(int pos);
        void reset(int pos);
        int size() const { return NBITS; }
        void clear();
        void print() const;
        bool operator[](int idx) const { return bit(idx); }
        Bvector& operator=(const Bvector& v);
        friend ostream& operator<<(ostream& os, const Bvector& v);
    };

    Bvector::Bvector(int nbits) : Kvector((nbits + 31) / 32), NBITS(nbits) {
        u_m = (unsigned int*)m;
    }

    Bvector::Bvector(const Bvector& e) : Kvector(e), NBITS(e.NBITS) {
        u_m = (unsigned int*)m;
    }

    Bvector::~Bvector() {
        // Kvector destructor will handle memory deallocation
    }

    bool Bvector::bit(int pos) const {
        if (pos >= NBITS) return false;
        int index = pos / 32;
        int shift = pos % 32;
        return (u_m[index] & (1 << shift)) != 0;
    }

    void Bvector::set(int pos) {
        if (pos >= NBITS) return;
        int index = pos / 32;
        int shift = pos % 32;
        u_m[index] |= (1 << shift);
    }

    void Bvector::reset(int pos) {
        if (pos >= NBITS) return;
        int index = pos / 32;
        int shift = pos % 32;
        u_m[index] &= ~(1 << shift);
    }

    void Bvector::clear() {
        for (int i = 0; i < len; ++i)
            m[i] = 0;
    }

    void Bvector::print() const {
        cout << "Bvector with " << NBITS << " bits" << endl;
        for (int i = 0; i < NBITS; ++i) {
            cout << bit(i) << " ";
            if ((i + 1) % 32 == 0) cout << " ";
        }
        cout << endl;
    }

    Bvector& Bvector::operator=(const Bvector& v) {
        if (this != &v) {
            Kvector::operator=(v);
            u_m = (unsigned int*)m;
        }
        return *this;
    }

    ostream& operator<<(ostream& os, const Bvector& v) {
        for (int i = 0; i < v.NBITS; ++i) {
            os << v.bit(i);
            if ((i + 1) % 32 == 0) os << " ";
        }
        return os;
    }

    class BitSet : public Bvector {
    public:
        BitSet(int sz = 32);
        void insert(int v);
        friend BitSet operator+(const BitSet& v1, const BitSet& v2);
        friend ostream& operator<<(ostream& os, const BitSet& s);
    };

    BitSet::BitSet(int sz) : Bvector(sz) {}

    void BitSet::insert(int v) {
        set(v);
    }

    BitSet operator+(const BitSet& v1, const BitSet& v2) {
        if (v1.size() != v2.size()) {
            throw IncompatibleException();
        }
        BitSet r(v1.size());
        for (int i = 0; i < r.len; ++i) {
            r.u_m[i] = v1.u_m[i] | v2.u_m[i];
        }
        return r;
    }

    ostream& operator<<(ostream& os, const BitSet& s) {
        os << "{ ";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i]) {
                os << i << " ";
            }
        }
        os << "}";
        return os;
    }

    int main(int argc, char* argv[]) {
        try {
            BitSet b1(132), b2(131);
            b1.insert(3);b1.insert(5);b1.insert(8);
            b2.insert(4);b2.insert(5);b2.insert(8);b2.insert(130);
            b1.print();b2.print();
            cout << "b1= " << b1 << endl;
            cout << "b2= " << b2 << endl;
            cout << "b1+b2= " << b1 + b2 << endl;
        } catch (const IncompatibleException& e) {
            cout << e.what() << endl;
            cout << "The size of the first BitSet is 132" << endl;
            cout << "The size of the second BitSet is 131" << endl;
        }
        return 0;
    }

