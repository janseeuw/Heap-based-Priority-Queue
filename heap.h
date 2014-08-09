#include <iostream>
#include <vector>


// -------------------------------------------------------------------
// ---------------------------- interface ----------------------------
// -------------------------------------------------------------------

template <class T>
class Heap {
public:
	Heap(int maxN);
	~Heap();
	void push(const T &d);
	void pop();
	T top();
	int size() const;
	bool empty() const;
private:
	T *pq;
	int N;
	void fixUp(int i);
	void fixDown(int i, int N);
};

// -------------------------------------------------------------------
// -------------------------- implementation -------------------------
// -------------------------------------------------------------------


template <class T>
Heap<T>::Heap(int maxN){
	pq = new T[maxN+1];
	N = 0;
}

template <class T>
Heap<T>::~Heap<T>(){
	delete pq;
}

template <class T>
void Heap<T>::push(const T&d){
	pq[++N] = d;
	fixUp(N);
}

template <class T>
void Heap<T>::pop(){
	std::swap(pq[1], pq[N]);
	fixDown(1, N-1);
}

template <class T>
T Heap<T>::top(){
	return pq[1];
}

template <class T>
int Heap<T>::size() const{
	return N;
}

template <class T>
bool Heap<T>::empty() const{
	return N == 0;
}

template <class T>
void Heap<T>::fixUp(int i){
	while(i > 1 && pq[i/2] < pq[i])
	{
		std::swap(pq[i], pq[i/2]);
		i = i/2;
	}
}

template <class T>
void Heap<T>::fixDown(int i, int N){
	while(2*i <= N){
		int j = 2*i;
		if(j < N && pq[j] < pq[j+1]) j++;
		if(!(pq[i] < pq[j])) break;
		std::swap(pq[i], pq[j]);
		i = j;
	}
}