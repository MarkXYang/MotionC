

#ifndef RINGBUFFER_H
#define RINGBUFFER_H


template<class kind, int length> class RingBuffer {
    public:
        RingBuffer();
        int          size();
        int          capacity();
        int          next_block_index(int index);
        int          prev_block_index(int index);
        void         push_back(kind object);
        void         pop_front(kind &object);
        void         get( int index, kind &object);
        kind*        get_ref( int index);
        void         delete_first();

        kind         buffer[length];
        int          head;
        int          tail;
};


template<class kind, int length> RingBuffer<kind, length>::RingBuffer(){
    this->head = this->tail = 0;
}

template<class kind, int length>  int RingBuffer<kind, length>::capacity(){
    return length-1;
}

template<class kind, int length>  int RingBuffer<kind, length>::size(){
return((this->head>this->tail)?length:0)+this->tail-head;
}

template<class kind, int length> int RingBuffer<kind, length>::next_block_index(int index){
    index++;
    if (index == length) { index = 0; }
    return(index);
}

template<class kind, int length> int RingBuffer<kind, length>::prev_block_index(int index){
    if (index == 0) { index = length; }
    index--;
    return(index);
}

template<class kind, int length> void RingBuffer<kind, length>::push_back(kind object){
    this->buffer[this->tail] = object;
    this->tail = (tail+1)&(length-1);
}

template<class kind, int length> void RingBuffer<kind, length>::get(int index, kind &object){
    int j= 0;
    int k= this->head;
    while (k != this->tail){
        if (j == index) break;
        j++;
        k= (k + 1) & (length - 1);
    }
    if (k == this->tail){
        //return NULL; 
    }
    object = this->buffer[k];
}


template<class kind, int length> kind* RingBuffer<kind, length>::get_ref(int index){
    int j= 0;
    int k= this->head;
    while (k != this->tail){
        if (j == index) break;
        j++;
        k= (k + 1) & (length - 1);
    }
    if (k == this->tail){
        return NULL;
    }
    return &(this->buffer[k]);
}

template<class kind, int length> void RingBuffer<kind, length>::pop_front(kind &object){
    object = this->buffer[this->head]; 
    this->head = (this->head+1)&(length-1);
}

template<class kind, int length> void RingBuffer<kind, length>::delete_first(){
    //kind dummy;
    //this->pop_front(dummy);
    this->head = (this->head+1)&(length-1);
}


#endif
