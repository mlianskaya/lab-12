#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class RangeIterator
{
private:
	typename T::iterator current;
	typename T::iterator end;
public:
	RangeIterator(typename T::iterator rbegin, typename T::iterator rend)
	{
		current = rbegin;
		end = rend;
	}

	RangeIterator& operator++()
	{
		++current;
		return *this;
	}

	RangeIterator& operator--()
	{
		--current;
		return *this;
	}

	typename T:: value_type& operator*()
	{
		return *current;
	}

	bool operator != (const RangeIterator& other)
	{
		return current != other.current;
	}

	void print() 
	{
		for (typename T::iterator it = current; it != end; ++it) 
		{
			cout << *it << " ";
		}
	}

};

int main()
{
	vector<int> numbers = { 1, 2, 3, 4, 5 };
	RangeIterator<vector<int>> first_it(numbers.begin(), numbers.end());
	cout << "Vector 1: ";
	first_it.print();
	cout << endl;

	vector<double> numbers2 = { 1.2, 1.3, 1.6, 1.7, 5.2, 5.3, 5.6, 5.7 };
	RangeIterator<vector<double>> second_it(numbers2.begin()+2, numbers2.end()-2);
	cout << "Vector 2: ";
	second_it.print();
	cout << endl;

	vector<string> words = {"apple", "cherry", "peach", "cucumber"};
	RangeIterator<vector<string>> third_it(words.begin(), words.end());
	cout << "Vector 3: ";
	third_it.print();
	cout << endl;

	vector<int> numbers3 = { 1, 2, 3, 4, 5 };
	RangeIterator<vector<int>> begin(numbers3.begin(), numbers3.end());
	RangeIterator<vector<int>> end(numbers3.end(), numbers3.end());
	cout << "Vector 4: ";
	while (begin != end)
	{
		*begin += 4;
		cout << *begin << " ";
		++begin;
	}

	return 0;
}

