class Research:

    def file_reader(self):
        with open('data.csv', 'r') as file_to_read:
            data = file_to_read.read()
        return (data)


if __name__=='__main__':
    print(Research().file_reader())