def data_types():
    var = [0, '', 0.0, False, [], {}, (), set()]
    
    print(
        f'[{type(var[0]).__name__}, '
        f'{type(var[1]).__name__}, '
        f'{type(var[2]).__name__}, '
        f'{type(var[3]).__name__}, '
        f'{type(var[4]).__name__}, '
        f'{type(var[5]).__name__}, '
        f'{type(var[6]).__name__}, '
        f'{type(var[7]).__name__}]'
    )

if __name__ == '__main__':
    data_types()