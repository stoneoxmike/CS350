#ifndef HISTOGRAM_H
#define HISTOGRAM_H

class Histogram {
private:
    int *m_counts;

public:
    // constructor
    explicit Histogram(int numBuckets);
    // destructor
    ~Histogram();

    // interface methods
    void increaseCount(int bucket);
    int getCount(int bucket);
};

#endif
