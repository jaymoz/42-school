class Must_read:
    with open('data.csv', 'r') as file_to_read:
        data = file_to_read.read()
        print(data)


if __name__=='__main__':
    Must_read()