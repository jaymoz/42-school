import timeit
import sys


def with_list_comp():
    emails = 5 * ['john@gmail.com', 'james@gmail.com', 'alice@yahoo.com', 'anna@live.com', 'philipp@gmail.com']
    return [email for email in emails if email.endswith('@gmail.com')]


def with_loop():
    emails = 5 * ['john@gmail.com', 'james@gmail.com', 'alice@yahoo.com', 'anna@live.com', 'philipp@gmail.com']
    lst = []
    for email in emails:
        if email.endswith('@gmail.com'):
            lst.append(email)
    return lst


def with_map():
    emails = 5 * ['john@gmail.com', 'james@gmail.com', 'alice@yahoo.com', 'anna@live.com', 'philipp@gmail.com']
    return list(map(lambda x: x if x.endswith('@gmail.com') else None, emails))


def with_filter():
    emails = 5 * ['john@gmail.com', 'james@gmail.com', 'alice@yahoo.com', 'anna@live.com', 'philipp@gmail.com']
    return list(filter(lambda x: x.endswith('@gmail.com'), emails))



def main():
    dict_list = {'loop': 'with_loop',
           'list_comprehension': 'with_list_comp',
           'map': 'with_map',
           'filter': 'with_filter'}
    if len(sys.argv) == 3:
        try:
            if sys.argv[1] in dict_list:
                func_to_exec = dict_list[sys.argv[1]]
                print(timeit.timeit( func_to_exec + '()', number=int(sys.argv[2]), setup='from __main__ import ' + dict_list[sys.argv[1]]))
            else:
                print('Function does not exist')
        except Exception as e:
            print(e, type(e))

if __name__ == '__main__':
    main()