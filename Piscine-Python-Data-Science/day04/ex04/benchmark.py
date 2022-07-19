import timeit
import random
from collections import Counter

def ft_create_dict(lst):
    dict_counter = {}
    for data in lst:
        if data in dict_counter:
            dict_counter[data] += 1
        else:
            dict_counter[data] = 1
    return dict_counter


def top_most(lst):
    dict_counter = ft_create_dict(lst)
    return sorted(dict_counter.items(), key=(lambda x: -x[1]))[:10]


def main():
    lst = [random.randint(0, 100) for x in range(1000000)]
    print('my function:',timeit.timeit(f'ft_create_dict({lst})',number=1,setup='from __main__ import ft_create_dict'))
    print('Counter:',timeit.timeit(f'Counter({lst})',number=1,setup='from __main__ import Counter'))
    print('my top:',timeit.timeit(f'top_most({lst})',number=1,setup='from __main__ import top_most'))
    print('Counter\'s top:',timeit.timeit(f'Counter({lst}).most_common(10)',number=1,setup='from __main__ import Counter'))


if __name__ == '__main__':
    main()