class MedianFinder {
public:
    vector<int> elements;
    int size = 0, index = -1;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        auto it = upper_bound(elements.begin(), elements.end(), num);
        elements.insert(it, num);
        size += 1;
        if(size % 2 == 1) index += 1;
    }
    
    double findMedian() {
        cout<<size<<"  "<<index<<endl;
        return size % 2 == 1 ? elements[index] : (elements[index] + (index + 1 < size ? elements[index+1] : 0))/2.00;
    }
};