def read_and_write():
    with open('ds.csv', 'r') as file1:
        with open('ds.tsv', 'w') as file2:
            text = file1.read().replace('\",', '\"\t')\
                .replace('false,', 'false\t')\
                .replace('true,', 'true\t')
            file2.write(text)


if __name__ == '__main__':
    read_and_write()