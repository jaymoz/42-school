def to_dictionary():
    list_of_tuples = [
        ('Russia', '25'),
        ('France', '132'),
        ('Germany', '132'),
        ('Spain', '178'),
        ('Italy', '162'),
        ('Portugal', '17'),
        ('Finland', '3'),
        ('Hungary', '2'),
        ('The Netherlands', '28'),
        ('The USA', '610'),
        ('The United Kingdom', '95'),
        ('China', '83'),
        ('Iran', '76'),
        ('Turkey', '65'),
        ('Belgium', '34'),
        ('Canada', '28'),
        ('Switzerland', '26'),
        ('Brazil', '25'),
        ('Austria', '14'),
        ('Israel', '12')
        ]
    dict_list = {}
    for value, key in list_of_tuples:
        if key in dict_list:
            dict_list[key].append(value)
        else:
            dict_list[key] = [value]
    for key, values in dict_list.items():
        for val in values:
            print(f'{key} : {val}')



if __name__ == '__main__':
    to_dictionary()
