import sys

class Research:
    def __init__(self, pathname):
        self.pathname = pathname
    
    def file_reader(self):
        with open(self.pathname, "r") as file_to_read:
            read_file = file_to_read.read()
        lines = read_file.split('\n')
        if len(lines[0].split(',')) != 2:
            raise Exception("Header must contain two strings delimited by a ',' ")
        remaining = lines[1:]
        if len(remaining) == 0:
            raise Exception("Error, no data")
        for line in remaining:
            if line != '0,1' and line != '1,0':
                raise Exception("Invalid Line")
        return read_file

if __name__=='__main__':
    if len(sys.argv) == 2:
        val = Research(sys.argv[1])
        print(val.file_reader())

