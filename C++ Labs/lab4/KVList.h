
//#define CLIENT
//#define STRUCT
#define PAIR
#include<iostream>
#include<string>
#include<utility>

using namespace std;

template<typename K, typename V, int N>
class KVList {
#ifdef CLIENT
	K k[N];
	V v[N];
#endif
#ifdef STRUCT
	struct {
		K k;
		V v;
	}data[N];
#endif
#ifdef PAIR
	std::pair<K,V> data[N];
#endif
	K kDefault;
	V vDefault;
	size_t count;
	public:

KVList() : count(0) {

}

size_t size() const {
	return count;
}

const K& key(int i) const
{
	if(i >= 0 && i < count)
	#ifdef CLIENT
	return k[i];
	#endif

	#ifdef STRUCT
	return data[i].k
	#endif
	#ifdef PAIR
	return data[i].first;
	#endif
	return kDefault;
}

const V& value(int i) const
{
	if(i >= 0 && i < count) 
	#ifdef CLIENT
	return v[i];
	#endif
	
	#ifdef STRUCT
	return data[i].v;
	#endif
	
	#ifdef PAIR
	return data[i].second;
	#endif
	return vDefault;
}

KVList& add(const K& kk, const V& vv) 
{
	if(count < N){
	#ifdef CLIENT
	v[count] = vv;
	k[count] = kk;
	#endif
	
	#ifdef PAIR
	data[count] = std::make_pair (kk,vv);
	#endif
	count++;
	}	
}

int find(const K& kk) const {
	for(size_t i = 0; i < count; i++)
	#ifdef CLIENT
	//if(k[i] = kk)
	#endif
	#ifdef PAIR
	if(data[i].first == kk)
	#endif	
	return i;
	return 0;
	
}

KVList& replace(int i, const K& kk, const V& vv) 
{
	if(i >= 0 && i < count){
	#ifdef CLIENT
	v[i] = vv;
	k[i] = kk;
	#endif
	#ifdef STRUCT
	data[i].v = vv;
	data[i].k = kk;
	#endif
	#ifdef PAIR
	data[i] = make_pair(kk,vv);
	#endif
	}
}

};
