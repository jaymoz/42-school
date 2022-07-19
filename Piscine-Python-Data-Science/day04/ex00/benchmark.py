import timeit


def with_list_comp():
    emails = ['john@gmail.com', 'james@gmail.com', 'alice@yahoo.com', 'anna@live.com', 'philipp@gmail.com'] * 5
    return [email for email in emails if email.endswith('@gmail.com')]


def with_loop():
    emails = ['john@gmail.com', 'james@gmail.com', 'alice@yahoo.com', 'anna@live.com', 'philipp@gmail.com'] * 5
    lst = []
    for email in emails:
        if email.endswith('@gmail.com'):
            lst.append(email)
    return lst



def main():
    loop_time = timeit.timeit(stmt='with_loop()',setup='',number=90000000, globals=globals())
    list_time = timeit.timeit(stmt='with_list_comp()',setup='',number=90000000, globals=globals())
    if loop_time < list_time:
        print('it is better to use a loop')
        print(str(loop_time) + ' vs ' + str(list_time))
    else:
        print('it is better to use a list comprehension')
        print(str(list_time) + ' vs ' + str(loop_time))


if __name__ == '__main__':
    main()