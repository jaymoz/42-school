from random import randint

class Research:
    def __init__(self, filename):
        self.filename = filename
        self.data = self.file_reader()
        self.calc = self.Analytics(self.data)

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

        def __init__(self, data):
            self.data = data
            self.count = self.counts()
            self.fraction = self.fractions(self.count)

        def counts(self):
            x = [x[0] for x in self.data]
            y = [y[1] for y in self.data]
            return [sum(x), sum(y)]

        def fractions(self, counts):
            return [(counts[0] / (counts[0] + counts[1])) * 100,
                    (counts[1] / (counts[0] + counts[1])) * 100]

        
    class Analytics(Calculations):
        def predict_random(self, num_prediction):
            dict = {0: [0, 1], 1:[1, 0]}
            return [dict[randint(0,1)] for x in range(num_prediction)]

        def predict_last(self):
            return self.data[-1]

        def save_file(self, data, filename, extension="txt"):
            with open(f'{filename}.{extension}', "w") as output:
                output.write(data)
