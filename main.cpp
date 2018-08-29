#include <iostream>
#include <assert.h>
using namespace std;

namespace Vec
{
	struct Vect
	{
		int *data;
		int n_data;
		int array_size;
	};

	void init(Vect *a, int size)
	{
		a->n_data = 0;
		a->array_size = size;
		a->data = (int*)malloc(size * sizeof(int));
		assert(a->data);
	}

	void resize(Vect *a)
	{
		a->array_size = a->array_size++ * 1.2; //++ in case size = 1
		a->data = (int*)realloc(a->data, a->array_size * sizeof(int));
		assert(a->data);
	}

	void add(Vect *a, int input)
	{
		if (a->n_data >= a->array_size) resize(a);

		a->data[a->n_data++] = input;
	}

	void clean(Vect *a)
	{
		if (a->data != NULL) free(a->data);
		*a = {}; //zero out
	}
}

void main()
{
	Vec::Vect original_list;
	Vec::Vect reverse_list;
	int input;

	cout << "Input list size: ";
	cin >> input;
	cout << endl;

	Vec::init(&original_list, input);
	Vec::init(&reverse_list, input);

	cout << "Original List:" << endl;

	for (int i = 0; i < input; i++)
	{
		Vec::add(&original_list, rand());
		cout << original_list.data[i] << endl;
	}

	cout << "Reverse List:" << endl;

	for (int i = 0; i < input; i++)
	{
		Vec::add(&reverse_list, original_list.data[original_list.n_data - i - 1]);
		cout << reverse_list.data[i] << endl;
	}

	Vec::clean(&original_list);
	Vec::clean(&reverse_list);

	system("pause");
}