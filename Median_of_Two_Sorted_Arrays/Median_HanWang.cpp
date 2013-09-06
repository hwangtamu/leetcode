class Solution{
public:
    double findMedianSortedArrays(int A [], int m, int B [], int n){
		vector <int> va(A, A + m);
		vector <int> vb(B, B + n);
		vector <int> pool;
		vector <int>::iterator it_a = va.begin();
		vector <int>::iterator it_b = vb.begin();
		while (1){
			if (it_a < va.end() && it_b < vb.end()){
				pool.insert(pool.end(), *it_a < *it_b ? *it_a : *it_b);
				*it_a < *it_b ? ++it_a : ++it_b;
			}
			if (it_a == va.end() && it_b != vb.end()){
				pool.insert(pool.end(), *it_b);
				++it_b;
			}
			if (it_b == vb.end() && it_a != va.end()){
				pool.insert(pool.end(), *it_a);
				++it_a;
			}
			if (it_b == vb.end() && it_a == va.end())
				break;
		}
		return (m + n) % 2 == 0 ? double(pool[(m + n) / 2] + pool[(m + n) / 2 - 1]) / 2 : pool[(m + n - 1) / 2];
	}
};
