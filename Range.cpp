template <class Vector = int, class Scalar = int> class range {
    private:
    Vector left, right, diff;

    public:
    class iterator : std::iterator<std::forward_iterator_tag, Vector> {
        private:
        Scalar index;
        Vector diff;

        public:
        iterator() {}
        iterator(Scalar index) : index(index), diff(1) {}
        iterator(Scalar index, Vector diff) : index(index), diff(diff) {}
        iterator(const iterator &i) : index(i.index), diff(i.diff) {}

        Scalar &operator*() { return index; }
        iterator &operator++() {
            index += diff;
            return *this;
        }
        iterator operator++(int) {
            iterator tmp(*this);
            index += diff;
            return *tmp;
        }
        iterator &operator--() {
            index -= diff;
            return *this;
        }
        iterator operator--(int) {
            iterator tmp(*this);
            index -= diff;
            return tmp;
        }
        bool operator==(const iterator &rhs) const { return index == rhs.index; }
        bool operator!=(const iterator &rhs) const { return index != rhs.index; }
        iterator &operator=(const iterator &rhs) {
            index = rhs.index;
            return *this;
        }
    };

    range() : left(0), right(0), diff(1) {}
    range(Vector right) : left(0), right(right), diff(1) {}
    range(Vector left, Vector right) : left(left), right(right), diff(1) {}
    range(Vector left, Vector right, Vector diff) : left(left), right(right), diff(diff) {}
    range(const range &r) : left(r.left), right(r.right), diff(r.diff) {}

    Scalar &operator[](Scalar index) const { return *iterator(left + diff * index); }

    iterator begin() const { return iterator(left, diff); }
    iterator end() const { return iterator(right, diff); }
};
