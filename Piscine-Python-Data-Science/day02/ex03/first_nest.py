import sys


class Research:
    def __init__(self, filename):
        self.filename = filename
        self.data = self.file_reader()
        self.calc = self.Calculations()

    def file_reader(self, has_header=True):
        with open(self.filename, 'r') as file:
            read_file = file.read()
        lines = read_file.split('\n')
        if has_header and len(lines[0].split(',')) != 2:
            raise Exception("Header must contain two strings delimited by a ',' ")
        if has_header:
            lines = lines[1:]
        if len(lines) == 0:
            raise Exception("Error, no data")
        for line in lines:
            if line != '0,1' and line != '1,0':
                raise ValueError('Incorrect line')
        return [[int(elem) for elem in line.split(',')] for line in lines]

    class Calculations:

        def counts(self, data):
            x = [x[0] for x in data]
            y = [y[1] for y in data]
            return [sum(x), sum(y)]

        def fractions(self, counts):
            return [(counts[0] / (counts[0] + counts[1])) * 100,
                    (counts[1] / (counts[0] + counts[1])) * 100]


if __name__ == '__main__':
    if len(sys.argv) == 2:
        reader = Research(sys.argv[1])
        print(reader.data)
        counts = reader.calc.counts(reader.data)
        print(' '.join([str(elem) for elem in counts]))
        print(' '.join([str(elem) for elem in reader.calc.fractions(counts)]))
