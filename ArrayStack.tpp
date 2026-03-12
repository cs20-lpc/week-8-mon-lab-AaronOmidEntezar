template <typename T>
ArrayStack<T>::ArrayStack(int i) {
    if (i <= 0) {
        throw string("Invalid max size.");
    }

    maxSize = i;
    buffer = new T[maxSize];
    this->length = 0;
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <typename T>
void ArrayStack<T>::clear() {
    delete[] buffer;
    buffer = nullptr;
    this->length = 0;
    maxSize = 0;
}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    maxSize = copyObj.maxSize;
    this->length = copyObj.length;
    buffer = new T[maxSize];

    for (int i = 0; i < this->length; i++) {
        buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
T ArrayStack<T>::peek() const {
    if (isEmpty()) {
        throw string("Cannot peek from an empty stack.");
    }

    return buffer[this->length - 1];
}

template <typename T>
void ArrayStack<T>::pop() {
    if (isEmpty()) {
        throw string("Cannot pop from an empty stack.");
    }

    this->length--;
}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    if (isFull()) {
        throw string("Cannot push onto a full stack.");
    }

    buffer[this->length] = elem;
    this->length++;
}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {
    if (this->length <= 1) {
        throw string("Cannot rotate a stack with fewer than two elements.");
    }

    if (dir == Stack<T>::RIGHT) {
        T topElem = buffer[this->length - 1];

        for (int i = this->length - 1; i > 0; i--) {
            buffer[i] = buffer[i - 1];
        }

        buffer[0] = topElem;
    }
    else if (dir == Stack<T>::LEFT) {
        T bottomElem = buffer[0];

        for (int i = 0; i < this->length - 1; i++) {
            buffer[i] = buffer[i + 1];
        }

        buffer[this->length - 1] = bottomElem;
    }
    else {
        throw string("Invalid rotation direction.");
    }
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        for (int i = myObj.length - 1; i >= 0; i--) {
            outStream << (i == myObj.length - 1 ? "top\t" : "\t")
                      << myObj.buffer[i] << endl;
        }
    }

    return outStream;
}