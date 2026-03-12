template <typename T>
ArrayStack<T>::ArrayStack(int i) {
    if (i <= 0) {
        throw string("invalid size");
    }
    maxSize = i;
    buffer = new T[maxSize];
    this->length = 0;
}

template <typename T>
void ArrayStack<T>::clear() {
    delete[] buffer;
    buffer = new T[maxSize];
    this->length = 0;
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
T ArrayStack<T>::peek() const {
    if (isEmpty()) {
        throw string("empty stack");
    }
    return buffer[this->length - 1];
}

template <typename T>
void ArrayStack<T>::pop() {
    if (isEmpty()) {
        throw string("empty stack");
    }
    this->length--;
}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    if (isFull()) {
        throw string("full stack");
    }
    buffer[this->length] = elem;
    this->length++;
}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {
    if (this->length <= 1) {
        throw string("cannot rotate");
    }

    if (dir == Stack<T>::RIGHT) {
        T temp = buffer[this->length - 1];
        for (int i = this->length - 1; i > 0; i--) {
            buffer[i] = buffer[i - 1];
        }
        buffer[0] = temp;
    }
    else {
        T temp = buffer[0];
        for (int i = 0; i < this->length - 1; i++) {
            buffer[i] = buffer[i + 1];
        }
        buffer[this->length - 1] = temp;
    }
}